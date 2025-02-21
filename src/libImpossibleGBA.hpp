#ifndef IMPOSSIBLE_LEVEL_LOADER_GBA
#define IMPOSSIBLE_LEVEL_LOADER_GBA


#include "bn_array.h"
#include "bn_vector.h"


/*
BlockObj: short for "block object"
xPos = the object's x position in raw coordinates (divide by 30 to get its grid space)
yPos = the object's y position in raw coordinates (instead serves as the ending x position for pits)
objType = the object's type ID (00 for a block, 01 for a spike, 02 for a pit)
indexInVec = the object's index in the vector it's part of. Only used by this library, does not get read from or written to the level file
*/
struct BlockObject
{
    int xPos;
    int yPos;
    int objType;
    //int indexInVec;
};

/*
BackgroundChange: the invisible objects that change the color or texture of the background
xPos = the object's x position in raw coordinates (divide by 30 to get its grid space)
colorId = the ID of the background color that will be used when this object is passed ()
customGraphics = the editor's seemingly-unused ability to load an actual texture image instead of using a color
customFile = the also unused UTF-8 string pointing to a texture
indexInVec = the object's index in the vector it's part of. Only used by this library, does not get read from or written to the level file
*/
struct BackgroundChange
{
    int xPos;
    int colorID;
    //int indexInVec;
};

/*
GravityChange: the object that flips the level upside-down (only used in Chaoz Fantasy, impossible to place in the editor)
xPos = the object's x position in raw coordinates (divide by 30 to get its grid space)
indexInVec = the object's index in the vector it's part of. Only used by this library, does not get read from or written to the level file
*/
struct GravityChange
{
    int xPos;
    //int indexInVec;
};

/*
FadeEffect: the object that enables the fade effect where blocks will rise or fall from the ground on the right side of the screen
startX = the x positon where the effect will be enabled
endX = the x position where the effect will be disabled
upOrDown = whether it triggers the rising or falling effect (true=rising, false=falling)
Note: this is the result of merging the BlocksRising and BlocksFalling structs from the original libImpossibleLevel
*/
struct FadeEffect
{
    int startX;
    int endX;
    bool upOrDown;
};

/*
The class that holds the actual level data

PUBLIC MEMBERS
- Level(): failsafe for if no parameters are given
- Level(char const*): call loadDataFromFile and pass its parameter
- ~Level(): deconstructor
- loadDataFromFile(char const*): load level data from path given by the parameter
- writeDataToFile(char const*): write data to path given by parameter
- getFormatVer(): get the file format version, returns an int
- getBlockAtIndex(int): returns the BlockObj at the given int if it exists, returns an empty BlockObj otherwise
- getBgConAtIndex(int): returns the BgCon at the given int if it exists, returns an empty BgCon otherwise
- getGravityAtIndex(int): returns the GravityChange at the given int if it exists, returns an empty GravityChange otherwise
- getFadeEffectAtIndex(int): returns the FadeEffect at the given int if it exists, returns an empty RisingBlocks otherwise
- getEndPos(): return the x position of the end wall as an int
- getObjCount() through getFallingCount(): return the size of the corresponding vectors
- addNewBlock(BlockObj) through addFallingBlocks(FallingBlocks): add the provided object to the corresponding vector, and increment the associated private member
- setEndPos(int): set the position of the end wall to the given parameter
- remove____AtIndex(int): removes the object at the given index from the appropriate vector, if the given index is in bounds
- removeLast____(): removes the last entry from the appropriate vector, if the appropriate vector isn't empty
- printSummary(): prints a short summary including the format version, which objects the level has and how many, which custom textures the level uses if any, and where the level starts and ends

PRIVATE MEMBERS
- blockObjs: pointer to a vector of BlockObj objects, stored in the heap
- backgroundSwitches: pointer to a vector of BgCon objects, stored in the heap
- gravitySwitches: pointer to a vector of GravityChange objects, stored in the heap
- risingSections: pointer to a vector of RisingBlocks objects, stored in the heap
- fallingSections: pointer to a vector of FallingBlocks objects, stored in the heap
- numBlocks: size of blockObjs, stored as a short
- numBgSwitch through numFadeEffects: size of the associated vector, stored as an int
- endWallPos: x position of the end of the level, stored as an int
- formatVer: the file format version, stored as an int
*/
class Level
{
    public:
        Level(bool);
        Level(bn::array<unsigned char, 5120> &levelChars, bool);
        ~Level();
        void loadLevel(bn::array<unsigned char, 5120> &levelChars, bool);
        //void saveLevel(std::string); //char const* is still needed in loadLevel since it passes that value to a lot of other functions, while saveLevel does not

        //get methods
        int getFormatVer();
        BlockObject& getBlockAtIndex(int);
        BackgroundChange& getBackgroundAtIndex(int);
        GravityChange& getGravAtIndex(int);
        FadeEffect& getFadeEffectAtIndex(int);
        int getEndPos();
        int getBlockCount();
        int getBackgroundCount();
        int getGravityCount();
        int getFadeEffectCount();

        //set methods
        void addBlock(BlockObject*);
        void addBackground(BackgroundChange*);
        void addGravity(GravityChange*);
        void addFadeEffect(FadeEffect*);
        void setEndPos(int);

        //removal methods
        void removeBlockAtIndex(int);
        void removeLastBlock();
        void removeBackgroundAtIndex(int);
        void removeLastBackground();
        void removeGravityAtIndex(int);
        void removeLastGravity();
        void removeFadeEffectAtIndex(int);
        void removeLastFadeEffect();
        
    private:
        bn::vector<BlockObject, 1024> blockObjects;
        bn::vector<BackgroundChange, 16> backgroundChanges;
        bn::vector<GravityChange, 16> gravityChanges;
        bn::vector<FadeEffect, 32> fadeEffects;
        short numBlockObjects;
        int numBackgroundChanges;
        int numGravityChanges;
        int numFadeEffects;
        int endPos;
        int formatVer;
};

#endif
