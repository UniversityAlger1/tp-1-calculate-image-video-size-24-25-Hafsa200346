#include <string.h>
#include "config/video.h"
// Parameters:
//   w: width of the image
//   h: height of the image
//   durationMovie: duration in seconds of movie (colored image)
//   durationCredits: duration in seconds of credits (black & white image)
//   unit: Unit of the output value. It could be 'B' bytes, 'KB' kilobytes, 'MB' megabytes, 'GB' gigabytes
// Return value
//   video size based on the unit passed parameter

float video(int w, int h, int durationMovie, int durationCredits, int fps, char* unit) {
   int pixelsParFrame = w * h;
   // Calculer le nombre total d'images pour chaque section
   int totalFramesMovie = durationMovie * fps;
   int totalFramesCredits = durationCredits * fps;
   
   // Calculer la taille de la section en couleur en octets (3 octets par pixel)
   float colorSizeBytes = totalFramesMovie * pixelsParFrame * 3;

   // Calculer la taille de la section en noir et blanc en octets (1 octet par pixel)
   float blackWhiteSizgiteBytes = totalFramesCredits * pixelsParFrame * 1;

   // Taille totale en octets
   float totalSizeBytes = colorSizeBytes + blackWhiteSizeBytes;
   if (strcmp(unit, "B") == 0) {
       return totalSizeBytes;
   } else if (strcmp(unit, "Ko") == 0) {
       return totalSizeBytes / 1024;  
   } else if (strcmp(unit, "Mo") == 0) {
       return totalSizeBytes / (1024 * 1024); 
   } else if (strcmp(unit, "Go") == 0) {
       return totalSizeBytes / (1024 * 1024 * 1024); 
   } else if (strcmp(unit, "bit") == 0) {
       return totalSizeBytes * 8;  
   } else {
       return 0;
   }
}