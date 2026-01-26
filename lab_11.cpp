#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX_N = 100;
const int INF = 1000000000;

int dist[MAX_N][MAX_N];
int nextV[MAX_N][MAX_N];
int n, m;

void printPath(int u, int v)
{
    if (nextV[u][v] == -1)
    {
        cout << "No path\n";
        return;
    }

    cout << u + 1;
    while (u != v)
    {
        u = nextV[u][v];
        cout << " -> " << u + 1;
    }
    cout << endl;
}

int main()
{
    // ===== ÂÕ²ÄÍÈÉ ÔÀÉË =====
    ifstream fin("F:/graph.txt");

    if (!fin.is_open())
    {
        cout << "Error: cannot open input file!\n";
        return 1;
    }

    fin >> n >> m;

    // ²í³ö³àë³çàö³ÿ
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            dist[i][j] = (i == j) ? 0 : INF;
            nextV[i][j] = -1;
        }
    }

    // Ç÷èòóâàííÿ ğåáåğ
    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        fin >> v >> u >> w;
        dist[v - 1][u - 1] = w;
        nextV[v - 1][u - 1] = u - 1;
    }

    fin.close();

    // ===== ÀËÃÎĞÈÒÌ ÔËÎÉÄÀ–ÓÎĞØÅËËÀ =====
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (dist[i][k] < INF && dist[k][j] < INF &&
                    dist[i][j] > dist[i][k] + dist[k][j])
                {
                    dist[i][j] = dist[i][k] + dist[k][j];
                    nextV[i][j] = nextV[i][k];
                }

    // ===== ÂÈÂ²Ä ÌÀÒĞÈÖ² Â²ÄÑÒÀÍÅÉ =====
    cout << "Distance matrix:\n\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (dist[i][j] == INF)
                cout << setw(6) << "INF";
            else
                cout << setw(6) << dist[i][j];
        }
        cout << endl;
    }

    // ===== ÇÀÏÈÒ ÊÎĞÈÑÒÓÂÀ×À =====
    int start, end;
    cout << "\nEnter start vertex: ";
    cin >> start;
    cout << "Enter end vertex: ";
    cin >> end;

    start--;
    end--;

    cout << "\nShortest distance: ";
    if (dist[start][end] == INF)
        cout << "INF\n";
    else
        cout << dist[start][end] << endl;

    cout << "Shortest path: ";
    printPath(start, end);

    return 0;
}
