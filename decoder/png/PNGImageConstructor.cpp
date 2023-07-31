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

    PNGImage PNGImageConstructor::getFinalImage() const {
        return this->image;
    }

    PNGImageConstructor::PNGImageConstructor() {
        image = PNGImage();
    }

} // structure::imageConstructor