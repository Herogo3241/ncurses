#!/bin/bash

# Variables
SOURCE_FILE="main.c"           # Source file name
OUTPUT_FILE="mazeoftime"       # Output executable name
INSTALL_DIR="/usr/local/bin"   # Installation directory

# Step 1: Compile the program
echo "Compiling $SOURCE_FILE..."
gcc "$SOURCE_FILE" -lncurses -lm -o "$OUTPUT_FILE"

# Check if compilation succeeded
if [ $? -eq 0 ]; then
    echo "Compilation successful."

    # Step 2: Install the executable
    echo "Installing $OUTPUT_FILE to $INSTALL_DIR..."
    sudo mv "$OUTPUT_FILE" "$INSTALL_DIR"

    if [ $? -eq 0 ]; then
        echo "Installation successful! You can now run 'mazeoftime' from anywhere."
    else
        echo "Installation failed. Please check your permissions."
        exit 2
    fi
else
    echo "Compilation failed. Please check your code for errors."
    exit 1
fi
    
