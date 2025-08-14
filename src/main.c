#include <neocore.h>
// #include "externs.h"

static void init();
static void display();
static void update();

static void init() {
  // Initialize NeoCore system
  nc_init_system();
}

static void display() {
  // Display logic here
}

static void update() {
  nc_init_log();
  nc_log_info("HELLO NEO GEO !!!");

  // Test the nc_get_relative_position v2 pattern (REAL breaking change)
  Box player_box;
  Position world_pos = {100, 50};
  Vec2short relative_pos = nc_get_relative_position(player_box, world_pos); // V2 pattern - should be detected

  // Test Vec2short usage (REAL v2 type that changed in v3)
  Vec2short player_position = {50, 100};
  Vec2short enemy_position;

  // Test old logging pattern (REAL v2 function)
  nc_log("Game state updated"); // V2 pattern - should be detected
}

int main(void) {
  init();
  // display();
  while(1) {
    nc_update();
    update();
  };
  return 0;
}
