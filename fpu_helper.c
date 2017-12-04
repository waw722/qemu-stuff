#include <stdbool.h>
#include "fake_env.h"
#include "softfloat.h"

static inline void fpush(CPUX86State *env) {
    env->fpstt = (env->fpstt - 1) & 7;
    // validate stack entry
    env->fptags[env->fpstt] = 0;
}

static inline void fpop(CPUX86State *env) {
    // invalidate stack entry
    env->fptags[env->fpstt] = 1;
    env->fpstt = (env->fpstt + 1) & 7;
}
