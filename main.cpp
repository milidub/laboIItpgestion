#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "CargarCadena.h"
#include "clsFecha.h"
#include "interfaz.h"
#include "clsPacientes.h"
#include "clsArchivoPacientes.h"
#include "menuPaciente.h"
#include "clsProfesional.h"
#include "clsArchivoProfesional.h"
#include "menuProfesional.h"
#include "clsTurnos.h"
#include "clsArchivoTurnos.h"
#include "menuTurno.h"
#include "clsLogin.h"
#include "Configuracion.h"

///PORTAL DE TURNOS

///CLASES PRINCIALES A USAR:
///PACIENTE
///PROFESIONAL
///TURNOS

///ARCHIVOS A USAR:
///ARCHIVOPACIENTE (pacientes.dat)
///ARCHIVOPROFESIONAL (profesional.dat)
///ARCHIVOTURNO(turnos.dat)

///CLASES SECUNDARIAS:
///FECHA
///LOGIN (nombre y contraseña)

///CAMPOS DE LAS CLASES PRINCIPALES:
///PACIENTE:
/**
nombre (char)
apellido (char)
fecha de nacimiento (FECHA)
dni (int)
obra social (int)
direccion (char)
telefono (int)
email (char)
estado (bool)
*/

///PROFESIONAL:
/**
nombre (char)
apellido (char)
matricula (int)
fecha de ingreso (FECHA)
especialidad (int)
direccion (char)
telefono (int)
email (char)
estado (bool)
*/

///TURNO:
/**
matriculaProfesional [Recibe el parametro de la matricula Profesional]
dniPaciente [recibe el parametro del dni Paciente]
observaciones (char) [escribe las observaciones]
fecha (FECHA) [escribe y recibe el parametro de fecha]
hora (int) [recibe el parametro de hora]
minuto (int) [recibe el parametro de minuto]
estado (bool)
*/


int main()
{
    Logeo();
    system("cls");
    int num;
    while(true){
        rlutil::setColor(rlutil::GREY);
        interfaz();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(53, 7);
        cout<<"MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 10);
        cout<<"1. MENU PACIENTE"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. MENU PROFESIONAL"<<endl;
        rlutil::locate(50, 14);
        cout<<"3. MENU TURNOS"<<endl;
        rlutil::locate(50, 16);
        cout<<"4. CONFIGURACION"<<endl;
        rlutil::locate(50, 18);
        cout<<"0. SALIR"<<endl;
        rlutil::locate(50, 20);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 20);
        cin>>num;
        system("cls");
        switch(num){
            case 1: menuPaciente();
                break;
            case 2: menuProfesional();
                break;
            case 3: menuTurno();
                break;
            case 4: menuConfiguracion();
                break;
            case 0:
                return 0;
            default:
                cout<<"ERROR"<<endl;
                break;
        }
        rlutil::locate(0, 60);
        system("cls");
    }
    return 0;
}

