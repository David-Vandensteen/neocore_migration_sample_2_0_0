// Memory management utilities with v2 patterns
#ifndef MEMORY_UTILS_H
#define MEMORY_UTILS_H

// Function prototypes using deprecated memory functions
void* allocate_sprite_memory(size_t size);
void deallocate_sprite_memory(void* ptr);

// Vec2short for memory alignment
typedef struct {
    Vec2short dimensions;
    void* data;
} MemoryBlock;

#endif
