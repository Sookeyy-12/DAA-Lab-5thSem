#include <bits/stdc++.h>
using namespace std;

typedef struct huffnode {
    int val;
    char ch;
    struct huffnode *up;
    struct huffnode *left;
    struct huffnode *right;
    bool isLeaf;
} node;

// Create a new node with a given value and character
node* createNode(int val, char ch = '\0') {
    node* newNode = (node*)malloc(sizeof(node));
    newNode->left = nullptr;
    newNode->right= nullptr;
    newNode->up = nullptr;
    newNode->val = val;
    newNode->ch = ch;
    newNode->isLeaf = (ch != '\0');
    return newNode;
}

// Insert two nodes into the Huffman tree and create a parent node
node* insertNode(node* leftChild, node* rightChild) {
    int leftval = leftChild->val;
    int rightval = rightChild->val;
    node* newNode = createNode(leftval + rightval);
    newNode->left = leftChild;
    newNode->right = rightChild;
    leftChild->up = newNode;
    rightChild->up = newNode;
    return newNode;
}

// Compare nodes based on their values
struct compare {
    bool operator()(node* a, node* b) {
        return a->val > b->val;
    }
};

// Build Huffman tree from the given frequency map
node* buildHuffmanTree(const unordered_map<char, int>& freq) {
    priority_queue<node*, vector<node*>, compare> minHeap;

    // Create leaf nodes for each character and add them to the min-heap
    for (const auto& pair : freq) {
        minHeap.push(createNode(pair.second, pair.first));
    }

    // Build the Huffman Tree
    while (minHeap.size() > 1) {
        node* left = minHeap.top(); minHeap.pop();
        node* right = minHeap.top(); minHeap.pop();
        node* parent = insertNode(left, right);
        minHeap.push(parent);
    }

    return minHeap.top();
}

// Generate Huffman codes from the Huffman Tree
void generateCodes(node* root, const string& str, unordered_map<char, string>& codes) {
    if (root == nullptr) return;
    if (root->isLeaf) {
        codes[root->ch] = str;
    }
    generateCodes(root->left, str + "0", codes);
    generateCodes(root->right, str + "1", codes);
}

// Encode the input string using the Huffman codes
string encode(const string& str, const unordered_map<char, string>& codes) {
    string encodedStr;
    for (char ch : str) {
        encodedStr += codes.at(ch);
    }
    return encodedStr;
}

// Main function to handle Huffman coding
void huffman(const string& str) {
    // Calculate frequency of each character
    unordered_map<char, int> freq;
    for (char ch : str) {
        freq[ch]++;
    }
    // Build the Huffman Tree
    node* root = buildHuffmanTree(freq);
    // Generate Huffman codes
    unordered_map<char, string> codes;
    generateCodes(root, "", codes);
    // Encode the input string
    string encodedStr = encode(str, codes);
    // Print the Huffman codes and the encoded string
    cout << "Character Codes:\n";
    for (const auto& pair : codes) {
        cout << pair.first << ": " << pair.second << endl;
    }
    cout << "Encoded String: " << encodedStr << endl;
}

int main() {
    huffman("BCCABBDDAECCBBAEDDCC");
    huffman("122341322144344");
    return 0;
}
