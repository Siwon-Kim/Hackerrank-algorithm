#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanTree.hpp"
#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include <map>
#include <iostream>
#include <stack>

std::string compress(const std::string inputStr) {
    std::map<char, size_t> charMap;
    std::map<char, size_t>::iterator it;

    // 256 = the last decimal in ASCII table
    size_t count[256] = {0};

    // reading characters from input string and counting their frequencies
    // and storing those frequencies in the array
    for(int i=0; inputStr[i]!='\0'; ++i) count[inputStr[i]++];
    for(int i=0; i<256; ++i) {
        if(count[i] != 0) {
            charMap.insert(std::pair<char, size_t>((char)i, count[i]));
        }
    }

    // create Heap Priority Queue and populate characters and frequencies
    // sorted first by the lowest frequency
    HeapQueue<HuffmanNode*, HuffmanNode::Compare> PQ;
    for(it=charMap.begin(); it!=charMap.end(); ++it) {
        // first: char, second: frequency
        HuffmanNode* node = new HuffmanNode(it->first, it->second);
        n++;
        PQ.insert(node);
    }

    // Huffman Tree creating from PQ
    // Until there is one element left in the priority queue
    // 1. Remove two characters/frequencies pairs from the PQ
    // 2. Turn them into leaf nodes on a binary tree
    // 3. Create an intermediate node to be their parent using the sum of the frequencies for thos children
    // 4. Put that intermediate node back in the PQ
    while(PQ.size() != 1) {
        // 1
        HuffmanNode* node1 = PQ.min();
        PQ.removeMin();
        HuffmanNode* node2 = PQ.min();
        PQ.removeMin();
        // 2
        size_t frequencyT = (node1->getFrequency() + node2-> getFrequency());
    }
}

std::string serializeTree() const {
    
}

std::string decompress(const std::string inputCode, const std::string serializedTree) {
    
}