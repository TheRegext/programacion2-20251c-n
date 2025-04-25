#include <iostream>
#include "Perro.h"

using namespace std;

Perro::Perro()
: Mascota() {
  _trabaja = false;
}

Perro::Perro(int edad, float peso, string nombre, bool trabaja)
: Mascota(edad, peso, nombre){ /// llama al constructor de la mascota y le envia los datos
  setTrabaja(trabaja);
}

void Perro::setTrabaja(bool trabaja){
  _trabaja = trabaja;
}

bool Perro::getTrabaja(){
  return _trabaja;
}

void Perro::ladrar(){
  cout << "Guau Guau!" << endl;
  cout << "tengo "<< getPeso() << endl;
}
