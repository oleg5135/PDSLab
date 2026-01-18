#include <iostream>
#include <iomanip>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    // Завдання 1
    int n = 9;
    int r = 6;

    unsigned long long P1 = 1;
    for (int i = 1; i <= n; ++i) {
        P1 *= i;
    }

    unsigned long long P2 = 1;
    for (int i = 1; i <= n - r; ++i) {
        P2 *= i;
    }

    unsigned long long A = P1 / P2;

    cout << "Лабораторна 3, завдання 1 (варіант 12)\n";
    cout << "n = " << n << ", r = " << r << "\n";
    cout << "A(n, r) = " << A << "\n\n";

    // Завдання 2
    int variant = 12;
    int n2 = variant + 5; // 17

    vector<vector<unsigned long long>> F(n2 + 1, vector<unsigned long long>(n2 + 1, 0));
    vector<unsigned long long> B(n2 + 1, 0);

    for (int j = 1; j <= n2; ++j) {
        F[j][1] = 1;
        F[j][j] = 1;
    }

    for (int j = 3; j <= n2; ++j) {
        for (int k = 2; k <= j - 1; ++k) {
            F[j][k] = F[j - 1][k - 1] + k * F[j - 1][k];
        }
    }

    for (int j = 1; j <= n2; ++j) {
        unsigned long long sum = 0;
        for (int k = 1; k <= j; ++k) {
            sum += F[j][k];
        }
        B[j] = sum;
    }

    cout << "Лабораторна 3, завдання 2 (варіант 12)\n";
    cout << "n = " << n2 << "\n\n";

    cout << setw(4) << "n\\k";
    for (int k = 1; k <= n2; ++k) {
        cout << setw(10) << k;
    }
    cout << setw(12) << "B(n)" << "\n";

    for (int j = 1; j <= n2; ++j) {
        cout << setw(4) << j;
        for (int k = 1; k <= n2; ++k) {
            if (k <= j) {
                cout << setw(10) << F[j][k];
            }
            else {
                cout << setw(10) << "";
            }
        }
        cout << setw(12) << B[j] << "\n";
    }

    return 0;
}
