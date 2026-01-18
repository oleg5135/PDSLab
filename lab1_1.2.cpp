#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

char bit_or(char a, char b) {
    if (a == '1' || b == '1') {
        return '1';
    }
    return '0';
}

char bit_and(char a, char b) {
    if (a == '1' && b == '1') {
        return '1';
    }
    return '0';
}

char bit_xor(char a, char b) {
    if (a != b) {
        return '1';
    }
    return '0';
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif
    const string a = "11001110";
    const string b = "01100111";

    cout << "Завдання 2" << endl;
    cout << "Вхідні дані (варіант 12): a = " << a << ", b = " << b << endl;

    string x = "";
    string y = "";
    string z = "";

    for (size_t i = 0; i < a.size(); ++i) {
        char c = bit_or(a[i], b[i]);
        x = x + c;

        c = bit_and(a[i], b[i]);
        y = y + c;

        c = bit_xor(a[i], b[i]);
        z = z + c;
    }

    cout << "OR  = " << x << endl;
    cout << "AND = " << y << endl;
    cout << "XOR = " << z << endl;

    return 0;
}
