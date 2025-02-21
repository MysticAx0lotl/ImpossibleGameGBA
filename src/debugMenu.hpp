#ifndef DEBUG_MENU
#define DEBUG_MENU

#include "bn_math.h"
#include "bn_keypad.h"
#include "bn_display.h"
#include "bn_sprite_ptr.h"
#include "bn_bg_palettes.h"
#include "bn_sprite_text_generator.h"
#include "common_fixed_8x8_sprite_font.h"
#include "common_fixed_8x16_sprite_font.h"
#include "common_variable_8x8_sprite_font.h"
#include "common_variable_8x16_sprite_font.h"

namespace dbgMenu 
{
    constexpr bn::fixed text_y_inc = 14;
    constexpr bn::fixed text_y_limit = (bn::display::height() / 2) - text_y_inc;

    void mainLoop();
    void mainMenu(int&, bn::fixed&, bn::sprite_text_generator&, bn::vector<bn::sprite_ptr, 32>&);
    void levelSelect(int&, bn::fixed&, bn::sprite_text_generator&, bn::vector<bn::sprite_ptr, 32>&);
    void editorOptions(int&, bn::fixed&, bn::sprite_text_generator&, bn::vector<bn::sprite_ptr, 32>&);
    void recordOptions(int&, bn::fixed&, bn::sprite_text_generator&, bn::vector<bn::sprite_ptr, 32>&);
    void settingsMenu(int&, bn::fixed&, bn::sprite_text_generator&, bn::vector<bn::sprite_ptr, 32>&);
    void formatMenu(int&, bn::fixed&, bn::sprite_text_generator&, bn::vector<bn::sprite_ptr, 32>&);
    void handleInput(int&, int&);
    void showOptions(int);
    void update(int, int);
}

#endif