![windmill](docs/windmill.png)
#Windmill3D

##Goal: Create a virtual landscape that a use can wander around on. Place a rotating windmill on the ground, along with some buildings.

### Dependencies:
- [glfw3](https://www.archlinux.org/packages/community/x86_64/glfw-x11/)
- [SOIL.h](https://www.archlinux.org/packages/community/i686/soil/)
- [openGL/glew.h](https://www.archlinux.org/packages/extra/x86_64/glew/)

### Resources used:
- [Rotation matrices](https://en.wikipedia.org/wiki/Rotation_matrix)
- [Awesome face image](http://learnopengl.com/img/textures/awesomeface.png)
- [learnopengl.com pdf](http://learnopengl.com/book/offline%20learnopengl.pdf) by Joey de Vries.
- [Vector normalization](http://www.fundza.com/vectors/normalize/)
- [OpenGL Projection Matrix](http://www.songho.ca/opengl/gl_projectionmatrix.html) by Song He Ahn.
- [What Every Programmer Should Know About Memory.pdf](https://www.google.com/search?q=What+every+programmer+should+know+about+memory) by Ulrich Drepper.

### Resources I want to use, but haven't had a chance yet:
- [Particles](https://www.khronos.org/registry/webgl/sdk/demos/google/particles/)
- [Font image](http://webglfundamentals.org/webgl/resources/8x8-font.png)
- [Euler Angles](https://en.wikipedia.org/wiki/Aircraft_principal_axes)
- [Gimbal locks](https://en.wikipedia.org/wiki/Gimbal_lock)
- [OpenGL Mathematics](https://github.com/g-truc/glm)
- [Perspective projection](https://en.wikipedia.org/wiki/3D_projection#Perspective_projection)
- [Torque 3D Videogame Engine](https://github.com/GarageGames/Torque3D)
  , a webgl demo application by google
- [Graphics Programming Black Book by Michael Abrash](https://github.com/mcmihai/GPBB)

### Home workspace:
- OS: 4.7.2-1-ARCH x86_64 GNU/Linux
- CPU: Intel(R) Core(TM) i5-2320 CPU @ 3.00GHz (sandybridge)
- GPU: AMD Redwood LE Radeon HD 5550/5570/5630/6390/6490/7570

### Next goal 3Dcube:
- update geometry math dir with projection/view/clipping, converting
  coordinates for objects between spaces:
    - local space, local object coords.
    - world space(uses MODEL matrix), coordinates of each object relative to
      the "world". Model matrix will place an object in the world using
      transformations: translate/scale/rotate.
    - view space(used VIEW matrix), transforms world space to coordinates that
      are in front of the user's view. Accomplished with a combination of
      translations and rotations that will move the scene so that certain items
      are transformed to the front of the camera.
    - clipping(projection matrix), specifies a range of coords e.g. -1000 to
      1000 in each dimansion. Then, transforms the coords within this range to
      NDC(-1.0 to 1.0). This conversion is like creating a "viewing box", which
      is called the "frustrum"(if you cut off the tip of a pyramid, the plane
      that the knife was parallel to would be the frustrum). Everything in the
      frustrum after conversion will be displayed.
        - perspective division: division of x, y, and z components of position
          vectors by the vector's homogeneous W component(performed
          automagically by the end of each vshader run?, Joey de Vries, pg98).
    - screen space: resulting coordingates are mapped to screen coords using
      settings of glViewport, and turned into fragments.
- consider making seperate object file for input controls/matrix operations

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
- perspective projection
- viewing matrix
- refactoring and optimization
    - try x86intrin.h for vectorization and optimization in geometry math

### Need to know vocab:
- NDC aka Normalized Device Coordinates: range of coordinate visibility,
  minus 1.0 to plus 1.0
- HSR aka hidden surface removal

### Current direcotry tree courtesy of [tree](http://mama.indstate.edu/users/ice/tree/):
```
.
├── base/
│   ├── graphics.c
│   ├── main.c      /* requires GL/glew.h and GLFW/glfw3.h */
│   ├── window.c    /* requires GL/glew.h GLFW/glfw3.h SOIL.h */
│   └── window.h
│
├── docs/
│   └── windmill.png
│
├── include/
│   ├── input.h
│   └── mat4array.h
│
├── Makefile
├── README.md
├── obj/
│
├── textures/
│   ├── awesomeface.png
│   └── font.png
│
└── utils/
    ├── geometry/
    │   │
    │   ├── header/
    │   │   └── mat4array_defs.h
    │   │
    │   ├── include/
    │   │   ├── mat4array_copy.h
    │   │   ├── mat4array_make.h
    │   │   ├── mat4array_multiply.h
    │   │   ├── mat4array_print.h
    │   │   ├── mat4array_rotate.h
    │   │   ├── mat4array_translate.h
    │   │   ├── mat4array_transpose.h
    │   │   └── rowVecMat4.h
    │   │
    │   ├── mat4array_copy.c
    │   ├── mat4array_make.c
    │   ├── mat4array_multiply.c
    │   ├── mat4array_print.c
    │   ├── mat4array_rotate.c
    │   ├── mat4array_translate.c
    │   ├── mat4array_transpose.c
    │   │
    │   ├── rowVecMat4/
    │   │   ├── make_rowVecMat4.c
    │   │   └── rowVecMat4_t.h
    │   │
    │   ├── toriaezu_matrix.c
    │   └── toriaezu_matrix.h
    └── input/
        ├── input.c           /* requires GLFW/glfw3.h */
        └── key_macros.h
```
