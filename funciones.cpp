#include "Paciente.h"
#include "Tratamiento.h"
#include "Cita.h"
#include "funciones.h"

#include <ctime>
#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cstring>
#include<vector>


using namespace std;


/**
    @fn int menu()
    @brief Menu de las funciones principales
    @param pacientes
    @return int opcion elegida
*/
int menu(){
  int opc;
  printf("\n///////////////MENU PRINCIPAL///////////////");
  printf("\n1. Mostrar citas del dia\n");
  printf("2. Mostrar lista de pacientes\n");
  printf("3. Añadir paciente\n");
  printf("4. Mostrar paciente y opciones\n");
  printf("5. Borrar paciente\n");
  printf("6. Salir\n");
  printf("//////////////////////////////\n");
  printf("Introduzca la opcion deseada: \n");
  scanf("%i", &opc);
  return opc;
}

int menu2(){
  int opc2;
  printf("\n--------------------");
  printf("\nSUBMENU MOSTRARPACIENTE");
  printf("\n--------------------");

  printf("\n1. Modificar datos del paciente\n");
  printf("2. Modificar historial\n");
  printf("3. Añadir cita\n");
  printf("4. Mover cita\n");
  printf("5. Cancelar cita\n");
  printf("6. Añadir tratamiento\n");
  printf("7. Cancelar tratamiento\n");
  printf("0. Volver al menú principal\n");

  printf("Introduzca la opcion deseada: ");
  scanf("%i", &opc2);
  return opc2;
}

/**
    @fn void fichPacientesToVect(vector<Paciente>&pacientes)
    @brief Pasa los datos del fichero de pacientes al vector
    @param pacientes
    @return void
*/
void fichPacientesToVect(vector<Paciente>&pacientes){

  pacientes.clear();
  ifstream fich;
  fich.open("pacientes.txt");
  Paciente p;
  string lineaLeida;

  while(getline(fich, lineaLeida,' ')){
    p.setDNI(lineaLeida);

    getline(fich, lineaLeida,' ');
    p.setNOMBRE(lineaLeida);

    getline(fich, lineaLeida,' ');
    p.setAPELL(lineaLeida);

    getline(fich, lineaLeida,' ');
    p.setDIR(lineaLeida);

    getline(fich, lineaLeida,' ');
    p.setNACI(lineaLeida);

    getline(fich, lineaLeida,'\n');
    p.setHIST(lineaLeida);

    pacientes.push_back(p);
  }
  fich.close();
}

/**
    @fn void fichTratamientosToVect(vector<Tratamiento>&tratamientos)
    @brief Pasa los datos del fichero de tratamientos al vector
    @param tratamientos
    @return void
*/
void fichTratamientosToVect(vector<Tratamiento>&tratamientos){
  tratamientos.clear();

  ifstream fich;
  fich.open("tratamientos.txt");
  Tratamiento t;
  string lineaLeida;

  while(getline(fich, lineaLeida,' ')){
  t.setAPELL(lineaLeida);
  getline(fich, lineaLeida,' ');
  t.setMEDIC(lineaLeida);
  getline(fich, lineaLeida,' ');
  t.setCONCEN(lineaLeida);
  getline(fich, lineaLeida,' ');
  t.setPLANIF(lineaLeida);
  getline(fich, lineaLeida,' ');
  t.setINICIO(lineaLeida);
  getline(fich, lineaLeida,'\n');
  t.setFIN(lineaLeida);

  tratamientos.push_back(t);
  }
  fich.close();
}
/**
    @fn void fichCitasToVect(vector<Cita>&citas)
    @brief Pasa los datos del fichero de citas al vector
    @param citas
    @return void
*/
void fichCitasToVect(vector<Cita>&citas){
  citas.clear();

  ifstream fich;
  fich.open("citas.txt");
  Cita c;
  string lineaLeida;

  while(getline(fich, lineaLeida,' ')){
  c.setAPELL(lineaLeida);
  getline(fich, lineaLeida,' ');
  c.setFECHA(lineaLeida);
  getline(fich, lineaLeida,'\n');
  c.setHORA(lineaLeida);

  citas.push_back(c);
  }
  fich.close();
}







/**
    @fn void mostrarListaPacientes(vector<Paciente>pacientes)
    @brief muestra el nombre y apellidos de todos los pacientes registrados
    @param pacientes
    @return void
*/
void mostrarListaPacientes(vector<Paciente>pacientes){
  vector<Paciente>::iterator it;
  RegistroPaciente reg;
  for(it=pacientes.begin();it !=pacientes.end(); it++){

    strcpy(reg.nombre, (*it).getNOMBRE().c_str());
    strcpy(reg.apellidos,(*it).getAPELL().c_str());

    cout<<reg.nombre<<' ';
    cout<<reg.apellidos<<'\n';
  }
}


