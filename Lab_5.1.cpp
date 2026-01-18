#include <iostream>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    string A[3] = { "a", "b", "c" };
    string B[3] = { "x", "y", "z" };
    string C[2] = { "0", "1" };

    string D[18];
    int j = 0;

    // D = B x B x C
    for (int ib1 = 0; ib1 < 3; ++ib1) {
        for (int ib2 = 0; ib2 < 3; ++ib2) {
            for (int ic = 0; ic < 2; ++ic) {
                D[j] = B[ib1] + B[ib2] + C[ic];
                ++j;
            }
        }
    }

    cout << "Результат (елементи масиву D):" << endl;
    for (int i = 0; i < 18; ++i) {
        cout << "D[" << (i + 1) << "] = " << D[i] << endl;
    }

    return
