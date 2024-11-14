#include <string.h>
#include "config/coloredBitmap.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   u: Unit of the output value. It could be 'bt' bits, 'ko' kilobits, 'mo' megabits, 'go' gigabits
// Return value
//   colored image size Bitmap (based on the unit passed parametter)
float coloredBitmap(int w, int h, char* unit) {
   // Calculer la taille de l'image couleur en octets
   float sizeInBytes = w * h * 3; 

   // Conversion de la taille
   if (strcmp(unit, "B") == 0) {
       return sizeInBytes;
   } else if (strcmp(unit, "Ko") == 0) {
       return sizeInBytes / 1024; 
   } else if (strcmp(unit, "Mo") == 0) {
       return sizeInBytes / (1024 * 1024);  
   } else if (strcmp(unit, "Go") == 0) {
       return sizeInBytes / (1024 * 1024 * 1024);
   } else if (strcmp(unit, "bit") == 0) {
       return sizeInBytes * 8;  
   } else {
       return 0;
   }
}