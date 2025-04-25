#include <iostream>
#include "Gato.h"

using namespace std;

Gato::Gato()
: Mascota() {
  
}

Gato::Gato(int edad, float peso, string nombre)
: Mascota(edad, peso, nombre){ /// llama al constructor de la mascota y le envia los datos
  
}


void Gato::maullar(){
  cout << "Miau Miau!" << endl;
}
