#include <iostream>
using namespace std;

void mostrarRecaudacion(float matriz[][4], const int ART, const int SUC);

void mostrarRecaudacion(float matriz[][4], const int ART, const int SUC){

    cout << endl << "Recaudacion final: " << endl;
    for(int i = 0; i < ART; i++){
        cout << "ID Articulo: " << i+1 << endl;
        cout << "----------------------------------" << endl;
        for(int j = 0; j < SUC; j++){
            cout << "ID Sucursal: " << j+1;
            cout << "\tTotal: $ " << matriz[i][j] << endl;
        }
        cout << endl;
    }

}

int main()
{
    const int ART = 10;
    const int SUC = 4;

    float importe;
    int idsucursal, idarticulo;

    /// Recaudación
    float recaudacion[ART][SUC] = {};

    /// Carga de datos
    do{
        cout << "ID Articulo: ";
        cin >> idarticulo;
    }
    while(!(idarticulo >= 0 && idarticulo <= 10));  /// Validación de datos

    while (idarticulo != 0){
        cout << "ID Sucursal: ";
        cin >> idsucursal;

        cout << "IMPORTE: $ ";
        cin >> importe;

        cout << endl << "--------------------------" << endl;

        recaudacion[idarticulo - 1][idsucursal - 1] += importe;

        cout << "ID Articulo: ";
        cin >> idarticulo;
    }

    mostrarRecaudacion(recaudacion, ART, SUC);

    return 0;
}
