@echo off

g++ src/*.cpp -o bin/release/main -std=c++14 -O3 -Wall -m64 -Iinclude -IC:/SDL2_x64/include -L C:/SDL2_x64/lib -lmingw32 -lSDL2main -lSDL2 -lSDL2_image -s -static-libgcc -static-libstdc++  && start bin/release/main

echo compiled code at release

pause