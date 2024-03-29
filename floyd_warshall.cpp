#include <bits/stdc++.h>

using namespace std;

const int inf = 1e9;

int dis[405][405], p[405][405];

// Inicialización de las matrices
void init(int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            p[i][j] = i;
            if (i == j)
                continue;
            dis[i][j] = inf;
        }
    }
}

// Función para imprimir el camino más corto entre dos vértices
void printPath(int i, int j)
{
    if (i != j)
    {
        printPath(i, p[i][j]);
        cout << j << " ";
    }
}

int main()
{
    int n, m, u, v, w;
    cin >> n >> m;

    init(n); // Inicialización de las matrices

    // Lectura de las aristas del grafo
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        dis[u][v] = min(dis[u][v], w); // Actualización de las distancias entre los vértices
    }

    // Algoritmo de Floyd-Warshall
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dis[i][j] > dis[i][k] + dis[k][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j]; // Actualización de la distancia más corta
                    p[i][j] = p[k][j];                 // Actualización del nodo intermedio en el camino más corto
                }
            }
        }
    }

    // Impresión de las distancias más cortas
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << dis[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;

    // Impresión del camino más corto entre los vértices 1 y 4
    printPath(1, 4);

    return 0;
}

/*
5 9
0 1 2
0 2 1
0 4 3
1 3 4
2 1 1
2 4 1
3 0 1
3 2 3
3 4 5
*/
