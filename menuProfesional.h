#ifndef MENUPROFESIONAL_H_INCLUDED
#define MENUPROFESIONAL_H_INCLUDED

void agregarProfesional();
void darBajaProfesional();
void listarProfesional();
void buscarProfesional();
void modificarProfesional();

Profesional cargarMemoriaDinamicaProfesional(Profesional *obj, int tam){
    ArchivoProfesional arc;
    for(int i=0;i<tam;i++){
        obj[i] = arc.leerRegistro(i);
    }
    return *obj;
}

void menuProfesional(){
    int num;
    while(true){
        rlutil::setColor(rlutil::BLUE);
        interfaz();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(53, 7);
        cout<<"MENU PROFESIONALES"<<endl;
        rlutil::locate(50, 10);
        cout<<"1. DAR DE ALTA PROFESIONAL"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. LISTAR PROFESIONALES"<<endl;
        rlutil::locate(50, 14);
        cout<<"3. BUSCAR PROFESIONAL"<<endl;
        rlutil::locate(50, 16);
        cout<<"4. DAR DE BAJA PROFESIONAL"<<endl;
        rlutil::locate(50, 18);
        cout<<"5. MODIFICAR PROFESIONAL"<<endl;
        rlutil::locate(50, 20);
        cout<<"0. VOLVER MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 22);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 22);
        cin>>num;
        system("cls");
        switch(num){
            case 1: agregarProfesional();
                break;
            case 2: listarProfesional();
                break;
            case 3: buscarProfesional();
                break;
            case 4: darBajaProfesional();
                break;
            case 5: modificarProfesional();
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

bool compararProfesional(Profesional obj){
    Profesional obj2;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();

    for(int i=0;i<cant;i++){
        obj2 = arc.leerRegistro(i);
        if(obj.getMatricula() == obj2.getMatricula()){
            return true;
        }
    }
    return false;
}

void agregarProfesional(){
    Profesional obj;
    ArchivoProfesional arc;
    obj.Cargar();
    if(compararProfesional(obj)){
        cout<<"YA EXISTE MATRICULA PROFESIONAL EN EL ARCHIVO"<<endl;
        cout<<"NO SE PUDO GUARDAR EL ARCHIVO"<<endl;
        return;
    }
    arc.grabarRegistro(obj);
}

void darBajaProfesional(){
    Profesional *obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();
    obj = new Profesional[cant];
    if(obj==nullptr)exit(-1);

    cargarMemoriaDinamicaProfesional(obj, cant);

    int matricula;
    cout<<"MATRICULA: ";
    cin>>matricula;

    for(int i=0;i<cant;i++){
        if(matricula == obj[i].getMatricula() && obj[i].getEstado()){
            obj[i].setEstado(false);
            arc.modificarRegistro(obj[i], i);
            cout<<"GRABADO CON EXITO"<<endl;
            delete[] obj;
            return;
        }
    }
    cout<<"NO SE PUDO ENCONTRAR"<<endl;
    delete[] obj;
}

void listarProfesional(){
    Profesional *obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();
    obj = new Profesional [cant];
    if(obj==nullptr)exit(-1);

    cargarMemoriaDinamicaProfesional(obj, cant);

    for(int i=0;i<cant;i++){
        if(obj[i].getEstado()){
            obj[i].Mostrar();
            cout<<endl;
        }
    }
    delete[] obj;
}

void buscarProfesional(){
    Profesional *obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();
    obj = new Profesional[cant];
    if(obj==nullptr)exit(-1);

    cargarMemoriaDinamicaProfesional(obj, cant);

    int matricula;
    cout<<"MATRICULA: ";
    cin>>matricula;

    for(int i=0;i<cant;i++){
        obj[i] = arc.leerRegistro(i);
        if(matricula == obj[i].getMatricula() && obj[i].getEstado()){
            obj[i].Mostrar();
            delete[] obj;
            return;
        }
    }
    delete[] obj;
}

void modificarProfesional(){
    Profesional *obj;
    ArchivoProfesional arc;

    int cant = arc.contarRegistros();
    obj = new Profesional [cant];

    cargarMemoriaDinamicaProfesional(obj, cant);

    int opc;
    int matricula;
    int especialidad;
    char numTelefono[20];
    char direccion[100], email[50], nombre[50], apellido[50];
    Fecha f;
    bool band=false;

    cout<<"INGRESE DNI: ";
    cin>>matricula;

    for(int i=0;i<cant;i++){
        if(matricula == obj[i].getMatricula() && obj[i].getEstado()){
            while(band==false){
                system("cls");
                interfaz();
                rlutil::locate(57, 7);
                cout<<"QUE QUIERE MODIFICAR?"<<endl;
                rlutil::locate(57, 10);
                cout<<"1. FECHA DE INGRESO"<<endl;
                rlutil::locate(57, 11);
                cout<<"1. FECHA DE INGRESO"<<endl;
                rlutil::locate(57, 12);
                cout<<"2. OBRA ESPECIALIDAD"<<endl;
                rlutil::locate(57, 13);
                cout<<"3. DIRECCION"<<endl;
                rlutil::locate(57, 14);
                cout<<"4. NUMERO DE TELEFONO"<<endl;
                rlutil::locate(57, 15);
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
                        rlutil::locate(51, 12);
                        cout<<"NOMBRE: ";
                        rlutil::locate(59, 12);
                        cargarCadena(nombre, 50);
                        obj[i].setNombre(nombre);
                        rlutil::locate(51, 14);
                        cout<<"APELLIDO: ";
                        rlutil::locate(61, 14);
                        cargarCadena(apellido, 50);
                        obj[i].setApellido(apellido);
                        band=true;
                        break;
                    case 2:
                        rlutil::locate(49, 11);
                        cout<<"FECHA DE INGRESO: ";
                        f.CargarConInterfaz();
                        obj[i].setFecha(f);
                        band=true;
                        break;
                    case 3:
                        rlutil::locate(48, 13);
                        cout<<"ESPECIALIDAD: ";
                        rlutil::locate(61, 13);
                        cin>>especialidad;
                            if(especialidad<1 || especialidad>4){
                                while(true){
                                rlutil::locate(48, 13);
                                cout<<"INGRESE NUEVAMENTE LA ESPECIALIDAD: "<<endl;
                                rlutil::locate(50, 14);
                                cin>>especialidad;
                                if(especialidad>0 && especialidad <5){
                                    break;
                                }
                            }
                        }
                        obj[i].setEspecialidad(especialidad);
                        band=true;
                        break;
                    case 4:
                        rlutil::locate(48, 13);
                        cout<<"DIRECCION: ";
                        rlutil::locate(59, 13);
                        cargarCadena(direccion, 100);
                        obj[i].setDireccion(direccion);
                        band=true;
                        break;
                    case 5:
                        rlutil::locate(48, 13);
                        cout<<"NUMERO DE TELEFONO: ";
                        rlutil::locate(68, 13);
                        cargarCadena(numTelefono, 20);
                        obj[i].setTelefono(numTelefono);
                        band=true;
                        break;
                    case 6:
                        rlutil::locate(48, 13);
                        cout<<"EMAIL: ";
                        rlutil::locate(55, 13);
                        cargarCadena(email, 50);
                        obj[i].setEmail(email);
                        band=true;
                        break;
                    case 0:
                        system("cls");
                        delete[] obj;
                        return;
                        break;
                    default:
                        rlutil::locate(48, 13);
                        cout<<"ERROR DE OPCION"<<endl;
                        break;
                }
                system("pause");
            }
            arc.modificarRegistro(obj[i], i);
            interfazLogin();
            rlutil::locate(48, 13);
            cout<<"MODIFICADO CON EXITO"<<endl;
            delete[] obj;
            return;
        }
    }
    system("cls");
    interfazLogin();
    rlutil::locate(50, 13);
    cout<<"NO SE ENCONTRO LA MATRICULA"<<endl;
    delete[] obj;
    return;
}

#endif // MENUPROFESIONAL_H_INCLUDED
