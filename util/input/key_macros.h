/** key_macros.h */
#ifndef WINDMILL_KEY_MACROS_H_
#define WINDMILL_KEY_MACROS_H_
/* 整数型じゃこれくらいべつのステートがあるね */
enum WindmillKeyMasks {
//    KEY_NULL  =       0x00
      KEY_W     =       0x01 /* 前行動  bit pos 1 */
    , KEY_S     =       0x02 /* 後移動  bit pos 2 */
    , KEY_A     =       0x04 /* 左移動  bit pos 3 */
    , KEY_D     =       0x08 /* 右移動  bit pos 4 */

    , KEY_K     =       0x10 /* 上向き  bit pos 5 */
    , KEY_J     =       0x20 /* 下向き  bit pos 6 */
    , KEY_H     =       0x40 /* 左向き  bit pos 7 */
    , KEY_L     =       0x80 /* 右向き  bit pos 8 */

    , KEY_SPACE =     0x0100 /* ジャンプにしようかな */
    , KEY_SHIFT =     0x0200 /* キー機能変換 */
};
#endif
    //, KEY_xxx =     0x0400
    //, KEY_xxx =     0x0800

    //, KEY_xxx = 0x00001000
    //, KEY_xxx = 0x00002000
    //, KEY_xxx = 0x00004000
    //, KEY_xxx = 0x00008000

    //, KEY_xxx = 0x00010000
    //, KEY_xxx = 0x00020000
    //, KEY_xxx = 0x00040000
    //, KEY_xxx = 0x00080000

    //, KEY_xxx = 0x00100000
    //, KEY_xxx = 0x00200000
    //, KEY_xxx = 0x00400000
    //, KEY_xxx = 0x00800000

    //, KEY_xxx = 0x01000000
    //, KEY_xxx = 0x02000000
    //, KEY_xxx = 0x04000000
    //, KEY_xxx = 0x08000000

    //, KEY_xxx = 0x10000000
    //, KEY_xxx = 0x20000000
    //, KEY_xxx = 0x40000000
    //, KEY_xxx = 0x80000000
/* 俺のパソコンじゃーこうだってな */
// Register sizes of various data types:
// 	                  bytes bits
// 	                  ----- -----
//                   char:   1       8
//          unsigned char:   1       8
//                  short:   2      16
//         unsigned short:   2      16
//                    int:   4      32
//           unsigned int:   4      32
//               long int:   8      64
//      long unsigned int:   8      64
//          long long int:   8      64
// long long unsigned int:   8      64
//                  float:   4      32
//                 double:   8      64
//            long double:  16     128
//             __float128:  16     128
//                  int *:   8      64
//                 void *:   8      64
//                float64:   8      64
//                float80:  16     128
//                type_tc:   8      64
//                     tc:   8      64
