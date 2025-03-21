#include <iostream>
using namespace std;

int main()
{
  int miMatriz[2][3] = {
                        {1,2,3},
                        {4,5,6},
                      };
  int fila, columna;
          
  miMatriz[1][1] = 7;
  
  cout << "Ingrese numero de fila: "<<endl;
  cin >> fila;
  
  cout << "Ingrese numero de columna: "<<endl;
  cin >> columna;
  
  miMatriz[fila-1][columna-1] = 9;
  
  /// RECORRE LAS FILAS
  for(int f=0; f<2; f++){
    /// RECORRE LAS COLUMNAS
    for(int c=0; c<3; c++){
      cout << miMatriz[f][c] << " ";    
    } 
    cout << endl;
  }
  return 0;
}
