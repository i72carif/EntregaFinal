#ifndef TRATAMIENTO_H
#define TRATAMIENTO_H
#include<string>
using namespace std;

class Tratamiento{
  private:
    string _APELL;
    string _MEDIC;
    string _CONCEN;
    string _PLANIF;
    string _INICIO;
    string _FIN;
    vector<Tratamiento>tratamientos;

  public:
    Tratamiento(){
      _APELL="";
      _MEDIC="";
      _CONCEN="";
      _PLANIF="";
      _INICIO="";
      _FIN="";
    }

    inline string getAPELL() const{ return _APELL;  }
    inline bool setAPELL(const string APELL)
		{
			_APELL=APELL;
      return true;
		}

    inline string getMEDIC() const{  return _MEDIC; }
    inline bool setMEDIC(const string MEDIC)
		{
			_MEDIC=MEDIC;
      return true;

		}

    inline string getCONCEN() const{ return _CONCEN;  }
    inline bool setCONCEN(const string CONCEN)
		{
			_CONCEN=CONCEN;
      return true;

		}

    inline string getPLANIF() const{  return _PLANIF; }
    inline bool setPLANIF(const string PLANIF)
		{
			_PLANIF=PLANIF;
      return true;

		}

    inline string getINICIO() const{ return _INICIO;  }
    inline bool setINICIO(const string INICIO)
		{
      bool correcto=true;
      char linea[10];
      strcpy(linea, INICIO.c_str());
      unsigned d, m, a;
      bool correctoM = false, correctoD = false, bandera=false;

      strcpy(linea, INICIO.c_str());
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
          _INICIO = INICIO;
          bandera= true;
      }
      else{
          cout<<"La Fecha introducida no es correcta. Debe usar el formato dd/MM/aaaa\n";
          bandera= false;
      }
    return bandera;

		}

    inline string getFIN() const{ return _FIN;  }
    inline bool setFIN(const string FIN)
		{
      bool correcto=true;
      char linea[10];
      strcpy(linea, FIN.c_str());
      unsigned d, m, a;
      bool correctoM = false, correctoD = false, bandera=false;

      strcpy(linea, FIN.c_str());
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
          _FIN = FIN;
          bandera= true;
      }
      else{
          cout<<"La Fecha introducida no es correcta. Debe usar el formato dd/MM/aaaa\n";
          bandera= false;
      }
    return bandera;

		}

};
#endif
