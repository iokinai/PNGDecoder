//
// Created by MegaD on 30.07.2023.
//

#ifndef PNG_DECODER_PNGIMAGE_H
#define PNG_DECODER_PNGIMAGE_H

#include "SignatureData.h"
#include "chunks/Chunk.h"
#include "chunks/IHDRData.h"

using namespace structure::signature;
using namespace structure::chunks;

namespace structure::constructor {
    class PNGImageConstructor;
}

namespace structure {

    class PNGImage {
    public:
        PNGImage() = default;
        PNGImage(const SignatureData &signature, const Chunk <IHDRData> &ihdr);
        [[nodiscard]] const SignatureData &getSignature() const;
        [[nodiscard]] const Chunk <IHDRData> &getIHDR() const;

    private:
        SignatureData signature;
        Chunk<IHDRData> IHDR;

        friend structure::constructor::PNGImageConstructor;
    };

} // structure

#endif //PNG_DECODER_PNGIMAGE_H
