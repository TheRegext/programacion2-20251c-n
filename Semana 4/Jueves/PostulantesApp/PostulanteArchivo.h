#pragma once
#include <string>
#include "Postulante.h"

class PostulanteArchivo{
private:
  std::string _nombreArchivo;
public:
  PostulanteArchivo();
  PostulanteArchivo(std::string nombreArchivo);
  
  bool guardar(Postulante registro);
  int getCantidadRegistros();
  
  
  Postulante leer(int pos);
};
