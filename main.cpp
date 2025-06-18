#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;
const int V = 6;

void floydWarshall(vector<vector<int>>& dist) {
    for (int k = 0; k < V; ++k)
        for (int i = 0; i < V; ++i)
            for (int j = 0; j < V; ++j)
                if (dist[i][k] < INF && dist[k][j] < INF)
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

void printDistanceMatrix(const vector<vector<int>>& dist) {
    char names[V] = {'A', 'B', 'C', 'D', 'E', 'F'};
    cout << "     ";
    for (int j = 0; j < V; ++j) cout << names[j] << "   ";
    cout << endl;

    for (int i = 0; i < V; ++i) {
        cout << names[i] << " | ";
        for (int j = 0; j < V; ++j) {
            if (dist[i][j] == INF)
                cout << "INF ";
            else
                cout << dist[i][j] << "   ";
        }
        cout << endl;
    }
}

int main() {
    vector<vector<int>> graph = {
        // A   B   C   D   E   F
        { 0, 10,  3, INF, INF, INF}, // A
        {INF, 0, INF,  2,  8,  INF}, // B
        {INF, INF, 0, INF,  3,  INF}, // C
        {INF, INF, INF, 0, INF, INF}, // D
        {INF, INF, INF,  4,  0,   1}, // E
        {INF, INF, INF,  4, INF,  0}  // F
    };

    floydWarshall(graph);
    printDistanceMatrix(graph);

    return 0;
}
