#include <iostream>
#include <fstream>
#include <vector>
#include <limits>
#include <iomanip>

using namespace std;

const int INF = 1000000000;

struct Edge {
    int to;
    int weight;
};

int n, m;
vector<vector<Edge>> graph;
vector<int> dist;
vector<int> parent;

bool hasNegativeEdge = false;

void dijkstra(int start)
{
    dist.assign(n, INF);
    parent.assign(n, -1);
    vector<bool> used(n, false);

    dist[start] = 0;

    for (int i = 0; i < n; i++)
    {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!used[j] && (v == -1 || dist[j] < dist[v]))
                v = j;

        if (dist[v] == INF)
            break;

        used[v] = true;

        for (auto e : graph[v])
        {
            if (dist[e.to] > dist[v] + e.weight)
            {
                dist[e.to] = dist[v] + e.weight;
                parent[e.to] = v;
            }
        }
    }
}

void printPath(int start, int end)
{
    if (dist[end] == INF)
    {
        cout << "No path\n";
        return;
    }

    vector<int> path;
    for (int v = end; v != -1; v = parent[v])
        path.push_back(v);

    for (int i = path.size() - 1; i >= 0; i--)
    {
        cout << path[i] + 1;
        if (i) cout << " -> ";
    }
    cout << endl;
}

int main()
{
    // ===== Ç×ÈÒÓÂÀÍÍß ÃÐÀÔÓ =====
    ifstream fin("F:/graph.txt");

    if (!fin.is_open())
    {
        cout << "Error: cannot open input file\n";
        return 1;
    }

    fin >> n >> m;
    graph.resize(n);

    for (int i = 0; i < m; i++)
    {
        int v, u, w;
        fin >> v >> u >> w;
        graph[v - 1].push_back({ u - 1, w });
        if (w < 0) hasNegativeEdge = true;
    }

    fin.close();

    // ===== ÏÅÐÅÂ²ÐÊÀ Â²Ä’ªÌÍÈÕ ÂÀÃ =====
    if (hasNegativeEdge)
    {
        cout << "Graph contains negative edge weights.\n";
        cout << "Dijkstra algorithm cannot be applied.\n";
        return 0;
    }

    // ===== ×ÀÑÒÈÍÀ 1: Ì²Æ ÄÂÎÌÀ ÂÅÐØÈÍÀÌÈ =====
    int start, end;
    cout << "Enter start vertex: ";
    cin >> start;
    cout << "Enter end vertex: ";
    cin >> end;

    start--; end--;

    dijkstra(start);

    cout << "\nShortest distance: ";
    if (dist[end] == INF)
        cout << "INF\n";
    else
        cout << dist[end] << endl;

    cout << "Shortest path: ";
    printPath(start, end);

    // ===== ×ÀÑÒÈÍÀ 2: ÄÎ ÂÑ²Õ ÂÅÐØÈÍ =====
    cout << "\nShortest distances from vertex " << start + 1 << ":\n";
    for (int i = 0; i < n; i++)
    {
        cout << "To " << i + 1 << ": ";
        if (dist[i] == INF)
            cout << "INF\n";
        else
            cout << dist[i] << endl;
    }

    return 0;
}
