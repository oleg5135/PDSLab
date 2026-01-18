#include <cctype>
#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

bool parse_bool(const string &value) {
    string lower;
    lower.reserve(value.size());
    for (char ch : value) {
        lower.push_back(static_cast<char>(tolower(static_cast<unsigned char>(ch))));
    }
    return lower == "1" || lower == "true" || lower == "t" || lower == "yes" || lower == "y";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif
    string p_input;
    string q_input;

    cout << "Введіть p (True/False або 1/0): ";
    cin >> p_input;
    cout << "Введіть q (True/False або 1/0): ";
    cin >> q_input;

    bool p = parse_bool(p_input);
    bool q = parse_bool(q_input);

    bool conjunction = p && q;
    bool disjunction = p || q;
    bool xor_value = (p != q);
    bool impl_p_q = (!p) || q;
    bool impl_q_p = (!q) || p;
    bool equivalence = impl_p_q && impl_q_p;

    cout << "Результати:" << endl;
    cout << "p AND q: " << conjunction << endl;
    cout << "p OR q: " << disjunction << endl;
    cout << "p XOR q: " << xor_value << endl;
    cout << "p -> q: " << impl_p_q << endl;
    cout << "q -> p: " << impl_q_p << endl;
    cout << "p ~ q: " << equivalence << endl;

    return 0;
}
