//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_LIMITEDSEQUENCE_H
#define PNG_DECODER_LIMITEDSEQUENCE_H

#include <vector>
#include <memory>
#include <exception>
#include <cstring>
#include "SizeException.h"
#include "IndexException.h"

namespace utils {

    template<class T, size_t Size, class Alloc = std::allocator<T>>
    class LimitedSequence {
    private:
        std::vector<T, Alloc> vec;

    public:
        LimitedSequence() {
            vec = std::vector<T, Alloc>(Size);
        }

        LimitedSequence(std::initializer_list<T> values) {
            if (values.size() > Size) {
                throw exceptions::SizeException(values.size());
            }

            vec = std::vector<T, Alloc>(values.begin(), values.end());
        }

        LimitedSequence(const LimitedSequence& other) : vec(std::vector<T, Alloc>(*other.vec)) {}

        T& operator[](size_t index) {
            if (index > Size) {
                throw exceptions::IndexException(index);
            }

            return vec[index];
        }

        const std::vector<T, Alloc> &getVector() const noexcept {
            return this->vec;
        }

        inline bool
        operator==(const LimitedSequence<T, Size, Alloc> &second) {
            return *this->getVector() == *second.getVector();
        }

        inline bool
        operator!=(const LimitedSequence<T, Size, Alloc> &second) {
            return !(*this == second);
        }

        LimitedSequence& operator=(const LimitedSequence& other) {
            if (this == &other) {
                return *this;
            }
            *vec = *other.vec;
            return *this;
        }
    };

    template<size_t Size, class Alloc>
    class LimitedSequence<char, Size, Alloc> {
    private:
        std::vector<char, Alloc> vec;

    public:
        LimitedSequence(const char* string) {
            this->vec = std::vector<char, Alloc>(string, string + strlen(string) + 1);
        }

        LimitedSequence() = default;
    };

} // utils


#endif //PNG_DECODER_LIMITEDSEQUENCE_H
