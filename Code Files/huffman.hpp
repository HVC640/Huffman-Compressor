 //Header Guards to prevent header files from being included multiple times
#ifndef HUFFMAN_HPP
#define HUFFMAN_HPP
#include <string>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

//Defining Huffman Tree Node
struct Node {
    char data;
    unsigned freq;
    string code;
    Node *left, *right;

    Node() {
        left = right = NULL;
    }
};

class huffman {
    private:
    	//Data Members
        vector <Node*> arr;
        fstream inFile, outFile;
        string inFileName, outFileName;
        Node *root;
        
        //Data Methods
        class Compare {
            public:
                bool operator() (Node* l, Node* r)
                {
                    return l->freq > r->freq;
                }
        };
        priority_queue <Node*, vector<Node*>, Compare> minHeap;

	//Helper Methods
        void createArr();
        void traverse(Node*, string);
        int binToDec(string);
        string decToBin(int);
        
        //Heap Methods
        void buildTree(char, string&);
        void createMinHeap();
        void createTree();
        void createCodes();
        
        //File Methods
        void saveEncodedFile();
        void saveDecodedFile();
        
        //Tree Methods
        void getTree();

    public:
        //Constructor
        huffman(string inFileName, string outFileName)
        {
            this->inFileName = inFileName;
            this->outFileName = outFileName;
            createArr();
        }
        //Compressing and Decompressing Methods
        void compress();
        void decompress();
};
#endif
