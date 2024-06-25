#!/bin/bash

RED='\033[31m'
GREEN='\033[32m'
BLUE='\033[34m'
RESET='\033[0m'

SRC_DIR=src
OBJ_DIR=obj
BIN_FILE=dog

# Check for cleanup argument
if [ "$1" == clean ]; then
	echo "Cleaning up the project"
	rm "$OBJ_DIR"/*.o
	rm "$BIN_FILE"
	exit 0
fi

# Compile into object files
echo -e "${BLUE}Starting compilation... $RESET"
mkdir -p "$OBJ_DIR"
for FILE in "$SRC_DIR"/*; do
	FILENAME=$(basename -- $FILE)
	EXTENSION=$(echo "$FILENAME" | cut -d. -f2)

	if [ "$EXTENSION" == "h" ]; then
		continue
	fi

	echo "Compiling $FILE to "$OBJ_DIR"/"$FILENAME".o"
	g++ -D_LIBCPP_REMOVE_TRANSITIVE_INCLUDES --std=c++17 -g -c $FILE -o "$OBJ_DIR"/"$FILENAME".o
	if [ "$?" -eq 1 ]; then
		echo -e "${RED}An error occured. Ending compilation. $RESET"
		exit 1
	fi
done

# Link object files and compile to binary
echo -e "${BLUE}Linking... $RESET"
g++ --std=c++17 -Wall -pedantic -g -fsanitize=address "$OBJ_DIR"/*.o -o "$BIN_FILE"
if [ "$?" -eq 1 ]; then
	echo -e "${RED}An error occured. Ending linking. $RESET"
	exit 1
fi
echo -e "${GREEN}Complete. $RESET"
