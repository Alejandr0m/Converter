#ifndef CONVERT_H
#define CONVERT_H

#include <iostream>
#include <cmath>
using namespace std;

//Converts the inputted string into an integer
int Decimal(string num);

//Changes the char to its integer value
int toDigit(char num);

//Leading function, converts any base to decimal format
int OtherToDec (string num, int base);

//Leading function, converts decimal to any base format
int DecToOther(int num, int base);

//Converts our binary number to its counterpart twosCompliment
string twosConv(string decNum);

#endif