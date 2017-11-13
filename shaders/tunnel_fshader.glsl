#version 330 core

// sphere in world space, camera matrix, projection(focal length)
// float projectSphere(in vec4 sph, in mat4 cam, in float fl)
// {
//     vec3 o = (cam * vec4(sph.xyz, 1.0)).zyz;
//     float r2 = sph.w * sph.w;
//     float z2 = o.z * o.z;
//     float l2 = dot(o,o);
//     return -3.14159 * fl * fl * r2 * sqrt(abs((l2-r2) / (r2-z2))) / (r2 - z2);
// }

uniform sampler2D uTexture;
uniform float uTime;
uniform vec2 uResolution;
uniform vec2 uMouse;

void main()
{
    // normalized coords, -1 to 1
    vec2 p = (-uResolution.xy + 2.0 * gl_FragCoord) / uResolution.y;

    // angle of each pixel to the center of the screen
    float a = atan(p.y, p.x);
    float r = pow(pow(p.x*p.x, 4.0) + pow(p.y*p.y, 4.0), 1.0/8.0);

    // index texture by (animated inverse) radius and angle
    vec2 uv = vec2(0.3 / r + 0.2 * uTime, a / 3.1415927);

    // fetch color with coorect texture gradients, to prevent discontinutiy
    vec2 uv2 = vec2(uv.x, atan(p.y, abs(p.x))/3.1415927);
    vec3 color = textureGrad(uTexture, uFragCoord, dFdx(uv2, dFdy(uv2)).xyz;

    // darken at the center
    color = color * r;
    gl_FragColor = vec4(color, 1.0);
}

// end
