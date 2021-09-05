/*
 * Base Converter CS66 Lab 01.5
 * Group Leader: Alejandro Martinez
 * Group Member: Shaochong Jia
 */

#include <iostream>
#include <iomanip>
#include <cmath>
#include "includes/convert.h"

using namespace std;

int main()
{

    int choice, num, decNum, biNum;
    string numString;
    enum choices
    {
        DEC = 1,
        BIN,
        OCT,
        HEX
    };

    cout << "\n\n=================================================\n";
    cout << "Please choose the base you are starting with. \n0. Exit\n1. Decimal\n2. Binary\n3. Octal\n4. Hex\n";
    cin >> choice;

    while (choice != 0)
    {
        cout << "\nPlease enter the number you want to convert.\n";
        cin >> numString;

        cout << endl;
        switch (choice)
        {
        case DEC:
            decNum = Decimal(numString);
            cout << "Dec: " << decNum << endl;
            cout << "Binary is: \n";
            biNum = DecToOther(decNum, 2);
            cout << "Binary 2's complement is: \n";
            if (decNum > 0)
                cout << setw(8) << setfill('0') << biNum << endl;
            else
                cout << setw(8) << setfill('1') << twosConv(to_string(biNum)) << endl;
            cout << "Octal is: \n";
            DecToOther(decNum, 8);
            cout << "Hexadecimal is: \n";
            DecToOther(decNum, 16);
            break;
        case BIN:
            num = stoi(numString);
            cout << "Decimal is: \n";
            decNum = OtherToDec(numString, 2);

            cout << "Binary 2's complement is: \n";
            if (numString[0] == '0')
                cout << decNum << endl;
            else
            {
                string twos = twosConv(numString);
                cout << twos << " and in Decimal it is -> -";
                OtherToDec(twos, 2);
            }
            cout << "Octal is: \n";
            DecToOther(decNum, 8);
            cout << "Hexadecimal is: \n";
            DecToOther(decNum, 16);
            break;
        case OCT:
            cout << "Decimal is: \n";
            decNum = OtherToDec(numString, 8);
            cout << "Binary is: \n";
            biNum = DecToOther(decNum, 2);
            //cout << "Binary 2's complement is: \n";
            //cout << twosConv(biNum) << endl;
            cout << "Hexadecimal is: \n";
            DecToOther(decNum, 16);
            break;
        case HEX:
            cout << "Decimal is: \n";
            decNum = OtherToDec(numString, 16);
            cout << "Binary is: \n";
            biNum = DecToOther(decNum, 2);
            //cout << "Binary 2's complement is: \n";
            //cout << twosConv(to_string(biNum)) << endl;
            cout << "Octal is: \n";
            DecToOther(decNum, 8);
            break;
        }

        cout << "=================================================\n";
        cout << "\n\nPlease choose the base you are starting with. \n0. Exit\n1. Decimal\n2. Binary\n3. Octal\n4. Hex\n";
        cin >> choice;
    }

    return 0;
}