/**
    @fn void mostrarListaCitas(vector<Cita>citas)
    @brief muestra el horario de las citas del dia y el apellido del paciente
    @param citas
    @return void
*/
void mostrarListaCitas(vector<Cita>citas){
  vector<Cita>::iterator it;
  RegistroCita reg;
  for(it=citas.begin() ;it !=citas.end(); it++){
    strcpy(reg.fecha, (*it).getFECHA().c_str());
    strcpy(reg.apellidos, (*it).getAPELL().c_str());
    strcpy(reg.hora,(*it).getHORA().c_str());
      if(getFecha()==reg.fecha){
        cout<<reg.apellidos<<' ';
        cout<<reg.hora<<'\n';
      }
  }
}
/**
    @fn bool mostrarPaciente(string apellidos, vector<Paciente>pacientes, vector<Cita>citas, vector<Tratamiento>tratamientos){
    @brief muestra los datos de un paciente en concreto ademas de su cita y tratamiento si lo tiene
    @param apellidos
    @param pacientes
    @param citas
    @param tratamientos
    @return Devuelve un booleano, true si no ha habido problemas al mostrarlo y false en caso contrario
*/
bool mostrarPaciente(string apellidos, vector<Paciente>pacientes, vector<Cita>citas, vector<Tratamiento>tratamientos){
  vector<Paciente>::iterator it1;
  vector<Cita>::iterator it2;
  vector<Tratamiento>::iterator it3;

  bool res=false;

  RegistroPaciente reg1;
  RegistroCita reg2;
  RegistroTratamiento reg3;
  cout<<"\n     PACIENTE\n";

  for(it1=pacientes.begin();it1 !=pacientes.end(); it1++){
    strcpy(reg1.apellidos, (*it1).getAPELL().c_str());

    if(reg1.apellidos==apellidos){
      strcpy(reg1.dni, (*it1).getDNI().c_str());
      strcpy(reg1.nombre,(*it1).getNOMBRE().c_str());
      strcpy(reg1.apellidos, (*it1).getAPELL().c_str());
      strcpy(reg1.fechaNacimiento,(*it1).getNACI().c_str());
      strcpy(reg1.direccion, (*it1).getDIR().c_str());
      strcpy(reg1.historial,(*it1).getHIST().c_str());

      cout<<"DNI: "<<reg1.dni<<'\n';
      cout<<"Nombre: "<<reg1.nombre<<'\n';
      cout<<"Apellidos: "<<reg1.apellidos<<'\n';
      cout<<"Fecha de nacimiento: "<<reg1.fechaNacimiento<<'\n';
      cout<<"Direccion: "<<reg1.direccion<<'\n';
      cout<<"Historial: "<<reg1.historial<<'\n';
      res=true;
    }
  }
  cout<<"\n     CITA\n";

  for(it2=citas.begin();it2 !=citas.end(); it2++){
    strcpy(reg2.apellidos, (*it2).getAPELL().c_str());
    if(reg2.apellidos==apellidos){
      //strcpy(reg2.apellidos, (*it2).getAPELL().c_str());
      strcpy(reg2.fecha,(*it2).getFECHA().c_str());
      strcpy(reg2.hora,(*it2).getHORA().c_str());

      //cout<<reg2.apellidos<<' ';
      cout<<"Fecha: "<<reg2.fecha<<'\n';
      cout<<"Hora: "<<reg2.hora<<'\n';
    }
  }

  cout<<"\n     TRATAMIENTO\n";
  for(it3=tratamientos.begin();it3 !=tratamientos.end(); it3++){
    strcpy(reg3.apellidos, (*it3).getAPELL().c_str());

    if(reg3.apellidos==apellidos){
      //strcpy(reg3.apellidos, (*it3).getAPELL().c_str());
      strcpy(reg3.medicamento,(*it3).getMEDIC().c_str());
      strcpy(reg3.concentracion, (*it3).getCONCEN().c_str());
      strcpy(reg3.planificacion,(*it3).getPLANIF().c_str());
      strcpy(reg3.inicio, (*it3).getINICIO().c_str());
      strcpy(reg3.fin,(*it3).getFIN().c_str());

      //cout<<reg3.apellidos<<' ';
      cout<<"Medicamento: "<<reg3.medicamento<<'\n';
      cout<<"Concentracion: "<<reg3.concentracion<<'\n';
      cout<<"Planificacion: "<<reg3.planificacion<<'\n';
      cout<<"Inicio: "<<reg3.inicio<<'\n';
      cout<<"Fin: "<<reg3.fin<<'\n';
    }
  }
  return res;
}






