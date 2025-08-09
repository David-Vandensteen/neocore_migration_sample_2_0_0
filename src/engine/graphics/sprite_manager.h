#ifndef SPRITE_MANAGER_H
#define SPRITE_MANAGER_H

// Vec2short type definitions (deprecated)
typedef struct {
    Vec2short position;
    Vec2short velocity;
} Sprite;

// Function declarations
void init_sprite_manager();
void update_sprites();

// NeoCore version 2.1 specific code
#define NEOCORE_VERSION_2_1

#endif // SPRITE_MANAGER_H
