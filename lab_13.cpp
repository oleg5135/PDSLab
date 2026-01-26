#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 100;

int adj[MAX_N][MAX_N];
int color[MAX_N];
int n, m;

void clearGraph()
{
    for (int i = 0; i < n; i++)
    {
        color[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }
}

bool canColor(int v, int c)
{
    for (int u = 0; u < n; u++)
    {
        if (adj[v][u] == 1 && color[u] == c)
            return false;
        if (adj[u][v] == 1 && color[u] == c)
            return false;
    }
    return true;
}

int greedyColoring()
{
    int maxColor = 0;

    for (int v = 0; v < n; v++)
    {
        int c = 1;
        while (!canColor(v, c))
            c++;

        color[v] = c;
        if (c > maxColor)
            maxColor = c;
    }

    return maxColor;
}

int main()
{
    // ===== ВХІДНИЙ ФАЙЛ (ШЛЯХ ВПИСАНИЙ) =====
    ifstream fin("F:/graph.txt");

    if (!fin.is_open())
    {
        cerr << "Error: cannot open file!\n";
        return 1;
    }

    fin >> n >> m;
    clearGraph();

    for (int i = 0; i < m; i++)
    {
        int u, v;
        fin >> u >> v;
        u--; v--;

        // фарбування — неорієнтований граф
        adj[u][v] = 1;
        adj[v][u] = 1;
    }

    fin.close();

    int minColors = greedyColoring();

    cout << "\nMinimum number of colors: " << minColors << "\n\n";

    for (int i = 0; i < n; i++)
    {
        cout << "Vertex " << (i + 1)
            << " -> Color " << color[i] << "\n";
    }

    return 0;
}
