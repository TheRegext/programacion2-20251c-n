#include <iostream>
using namespace std;

/**
 Un comercio dispone de 10 art¡culos y desea llevar un
 control de las ventas realizadas en sus 4 sucursales.

 Cada venta se registra con los siguientes datos:
    N£mero de art¡culo (1 a 10)
    Sucursal (1 a 4)
    Monto de la venta

 El proceso de carga finaliza cuando se ingresa un n£mero de art¡culo igual a 0.

 Se pide:
  Calcular la recaudaci¢n total de cada art¡culo en cada sucursal
  
  4  x 10
  10 x 4
  
  Acumulador 
*/


void mostrarRecaudacion(float mat[][10], int filas = 4, int columnas = 10);

int main()
{
  int numeroArticulo, sucursal;
  float monto;
  
  float recaudaciones[4][10] = {};

  cout << "Ingrese numero de articulo: ";
  cin >> numeroArticulo;
  while(numeroArticulo != 0)
  {
    cout << "Ingrese numero de sucursal: ";
    cin >> sucursal;
    
    cout << "Ingrese monto de la venta: ";
    cin >> monto;
    
    recaudaciones[sucursal-1][numeroArticulo-1] += monto;

    cout << "Ingrese numero de articulo: ";
    cin >> numeroArticulo;
  }
  
  mostrarRecaudacion(recaudaciones);
  
  return 0;
}

void mostrarRecaudacion(float mat[][10], int filas, int columnas){

  for(int s=0;s<filas;s++){
    cout << "--- Sucursal #"<<s+1 << endl;
    
    for(int a=0; a<columnas; a++){
      cout << "Articulo #"  << a+1 << ": $" << mat[s][a] << endl;
    }
    cout << endl;
  }
}

