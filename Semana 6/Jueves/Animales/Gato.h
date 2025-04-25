#pragma once
#include <string>
#include "Mascota.h"

class Gato: public Mascota{
private :
  
public:
  Gato();
  Gato(int edad, float peso, std::string nombre);
  
  void maullar();
};
