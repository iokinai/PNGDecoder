//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_COMPRESSIONALGORITHM_H
#define PNG_DECODER_COMPRESSIONALGORITHM_H

namespace structure::chunks::algorithms {
    enum class CompressionAlgorithm : uint8_t {
        Deflate = 0,
    };
}

#endif //PNG_DECODER_COMPRESSIONALGORITHM_H
