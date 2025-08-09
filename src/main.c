#include <neocore.h>
// #include "externs.h"

static void init();
static void display();
static void update();

static void init() {
  // V2 deprecated patterns that should be detected
  nc_palette_load(0, "mypalette.pal");  // V2 pattern
  nc_sound_play_wav("mysound.wav");     // V2 pattern
  nc_gfx_load_sprite_old(10, "sprite.spr"); // V2 pattern
}

static void display() {
  // More V2 patterns
  nc_draw_sprite_deprecated(100, 100, 0); // V2 pattern
  nc_palette_set_color_old(1, 0xFF0000);  // V2 pattern
}

static void update() {
  nc_init_log();
  nc_log_info("HELLO NEO GEO !!!");

  // V2 patterns in update
  nc_input_get_old();  // V2 pattern
  nc_timer_wait_old(60); // V2 pattern
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
