//
// Created by MegaD on 05.08.2023.
//

#ifndef PNG_DECODER_COMPILETIME_H
#define PNG_DECODER_COMPILETIME_H

#include <cstdint>

namespace compiletime {
    consteval size_t strlen(const char* str) {
        size_t length = 0;
        while (str[length] != '\0') {
            length++;
        }
        return length;
    }

    consteval uint32_t hash(const char* string) {
        uint32_t hash = 0;

        for (int i = 0; i < strlen(string); i++) {
            hash = (hash << 8) | string[i];
        }

        return hash;
    }
}

#endif //PNG_DECODER_COMPILETIME_H
