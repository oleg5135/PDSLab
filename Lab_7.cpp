#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#ifdef _WIN32
#include <windows.h>
#endif

using namespace std;

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
#endif

    const string path = "C:\\Users\\OlegS\\source\\repos\\Lab_3\\Lab_7\\x64\\Debug\\graph.txt";
    ifstream fin(path);
    if (!fin) {
        cout << "Не вдалося вiдкрити файл: " << path << "\n";
        return 0;
    }

    int n, m, t;
    if (!(fin >> n >> m >> t)) {
        cout << "Помилка формату файлу.\n";
        return 0;
    }

    bool directed = (t == 1);
    vector<int> indeg(n, 0), outdeg(n, 0);

    for (int i = 0; i < m; ++i) {
        int u, v;
        if (!(fin >> u >> v)) {
            cout << "Помилка у рядку ребра.\n";
            return 0;
        }
        if (u < 1 || u > n || v < 1 || v > n) {
            cout << "Номер вершини поза межами.\n";
            return 0;
        }
        if (directed) {
            outdeg[u - 1]++;
            indeg[v - 1]++;
        }
        else {
            outdeg[u - 1]++;
            outdeg[v - 1]++;
        }
    }

    vector<int> degree(n, 0);
    for (int i = 0; i < n; ++i) {
        if (directed) degree[i] = indeg[i] + outdeg[i];
        else {
            degree[i] = outdeg[i];
            indeg[i] = outdeg[i];
        }
    }

    cout << "Ступенi вершин:\n";
    for (int i = 0; i < n; ++i) {
        cout << "v" << (i + 1)
            << ": in=" << indeg[i]
            << ", out=" << outdeg[i]
            << ", deg=" << degree[i] << "\n";
    }

    bool regular = true;
    if (n > 0) {
        if (directed) {
            int in0 = indeg[0], out0 = outdeg[0];
            for (int i = 1; i < n; ++i) {
                if (indeg[i] != in0 || outdeg[i] != out0) {
                    regular = false;
                    break;
                }
            }
            if (regular) {
                cout << "Граф однорiдний: in=" << in0 << ", out=" << out0 << "\n";
            }
            else {
                cout << "Граф не однорiдний.\n";
            }
        }
        else {
            int d0 = degree[0];
            for (int i = 1; i < n; ++i) {
                if (degree[i] != d0) {
                    regular = false;
                    break;
                }
            }
            if (regular) {
                cout << "Граф однорiдний: d=" << d0 << "\n";
            }
            else {
                cout << "Граф не однорiдний.\n";
            }
        }
    }

    vector<int> isolated, pendant;
    for (int i = 0; i < n; ++i) {
        if (degree[i] == 0) isolated.push_back(i + 1);
        if (degree[i] == 1) pendant.push_back(i + 1);
    }

    cout << "Iзольованi вершини: ";
    if (isolated.empty()) cout << "немає";
    else {
        for (size_t i = 0; i < isolated.size(); ++i) {
            cout << isolated[i] << (i + 1 < isolated.size() ? ", " : "");
        }
    }
    cout << "\n";

    cout << "Висячi вершини: ";
    if (pendant.empty()) cout << "немає";
    else {
        for (size_t i = 0; i < pendant.size(); ++i) {
            cout << pendant[i] << (i + 1 < pendant.size() ? ", " : "");
        }
    }
    cout << "\n";

    return 0;
}
