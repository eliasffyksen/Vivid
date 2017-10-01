//
// Created by Ole on 10.09.2017.
//

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <utility>

#define LOG(x) (std::cout << x << std::endl)

#define IMAGE_FORMAT_RGBA 6

struct Chunk {
	unsigned int length;
	std::string type;
	std::vector<unsigned char> data;
	unsigned int crc;
	
	Chunk(unsigned int length, std::string type, std::vector<unsigned char>& data, unsigned int crc)
			: length(length), type(std::move(type)), data(data), crc(crc) {}
};

struct Pixel {
	union {
		struct {
			unsigned char red, green, blue, alpha;
		};
		struct {
			unsigned char r{}, g{}, b{}, a{};
		};
	};
	
	Pixel(unsigned char alpha, unsigned char red, unsigned char green, unsigned char blue)
			: alpha(alpha), red(red), green(green), blue(blue) {}
	Pixel()
			: alpha(0), red(0), green(0), blue(0) {}
	
	unsigned int color() { return a << 24 | r << 16 | g << 8 | b; }
};

struct ImageFormat {
	unsigned int width;
	unsigned int height;
	unsigned char bitDepth;
	unsigned char colorFormat;
	
	ImageFormat()
			: width(0), height(0), bitDepth(0), colorFormat(0) {}
};

class Image {
private:
	ImageFormat format;
	Pixel* pixels;
public:
	explicit Image(const std::string& path);
	~Image();
	
	inline const Pixel& getPixel(unsigned int& x, unsigned int& y) { return pixels[x + y * format.width]; }
	inline const Pixel* const getPixels() const { return pixels; }
	inline const unsigned int& getWidth() const { return format.width; }
	inline const unsigned int& getHeight() const { return format.height; }
	inline const unsigned char& getBitDepth() const { return format.bitDepth; }
	inline const unsigned char& getColorFormat() const { return format.colorFormat; }
	
	inline const ImageFormat& getFormat() const { return format; }
private:
	void loadChunks(std::vector<Chunk>& chunks, const unsigned char* data, unsigned int size);
	Chunk loadChunk(const unsigned char* data, unsigned int& offset);
};


