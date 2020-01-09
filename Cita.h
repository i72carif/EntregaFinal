#ifndef CITA_H
#define CITA_H
#include<string>
using namespace std;

class Cita{
  private:
    string _APELL;
    string _FECHA;
    string _HORA;
    vector<Cita>citas;
  public:
    Cita(){
      _APELL="";
      _FECHA="";
      _HORA="";
    }

    inline string getAPELL() const{ return _APELL;  }
    inline bool setAPELL(const string APELL)
		{
			_APELL=APELL;
      return true;
		}

    inline string getFECHA() const{  return _FECHA; }
    inline bool setFECHA( string FECHA)
		{
      bool correcto=true;
      char linea[10];
      strcpy(linea, FECHA.c_str());
      unsigned d, m, a;
      bool correctoM = false, correctoD = false, bandera=false;

      strcpy(linea, FECHA.c_str());
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
          _FECHA = FECHA;
          bandera= true;
      }
      else{
          cout<<"La Fecha introducida no es correcta. Debe usar el formato dd/MM/aaaa\n";
          bandera= false;
      }
    return bandera;

		}

    inline string getHORA() const{ return _HORA;  }
    inline bool setHORA(const string HORA)
		{
      unsigned h;
      char linea[10];

      strcpy(linea, HORA.c_str());
      if(linea == NULL){
          return EXIT_FAILURE;
      }

      if(sscanf(linea, "%2u", &h) == 1){

          if(h >= 0 && h <= 24){
              _HORA=HORA;
              return true;
          }
      }
      cout<<"La Hora introducida no es correcta. Debe usar el formato hh desde las 00 hasta las 24\n";
      return false;
		}

};
#endif
