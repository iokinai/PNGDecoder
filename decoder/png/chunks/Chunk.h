//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_CHUNK_H
#define PNG_DECODER_CHUNK_H

#include <cstdint>
#include "../../../Types.h"
#include "../../../utils/LimitedSequence.h"

using ChunkNameString = utils::LimitedSequence<char, 4>;

namespace structure::chunks {

    template <class ChunkData>
    class Chunk {
    private:
        uint32_t DataSize;
        ChunkNameString ChunkName;
        std::vector<byte> RawData;
        uint32_t CRC32;

        ChunkData Data;

    public:
        Chunk(uint32_t dataSize, const ChunkNameString &chunkName, const std::vector<byte> &rawData, uint32_t crc32,
              ChunkData data);

    };

} // structure::chunks

#endif //PNG_DECODER_CHUNK_H
