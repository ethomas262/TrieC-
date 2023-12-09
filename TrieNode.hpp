#include <iostream>
#include <vector>

using namespace std;

// TrieNode class represents a node in a Trie data structure
class TrieNode {
public:
    // Constructors
    TrieNode(char input);
    TrieNode();
    
    // Getter method for the character stored in the node
    char getChar() const;
    
    // Add a child to the node, representing the next character in a word
    void addChild(string input, int index);
    
    // Mark the current node as the end of a word
    void setAsWord();
    
    // Search for a child node with a specific character
    TrieNode* searchChild(char child);
    
    // Search for a word in the Trie starting from the current node
    bool searchChild(const string& input, int index);

private:
    char character;          // The character stored in the node
    vector<TrieNode*> children;  // Children nodes representing possible next characters
    bool isWord;             // Flag indicating whether the current node represents the end of a word
};

// Constructor for TrieNode
TrieNode::TrieNode(char input) {
    character = input;
    isWord = false;
}

// Getter method for the character stored in the node
char TrieNode::getChar() const {
    return character;
}

// Mark the current node as the end of a word
void TrieNode::setAsWord() {
    isWord = true;
}

// Add a child to the node, representing the next character in a word
void TrieNode::addChild(string input, int index) {
    if (index < input.size()) {
        TrieNode* temp = searchChild(input[index]);
        if (temp != nullptr) {
            temp->addChild(input, index + 1);
        } else {
            TrieNode* newNode = new TrieNode(input[index]);
            children.push_back(newNode);
            newNode->addChild(input, index + 1);
        }
    } else {
        isWord = true;  // Mark the current node as the end of the word
    }
}

// Search for a child node with a specific character
TrieNode* TrieNode::searchChild(char childChar) {
    for (int i = 0; i < children.size(); ++i) {
        if (children.at(i)->getChar() == childChar) {
            return children.at(i);
        }
    }
    return nullptr;
}

// Constructor for TrieNode with default values
TrieNode::TrieNode() {
    isWord = false;
    character = '-';
}

// Search for a word in the Trie starting from the current node
bool TrieNode::searchChild(const string& input, int index) {
    if (index < input.size()) {
        TrieNode* temp = searchChild(input[index]);
        if (temp == nullptr) {
            return false;
        } else {
            return temp->searchChild(input, index + 1);
        }
    } else {
        return isWord;  // Check if the current node marks the end of a word
    }
}


