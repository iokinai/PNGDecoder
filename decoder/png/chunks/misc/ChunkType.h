//
// Created by MegaD on 05.08.2023.
//

#ifndef PNG_DECODER_CHUNKTYPE_H
#define PNG_DECODER_CHUNKTYPE_H

#include "../../../../utils/CompileTime.h"

enum class ChunkType {
    IHDR = compiletime::hash("IHDR"),
    IDAT = compiletime::hash("IDAT"),
    IEND = compiletime::hash("IEND"),
};

#endif //PNG_DECODER_CHUNKTYPE_H
