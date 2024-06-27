#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void copiaSeguridad();
void recibrCopiaSeguridad();
void registrarse();
void listarRegistros();

void menuConfiguracion(){
    int num;
    while(true){
        rlutil::setColor(rlutil::MAGENTA);
        interfaz();
        rlutil::setColor(rlutil::YELLOW);
        rlutil::locate(53, 7);
        cout<<"CONFIGURACION"<<endl;
        rlutil::locate(50, 10);
        cout<<"1. COPIA DE SEGUIRDAD GENERAL"<<endl;
        rlutil::locate(50, 12);
        cout<<"2. RECIBIR COPIA DE SEGURIDAD GENERAL"<<endl;
        rlutil::locate(50, 14);
        cout<<"3. REGISTRARSE"<<endl;
        rlutil::locate(50, 16);
        cout<<"4. LISTAR REGISTROS"<<endl;
        rlutil::locate(50, 20);
        cout<<"INGRESE OPCION: "<<endl;
        rlutil::locate(66, 20);
        cin>>num;
        system("cls");
        switch(num){
            case 1: copiaSeguridad();
                break;
            case 2: recibrCopiaSeguridad();
                break;
            case 3: registrarse();
                break;
            case 4: listarRegistros();
                break;
            case 0:
                return;
            default:
                cout<<"ERROR"<<endl;
                break;
        }
        rlutil::locate(0, 256);
        system("pause");
        system("cls");
    }
}

///REALIZA UN BACKUP PARA TODAS LAS CLASES

void copiaSeguridadPacientes() {
    FILE *archivoEntrada = fopen("pacientes.dat", "rb");
    FILE *archivoSalida = fopen("pacientes.bkp", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

void copiaSeguridadProfesional() {
    FILE *archivoEntrada = fopen("profesionales.dat", "rb");
    FILE *archivoSalida = fopen("profesionales.bkp", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

void copiaSeguridadTurnos() {
    FILE *archivoEntrada = fopen("turnos.dat", "rb");
    FILE *archivoSalida = fopen("turnos.bkp", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

///RECIBE EL BACKUP DE CADA CLASE

void recibirCopiaSeguridadPacientes() {
    FILE *archivoEntrada = fopen("pacientes.bkp", "rb");
    FILE *archivoSalida = fopen("pacientes.dat", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

void recibirCopiaSeguridadProfesional() {
    FILE *archivoEntrada = fopen("profesionales.bkp", "rb");
    FILE *archivoSalida = fopen("profesionales.dat", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

void recibirCopiaSeguridadTurnos() {
    FILE *archivoEntrada = fopen("turnos.bkp", "rb");
    FILE *archivoSalida = fopen("turnos.dat", "wb");

    if (archivoEntrada == NULL || archivoSalida == NULL) {
        cout << "Error al abrir los archivos." <<endl;
        return;
    }

   int byte;
    while ((byte = fgetc(archivoEntrada)) != EOF) {
        fputc(byte, archivoSalida);
    }

    fclose(archivoEntrada);
    fclose(archivoSalida);
}

///FUNCIONES

void copiaSeguridad(){
    copiaSeguridadPacientes();
    copiaSeguridadProfesional();
    copiaSeguridadTurnos();
    rlutil::locate(50, 7);
    cout<<"COPIADO CON EXITO"<<endl;
}

void recibrCopiaSeguridad(){
    recibirCopiaSeguridadPacientes();
    recibirCopiaSeguridadProfesional();
    recibirCopiaSeguridadTurnos();
    rlutil::locate(50, 7);
    cout<<"PEGADO CON EXITO"<<endl;
}

void registrarse(){
    Login obj, obj2;
    char opc;

    obj.Cargar();

    FILE *p=fopen("Login.dat","rb");
    if(p==NULL)return;
    while(fread(&obj2, sizeof obj2, 1, p)){
        if(obj==obj2){
            system("cls");
            rlutil::setColor(rlutil::RED);
            interfazLogin();
            rlutil::locate(50, 12);
            cout<<"YA EXISTE UN NOMBRE DE USUARIO"<<endl;
            rlutil::locate(50, 13);
            cout<<" Y/O CONTRASENA"<<endl;
            return;
        }
    }
    rlutil::locate(50, 12);
    cout<<"DESEA REGISTRARSE?   "<<endl;
    rlutil::locate(50, 13);
    cout<<"1: SI"<<"    "<<"2: NO       "<<endl;
    rlutil::locate(50, 14);
    cout<<"                          "<<endl;
    while(true){
        rlutil::setColor(rlutil::WHITE);
        rlutil::locate(50, 14);
        cin>>opc;
        switch(opc){
        case 1:
            if(grabarLogin(obj)){
                rlutil::setColor(rlutil::GREEN);
                interfazLogin();
                rlutil::locate(50, 13);
                cout<<"REGISTRADO CON EXITO"<<endl;
            }else{
                rlutil::setColor(rlutil::RED);
                interfazLogin();
                rlutil::locate(50, 13);
                cout<<"ERROR AL REGISTRARSE"<<endl;
            }
            return;
        break;

        case 2: return;
            break;

        default:
            rlutil::locate(50, 13);
            rlutil::setColor(rlutil::RED);
            cout<<"INGRESE NUEVAMENTE LA OPCION"<<endl;
            break;
        }
    }
}

void listarRegistros(){
    Login obj2;

    FILE *p=fopen("Login.dat","rb");
    if(p==NULL)return;
    while(fread(&obj2, sizeof obj2, 1, p)){
        cout<<obj2.getUsuario()<<endl;
        cout<<obj2.getContrasena()<<endl;
        cout<<endl;
    }
}

#endif // CONFIGURACION_H_INCLUDED
