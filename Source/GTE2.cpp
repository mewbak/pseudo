#import "Global.h"


// Accessors
#define oooo(base, index) \
    base[(index)]

#define __oo(base, index, offset) \
    base[(index << 1) + offset]

// Cop2d
// --------------------------------
//  0 | VY0         | VX0         | Vector X, Y, Z (1.15.0) or (1.3.12)
//  1 |             | VZ0         |
//  2 | VY1         | VX1         |
//  3 |             | VZ1         |
//  4 | VY2         | VX2         |
//  5 |             | VZ2         |
// --------------------------------
//  6 | CODE | B    | G    | R    | Color data + GTE instruction (0.8.0)
// --------------------------------
//  7 |             | OTZ         | Z-component value (0.15.0)
// --------------------------------
//  8 | IR0                       | Intermediate value (1.3.12)
//  9 | IR1                       |
// 10 | IR2                       |
// 11 | IR3                       |
// --------------------------------
// 12 | SY0         | SX0         | Calculation result record X, Y, P (1.15.0)
// 13 | SY1         | SX1         |
// 14 | SY2         | SX2         |
// 15 | SYP         | SXP         |
// --------------------------------
// 16 |             | SZ0         | Calculation result record Z (0.16.0)
// 17 |             | SZ1         |
// 18 |             | SZ2         |
// 19 |             | SZ3         |
// --------------------------------
// 20 | CD0  | B0   | G0   | R0   | Color data (0.8.0)
// 21 | CD1  | B1   | G1   | R1   |
// 22 | CD2  | B2   | G2   | R2   |
// --------------------------------
// 23 | RES1                      |
// --------------------------------
// 24 | MAC0                      | Sum of products (1.31.0)
// 25 | MAC1                      |
// 26 | MAC2                      |
// 27 | MAC3                      |
// --------------------------------
// 28 | IRGB                      | Color data input/output (?)
// 29 | ORGB                      |
//---------------------------------
// 30 | LZCS                      | Lead zero/one count source data (1.31.0)
// --------------------------------
// 31 |                    | LZCR | Lead zero/one count process result (0.6.0)
// --------------------------------

#define VX0   __oo(cop2d.ish,  0, 0)
#define VY0   __oo(cop2d.ish,  0, 1)
#define VZ0   __oo(cop2d.ish,  1, 0)
#define VX1   __oo(cop2d.ish,  2, 0)
#define VY1   __oo(cop2d.ish,  2, 1)
#define VZ1   __oo(cop2d.ish,  3, 0)
#define VX2   __oo(cop2d.ish,  4, 0)
#define VY2   __oo(cop2d.ish,  4, 1)
#define VZ2   __oo(cop2d.ish,  5, 0)
#define R     ___o(cop2d.iub,  6, 0)
#define G     ___o(cop2d.iub,  6, 1)
#define B     ___o(cop2d.iub,  6, 2)
#define CODE  ___o(cop2d.iub,  6, 3)
#define OTZ   __oo(cop2d.iuh,  7, 0)
#define IR0   __oo(cop2d.ish,  8, 0)
#define IR1   __oo(cop2d.ish,  9, 0)
#define IR2   __oo(cop2d.ish, 10, 0)
#define IR3   __oo(cop2d.ish, 11, 0)
#define SX0   __oo(cop2d.ish, 12, 0)
#define SY0   __oo(cop2d.ish, 12, 1)
#define SX1   __oo(cop2d.ish, 13, 0)
#define SY1   __oo(cop2d.ish, 13, 1)
#define SX2   __oo(cop2d.ish, 14, 0)
#define SY2   __oo(cop2d.ish, 14, 1)
#define SXP   __oo(cop2d.ish, 15, 0)
#define SYP   __oo(cop2d.ish, 15, 1)
#define SZ0   __oo(cop2d.iuh, 16, 0)
#define SZ1   __oo(cop2d.iuh, 17, 0)
#define SZ2   __oo(cop2d.iuh, 18, 0)
#define SZ3   __oo(cop2d.iuh, 19, 0)
#define R0    ___o(cop2d.iub, 20, 0)
#define G0    ___o(cop2d.iub, 20, 1)
#define B0    ___o(cop2d.iub, 20, 2)
#define CD0   ___o(cop2d.iub, 20, 3)
#define R1    ___o(cop2d.iub, 21, 0)
#define G1    ___o(cop2d.iub, 21, 1)
#define B1    ___o(cop2d.iub, 21, 2)
#define CD1   ___o(cop2d.iub, 21, 3)
#define R2    ___o(cop2d.iub, 22, 0)
#define G2    ___o(cop2d.iub, 22, 1)
#define B2    ___o(cop2d.iub, 22, 2)
#define CD2   ___o(cop2d.iub, 22, 3)
#define RES1  oooo(cop2d.iuw, 23)
#define MAC0  oooo(cop2d.isw, 24)
#define MAC1  oooo(cop2d.isw, 25)
#define MAC2  oooo(cop2d.isw, 26)
#define MAC3  oooo(cop2d.isw, 27)
#define IRGB  oooo(cop2d.iuw, 28)
#define ORGB  oooo(cop2d.iuw, 29)
#define LZCS  oooo(cop2d.isw, 30)
#define LZCR  oooo(cop2d.iuw, 31)

