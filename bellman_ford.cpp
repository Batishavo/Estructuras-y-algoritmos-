#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int src, dest, weight;
};

// Función para imprimir el camino más corto desde el nodo de origen hasta el nodo dado
void printPath(vector<int>& parent, int node) {
    if (node == -1)
        return;
    printPath(parent, parent[node]);
    cout << node << " ";
}

// Función para ejecutar el algoritmo de Bellman-Ford
void bellmanFord(vector<Edge>& edges, int V, int E, int src) {
    vector<int> dist(V, INT_MAX);   // Distancias iniciales a todos los nodos como infinito
    dist[src] = 0;  // Distancia del nodo de origen a sí mismo es 0

    vector<int> parent(V, -1);  // Almacenar el nodo previo de cada nodo

    // Paso 2: Iteraciones
    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].src;
            int v = edges[j].dest;
            int weight = edges[j].weight;
            // Actualizar la distancia si se encuentra una ruta más corta
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
                dist[v] = dist[u] + weight;
                parent[v] = u;
            }
        }
    }

    // Paso 3: Detección de ciclos negativos
    for (int i = 0; i < E; i++) {
        int u = edges[i].src;
        int v = edges[i].dest;
        int weight = edges[i].weight;
        // Si se encuentra una ruta más corta, hay un ciclo negativo
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) {
            cout << "El grafo contiene un ciclo negativo" << endl;
            return;
        }
    }

    // Paso 4: Imprimir resultados
    cout << "Distancias más cortas desde el nodo de origen " << src << ":" << endl;
    for (int i = 0; i < V; i++) {
        cout << "Nodo " << i << ": Distancia = " << dist[i] << ", Camino más corto: ";
        printPath(parent, i);
        cout << endl;
    }
}

int main() {
    int V, E;
    cout << "Ingrese el número de nodos y aristas en el grafo: ";
    cin >> V >> E;

    vector<Edge> edges(E);
    cout << "Ingrese las aristas en el formato (fuente, destino, peso):" << endl;
    for (int i = 0; i < E; i++) {
        cin >> edges[i].src >> edges[i].dest >> edges[i].weight;
    }

    int src;
    cout << "Ingrese el nodo de origen: ";
    cin >> src;

    bellmanFord(edges, V, E, src);

    return 0;
}
