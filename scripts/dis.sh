#!/bin/bash

OUTPUT_DIR="./tmp"
CMSIS_ELF_PATH=".pio/build/CMSIS/firmware.elf"
STM32CUBE_ELF_PATH=".pio/build/STM32Cube/firmware.elf"

mkdir -p $OUTPUT_DIR

# if first parameter is "CMSIS" then use CMSIS ELF file
if [ "$1" == "CMSIS" ]; then
    echo "Using CMSIS ELF file"
    ELF_PATH=$CMSIS_ELF_PATH
else
    echo "Using STM32Cube ELF file"
    ELF_PATH=$STM32CUBE_ELF_PATH
fi

# if ELF_PATH exists then use it
if [ -f $ELF_PATH ]; then
    arm-none-eabi-readelf -a $ELF_PATH > "$OUTPUT_DIR/readelf.txt"
    arm-none-eabi-objdump -d $ELF_PATH > "$OUTPUT_DIR/objdump.S"
    arm-none-eabi-objdump -S $ELF_PATH > "$OUTPUT_DIR/objdump-source.S"
else
    echo "ELF file not found: $ELF_PATH"
fi


