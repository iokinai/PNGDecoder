//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_SIGNATUREDATA_H
#define PNG_DECODER_SIGNATUREDATA_H

#include "../../Types.h"
#include "../../utils/LimitedSequence.h"

namespace structure::signature {

    class SignatureData {
    public:
        const static size_t Size {8};

        const static ubyte NotAnAscii {0x89};
        const static ubyte P {0x50};
        const static ubyte N {0x4e};
        const static ubyte G {0x47};
        const static ubyte MsDosCR {0x0d};
        const static ubyte MsDosLF {0x0a};
        const static ubyte MsDosEnd {0x1a};
        const static ubyte UnixLF {0x0a};

        static utils::LimitedSequence<ubyte, 8> toBytes();
        static bool isValid(utils::LimitedSequence<ubyte, 8> bytes);
    };

} // structure

#endif //PNG_DECODER_SIGNATUREDATA_H
