#include <iostream>
using namespace std;

/// parametros por omision
int pedirNumero(int valorMinimo = INT_MIN, string mensaje = "Ingrese Numero: ");

/// sobrecarga de funciones
int sumar(int n1, int n2);
int sumar(int n1, int n2, int n3);
float sumar(float n1, float n2);
int sumar(int vec[], int cant);

int main()
{
  int vec[5] = {5,3,6,9,10};
  
  cout << "Resultado suma: " << sumar(5,2) << endl;
  cout << "Resultado suma: " << sumar(10.5f , 3.37f) << endl;
  cout << "Resultado suma: " << sumar(10.0f , 3.37f) << endl;
  cout << "Resultado suma: " << sumar(10, 15, 20) << endl;
  cout << "Resultado suma: " << sumar(vec, 5) << endl;
   
  /*
  int n;
  cout << "Valor minimo: " << INT_MIN << endl;
  
  n = pedirNumero(10, "Ingrese un valor mayor que 9: ");
  cout << "El numero es: " << n << endl;
  
  n = pedirNumero(INT_MIN, "Ingrese cualquier valor: ");
  cout << "El numero es: " << n << endl;
  
  n = pedirNumero(50);
  cout << "El numero es: " << n << endl;
    */
    return 0;
}

int sumar(int n1, int n2, int n3){
  return n1 + n2 + n3;
}


int sumar(int n1, int n2){
  return n1 + n2;
}

float sumar(float n1, float n2){
  return n1 + n2;
}

int sumar(int vec[], int cant){
  int suma = 0;
  
  for(int i=0; i<cant; i++){
    suma += vec[i];  
  }
  
  return suma;
}

int pedirNumero(int valorMinimo, string mensaje){
  int numero;
  
  do{
    cout << mensaje;
    cin >> numero;
    
    if(numero < valorMinimo){
      cout << "> El numero ingresado es incorrecto!" << endl;  
    }
  }while(numero < valorMinimo);
  
  
  return numero;
}