// Cop2c
// --------------------------------
//  0 | R12         | R11         | Rotation matrix (1.3.12)
//  1 | R21         | R13         |
//  2 | R23         | R22         |
//  3 | R32         | R31         |
//  4 |             | R33         |
// --------------------------------
//  5 | TRX                       | Translation vector (1.31.0)
//  6 | TRY                       |
//  7 | TRZ                       |
// --------------------------------
//  8 | L12         | L11         | Lite source direction (1.3.12)
//  9 | L21         | L13         |
// 10 | L23         | L22         |
// 11 | L32         | L31         |
// 12 |             | L33         |
// --------------------------------
// 13 | RBK                       | Peripheral color (1.19.12)
// 14 | GBK                       |
// 15 | BBK                       |
// --------------------------------
// 16 | LR2         | LR1         | Lite source color (1.3.12)
// 17 | LG1         | LR3         |
// 18 | LG3         | LG2         |
// 19 | LB2         | LB1         |
// 20 |             | LB3         |
// --------------------------------
// 21 | RFC                       | Far color (1.27.4)
// 22 | BFC                       |
// 23 | GFC                       |
// --------------------------------
// 24 | OFX                       | Screen offset (1.15.16)
// 25 | OFY                       |
// --------------------------------
// 26 |             | H           | Screen position (0.16.0)
// --------------------------------
// 27 |             | DQA         | Depth parameter A (1.7.8)
// --------------------------------
// 28 | DQB                       | Depth parameter B (1.7.24)
// --------------------------------
// 29 |             | ZSF3        | Z scale factor (1.3.12)
// 30 |             | ZSF4        |
// --------------------------------
// 31 | FLAG                      | !
// --------------------------------

#define R11   __oo(cop2c.ish,  0, 0)
#define R12   __oo(cop2c.ish,  0, 1)
#define R13   __oo(cop2c.ish,  1, 0)
#define R21   __oo(cop2c.ish,  1, 1)
#define R22   __oo(cop2c.ish,  2, 0)
#define R23   __oo(cop2c.ish,  2, 1)
#define R31   __oo(cop2c.ish,  3, 0)
#define R32   __oo(cop2c.ish,  3, 1)
#define R33   __oo(cop2c.ish,  4, 0)
#define TRX   oooo(cop2c.isw,  5)
#define TRY   oooo(cop2c.isw,  6)
#define TRZ   oooo(cop2c.isw,  7)
#define L11   __oo(cop2c.ish,  8, 0)
#define L12   __oo(cop2c.ish,  8, 1)
#define L13   __oo(cop2c.ish,  9, 0)
#define L21   __oo(cop2c.ish,  9, 1)
#define L22   __oo(cop2c.ish, 10, 0)
#define L23   __oo(cop2c.ish, 10, 1)
#define L31   __oo(cop2c.ish, 11, 0)
#define L32   __oo(cop2c.ish, 11, 1)
#define L33   __oo(cop2c.ish, 12, 0)
#define RBK   oooo(cop2c.isw, 13)
#define GBK   oooo(cop2c.isw, 14)
#define BBK   oooo(cop2c.isw, 15)
#define LR1   __oo(cop2c.ish, 16, 0)
#define LR2   __oo(cop2c.ish, 16, 1)
#define LR3   __oo(cop2c.ish, 17, 0)
#define LG1   __oo(cop2c.ish, 17, 1)
#define LG2   __oo(cop2c.ish, 18, 0)
#define LG3   __oo(cop2c.ish, 18, 1)
#define LB1   __oo(cop2c.ish, 19, 0)
#define LB2   __oo(cop2c.ish, 19, 1)
#define LB3   __oo(cop2c.ish, 20, 0)
#define RFC   oooo(cop2c.isw, 21)
#define BFC   oooo(cop2c.isw, 22)
#define GFC   oooo(cop2c.isw, 23)
#define OFX   oooo(cop2c.isw, 24)
#define OFY   oooo(cop2c.isw, 25)
#define H     __oo(cop2c.iuh, 26, 0)
#define DQA   __oo(cop2c.ish, 27, 0)
#define DQB   oooo(cop2c.isw, 28)
#define ZSF3  __oo(cop2c.ish, 29, 0)
#define ZSF4  __oo(cop2c.ish, 30, 0)
#define FLAG  oooo(cop2c.iuw, 31)

void CstrMips::executeCop2(uw code) {
    switch(code & 63) {
    }
    
    printx("/// PSeudo Unknown Cop2 opcode: %d", (code & 63));
}