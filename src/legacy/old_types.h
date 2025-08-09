// Legacy types header - contains obsolete v2 types
#ifndef OLD_TYPES_H
#define OLD_TYPES_H

// Vec2short usage (obsolete in v3)
typedef struct {
    Vec2short position;
    Vec2short velocity;
} LegacySprite;

// Function declarations using old types
Vec2short get_sprite_position(int sprite_id);
void set_sprite_position(int sprite_id, Vec2short pos);

// DATlib version reference
#define DATLIB_VERSION "DATlib 0.2"

#endif
