//
// Created by MegaD on 29.07.2023.
//

#include "SignatureData.h"

namespace structure::signature {
    utils::LimitedSequence<uint8_t, 8> SignatureData::toBytes() {
        return {
            SignatureData::NotAnAscii,
            SignatureData::P,
            SignatureData::N,
            SignatureData::G,
            SignatureData::MsDosCR,
            SignatureData::MsDosLF,
            SignatureData::MsDosEnd,
            SignatureData::UnixLF,
        };
    }
}