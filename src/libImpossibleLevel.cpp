#include "libImpossibleLevel.hpp"

//Java handles evereything in big-Endian
//Since TIG's level editor is written in java, ints and shorts are written as big-Endian
//They must be converted to little-Endian after being read to be useable here
//This function takes an array of chars and a byte to start from. 
//It bit-shifts the starting byte and the next three bytes, then joins them together into a single int
//file = loaded file as a array of chars, startingOffset = the byte to start processing from
int readIntFromJava(bn::array<unsigned char, 5120> &file, int startingOffset)
{
    unsigned int bit1, bit2, bit3, bit4;
    bit1 = static_cast<unsigned int>(file[startingOffset]);
    bit2 = static_cast<unsigned int>(file[startingOffset + 1]);
    bit3 = static_cast<unsigned int>(file[startingOffset + 2]);
    bit4 = static_cast<unsigned int>(file[startingOffset + 3]);

    bit1 = bit1 << 24;
    bit2 = bit2 << 16;
    bit3 = bit3 << 8;
    //bit 4 doesn't get shifted

    unsigned int resultU = bit1 | bit2 | bit3 | bit4;
    int result = static_cast<int>(resultU);
    return result;
}

//This function takes an array of chars and a byte to start from. 
//It bit-shifts the starting byte and the next byte, then joins them together into a single short
//file = loaded file as a array of chars, startingOffset = the byte to start processing from
short readShortFromJava(bn::array<unsigned char, 5120> &file, int startingOffset)
{
    unsigned short bit1, bit2;
    bit1 = static_cast<unsigned int>(file[startingOffset]);
    bit2 = static_cast<unsigned int>(file[startingOffset + 1]);

    bit1 = bit1 << 8;
    //bit 2 doesn't get shifted

    unsigned short resultU = bit1 | bit2;
    short result = static_cast<short>(resultU);
    return result;
}

//Java handles evereything in big-Endian
//Since TIG's level editor is written in java, ints and shorts are read as big-Endian
//They must be converted to little-Endian after being written to be accepted by the game
/*void writeJavaInt(std::ofstream& datafile, int sourceInt)
{
    unsigned int swapSource = __builtin_bswap32(static_cast<unsigned int>(sourceInt));
    datafile.write(reinterpret_cast<const char*>(&swapSource), sizeof(swapSource));
}*/

//Java handles evereything in big-Endian
//Since TIG's level editor is written in java, ints and shorts are read as big-Endian
//They must be converted to little-Endian after being written to be accepted by the game
/*
void writeJavaShort(std::ofstream& datafile, short sourceShort)
{
    unsigned short swapSource = static_cast<unsigned short>((sourceShort >> 8) | (sourceShort << 8));
    datafile.write(reinterpret_cast<const char*>(&swapSource), sizeof(swapSource));
}*/

//Endianess doesn't matter for bools or char arrays, this function handles exporting those
/*
void writeOtherData(std::ofstream& datafile, unsigned char data)
{
    datafile.write(reinterpret_cast<const char*>(&data), sizeof(data));
}*/

//Constructor that generates a blank level if no data is given
Level::Level(bool debugMode)
{
    numBlockObjects = 0;
    numBackgroundChanges = 0;
    numGravityChanges = 0;
    numFadeEffects = 0;
    endPos = 3015;
    formatVer = 0;
}

Level::Level(bn::array<unsigned char, 5120> &levelChars, bool debugMode)
{
    this->loadLevel(levelChars, debugMode);
}

//Destructor that serves no purpose right now
Level::~Level()
{

}

