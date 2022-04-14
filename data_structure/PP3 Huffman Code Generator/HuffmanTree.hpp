#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include <map>


class HuffmanTree : HuffmanTreeBase {
private:
    size_t n;
    HuffmanNode* root;
public:
    std::string compress(const std::string inputStr) override;
    std::string serializeTree() const override;
    std::string decompress(const std::string inputCode, const std::string serializedTree) override;
    // when decoding the characters, adding a zero for a left move and a 1 for a right move
    void findCode(const HuffmanNode* node, std::map<char, std::string>& codeMap, std::string code) {
        if(node == nullptr) return;
        if(node->isLeaf()) codeMap[node->getCharacter()] = code;

        findCode(node->left, codeMap, code + "0");
        findCode(node->left, codeMap, code + "1");
    }
    
    // For encoding step, recursive function re recursively serialize the Huffman Tree
    // in preorder traversal
    void serialize(const HuffmanNode* node, std::string& outString) const {
        if(node == nullptr) return;

        serialize(node->left, outString);
        serialize(node->right, outString);

        // if the node is a leaft, add a L plus the character to the tree string
        // if the node is a branch, add B to the tree string
        if(node->isLeaf()) outString = outString + "L" + node->getCharacter();
        if(node->isBranch()) outString += "B";
    }
};

#endif
