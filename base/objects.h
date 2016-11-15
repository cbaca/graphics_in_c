/* objects.h */
#ifndef WINDMILL_OBJECTS_H_
#define WINDMILL_OBJECTS_H_

/** player */
typedef struct {
    float *restrict pos;
    float *restrict frt; 
    // float *restrict up;
    float *restrict rgt
    float vel;
} camera_t; /* look at model */

typedef struct {
    float yaw;
    float pitch;
} euler_t;


/** windmill */
typedef struct {
    float a[16]; /* model matrix */
    float dx;
} _sail;

typedef struct {
    float body[16]; /* model matrix */
    _sail_t sails[4];
    float dy;
} windmill_t;
#endif
