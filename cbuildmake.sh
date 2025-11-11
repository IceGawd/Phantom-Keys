#!/bin/bash

RELEASE=false

while getopts ":r" opt; do
	case $opt in
		r)
			echo "COMPILING RELEASE VERSION!"
			RELEASE=true
			;;
		/?)
			echo "Invalid option: -$OPTARG" >&2
			exit 1
			;;
	esac
done


if $RELEASE; then
	cmake -G "Ninja" -S . -B build -DCMAKE_BUILD_TYPE=Release -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
else
	cmake -G "Ninja" -S . -B build -DCMAKE_BUILD_TYPE=Debug -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++
fi

cmake --build build

if $RELEASE; then
	mv ./build/main.exe ./bin/release/main.exe
else
	mv ./build/main.exe ./bin/debug/main.exe
fi