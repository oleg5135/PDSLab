#include <iostream>
#include <vector>
#include <windows.h>
using namespace std;

bool isSafe(const vector<int>& queens, int row, int col) {
    for (int i = 0; i < row; ++i) {
        int qCol = queens[i];
        if (qCol == col || abs(qCol - col) == abs(i - row)) {
            return false;
        }
    }
    return true;
}

void solveNQueens(int n, int row, vector<int>& queens, vector<vector<int>>& solutions) {
    if (row == n) {
        solutions.push_back(queens);
        return;
    }
    for (int col = 0; col < n; ++col) {
        if (isSafe(queens, row, col)) {
            queens[row] = col;
            solveNQueens(n, row + 1, queens, solutions);
        }
    }
}

void printSolutions(const vector<vector<int>>& solutions, int n) {
    for (const auto& sol : solutions) {
        for (int row = 0; row < n; ++row) {
            for (int col = 0; col < n; ++col) {
                cout << (sol[row] == col ? "Q " : ". ");
            }
            cout << endl;
        }
        cout << endl;
    }
}

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    int n;
    cout << "¬вед≥ть n: ";
    cin >> n;

    vector<int> queens(n);
    vector<vector<int>> solutions;

    solveNQueens(n, 0, queens, solutions);

    cout << "«найдено " << solutions.size() << " р≥шень:\n\n";
    printSolutions(solutions, n);

    return 0;
}