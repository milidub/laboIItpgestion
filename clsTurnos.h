#ifndef CLSTURNOS_H_INCLUDED
#define CLSTURNOS_H_INCLUDED

class Turnos{
private:
    int dni;
    int matricula;
    char *observaciones;
    Fecha fecha;
    bool estado;
public:
    void Mostrar(){
        cout<<"DNI DEL PACIENTE: "<<dni<<endl;
        cout<<"MATRICULA DEL PACIENTE QUE ATENDERA: "<<matricula<<endl;
        cout<<"FECHA PARA EL TURNO: ";
        fecha.Mostrar();
        fecha.MostrarHoraYMinuto();
    }
    void CargarFecha(){
        fecha.CargarFechaYHora();
    }
    int getDniPaciente(){return dni;}
    int getMatriculaProfesional(){return matricula;}

    void setDniPaciente(int d){dni=d;}
    void setMatriculaProfesional(int m){matricula=m;}
    void setFecha(Fecha f){fecha=f;}
    void setEstado(bool e){estado=e;}
};

bool grabarTurno(Turnos obj){
    FILE *p = fopen("turnos.dat","ab");
    if(p==NULL)return false;
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

void listarTurnos(){
    Turnos obj;
    FILE *p = fopen("turnos.dat","ab");
    if(p==NULL)return;
    while(fread(&obj, sizeof obj, 1, p)){
        obj.Mostrar();
        cout<<endl;
    }
    fclose(p);
}

void buscarYleerTurnoPaciente(int dni){
    Turnos obj;
    FILE *p=fopen("turnos.dat","rb");
    if(p==NULL){return;}
    while(fread(&obj, sizeof obj, 1, p)){
        if(dni==obj.getDniPaciente()){
            obj.Mostrar();
            fclose(p);
            cout<<endl;
            return;
        }
    }
    cout<<"TURNO INEXISTENTE"<<endl;
    fclose(p);
}

#endif // CLSTURNOS_H_INCLUDED
