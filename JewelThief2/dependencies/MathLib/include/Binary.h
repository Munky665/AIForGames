#pragma once
class Binary
{
public:
	Binary();
	int binToDec(const char* binaryString);
	void decToBin(char* binaryString, int len, int value);
	void setBit(char& binfield, char bit, char value);
	char checkBit(char& bitfield, char bit);
	
	~Binary();
};

