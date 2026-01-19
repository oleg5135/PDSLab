#include <fstream>
#include <iostream>
using namespace std;

// Build adjacency matrix
void buildAdjacencyMatrix(int** adjMatrix, int* edgesU, int* edgesV, int m) {
    for (int i = 0; i < m; i++) {
        int u = edgesU[i] - 1;
        int v = edgesV[i] - 1;
        adjMatrix[u][v] = 1;
    }
}

// Build incidence matrix
void buildIncidenceMatrix(int** incMatrix, int* edgesU, int* edgesV, int n, int m) {
    for (int i = 0; i < m; i++) {
        int u = edgesU[i] - 1;
        int v = edgesV[i] - 1;
        incMatrix[u][i] = -1; // leaves vertex u
        incMatrix[v][i] = 1;  // enters vertex v
    }
}

// Print adjacency matrix
void printAdjacencyMatrix(ofstream& fout, int** adjMatrix, int n) {
    cout << "\nAdjacency Matrix:\n";
    fout << "Adjacency Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << adjMatrix[i][j] << " ";
            fout << adjMatrix[i][j] << " ";
        }
        cout << "\n";
        fout << "\n";
    }
}

// Print incidence matrix
void printIncidenceMatrix(ofstream& fout, int** incMatrix, int n, int m) {
    cout << "\nIncidence Matrix:\n";
    fout << "\nIncidence Matrix:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << incMatrix[i][j] << " ";
            fout << incMatrix[i][j] << " ";
        }
        cout << "\n";
        fout << "\n";
    }
}

int main() {
    int n, m;
    string inputFile, outputFile;

    cout << "Enter the input file name: ";
    cin >> inputFile;

    ifstream fin(inputFile);
    if (!fin.is_open()) {
        cerr << "Error: cannot open input file!\n";
        return 1;
    }

    fin >> n >> m;
    int* edgesU = new int[m];
    int* edgesV = new int[m];
    for (int i = 0; i < m; i++)
        fin >> edgesU[i] >> edgesV[i];
    fin.close();

    // Allocate matrices on heap
    int** adjMatrix = new int* [n];
    int** incMatrix = new int* [n];
    for (int i = 0; i < n; i++) {
        adjMatrix[i] = new int[n]();
        incMatrix[i] = new int[m]();
    }

    buildAdjacencyMatrix(adjMatrix, edgesU, edgesV, m);
    buildIncidenceMatrix(incMatrix, edgesU, edgesV, n, m);

    cout << "Enter the output file name: ";
    cin >> outputFile;

    ofstream fout(outputFile);
    if (!fout.is_open()) {
        cerr << "Error: cannot create output file!\n";
        return 1;
    }

    printAdjacencyMatrix(fout, adjMatrix, n);
    printIncidenceMatrix(fout, incMatrix, n, m);

    fout.close();
    cout << "\nResults written to file: " << outputFile << endl;

    // Free memory
    delete[] edgesU;
    delete[] edgesV;
    for (int i = 0; i < n; i++) {
        delete[] adjMatrix[i];
        delete[] incMatrix[i];
    }
    delete[] adjMatrix;
    delete[] incMatrix;

    return 0;
}