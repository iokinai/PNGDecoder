//
// Created by MegaD on 04.08.2023.
//

#ifndef PNG_DECODER_COMPILETILEHASH_H
#define PNG_DECODER_COMPILETILEHASH_H

#define DEBUG

#ifndef DEBUG

#endif

#include <cstdint>

consteval uint32_t hash(const char* string) {
    uint32_t hash = 0;

    for (int i = 0; i < 4; i++) {
        hash = (hash << 8) | string[i];
    }

    return hash;
}

#endif //PNG_DECODER_COMPILETILEHASH_H
