#ifndef MENUTURNO_H_INCLUDED
#define MENUTURNO_H_INCLUDED

///TURNO:
/**
matriculaProfesional [Recibe el parametro de la matricula Profesional]
dniPaciente [recibe el parametro del dni Paciente]
observaciones (char)
fecha (FECHA)
hora (int)
minuto (int)
estado (bool)
*/

void agregarTurno();
void listarTurno();
void darBajaTurno();
void buscarTurnoPorDniPaciente();
void CambiarTurno();

void menuTurno(){
    int num;
    while(true){
        rlutil::setColor(rlutil::RED);
        interfaz();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(53, 7);
        cout<<"MENU TURNOS"<<endl;
        rlutil::locate(50, 9);
        cout<<"1. AGREGAR TURNO"<<endl;
        rlutil::locate(50, 11);
        cout<<"2. LISTAR TURNOS"<<endl;
        rlutil::locate(50, 13);
        cout<<"3. DAR DE BAJA TURNO"<<endl;
        rlutil::locate(50, 15);
        cout<<"4. MOSTRAR TURNO POR DNI PACIENTE"<<endl;
        rlutil::locate(50, 17);
        cout<<"5. CAMBIAR FECHA DEL TURNO"<<endl;
        rlutil::locate(50, 19);
        cout<<"0. VOLVER MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 21);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 21);
        cin>>num;
        system("cls");
        switch(num){
            case 1: agregarTurno();
                break;
            case 2: listarTurno();
                break;
            case 3: darBajaTurno();
                break;
            case 4: buscarTurnoPorDniPaciente();
                break;
            case 5: CambiarTurno();
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

bool verDni(int dni){
    Paciente obj;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(dni==obj.getDni() && obj.getEstado()){
            return true;
        }
    }
    return false;
}

bool verMatricula(int matricula){
    Profesional obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(matricula==obj.getMatricula() && obj.getEstado()){
            return true;
        }
    }
    return false;
}

///box2d

void agregarTurno(){
    Turno obj;
    ArchivoTurno arc;

    int dni, matricula;
    char observacion[400];
    Fecha f;
    int hora, minuto;

    cout<<"INGRESE DNI: ";
    cin>>dni;
    if(verDni(dni)==false){
        cout<<"NO SE ENCONTRO UN DNI PACIENTE"<<endl;
        return;
    }else{
        obj.setDniPaciente(dni);
    }
    cout<<"INGRESE MATRICULA: ";
    cin>>matricula;
    if(verMatricula(matricula)==false){
        cout<<"NO SE ENCONTRO UNA MATRICULA DE PROFESIONAL"<<endl;
        return;
    }else{
        obj.setMatriculaProfesional(matricula);
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

void listarTurno(){
    Turno *obj;
    ArchivoTurno arc;

    int cant = arc.contarRegistros();
    obj = new Turno [cant];
    if(obj==nullptr)exit(-1);

    for(int i=0;i<cant;i++){
        obj[i] = arc.leerRegistro(i);
    }

    for(int i=0;i<cant;i++){
        if(obj[i].getEstado()){
            obj[i].Mostrar();
            cout<<endl;
        }
    }
    delete[] obj;
}

void darBajaTurno(){
    Turno obj;
    ArchivoTurno arc;

    int dni;
    cout<<"INGRESE DNI DEL PACIENTE: ";
    cin>>dni;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(dni==obj.getDniPaciente() && obj.getEstado()){
            obj.setEstado(false);
            arc.modificarRegistro(obj, i);
            cout<<"MODIFICADO CON EXITO"<<endl;
            return;
        }
    }
}

void buscarTurnoPorDniPaciente(){
    Turno obj;
    ArchivoTurno arc;

    int dni;
    cout<<"INGRESE DNI DEL PACIENTE: ";
    cin>>dni;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(dni==obj.getDniPaciente() && obj.getEstado()){
            obj.Mostrar();
            cout<<endl;
        }
    }
}

void CambiarTurno(){
    Turno obj;
    ArchivoTurno arc;
    Fecha f;

    int dni, hora, minuto;
    cout<<"INGRESE DNI DEL PACIENTE: ";
    cin>>dni;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj = arc.leerRegistro(i);
        if(dni==obj.getDniPaciente() && obj.getEstado()){
            f.Cargar();
            obj.setFecha(f);
            cout<<"HORA: ";
            cin>>hora;
            obj.setHora(hora);
            cout<<"MINUTO: ";
            cin>>minuto;
            obj.setMinuto(minuto);
            arc.modificarRegistro(obj, i);
            cout<<"MODIFICADO CON EXITO"<<endl;
            return;
        }
    }
}

#endif // MENUTURNO_H_INCLUDED
