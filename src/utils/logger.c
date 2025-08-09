// Game logger with REAL v2 logging patterns
#include <stdio.h>

// Test all REAL v2 logging functions that were removed in v3
void game_logging_examples(void) {
    int score = 1500;
    int lives = 3;
    Vec2short player_pos = {100, 150};

    // OLD v2 logging functions - all removed in v3
    nc_log("Game session started");
    nc_log("Player spawned");

    // OLD v2 labeled logging functions - removed in v3
    nc_log_word("Score", score);
    nc_log_word("Lives", lives);
    nc_log_int("Level", 1);
    nc_log_vec2short("PlayerPos", player_pos);

    // More v2 logging
    nc_log("Combat initiated");
    nc_log_word("EnemyHP", 50);
    nc_log_int("Damage", 25);
}

// Function using v2 position retrieval
void debug_positions(void) {
    int player_sprite = 1;
    int ui_picture = 2;

    // OLD v2 function signatures (all changed in v3)
    Vec2short player_pos = nc_get_position_gfx_animated_sprite(player_sprite);
    Vec2short ui_pos = nc_get_position_gfx_picture(ui_picture);

    // OLD v2 debug logging
    nc_log("Debug position check");
    nc_log_vec2short("Player", player_pos);
    nc_log_vec2short("UI", ui_pos);
}
