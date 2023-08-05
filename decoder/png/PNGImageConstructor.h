//
// Created by MegaD on 30.07.2023.
//

#ifndef PNG_DECODER_PNGIMAGECONSTRUCTOR_H
#define PNG_DECODER_PNGIMAGECONSTRUCTOR_H

#include "PNGImage.h"

namespace structure::constructor {

    class PNGImageConstructor {
    public:
        PNGImageConstructor();
        explicit PNGImageConstructor(PNGImage base);

        void addIHDR(Chunk<IHDRData> ihdr);
        void addIDAT(Chunk<IDATData> idat);

        [[nodiscard]] PNGImage getFinalImage() const;

    private:
        PNGImage image;

    };
} // structure::imageConstructor

#endif //PNG_DECODER_PNGIMAGECONSTRUCTOR_H
