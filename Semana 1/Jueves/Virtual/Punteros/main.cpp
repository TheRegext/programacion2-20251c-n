#include <iostream>

using namespace std;

int main()
{
    int numero = 10;
    int *pNumero;
    // creamos una referencia (es como si crearamos un alias)
    int &rNumero = numero;
    
    pNumero = &numero;
    
    rNumero = 120;
    // *pNumero = 500;
    
    cout << "Puntero de rNumero: " << &rNumero << endl;
    cout << "Puntero a numero: " << pNumero << endl;
    cout << "Punto de pNumero: " << &pNumero << endl;
    cout << "Numero: " << numero << endl;
    return 0;
}
