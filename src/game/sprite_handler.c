// Sprite handler with REAL v2 patterns from NeoCore v2.0.0
#include <stdio.h>

// REAL v2 function signatures that changed in v3
void handle_sprite_movement(int sprite_id) {
    // OLD v2 function call - returned Vec2short directly in v2, now uses Position* in v3
    Vec2short current_pos = nc_get_position_gfx_animated_sprite(sprite_id); // V2 pattern

    // OLD v2 logging function (REAL function that existed in v2)
    nc_log("Sprite movement update"); // V2 pattern

    // Use the old Vec2short type (REAL v2 type, replaced with Position in v3)
    Vec2short new_pos;
    new_pos.x = current_pos.x + 10;
    new_pos.y = current_pos.y + 5;

    // Test another real v2 logging function
    nc_log_vec2short("NewPos", new_pos); // V2 pattern
}

// REAL v2 picture positioning (signature changed in v3)
void handle_picture_display(int picture_id) {
    // OLD v2 function call - returned Vec2short in v2, now uses Position* in v3
    Vec2short pic_pos = nc_get_position_gfx_picture(picture_id); // V2 pattern

    // Test relative position calculation with v2 pattern (REAL breaking change)
    Box collision_box;
    Position world_coord = {200, 150};
    Vec2short relative = nc_get_relative_position(collision_box, world_coord); // V2 pattern

    nc_log_vec2short("RelativePos", relative); // V2 pattern
}

// REAL v2 scroller positioning (signature changed in v3)
void handle_scroller_update(int scroller_id) {
    // OLD v2 function call - returned Vec2short in v2, now uses Position* in v3
    Vec2short scroll_pos = nc_get_position_gfx_scroller(scroller_id); // V2 pattern

    nc_log("Scroller update"); // V2 pattern
}
