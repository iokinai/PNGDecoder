//
// Created by MegaD on 31.07.2023.
//

#include "IndexException.h"

namespace utils::exceptions {
        IndexException::IndexException(size_t index) : index(index) {}

    size_t IndexException::getIndex() const {
        return index;
    }
} // utils::exceptions