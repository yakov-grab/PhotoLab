# PhotoLab v1.0

Implementation of the PhotoLab v1.0 project
The russian version of the task can be found in the repository.

## Part 1. Implementation of simple filters in PhotoLab v1.0

You need to implement the PhotoLab v1.0 program:

- The program must be developed in C++ language of C++17 standard 
- The program code must be located in the src folder
- When writing code it is necessary to follow the Google style
- Classes must be implemented within the `s21` namespace
- Prepare full coverage of modules that implement the business logic of the application with unit-tests using the GTest library
- The program must be built with Makefile which contains standard set of targets for GNU-programs: all, install, uninstall, clean, dvi, dist, tests. Installation directory could be arbitrary, except the building one
- GUI implementation, based on any GUI library with API for C++17: Qt, SFML, GTK+, Nanogui, Nngui, etc.
- The program must be implemented using the MVC pattern, and also:
     - there should be no business code in the view code
     - there should be no interface code in the controller and the model
     - controllers must be thin
- You cannot use ready-made libraries that implement filtering or work with matrices, except for the `s21_matrix` library you developed earlier.
- The program should provide the ability to:
    - Load an arbitrary image in BMP format
    - Save the result of filtering into a separate file (BMP format)
    - Apply a filter from a pool of ready-made filters:
        - Conversion to grayscale (without convolution)
        - Negative (without convolution)
        - Toning (similar to grayscale conversion, but in shades of the color specified on the palette. The palette must contain at least 16 different colors. The palette is implemented arbitrarily)
- After applying the filtering, the result should be displayed in the user interface along with the original image

## Part 2. Implementation of convolution filters in PhotoLab v1.0

You need to modify the PhotoLab v1.0 program to implement convolution filters:

- The program should provide the ability to apply the following convolution filters to the image:
    - Emboss 
    - Sharpen 
    - Box blur
    - Gaussian blur 
    - Laplacian filter
    - Prewitt filter (Prewitt filter) or Sobel filter (Sobel filter)
- The program should provide the ability to enter an arbitrary filter kernel matrix (up to size 16x16) by hand through a separate dialog window

## Part 3. Bonus. Implementation of color correction

You need to modify the PhotoLab v1.0 program to implement color correction algorithms:

- The program should provide the ability to make adjustments to color correction, such as:
    - changing the brightness and contrast of the image
    - work with saturation for the whole image (by HSL and HSV models)
- The interface for color correction of the original image should provide the ability to set brightness, contrast and the three parameters of the specified saturation model both numerically and by slider.

