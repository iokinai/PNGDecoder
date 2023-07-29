//
// Created by MegaD on 29.07.2023.
//

#ifndef PNG_DECODER_LIMITEDSEQUENCE_H
#define PNG_DECODER_LIMITEDSEQUENCE_H

#include <vector>
#include <memory>
#include <exception>
#include <cstring>
#include <valarray>

namespace utils {

    template<class T, size_t Size, class Alloc = std::allocator<T>>
    class LimitedSequence {
    private:
        std::shared_ptr<std::vector<T, Alloc>> vec;

    public:
        class SizeException : public std::exception {
        private:
            size_t size;

        public:
            SizeException(size_t size) : size(size) {
            }

            size_t getCurrentSize() const noexcept {
                return this->size;
            }
        };

        class IndexException : public std::exception {
        private:
            size_t index;

        public:
            IndexException(size_t index) : index(index) {
            }

            size_t getCurrentIndex() const noexcept {
                return this->index;
            }

        };

        LimitedSequence() {
            vec = new std::vector<T, Alloc>(Size);
        }

        LimitedSequence(std::initializer_list<T> values) {
            if (values.size() > Size) {
                throw SizeException(values.size());
            }

            vec = std::make_shared<std::vector<T, Alloc>>(values.begin(), values.end());
        }

        T operator[](size_t index) {
            if (index > Size) {
                throw IndexException(index);
            }
        }

        const std::shared_ptr<std::vector<T, Alloc>> &getVectorPtr() const noexcept {
            return this->vec;
        }

        inline bool
        operator==(const LimitedSequence<T, Size, Alloc> &second) {
            return *this->getVectorPtr() == *second.getVectorPtr();
        }

        inline bool
        operator!=(const LimitedSequence<T, Size, Alloc> &second) {
            return !(*this == second);
        }
    };

    template<int Size, class Alloc>
    class LimitedSequence<char, Size, Alloc> {
    private:
        const std::shared_ptr<std::vector<char, Alloc>> vec;

    public:
        LimitedSequence(const char* string) {
            this->vec->assign(string, string + strlen(string) + 1);
        }
    };

} // utils


#endif //PNG_DECODER_LIMITEDSEQUENCE_H
