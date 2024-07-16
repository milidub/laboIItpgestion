#include <iostream>
#include <cstring>
#include <stdlib.h>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "CargarCadena.h"
#include "interfaz.h"
#include "clsFecha.h"
#include "clsPaciente.h"
#include "clsArchivoPaciente.h"
#include "menuPaciente.h"
#include "clsProfesional.h"
#include "clsArchivoProfesional.h"
#include "menuProfesional.h"
#include "clsTurno.h"
#include "clsArchivoTurno.h"
#include "menuTurno.h"
#include "clsLogin.h"
#include "Configuracion.h"
#include "Reportes.h"


int main()
{
    Logeo();
    system("cls");
    int num;
    while(true){
        rlutil::setColor(rlutil::GREY);
        interfaz();
        rlutil::setColor(rlutil::WHITE);
        FechaActual fa;
        rlutil::locate(53, 6);
        cout<<"FECHA: ";
        fa.Mostrar();
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
        cout<<"5. REPORTES"<<endl;
        rlutil::locate(50, 20);
        cout<<"0. SALIR"<<endl;
        rlutil::locate(50, 22);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 22);
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
            case 5: MenuReportes();
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
