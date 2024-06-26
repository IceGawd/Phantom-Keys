#!/bin/bash

# Define directories
SRCDIR=src
OBJDIR=obj/debug
INCLUDEDIR=include
SDLINCLUDEDIR=C:/SDL2/include

# Create the output directory if it doesn't exist
mkdir -p $OBJDIR

# Parse flags
RELEASE=false

while getopts "r" opt; do
  case $opt in
    r)
      echo "COMPILING RELEASE VERSION!"
      RELEASE=true
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
  esac
done

# Compile all .cpp and .c files in the src directory
for file in $SRCDIR/*.cpp $SRCDIR/*.c $SRCDIR/detail/*.cpp; do
  if [ -f "$file" ]; then
    objfile=$OBJDIR/$(basename ${file%.*}.o)
    # Check if the object file needs to be recompiled
    if $RELEASE; then
      echo "Compiling $file..."
      g++ -c $file -o $objfile -std=c++14 -g -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
    else
      if [ ! -f "$objfile" ] || [ "$file" -nt "$objfile" ]; then
        echo "Compiling $file..."
        g++ -c $file -o $objfile -std=c++14 -O3 -g -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR        
      else
        echo "Skipping $file, object file is up to date."
      fi
    fi
  fi
done

echo "Creating the main.exe file"

if $RELEASE; then
  g++ *.o -o bin/release/main -L C:/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
else
  g++ *.o -o bin/debug/main -L C:/SDL2/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer
fi