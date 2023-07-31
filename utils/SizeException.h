//
// Created by MegaD on 31.07.2023.
//

#ifndef PNG_DECODER_SIZEEXCEPTION_H
#define PNG_DECODER_SIZEEXCEPTION_H

#include <exception>

namespace utils::exceptions {

    class SizeException : public std::exception {
    private:
        size_t size;

    public:
        explicit SizeException(size_t size);

        [[nodiscard]] size_t getSize() const;
    };

} // utils::exceptions

#endif //PNG_DECODER_SIZEEXCEPTION_H
