#!/usr/bin/env bash
mkdir -p ./bin
g++ LUtil.cpp main.cpp -w -lGL -lGLU -lglut -o ./bin/application.out
