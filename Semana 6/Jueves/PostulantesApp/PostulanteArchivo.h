#pragma once
#include <string>
#include "Postulante.h"

class PostulanteArchivo{
private:
  std::string _nombreArchivo;
public:
  PostulanteArchivo();
  PostulanteArchivo(std::string nombreArchivo);

  int buscar(int idPostulante);
  bool guardar(Postulante registro);
  bool guardar(Postulante registro, int posicion);
  int getCantidadRegistros();


  Postulante leer(int pos);
};
