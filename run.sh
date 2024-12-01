#!/bin/bash

# Variables
SOURCE_FILE="main.c"    # Source file name
OUTPUT_FILE="main"      # Output executable name

# Step 1: Compile the program
echo "Compiling $SOURCE_FILE..."
gcc "$SOURCE_FILE" -lncurses -lm -o "$OUTPUT_FILE"

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation successful. Executing $OUTPUT_FILE..."
    
    # Step 2: Execute the program
    ./"$OUTPUT_FILE"
else
    echo "Compilation failed. Please check your code for errors."
    exit 1
fi

