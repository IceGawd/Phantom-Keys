#!/bin/bash

set -e

# Define directories
SRCDIR=src
INCLUDEDIR=include
SDLINCLUDEDIR=C:/SDL2/include
OBJDIR=obj/debug
RESOURCEDIR=res
OUTDIR=bin/debug/res

# Parse flags
FULL=false
RELEASE=false
DOCSGENERATOR=false
GDBDEBUG=false
SYNC=false

while getopts ":frdgs" opt; do
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
		s)
			echo "SYNCING!"
			SYNC=true
			;;
		\?)
			echo "Invalid option: -$OPTARG" >&2
			exit 1
			;;
	esac
done

if $DOCSGENERATOR; then
	 g++ -c iceDocsGenerator.cpp -std=c++17 -g -m64 -o obj/iceDocsGenerator.o
	 g++ obj/iceDocsGenerator.o -o iceDocsGenerator
	 exit 0
fi

if $RELEASE; then
	OBJDIR=obj/release
	OUTDIR=bin/release/res
elif $GDBDEBUG; then
	OBJDIR=obj/gdb
	OUTDIR=bin/gdb/res
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
				g++ -c $file -o $objfile -std=c++17 -O3 -g -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
			elif $GDBDEBUG; then
				g++ -c $file -o $objfile -std=c++17 -g3 -O0 -fno-omit-frame-pointer -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
			else
				g++ -c $file -o $objfile -std=c++17 -g -m64 -I $INCLUDEDIR -I $SDLINCLUDEDIR
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

if $SYNC; then
	mkdir -p "$OUTDIR"

	echo "Syncing resources between '$RESOURCEDIR' and '$OUTDIR'..."

	rsync -ru --delete "$RESOURCEDIR"/ "$OUTDIR"/

	rsync -ru "$OUTDIR"/ "$RESOURCEDIR"/

	echo "Resource sync complete!"
fi