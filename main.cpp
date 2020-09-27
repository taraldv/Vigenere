#include <iostream>
#include "Vigenere.h"

int main(int argc, char const *argv[])
{
	Vigenere v;

	std::vector<std::string> keyList;
	keyList.push_back("Norway");
	keyList.push_back("Oslo");
	v.setKeyList(keyList);
	v.setMessage("The quick brown fox jumps over the lazy dog.");
	v.encrypt();

	std::string cipher2 = v.getCipher();
	std::cout << cipher2 << std::endl;

	return 0;
}

/*

	v.setKey("Kongsberg");
	v.setMessage("The quick brown fox jumps over the lazy dog.");
	v.encrypt();

	std::string cipher = v.getCipher();
	std::cout << cipher << std::endl;

	std::vector<std::string> keyList;
	keyList.push_back("Norway");
	keyList.push_back("Oslo");
	v.setKeyList(keyList);
	v.setMessage("The quick brown fox jumps over the lazy dog.");
	v.encrypt();

	std::string cipher2 = v.getCipher();
	std::cout << cipher2 << std::endl;

	*/