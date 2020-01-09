#include "funciones.cpp"

#include <iostream>



#include "Paciente.h"
#include "Tratamiento.h"
#include "Cita.h"

using namespace std;

int main() {
  Paciente p;
  Cita c;
  Tratamiento t;
  int opc=1;
  int opc2;

  vector<Paciente>pacientes;
  vector<Cita>citas;
  vector<Tratamiento>tratamientos;


  string dni;
  string nombre;
  string apellidos;
  string fecha_nacimiento;
  string direccion;
  string historial;
  string fecha;
  string hora;
  string medicamento;
  string concentracion;
  string planificacion;
  string inicio;
  string fin;
  int res;


  do{
    opc = menu();
    fichPacientesToVect(pacientes);
    fichCitasToVect(citas);
    fichTratamientosToVect(tratamientos);
    switch(opc){
      case 1:
      /*mostrar citas*/
        mostrarListaCitas(citas);
      break;
      case 2:
        mostrarListaPacientes(pacientes);
        //void mostrarListaPacientes(getPacientes());
      break;
      case 3:
      cout<<"\n ESRIBA TODO JUNTO\n";

        cout<<"Introduce el DNI\n";
        cin>> dni;
        cout<<"\nIntroduce el Nombre\n";
        cin>>nombre;
        cout<<"\nIntroduce el Apellido del paciente\n";
        cin>>apellidos;
        cout<<"\nIntroduce el Dirección\n";
        cin>>direccion;
        cout<<"\nIntroduce el Fecha Nacimiento. Debe usar el formato dd/MM/aaaa\n";
        cin>>fecha_nacimiento;
        cout<<"\nIntroduce el Historial\n";
        cin>>historial;

        if(anadirDatosPacientes(dni, nombre, apellidos, fecha_nacimiento, direccion, historial, pacientes)==true){
          cout<<"Se ha anadido el paciente correctamente";
        }else{
          cout<<"NO se ha anadido el paciente, compruebe que introduce los datos correctamente";
        }
      break;
      case 4:
      cout<<"Introduce el apellido del paciente que deseas mostrar\n";
      cin>>apellidos;
      apellidos=mayusculas(apellidos);

        if(mostrarPaciente(apellidos, pacientes, citas, tratamientos)==true){
          cout<<"Paciente mostrado con exito\n";
          opc2= 1;
        }else{
          cout<<"No existe ningun paciente con dicho apellido\n";
          opc2=0;
        }
        while(opc2!=0){
          fichPacientesToVect(pacientes);
          fichCitasToVect(citas);
          fichTratamientosToVect(tratamientos);
          opc2= menu2();
          switch(opc2){
            case 1:
            /*modificar datos del paciente*/

              if(modificarPaciente(apellidos, pacientes)==true){
                cout<<"\nPaciente modificado con exito\n";
              }else{
                cout<<"\nNo existe ningun paciente con dicho apellido\n";
              }
              fichPacientesToVect(pacientes);

            break;
            case 2:
            /*añadir historial*/

              if(modificarHistorial(apellidos, pacientes)==true){
                cout<<"\nHistorial modificado con exito\n";
              }else{
                cout<<"\nNo existe ningun paciente con dicho apellido\n";
              }
              fichPacientesToVect(pacientes);

            break;
            case 3:
            /*añadir cita*/

            cout<<"\nIntroduce la fecha de la cita. Debe usar el formato dd/MM/aaaa\n";
            cin>>fecha;
            cout<<"\nIntroduce la hora. Debe usar el formato hh desde las 00 hasta las 24\n";
            cin>>hora;
            if(anadirDatosCitas(apellidos, fecha, hora, citas)==true){
              cout<<"Se ha anadido la cita correctamente";
            }else{
              cout<<"NO se ha anadido la cita correctamente";
            }

            break;
            case 4:
            /*mover cita*/

              if(modificarCita(apellidos, citas)==true){
                cout<<"\n Cita modificada con exito\n";
              }else{
                cout<<"NO se ha modificado la cita correctamente";
              }
              fichPacientesToVect(pacientes);

            break;
            case 5:
            /*cancelar cita*/

            cout<<"¿Estas seguro de que quieres cancelar esta cita? Si=1 / No=2\n";
            cin>>res;
            if(res==1){
              if(borrarCita(apellidos, citas)==true){
                cout<<"\nCita borrada con exito\n";
              }else{
                cout<<"\nNo existe ningun paciente con dicho apellido\n";
              }
              fichCitasToVect(citas);
            }
            break;
            case 6:
            /*añadir tratamiento*/
            cout<<"\n ESRIBA TODO JUNTO\n";

            cout<<"Introduce el nombre del medicamento\n";
            cin>>medicamento;
            cout<<"\nIntroduce la dosis del medicamento\n";
            cin>>concentracion;
            cout<<"\nIntroduce la dosis al dia\n";
            cin>>planificacion;
            cout<<"\nIntroduce la fecha de inicio formato dd/MM/aaaa\n";
            cin>>inicio;
            cout<<"\nIntroduce la fecha de finalizacion formato dd/MM/aaaa\n";
            cin>>fin;
            if(anadirDatosTratamientos(apellidos, medicamento, concentracion, planificacion, inicio, fin, tratamientos)==true){
              cout<<"Se ha anadido el tratamiento correctamente";
            }else{
              cout<<"NO se ha anadido el tratamiento correctamente";
            }
            break;
            case 7:
            /*cancelar tratamiento*/

            cout<<"¿Estas seguro de que quieres cancelar este tratamiento? Si=1 / No=2\n";
            cin>>res;
            if(res==1){
              if(borrarTratamiento(apellidos, tratamientos)==true){
                cout<<"\nTratamiento cancelado con exito\n";
              }else{
                cout<<"\nNo existe ningun paciente con dicho apellido\n";
              }
              fichTratamientosToVect(tratamientos);
            }
            break;
            case 0:
              opc2=0;
            break;
          }
        }
      break;
      case 5:
      /*borrar paciente*/
      cout<<"Introduce el apellido del paciente que deseas eliminar\n";
      cin>>apellidos;
      cout<<"¿Estas seguro de que quieres borrar este paciente? Si=1 / No=2\n";
      cin>>res;
      apellidos=mayusculas(apellidos);
      if(res==1){
        if(borrarPaciente(apellidos, pacientes, citas, tratamientos)==true){
          cout<<"\nPaciente borrado con exito\n";
        }else{
          cout<<"\nNo existe ningun paciente con dicho apellido\n";
        }
        fichPacientesToVect(pacientes);
      }
      break;
      case 0:
      printf("Sale\n");
      opc=0;
      break;
    }
  }while(opc!=0);


  return 0;
}
