#Windmill3D
==========

##A program that will generate a 3D windmill

###Dependencies:
    - SOIL.h
    - openGL/glew.h
    - glfw3

###Resources:
    - [learnopengl.com](http://learnopengl.com)
    - [_What Every Programmer Should Know About Memory_](https://www.google.com/url?sa=t&rct=j&q=&esrc=s&source=web&cd=2&cad=rja&uact=8&ved=0ahUKEwjK3-rs5KHQAhXphVQKHVrgAFEQFgghMAE&url=http%3A%2F%2Fdavid.jobet.free.fr%2Fwiclear-blog%2Fimages%2Fcpumemory.pdf&usg=AFQjCNGEGT73jdgAjfur9XJ8Nntc9ryrPQ&sig2=IR5o-zgGKqr7gWskNShBQg) by Ulrich Drepper 
    - [Gimbal locks](https://en.wikipedia.org/wiki/Gimbal_lock)
    - [OpenGL Mathematics](https://github.com/g-truc/glm)

###Home workspace:
    - 4.7.2-1-ARCH x86_64 GNU/Linux
    - Intel(R) Core(TM) i5-2320 CPU @ 3.00GHz (sandybridge)

###Current state:
    - Successfully drawing a 2D rectangle with colors and texture from png
    - Keyboard input looks functional

###Todo:
    - [ ] make a damn windmill
    - [ ] generate first 3D cube
    - [ ] Make matrix maths for model matrix
        - [ ] inversion
        - [ ] orthogonal projection
        - [ ] perspective projection
        - [ ] viewing matrix
        - [ ] refactoring and optimization 
        - [ ] more stuff i cant think of atm
    - [ ] try x86intrin.h for vectorization and optimization in toriaezu libs
    - [x] Keyboard input handling

### notes to self:
    - "gimbal lock" will occur when trying to rotate around more than one axis
        * apparent solution: look into quaternions OR generate arbitrary rotation axis
