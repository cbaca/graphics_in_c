![windmill](docs/windmill.png)
#Windmill3D

##Goal: Create a virtual landscape that a use can wander around on. Place a rotating windmill on the ground, along with some buildings.

### Dependencies:
- [glfw3](https://www.archlinux.org/packages/community/x86_64/glfw-x11/)
- [SOIL.h](https://www.archlinux.org/packages/community/i686/soil/)
- [openGL/glew.h](https://www.archlinux.org/packages/extra/x86_64/glew/)

### Resources used:
- learnopengl.com
- [Awesome face image](http://learnopengl.com/img/textures/awesomeface.png)
- [What Every Programmer Should Know About Memory.pdf](https://www.google.com/search?q=What+every+programmer+should+know+about+memory) by Ulrich Drepper

### Resources I want to use, but haven't had a chance yet:
- [Font image](http://webglfundamentals.org/webgl/resources/8x8-font.png)
- [Euler Angles](https://en.wikipedia.org/wiki/Aircraft_principal_axes)
- [Gimbal locks](https://en.wikipedia.org/wiki/Gimbal_lock)
- [OpenGL Mathematics](https://github.com/g-truc/glm)
- [Torque 3D Videogame Engine](https://github.com/GarageGames/Torque3D)
- [Particles](https://www.khronos.org/registry/webgl/sdk/demos/google/particles/)
  , a webgl demo application by google
- [Graphics Programming Black Book by Michael Abrash](https://github.com/mcmihai/GPBB)

### Home workspace:
- 4.7.2-1-ARCH x86_64 GNU/Linux
- Intel(R) Core(TM) i5-2320 CPU @ 3.00GHz (sandybridge)

### Current state:
- Successfully drawing a 2D rectangle with colors and texture from png
- reading, storing, and interacting with keyboard input successfully
- matrix math is not breaking the program, I think

### Goals:
- use a world coordinate system that is much wider than NVC.
- create texture-mapped geometry to represent the ground - using a quad.
- use a single cube object to create ALL models.
- use instance transformations to translate, scale and rotate all objects.
- make at least ONE building have a different color on every side.
- use two program objects (two shader programs?): one for textured objects,
  and one for non-textured objects.
- place a windmill in the scene: will have different colors for each face for
  each part, using a minimum of 5 instances of cube objects.
- provide keyboard controls: must be scales to make navigation easy for the user
    - *w key: toggle windmill blade rotation.*
    - *y key: toggle windmill spin about the yaw axis.*
    - *left/right: change direction of view about the yaw axis.*
    - *up/down: move the user forward/backward along the axis of view.*
- use perspective projection.
- note: don't forget to enable hidden surface removal and clear the depth buffer.

### Todo:
- make a damn windmill
- generate first 3D cube
- math/inversion
- math/orthogonal projection
- math/perspective projection
- math/viewing matrix
- math/refactoring and optimization
- math/try x86intrin.h for vectorization and optimization in toriaezu libs

### Next goal:3Dcube:
- update toriaezu math library to deal with projection/view/clipping
- update main to get uniform locations for new mat4s
- consider making seperate object file for input controls/matrix operations

### Need to know vocab:
- NDC aka Normalized Device Coordinates: range of coordinate visibility,
  minus 1.0 to plus 1.0

### Current direcotry tree courtesy of [tree](http://mama.indstate.edu/users/ice/tree/):
```
.
├── base
│   ├── graphics.c
│   ├── input.c
│   ├── keys.h
│   ├── main.c
│   ├── window.c
│   └── _window.h
├── docs
│   └── windmill.png
├── includes
│   ├── graphics.h
│   ├── input.h
│   └── toriaezu_matrix.h
├── Makefile
├── README.md
├── textures
│   ├── awesomeface.png
│   └── font.png
└── toriaezu_matrix
    ├── data_type.c
    ├── data_type.h
    ├── debug.c
    ├── enum.h
    ├── macros.h
    ├── mat_manip.c
    ├── toriaezu_matrix.c
    ├── toriaezu_matrix.h
    └── _vec.h
```
