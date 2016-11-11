Windmill3D
==========

A program that will generate a 3D windmill

Dependencies:
    -SOIL.h
    -openGL/glew.h
    -glfw3

Resources:
    -learnopengl.com
    -"What Every Programmer Should Know About Memory" by Ulrich Drepper
    -`Gimbal locks`_.
    .. _Wikipedia: https://en.wikipedia.org/wiki/Gimbal_lock

Home workspace:
    -4.7.2-1-ARCH x86_64 GNU/Linux
    -Intel(R) Core(TM) i5-2320 CPU @ 3.00GHz (sandybridge)

Current state:
    -Successfully drawing a 2D rectangle with colors and texture from png

Todo:
    -generate first 3D cube
    -Make matrix maths for model matrix
        -inversion
        -orthogonal projection
        -perspective projection
        -viewing matrix
        -refactoring and optimization 
    -try x86intrin.h for vectorization
    -finish Keyboard input handling

New things I learned:
    -C allows main() to be called recursively (not tested)

PS_to_self:
    -"gimbal lock" will occur when trying to rotate around more than one axis
        -solution: look into quaternions OR generate arbitrary rotation axis
