//
// Created by MegaD on 31.07.2023.
//

#include "SizeException.h"

namespace utils::exceptions {
        SizeException::SizeException(size_t size) : size(size) {}

    size_t SizeException::getSize() const {
        return size;
    }
} // utils::exceptions