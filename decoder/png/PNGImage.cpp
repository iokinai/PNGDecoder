//
// Created by MegaD on 30.07.2023.
//

#include "PNGImage.h"

namespace structure {
    PNGImage::PNGImage(const SignatureData &signature, const Chunk<IHDRData> &ihdr) : signature(signature),
                                                                                      IHDR(ihdr) {}

    const SignatureData &PNGImage::getSignature() const {
        return signature;
    }

    const Chunk<IHDRData> &PNGImage::getIHDR() const {
        return IHDR;
    }
} // structure