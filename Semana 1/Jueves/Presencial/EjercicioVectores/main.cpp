#include <iostream>

using namespace std;

int main()
{
    const int ART = 10;
    float importe;
    int idsucursal, idarticulo;

    /// Recaudación
    float uno[ART]={}, dos[ART]={}, tres[ART]={}, cuatro[ART]={};

    /// Carga de datos
    do{
        cout << "ID Articulo: ";
        cin >> idarticulo;
    }
    while(!(idarticulo >= 1 && idarticulo <= 10));  /// Validación de datos

    while (idarticulo != 0){
        cout << "ID Sucursal: ";
        cin >> idsucursal;

        cout << "IMPORTE: $ ";
        cin >> importe;

        cout << endl << "--------------------------" << endl;

        switch (idsucursal){
            case 1:
                uno[idarticulo-1] += importe;
            break;
            case 2:
                dos[idarticulo-1] += importe;
            break;
            case 3:
                tres[idarticulo-1] += importe;
            break;
            case 4:
                cuatro[idarticulo-1] += importe;
            break;
        }

        cout << "ID Articulo: ";
        cin >> idarticulo;
    }

    cout << endl << "Recaudacion final: " << endl;
    for(int i = 0; i < ART; i++){
        cout << "ID Articulo: " << i+1 << endl;
        cout << "----------------------------------" << endl;
        cout << "ID Sucursal: 1";
        cout << "\tTotal: $ " << uno[i] << endl;

        cout << "ID Sucursal: 2";
        cout << "\tTotal: $ " << dos[i] << endl;

        cout << "ID Sucursal: 3";
        cout << "\tTotal: $ " << tres[i] << endl;

        cout << "ID Sucursal: 4";
        cout << "\tTotal: $ " << cuatro[i] << endl;
        cout << "----------------------------------" << endl;


    }


    return 0;
}
