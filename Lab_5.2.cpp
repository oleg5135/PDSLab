#include <iostream>
#include <vector>
#include <algorithm>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

bool contains(const vector<int>& arr, int value) {
    for (int x : arr) {
        if (x == value) return true;
    }
    return false;
}

void print_bits(const vector<int>& bits) {
    for (int b : bits) cout << b;
    cout << "\n";
}

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    int n;
    cout << "¬ведiть n: ";
    cin >> n;

    vector<int> U(n);
    cout << "¬ведiть елементи U: ";
    for (int i = 0; i < n; ++i) cin >> U[i];

    int ka;
    cout << "¬ведiть kA: ";
    cin >> ka;
    vector<int> A(ka);
    cout << "¬ведiть елементи A: ";
    for (int i = 0; i < ka; ++i) cin >> A[i];

    int kb;
    cout << "¬ведiть kB: ";
    cin >> kb;
    vector<int> B(kb);
    cout << "¬ведiть елементи B: ";
    for (int i = 0; i < kb; ++i) cin >> B[i];

    sort(U.begin(), U.end());

    vector<int> Abit(n, 0), Bbit(n, 0);
    for (int i = 0; i < n; ++i) {
        Abit[i] = contains(A, U[i]) ? 1 : 0;
        Bbit[i] = contains(B, U[i]) ? 1 : 0;
    }

    vector<int> notA(n), AandB(n), AorB(n), AminusB(n), AxorB(n);
    for (int i = 0; i < n; ++i) {
        notA[i] = 1 - Abit[i];
        AandB[i] = (Abit[i] == 1 && Bbit[i] == 1) ? 1 : 0;
        AorB[i] = (Abit[i] == 1 || Bbit[i] == 1) ? 1 : 0;
        AminusB[i] = (Abit[i] == 1 && Bbit[i] == 0) ? 1 : 0;
        AxorB[i] = (Abit[i] != Bbit[i]) ? 1 : 0;
    }

    cout << "\nЅiтовi р€дки:\n";
    cout << "A:     "; print_bits(Abit);
    cout << "B:     "; print_bits(Bbit);
    cout << "not A: "; print_bits(notA);
    cout << "A ? B: "; print_bits(AandB);
    cout << "A ? B: "; print_bits(AorB);
    cout << "A \\ B: "; print_bits(AminusB);
    cout << "A XOR B: "; print_bits(AxorB);

    return 0;
}
