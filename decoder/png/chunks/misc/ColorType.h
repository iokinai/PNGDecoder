//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_COLORTYPE_H
#define PNG_DECODER_COLORTYPE_H

namespace structure::chunks::colors {

    enum class ColorType : uint8_t {
        Halftone = 0,
        RGB = 2,
        PLT = 3,
        HalftoneA = 4,
        RGBA = 6
    };

}

#endif //PNG_DECODER_COLORTYPE_H
