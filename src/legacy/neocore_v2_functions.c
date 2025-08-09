// NeoCore v2 function patterns and signatures
#include <stdio.h>

// Test all the NeoCore v2 functions that changed in v3
void test_neocore_v2_functions(void) {
    Vec2short pos, pic_pos, scroll_pos;
    int player = 1, picture = 2, scroller = 3;

    // OLD v2 function signatures (all changed in v3)
    pos = nc_get_position_gfx_animated_sprite(player);        // Now takes pointer parameters
    pic_pos = nc_get_position_gfx_picture(picture);          // Now takes pointer parameters
    scroll_pos = nc_get_position_gfx_scroller(scroller);     // Now takes pointer parameters

    // OLD v2 logging functions (all deprecated in v3)
    nc_log("Game started");
    nc_log_word("Player HP", 100);
    nc_log_int("Score", 5000);
    nc_log_vec2short("Position", pos);
    nc_log_info("Info message");
    nc_log_debug("Debug message");
    nc_log_warn("Warning message");
    nc_log_error("Error message");

    printf("Position: %d, %d\n", pos.x, pos.y);
    printf("Picture position: %d, %d\n", pic_pos.x, pic_pos.y);
}

// Test functions with old type usage
void handle_sprite_positions(Vec2short positions[], int count) {
    for (int i = 0; i < count; i++) {
        Vec2short current = positions[i];
        nc_log_vec2short("Sprite position", current);

        // Using old function signature
        Vec2short new_pos = nc_get_position_gfx_animated_sprite(i);
        positions[i] = new_pos;
    }
}

// Test structure with Vec2short
typedef struct Player_v2 {
    Vec2short position;
    Vec2short velocity;
    Vec2short last_position;
    int health;
} Player_v2;

void update_player_v2(Player_v2* player) {
    player->last_position = player->position;

    // Get new position using old API
    player->position = nc_get_position_gfx_animated_sprite(0);

    // Calculate velocity
    player->velocity.x = player->position.x - player->last_position.x;
    player->velocity.y = player->position.y - player->last_position.y;

    nc_log_vec2short("Player moved to", player->position);
    nc_log_vec2short("Velocity", player->velocity);
}
