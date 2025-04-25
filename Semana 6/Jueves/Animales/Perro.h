#pragma once
#include <string>
#include "Mascota.h"

class Perro: public Mascota{
private:
  bool _trabaja;
public:
  Perro();
  Perro(int edad, float peso, std::string nombre, bool trabaja = true);
  
  void setTrabaja(bool trabaja);
  bool getTrabaja();
  
  void ladrar();
};
