#!/bin/sh

# File to monitor
FILE="./src/main.c"

# Command to execute
COMMAND="make"

# Interval in seconds
INTERVAL=10

# Initialize the variable to store the previous content
previous_content=""

# Function to compare and execute command if content has changed
check_content() {
    current_content=$(cat "$FILE")
    if [ "$current_content" != "$previous_content" ]; then
        echo "Content has changed. Executing command..."
        $COMMAND
        previous_content="$current_content"
    fi
}

# Main loop
while true; do
    check_content
    sleep "$INTERVAL"
done
