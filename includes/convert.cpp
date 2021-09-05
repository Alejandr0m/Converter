#include "convert.h"

//Converts the inputted string into an integer
int Decimal(string num)
{
    return stoi(num);
}

//Changes the char to its integer value
int toDigit(char num)
{
    switch (toupper(num))
    {
    case '0':
        return 0;
    case '1':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'A':
        return 10;
    case 'B':
        return 11;
    case 'C':
        return 12;
    case 'D':
        return 13;
    case 'E':
        return 14;
    case 'F':
        return 15;
    }
}

//Leading function, converts any base to decimal format
int OtherToDec(string num, int base)
{
    int i = 0, sumInDec = 0;
    string originalNum = num;
    if (num[0] == '-')
        num.erase(0, 1);
    int l = num.length();
    while (i < l)
    {
        int character = toDigit(num[l - i - 1]);
        sumInDec += character * pow(base, i);
        i++;
    }
    if (originalNum[0] == '-')
    {
        cout << -1 * sumInDec << endl;
        return -1 * sumInDec;
    }
    else
    {
        cout << sumInDec << endl;
        return sumInDec;
    }
}

//Leading function, converts decimal to any base format
int DecToOther(int num, int base)
{
    string otherNum[32];
    int i = 0, otherInt = 0, originalNum = num;
    while (num != 0)
    {
        if (abs(num) % base >= 10)
        {
            otherNum[i] = 'A' + abs(num) % base - 10;
        }
        else
            otherNum[i] = to_string(abs(num) % base);
        i++;
        num /= base;
    }
    if (originalNum < 0)
        cout << "-";
    for (int k = i - 1; k >= 0; k--)
    {
        cout << otherNum[k];
        if (base == 2)
        {
            otherInt += pow(10, k) * stoi(otherNum[k]);
        }
    }
    cout << endl;
    return otherInt;
}

//Converts our binary number to its counterpart twosCompliment
string twosConv(string binNum)
{
    int zero = 8 - binNum.length();
    string binStr = "";

    for (int i = 0; i < zero; i++) //This will fill the string to fit the size of 8 bits w/ 0's
        binStr += '0';
    binStr += binNum;

    for (int i = 0; i < binStr.length(); i++) //Flips the 1's and 0's
    {
        if (binStr[i] == '1')
        {
            binStr[i] = '0';
            continue;
        }
        if (binStr[i] == '0')
        {
            binStr[i] = '1';
            continue;
        }
    }

    for (int i = binStr.length() - 1; i > 0; i--) //Adds 1 to the complememnt
    {
        if (i == (binStr.length() - 1))
        {
            binStr[i]++;
        }
        if (binStr[i] == '2')
        {
            binStr[i] = '0';
            binStr[i - 1]++;
        }
    }

    return binStr;
}