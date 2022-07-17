#ifndef HUFFMAN_HPP
// This will allow the header files to be imported only once in a file

#include <iostream>
#include <string>
#include <queue>
#include <unordered_map>
// importing relevant data structures and packages from c++ and c library

using namespace std;

#define EMPTY_STRING ""
// Defining a condition when the string could be empty

struct Node
{
    char ch;
    int freq;
    Node *left, *right;
};
// Defining Node that will store character occouring in a sentence, its frequency
// and access to nodes pointing towards left and right

class huffman
// Huffman Class having all the functions and structures defined inside it that will help to encode and decode the sentence entered by user

{
public:
    Node *getNode(char, int, Node *, Node *);
    // Functions to declare and initialize a new tree node

    struct comparatorFunction
    {
        bool operator()(const Node *o1, const Node *o2) const
        {
            return o1->freq > o2->freq;
            // Comparator Function. The highest priority item has the lowest frequency
        }
    };

    bool isLeaf(Node *);
    // This function checks if Huffman Tree has only a single node.

    void encode(Node *, string, unordered_map<char, string> &);
    // This function helps to traverse the tree and store all the huffman codes in a map

    void decode(Node *, int &, string);
    // This function is used to decode the already encoded string

    void buildHuffmanTree(string);
    // This function is used build a Huffman Tree and it also decodes the input string that is entered by user
};

#endif