/**
    @fn bool añadirDatosPacientes(string dni, string nombre, string apellidos string direccion, string fecha_nacimiento, vector<Paciente>pacientes)
    @brief Hace las comprobaciones necesarias de los datos y llama a la función insertarPaciente para introducirlo en el fichero
    @param dni
    @param nombre
    @param apellidos
    @param direccion
    @param fecha_nacimiento
    @param pacientes
    @return Devuelve un booleano, true si no ha habido problemas al guardarlo y false en caso contrario
*/
bool anadirDatosPacientes(string dni, string nombre, string apellidos, string fecha_nacimiento, string direccion, string historial, vector<Paciente>pacientes){
    Paciente p;

    vector<Paciente> aux;
    char auxDNI[9];
    bool funcionCorrecta=false, devuelve=false, encontrado=false, guardar=true;;

    strcpy(auxDNI, dni.c_str());
    auxDNI[8]= toupper(auxDNI[8]);
    dni= auxDNI;
    encontrado= comprobarExistenciaDNI(dni, pacientes);
    if(encontrado==false){
        if((p.setDNI(dni))==false){
            guardar=false;
        }
    }else{
        cout<<"DNI existente. Introduzca uno distinto"<<endl;
        guardar=false;
    }

    nombre= mayusculas(nombre);
    p.setNOMBRE(nombre);

    apellidos= mayusculas(apellidos);
    p.setAPELL(apellidos);

    direccion= mayusculas(direccion);
    p.setDIR(direccion);
  if((p.setNACI(fecha_nacimiento))==false){
        guardar=false;
    }
    historial= mayusculas(historial);
    p.setHIST(historial);

    if(guardar==true){
        funcionCorrecta= insertarPaciente(p);
            if(funcionCorrecta==true){
                devuelve= true;
            }else{
                devuelve= false;
            }
    }else{
      devuelve= false;
    }
    aux.clear();
    return devuelve;
}
/*
@fn bool añadirDatosCitas(string apellidos string fecha, string hora, vector<Cite>citas)
@return Devuelve un booleano, true si no ha habido problemas al guardarlo y false en caso contrario
*/
bool anadirDatosCitas(string apellidos, string fecha, string hora, vector<Cita>citas){
    Cita c;
    vector<Cita> aux;
    bool funcionCorrecta=false, devuelve=false, guardar=true;
    char auxAPELL[100];
    strcpy(auxAPELL, apellidos.c_str());
    apellidos= auxAPELL;
    if(comprobarApellidos(apellidos, citas)==false){
      apellidos= mayusculas(apellidos);
      c.setAPELL(apellidos);
    }else{
      cout<<"El paciente ya tiene asignada una cita\n";
      guardar=false;
    }
    char auxFECHA[100];
    char auxHORA[100];

    strcpy(auxFECHA, fecha.c_str());
    strcpy(auxHORA, hora.c_str());

    hora= auxHORA;
    fecha= auxFECHA;
    if(comprobarFechaHora(fecha, hora, citas)==false){
      if(c.setFECHA(fecha)==false){
        guardar=false;
      }
      if((c.setHORA(hora))==false){
        guardar=false;
      }
    }else{
      cout<<"Ya existe una cita para ese dia y hora\n";
      guardar=false;
    }
    if(guardar==true){
        funcionCorrecta= insertarCita(c);
            if(funcionCorrecta==true){
                devuelve= true;
            }else{
                devuelve= false;
            }
    }else{
      devuelve= false;
    }
    aux.clear();
    return devuelve;
}




/*
@fn bool añadirDatosTratamientos(string apellidos, string medicamento, string concentracion, string planificacion, string inicio, string fin, vector<Tratamiento>tratamientos)
@return Devuelve un booleano, true si no ha habido problemas al guardarlo y false en caso contrario
*/
bool anadirDatosTratamientos(string apellidos, string medicamento, string concentracion, string planificacion, string inicio, string fin, vector<Tratamiento>tratamientos){
    Tratamiento t;
    vector<Tratamiento> aux;

    bool funcionCorrecta=false, devuelve=false, guardar=true;

    if(comprobarApellidosTratamientos(apellidos, tratamientos)==false){
      apellidos= mayusculas(apellidos);
      t.setAPELL(apellidos);
    }else{
      cout<<"El paciente ya tiene asignada un tratamiento\n";
      guardar=false;
    }

      if((t.setMEDIC(medicamento))==false){
        guardar=false;
      }
      if((t.setCONCEN(concentracion))==false){
        guardar=false;
      }
      if((t.setPLANIF(planificacion))==false){
        guardar=false;
      }
      if((t.setINICIO(inicio))==false){
        guardar=false;
      }
      if((t.setFIN(fin))==false){
        guardar=false;
      }

    if(guardar==true){
        funcionCorrecta= insertarTratamiento(t);
            if(funcionCorrecta==true){
                devuelve= true;
            }else{
                devuelve= false;
            }
    }else{
      devuelve= false;
    }
    aux.clear();
    return devuelve;
}




