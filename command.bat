nasm -f win64 sdot.asm
gcc -c c_sdot.c -o c_sdot.obj -m64
gcc c_sdot.obj sdot.obj -o sdot.exe -m64
sdot