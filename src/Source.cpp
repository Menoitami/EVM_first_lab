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
    cout << "Лабораторная работа Носкова Евгения.\nДля ввода типа данных используйте \"int\" или \"long double\" " << endl;

    digits_union number;


    while (true) {

        string answer;

        cout << "enter the type of var: ";
        getline(cin, answer);

        if (answer == "int") {
            cout << "enter a number: ";
            cin >> number.int_num;

            show_bits(number.int_num, number);
        }

        if (answer == "long double") {
            cout << "enter a number: ";
            cin >> number.double_num;

            show_bits(number.double_num, number);
        }
        else cout << "u entered wrong argument. Try again " << endl;
    }





    return 0;
}