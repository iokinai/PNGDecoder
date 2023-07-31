#include <iostream>
#include "decoder/png/fs/PNGFile.h"
#include "decoder/png/parser/Parser.h"

int main() {
    std::string png = "C:\\Users\\MegaD\\Downloads\\tinypng.png";
    
    fs::PNGFile file(png);

    file.read();

    if (!file.isValidPNG()) {
        throw std::exception();
    }

    parser::Parser pars(file.getFileData());

    pars.parse();
}
