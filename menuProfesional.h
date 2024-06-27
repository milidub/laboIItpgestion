#ifndef MENUPROFESIONAL_H_INCLUDED
#define MENUPROFESIONAL_H_INCLUDED

void agregarProfesional();
void darBajaProfesional();
void listarProfesional();
void buscarProfesional();

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
        cout<<"1. AGREGAR PROFESIONAL"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. LISTAR PROFESIONALES"<<endl;
        rlutil::locate(50, 14);
        cout<<"3. BUSCAR PROFESIONAL"<<endl;
        rlutil::locate(50, 16);
        cout<<"4. DAR DE BAJA PROFESIONAL"<<endl;
        rlutil::locate(50, 18);
        cout<<"0. VOLVER MENU PRINCIPAL"<<endl;
        rlutil::locate(50, 20);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 20);
        cin>>num;
        system("cls");
        switch(num){
            case 1: agregarProfesional();
                break;
            case 2: listarProfesional();
                break;
            case 3: darBajaProfesional();
                break;
            case 4: buscarProfesional();
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
            arc.grabarRegistro(obj[i]);
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

#endif // MENUPROFESIONAL_H_INCLUDED
