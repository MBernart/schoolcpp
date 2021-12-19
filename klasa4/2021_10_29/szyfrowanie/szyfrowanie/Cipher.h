#pragma once
#include <string>
#include <iostream>
class Cipher
{
public:
	std::string ColumnarTranspositionCipherEncoder(const std::string& input, const std::string& key);

	std::string ColumnarTranspositionCipherDecoder(const std::string& input, const std::string& key);

};

