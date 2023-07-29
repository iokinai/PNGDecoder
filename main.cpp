#include <iostream>
#include "decoder/png/fs/PNGFile.h"

int main() {
    std::string png = "C:\\Users\\MegaD\\Downloads\\tinypng.png";
    std::string notpng = "C:\\Users\\MegaD\\Downloads\\pngtree-blue-bird-vector-or-color-illustration-png-image_2013004.jpg";

    fs::PNGFile file(notpng);
    file.read();
    std::cout << file.isValidPNG() << std::endl;
}
