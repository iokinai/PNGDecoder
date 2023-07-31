//
// Created by MegaD on 29.07.2023.
//

#include "Chunk.h"

#include <utility>
#include "IHDRData.h"

namespace structure::chunks {

    template<class ChunkData>
    Chunk<ChunkData>::Chunk(uint32_t dataSize, ChunkNameString chunkName, const std::vector<uint8_t> &rawData, uint32_t crc32,
                            ChunkData data) : DataSize(dataSize), ChunkName(std::move(chunkName)), RawData(rawData), CRC32(crc32), Data(data) {}


    template class Chunk<IHDRData>;
}