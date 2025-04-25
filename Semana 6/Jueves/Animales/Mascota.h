#pragma once
#include <string>
#include "Animal.h"

class Mascota: public Animal{
private :
  std::string _nombre;

public:
  Mascota();
  Mascota(int edad, float peso, std::string nombre);
  
  void saludar();

  void setNombre(std::string nombre);
  std::string getNombre();
};
