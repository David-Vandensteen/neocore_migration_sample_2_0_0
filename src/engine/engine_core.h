#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

#include <neocore_v2.h>  // Deprecated header
#include <datlib_v2.h>   // Deprecated header

// Engine core header with v2 compatibility issues
#ifndef ENGINE_CORE_H
#define ENGINE_CORE_H

// OLD v2 type usage (Vec2short removed in v3)
#define ENGINE_VERSION "NeoCore 2.3.1"
#define DATLIB_VERSION_2_4

// Type definitions using deprecated Vec2short
typedef Vec2short Position;
typedef Vec2short Velocity;
typedef Vec2short Size;

// Core engine structures
typedef struct {
    Position camera_pos;
    Size screen_size;
    int frame_count;
} EngineState;

// Function prototypes
void engine_init();
void engine_shutdown();
void engine_update();

#endif // ENGINE_CORE_H
