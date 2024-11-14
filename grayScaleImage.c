#include "config/grayScaleImage.h"
// Parameters:
//   w: width of the image
//   h: height of the image
// Return value
//   grayScale size of the image Bitmap (in byte)
float grayScaleImage(int w, int h) {
   int size = w * h * 1;  // Chaque pixel occupe 1 octet qui est egale a 8 bits
   return size;
}