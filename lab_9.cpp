#include <iostream>
#include <fstream>
using namespace std;

const int MAX_N = 100;

int adj[MAX_N][MAX_N];
bool visited[MAX_N];
int bfsNumber[MAX_N];
int bfsCounter = 0;
int n, m;

int Queue[MAX_N];
int head = 0;
int tail = 0;

void enqueue(int v)
{
    Queue[tail++] = v;
}

int dequeue()
{
    return Queue[head++];
}

bool isQueueEmpty()
{
    return head == tail;
}

void printQueue()
{
    cout << "[ ";
    for (int i = head; i < tail; i++)
    {
        if (!visited[Queue[i]])
            cout << Queue[i] + 1 << " ";
    }
    cout << "]";
}

void BFS(int start)
{
    enqueue(start);

    while (!isQueueEmpty())
    {
        int v = dequeue();

        if (!visited[v])
        {
            visited[v] = true;
            bfsNumber[v] = ++bfsCounter;

            cout << "Current: " << v + 1
                << " | BFS-number: " << bfsNumber[v]
                << " | Queue: ";
            printQueue();
            cout << "\n";

            for (int u = 0; u < n; u++)
            {
                if (adj[v][u] && !visited[u])
                    enqueue(u);
            }
        }
    }
}

int main()
{
    // ?? ÔÀÉË ÂÆÅ ÇÀÄÀÍÈÉ
    ifstream fin("F:/graph.txt");


    if (!fin.is_open())
    {
        cerr << "Error: cannot open file!\n";
        return 1;
    }

    fin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        bfsNumber[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        fin >> u >> v;
        adj[u - 1][v - 1] = 1;
    }

    fin.close();

    int start = 1; // ñòàğòîâà âåğøèíà
    cout << "\nBFS traversal protocol:\n";
    BFS(start - 1);

    return 0;
}
