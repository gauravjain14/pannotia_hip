#include "hip/hip_runtime.h"
#include "stdlib.h"
#include "stdio.h"

#define hipMalloc(ptr, size) ({fprintf(stderr, "MALLOC\n"); int* tptr = (int*) malloc(size); if (!tptr) {fprintf(stderr, "MALLOC FAILED");}; *ptr = tptr; hipSuccess;})
#define hipMemcpy(dest, src, size, hiptype) ({fprintf(stderr, "MEMCPY\n"); if (hiptype == hipMemcpyHostToDevice) {memcpy(dest, src, size);} else {memcpy(dest, src, size);} hipSuccess;})
#define hipDeviceSynchronize() ({;})
#define hipFree(addr) ({free(addr);})

