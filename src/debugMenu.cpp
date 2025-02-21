#include "debugMenu.hpp"
#include "debugMenuFuncs.hpp"
#include "bn_core.h"


void dbgMenu::mainLoop()
{
    int menu = 0;
    int option = 1;

    while(! bn::keypad::start_pressed())
    {
        handleInput(menu, option);
    }
}


void dbgMenu::update(int menu, int option)
{
    
    bn::sprite_text_generator small_fixed_text_generator(common::fixed_8x8_sprite_font);
    small_fixed_text_generator.set_center_alignment();

    bn::sprite_text_generator small_variable_text_generator(common::variable_8x8_sprite_font);
    small_variable_text_generator.set_center_alignment();

    bn::vector<bn::sprite_ptr, 32> text_sprites;
    small_variable_text_generator.generate(0, -dbgMenu::text_y_limit, "Impossible Game Advance - Debug Menu", text_sprites);

    bn::fixed text_y = -dbgMenu::text_y_inc - (dbgMenu::text_y_inc / 4);

    std::string result = "";

    if(menu == 0)
    {
        mainMenu(option, text_y, small_variable_text_generator, text_sprites);
    }
    else if(menu == 1)
    {
        levelSelect(option, text_y, small_variable_text_generator, text_sprites);
    }
    else if(menu == 2)
    {
        editorOptions(option, text_y, small_variable_text_generator, text_sprites);
    }
    else if(menu == 3)
    {
        recordOptions(option, text_y, small_variable_text_generator, text_sprites);
    }
    else if(menu == 4)
    {
        settingsMenu(option, text_y, small_variable_text_generator, text_sprites);
    }
    else if(menu == 5)
    {
        formatMenu(option, text_y, small_variable_text_generator, text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "ERROR: No data found for given menu ID", text_sprites);
    }

    bn::core::update();
}

void dbgMenu::showOptions(int)
{
    return;
}