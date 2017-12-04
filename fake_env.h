#include <stdint.h>
#include "softfloat.h"

#ifndef __FAKE_ENV_H
#define __FAKE_ENV_H


typedef union {
    floatx80 d;
} FPReg;

/* float macros */
#define FT0     (env->ft0)
#define ST0     (env->fpregs[env->fpstt].d)
#define ST(n)   (env->fpregs[(env->fpstt + (n)) & 7].d)
#define ST1     ST(1)

typedef struct CPUX86State {
    unsigned int fpstt;
    uint16_t fpus;
    uint16_t fpuc;
    uint8_t fptags[8];
    FPReg fpregs[8];
} CPUX86State;

#endif
