cmake_minimum_required(VERSION 3.26)
project(png_decoder)

set(CMAKE_CXX_STANDARD 20)

add_executable(png_decoder main.cpp
        decoder/png/SignatureData.h
        utils/LimitedSequence.h
        decoder/png/SignatureData.cpp
        decoder/png/chunks/Chunk.h
        decoder/png/chunks/IHDRData.cpp
        decoder/png/chunks/IHDRData.h
        decoder/png/chunks/misc/ColorType.h
        decoder/png/chunks/misc/CompressionAlgorithm.h
        decoder/png/chunks/misc/FilterAlgorithm.h
        decoder/png/chunks/Chunk.cpp
        decoder/png/parser/Parser.cpp
        decoder/png/parser/Parser.h
        decoder/png/fs/PNGFile.cpp
        decoder/png/fs/PNGFile.h
        decoder/png/PNGImage.cpp
        decoder/png/PNGImage.h
        decoder/png/PNGImageConstructor.cpp
        decoder/png/PNGImageConstructor.h
        utils/SizeException.cpp
        utils/SizeException.h
        utils/IndexException.cpp
        utils/IndexException.h
)
