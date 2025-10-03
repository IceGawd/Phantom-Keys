#!/bin/bash

set -e

# Define directories
SRCDIR=src
INCLUDEDIR=include
SDLINCLUDEDIR=C:/SDL2/include
OBJDIR=obj/debug

# Parse flags
FULL=false
RELEASE=false
DOCSGENERATOR=false
GDBDEBUG=false

while getopts ":frdg" opt; do
	case $opt in
		f)
			echo "FULL COMPILE!"
			FULL=true
			;;
		r)
			echo "COMPILING RELEASE VERSION!"
			RELEASE=true
			;;
		d)
			echo "COMPILING DOCS GENERATOR!"
			DOCSGENERATOR=true
			;;
		g)
			echo "COMPILING WITH GDB DEBUG MODE!"
			GDBDEBUG=true
			;;
		\?)
			echo "Invalid option: -$OPTARG" >&2
			exit 1
			;;
	esac
done

if $DOCSGENERATOR; then
	 g++ -c iceDocsGenerator.cpp -std=c++14 -g -m64 -o obj/iceDocsGenerator.o
	 g++ obj/iceDocsGenerator.o -o iceDocsGenerator
	 exit 0
fi

if $RELEASE; then
	OBJDIR=obj/release
elif $GDBDEBUG; then
	OBJDIR=obj/gdb
fi

# Create the output directory if it doesn't exist
mkdir -p $OBJDIR

# Compile all .cpp and .c files in the src directory
for file in $SRCDIR/*.cpp $SRCDIR/*.c $SRCDIR/detail/*.cpp; do
	if [ -f "$file" ]; then
		objfile=$OBJDIR/$(basename ${file%.*}.o)
		# Check if the object file needs to be recompiled
		if [ ! -f "$objfile" ] || [ "$file" -nt "$objfile" ] || $FULL; then
			echo "Compiling $file..."
			if $RELEASE; then
				g++ -c $file -o $objfile -std=c++14 -O3 -g -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
			elif $GDBDEBUG; then
				g++ -c $file -o $objfile -std=c++14 -g3 -O0 -fno-omit-frame-pointer -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
			else
				g++ -c $file -o $objfile -std=c++14 -g -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
			fi
		else
			echo "Skipping $file, object file is up to date."
		fi
	fi
done

echo "Creating the main executable..."

if $RELEASE; then
	g++ obj/release/*.o -o bin/release/main -L C:/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
elif $GDBDEBUG; then
	g++ obj/gdb/*.o -o bin/gdb/main -L C:/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
else
	g++ obj/debug/*.o -o bin/debug/main -L C:/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
fi