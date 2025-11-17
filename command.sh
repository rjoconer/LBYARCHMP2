#!/bin/bash

nasm -f macho64 sdot.asm -o sdot.o

gcc -c c_sdot.c -o c_sdot.o -arch x86_64

gcc c_sdot.o sdot.o -o sdot -arch x86_64

./sdot
