#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

bool implication(bool a, bool b) {
    return (!a) || b;
}

bool equivalence(bool a, bool b) {
    return a == b;
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif
    cout << "Функція: (p ~ q) -> (p ∧ r)\n";
    cout << "\nТаблиця істинності:\n";
    cout << "p q r | f\n";
    cout << "------------\n";

    for (int p = 0; p <= 1; ++p) {
        for (int q = 0; q <= 1; ++q) {
            for (int r = 0; r <= 1; ++r) {
                bool pb = p == 1;
                bool qb = q == 1;
                bool rb = r == 1;
                bool left = equivalence(pb, qb);
                bool right = pb && rb;
                bool f = implication(left, right);
                cout << p << " " << q << " " << r << " | " << (f ? 1 : 0) << "\n";
            }
        }
    }

    return 0;
}
