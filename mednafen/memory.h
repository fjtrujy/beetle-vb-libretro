#ifndef _MDFN_MEMORY_H
#define _MDFN_MEMORY_H

// These functions can be used from driver code or from internal Mednafen code.
//

#include <stdint.h>

#define MDFN_malloc(size, purpose) MDFN_malloc_real(size, purpose, __FILE__, __LINE__)
#define MDFN_calloc(nmemb, size, purpose) MDFN_calloc_real(nmemb, size, purpose, __FILE__, __LINE__)
#define MDFN_realloc(ptr, size, purpose) MDFN_realloc_real(ptr, size, purpose, __FILE__, __LINE__)

void *MDFN_malloc_real(uint32_t size, const char *purpose, const char *_file, const int _line);
void *MDFN_calloc_real(uint32_t nmemb, uint32_t size, const char *purpose, const char *_file, const int _line);
void *MDFN_realloc_real(void *ptr, uint32_t size, const char *purpose, const char *_file, const int _line);
void MDFN_free(void *ptr);

static inline void MDFN_FastU32MemsetM8(uint32_t *array, uint32_t value_32, unsigned int u32len)
{
 for(uint32_t *ai = array; ai < array + u32len; ai += 2)
 {
  ai[0] = value_32;
  ai[1] = value_32;
 }
}

#endif
