#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

#define ERROR_EXIT(...) fprintf(stderr, __VA_ARGS__);
#define ERROR_RETURN(R, ...) ERROR_EXIT(__VA_ARGS__); return R;

#endif
