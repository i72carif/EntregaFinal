#ifndef PACIENTE_H
#define PACIENTE_H
#include<cstring>
#include<vector>
#include <iostream>
#include <cstdlib>
#include<stdio.h>


using namespace std;


class Paciente{
  private:
    string _DNI;
    string _NOMBRE;
    string _APELL;
    string _NACI;
    string _DIR;
    string _HIST;

    vector<Paciente>pacientes;

  public:
    Paciente(){
      _DNI=" ";
      _NOMBRE=" ";
      _APELL=" ";
      _NACI=" ";
      _DIR=" ";
      _HIST=" ";
    }

    inline string getDNI() const{
      return _DNI;
    }
    inline bool setDNI(string dni){
  	bool correcto=false;
      char cadDni[9];

      strcpy(cadDni, dni.c_str());

      dni[8] = toupper(dni[8]);
      if(strlen(cadDni) != 9){
          //cout<<"El DNI introducido no es correcto\n";
          correcto= false;
      }
      else{
          char letra[] = "TRWAGMYFPDXBNJZSQVHLCKE";
          if(letra[atoi(cadDni)%23] == dni[8]){
              _DNI=dni;
              correcto =true;
          }else{
            //cout<<"El DNI introducido no es correcto\n";
              correcto =false;
          }
      }
  	return correcto;
		}

    inline string getNOMBRE() const{
      return _NOMBRE;
    }
    inline bool setNOMBRE(const string NOMBRE)
		{
			_NOMBRE=NOMBRE;
      return true;

		}

    inline string getAPELL() const{
     return _APELL;
    }
    inline bool setAPELL(string APELL)
		{
			_APELL=APELL;
      return true;
		}

    inline string getNACI() const{
      return _NACI;
    }
    inline bool setNACI(string fecha_nacimiento)
		{
      bool correcto=true;
      char linea[10];
      strcpy(linea, fecha_nacimiento.c_str());
      unsigned d, m, a;
      bool correctoM = false, correctoD = false, bandera=false;

      strcpy(linea, fecha_nacimiento.c_str());
      if(linea == NULL){
          return EXIT_FAILURE;
      }
      //Comprueba que el formato de la fecha sea correcto, es decir, dd/mm/aaaa
      if(sscanf(linea, "%2u/%2u/%4u", &d, &m, &a) == 3){
          //Comprueba que el dia no sea menor de 1 ni mayor de 31
          if(d >= 1 && d <= 31){
              correctoD = true;
          }
          else{
              correctoD = false;
          }

          //Comprueba que el mes no sea menor de 1 ni mayor de 12
          if(m >= 1 && m <= 12){
              correctoM = true;
          }
          else{
              correctoM = false;
          }
      }
      else{
          correcto = false;
      }

      if(correcto && correctoD && correctoM){
          correcto = true;
      }
      else{
          correcto = false;
      }

      if(correcto==true){
          _NACI = fecha_nacimiento;
          bandera= true;
      }
      else{
          //cout<<"La Fecha introducida no es correcta. Debe usar el formato dd/MM/aaaa\n";
          bandera= false;
      }
    return bandera;

		}

    inline string getDIR() const{
      return _DIR;
    }
    inline bool setDIR(const string DIR)
		{
			_DIR=DIR;
      return true;

		}
    inline string getHIST() const{
      return _HIST;
    }
    inline bool setHIST(const string HIST)
    {
      _HIST=HIST;
      return true;

    }
    vector <Paciente>getPacientes(){
      return pacientes;
    }


};
#endif
