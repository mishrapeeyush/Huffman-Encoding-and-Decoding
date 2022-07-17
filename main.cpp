#include "huffman.hpp"
#include <iostream>
#include <string>
// Importing all the relevant packages and huffman.hpp header file

int main()
// Main function from where the Huffman Coding Algorithm is implemented

{
    class huffman obj;
    // An object of class huffman is createrd to access it inside main function

    string text;
    // The text entered by user

    cout << "Enter your sentence. I will encode and decode it using Huffman Coding \n" << endl;
    getline(cin, text);

    obj.buildHuffmanTree(text);
    // The object of huffman class calls buildHuffmanTree function by passing input as its argument

    return 0;
}