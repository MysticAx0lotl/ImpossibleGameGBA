#include "bn_core.h"

#include "levels.hpp"
#include "debugMenu.hpp"
#include "libImpossibleGBA.hpp"
//#include "levelHandler.hpp"

/*
Level loadLevel(int levelID)
{
    switch(levelID)
    {
        case(1):
            Level returnObject(fireauraDat, false);
            break;
        case(2):
            Level returnObject(fireauraxboxDat, false);
            break;
        case(3):
            Level returnObject(chaozfantasyDat, false);
            break;
        case(4):
            Level returnObject(heavenDat, false);
            break;
        case(5):
            Level returnObject(phazedDat, false);
            break;
        case(6):
            Level returnObject(doomDat, false);
            break;
        default:
            Level returnObject(false);
    }

    return returnObject;
}
*/

int main()
{
    bn::core::init();
    bn::bg_palettes::set_transparent_color(bn::color(16, 16, 16));

    //int menu = 0;
    
    Level *testlvl = new Level(chaozfantasyDat, false);

    dbgMenu::mainLoop();
}
