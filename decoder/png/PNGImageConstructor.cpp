//
// Created by MegaD on 30.07.2023.
//

#include "PNGImageConstructor.h"

#include <utility>

namespace structure::constructor {

    PNGImageConstructor::PNGImageConstructor(PNGImage base) : image(std::move(base)) {
    }

    void PNGImageConstructor::addIHDR(Chunk<IHDRData> ihdr) {
        this->image.IHDR = std::move(ihdr);
    }

    void PNGImageConstructor::addIDAT(Chunk<IDATData> idat) {
        this->image.IDAT = std::move(idat);
    }

    PNGImage PNGImageConstructor::getFinalImage() const {
        return this->image;
    }

    PNGImageConstructor::PNGImageConstructor() {
        image = PNGImage();
    }

} // structure::imageConstructor