/**
    @fn bool insertarPaciente(Paciente p)
    @brief Función que inserta un nuevo paciente en la base de datos

    Esta función inserta el nuevo paceinte si cumple las siguientes condiciones:
        - El paciente aún no está guardado.
        - Los campos a rellenar están correctamente cumplimentados.
    @param p
    @return Devuelve un booleano, si guarda al paciente devuelve true y en caso contrario false
*/

bool insertarPaciente(Paciente p){
  bool correcto = false;
  ofstream file;
  file.open("pacientes.txt",ios::out | ios::binary | ios::app);
  RegistroPaciente reg;

  if(file.is_open()){
    strcpy(reg.dni,p.getDNI().c_str());
    strcpy(reg.nombre,p.getNOMBRE().c_str());
    strcpy(reg.apellidos,p.getAPELL().c_str());
    strcpy(reg.direccion, p.getDIR().c_str());
    strcpy(reg.fechaNacimiento,p.getNACI().c_str());
    strcpy(reg.historial,p.getHIST().c_str());

    file<<reg.dni<<' ';
    file<<reg.nombre<<' ';
    file<<reg.apellidos<<' ';
    file<<reg.direccion<<' ';
    file<<reg.fechaNacimiento<<' ';
    file<<reg.historial<<'\n';


    file.close();
    correcto = true;
  }else{
    correcto=false;
  }
  return correcto;
}
/**
    @fn bool insertarCita(Cita c)
    @brief Función que inserta una nueva cita en la base de datos

    Esta función inserta una nueva cita si cumple las siguientes condiciones:
        - El paciente aun no tiene asignada ninguna cita.
        - Los campos a rellenar están correctamente cumplimentados.
    @param c
    @return Devuelve un booleano, si guarda la cita devuelve true y en caso contrario false
*/
bool insertarCita(Cita c){
  bool correcto = false;
  ofstream file;
  file.open("citas.txt",ios::out | ios::binary | ios::app);
  RegistroCita reg;

  if(file.is_open()){
    strcpy(reg.apellidos,c.getAPELL().c_str());
    strcpy(reg.fecha,c.getFECHA().c_str());
    strcpy(reg.hora,c.getHORA().c_str());

    file<<reg.apellidos<<' ';
    file<<reg.fecha<<' ';
    file<<reg.hora<<'\n';

    file.close();
    correcto = true;
  }else{
    correcto=false;
  }
  return correcto;
}
/**
    @fn bool insertarTratamiento(Tratamiento t)
    @brief Función que inserta un nuevo tratamiento en la base de datos

    Esta función inserta el nuevo tratamiento si cumple las siguientes condiciones:
        - El paciente aún no tiene asignado ningun tratamiento.
        - Los campos a rellenar están correctamente cumplimentados.
    @param t
    @return Devuelve un booleano, si guarda al paciente devuelve true y en caso contrario false
*/
bool insertarTratamiento(Tratamiento t){
  bool correcto = false;
  ofstream file;
  file.open("tratamientos.txt",ios::out | ios::binary | ios::app);
  RegistroTratamiento reg;

  if(file.is_open()){
    strcpy(reg.apellidos,t.getAPELL().c_str());
    strcpy(reg.medicamento,t.getMEDIC().c_str());
    strcpy(reg.concentracion,t.getCONCEN().c_str());
    strcpy(reg.planificacion,t.getPLANIF().c_str());
    strcpy(reg.inicio,t.getINICIO().c_str());
    strcpy(reg.fin,t.getFIN().c_str());

    file<<reg.apellidos<<' ';
    file<<reg.medicamento<<' ';
    file<<reg.concentracion<<' ';
    file<<reg.planificacion<<' ';
    file<<reg.inicio<<' ';
    file<<reg.fin<<'\n';

    file.close();
    correcto = true;
  }else{
    correcto=false;
  }
  return correcto;
}




/**
    @fn borrarPaciente(string apellidos,   vector<Paciente>pacientes, vector<Cita>citas, vector<Tratamiento>tratamientos){
    @brief Función que borra todos los datos de las bases de datos de un paciente

    Esta función elimina un paciente si cumple las siguientes condiciones:
        - El paciente existe en la base de datos.
        - El apellidos del paciente que se quiere eliminar es correcto.
    @param pacientes
    @param citas
    @param tratamientos
    @param apellidos
    @return Devuelve un booleano, si elimina al paciente devuelve true y en caso contrario false
*/


