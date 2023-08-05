//
// Created by MegaD on 30.07.2023.
//

#ifndef PNG_DECODER_PARSER_H
#define PNG_DECODER_PARSER_H

#include "../PNGImage.h"
#include "../PNGImageConstructor.h"

using structure::constructor::PNGImageConstructor;

namespace parser {

    class Parser {
    public:
        explicit Parser(const std::vector<uint8_t>& data);

        structure::PNGImage parse();
        ChunkType parseChunkType(const std::vector<uint8_t>::iterator& startsAt);
        bool hasIHDR();

        void parseChunk(ChunkType type, std::vector<uint8_t>::iterator& start, bool& iend);
        void parseIHDR(std::vector<uint8_t>::iterator& start);
        void parseIDAT(std::vector<uint8_t>::iterator& start);
        void parsePLTE(std::vector<uint8_t>::iterator& start);
        void parseIEND(std::vector<uint8_t>::iterator& start, bool& iend);

        void skipChunk(std::vector<uint8_t>::iterator& start);

        template<typename T> T readBytesToValue(typename std::vector<uint8_t>::const_iterator startIndex);

    private:
        const uint8_t chunkSizeWithoutData = 4 * 3;
        std::vector<uint8_t> data;
        PNGImageConstructor imageConstructor;

        bool isFirstChunkA(ChunkType type);
    };

} // parser

#endif //PNG_DECODER_PARSER_H
