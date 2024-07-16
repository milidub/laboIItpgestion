#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED

void TurnosPorDniPaciente(){

    Turno turno;
    ArchivoTurno arcTur;

    int dni;
    int cant=arcTur.contarRegistros();
    cout<<"INGRESE DNI DEL PACIENTE"<<endl;
    cin>>dni;

    for(int i=0;i<cant;i++){
        turno = arcTur.leerRegistro(i);
        if(dni == turno.getDniPaciente()){
            turno.Mostrar();
            cout<<endl;
        }
    }
}

void CantidadPacientesYProfesionales(){
    Paciente obj1;
    ArchivoPaciente arc1;

    int dni=0;
    char nombre[50]={}, apellido[50]={};
    bool estado=false;;

    Profesional obj2;
    ArchivoProfesional arc2;

    int matricula=0;

    int cant1 = arc1.contarRegistros();
    int cantidadPacientesActivos=0;
    int cant2 = arc2.contarRegistros();
    int cantidadProfesionalesActivos=0;

    rlutil::setColor(rlutil::CYAN);
    cout<<"========="<<endl;
    cout<<"PACIENTES"<<endl;
    cout<<"========="<<endl;

    for(int i=0;i<cant1;i++){
        obj1 = arc1.leerRegistro(i);
        dni = obj1.getDni();
        strcpy(nombre, obj1.getNombre());
        strcpy(apellido, obj1.getApellido());
        estado = obj1.getEstado();

        cout<<"DNI: "<<dni<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: "<<apellido<<endl;
        cout<<"ESTADO: ";
        if(estado){cout<<"ACTIVO"<<endl; cantidadPacientesActivos++;}
        else{cout<<"INNACTIVO"<<endl;}

        cout<<endl;
    }

    rlutil::setColor(rlutil::BLUE);
    cout<<"========="<<endl;
    cout<<"PROFESIONALES"<<endl;
    cout<<"========="<<endl;

    for(int i=0;i<cant2;i++){
        obj2 = arc2.leerRegistro(i);
        dni = obj2.getMatricula();
        strcpy(nombre, obj2.getNombre());
        strcpy(apellido, obj2.getApellido());
        estado = obj2.getEstado();

        cout<<"MATRICULA: "<<matricula<<endl;
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: "<<apellido<<endl;
        cout<<"ESTADO: ";
        if(estado){cout<<"ACTIVO"<<endl; cantidadProfesionalesActivos++;}
        else{cout<<"INNACTIVO"<<endl;}

        cout<<endl;
    }

    rlutil::setColor(rlutil::WHITE);
    cout<<"CANTIDAD DE PACIENTES ACTIVOS: ";
    rlutil::setColor(rlutil::CYAN);
    cout<<cantidadPacientesActivos<<endl;
    rlutil::setColor(rlutil::WHITE);
    cout<<"CANTIDAD DE PROFESIONALES ACTIVOS: ";
    rlutil::setColor(rlutil::BLUE);
    cout<<cantidadProfesionalesActivos<<endl;
    rlutil::setColor(rlutil::WHITE);
}

void MenuReportes(){
    int num;
    while(true){
        rlutil::setColor(rlutil::CYAN);
        interfaz();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(53, 7);
        cout<<"REPORTES"<<endl;
        rlutil::locate(50, 10);
        cout<<"1. LISTAR TURNOS POR DNI PACIENTE"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. PACIENTES Y PROFESIONALES"<<endl;
        rlutil::locate(50, 14);
        cout<<""<<endl;
        rlutil::locate(50, 16);
        cout<<""<<endl;
        rlutil::locate(50, 18);
        cout<<""<<endl;
        rlutil::locate(50, 20);
        cout<<"0. VOLVER MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 22);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 22);
        cin>>num;
        system("cls");
        switch(num){
            case 1: TurnosPorDniPaciente();
                break;
            case 2: CantidadPacientesYProfesionales();
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 0:
                return;
            default:
                cout<<"ERROR"<<endl;
                break;
        }
        system("pause");
        system("cls");

    }
    return;
}

#endif // REPORTES_H_INCLUDED
