#include <bits/stdc++.h>
using namespace std;

const int N = 1e5; // Tamaño máximo del arreglo
int arr[N]; // Arreglo original
int segTree[4 * N]; // Segment Tree

// Construir el Segment Tree
void build(int node, int start, int end) {
    if (start == end) {
        segTree[node] = arr[start];
        return;
    }
    
    int mid = (start + end) / 2;
    build(2 * node, start, mid);
    build(2 * node + 1, mid + 1, end);
    
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

// Consulta de suma en un rango
int query(int node, int start, int end, int l, int r) {
    if (r < start || l > end)
        return 0;
    
    if (l <= start && r >= end)
        return segTree[node];
    
    int mid = (start + end) / 2;
    int leftSum = query(2 * node, start, mid, l, r);
    int rightSum = query(2 * node + 1, mid + 1, end, l, r);
    
    return leftSum + rightSum;
}

// Actualización de un elemento en el arreglo
void update(int node, int start, int end, int idx, int val) {
    if (start == end) {
        arr[idx] = val;
        segTree[node] = val;
        return;
    }
    
    int mid = (start + end) / 2;
    if (idx <= mid)
        update(2 * node, start, mid, idx, val);
    else
        update(2 * node + 1, mid + 1, end, idx, val);
    
    segTree[node] = segTree[2 * node] + segTree[2 * node + 1];
}

int main() {
    int n; // Tamaño del arreglo
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    
    build(1, 0, n - 1); // Construir el Segment Tree
    
    int q; // Número de consultas
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) { // Consulta de suma en rango
            int l, r;
            cin >> l >> r;
            cout << query(1, 0, n - 1, l, r) << endl;
        } else if (type == 2) { // Actualización de un elemento
            int idx, val;
            cin >> idx >> val;
            update(1, 0, n - 1, idx, val);
        }
    }
    
    return 0;
}
