// Engine subsystem with v2 type usage
#include <stdio.h>

// Using OLD v2 types in structures
typedef struct GameEntity {
    Vec2short position;    // OLD v2 type - removed in v3
    Vec2short velocity;    // OLD v2 type - removed in v3
    Vec2short bounds;      // OLD v2 type - removed in v3
    int health;
} GameEntity;

// Function using v2 types and signatures
void update_entities(GameEntity entities[], int count) {
    for (int i = 0; i < count; i++) {
        // OLD v2 function call
        Vec2short new_pos = nc_get_position_gfx_animated_sprite(i);
        entities[i].position = new_pos;

        // OLD v2 logging
        nc_log_word("EntityID", i);
        nc_log_vec2short("NewPosition", new_pos);
    }
}

// Another function with v2 patterns
void render_scene(void) {
    int background_pic = 0;

    // OLD v2 function signature
    Vec2short bg_pos = nc_get_position_gfx_picture(background_pic);

    nc_log("Scene render");
    nc_log_vec2short("BackgroundPos", bg_pos);
}
