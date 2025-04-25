#include <iostream>
#include "Perro.h"
#include "Gato.h"

/**
  edad
  peso
  nombre
  
  ///
  maullar
*/

/**
  private: accede unicame la clase 
  protected: accede la clase y sus hijos
  public: accede la calse, sus hijos, y todos
  
  
  clase base
  clase hija
  
  
  herencia public
  la hija
    
  
  
*/

using namespace std;

void mostrarSobrepeso(Mascota a, float pesoMinimo=10){
  if(a.getPeso() > pesoMinimo){
    cout << a.getNombre() << " tiene sobrepeso!"<<endl;  
  }
}

int main()
{
  Perro p(-11, 12, "Mancha");
  Gato g(-9, 50.5, "Griseldo");

  cout << "Este es: "<< p.getNombre() << endl;
  cout << "Edad: " << p.getEdad() << endl;
  p.ladrar();
  mostrarSobrepeso(p, 14);
  cout << endl;
  
  
  cout << "Este es: " << g.getNombre() << endl;
  cout << "Edad: " << g.getEdad() << endl;
  g.maullar();
  mostrarSobrepeso(g, 7);
  
  cout << endl << endl;
  g.saludar();
  cout << endl << endl;

  return 0;
}
