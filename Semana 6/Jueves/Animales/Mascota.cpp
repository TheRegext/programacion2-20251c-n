#include <iostream>
#include "Mascota.h"

using namespace std;

Mascota::Mascota()
: Animal(), _nombre(""){
  
  
}

Mascota::Mascota(int edad, float peso, std::string nombre)
: Animal(edad, peso){
  setNombre(nombre);
}

void Mascota::setNombre(std::string nombre){
  _nombre = nombre;
}

std::string Mascota::getNombre(){
  return _nombre;
}

void Mascota::saludar(){
  cout << "Hola soy " << _nombre << endl;
  cout << "Y peso " << getPeso() << " kg"<<endl;
}
