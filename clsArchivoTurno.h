#ifndef CLSARCHIVOTURNO_H_INCLUDED
#define CLSARCHIVOTURNO_H_INCLUDED

class ArchivoTurno{
    private:
        char nombre[30];
    public:
        ArchivoTurno(const char *n="turnos.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Turno obj);
        void modificarRegistro(Turno obj, int pos);
        Turno leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
};

void ArchivoTurno::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoTurno::grabarRegistro(Turno obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoTurno::modificarRegistro(Turno obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Turno ArchivoTurno::leerRegistro(int pos){
    Turno obj;
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoTurno::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Turno);
}

void ArchivoTurno::listarArchivo(){
    int cant=contarRegistros();
    Turno obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoTurno::buscarRegistro(int num){
    int cant=contarRegistros();
    Turno obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getDniPaciente()){
            return i;
        }
    }
    return -1;
}

#endif // CLSARCHIVOTURNO_H_INCLUDED
