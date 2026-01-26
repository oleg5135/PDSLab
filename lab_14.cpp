#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 100;

int adj[MAX_N][MAX_N];
int n, m;

int main()
{
    // ===== ВХІДНИЙ ФАЙЛ (ШЛЯХ ВЖЕ ВКАЗАНИЙ) =====
    ifstream fin("F:/graph3.txt");

    if (!fin.is_open())
    {
        cout << "Error: cannot open file!\n";
        return 1;
    }

    fin >> n >> m;

    // ініціалізація матриці
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;

    // зчитування ребер
    for (int i = 0; i < m; i++)
    {
        int v, u;
        fin >> v >> u;
        adj[v - 1][u - 1] = 1;
    }

    fin.close();

    // ===== ПЕРЕВІРКА РЕФЛЕКСИВНОСТІ =====
    bool reflexive = true;
    for (int i = 0; i < n; i++)
    {
        if (adj[i][i] == 0)
        {
            reflexive = false;
            break;
        }
    }

    // ===== ПЕРЕВІРКА СИМЕТРИЧНОСТІ =====
    bool symmetric = true;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (adj[i][j] != adj[j][i])
            {
                symmetric = false;
                break;
            }
        }
        if (!symmetric) break;
    }

    // ===== ВИВІД РЕЗУЛЬТАТУ =====
    if (reflexive)
        cout << "Relation is reflexive\n";
    else
        cout << "Relation is NOT reflexive\n";

    if (symmetric)
        cout << "Relation is symmetric\n";
    else
        cout << "Relation is NOT symmetric\n";

    return 0;
}
