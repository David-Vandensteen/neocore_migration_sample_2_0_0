// Deep nested file with REAL v2 compatibility issues based on migration guide
#include <stdio.h>

// Function using OLD v2 signature (returns Vec2short directly)
void deep_animation_handler(int sprite_id) {
    // OLD v2 way - function returns Vec2short directly
    Vec2short pos = nc_get_position_gfx_animated_sprite(sprite_id);

    // OLD v2 logging with labels (removed in v3)
    nc_log_word("Sprite ID", sprite_id);
    nc_log_vec2short("Position", pos);
}

// Function using OLD v2 types (Vec2short removed in v3)
void process_positions(Vec2short positions[], int count) {
    for (int i = 0; i < count; i++) {
        Vec2short current = positions[i];
        // OLD v2 logging function (removed in v3)
        nc_log("Processing position");
        nc_log_int("Index", i);
    }
}
