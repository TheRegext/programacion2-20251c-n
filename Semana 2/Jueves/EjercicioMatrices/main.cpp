#include <iostream>
using namespace std;
#include "funciones.h"

int main()
{
   /// Inicializar las variables
   /// Punto A
   bool asistencia[12][31] = {};

   /// Punto B
   /// Punto C
   const int EMPLEADOS = 30;
   int horasTrabajadas[EMPLEADOS] = {};

   /// Carga y proceso de información
   cargarAsistencia(asistencia, horasTrabajadas);

   cout << endl << endl;

   /// Mostrar Punto A
   puntoA(asistencia);
   /// Mostrar Punto B
   cout << endl << endl;
   /// Mostrar Punto C
   puntoC(horasTrabajadas);


   cout << endl << "Fin del programa" << endl;

   return 0;
}
