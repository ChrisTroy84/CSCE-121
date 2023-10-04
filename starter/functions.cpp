#include <iostream>
#include <sstream>
#include <fstream>
#include <cmath>
#include "functions.h"
#include <string>

using std::cout, std::endl, std::string;
using namespace std;
using std::ifstream; using std::ofstream;

void initializeImage(Pixel image[][MAX_HEIGHT]) {
  // iterate through columns
  for (unsigned int col = 0; col < MAX_WIDTH; col++) {
    // iterate through rows
    for (unsigned int row = 0; row < MAX_HEIGHT; row++) {
      // initialize pixel
      image[col][row] = {0, 0, 0};
    }
  }
}

void loadImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int& height) {
  // TODO: implement (part 1)
  ifstream inFS;

  inFS.open(filename);

  // open error 
  if (!inFS.is_open()) {

    throw runtime_error("Failed to open " + filename);
  }
  
  //p3 error
  char file_type[3];
    inFS >> file_type;
    if ((file_type[1] != '3') || (toupper(file_type[0]) != 'P')) {
      throw runtime_error("Invalid type " + file_type[3]);
    }

  //non-integer value error
  inFS >> width;
  if (inFS.fail()) {
    throw runtime_error("Invalid dimensions");
  } 
  else if (width <= 0) {
    throw runtime_error("Invalid dimensions");
  }

  inFS >> height;
  if (inFS.fail()) {
    throw runtime_error("Invalid dimensions");
  }
  else if (height <= 0) {
    throw runtime_error("Invalid dimensions");
  }

  int color_Value = 0; 
  inFS >> color_Value;
  if (inFS.fail()) {
    throw runtime_error("Invalid color value");
  } 
  else if (color_Value != 255) {
    throw runtime_error("Invalid color value");
  }

  //pixel validation
  int pixel_dims[3];
  unsigned int i;
  unsigned int j;
  int k;

  for (j = 0; j < height; j++) {
    for (i = 0; i < width; i++) {
      if (!(inFS >> pixel_dims[0])) {
        throw runtime_error("Invalid color value");
      }
      else if (!(inFS >> pixel_dims[1])) {
        throw runtime_error("Invalid color value");
      }
      else if (!(inFS >> pixel_dims[2])) {
        throw runtime_error("Invalid color value");
      }
      for (k = 0; k < 3; k++) {
        if (pixel_dims[k] < 0) {
          throw runtime_error("Invalid color value");
        }
        else if (pixel_dims[k] > color_Value) {
          throw runtime_error("Invalid color value");
        }
      }
      image[i][j].r = pixel_dims[0];
      image[i][j].g = pixel_dims[1];
      image[i][j].b = pixel_dims[2];
    }
  }
  if (inFS >> pixel_dims[0]) {
    throw runtime_error("Too many values");
  }

  inFS.close(); 

}

void outputImage(string filename, Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  ofstream outFS;

  outFS.open(filename);

  // checking to see if the program failed to open the output file
  if (!outFS.is_open()) {
    throw runtime_error("Failed to open " + filename);
  }

  //ui output 
  outFS << "P3" << endl;
  outFS << width << " " << height << endl;
  outFS << 255 << endl;

  //output for the pixel information
  unsigned int current_row = 0;
  unsigned int current_column = 0;

  for (current_row = 0; current_row < height; current_row++) {
    for (current_column = 0; current_column < width; current_column++) {
      outFS << image[current_column][current_row].r << " ";
      outFS << image[current_column][current_row].g << " ";
      outFS << image[current_column][current_row].b << " ";
    } outFS << endl;
  }

  outFS.close();
}

unsigned int energy(Pixel image[][MAX_HEIGHT], unsigned int x, unsigned int y, unsigned int width, unsigned int height) {
  // TODO: implement (part 1)
  int Energy_of_X;
  int Energy_of_Y;
  int i1;
  int j1;
  int i2;
  int j2;
  int change_R;
  int change_G;
  int change_B;

  if (width < 3 || height < 3) {
    return 1;
  }

  //edges of x
  if (x == 0) {
    i1 = width - 1;
    i2 = x + 1;
  } else if (x == width - 1) {
    i1 = x - 1;
    i2 = 0;
  } else {
    i1 = x - 1;
    i2 = x + 1;
  }

  //calculating the energy of x
  //change in the energy of red, green, and blue values

  change_R = image[i1][y].r - image[i2][y].r;
  change_G = image[i1][y].g - image[i2][y].g;
  change_B = image[i1][y].b - image[i2][y].b;

  Energy_of_X = (pow(change_R, 2) + pow(change_G, 2) + pow(change_B, 2));

  //edges of y
  if (y == 0) {
    j1 = height - 1;
    j2 = y + 1;
  } else if (y == height - 1) {
    j1 = y - 1;
    j2 = 0;
  } else {
    j1 = y - 1;
    j2 = y + 1;
  }

  //calculating energy of y
  //change in the enregy of red, green, and blue 
  
  change_R = image[x][j1].r - image[x][j2].r;
  change_G = image[x][j1].g - image[x][j2].g;
  change_B = image[x][j1].b - image[x][j2].b;

  Energy_of_Y = (pow(change_R, 2) + pow(change_G, 2) + pow(change_B, 2));

  //returning the total energy of the pixel
  return Energy_of_X + Energy_of_Y;

  //return 0;
}

