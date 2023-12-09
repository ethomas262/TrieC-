#include <iostream>
#include <vector>


using namespace std;

class TrieNode {
public:
	TrieNode(char input);
	TrieNode();
	char getChar() const;
	void addChild(string input, int index);
	void setAsWord();
	TrieNode* searchChild(char child);
	bool searchChild(const string& input, int index);
private:
	char character;
	vector<TrieNode*> children;
	bool isWord;
};




TrieNode::TrieNode(char input) {
	character = input;
	isWord = false;
}
char TrieNode::getChar() const {
	return character;
}
void TrieNode::setAsWord() {
	isWord = true;
}
void TrieNode::addChild(string input, int index) {
	if (index < input.size()) {

		TrieNode* temp = searchChild(input[index]);
		if (temp != nullptr) {
			temp->addChild(input, input[index + 1]);
		}
		else {
			TrieNode* newNode = new TrieNode(input[index]);
			children.push_back(newNode);
			newNode->addChild(input, index + 1);
		}

	}
	else {
		isWord = true;
	}
}
TrieNode* TrieNode::searchChild(char childChar) {
	for (int i = 0; i < children.size(); ++i) {
		if (children.at(i)->getChar() == childChar) {
			return children.at(i);
		}
	}
	return nullptr;
}
TrieNode::TrieNode() {
	isWord = false;
	character = '-';
}
bool TrieNode::searchChild(const string& input, int index) {
	if (index < input.size()) {
		TrieNode* temp = searchChild(input[index]);
		if (temp == nullptr) {
			return false;
		}
		else {
			return temp->searchChild(input, index + 1);
		}
	}
	else {
		return isWord;  // Check if the current node marks the end of a word
	}
}