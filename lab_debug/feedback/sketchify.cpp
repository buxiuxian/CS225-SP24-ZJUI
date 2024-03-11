#include <cstdlib>
#include <cmath>

#include "cs225/PNG.h"
#include "cs225/HSLAPixel.h"
using namespace cs225;
using namespace std;
// If you’re getting compiler errors after trying to use cout statements
// then you need to #include the iostream library like this

// sets up the output image
PNG* setupOutput(unsigned w, unsigned h) {
    PNG* image = new PNG(w, h);
    return image;
}

// Returns my favorite color
HSLAPixel* myFavoriteColor(double saturation) {
    HSLAPixel *pixel = new HSLAPixel(212, saturation, 0.5);
    return pixel;
    // Because 'pixel' is created within the function
    // once the function completes its execution
    // the memory space it occupies will be deallocated.
}

void sketchify(std::string inputFile, std::string outputFile) {
    // Load in.png
    PNG* original = new PNG();
    // do not create a NULL pointer but create a new one in heap

    original->readFromFile(inputFile);
    unsigned width = original->width();
    unsigned height = original->height();

    // Create out.png
    PNG* output;
    output = setupOutput(width, height);
    // the out put is used, and is for the pointer to the OutPut

    // Load our favorite color to color the outline
    HSLAPixel* myPixel = myFavoriteColor(0.5);

    // Go over the whole image, and if a pixel differs from that to its upper
    // left, color it my favorite color in the output
    for (unsigned y = 1; y < height && y > 0; y++) {
        for (unsigned x = 1; x < width && x > 0; x++) {
            // there is warning because 0 < x < height do not have their mathematical meaning
            // we need to separate them

            // Calculate the pixel difference
            HSLAPixel* prev = original->getPixel(x - 1, y - 1);
            HSLAPixel* curr = original->getPixel(x, y);
            double diff = std::fabs(curr->h - prev->h);

            // If the pixel is an edge pixel,
            // color the output pixel with my favorite color
            HSLAPixel* currOutPixel = (*output).getPixel(x, y);
            if (diff > 20) {
                *currOutPixel = *myPixel;
                // did not define the currOutPixel, and we can not use the value change
                // here we need to use the pointer change, use the pointer(heap) to change
            }
        }
    }

    // Save the output file
    output->writeToFile(outputFile);

    // Clean up memory
    delete myPixel;
    delete output;
    delete original;
    myPixel = nullptr;
    output = nullptr;
    original = nullptr;
    // if these pointer delete, but we did not define them as the null ptr
    // the program may cause a Segmentation Fault
}
