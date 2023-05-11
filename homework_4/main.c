
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#define DIMENSION_START 18 //find what value this is
#define PIXEL_DATA_OFFSET 36

typedef unsigned char color;
typedef struct pixel
{
    color blue;
    color green;
    color red;
}pixel;

void getWidthHeight(FILE* image, int* width, int* height, int dimensionDataOffset);
pixel** readPixelData(FILE* image, int width, int height, int pixelDataOffset);
void flipHorizontalPixelData(pixel** pixelData, int width, int height);
void writePixelData(FILE* image, pixel** pixelBuffer, int width, int height, int pixelDataOffset);
void swap(pixel* left, pixel* right);
void freeImage(pixel*** pixelData, int length);

/// <summary>
/// this program flips an image horizontally
///
/// For simplicity, no error checking is done. add your own.
/// </summary>
/// <returns></returns>
/*
 a.
  int main()
{
    int width = 0;
    int height = 0;
    FILE* myImage = fopen("image.bmp", "r+b");*/
//b:
int main(int argc, char* argv[])
{
    int width = 0;
    int height = 0;
    FILE* myImage = fopen(argv[1], "r+b");

    getWidthHeight(myImage, &width, &height, DIMENSION_START);
    //this array of pointers will hold all image rows. there are "height" rows,
    // each will later be allocated with "width" pixels dynamically in the function readPixelData
    pixel** imageMatrix = readPixelData(myImage, width, height, PIXEL_DATA_OFFSET);

   flipHorizontalPixelData(imageMatrix, width, height);
    writePixelData(myImage, imageMatrix, width, height, PIXEL_DATA_OFFSET);

    freeImage(&imageMatrix, height);

    fclose(myImage);
    return 0;
}

void getWidthHeight(FILE* image, int* width, int* height, int dimensionDataOffset)
{
    fseek(image,dimensionDataOffset,SEEK_SET);

    //width,height:
    fread(width,sizeof(int),1,image);
    fread(height,sizeof(int),1,image);
}

pixel** readPixelData(FILE* image, int width, int height, int pixelDataOffset)
{
pixel ** ourimage = (pixel**)calloc(height, sizeof(pixel*));
for (int i=0;i<height;i++){
   ourimage[i] = (pixel*)calloc(width, sizeof(pixel));
}

    fseek(image,pixelDataOffset,SEEK_SET);

    for (int i= 0 ; i<height;i++)
    {
        for (int j=0; j<width;j++)
        {
            fread(&ourimage[i][j],sizeof(pixel),1,image);
        }
    }

    return ourimage;
}

void flipHorizontalPixelData(pixel** pixelData, int width, int height)
{
 for (int i =0; i<height; i++){
     for (int j=0;j<width/2;j++){
         swap(&pixelData[i][width-j],&pixelData[i][j]);
     }
 }
}

void writePixelData(FILE* image, pixel** pixelBuffer, int width, int height, int pixelDataOffset) {
    fseek(image, pixelDataOffset, SEEK_SET);
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            fwrite(&pixelBuffer[i][j], sizeof(pixel), 1, image);
        }

    }
}
void swap(pixel* left, pixel* right)
{
  pixel temp = *right;
  *right=*left;
  *left=temp;
}

void freeImage(pixel*** pixelData, int length)
{
 for (int i=0;i<length;i++)
 {
     free((*pixelData)[i]);
 }
    free(*pixelData);
}
