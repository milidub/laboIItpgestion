#include <iostream>
#include <cstring>
#include <ctime>

using namespace std;

#include "rlutil.h"
#include "cargarCadena.h"
#include "clsFecha.h"
#include "clsPacientes.h"
#include "clsProfesional.h"
#include "clsTurnos.h"
#include "clsLogin.h"
#include "clsArchivoPacientes.h"
#include "clsArchivoProfesional.h"
#include "Configuracion.h"

///FUNCIONES

///PACIENTES

void registrarPaciente(){
    Paciente obj;
    ArchivoPacientes arc;
    obj.Cargar();
    arc.grabarRegistro(obj);
}

void buscarPaciente(){
    Paciente obj;
    ArchivoPacientes arc;

    int cant = arc.contarRegistros();
    int dni;
    cout<<"INGRESE EL DNI DEL PACIENTE: ";
    cin>>dni;

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(dni==obj.getDni() && obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
}

void darDeAltaPaciente(){
    Paciente obj;
    ArchivoPacientes arc;

    int cant = arc.contarRegistros();
    int dni;
    cout<<"INGRESE EL DNI DEL PACIENTE: ";
    cin>>dni;

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(dni==obj.getDni() && obj.getEstado()){
            obj.setEstado(false);
            cout<<endl;
        }
    }
}

void listarPacientes(){
    Paciente obj;
    ArchivoPacientes arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        obj.Mostrar();
        cout<<endl;
    }
}

///PROFESIONAL

void registrarProfesional(){
    Profesional obj;
    ArchivoProfesional arc;
    obj.Cargar();
    arc.grabarRegistro(obj);
}

void buscarProfesional(){
    Profesional obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();
    int matricula;
    cout<<"INGRESE LA MATRICULA DEL PROFESIONAL: ";
    cin>>matricula;

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(matricula==obj.getMatricula() && obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
}

void darDeBajaProfesional(){
    Profesional obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();
    int matricula;
    cout<<"INGRESE LA MATRICULA DEL PROFESIONAL: ";
    cin>>matricula;

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(matricula==obj.getMatricula() && obj.getEstado()){
            obj.setEstado(false);
            cout<<endl;
        }
    }
}

void listarProfesional(){
    Profesional obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        obj.Mostrar();
        cout<<endl;
    }
}

///TURNOS

void menuPaciente(){
    while(true){
        int num;
        cout<<"MENU PACIENTE"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. REGISTRAR PACIENTE"<<endl;
        cout<<"2. BUSCAR PACIENTE"<<endl;
        cout<<"3. DAR DE ALTA PACIENTE"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cin>>num;
        system("cls");
        switch(num){
        case 1: registrarPaciente();
            break;
        case 2: buscarPaciente();
            break;
        case 3: darDeAltaPaciente();
            break;
        case 0:
            return;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

void menuProfesional(){
    while(true){
        int num;
        cout<<"MENU PROFESIONAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. REGISTRAR PROFESIONAL"<<endl;
        cout<<"2. BUSCAR PROFESIONAL"<<endl;
        cout<<"3. DAR DE BAJA PROFESIONAL"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cin>>num;
        system("cls");
        switch(num){
        case 1: registrarProfesional();
            break;
        case 2: buscarProfesional();
            break;
        case 3: darDeBajaProfesional();
            break;
        case 0:
            return;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

///TURNOS

void registrarTurno(){
    Turno obj;
    ArchivoTurno arc;

    Paciente paciente;
    ArchivoPaciente arcPac;
    Profesional profesional;
    ArchivoProfesional arcProf;

    int dni, matricula;
    char observacion[400];
    Fecha f;
    int hora, minuto;

    cout<<"INGRESE DNI: ";
    cin>>dni;

    int cant=arcPac.contarRegistros();
    for(int i=0;i<cant;i++){
        paciente = arcPac.leerRegistro(i);
        if(paciente.getDni()==dni){
            obj.setDni(dni);
            break;
        }else{
            cout<<"NO SE ENCONTRO EL DNI DEL PACIENTE"<<endl;
            return;
        }
    
    cout<<"INGRESE MATRICULA DEL PROFESIONAL: ";
    cin>>matricula;

    int cant=arcPro.contarRegistros();
    for(int i=0;i<cant;i++){
        profesional = arcPro.leerRegistro(i);
        if(profesional.getMatricula()==matricula){
            obj.setMatricula(matricula)
            break;
        }else{
            cout<<"NO SE ENCONTRO LA MATRICULA DEL PROFESIONAL"<<endl;
            return;
        }
    cout<<"OBSERVACION: ";
    cargarCadena(observacion, 400);
    obj.setObservaciones(observacion);
    cout<<"FECHA: "<<endl;
    f.Cargar();
    obj.setFecha(f);
    cout<<"HORA: ";
    cin>>hora;
    obj.setHora(hora);
    cout<<"MINUTO: ";
    cin>>minuto;
    obj.setMinuto(minuto);
    obj.setEstado(true);

    arc.grabarRegistro(obj);
}

void menuTurnos(){
    while(true){
        int num;
        cout<<"MENU TURNOS"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. REGISTRAR TURNO"<<endl;
        cout<<"2. LISTAR TURNO"<<endl;
        cout<<"3. BUSCAR TURNO"<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cin>>num;
        system("cls");
        switch(num){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 0:
            return;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

///CONFIGURACION



void configuracion(){
    int num;
    while(true){
        cout<<"CONFIGURACION"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. "<<endl;
        cout<<"2. "<<endl;
        cout<<"3. "<<endl;
        cout<<"4. "<<endl;
        cout<<"0. VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cin>>num;
        system("cls");
        switch(num){
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 0:
            return;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
}

int main()
{
    FechaActual f;
    /// Login obj;
    int num;
    while(true){
        f.MostrarFecha();
        f.MostrarHora();
        cout<<endl;
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"=============="<<endl;
        cout<<"1. MENU PACIENTE"<<endl;
        cout<<"2. MENU PROFESIONAL"<<endl;
        cout<<"3. MENU TURNOS"<<endl;
        cout<<"4. CONFIGURACION"<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"=============="<<endl;
        cin>>num;
        system("cls");
        switch(num){
        case 1: menuPaciente();
            break;
        case 2: menuProfesional();
            break;
        case 3: menuTurnos();
            break;
        case 4: menuConfiguracion();
            break;
        case 0:
            return 0;
        default:
            break;
        }
        system("pause");
        system("cls");
    }
    return 0;
}
