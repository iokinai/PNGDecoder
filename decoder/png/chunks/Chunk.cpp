//
// Created by MegaD on 29.07.2023.
//

#include "Chunk.h"

#include <utility>
#include "IHDRData.h"
#include "IDATData.h"

namespace structure::chunks {

    template<class ChunkData>
    Chunk<ChunkData>::Chunk(uint32_t dataSize, ChunkType type, const std::vector<uint8_t> &rawData, uint32_t crc32,
                            ChunkData data) : DataSize(dataSize), Type(type), RawData(rawData), CRC32(crc32), Data(data) {}


    template class Chunk<IHDRData>;
    template class Chunk<IDATData>;
}