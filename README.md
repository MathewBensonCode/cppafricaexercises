# My CPPAFRICA Exercise Solutions

This is my workspace for practicing C++ exercises as published on the [CppAfrica Discord server](https://discord.gg/fudRw3nH). 

## Setup Guide

I primarily use cmake for project setup and management. To work with the solutions you need to create a build directory where the project will be built, preferably outside of the source directory. After cloning the repository, change directories into the main directory and run the following:

```
mkdir -p ../builds/cppafrica
cmake -B ../builds/cppafrica
```
You should be able to build the project with 
```
cmake --build ../builds/cppafrica
```
