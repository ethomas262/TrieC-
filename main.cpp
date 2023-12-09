#include <iostream>
#include <C:\Users\thoma\VS\FA\TestinC\TestinC\Trie.hpp>

using namespace std;



//simple Test script for functionality
int main() {
	vector<string> testStrings = { "hello", "world", "howareyoy", "doing" };
	Trie t;
	for (const auto& element : testStrings) {
		t.insert(element);
	}




	if (t.search("hello")) {
		printf("Success!!");
	}
	else {
		printf("awww come back when ya get some money, buddy");
	}


	return 0;
}
