#include <iostream>
#include <string>
#include "Postulante.h"
#include "PostulanteManager.h"
#include "PostulanteArchivo.h"

using namespace std;

void PostulanteManager::cargarPostulante()
{
  Postulante postulante; /// crea el objeto llamando al constructor vacio
  PostulanteArchivo pArchivo;

  int id, experiencia, edad;
  string nombres, apellidos, puesto;
  bool contratado;

  cout << "Ingrese ID: ";
  cin >> id;

  cout << "Ingrese nombres: ";
  cin.ignore();
  getline(cin, nombres);

  cout << "Ingrese apellidos: ";
  getline(cin, apellidos);

  cout << "Ingrese edad: ";
  cin >> edad;

  cout << "Ingrese puesto: ";
  cin.ignore();
  getline(cin, puesto);

  cout << "Ingrese experiencia: ";
  cin >> experiencia;

  cout << "Esta contratado? 1- Si 0- No: ";
  cin >> contratado;

  /// aca ya se que esta todo ok
  // postulante.setId(id);
  // postulante.setNombres(nombres);
  /// reemplazmos al postulante con un nuevo objeto
  postulante = Postulante(id, nombres, apellidos, edad, puesto, experiencia, contratado);

  /// cout << postulante.toCSV() << endl;

  if(pArchivo.guardar(postulante))
  {
    cout << "Se guardo correctamente!" << endl;
  }
  else
  {
    cout << "Hubo un error inesperado, llame al de sistemas..." << endl;
  }
}



void PostulanteManager::mostrarCantidadRegistros()
{
  PostulanteArchivo pArchivo;

  int cantidadRegistros = pArchivo.getCantidadRegistros();

  cout << "La cantidad de registros son: " << cantidadRegistros << endl;
}


void PostulanteManager::listarTodos()
{
  PostulanteArchivo pArchivo;
  Postulante registro;
  int cantidadRegistros = pArchivo.getCantidadRegistros();

  for(int i=0; i<cantidadRegistros; i++)
  {
    registro = pArchivo.leer(i);

    cout << registro.toCSV() << endl;
  }
}


void PostulanteManager::listarContratados()
{
  PostulanteArchivo pArchivo;
  Postulante reg;

  int cantidad = pArchivo.getCantidadRegistros();
  
  cout << "Los contratados fueron "<< endl;

  for(int i=0; i<cantidad; i++)
  {
    reg = pArchivo.leer(i);

    if(reg.getContratado())
    {
      cout << "------------" << endl;
      cout << "Apellido: " << reg.getApellidos() << endl;
      cout << "Nombre: " << reg.getNombres() << endl;
      cout << endl;
    }
  }
}






