//
// Created by MegaD on 30.07.2023.
//

#ifndef PNG_DECODER_PNGFILE_H
#define PNG_DECODER_PNGFILE_H

#include <string>
#include <vector>
#include <cstdint>

namespace fs {

    class PNGFile {
    public:
        [[nodiscard]] const std::string &getFilePath() const;
        [[nodiscard]] const std::vector<uint8_t> &getFileData() const;

        explicit PNGFile(std::string path);

        void read();
        bool isValidPNG();

        class WrongPNG : public std::exception {
            [[nodiscard]] const char * what() const noexcept override;
        };

    private:
        std::string FilePath;
        std::vector<uint8_t> FileData;

        //
    };

} // fs

#endif //PNG_DECODER_PNGFILE_H
