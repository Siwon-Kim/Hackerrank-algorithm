#ifndef HUFFMANTREE_H
#define HUFFMANTREE_H

#include "HuffmanTree.hpp"
#include "HuffmanBase.hpp"
#include "HeapQueue.hpp"
#include <map>
#include <iostream>
#include <stack>

//tree compression
std::string HuffmanTree::compress(const std::string inputStr) {
  std::map<char, size_t> charMap;
  std::map<char, size_t>::iterator it;

  size_t count[256] = {0};

  //reading characters from input string and counting their frequencies and storing those frequencies in the array.
  for (int i = 0; inputStr[i] != '\0'; i++) {
  count[inputStr[i]]++;
  }
  for(int i = 0; i < 256; i++) {
    if(count[i] != 0){
    charMap.insert(std::pair<char,size_t>((char)i, count[i]));
    }
  }

  //create Heap Priority Queue and populate it.
  HeapQueue<HuffmanNode*, HuffmanNode::Compare> PQ;
    for (it = charMap.begin(); it != charMap.end(); ++it) {
    HuffmanNode* node = new HuffmanNode(it->first, it->second);
    n++;
    PQ.insert(node);
  }

  //huffman tree creating from PQ
  while (PQ.size() != 1){
    HuffmanNode* node1 = PQ.min();
    PQ.removeMin();
    HuffmanNode* node2 = PQ.min();
    PQ.removeMin();
    size_t frequencyT = (node1->getFrequency() + node2->getFrequency());
    HuffmanNode* parentN1N2 = new HuffmanNode('\0', frequencyT, nullptr, node1, node2);
    node1->parent = parentN1N2;
    node2->parent = parentN1N2;
    PQ.insert(parentN1N2);
  }

  //assign root private var.
  root = PQ.min();

  //encoding of each character in the string
  //map for the Huffman Coding for each characters
  std::map<char, std::string> codeMap;
  std::string code = "";
  std::string output = "";

  for (it = charMap.begin(); it != charMap.end(); ++it) {
    findCode(PQ.min(), codeMap, code);
  }
    
  for (auto i : inputStr) {
    output += codeMap[i];
  }
  
  return output;
}

//tree serialization
std::string HuffmanTree::serializeTree() const {
  if (root == nullptr) {
  return "";
}

  std::string output = "";
  serialize(root, output);
  return output;
}

//tree decompression - get the text that was initially encoded by using Huffman Coding
std::string HuffmanTree::decompress(const std::string inputCode, const std::string serializedTree) {
  std::string output = "";
  size_t len = serializedTree.length();
  std::stack<HuffmanNode*> treeStack;

  //reconstruct the tree from serializedTree
  for(auto character : serializedTree) {
    if (character == 'L') {
    continue;
    } else if ((character != 'L') && (character != 'B')) {
    HuffmanNode* huffNode = new HuffmanNode(character, 0);
    treeStack.push(huffNode);
    } else if (character == 'B') {
    HuffmanNode* right = treeStack.top();
    treeStack.pop();
    HuffmanNode* left = treeStack.top();
    treeStack.pop();
    HuffmanNode* branch = new HuffmanNode('\0', 0, nullptr, left, right);
    treeStack.push(branch);
    right->parent = branch;
    left->parent = branch;
    }
  }

  //copy the remained stack to be the root of the newly constructed Huffman Tree & clean up.
  HuffmanNode* root = treeStack.top();
  treeStack.pop();

  //reconstructing the text from the code using the built huffman tree
  HuffmanNode* curr = root;
  for (auto character : inputCode) {
    if (character == '0')
    curr = curr->left;
    else
    curr = curr->right;

  //once hit the leaf, this is the full character, add the char to output, start over from the root.
    if (curr->isLeaf()) {
      output += curr->getCharacter();
      curr = root;
    }
  }

  return output;
}

#endif /*HUFFMANTREE_HPP*/
