// Simple sprite handler with REAL v2 patterns only
#include <stdio.h>

// REAL v2 function that changed signature in v3
void handle_sprite_movement(int sprite_id) {
    // OLD v2 function call - returns Vec2short directly
    Vec2short current_pos = nc_get_position_gfx_animated_sprite(sprite_id);

    // OLD v2 logging functions (all removed in v3)
    nc_log("Sprite movement update");
    nc_log_word("SpriteID", sprite_id);
    nc_log_vec2short("Position", current_pos);

    // Use the old type in calculations
    Vec2short new_pos;
    new_pos.x = current_pos.x + 10;
    new_pos.y = current_pos.y + 5;

    nc_log_vec2short("NewPos", new_pos);
}

// REAL v2 picture positioning (signature changed in v3)
void handle_picture_display(int picture_id) {
    // OLD v2 function call
    Vec2short pic_pos = nc_get_position_gfx_picture(picture_id);

    nc_log_int("PictureID", picture_id);
    nc_log_vec2short("PicturePos", pic_pos);
}

// REAL v2 scroller positioning (signature changed in v3)
void handle_scroller_update(int scroller_id) {
    // OLD v2 function call
    Vec2short scroll_pos = nc_get_position_gfx_scroller(scroller_id);

    nc_log("Scroller update");
    nc_log_word("ScrollerID", scroller_id);
    nc_log_vec2short("ScrollPos", scroll_pos);
}
