//
// Created by MegaD on 30.07.2023.
//

#ifndef PNG_DECODER_PNGFILE_H
#define PNG_DECODER_PNGFILE_H

#include <string>
#include <vector>
#include "../../../Types.h"

namespace fs {

    class PNGFile {
    public:
        const std::string &getFilePath() const;
        const std::vector<byte> &getFileData() const;

        explicit PNGFile(std::string path);

        void read();
        bool isValidPNG();

        class WrongPNG : public std::exception {
            const char * what() const noexcept override;
        };

    private:
        std::string FilePath;
        std::vector<byte> FileData;

        //
    };

} // fs

#endif //PNG_DECODER_PNGFILE_H
