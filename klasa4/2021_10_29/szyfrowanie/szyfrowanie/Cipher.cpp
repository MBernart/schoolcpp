#include "Cipher.h"

std::string Cipher::ColumnarTranspositionCipherEncoder(const std::string& input, const std::string& key)
{
	int keyLength = key.length();
	std::string encodedText;
	std::string* columns = new std::string[keyLength];

	for (int i = 0; i < input.length(); i++)
	{
		columns[i % keyLength] += input[i];
	}

	for (int i = 0; i < key.length(); i++)
	{
		int columnKeyStepIndex = key[i] - '0';
		encodedText += columns[columnKeyStepIndex];
	}

	delete[] columns;
	return encodedText;
}

std::string Cipher::ColumnarTranspositionCipherDecoder(const std::string& input, const std::string& key)
{
	return std::string();
}
