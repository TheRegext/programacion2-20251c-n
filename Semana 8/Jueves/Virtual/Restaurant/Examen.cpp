#include <iostream>
using namespace std;

#include "Examen.h"
#include "ServicioMesa.h"
#include "ArchivoServicioMesa.h"

void Examen::EjemploDeListado(){
   ArchivoServicioMesa archivo("restaurant.dat");
   ServicioMesa registro;

   int i, cantidadRegistros = archivo.CantidadRegistros();
   for(i = 0; i < cantidadRegistros; i++){
      registro = archivo.Leer(i);
      cout << registro.toCSV() << endl;
   }
}
/**
  Listar la cantidad de servicios de mesa que fueron valorados con un puntaje mayor al puntaje promedio
*/
void Examen::Punto1(){
  ServicioMesa registro;
  ArchivoServicioMesa aServicioMesa("restaurant.dat");
  int cantidadServicioMesa = aServicioMesa.CantidadRegistros();
  float puntajeTotal = 0, promedio;
  int cantidadMayoresPromedio = 0;
  
  for(int i=0; i < cantidadServicioMesa; i++){
    registro = aServicioMesa.Leer(i);
    puntajeTotal += registro.getPuntajeObtenido();
  }
  
  if(cantidadServicioMesa > 0){
    promedio = puntajeTotal / cantidadServicioMesa;  
  }
  
  for(int i=0; i < cantidadServicioMesa; i++){
    ServicioMesa registro;
    registro = aServicioMesa.Leer(i);
    
    if(registro.getPuntajeObtenido() > promedio){
        cantidadMayoresPromedio++;
    }
  }

  // mostrar la cantidad
  cout << "La cantidad mayores al promedio son: " << cantidadMayoresPromedio << endl;
  
}
/**
  Listar el n£mero de plato que recaud¢ mayor cantidad de dinero
  
*/
void Examen::Punto2(){
  float recPlatos[70]={0};
  ServicioMesa registro;
  ArchivoServicioMesa aServicioMesa("restaurant.dat");
  
  int cantidadServicioMesa = aServicioMesa.CantidadRegistros();
  
  for(int i=0; i < cantidadServicioMesa; i++){
    registro = aServicioMesa.Leer(i);
    
    recPlatos[registro.getIDPlato() - 1] += registro.getImporte();
  }
  /*
  float maximo;
  int maximoPlato;
  
  for(int i=0; i<70; i++){
    if(i==0 || recPlatos[i] > maximo){
      maximo = recPlatos[i];
      maximoPlato = i + 1;
    }  
  }
  
  cout << "El plato maximo es: " << maximoPlato << endl;
  */
  
  int maximoPlato = 0;
  
  for(int i=1; i<70; i++){
    if(recPlatos[i] > recPlatos[maximoPlato]){
      maximoPlato = i;
    }  
  }
  
  /// el maximo
  cout << "El plato maximo es: " << maximoPlato + 1 << endl;
  
  /// los maximos
  /*
  for(int i=0; i<70; i++){
    if(recPlatos[i] == recPlatos[maximoPlato]){
      cout << i + 1 << endl;
    }  
  }*/
}
/***
  Listar el n£mero de mozo que recibi¢ mayor cantidad total de propinas en el a¤o 2024
*/
void Examen::Punto3(){
  int cantidadPropinas[20]={0};
  ServicioMesa registro;
  ArchivoServicioMesa aServicioMesa("restaurant.dat");
  
  int cantidadServicioMesa = aServicioMesa.CantidadRegistros();
  
  for(int i=0; i < cantidadServicioMesa; i++){
    registro = aServicioMesa.Leer(i);
    
    if(registro.getFecha().getAnio() == 2024 && registro.getPropina() > 0){
      cantidadPropinas[registro.getIDMozo() - 1]++;
    }
  }
  
  int maximoMozo = 0;
  
  for(int i=1; i<20; i++){
    if(cantidadPropinas[i] > cantidadPropinas[maximoMozo]){
      maximoMozo = i;
    }  
  }
  
  if(cantidadPropinas[maximoMozo] > 0){
    cout << "El mozo que mas propinas recibio en el 2024 es: " << maximoMozo + 1  << endl;    
  }
  else{
    cout << "Ningun mozo recibio propina en el 2024" << endl;  
  }
}










