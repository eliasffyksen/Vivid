//
// Created by Ole on 10.09.2017.
//

#pragma once

#include "node.h"
#include "bitarray.h"
#include <vector>
#include <map>

namespace vivid { namespace util {
	
	class Tree {
	private:
		Node* root = nullptr;
		std::map<unsigned int, std::string> codes; // (symbol, code)
	public:
		explicit Tree(std::vector<Leaf*>& data);
		Tree(std::vector<unsigned int> symbols, std::vector<unsigned int> lengths);
		~Tree();
		
		std::string uncompress(const std::string& compressed);
		std::string uncompress(const BitArray& compressed);
		unsigned int uncompressOneCode(const std::string& compressed, const unsigned int& start, unsigned int* end);
		unsigned int uncompressOneCode(const BitArray& compressed, const unsigned int& start, unsigned int* end);
		
		BitArray* compress(const std::vector<unsigned int>& uncompressed);
		
		void print();
	private:
		void createTree(const std::vector<BitArray*>& codes, const std::vector<unsigned int>& symbols, Node* parent, const BitArray& curCode);
		
		void saveCodes();
	};
	
}}