bool borrarPaciente(string apellidos,   vector<Paciente>pacientes, vector<Cita>citas, vector<Tratamiento>tratamientos){
  vector<Paciente>::iterator it;
  RegistroPaciente reg;
  bool correcto = false;
  ifstream file("pacientes.txt",ios::in);
  ofstream fileAux;
  borrarCita(apellidos, citas);
  borrarTratamiento(apellidos, tratamientos);
  fileAux.open("auxiliar.txt",ios::out | ios::binary | ios::app);
  if(file.is_open() && fileAux.is_open()){
    for(it=pacientes.begin();it !=pacientes.end(); it++){
      strcpy(reg.apellidos, (*it).getAPELL().c_str());

      if(reg.apellidos==apellidos){
        correcto = true;
      }else{
          strcpy(reg.dni,(*it).getDNI().c_str());
          strcpy(reg.nombre,(*it).getNOMBRE().c_str());
          strcpy(reg.apellidos,(*it).getAPELL().c_str());
          strcpy(reg.direccion, (*it).getDIR().c_str());
          strcpy(reg.fechaNacimiento, (*it).getNACI().c_str());
          strcpy(reg.historial, (*it).getHIST().c_str());


          fileAux<<reg.dni<<' ';
          fileAux<<reg.nombre<<' ';
          fileAux<<reg.apellidos<<' ';
          fileAux<<reg.direccion<<' ';
          fileAux<<reg.fechaNacimiento<<' ';
          fileAux<<reg.historial<<'\n';
        }
      }
  }else{
    cout<<"Problema con el fichero de texto";
  }
  file.close();
  fileAux.close();
  remove("pacientes.txt");
  rename("auxiliar.txt", "pacientes.txt");
  return correcto;
}




/**
    @fn borrarCita(string apellidos, vector<Cita>citas){
    @brief Función que borra la cita asignada a un paciente en concreto.

    Esta función elimina una cita si cumple las siguientes condiciones:
        - El paciente tiene asignada una cita.
        - El apellidos del paciente que se quiere eliminar es correcto.
    @param citas
    @param apellidos
    @return Devuelve un booleano, si elimina la cita del paciente devuelve true y en caso contrario false
*/
bool borrarCita(string apellidos,   vector<Cita>citas){
  vector<Cita>::iterator it;
  RegistroCita reg;
  bool correcto = false;
  ifstream file("citas.txt",ios::in);
  ofstream fileAux;
  fileAux.open("auxiliar.txt",ios::out | ios::binary | ios::app);
  if(file.is_open() && fileAux.is_open()){
    for(it=citas.begin();it !=citas.end(); it++){
      strcpy(reg.apellidos, (*it).getAPELL().c_str());

      if(reg.apellidos==apellidos){
        correcto = true;
      }else{
          strcpy(reg.apellidos,(*it).getAPELL().c_str());
          strcpy(reg.fecha,(*it).getFECHA().c_str());
          strcpy(reg.hora,(*it).getHORA().c_str());

          fileAux<<reg.apellidos<<' ';
          fileAux<<reg.fecha<<' ';
          fileAux<<reg.hora<<'\n';
        }
      }
  }else{
    cout<<"Problema con el fichero de texto";
  }
  file.close();
  fileAux.close();
  remove("citas.txt");
  rename("auxiliar.txt", "citas.txt");
  return correcto;
}




/**
    @fn borrarTratamiento(string apellidos, vector<Tratamiento>tratamientos){
    @brief Función que borra el tratamiento de un paciente en concreto

    Esta función elimina un tratamiento si cumple las siguientes condiciones:
        - El paciente tiene asignado un tratamiento.
        - El apellidos del paciente que se quiere eliminar es correcto.
    @param tratamientos
    @param apellidos
    @return Devuelve un booleano, si elimina el tratamiento del paciente devuelve true y en caso contrario false
*/
bool borrarTratamiento(string apellidos,   vector<Tratamiento>tratamientos){
  vector<Tratamiento>::iterator it;
  RegistroTratamiento reg;
  bool correcto = false;
  ifstream file;
  file.open("tratamientos.txt",ios::in);
  ofstream fileAux;
  fileAux.open("auxiliar.txt",ios::out | ios::binary | ios::app);
  if(file.is_open() && fileAux.is_open()){
    for(it=tratamientos.begin();it !=tratamientos.end(); it++){
      strcpy(reg.apellidos, (*it).getAPELL().c_str());

      if(reg.apellidos==apellidos){
        correcto = true;
      }else{
          strcpy(reg.apellidos,(*it).getAPELL().c_str());
          strcpy(reg.medicamento,(*it).getMEDIC().c_str());
          strcpy(reg.concentracion,(*it).getCONCEN().c_str());
          strcpy(reg.planificacion, (*it).getPLANIF().c_str());
          strcpy(reg.inicio, (*it).getINICIO().c_str());
          strcpy(reg.fin, (*it).getFIN().c_str());


          fileAux<<reg.apellidos<<' ';
          fileAux<<reg.medicamento<<' ';
          fileAux<<reg.concentracion<<' ';
          fileAux<<reg.planificacion<<' ';
          fileAux<<reg.inicio<<' ';
          fileAux<<reg.fin<<'\n';
        }
      }
  }else{
    cout<<"Problema con el fichero de texto";
  }
  file.close();
  fileAux.close();
  remove("tratamientos.txt");
  rename("auxiliar.txt", "tratamientos.txt");
  return correcto;
}