//Parse level data from the given filepath, called by constructor
void Level::loadLevel(bn::array<unsigned char, 5120> &levelChars, bool debugMode)
{
    int currentByte = 0; //tracks the current byte in the file

    //make sure we actually loaded data
    if (levelChars.size() == 0)
    {
        Level(false); //call blank constructor if empty file is loaded
    }
    else
    {
        //first four bytes in the file are the format version, stored as an int
        this->formatVer = readIntFromJava(levelChars, currentByte);
        currentByte += 4;
        
        //the next byte is a bool seeing if custom graphics are enabled, we can skip reading it
        currentByte += 1;

        //the next two bytes are the number of blocks in the level, stored as a short
        this->numBlockObjects = readShortFromJava(levelChars, currentByte);
        currentByte += 2;

        //One block uses nine bytes of data (bool + 2 ints = 1 + 2(4) = 9 bytes)
        //the next (9 * numBlocks) bytes are the data for each block
        BlockObject *tempBlockObject = new BlockObject;
    
        for(int i = 0; i < this->numBlockObjects; i++)
        {

            tempBlockObject->objType = static_cast<int>(levelChars.at(currentByte));
            currentByte++;
    
            tempBlockObject->xPos = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            tempBlockObject->yPos = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            //tempBlockObject->indexInVec = i;
            this->blockObjects.push_back(*tempBlockObject);
        }
    
        delete tempBlockObject;
    
        //the next four bytes are the x position of the end of the level, stored as an int
        this->endPos = readIntFromJava(levelChars, currentByte);
        currentByte += 4;
    
        //the next four bytes are the number of color changes in the level, stored as an int
        this->numBackgroundChanges = readIntFromJava(levelChars, currentByte);
        currentByte += 4;
    
        //Assuming all background changes don't use custom graphics
        //Each background change takes up 9 bytes (same math as before, 2 ints + 1 bool)
        //Therefore the next (9 * numBgSwitch) bytes are background changes
        BackgroundChange *tempBackgroundChage = new BackgroundChange;
    
        for(int i = 0; i < this->numBackgroundChanges; i++)
        {
            tempBackgroundChage->xPos = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            //tempBackgroundChage->customTexture = static_cast<bool>(levelChars.at(currentByte));
            currentByte++; //WILL CURRENTLY BREAK HERE IF CUSTOM GRAPHICS ARE ENABLED

            tempBackgroundChage->colorID = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            //tempBackgroundChage->indexInVec = i;
    
            this->backgroundChanges.push_back(*tempBackgroundChage);
    
        }
    
        delete tempBackgroundChage;
    
        //The next 4 bytes are the number of gravity changes in the level, stored as an int
        this->numGravityChanges = readIntFromJava(levelChars, currentByte);
        currentByte += 4;
    
        //Each gravity change only takes up 4 bytes (1 int = 4 bytes)
        //Therefore, the next (4 * numGravitySwitch) bytes are gravity switch data
        GravityChange *tempGravityChange = new GravityChange;
    
        for(int i = 0; i < this->numGravityChanges; i++)
        {
            tempGravityChange->xPos = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            //tempGravityChange->indexInVec = i;
    
            this->gravityChanges.push_back(*tempGravityChange);
    
        }
        delete tempGravityChange;
    
        //The next 4 bytes are the number of falling block fade effects, stored as an int
        this->numFadeEffects = readIntFromJava(levelChars, currentByte);
        currentByte += 4;
    
        //Each falling block object takes up 8 bytes (2 ints = 2 * 4 bytes = 8 bytes)
        //Therefore the next (8 * numFallingBlocks) bytes are Falling Blocks data
        FadeEffect *tempFadeEffect = new FadeEffect;
    
        for(int i = 0; i < this->numFadeEffects; i++)
        {
            tempFadeEffect->startX = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            tempFadeEffect->endX = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            tempFadeEffect->upOrDown = false;
            
            this->fadeEffects.push_back(*tempFadeEffect);
        }
        
        //The next 4 bytes are the number of rising block fade effects, stored as an int
        int oldNumFadeEffects = this->numFadeEffects;
        this->numFadeEffects += readIntFromJava(levelChars, currentByte);
        currentByte += 4;

        for(int i = oldNumFadeEffects; i < this->numFadeEffects; i++)
        {
            tempFadeEffect->startX = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            tempFadeEffect->endX = readIntFromJava(levelChars, currentByte);
            currentByte += 4;
    
            tempFadeEffect->upOrDown = true;
            
            this->fadeEffects.push_back(*tempFadeEffect);
        }
    
        delete tempFadeEffect;
    }
}

/*
void Level::saveLevel(std::string filepath)
{
    if(!std::filesystem::exists(filepath))
    {
        std::filesystem::create_directory(filepath);
    }

    filepath += "/level.dat";

    std::ofstream dataOut;
    dataOut.open(filepath.c_str(), std::ios_base::binary | std::ios_base::out);
    writeJavaInt(dataOut, this->formatVer);
    writeOtherData(dataOut, this->customGraphicsEnabled);
    writeJavaShort(dataOut, this->numBlockObjects);
    BlockObject temp;
    for(int i = 0; i < this->numBlockObjects; i++)
    {
        temp = this->getBlockAtIndex(i);
        writeOtherData(dataOut, temp.objType);
        writeJavaInt(dataOut, temp.xPos);
        writeJavaInt(dataOut, temp.yPos);
    }
    writeJavaInt(dataOut, endPos);
    writeJavaInt(dataOut, numBackgroundChanges);
    BackgroundChange tempCon;
    for(int i = 0; i < numBackgroundChanges; i++)
    {
        tempCon = this->getBackgroundAtIndex(i);
        writeJavaInt(dataOut, tempCon.xPos);
        writeOtherData(dataOut, tempCon.customTexture);
        if(tempCon.customTexture)
        {
            short strLen = sizeof(tempCon.filePath);
            writeJavaShort(dataOut, strLen);
            for(int i = 0; i < sizeof(tempCon.filePath); i++)
            {
                writeOtherData(dataOut, tempCon.filePath[i]);
            }
        }
        else
        {
            writeJavaInt(dataOut, tempCon.colorID);
        }
    }
    writeJavaInt(dataOut, this->numGravityChanges);
    GravityChange tempGrav;
    for(int i = 0; i < this->numGravityChanges; i++)
    {
        tempGrav = this->getGravAtIndex(i);
        writeJavaInt(dataOut, tempGrav.xPos);
    }
    writeJavaInt(dataOut, this->numBlocksRise);
    BlocksRise tempRising;
    for(int i = 0; i < this->numBlocksRise; i++)
    {
        tempRising = this->getRisingAtIndex(i);
        writeJavaInt(dataOut, tempRising.startX);
        writeJavaInt(dataOut, tempRising.endX);
    }
    writeJavaInt(dataOut, this->numBlocksFall);
    BlocksFall tempFalling;
    for(int i = 0; i < this->numBlocksFall; i++)
    {
        tempFalling = this->getFallingAtIndex(i);
        writeJavaInt(dataOut, tempFalling.startX);
        writeJavaInt(dataOut, tempFalling.startX);
    }
}
*/

