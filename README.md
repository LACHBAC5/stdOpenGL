### STDOPENGL

**purpose:** A collection of OpenGL code that may be frequently used.

**composition**

A stdOpenGL/ folder with many sub-folders like stdOpenGL/shader/ each containing .cpp and .h files.

**compilation**

Running make compiles **libcmple.c** and each **.cpp file** from each sub-folder into .o file into stdOpenGL/.

If any **.cpp files** are compiled, ./libcmple.out is run which uses the **ar** utility to combine .o files into .a files

