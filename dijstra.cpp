#include <iostream>
#include <vector>
#include <queue>
#include <limits>

using namespace std;

const int INF = numeric_limits<int>::max();

// Estructura para representar una arista
struct Edge {
    int destination;
    int weight;
};

// Función para encontrar la ruta más corta utilizando el algoritmo de Dijkstra
void Dijkstra(vector<vector<Edge>>& graph, int start, vector<int>& distances) {
    int n = graph.size();
    distances.assign(n, INF); // Inicializar todas las distancias como infinito
    distances[start] = 0; // La distancia al nodo de inicio es 0

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(make_pair(0, start));

    while (!pq.empty()) {
        int u = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        // Si ya se encontró una distancia más corta para este nodo, ignorarlo
        if (dist > distances[u]) {
            continue;
        }

        // Iterar sobre los vecinos de u
        for (const auto& edge : graph[u]) {
            int v = edge.destination;
            int weight = edge.weight;

            // Actualizar la distancia si encontramos un camino más corto
            if (distances[u] + weight < distances[v]) {
                distances[v] = distances[u] + weight;
                pq.push(make_pair(distances[v], v));
            }
        }
    }
}

int main() {
    int n, m; // n = número de nodos, m = número de aristas
    int start; // Nodo de inicio

    cout << "Ingrese el número de nodos: ";
    cin >> n;

    cout << "Ingrese el número de aristas: ";
    cin >> m;

    vector<vector<Edge>> graph(n);

    cout << "Ingrese las aristas en el formato 'nodo_origen nodo_destino peso':\n";
    for (int i = 0; i < m; i++) {
        int u, v, weight;
        cin >> u >> v >> weight;

        graph[u].push_back({v, weight});
    }

    cout << "Ingrese el nodo de inicio: ";
    cin >> start;

    vector<int> distances;
    Dijkstra(graph, start, distances);

    cout << "Distancias más cortas desde el nodo " << start << ":\n";
    for (int i = 0; i < n; i++) {
        cout << "Nodo " << i << ": ";
        if (distances[i] == INF)
            cout << "No alcanzable\n";
        else
            cout << distances[i] << "\n";
    }

    return 0;
}
