//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_CHUNK_H
#define PNG_DECODER_CHUNK_H

#include <cstdint>
#include "../../../utils/LimitedSequence.h"
#include "misc/ChunkType.h"

using ChunkNameString = utils::LimitedSequence<char, 5>;

namespace structure::chunks {

    template <class ChunkData>
    class Chunk {
    private:
        uint32_t DataSize{};
        ChunkType Type;
        std::vector<uint8_t> RawData;
        uint32_t CRC32{};

        ChunkData Data;

    public:
        Chunk(uint32_t dataSize, ChunkType type, const std::vector<uint8_t> &rawData, uint32_t crc32,
              ChunkData data);

        Chunk() = default;
    };

} // structure::chunks

#endif //PNG_DECODER_CHUNK_H
