#pragma once

class Animal{
private:
  int _edad;
  float _peso;
  
public:
  Animal();
  Animal(int edad, float peso);

  void setEdad(int edad);
  void setPeso(float peso);
  
  int getEdad();
  float getPeso();
};
