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
        std::string parseChunkName(const std::vector<uint8_t>::iterator& startsAt);
        bool hasPLTE();
        bool hasIHDR();

        void parseChunk(const std::string& name, std::vector<uint8_t>::iterator& start, bool& iend);
        void parseIHDR(std::vector<uint8_t>::iterator& start);

        template<typename T>
        T readBytesToValue(typename std::vector<uint8_t>::const_iterator startIndex);

    private:
        std::vector<uint8_t> data;
        PNGImageConstructor imageConstructor;
    };

} // parser

#endif //PNG_DECODER_PARSER_H
