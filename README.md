Vivid
=====

**Vivid** is a game engine created by [Ole Marius Strøhm](https://github.com/OleStrohm) and [Elias Forstrøm Fyksen](https://github.com/eliasffyksen).

 Code
-----

The engine is written in C++ and uses [GLFW](http://www.glfw.org/) for windows, [GLEW](http://glew.sourceforge.net/) for rendering, and a custom library for mathematics. A custom library is used to load images (currently only suppports the PNG format).

Features
-----

The foundation of the engine is built upon a scene graph allowing for easy addition of child objects. **GameObjects** and **GameComponents** make the primary building blocks of entities in the engine.

Essential features like transformations, textures and input are also included.

### Input

Input is an essential part of a game engine and our custom input engine, built on top of GLFW's raw input, is extremely fast. Instead of lists of pressed buttons it uses a counting technique which results in negligible response times.