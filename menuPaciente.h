#ifndef MENUPACIENTE_H_INCLUDED
#define MENUPACIENTE_H_INCLUDED

void agregarPaciente();
void darBajaPaciente();
void listarPaciente();
void buscarPaciente();
void modificarPaciente();

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
        cout<<"1. DAR DE ALTA PACIENTE"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. LISTAR PACIENTE"<<endl;
        rlutil::locate(50, 14);
        cout<<"3. BUSCAR PACIENTE"<<endl;
        rlutil::locate(50, 16);
        cout<<"4. DAR DE BAJA PACIENTE"<<endl;
        rlutil::locate(50, 18);
        cout<<"5. MODIFICAR PACIENTE"<<endl;
        rlutil::locate(50, 20);
        cout<<"0. VOLVER MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 22);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 22);
        cin>>num;
        system("cls");
        switch(num){
            case 1: agregarPaciente();
                break;
            case 2: listarPaciente();
                break;
            case 3: buscarPaciente();
                break;
            case 4: darBajaPaciente();
                break;
            case 5: modificarPaciente();
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

void darBajaPaciente(){
    Paciente *obj;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();

    obj = new Paciente [cant];
    if(obj==nullptr){exit(-1);}
    cargarMemoriaDinamicaPaciente(obj, cant);

    int dni;
    cout<<"DNI: ";
    cin>>dni;

    for(int i=0;i<cant;i++){
        if(dni == obj[i].getDni() && obj[i].getEstado()){
            obj[i].setEstado(false);
            arc.modificarRegistro(obj[i], i);
            cout<<"DADO DE BAJA CON EXITO"<<endl;
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
    cout<<"INGRESE DNI: ";
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

void modificarPaciente(){
    Paciente *obj;
    ArchivoPaciente arc;

    int cant = arc.contarRegistros();
    obj = new Paciente [cant];

    cargarMemoriaDinamicaPaciente(obj, cant);

    int opc;
    int dni;
    int obraSocial, numTelefono;
    char direccion[100], email[50];
    Fecha f;
    bool band=false;

    interfazLogin();
    rlutil::locate(49, 13);
    cout<<"INGRESE DNI: ";
    rlutil::locate(62, 13);
    cin>>dni;

    for(int i=0;i<cant;i++){
        if(dni == obj[i].getDni() && obj[i].getEstado()){
            while(band==false){
                system("cls");
                interfaz();
                rlutil::locate(57, 7);
                cout<<"QUE QUIERE MODIFICAR?"<<endl;
                rlutil::locate(57, 10);
                cout<<"1. FECHA DE NACIMIENTO"<<endl;
                rlutil::locate(57, 12);
                cout<<"2. OBRA SOCIAL"<<endl;
                rlutil::locate(57, 14);
                cout<<"3. DIRECCION"<<endl;
                rlutil::locate(57, 16);
                cout<<"4. NUMERO DE TELEFONO"<<endl;
                rlutil::locate(57, 18);
                cout<<"5. EMAIL"<<endl;
                rlutil::locate(57, 20);
                cout<<"0. CANCELAR CAMBIO"<<endl;
                rlutil::locate(57, 22);
                cout<<"INGRESE UNA OPCION: ";
                rlutil::locate(77, 22);
                cin>>opc;
                system("cls");
                interfazLogin();
                switch(opc){
                    case 1:
                        rlutil::locate(49, 11);
                        cout<<"FECHA DE NACIMIENTO: ";
                        f.CargarConInterfaz();
                        obj[i].setFecha(f);
                        band=true;
                        break;
                    case 2:
                        rlutil::locate(49, 13);
                        cout<<"OBRA SOCIAL: ";
                        rlutil::locate(61, 13);
                        cin>>obraSocial;
                        obj[i].setObraSocial(obraSocial);
                        band=true;
                        break;
                    case 3:
                        rlutil::locate(49, 13);
                        cout<<"DIRECCION: ";
                        rlutil::locate(49, 14);
                        cargarCadena(direccion, 100);
                        obj[i].setDireccion(direccion);
                        band=true;
                        break;
                    case 4:
                        rlutil::locate(49, 13);
                        cout<<"NUMERO DE TELEFONO: ";
                        rlutil::locate(49, 14);
                        cin>>numTelefono;
                        obj[i].setTelefono(numTelefono);
                        band=true;
                        break;
                    case 5:
                        rlutil::locate(49, 13);
                        cout<<"EMAIL: ";
                        rlutil::locate(56, 13);
                        cargarCadena(email, 50);
                        obj[i].setEmail(email);
                        band=true;
                        break;
                    case 0:
                        system("cls");
                        return;
                        break;
                    default:
                        interfazLogin();
                        rlutil::locate(49, 13);
                        cout<<"ERROR DE OPCION"<<endl;
                        system("pause");
                        break;
                }
            }
            arc.modificarRegistro(obj[i], i);
            interfazLogin();
            rlutil::locate(49, 13);
            cout<<"MODIFICADO CON EXITO"<<endl;
            delete[] obj;
            return;
        }
    }
    system("cls");
    interfazLogin();
    rlutil::locate(50, 13);
    cout<<"NO SE ENCONTRO EL DNI"<<endl;
    delete[] obj;
    return;
}

#endif // MENUPACIENTE_H_INCLUDED
