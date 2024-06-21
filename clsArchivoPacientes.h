#ifndef CLSARCHIVOPACIENTES_H_INCLUDED
#define CLSARCHIVOPACIENTES_H_INCLUDED

class ArchivoPacientes{
private:
    char nombre[40];
public:
    ArchivoPacientes(const char *n = "pacientes.dat"){strcpy(nombre, n);}
    void limpiarArchivo();
    void grabarRegistro(Paciente obj);
    void modificarRegistro(Paciente obj, int pos);
    Paciente leerRegistro(int pos);
    void listarArchivo();
    int contarRegistros();
    int buscarRegistro(int num);
};

void ArchivoPacientes::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}
void ArchivoPacientes::grabarRegistro(Paciente obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}
void ArchivoPacientes::modificarRegistro(Paciente obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}
Paciente ArchivoPacientes::leerRegistro(int pos){
    Paciente obj;
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        return obj;
        }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}
void ArchivoPacientes::listarArchivo(){
    int cant=contarRegistros();
    Paciente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}
int ArchivoPacientes::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Paciente);
}
int ArchivoPacientes::buscarRegistro(int dni){
    int cant=contarRegistros();
    Paciente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(dni==obj.getDni()){
            return i;
        }
    }
    return -1;
}

#endif // CLSARCHIVOPACIENTES_H_INCLUDED
