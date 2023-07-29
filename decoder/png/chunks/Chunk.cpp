//
// Created by MegaD on 29.07.2023.
//

#include "Chunk.h"
#include "IHDRData.h"

namespace structure::chunks {

    template<class ChunkData>
    Chunk<ChunkData>::Chunk(uint32_t dataSize, const ChunkNameString &chunkName, const std::vector<byte> &rawData, uint32_t crc32,
          ChunkData data) : DataSize(dataSize), ChunkName(chunkName), RawData(rawData), CRC32(crc32), Data(data) {}


    template class Chunk<IHDRData>;
}