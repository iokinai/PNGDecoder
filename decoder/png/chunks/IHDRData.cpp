//
// Created by MegaD on 29.07.2023.
//

#include "IHDRData.h"

namespace structure::chunks {

    IHDRData::IHDRData(uint32_t width, uint32_t height, ubyte colorDepPerChannel, colors::ColorType colorType,
                         algorithms::CompressionAlgorithm compressionAlgorithm,
                         algorithms::FilterAlgorithm filterAlgorithm, bool interlace) : width(width), height(height),
                                                                                        colorDepPerChannel(
                                                                                                colorDepPerChannel),
                                                                                        colorType(colorType),
                                                                                        compressionAlgorithm(
                                                                                                compressionAlgorithm),
                                                                                        filterAlgorithm(
                                                                                                filterAlgorithm),
                                                                                        interlace(interlace) {}

} // structure::chunks