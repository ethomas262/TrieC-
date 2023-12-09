#include <iostream>
#include <string>
#include <vector>
#include <C:\Users\thoma\VS\FA\TestinC\TestinC\TrieNode.hpp>
using namespace std;

class Trie {
public:
	Trie();
	void insert(string input);
	bool search(string input);
	string suggest(string input);

private:
	TrieNode root; 	//Root TrieNode with Null Value used to maintain start index
};

Trie::Trie() {
	root = TrieNode();
}
void Trie::insert(string input) {
	root.addChild(input, 0);
}
bool Trie::search(string input) {
	return root.searchChild(input, 0);
}
string suggest(string input) {
	return "FIXME:: ADD SUGGESTION FUNCTIONALITY";
}