//The following methods are all explained in the hpp file
int Level::getFormatVer()
{
    return this->formatVer;
}

BlockObject& Level::getBlockAtIndex(int index)
{
    if(index < this->numBlockObjects)
    {
        return this->blockObjects.at(index);
    }
    else
    {
        static BlockObject nullObj = {0, 0, 0};
        return nullObj;
    }
}

BackgroundChange& Level::getBackgroundAtIndex(int index)
{
    if(index < this->numBackgroundChanges)
    {
        return this->backgroundChanges.at(index);
    }
    else
    {
        static BackgroundChange nullObj = {0, 0};
        return nullObj;
    }

}

GravityChange& Level::getGravAtIndex(int index)
{
    if(index < this->numGravityChanges)
    {
        return this->gravityChanges.at(index);
    }
    else
    {
        static GravityChange nullObj = {0};
        return nullObj;
    }
}

FadeEffect& Level::getFadeEffectAtIndex(int index)
{
    if(index < this->numFadeEffects)
    {
        return this->fadeEffects.at(index);
    }
    else
    {
        static FadeEffect nullObj = {0, 0, false};
        return nullObj;
    }
}

int Level::getEndPos()
{
    return this->endPos;
}

int Level::getBlockCount()
{
    return this->numBlockObjects;
}

int Level::getBackgroundCount()
{
    return this->numBackgroundChanges;
}

int Level::getGravityCount()
{
    return this->numGravityChanges;
}

int Level::getFadeEffectCount()
{
    return this->numFadeEffects;
}

void Level::addBlock(BlockObject *toAdd)
{
    //toAdd->indexInVec = this->numBlockObjects;
    numBlockObjects++;
    this->blockObjects.push_back(*toAdd);
}

void Level::addBackground(BackgroundChange *toAdd)
{
    //toAdd->indexInVec = this->numBackgroundChanges;
    numBackgroundChanges++;
    //toAdd->colorName = this->colorNames[toAdd->colorID];
    this->backgroundChanges.push_back(*toAdd);
}

void Level::addGravity(GravityChange *toAdd)
{
    //toAdd->indexInVec = this->numGravityChanges;
    numGravityChanges++;
    this->gravityChanges.push_back(*toAdd);
}

void Level::addFadeEffect(FadeEffect *toAdd)
{
    //toAdd->indexInVec = this->numBlocksRise;
    numFadeEffects++;
    this->fadeEffects.push_back(*toAdd);
}

void Level::setEndPos(int wantedEndPos)
{
    this->endPos = wantedEndPos;
}

//The if-else statements in the AtIndex methods make sure that the index is in range
void Level::removeBlockAtIndex(int index)
{
    if(index < this->numBlockObjects)
    {
        this->blockObjects.erase(this->blockObjects.begin() + index);
        this->numBlockObjects--;
    }
}

//The if-else statements in the removeLast methods make sure that the appropriate vectors contain data 
void Level::removeLastBlock()
{
    if(this->numBlockObjects > 0)
    {
        this->blockObjects.pop_back();
        this->numBlockObjects--;
    }
}

void Level::removeBackgroundAtIndex(int index)
{
    if(index < this->numBackgroundChanges)
    {
        this->backgroundChanges.erase(this->backgroundChanges.begin() + index);
        this->numBackgroundChanges--;
    }
}

void Level::removeLastBackground()
{
    if(this->numBackgroundChanges > 0)
    {
        this->backgroundChanges.pop_back();
        this->numBackgroundChanges--;
    }
}

void Level::removeGravityAtIndex(int index)
{
    if(index < this->numGravityChanges)
    {
        this->gravityChanges.erase(this->gravityChanges.begin() + index);
        this->numGravityChanges--;
    }
}

void Level::removeLastGravity()
{
    if(this->numGravityChanges > 0)
    {
        this->gravityChanges.pop_back();
        this->numGravityChanges--;
    }
}

void Level::removeFadeEffectAtIndex(int index)
{
    if(index < this->numFadeEffects)
    {
        this->fadeEffects.erase(this->fadeEffects.begin() + index);
        this->numFadeEffects--;
    }
}

void Level::removeLastFadeEffect()
{
    if(this->numFadeEffects > 0)
    {
        this->fadeEffects.pop_back();
        this->numFadeEffects--;
    }
}