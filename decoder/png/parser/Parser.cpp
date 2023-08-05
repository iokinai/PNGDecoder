//
// Created by MegaD on 30.07.2023.
//

#include "Parser.h"

namespace parser {
    structure::PNGImage Parser::parse() {
        auto currentPosition =  data.begin() + 8;
        bool iend = false;

        if (!hasIHDR()) {
            throw std::exception(); // TODO: rework
        }

        while (!iend) {
            parseChunk(parseChunkType(currentPosition), currentPosition, iend);
        }

        return this->imageConstructor.getFinalImage();
    }

    Parser::Parser(const std::vector<uint8_t>& data) : data(data), imageConstructor(PNGImageConstructor()) {
    }

    ChunkType Parser::parseChunkType(const std::vector<uint8_t>::iterator& startsAt) {
        return static_cast<ChunkType>(readBytesToValue<uint32_t>(startsAt + 4));
    }

    bool Parser::hasIHDR() {
        return isFirstChunkA(ChunkType::IHDR);
    }

    void Parser::parseChunk(ChunkType type, std::vector<uint8_t>::iterator &start, bool &iend) {
        switch (type) {
            case ChunkType::IHDR:
                parseIHDR(start);
                break;
            case ChunkType::IDAT:
                parseIDAT(start);
                break;
            case ChunkType::IEND:
                parseIEND(start, iend);
                break;
            default:
                skipChunk(start);
                break;
        }
    }

    void Parser::parseIHDR(std::vector<uint8_t>::iterator &start) {
        const uint8_t defaultDataSize = 13;

        auto size = readBytesToValue<uint32_t>(start);

        if (size != defaultDataSize) {
            throw utils::exceptions::SizeException(size);
        }

        std::vector<uint8_t> rawIHDR(start, start + chunkSizeWithoutData + defaultDataSize);

        auto dataStart = rawIHDR.begin();

        auto w = readBytesToValue<uint32_t>(dataStart + 8);
        auto h = readBytesToValue<uint32_t>(dataStart + 12);
        auto colorDepPerChannel = readBytesToValue<uint8_t>(dataStart + 16);
        auto colorType = static_cast<colors::ColorType>(readBytesToValue<uint8_t>(dataStart + 17));
        auto compressionAlgorithm = static_cast<algorithms::CompressionAlgorithm>(readBytesToValue<uint8_t>(dataStart + 18));
        auto filterAlgorithm = static_cast<algorithms::FilterAlgorithm>(readBytesToValue<uint8_t>(dataStart + 19));
        bool interlace = readBytesToValue<bool>(dataStart + 20);

        this->imageConstructor.addIHDR(Chunk<IHDRData>(defaultDataSize, ChunkType::IHDR, rawIHDR, readBytesToValue<uint32_t>(dataStart + 21), IHDRData(w, h, colorDepPerChannel, colorType, compressionAlgorithm, filterAlgorithm, interlace)));

        start += static_cast<uint32_t>(rawIHDR.size());
    }

    void Parser::parseIDAT(std::vector<uint8_t>::iterator &start) {
        auto dataSize = readBytesToValue<uint32_t>(start);
        std::vector<uint8_t> rawData(start, start + chunkSizeWithoutData + dataSize);

        std::vector<uint8_t> idatData(start + 8, start + 8 + dataSize);

        this->imageConstructor.addIDAT(Chunk<IDATData>(dataSize, ChunkType::IDAT, rawData, readBytesToValue<uint32_t>(start + 8 + dataSize), IDATData(idatData)));

        start += static_cast<uint32_t>(rawData.size());
    }

    void Parser::parsePLTE(std::vector<uint8_t>::iterator &start) {
        auto plteSize = readBytesToValue<uint32_t>(start);

        start += chunkSizeWithoutData + plteSize;

        return; // TODO: rework
    }

    bool Parser::isFirstChunkA(ChunkType type) {
        return parseChunkType(data.begin() + 8) == type;
    }

    void Parser::skipChunk(std::vector<uint8_t>::iterator &start) {
        start += chunkSizeWithoutData + readBytesToValue<uint32_t >(start);
    }

    void Parser::parseIEND(std::vector<uint8_t>::iterator &start, bool &iend) {
        iend = true;
        return;
    }

    template<typename T>
    T Parser::readBytesToValue(std::vector<uint8_t>::const_iterator startIndex)  {
        T value = 0;
        for (size_t i = 0; i < sizeof(T); ++i) {
            value = (value << 8) | static_cast<T>(*(startIndex + i));
        }
        return value;
    }
} // parser