/**
 * @file cesar_code.cc
 * @author Mateusz Bernart (mateuszbernart@gmail.com)
 * @brief de/encryption - cesar code
 * @version 0.1
 * @date 2021-06-08
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#include <iostream>

std::string cesarEncryption(std::string toEncrypt, uint step = 3)
{
    std::string encrypted;
    for (char i : toEncrypt)
        if (i + step > 'z')
            encrypted += (i + step - 26);
        else
            encrypted += (i + step);
    return encrypted;
}

std::string cesarDecryption(std::string toEncrypt, uint step = 3)
{
    std::string encrypted;
    for (char i : toEncrypt)
        if (i - step < 'a')
            encrypted += (i - step + 26);
        else
            encrypted += (i - step);
    return encrypted;
}

int main(void)
{
    auto koza = cesarEncryption("koza");
    std::cout << cesarDecryption(koza);
    return 0;
}