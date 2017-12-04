#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "fake_env.h"
#include "softfloat.h"

void error(char *msg) {
    printf("error %s\n", msg);
    exit(1);
}

void print_floatx80(floatx80 x) {
    printf("Floatx80: mant: %li\t exp: %i", x.low, x.high);
}

void print_cpu_state(CPUX86State *env) {
    int i;
    printf("CPUX86State: fpus: %x fpuc: %x\n", env->fpus, env->fpuc);
    for (i = 0; i < 8; i++) {
        printf("Reg %i: ", i);
        print_floatx80(ST(i));
        printf("\t tags: %i\n", env->fptags[i]);
    }
}

void clear_state(CPUX86State *env) {
    int i;
    // init stack pointer with 7 for empty, grows down
    env->fpstt = 7;
    // clear out register tags, invalidate all entries
    *(uint32_t *)(env->fptags) = 0x01010101;
    *(uint32_t *)(env->fptags + 4) = 0x01010101;
    // clear out floating point registers
    for (i = 0; i < 8; i++) env->fpregs[i].d = make_floatx80(0, 0);
}

int main() {
    CPUX86State *env = (CPUX86State *)malloc(1 * sizeof(CPUX86State));
    clear_state(env);
    print_cpu_state(env);
    return 0;
}
