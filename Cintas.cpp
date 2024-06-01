#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double PromAcceso(vector<int>& archivos, vector<int>& orden) {
    
    vector<int> indices(archivos.size());

    for (int i{ 0 }; i < archivos.size(); i++) {
        indices[i] = i;
    }

    sort(indices.begin(), indices.end(), [&](int a, int b) {
        return archivos[a] < archivos[b];
        });

    int n = archivos.size();
    int tiempoTotal = 0;
    int tiempoAcumulado = 0;

    for (int i = 0; i < n; ++i) {
        tiempoAcumulado += archivos[indices[i]];
        tiempoTotal += tiempoAcumulado;
        orden.push_back(indices[i] + 1);
    }

    return static_cast<double>(tiempoTotal) / n;
}

int main() {
    vector<int> archivos = { 5, 10, 3 };
    vector<int> orden;
    double tiempoPromedio = PromAcceso(archivos,orden);

    cout << "Tiempo promedio de acceso: " << tiempoPromedio << endl;
    cout << "El orden de las tareas es: " ;
    for (int i = 0; i < archivos.size(); i++) {
        cout << orden[i] << " - ";
    }

    return 0;
}
