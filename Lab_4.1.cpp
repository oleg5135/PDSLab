#include <iostream>
#include <vector>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

void print_perm(const vector<int>& a) {
    for (size_t i = 0; i < a.size(); ++i) {
        cout << a[i] << (i + 1 == a.size() ? "\n" : " ");
    }
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    int n;
    cout << "Введіть n: ";
    cin >> n;

    if (n <= 0) {
        cout << "Помилка: n має бути натуральним.\n";
        return 0;
    }

    vector<int> a(n);
    for (int i = 0; i < n; ++i) {
        a[i] = i + 1;
    }

    print_perm(a);

    while (true) {
        int j = n - 2;
        while (j >= 0 && a[j] >= a[j + 1]) {
            --j;
        }
        if (j < 0) {
            break;
        }

        int l = n - 1;
        while (a[l] <= a[j]) {
            --l;
        }
        swap(a[j], a[l]);
        reverse(a.begin() + j + 1, a.end());

        print_perm(a);
    }

    return 0;
}
