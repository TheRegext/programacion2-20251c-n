#include "PostulanteArchivo.h"

PostulanteArchivo::PostulanteArchivo(){
  _nombreArchivo = "postulantes.dat";
}

PostulanteArchivo::PostulanteArchivo(std::string nombreArchivo){
  _nombreArchivo = nombreArchivo;
}

bool PostulanteArchivo::guardar(Postulante registro){
  FILE *pFile;
  bool result;
  
  pFile = fopen(_nombreArchivo.c_str(), "ab");
  
  if(pFile == nullptr){
    return false;  
  }
  
  result = fwrite(&registro, sizeof(Postulante), 1, pFile);
  
  fclose(pFile);
  
  return result;
}

int PostulanteArchivo::getCantidadRegistros(){
  int tamRegistro, total, cantidad;
  FILE* pFile;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    return 0;  
  }
    // file  byte  desde
  fseek(pFile, 0, SEEK_END);

  total = ftell(pFile);
  
  cantidad = total / sizeof(Postulante);
  
  fclose(pFile);
  
  return cantidad;
}


Postulante PostulanteArchivo::leer(int pos){
  FILE *pFile;
  Postulante reg;
  
  pFile = fopen(_nombreArchivo.c_str(), "rb");
  
  if(pFile == nullptr){
    return reg;   
  }
  
  fseek(pFile, sizeof(Postulante) * pos, SEEK_SET);
  
  fread(&reg, sizeof(Postulante), 1, pFile);
  
  fclose(pFile);
  
  return reg;
}






