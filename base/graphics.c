/** graphics.c
*/
#include <stdio.h>
#include <stdlib.h>

const char *const *VSHADER_STRING = (const char *[]) {
    "#version 330 core\n"

    "layout (location = 0) in vec3 a_position; "
    "layout (location = 1) in vec4 a_color; "
    "layout (location = 2) in vec2 a_tex; "
    // "layout (location = 3) in mat4 u_transform; "

    "out vec4 v_color; "
    "out vec2 v_tex; "

    "uniform mat4 u_transform; "

    "void main() "
    "{ "
    //"   gl_Position = vec4(a_position, 1.0f) * u_transform; "
    "   gl_Position = u_transform * vec4(a_position, 1.0f); "
    "   v_color = a_color; "
    "   v_tex = vec2(a_tex.x, 1.0 - a_tex.y); "
    "}\0"
};

const char *const *FSHADER_STRING = (const char *[]) {
    "#version 330 core\n"

    "in vec4 v_color; "
    "in vec2 v_tex; "
    "out vec4 color; "

    "uniform sampler2D u_texture; "

    "void main() "
    "{ "
    "   color = mix(texture(u_texture, v_tex), v_color, 0.2); "
    "}\0"
};

/** 頂点（ちょうてん）配列 aka バッファ
 *  頂点配列初期化
 *  ベクトルとしてGPUに渡します
 */
float VERTICES4[32] = {
   /** 場所                  色                  テキスチャ */
       0.2f,  0.2f, 0.0f,    1.0f, 0.0f, 0.0f,   1.0f, 1.0f /** 上右 */
    ,  0.2f, -0.2f, 0.0f,    0.0f, 1.0f, 0.0f,   1.0f, 0.0f /** 下右 */
    , -0.2f, -0.2f, 0.0f,    0.0f, 0.0f, 1.0f,   0.0f, 0.0f /** 下左 */
    , -0.2f,  0.2f, 0.0f,    1.0f, 1.0f, 0.0f,   0.0f, 1.0f /** 上右 */
};

/** ebo aka エレメント配列バッファー使用 */
unsigned int INDEX_ARRAY3[6] = {
      0, 1, 3 /** 三角さん第一目 */
    , 1, 2, 3 /** 三角さん第二目
      あわせて一匹の四角さんとなる
      */
};

/** ３Dキューブにこれを使えろと */
/*
float VERTICES36[108] = {
      -0.5,  0.5,  0.5
    , -0.5, -0.5,  0.5,
    ,  0.5, -0.5,  0.5,
    , -0.5,  0.5,  0.5,
    ,  0.5, -0.5,  0.5,
    ,  0.5,  0.5,  0.5,
    ,  0.5,  0.5,  0.5,
    ,  0.5, -0.5,  0.5,
    ,  0.5, -0.5, -0.5,
    ,  0.5,  0.5,  0.5,
    ,  0.5, -0.5, -0.5,
    ,  0.5,  0.5, -0.5,
    ,  0.5, -0.5,  0.5,
    , -0.5, -0.5,  0.5,
    , -0.5, -0.5, -0.5,
    ,  0.5, -0.5,  0.5,
    , -0.5, -0.5, -0.5,
    ,  0.5, -0.5, -0.5,
    ,  0.5,  0.5, -0.5,
    , -0.5,  0.5, -0.5,
    , -0.5,  0.5,  0.5,
    ,  0.5,  0.5, -0.5,
    , -0.5,  0.5,  0.5,
    ,  0.5,  0.5,  0.5,
    , -0.5, -0.5, -0.5,
    , -0.5,  0.5, -0.5,
    ,  0.5,  0.5, -0.5,
    , -0.5, -0.5, -0.5,
    ,  0.5,  0.5, -0.5,
    ,  0.5, -0.5, -0.5,
    , -0.5,  0.5, -0.5,
    , -0.5, -0.5, -0.5,
    , -0.5, -0.5,  0.5,
    , -0.5,  0.5, -0.5,
    , -0.5, -0.5,  0.5,
    , -0.5,  0.5,  0.5
};
*/
