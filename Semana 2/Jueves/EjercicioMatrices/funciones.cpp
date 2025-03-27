#include <iostream>
using namespace std;

#include "funciones.h"

void cargarAsistencia(bool asistencia[12][31], int totalHorasTrabajadas[30]){
   /// Registro
   int nroEmpleado, mes, dia, horasTrabajadas;

   cout << "Nro empleado: ";
   cin >> nroEmpleado;

   while (nroEmpleado != 0){
      cout << "Mes: ";
      cin >> mes;
      cout << "Dia: ";
      cin >> dia;
      cout << "Horas: ";
      cin >> horasTrabajadas;

      /// A
      asistencia[mes-1][dia-1] = true;

      /// C
      totalHorasTrabajadas[nroEmpleado-100]+=horasTrabajadas;

      cout << "--------------------" << endl;

      cout << "Nro empleado: ";
      cin >> nroEmpleado;
   }
}

void puntoA(bool asistencia[12][31]){
   int diasTrabajados;
   string nombreMeses[12] = { "Enero", "Febrero", "Marzo", "Abril", "Mayo", "Junio", "Julio", "Agosto", "Septiembre", "Octubre", "Noviembre", "Diciembre" };

   cout << "PUNTO A" << endl;
   cout << "--------------------" << endl;
   for(int mes=0; mes<12; mes++){
      diasTrabajados = 0;

      for(int dia=0; dia<31; dia++){
         if (asistencia[mes][dia]){
            diasTrabajados++;
         }
      }

      cout << nombreMeses[mes] << ": " << diasTrabajados << " días." << endl;
   }

}

void puntoC(int totalHorasTrabajadas[30]){

   cout << "PUNTO C" << endl;
   cout << "--------------------" << endl;
   for(int i=0; i<30; i++){
      cout << "IDEmpleado " << (i+100);
      cout << ": " << totalHorasTrabajadas[i] << " horas";
      cout << endl;
   }
}





