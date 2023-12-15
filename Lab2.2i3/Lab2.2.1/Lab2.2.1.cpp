#include<iostream>
#include<string>
#include<bitset>
#include<fstream>
using namespace std;

void Encoding(string text, bitset<16>* bitArray)
{
	for (int i = 0; i < text.size(); i++)
	{
		bitArray[i][6] = i % 2;
		bitArray[i][15] = text[i] % 2;
		for (int j = 0; j <= 5; j++) { bitArray[i][j] = i & (1 << j); }
		for (int j = 7; j <= 14; j++) { bitArray[i][j] = text[i] & (1 << j - 7); }
	}
}

void Decoding(string& text, bitset<16>* bitArray)
{
	for (int i = 0; i < 64; i++) { text.push_back('\0'); }
	for (int i = 0; i < text.size(); i++)
	{
		int pos = 0, symbol = 0;
		for (int j = 0; j <= 5; j++) { if (bitArray[i][j]) { pos |= (1 << j); } }
		for (int j = 7; j <= 14; j++) { if (bitArray[i][j]) { symbol |= (1 << j - 7); } }
		text[pos] = symbol;
	}
}

void ReadFromFile(bitset<16>* bitArray)
{
	string bits;
	ifstream file("data.bin");
	getline(file, bits);
	file.close();
	for (int i = 0; i < 64; i++) { for (int j = 0; j < 16; j++) { bitArray[i][j] = (bits[i * 16 + j] - '0'); } }
}

void WriteToFile(bitset<16>* bitArray)
{
	string bits;
	for (int i = 0; i < 64; i++) { for (int j = 0; j < 16; j++) { bits.push_back(bitArray[i][j] + '0'); } }
	ofstream file("data.bin");
	file << bits;
	file.close();
}

int main()
{
	bitset<16> bitArray[64];
	for (int i = 0; i < 64; i++) { bitArray[i].reset(); }
	string text = "";
	if (text == "")
	{
		ReadFromFile(bitArray);
		Decoding(text, bitArray);
		cout << text << endl;
	}
	else
	{
		for (; text.size() > 64;) { text.pop_back(); }
		for (; text.size() < 64;) { text.push_back(' '); }
		Encoding(text, bitArray);
		WriteToFile(bitArray);
	}
}
