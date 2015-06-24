#!/usr/bin/env bash
#g++ LOpenGL.h LUtil.h LUtil.cpp main.cpp -lglut -lGL -lGLU -lGLEW -lm -L/usr/include/GL
g++ LUtil.cpp main.cpp -w -lGL -lGLU -lglut -o 01_hello_freeglut
