//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_SIGNATUREDATA_H
#define PNG_DECODER_SIGNATUREDATA_H

#include "../../utils/LimitedSequence.h"

namespace structure::signature {

    class SignatureData {
    public:
        const static size_t Size {8};

        const static uint8_t NotAnAscii {0x89};
        const static uint8_t P {0x50};
        const static uint8_t N {0x4e};
        const static uint8_t G {0x47};
        const static uint8_t MsDosCR {0x0d};
        const static uint8_t MsDosLF {0x0a};
        const static uint8_t MsDosEnd {0x1a};
        const static uint8_t UnixLF {0x0a};

        static utils::LimitedSequence<uint8_t, 8> toBytes();
    };
} // structure

#endif //PNG_DECODER_SIGNATUREDATA_H
