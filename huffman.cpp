#include <iostream>
#include "huffman.hpp"
//  Importing iostream package from c++ library and importing huffman.hpp header file

Node *huffman::getNode(char ch, int freq, Node *left, Node *right)
{
    Node *node = new Node();
    // creating a new node

    node->freq = freq;
    node->ch = ch;
    node->left = left;
    node->right = right;

    return node;
}
// Function to declare and initialize a new tree node

bool huffman::isLeaf(Node *root)
{
    return root->left == nullptr && root->right == nullptr;
    // This function checks if Huffman Tree has only a single node.
}

void huffman::encode(Node *root, string str, unordered_map<char, string> &huffmanCode)
{
    // if found a nullpointer, we return
    if (root == NULL)
    {
        return;
    }

    // if found a leaf node
    if (isLeaf(root))
    {
        huffmanCode[root->ch] = (str != EMPTY_STRING) ? str : "1";
    }

    encode(root->left, str + "0", huffmanCode);
    encode(root->right, str + "1", huffmanCode);
}
// This function helps to traverse the tree and store all the huffman codes in a map

void huffman::decode(Node *root, int &index, string str)
{
    if (root == NULL)
    // if found a null pointer, we return
    {
        return;
    }

    if (isLeaf(root))
    // if found a leaf node, we execute here onwards
    {
        cout << root->ch;
        return;
    }

    index++;

    if (str[index] == '0')
    {
        decode(root->left, index, str);
    }
    else
    {
        decode(root->right, index, str);
    }
}
// This function is used to decode the already encoded string

void huffman::buildHuffmanTree(string text)
{
    if (text == EMPTY_STRING)
    // if we find an empty string, we return;
    {
        return;
    }

    unordered_map<char, int> freq;
    for (char ch : text)
    {
        freq[ch]++;
    }
    // We count the frequency of appearance of each character occouring in input
    // This is saved in the map

    priority_queue<Node *, vector<Node *>, comparatorFunction> minHeap;
    // A priority queue is created to store live nodes of the Huffman tree
    // It is a min heap

    for (auto pair : freq)
    {
        minHeap.push(getNode(pair.first, pair.second, nullptr, nullptr));
    }
    // Create a leaf node for each character and add it
    // to the priority queue.

    while (minHeap.size() != 1)
    // We continue this till there is more than one node in the queue
    {

        Node *left = minHeap.top();
        minHeap.pop();
        Node *right = minHeap.top();
        minHeap.pop();
        // We remove the two nodes of the highest priority from the top of minHeap
        // The element at top has the lowest frequency of characters from the queue

        int sum = left->freq + right->freq;
        minHeap.push(getNode('\0', sum, left, right));
        // We create a new internal node with these two nodes as its children and
        // with a frequency equal to the sum of the two nodes' frequencies.
        // The new node is added to minHeap priority queue.
    }

    Node *root = minHeap.top();
    // `root` stores pointer to the root of Huffman Tree

    unordered_map<char, string> huffmanCode;
    // We traverse the Huffman Tree and store all the Huffman Codes in a map
    // After, this we print them

    encode(root, EMPTY_STRING, huffmanCode);

    cout << "Huffman Codes for the characters of input are:\n"
         << endl;
    for (auto pair : huffmanCode)
    {
        cout << pair.first << ": " << pair.second << endl;
    }

    cout << "\nThe original string entered by user is:\n"
         << text << endl;

    // We print the encoded string
    string str;
    for (char ch : text)
    {
        str= str + huffmanCode[ch];
    }

    cout << "\nThe encoded string for the input is:\n"
         << str << endl;
    cout << "\nThe decoded string for the input is:\n";

    if (isLeaf(root))
    {

        while (root->freq--)
        {
            cout << root->ch;
        }
        // This is implemented for special cases. Exapmle: For input like a, aa, aaa, etc.
    }
    else
    {
        int index = -1;
        while (index < (int)str.size() - 1)
        {
            decode(root, index, str);
        }
        // We traverse the Huffman Tree once again and this time,
        // We decode the encoded string after that
    }
}
// This function is used build a Huffman Tree and it also decodes the input string that is entered by user
