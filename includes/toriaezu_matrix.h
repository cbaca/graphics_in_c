/** toriaezu_matrix.h */
#ifndef TORIAEZU_MATRIX_H_
#define TORIAEZU_MATRIX_H_
#define MAT_SIZE 16
#define VEC_SIZE 4
#define TORI_PI 3.141592653589793238462643383279502884197169399375105820974f
#define TORI_PI2 1.570796326794896619231321691639751442098584699687552910487f
#define TORI_PI3 1.047197551196597746154214461093167628065723133125035273658f
#define TORI_PI4 0.785398163397448309615660845819875721049292349843776455243f
#define TORI_PI6 0.523598775598298873077107230546583814032861566562517636829f
#define TORI_TAU 6.283185307179586476925286766559005768394338798750211641949f

enum ToriaezuStyle {
      TORI_DEBUG
    , TORI_MODEL
    , TORI_VIEW
    , TORI_CLIP
    , TORI_IDENTITY
    , TORI_ZERO
    , TORI_STYLE_ERROR
};
extern void tori_set(float *restrict, int);
extern void tori_copy(float *restrict, /* const */ float *restrict);
extern void tori_multiply(float *restrict, float *restrict);
extern void tori_transpose(float *restrict);
extern void tori_get_translate(float *restrict, float, float, float);
extern void tori_get_rotate(float *restrict, double);
extern void debug_tori_print(const float *);
typedef float mat4;
#endif /** TORIAEZU_MATRIX_H_ */
