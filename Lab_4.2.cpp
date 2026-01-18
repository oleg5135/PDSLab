#include <iostream>
#include <vector>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void print_comb(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i + 1 == a.size() ? "\n" : " ");
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    int n, r;
    cout << "Введіть n: ";
    cin >> n;
    cout << "Введіть r: ";
    cin >> r;

    if (n <= 0 || r < 0 || r > n) {
        cout << "Помилка: має бути 0 <= r <= n.\n";
        return 0;
    }

    if (r == 0) {
        cout << "(порожнє сполучення)\n";
        return 0;
    }

    vector<int> a(r);
    for (int i = 0; i < r; ++i) {
        a[i] = i + 1;
    }

    print_comb(a);

    while (true) {
        int i = r - 1;
        while (i >= 0 && a[i] == n - r + i + 1) {
            --i;
        }
        if (i < 0) {
            break;
        }

        a[i]++;
        for (int j = i + 1; j < r; ++j) {
            a[j] = a[j - 1] + 1;
        }
        print_comb(a);
    }

    return 0;
}
