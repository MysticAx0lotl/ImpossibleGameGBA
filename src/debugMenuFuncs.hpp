#include "debugMenu.hpp"

void dbgMenu::mainMenu(int& option, bn::fixed& text_y, bn::sprite_text_generator& small_variable_text_generator, bn::vector<bn::sprite_ptr, 32>& text_sprites)
{
    if(option == 1)
    {
        small_variable_text_generator.generate(0, text_y, "<Play>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Play", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 2)
    {
        small_variable_text_generator.generate(0, text_y, "<Level Editor>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Level Editor", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 3)
    {
        small_variable_text_generator.generate(0, text_y, "<Records>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Records", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 4)
    {
        small_variable_text_generator.generate(0, text_y, "<Settings>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Settings", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
}

void dbgMenu::levelSelect(int& option, bn::fixed& text_y, bn::sprite_text_generator& small_variable_text_generator, bn::vector<bn::sprite_ptr, 32>& text_sprites)
{
    if(option == 1)
    {
        small_variable_text_generator.generate(0, text_y, "<Fire Aura>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Fire Aura", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 2)
    {
        small_variable_text_generator.generate(0, text_y, "<Fire Aura (XBLA)>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Fire Aura (XBLA)", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 3)
    {
        small_variable_text_generator.generate(0, text_y, "<Chaoz Fantasy>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Chaoz Fantasy", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 4)
    {
        small_variable_text_generator.generate(0, text_y, "<Heaven>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Heaven", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 5)
    {
        small_variable_text_generator.generate(0, text_y, "<Phazd>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Phazd", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
    
    if(option == 6)
    {
        small_variable_text_generator.generate(0, text_y, "<Secret>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Secret", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 7)
    {
        small_variable_text_generator.generate(0, text_y, "<Return>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Return", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
}

void dbgMenu::editorOptions(int& option, bn::fixed& text_y, bn::sprite_text_generator& small_variable_text_generator, bn::vector<bn::sprite_ptr, 32>& text_sprites)
{
    if(option == 1)
    {
        small_variable_text_generator.generate(0, text_y, "<Create Level>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Create Level", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 2)
    {
        small_variable_text_generator.generate(0, text_y, "<Load Level>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Load Level", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 3)
    {
        small_variable_text_generator.generate(0, text_y, "<Delete Level>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Delete Level", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 4)
    {
        small_variable_text_generator.generate(0, text_y, "<Return>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Return", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
}

void dbgMenu::recordOptions(int& option, bn::fixed& text_y, bn::sprite_text_generator& small_variable_text_generator, bn::vector<bn::sprite_ptr, 32>& text_sprites)
{
    if(option == 1)
    {
        small_variable_text_generator.generate(0, text_y, "<Attempt Counts>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Attempt Counts", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 2)
    {
        small_variable_text_generator.generate(0, text_y, "<Progress>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Progress", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 3)
    {
        small_variable_text_generator.generate(0, text_y, "<Return>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Return", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
}

void dbgMenu::settingsMenu(int& option, bn::fixed& text_y, bn::sprite_text_generator& small_variable_text_generator, bn::vector<bn::sprite_ptr, 32>& text_sprites)
{
    if(option == 1)
    {
        small_variable_text_generator.generate(0, text_y, "<Music Format>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Music Format", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 2)
    {
        small_variable_text_generator.generate(0, text_y, "<Music Volume>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Music Volume", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 3)
    {
        small_variable_text_generator.generate(0, text_y, "<SFX Volume>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "SFX Volume", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 4)
    {
        small_variable_text_generator.generate(0, text_y, "<Format Savedata>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Format Savedata", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 5)
    {
        small_variable_text_generator.generate(0, text_y, "<Return>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Return", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
}

void dbgMenu::formatMenu(int& option, bn::fixed& text_y, bn::sprite_text_generator& small_variable_text_generator, bn::vector<bn::sprite_ptr, 32>& text_sprites)
{
    small_variable_text_generator.generate(0, text_y, "Are you sure you want to format savedata?", text_sprites);
    text_y += dbgMenu::text_y_inc;
    small_variable_text_generator.generate(0, text_y, "This process is IRREVERSABLE!!!", text_sprites);
    text_y += dbgMenu::text_y_inc;

    if(option == 1)
    {
        small_variable_text_generator.generate(0, text_y, "<No>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "No", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 2)
    {
        small_variable_text_generator.generate(0, text_y, "<Yes>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Yes", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;

    if(option == 3)
    {
        small_variable_text_generator.generate(0, text_y, "<Return>", text_sprites);
    }
    else
    {
        small_variable_text_generator.generate(0, text_y, "Return", text_sprites);
    }
    text_y += dbgMenu::text_y_inc;
}

void dbgMenu::handleInput(int& menu, int& option)
{
    //const int mainMenuSize = 4;
    //const int levelSelectSize = 7;
    //const int editorOptionsSize = 4;
    //const int recordOptionsSize = 3;
    //const int settingsMenuSize = 5;
    //const int formatMenuSize = 3;
    
    if(bn::keypad::down_pressed())
    {
        switch(menu)
        {
            case(0):
                if(option < 4)
                {
                    option++;
                }
                break;
            case(1):
                if(option < 7)
                {
                    option++;
                }
                break;
            case(2):
                if(option < 4)
                {
                    option++;
                }
                break;
            case(3):
                if(option < 3)
                {
                    option++;
                }
                break;
            case(4):
                if(option < 5)
                {
                    option++;
                }
                break;
            case(5):
                if(option < 3)
                {
                    option++;
                }
                break;
            default:
                return;
        }
    }
    
    if(bn::keypad::up_pressed())
    {
        if(option > 1)
        {
            option--;
        }
    }

    if(bn::keypad::a_pressed())
    {
        if(menu == 0)
        {
            switch(option)
            {
                case(1):
                    menu = 1;
                    break;
                case(2):
                    menu = 2;
                    break;
                case(3):
                    menu = 3;
                    break;
                case(4):
                    menu = 4;
                    break;
                default:
                    return;
            }
        }
        else if(menu == 1)
        {
            switch(option)
            {
                case(1):
                    //fire aura
                    break;
                case(2):
                    //fire aura (XBLA)
                    break;
                case(3):
                    //chaoz fantasy
                    break;
                case(4):
                    //heaven
                    break;
                case(5):
                    //phazd
                    break;
                case(6):
                    //doom
                    break;
                case(7):
                    menu = 0;
                    break;
                default:
                    return;
            }
        }
        else if(menu == 2)
        {
            switch(option)
            {
                case(1):
                    //create level
                    break;
                case(2):
                    //load level
                    break;
                case(3):
                    //delete level
                    break;
                case(4):
                    menu = 0;
                    break;
                default:
                    return;
            }
        }
        else if(menu == 3)
        {
            switch(option)
            {
                case(1):
                    //attempt counts
                    break;
                case(2):
                    //progress
                    break;
                case(3):
                    menu = 0;
                    break;
                default:
                    return;
            }
        }
        else if(menu == 4)
        {
            switch(option)
            {
                case(1):
                    //music format
                    break;
                case(2):
                    //music volume
                    break;
                case(3):
                    //sfx volume
                    break;
                case(4):
                    menu = 5;
                    break;
                case(5):
                    menu = 0;
                    break;
                default:
                    return;
            }
        }
        else if(menu == 5)
        {
            switch(option)
            {
                case(1):
                    menu = 4;
                    break;
                case(2):
                    //format sram
                    break;
                case(3):
                    menu = 4;
                    break;
                default:
                    return;
            }
        }
        option = 1;
    }

    if(bn::keypad::b_pressed())
    {
        menu = 0;
    }
    
    update(menu, option);

}