/**
    @fn bool modificarPaciente(string apellidos2,   vector<Paciente>pacientes)
    @brief Función que modifica los datos de un Paciente

    Esta función modifica los datos si todos ellos están cumplimentados correctamente.

    @param apellidos2
    @param pacientes
    @return Devuelve un booleano, si guarda al paciente devuelve true y en caso contrario false
*/
bool modificarPaciente(string apellidos2,   vector<Paciente>pacientes){
  vector<Paciente>::iterator it;
  RegistroPaciente reg;
  string dni;
  string nombre;
  //string apellidos;
  string fecha_nacimiento;
  string direccion;
  bool correcto = false;
  ifstream file("pacientes.txt",ios::in);
  ofstream fileAux;
  fileAux.open("auxiliar.txt",ios::out | ios::binary | ios::app);

  /*cout<<"\nIntroduce el DNI\n";
  cin>> dni;
  if(comprobarExistenciaDNI(dni, pacientes)==true){
    file.close();
    fileAux.close();
    remove("auxiliar.txt");
    cout<<"El paciente con el dni introducido ya existe";
    return false;
  }*/
  cout<<"\n ESRIBA TODO JUNTO\n";

  cout<<"\nIntroduce el Nombre\n";
  cin>>nombre;
  nombre=mayusculas(nombre);
  //cout<<"\nIntroduce el Apellidos\n";
  //cin>>apellidos;
  //apellidos=mayusculas(apellidos);

  /*if(comprobarApellidosPaciente(apellidos, pacientes)==true){
    file.close();
    fileAux.close();
    remove("auxiliar.txt");

    cout<<"No pueden existir dos pacientes con el mismo apellido";
    return false;
  }*/
  cout<<"\nIntroduce el Dirección\n";
  cin>>direccion;
  direccion=mayusculas(direccion);

  cout<<"\nIntroduce el Fecha Nacimiento\n";
  cin>>fecha_nacimiento;

  if(file.is_open() && fileAux.is_open()){
    for(it=pacientes.begin();it !=pacientes.end(); it++){
      strcpy(reg.apellidos, (*it).getAPELL().c_str());
      strcpy(reg.dni,(*it).getDNI().c_str());

      if(reg.apellidos==apellidos2){
        //strcpy(reg.dni,/*(*it).getHIST().*/dni.c_str());
        strcpy(reg.nombre,nombre.c_str());
        strcpy(reg.apellidos, (*it).getAPELL().c_str());

        //strcpy(reg.apellidos,apellidos.c_str());
        strcpy(reg.direccion, direccion.c_str());
        strcpy(reg.fechaNacimiento, fecha_nacimiento.c_str());
        strcpy(reg.historial, (*it).getHIST().c_str());

        fileAux<<reg.dni<<' ';
        fileAux<<reg.nombre<<' ';
        fileAux<<reg.apellidos<<' ';
        fileAux<<reg.direccion<<' ';
        fileAux<<reg.fechaNacimiento<<' ';
        fileAux<<reg.historial<<'\n';
        correcto = true;
      }else{
          strcpy(reg.dni,(*it).getDNI().c_str());
          strcpy(reg.nombre,(*it).getNOMBRE().c_str());
          strcpy(reg.apellidos,(*it).getAPELL().c_str());
          strcpy(reg.direccion, (*it).getDIR().c_str());
          strcpy(reg.fechaNacimiento, (*it).getNACI().c_str());
          strcpy(reg.historial, (*it).getHIST().c_str());


          fileAux<<reg.dni<<' ';
          fileAux<<reg.nombre<<' ';
          fileAux<<reg.apellidos<<' ';
          fileAux<<reg.direccion<<' ';
          fileAux<<reg.fechaNacimiento<<' ';
          fileAux<<reg.historial<<'\n';
        }
      }

  }else{
    cout<<"Problema con el fichero de texto";
  }
  file.close();
  fileAux.close();
  remove("pacientes.txt");
  rename("auxiliar.txt", "pacientes.txt");
  return correcto;
}


/**
    @fn bool modificarHistorial(string apellidos,   vector<Paciente>pacientes)
    @brief Función que modifica el historial de un paciente

    Esta función modifica el historial.

    @param apellidos
    @param pacientes
    @return Devuelve un booleano, si guarda el historial devuelve true y en caso contrario false
*/

