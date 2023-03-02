// ray-tracer.cpp

#include <iostream>
#include <fstream>
#include "color.h"

int main()
{
    // File Stream
    std::ofstream outFile;
    outFile.open("image.ppm");

    // Image
    const int img_width = 256;
    const int img_height = 256;

    // Render
    outFile << "P3\n" << img_width << ' ' << img_height << "\n255\n";

    for (int j = img_height - 1; j >= 0; j--) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < img_width; i++) {
            Color* pixel_color = new Color(double(i) / ((double)img_width - 1), double(j) / ((double)img_height - 1), 0.25);
            write_color(outFile, *pixel_color);
            delete pixel_color;
        }
    }
    std::cerr << "\nDone.\n";
    outFile.close();
}