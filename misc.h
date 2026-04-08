#ifndef MISC_H
#define MISC_H

// Prints size in bits: #pragma GCC diagnostic ignored -Wpointer-arith (optional, for clarity)
#define SIZE_IN_BITS(x) printf("%zu\n", sizeof(x) * 8)

// Prints size in bytes
#define SIZE_IN_BYTES(x) printf("%zu\n", sizeof(x))

// basic Error Logging
#define LOG_ERROR(msg) \
    fprintf(stderr, "Error in %s:%d: %s\n", __FILE__, __LINE__, (msg))


#endif