bool modificarHistorial(string apellidos,   vector<Paciente>pacientes){
  vector<Paciente>::iterator it;
  RegistroPaciente reg;
  string historial;
  bool correcto = false;
  ifstream file("pacientes.txt",ios::in);
  ofstream fileAux;
  fileAux.open("auxiliar.txt",ios::out | ios::binary | ios::app);
  if(file.is_open() && fileAux.is_open()){
    for(it=pacientes.begin();it !=pacientes.end(); it++){
      strcpy(reg.apellidos, (*it).getAPELL().c_str());

      if(reg.apellidos==apellidos){

        cout<<"\nIntroduce el nuevo historial\n";
        cin>>historial;
        historial=mayusculas(historial);
        strcpy(reg.dni,(*it).getDNI().c_str());
        strcpy(reg.nombre,(*it).getNOMBRE().c_str());
        strcpy(reg.apellidos,(*it).getAPELL().c_str());
        strcpy(reg.direccion, (*it).getDIR().c_str());
        strcpy(reg.fechaNacimiento, (*it).getNACI().c_str());
        strcpy(reg.historial, historial.c_str());

        fileAux<<reg.dni<<' ';
        fileAux<<reg.nombre<<' ';
        fileAux<<reg.apellidos<<' ';
        fileAux<<reg.direccion<<' ';
        fileAux<<reg.fechaNacimiento<<' ';
        fileAux<<reg.historial<<'\n';
        correcto = true;
      }else{
          strcpy(reg.dni,(*it).getDNI().c_str());
          strcpy(reg.nombre,(*it).getNOMBRE().c_str());
          strcpy(reg.apellidos,(*it).getAPELL().c_str());
          strcpy(reg.direccion, (*it).getDIR().c_str());
          strcpy(reg.fechaNacimiento, (*it).getNACI().c_str());
          strcpy(reg.historial, (*it).getHIST().c_str());


          fileAux<<reg.dni<<' ';
          fileAux<<reg.nombre<<' ';
          fileAux<<reg.apellidos<<' ';
          fileAux<<reg.direccion<<' ';
          fileAux<<reg.fechaNacimiento<<' ';
          fileAux<<reg.historial<<'\n';
        }
      }
  }else{
    cout<<"Problema con el fichero de texto";
  }
  file.close();
  fileAux.close();
  remove("pacientes.txt");
  rename("auxiliar.txt", "pacientes.txt");
  return correcto;
}






/**
    @fn bool modificarCita(string apellidos,   vector<Cita>citas)
    @brief Función que modifica la fecha de la cita de un paciente

    Esta función modifica el historial.

    @param apellidos
    @param citas
    @return Devuelve un booleano, si guarda la cita devuelve true y en caso contrario false
*/
bool modificarCita(string apellidos,   vector<Cita>citas){
  vector<Cita>::iterator it;
  Cita c;
  RegistroCita reg;
  string fecha;
  string hora;
  bool correcto = false;
  cout<<"\nIntroduce la fecha de la cita. Debe usar el formato dd/MM/aaaa\n";
  cin>>fecha;
  if(c.setFECHA(fecha)==false){
    return false;
  }
  cout<<"\nIntroduce la hora. Debe usar el formato hh desde las 00 hasta las 24\n";
  cin>>hora;
  if(c.setHORA(hora)==false){
    return false;
  }
  if(comprobarFechaHora(fecha,hora, citas)==true){
    return false;
  }

  ifstream file("citas.txt",ios::in);
  ofstream fileAux;
  fileAux.open("auxiliar.txt",ios::out | ios::binary | ios::app);


  if(file.is_open() && fileAux.is_open()){
    for(it=citas.begin();it !=citas.end(); it++){
      strcpy(reg.apellidos, (*it).getAPELL().c_str());

      if(reg.apellidos==apellidos){
        strcpy(reg.apellidos,(*it).getAPELL().c_str());
        strcpy(reg.fecha, fecha.c_str());
        strcpy(reg.hora, hora.c_str());

        fileAux<<reg.apellidos<<' ';
        fileAux<<reg.fecha<<' ';
        fileAux<<reg.hora<<'\n';
        correcto = true;
      }else{
          strcpy(reg.apellidos,(*it).getAPELL().c_str());
          strcpy(reg.fecha,(*it).getFECHA().c_str());
          strcpy(reg.hora,(*it).getHORA().c_str());

          fileAux<<reg.apellidos<<' ';
          fileAux<<reg.fecha<<' ';
          fileAux<<reg.hora<<'\n';
        }
      }
  }else{
    cout<<"Problema con el fichero de texto";
  }
  file.close();
  fileAux.close();
  remove("citas.txt");
  rename("auxiliar.txt", "citas.txt");
  return correcto;
}







/**
    @fn bool comprobarExistenciaDNI(string dni, vector<Paciente>pacientes)
    @brief Comprueba si el DNI introducido esta ya registrado
    @param dni
    @param pacientes

    @return Devuelve un booleano, true si se encuentra y false en caso contrario
*/

