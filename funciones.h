/**
    @file funciones.h
    @brief Archivo que contiene las funciones auxiliares.

    Todas las funciones auxiliares aquí definidas se utilizarán a lo largo del resto del código.
    También se declaran aquí tres struct auxiliares para la hora de escribir o leer de un fichero binario.
*/
#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <fstream>
#include <string>
#include <iostream>
using namespace std;
/**
    @struct RegistroPaciente
    @brief Estructura que con variables de tipo char que nos servirá para poder trabajar con los ficheros binarios
*/
struct RegistroPaciente{
    char dni[10];
    char nombre[100];
    char apellidos[100];
    char direccion[100];
    char fechaNacimiento[100];
    char historial[100];
};
/**
    @struct RegistroCita
    @brief Estructura que con variables de tipo char que nos servirá para poder trabajar con los ficheros binarios
*/
struct RegistroCita{
  char apellidos[100];
  char fecha[100];
  char hora[100];
};
/**
    @struct RegistroTratamiento
    @brief Estructura que con variables de tipo char que nos servirá para poder trabajar con los ficheros binarios
*/
struct RegistroTratamiento{
  char apellidos[100];
  char medicamento[100];
  char concentracion[100];
  char planificacion[100];
  char inicio[100];
  char fin[100];
};
bool comprobarExistenciaDNI(string dni, vector<Paciente>pacientes);
bool comprobarFechaHora(string fecha, string hora, vector<Cita>citas);
bool comprobarApellidosPaciente(string apellido, vector<Paciente>pacientes);
bool comprobarApellidos(string apellido, vector<Cita>citas);
bool comprobarApellidosTratamientos(string apellido, vector<Tratamiento>tratamientos);

bool insertarPaciente(Paciente p);
bool insertarCita(Cita c);
bool insertarTratamiento(Tratamiento t);

bool borrarCita(string apellidos,   vector<Cita>citas);

bool borrarTratamiento(string apellidos,   vector<Tratamiento>tratamientos);


string mayusculas(string cadena);
void mostrarListaCitas(vector<Cita>citas);
bool borrarPaciente(string dni, vector<Paciente>pacientes);


string getFecha();
string getHora();

#endif
