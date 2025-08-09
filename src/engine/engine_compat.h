// Header for engine compatibility
#ifndef ENGINE_COMPAT_H
#define ENGINE_COMPAT_H

// Vec2short usage in header
extern Vec2short engine_resolution;
extern Vec2short viewport_size;

// Function declarations with old patterns
void engine_init_v2(Vec2short resolution);
Vec2short engine_get_viewport(void);

// Version constants
#define ENGINE_VERSION "2.5.1"
#define REQUIRED_DATLIB "DATlib 0.2"

#endif
