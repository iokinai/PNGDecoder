//
// Created by MegaD on 04.08.2023.
//

#ifndef PNG_DECODER_IDATDATA_H
#define PNG_DECODER_IDATDATA_H

#include <vector>
#include <cstdint>

namespace structure::chunks {

    class IDATData {
    private:
        std::vector<uint8_t> idatData;
    public:
        [[nodiscard]] const std::vector<uint8_t> &getIdatData() const;

    public:
        explicit IDATData(const std::vector<uint8_t> &idatData);
        explicit IDATData() = default;
    };

} // structure::chunks

#endif //PNG_DECODER_IDATDATA_H
