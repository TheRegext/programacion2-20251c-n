#include "Animal.h"

using namespace std;

Animal::Animal()
: _edad(0), _peso(0){
}

Animal::Animal(int edad, float peso){
  setEdad(edad);
  setPeso(peso);
}

void Animal::setEdad(int edad){
  if(edad >= 0){
    _edad = edad;
  }
  else{
    _edad = 0;  
  }
}

void Animal::setPeso(float peso){
  _peso = peso;
}

int Animal::getEdad(){
  return _edad;
}

float Animal::getPeso(){
  return _peso;
}
