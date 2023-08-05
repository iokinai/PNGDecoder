//
// Created by MegaD on 04.08.2023.
//

#include "IDATData.h"

namespace structure::chunks {
    IDATData::IDATData(const std::vector<uint8_t> &idatData) : idatData(idatData) {}

    const std::vector<uint8_t> &IDATData::getIdatData() const {
        return idatData;
    }
} // structure::chunks