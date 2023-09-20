#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <limits>

using namespace std;

double distancia(pair<int, int> ciudad1, pair<int, int> ciudad2) {
    int dx = ciudad1.first - ciudad2.first;
    int dy = ciudad1.second - ciudad2.second;
    return sqrt(dx * dx + dy * dy);
}

double calcularLongitudRuta(const vector<int>& ruta, const vector<pair<int, int>>& ciudades) {
    double longitud = 0.0;
    for (int i = 0; i < ruta.size(); i++) {
        int ciudadActual = ruta[i];
        int ciudadSiguiente = ruta[(i + 1) % ruta.size()];
        longitud += distancia(ciudades[ciudadActual], ciudades[ciudadSiguiente]);
    }
    return longitud;
}

int main() {
    int numCiudades;
    cin >> numCiudades;
    vector<pair<int, int>> ciudades(numCiudades);
    for (int i = 0; i < numCiudades; i++) {
        cin >> ciudades[i].first >> ciudades[i].second;
    }

    vector<int> ruta(numCiudades);
    iota(ruta.begin(), ruta.end(), 0);

    double mejorLongitud = numeric_limits<double>::max();
    vector<int> mejorRuta;

    do {
        double longitudActual = calcularLongitudRuta(ruta, ciudades);
        if (longitudActual < mejorLongitud) {
            mejorLongitud = longitudActual;
            mejorRuta = ruta;
        }
    } while (next_permutation(ruta.begin() + 1, ruta.end()));

    for (int ciudad : mejorRuta) {
        cout << ciudad + 1 << " ";
    }
    cout << "1" << endl;
    cout << mejorLongitud << endl;

    return 0;
}
