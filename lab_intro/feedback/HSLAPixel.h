#ifndef CS225_HSLAPixel_H
#define CS225_HSLAPixel_H

namespace cs225 {
  class HSLAPixel{
    public:
      //Constructs a default HSLAPixel.
      HSLAPixel();

      /**Constructs an opaque HSLAPixel with the given hue, saturation, and luminance values.
        *The alpha component of the pixel constructed should be 1.0.
        */
      HSLAPixel(double hue, double saturation, double luminance);

      // Constructs an opaque HSLAPixel with the given hue, saturation, luminance, and alpha values.
      HSLAPixel(double hue, double saturation, double luminance, double aplha);
      
      double h;
      double s;
      double l;
      double a;
  };
}

#endif