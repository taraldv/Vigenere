#ifndef VIGENERE_H
#define VIGENERE_H

#include <iostream>
#include <vector>

class Vigenere{
public:
	Vigenere();
	void encrypt();
	void setKey(std::string key);
	void setKeyList(std::vector<std::string> keyList);
	void setMessage(std::string key);
	void setCipher(std::string cipher);
	std::string getMessage();
	std::string getCipher();
private:
	int charToInt(char c);
	char intToChar(int i,bool uppercase);
	std::vector<std::string> keyList;
	std::string message;
	std::string cipher;
};

#endif