bool comprobarExistenciaDNI(string dni, vector<Paciente>pacientes){
  bool correcto = false;
  ifstream file("pacientes.txt", ios::in);
  vector<Paciente>::iterator it;
  RegistroPaciente reg;
  if(file.is_open()){
    for(it=pacientes.begin();it !=pacientes.end(); it++){
      strcpy(reg.dni,(*it).getDNI().c_str());
      if(reg.dni == dni){
          correcto = true;
      }
    }
  }
  return correcto;
}
/**
    @fn bool comprobarFechaHora(string fecha, string hora, vector<Cita>citas)
    @brief Comprueba si la hora y dia introducidas de la cita ya estan asignadas
    @param fecha
    @param hora
    @param citas

    @return Devuelve un booleano, true si se encuentra y false en caso contrario
*/
bool comprobarFechaHora(string fecha,string hora, vector<Cita>citas){
  bool correcto = false;
  ifstream file("citas.txt", ios::in);
  vector<Cita>::iterator it;
  RegistroCita reg;
  if(file.is_open()){
    for(it=citas.begin();it !=citas.end(); it++){
      strcpy(reg.fecha,(*it).getFECHA().c_str());
      strcpy(reg.hora,(*it).getHORA().c_str());
      if(reg.fecha==fecha && reg.hora==hora){
          correcto = true;
      }
    }
  }
  return correcto;
}
/**
    @fn bool comprobarApellidosPaciente(string apellido, vector<Paciente>pacientes)
    @brief Comprueba si el apellido introducido esta ya registrado en la base de datos de pacientes
    @param apellido
    @param pacientes

    @return Devuelve un booleano, true si se encuentra y false en caso contrario
*/
bool comprobarApellidosPaciente(string apellido, vector<Paciente>pacientes){
  bool correcto = false;
  ifstream file("pacientes.txt", ios::in);
  vector<Paciente>::iterator it;
  RegistroPaciente reg;
  if(file.is_open()){

    for(it=pacientes.begin();it !=pacientes.end(); it++){
      strcpy(reg.apellidos,(*it).getAPELL().c_str());
      if(reg.apellidos==apellido){
          correcto = true;
      }
    }
  }
  return correcto;
}
/**
    @fn bool comprobarApellidos(string apellido, vector<Cita>citas)
    @brief Comprueba si el apellido introducido esta ya registrado en la base de datos de citas
    @param apellido
    @param citas

    @return Devuelve un booleano, true si se encuentra y false en caso contrario
*/
bool comprobarApellidos(string apellido, vector<Cita>citas){
  bool correcto = false;
  ifstream file("citas.txt", ios::in);
  vector<Cita>::iterator it;
  RegistroCita reg;
  if(file.is_open()){
    for(it=citas.begin();it !=citas.end(); it++){
      strcpy(reg.apellidos,(*it).getAPELL().c_str());

      if(reg.apellidos==apellido){
          correcto = true;
      }
    }
  }
  return correcto;
}/**
    @fn bool comprobarApellidosTratamientos(string apellido, vector<Tratamiento>tratamientos)
    @brief Comprueba si el apellido introducido esta ya registrado en la base de datos de tratamientos
    @param apellido
    @param tratamientos

    @return Devuelve un booleano, true si se encuentra y false en caso contrario
*/
bool comprobarApellidosTratamientos(string apellido, vector<Tratamiento>tratamientos){
  bool correcto = false;
  ifstream file("tratamientos.txt", ios::in);
  vector<Tratamiento>::iterator it;
  RegistroTratamiento reg;
  if(file.is_open()){
    for(it=tratamientos.begin();it !=tratamientos.end(); it++){
      strcpy(reg.apellidos,(*it).getAPELL().c_str());

      if(reg.apellidos==apellido){
          correcto = true;
      }
    }
  }
  return correcto;
}



/**
    @fn string getHora()
    @brief obtiene la hora del dia actual

    @return Devuelve la fecha del dia actual
*/
string getFecha()
{
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);

    stringstream ss_year;
    ss_year << timePtr->tm_year+1900;
    string Year = ss_year.str();

    stringstream ss_month;
    ss_month << timePtr->tm_mon+1;
    string Month = ss_month.str();
    if(atoi(Month.c_str()) < 10)
        Month = "0"+Month;

    stringstream ss_day;
    ss_day << timePtr->tm_mday;
    string Day = ss_day.str();
    if(atoi(Day.c_str()) < 10)
        Day = "0"+Day;

    string Fecha = Day+"/"+Month+"/"+Year;

    return Fecha;
}

/**
    @fn string mayusculas(string cadena)
    @brief Convierte a mayusculas todas las letras de la cadena pasada
    @param cadena
    @return Devuelve un string con las letras convertidas
*/
string mayusculas(string cadena){
	int longitud= cadena.length();
    for(int i=0; i<longitud; i++){
        cadena[i] = toupper(cadena[i]);
    }
    return cadena;
}
