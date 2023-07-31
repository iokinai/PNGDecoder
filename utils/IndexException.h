//
// Created by MegaD on 31.07.2023.
//

#ifndef PNG_DECODER_INDEXEXCEPTION_H
#define PNG_DECODER_INDEXEXCEPTION_H

#include <exception>

namespace utils::exceptions {

    class IndexException : public std::exception {
    private:
        size_t index;

    public:
        [[nodiscard]] size_t getIndex() const;

        explicit IndexException(size_t index);
    };

} // utils::exceptions

#endif //PNG_DECODER_INDEXEXCEPTION_H
