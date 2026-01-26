#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_N = 100;
const int INF = 0;   // 0 означає, що ребра немає

int W[MAX_N][MAX_N];
int n, m;

int main()
{
    // ===== ВХІДНИЙ ФАЙЛ (ШЛЯХ ВПИСАНИЙ) =====
    ifstream fin("F:/graph.txt");

    if (!fin.is_open())
    {
        cout << "Error: cannot open input file!\n";
        return 1;
    }

    fin >> n >> m;

    // Ініціалізація матриці ваг
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            W[i][j] = INF;

    // Зчитування списку ребер
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        fin >> v >> u >> w;
        W[v - 1][u - 1] = w;   // орієнтований граф
    }

    fin.close();

    // ===== ВИВІД НА ЕКРАН =====
    cout << "Weight matrix:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << setw(4) << W[i][j];
        cout << "\n";
    }

    // ===== ВИВІД У ФАЙЛ (ШЛЯХ ВПИСАНИЙ) =====
    ofstream fout("F:/matrix.txt");

    if (!fout.is_open())
    {
        cout << "Error: cannot open output file!\n";
        return 1;
    }

    fout << "Weight matrix:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            fout << setw(4) << W[i][j];
        fout << "\n";
    }

    fout.close();

    cout << "\nMatrix successfully saved to F:/matrix.txt\n";

    return 0;
}
