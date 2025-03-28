#include <iostream>
using namespace std;

int main(){

   int *vec = nullptr, n, i, indice;

   cout << "Cantidad de elementos del vector: ";
   cin >> n;

   /// Pedimos memoria dinámica: Si me otorgan memoria devuelve la dirección inicial del vector
   vec = new int [n];

   if (vec == nullptr){
      cout << "No hay memoria."  << endl;
      return 1;
   }

   /// Utilizo el vector
   for(i=0; i<n; i++){
      vec[i] = i+1;
   }

   cout << "Que elemento del vector queres ver: ";
   cin >> indice;

   cout << vec[indice] << endl;

   /// No lo necesito más al vector. Libero la memoria.
   delete []vec;

   cout << "Fin del programa";

	return 0;
}
