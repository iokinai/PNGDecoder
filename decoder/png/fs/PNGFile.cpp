//
// Created by MegaD on 30.07.2023.
//

#include <fstream>
#include <memory>
#include "PNGFile.h"
#include "../../../utils/LimitedSequence.h"
#include "../SignatureData.h"

namespace fs {
    const std::string &PNGFile::getFilePath() const {
        return FilePath;
    }

    const std::vector<uint8_t> &PNGFile::getFileData() const {
        return FileData;
    }

    PNGFile::PNGFile(std::string path) : FilePath(std::move(path)) {
    }

    void PNGFile::read() {
        std::ifstream png(getFilePath(), std::ios::in | std::ios::binary);

        if (!png.is_open()) {
            throw std::ios_base::failure("Couldn't open file!");
        }

        png.seekg(0, std::ios::end);
        std::streampos fileSize = png.tellg();
        png.seekg(0, std::ios::beg);

        std::unique_ptr<std::vector<uint8_t>> bytes = std::make_unique<std::vector<uint8_t>>(fileSize);

        png.read(reinterpret_cast<char *>(bytes->data()), fileSize);

        png.close();

        this->FileData = *bytes;
    }

    bool PNGFile::isValidPNG() {
        utils::LimitedSequence<uint8_t, 8> Signature = structure::signature::SignatureData::toBytes();
        std::vector<uint8_t> FileSig(FileData.begin(), FileData.begin() + 8);

        return FileSig == Signature.getVector();
    }

    const char *PNGFile::WrongPNG::what() const noexcept {
        return "File is corrupted or have an unsupported type!";
    }
} // fs