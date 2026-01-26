#include <iostream>
#include <sstream>
using namespace std;

const int MAX_N = 100;

int adj[MAX_N][MAX_N];
bool visited[MAX_N];
int dfsNumber[MAX_N];
int dfsCounter = 0;
int n, m;

int Stack[MAX_N];
int topIndex = -1;

void push(int v)
{
    Stack[++topIndex] = v;
}

int pop()
{
    return Stack[topIndex--];
}

bool isEmpty()
{
    return topIndex == -1;
}

void printStack()
{
    cout << "[ ";
    for (int i = 0; i <= topIndex; i++)
        cout << Stack[i] + 1 << " ";
    cout << "]";
}

void DFS(int start)
{
    push(start);

    while (!isEmpty())
    {
        int v = pop();

        if (!visited[v])
        {
            visited[v] = true;
            dfsNumber[v] = ++dfsCounter;

            cout << "Current: " << v + 1
                << " | DFS-number: " << dfsNumber[v]
                << " | Stack: ";
            printStack();
            cout << "\n";

            for (int u = n - 1; u >= 0; u--)
            {
                if (adj[v][u] && !visited[u])
                    push(u);
            }
        }
    }
}

int main()
{
    // ======= ВШИТИЙ ГРАФ =======
    stringstream fin;
    fin <<
        "5 6\n"
        "1 2\n"
        "1 3\n"
        "2 4\n"
        "2 5\n"
        "3 5\n"
        "4 1\n";
    // ==========================

    fin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
        dfsNumber[i] = 0;
        for (int j = 0; j < n; j++)
            adj[i][j] = 0;
    }

    for (int i = 0; i < m; i++)
    {
        int u, v;
        fin >> u >> v;
        adj[u - 1][v - 1] = 1;   // орієнтований граф
    }

    int start = 1;  // стартова вершина
    cout << "DFS traversal protocol:\n";
    DFS(start - 1);

    return 0;
}
