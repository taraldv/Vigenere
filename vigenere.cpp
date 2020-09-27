#include "Vigenere.h"

Vigenere::Vigenere(){

}

//For (m+k) % 26 to work, I convert the ascii char to int in 0-25 range
int Vigenere::charToInt(char c){
	int output = std::toupper(c);
	//A in ascii is 65
	return output - 65;

}
//Convert the int in ranges 0-25 back to proper ascii letter
char Vigenere::intToChar(int i, bool uppercase){
	if(uppercase){
		return i + 65;
	} else {
		return i + 97;
	}
}

void Vigenere::encrypt(){
	cipher = "";
	for(int x=0;x<keyList.size();x++){
		std::string key = keyList[x];
		int j = 0;

		//If we have multiple keys, the previous cipher becomes the next message.
		if(x != 0){
			message = cipher;
			cipher = "";
		}
		for(int i=0;i<message.size();i++){
			//Use modulo to loop the key string, for decryption I would need to
			// store the j variable after finding the ciphertext
			char k = key[j % key.size()];
			char m = message[i];
			bool upper = m < 'a';
			//If the char is not a letter, add it to cipher and skip the encryption.
			if(m == ' ' || m == '.'){
				cipher = cipher + m;
				continue;
			}
			//Only increase the key index if m is a letter.
			j++;
			int cipherInt = (charToInt(m) + charToInt(k)) % 26;
			char c = intToChar(cipherInt, upper);
			cipher = cipher + c;
		}
	}
}

void Vigenere::setKeyList(std::vector<std::string> _keyList){
	keyList = _keyList;
}

void Vigenere::setKey(std::string key){
	keyList.push_back(key);
}

void Vigenere::setMessage(std::string _message){
	message = _message;
}

void Vigenere::setCipher(std::string _cipher){
	cipher = _cipher;
}

std::string Vigenere::getMessage(){
	return message;
}

std::string Vigenere::getCipher(){
	return cipher;
}