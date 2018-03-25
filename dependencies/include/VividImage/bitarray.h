//
// Created by Ole on 10.09.2017.
//

#pragma once

#include <bitset>
#include <vector>
#include <iostream>

#define BITSET_SIZE 128

namespace vivid { namespace util {
	
	class BitArray {
	private:
		std::vector<std::bitset<BITSET_SIZE>*> bitsets;
		std::bitset<BITSET_SIZE>* current;
		unsigned short localSize = 0;
		unsigned int totalSize = 0;
	public:
		BitArray();
		BitArray(const BitArray& other);
		explicit BitArray(const unsigned int& length);
		BitArray(const int& value, unsigned int length);
		explicit BitArray(const std::string& bits);
		BitArray(const bool* bits, const unsigned int& size);
		
		~BitArray();
		
		void pushBack(const bool& one);
		void pushBack(const unsigned char& byte);
		void pushBack(const std::string& one);
		void pushFront(const bool& one);
		void setBit(const unsigned int& pos, bool one);
		bool getBit(const unsigned int& pos) const;
		
		void addBit(const unsigned int& position);
		void add(const unsigned int& value);
		void add(const BitArray& value);
		
		unsigned int read(const unsigned int& position, const unsigned int& length, const bool& reverse = false);
		
		inline const unsigned int& getSize() const { return totalSize; }
		
		const std::string toString() const;
		
		bool operator==(const BitArray& right) const;
	private:
		void updateSize();
	};
	
	std::ostream& operator<<(std::ostream& stream, const BitArray& array);
	std::ostream& operator<<(std::ostream& stream, const BitArray* const array);
	
}}
