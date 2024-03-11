#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
#include <string>
#include "mp1.h"

using namespace cs225;

void swap(PNG &png, unsigned x, unsigned y, unsigned newX, unsigned newY){
    HSLAPixel *pixel1 = png.getPixel(x, y);
    HSLAPixel *pixel2 = png.getPixel(newX, newY);
    HSLAPixel pixelStore = *pixel1;
    *pixel1 = *pixel2;
    *pixel2 = pixelStore;
}

void rotate(std::string inputFile, std::string outputFile){
    PNG PICTURE;
    // create a new empty picture
    if(PICTURE.readFromFile(inputFile) == 0){
        return;
    }
    // if the input file is nothing then the programe stop
    else{
        unsigned int width = PICTURE.width();
        unsigned int height = PICTURE.height();
        if(height%2 == 0){
            // the even height we can just rotate it side by side
            for(unsigned x = 0; x < width; x++){
                for(unsigned y = 0; y < height/2; y++){
                    swap(PICTURE, x, y, width-x-1, height-y-1);
                }
            }
        }
        if(height%2 != 0){
            // the odd height we need to consider the middle one
            for(unsigned x = 0; x < width; x++){
                for(unsigned y = 0; y < height/2; y++){
                    swap(PICTURE, x, y, width-x-1, height-y-1);
                }
            }
            unsigned y = height/2;
            for(unsigned x=0; x < width/2; x++){
                swap(PICTURE, x, y, width-x-1, y);
            }
        }
    }
    PICTURE.writeToFile(outputFile);
    // write the output picture to  the outputFile
    if(PICTURE.writeToFile(outputFile) == 0){
        return;
    }
    // if not return correctly then return
    return;
}
