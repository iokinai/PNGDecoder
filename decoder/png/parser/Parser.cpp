//
// Created by MegaD on 30.07.2023.
//

#include "Parser.h"

namespace parser {
    structure::PNGImage Parser::parse() {
        auto currentPosition =  data.begin() + 8;
        bool hasPLTE = true;
        bool iend = false;

        while (!iend) {
            parseChunk(parseChunkName(currentPosition), currentPosition, iend);
        }

        return this->imageConstructor.getFinalImage();
    }

    Parser::Parser(const std::vector<uint8_t>& data) : data(data), imageConstructor(PNGImageConstructor()) {
    }

    std::string Parser::parseChunkName(const std::vector<uint8_t>::iterator& startsAt) {
        return { startsAt + 4, startsAt + 8 };
    }

    bool Parser::hasPLTE() {
        return parseChunkName(data.begin() + 8) == "PLTE";
    }

    void Parser::parseChunk(const std::string& name, std::vector<uint8_t>::iterator &start, bool &iend) {
        if (name == "IHDR") {
            parseIHDR(start);
        } else if (name.empty()) {
            //
        } else {
            //
        }
    }

    void Parser::parseIHDR(std::vector<uint8_t>::iterator &start) {
        auto size = readBytesToValue<uint32_t>(start);
        std::vector<uint8_t> rawIHDR(start, start + 25);

        if (size != 13) {
            throw utils::exceptions::SizeException(size);
        }

        auto dataStart = rawIHDR.begin();

        auto w = readBytesToValue<uint32_t>(dataStart + 8);
        auto h = readBytesToValue<uint32_t>(dataStart + 12);
        auto colorDepPerChannel = readBytesToValue<uint8_t>(dataStart + 16);
        auto colorType = static_cast<colors::ColorType>(readBytesToValue<uint8_t>(dataStart + 17));
        auto compressionAlgorithm = static_cast<algorithms::CompressionAlgorithm>(readBytesToValue<uint8_t>(dataStart + 18));
        auto filterAlgorithm = static_cast<algorithms::FilterAlgorithm>(readBytesToValue<uint8_t>(dataStart + 19));
        bool interlace = readBytesToValue<bool>(dataStart + 20);

        this->imageConstructor.addIHDR(Chunk<IHDRData>(13, "IHDR", rawIHDR, readBytesToValue<uint32_t>(dataStart + 21), IHDRData(w, h, colorDepPerChannel, colorType, compressionAlgorithm, filterAlgorithm, interlace)));

        start += static_cast<uint32_t>(rawIHDR.size());
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