// uncomment functions as you implement them (part 2)

unsigned int loadVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_col, unsigned int width, unsigned int height, unsigned int seam[]) {
  // TODO: implement (part 2)
  int Total_Energy = 0;

  unsigned int left_of_seam;
  unsigned int middle_of_seam;
  unsigned int right_of_seam;
  unsigned int i = 0;

  for (i = 0; i < height; ++i) {
    if (i > 0) {
      if(start_col == width - 1) {
        left_of_seam = energy(image, start_col - 1, i, width, height);
        middle_of_seam = energy(image, start_col, i, width, height);
        if (middle_of_seam > left_of_seam) {
          --start_col;
        }
      }
      else if (start_col == 0) {
        right_of_seam = energy(image, start_col + 1, i, width, height);
        middle_of_seam = energy(image, start_col, i, width, height);
        if (middle_of_seam > right_of_seam) {
          ++start_col;
        }
      }
      else {
        left_of_seam = energy(image, start_col - 1, i , width, height);
        middle_of_seam = energy(image, start_col, i, width, height);
        right_of_seam = energy(image, start_col + 1, i, width, height);
        if (middle_of_seam > right_of_seam || middle_of_seam > left_of_seam) {
          if (left_of_seam < right_of_seam) {
            --start_col;
          }
          else {
            ++start_col;
          }
        }
      }
    }
    Total_Energy += energy(image, start_col, i, width, height);
    seam[i] = start_col;
  }
  return Total_Energy;

}

unsigned int loadHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int start_row, unsigned int width, unsigned int height, unsigned int seam[]) {
//   TODO: implement (part 2)
  int Total_Energy = 0;
  unsigned int upper_of_seam;
  unsigned int middle_of_seam;
  unsigned int down_of_seam;
  unsigned int i = 0;

  for (i = 0; i < width; ++i) {
    if (i > 0) {
      if(start_row == height - 1) {
        upper_of_seam = energy(image, i, start_row - 1, width, height);
        middle_of_seam = energy(image, i, start_row, width, height);
        if (middle_of_seam > upper_of_seam) {
          --start_row;
        }
      }
      else if (start_row == 0) {
        down_of_seam = energy(image, i, start_row + 1, width, height);
        middle_of_seam = energy(image, i, start_row, width, height);
        if (middle_of_seam > down_of_seam) {
          ++start_row;
        }
      }
      else {
        upper_of_seam = energy(image, i, start_row - 1, width, height);
        middle_of_seam = energy(image, i, start_row, width, height);
        down_of_seam = energy(image, i, start_row + 1, width, height);
        if (middle_of_seam > upper_of_seam || middle_of_seam > down_of_seam) {
          if (down_of_seam < upper_of_seam) {
            ++start_row;
          }
          else {
            --start_row;
          }
        }
      }
    }

    Total_Energy += energy(image, i, start_row, width, height);
    seam[i] = start_row;
  }
  return Total_Energy;
//   return 0;
}

void findMinVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
  // TODO: implement (part 2)
  int min_seam = loadVerticalSeam(image, 0, width, height, seam);
  int index = 0;

  for (unsigned int i = 0; i < width; i++) {
    int temp = loadVerticalSeam(image, i, width, height, seam);
    if (temp < min_seam) {
      index = i;
      min_seam = temp;
    }
  }
  loadVerticalSeam(image, index, width, height, seam);
}

void findMinHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int height, unsigned int seam[]) {
//   // TODO: implement (part 2)
  int min_seam = loadHorizontalSeam(image, 0, width, height, seam);
  int index = 0;

  for (unsigned int i = 0; i < height; i++) {
    int temp = loadHorizontalSeam(image, i, width, height, seam);
    if (temp < min_seam) {
      index = i;
      min_seam = temp;
    }
  }
  loadHorizontalSeam(image, index, width, height, seam);
  
}

void removeVerticalSeam(Pixel image[][MAX_HEIGHT], unsigned int& width, unsigned int height, unsigned int verticalSeam[]) {
  // TODO: implement (part 2)
  unsigned int i = 0;
  unsigned int j = 0;

  for (i = 0; i < height; i++) {
    for (j = verticalSeam[i]; j < width - 1; j++) {
      image[j][i] = image[j+1][i];
    }
  }
  width -= 1;
}

void removeHorizontalSeam(Pixel image[][MAX_HEIGHT], unsigned int width, unsigned int& height, unsigned int horizontalSeam[]) {
//   // TODO: implement (part 2)
  unsigned int i = 0;
  unsigned int j = 0;

  for (i = 0; i < width; ++i) {
    for (j = horizontalSeam[i]; j < height - 1; ++j) {
      image[i][j] = image[i][j+1];
    }
  }
  height -= 1;
}
