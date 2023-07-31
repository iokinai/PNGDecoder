//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_IHDRDATA_H
#define PNG_DECODER_IHDRDATA_H

#include "Chunk.h"
#include "misc/ColorType.h"
#include "misc/CompressionAlgorithm.h"
#include "misc/FilterAlgorithm.h"

namespace structure::chunks {

    class IHDRData {

    private:
        uint32_t width;
        uint32_t height;
        uint8_t colorDepPerChannel;
        colors::ColorType colorType;
        algorithms::CompressionAlgorithm compressionAlgorithm;
        algorithms::FilterAlgorithm filterAlgorithm;
        bool interlace;

    public:
        IHDRData(uint32_t width, uint32_t height, uint8_t colorDepPerChannel, colors::ColorType colorType,
                 algorithms::CompressionAlgorithm compressionAlgorithm, algorithms::FilterAlgorithm filterAlgorithm,
                 bool interlace);

        IHDRData() = default;
    };

} // structure::chunks

#endif //PNG_DECODER_IHDRDATA_H
