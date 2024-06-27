#ifndef MENUPACIENTE_H_INCLUDED
#define MENUPACIENTE_H_INCLUDED

void agregarPaciente();
void darAltaPaciente();
void listarPaciente();
void buscarPaciente();

Paciente cargarMemoriaDinamicaPaciente(Paciente *obj, int tam){
    ArchivoPaciente arc;
    for(int i=0;i<tam;i++){
        obj[i] = arc.leerRegistro(i);
    }
    return *obj;
}

void menuPaciente(){
    int num;
    while(true){
        rlutil::setColor(rlutil::CYAN);
        interfaz();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(53, 7);
        cout<<"MENU PACIENTES"<<endl;
        rlutil::locate(50, 10);
        cout<<"1. AGREGAR PACIENTE"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. LISTAR PACIENTE"<<endl;
        rlutil::locate(50, 14);
        cout<<"3. BUSCAR PACIENTE"<<endl;
        rlutil::locate(50, 16);
        cout<<"4. DAR DE ALTA PACIENTE"<<endl;
        rlutil::locate(50, 18);
        cout<<"0. VOLVER MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 20);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 20);
        cin>>num;
        system("cls");
        switch(num){
            case 1: agregarPaciente();
                break;
            case 2: listarPaciente();
                break;
            case 3: darAltaPaciente();
                break;
            case 4: buscarPaciente();
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

bool compararPaciente(Paciente obj){
    Paciente obj2;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj2 = arc.leerRegistro(i);
        if(obj.getDni() == obj2.getDni()){
            return true;
        }
    }
    return false;
}

void agregarPaciente(){
    Paciente obj;
    ArchivoPaciente arc;
    obj.Cargar();
    if(compararPaciente(obj)){
        cout<<"YA EXISTE UN DNI PACIENTE EN EL ARCHIVO"<<endl;
        cout<<"NO SE GUARDADA EL ARCHIVO"<<endl;
        return;
    }else{
        arc.grabarRegistro(obj);
    return;
    }
}

void darAltaPaciente(){
    Paciente *obj;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();
    obj = new Paciente[cant];
    if(obj==nullptr)exit(-1);

    cargarMemoriaDinamicaPaciente(obj, cant);

    int dni;
    cout<<"DNI: ";
    cin>>dni;

    for(int i=0;i<cant;i++){
        if(dni == obj[i].getDni() && obj[i].getEstado()){
            obj[i].setEstado(false);
            arc.grabarRegistro(obj[i]);
            cout<<"GRABADO CON EXITO"<<endl;
            delete[] obj;
            return;
        }
    }
    cout<<"NO SE PUDO ENCONTRAR"<<endl;
    delete[] obj;
}

void listarPaciente(){
    Paciente *obj;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();
    obj = new Paciente [cant];
    if(obj==nullptr)exit(-1);

    cargarMemoriaDinamicaPaciente(obj, cant);

    for(int i=0;i<cant;i++){
        if(obj[i].getEstado()){
            obj[i].Mostrar();
            cout<<endl;
        }
    }
    delete[] obj;
}

void buscarPaciente(){
    Paciente *obj;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();
    obj = new Paciente [cant];
    if(obj==nullptr)exit(-1);

    cargarMemoriaDinamicaPaciente(obj, cant);

    int dni;
    cout<<"DNI: ";
    cin>>dni;

    for(int i=0;i<cant;i++){
        if(dni == obj[i].getDni() && obj[i].getEstado()){
            obj[i].Mostrar();
            cout<<endl;
            delete[] obj;
            return;
        }
    }
    delete[] obj;
}

#endif // MENUPACIENTE_H_INCLUDED
