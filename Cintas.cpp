#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

double PromAcceso(std::vector<int>& archivos) {
    sort(archivos.begin(), archivos.end());

    int n = archivos.size();
    int tiempoTotal = 0;
    int tiempoAcumulado = 0;

    for (int i = 0; i < n; ++i) {
        tiempoAcumulado += archivos[i];
        tiempoTotal += tiempoAcumulado;
    }

    return static_cast<double>(tiempoTotal) / n;
}

int main() {
    vector<int> archivos = { 5, 10, 3 };

    double tiempoPromedio = PromAcceso(archivos);

    cout << "Tiempo promedio de acceso: " << tiempoPromedio << std::endl;

    return 0;
}
