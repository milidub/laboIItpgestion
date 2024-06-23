#ifndef CONFIGURACION_H_INCLUDED
#define CONFIGURACION_H_INCLUDED

void copiaSeguridad();
void recibrCopiaSeguridad();
void registrarse();

void menuConfiguracion(){
    int num;
    while(true){
        cout<<" ========================="<<endl;
        cout<<"|      CONFIGURACION     |"<<endl;
        cout<<" ========================="<<endl;
        cout<<"1. COPIA DE SEGURIDAD DE TODAS LAS CLASES"<<endl;
        cout<<"2. RECIBIR COPIA DE SEGURIDAD DE TODAS LAS CLASES"<<endl;
        cout<<"3. REGISTRARSE           "<<endl;
        cout<<"========================="<<endl;
        cout<<"0. SALIR"<<endl;
        cout<<"INGRESE OPCION: ";
        cin>>num;
        system("cls");
        switch(num){
            case 1: copiaSeguridad();
                break;
            case 2: recibrCopiaSeguridad();
                break;
            case 3: registrarse();
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
    cout<<"SE HA GUARDADO A LA COPIA DE SEGURIDAD"<<endl;
}

void recibrCopiaSeguridad(){
    recibirCopiaSeguridadPacientes();
    recibirCopiaSeguridadProfesional();
    recibirCopiaSeguridadTurnos();
    cout<<"SE HA RECIBIDO LA COPIA DE SEGURIDAD CON EXITO"<<endl;
}

void registrarse(){
    Login obj, obj2;
    bool bandera=false;
    obj.Cargar();
    FILE *p=fopen("Login.dat","rb");
    if(p==NULL)return;
    while(fread(&obj2, sizeof obj2, 1, p)){
        if(obj==obj2){
            cout<<"YA EXISTE UN NOMBRE DE USUARIO Y CONTRASENA"<<endl;
            return;
        }
    }
    if(grabarLogin(obj)){
        cout<<"REGISTRADO CON EXITO"<<endl;
    }
    else{
        cout<<"ERROR AL REGISTRARSE"<<endl;
    }
}

#endif // CONFIGURACION_H_INCLUDED
