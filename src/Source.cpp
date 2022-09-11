#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>

using namespace std;


union digits_union
{
    int int_num;
    long double double_num;
    unsigned char char_represent[sizeof(long double)];
};


template<typename Type>
Type show_bits(Type num, digits_union bit){



    for (int j = sizeof(num) - 1; j >= 0; j--)
    {
        cout << " ";
        for (int i = 128; i; i >>= 1)
        {
            if (bit.char_represent[j] & i)
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
    }

    cout << endl;
    return 0;
}


int main()
{
    setlocale(LC_ALL, "Russian");
    cout << "Lab Noskov Evgeny.\nTo enter the var type, use \"int\" or \"long double\" " << endl<<endl;

    digits_union number;
    string answer;
    string a;


    while (true) {

        cout << "enter the type of var: ";

        getline(cin, answer);

        if (answer == "int") {
            cout << "enter a number: ";
            cin >> number.int_num;

            show_bits(number.int_num, number);
            getline(cin, answer);
            continue;
        }

        if (answer == "long double") {
            cout << "enter a number: ";
            cin >> number.double_num;

            show_bits(number.double_num, number);
            getline(cin, answer);
            continue;
        }
        
        
        cout << "u entered wrong argument. Try again "<< endl;
    }





    return 0;
}