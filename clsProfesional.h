#ifndef CLSPROFESIONAL_H_INCLUDED
#define CLSPROFESIONAL_H_INCLUDED

class Profesional{
private:
    char nombre[40];
    char apellido[40];
    int matricula;
    Fecha fechaIngreso;
    int especialidad;
    bool estado;
public:
    void Cargar(){
        cout<<"NOMBRE: ";
        cargarCadena(nombre, 40);
        cout<<"APELLIDO: ";
        cargarCadena(apellido, 40);
        cout<<"MATRICULA: ";
        cin>>matricula;
        cout<<"FECHA DE INGRESO: "<<endl;
        fechaIngreso.Cargar();
        cout<<"ESPECIALIDAD: ";
        cin>>especialidad;
        estado=true;
    }
    void Mostrar(){
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: "<<apellido<<endl;
        cout<<"MATRICULA: "<<matricula<<endl;
        fechaIngreso.Mostrar();
        cout<<"ESPECIALIDAD: "<<especialidad<<endl;
    }

    void setEstado(bool e){estado=e;}

    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    int getMatricula(){return matricula;}
    Fecha getFecha(){return fechaIngreso;}
    int getEspecialidad(){return especialidad;}
    bool getEstado(){return estado;}

};

#endif // CLSPROFESIONAL_H_INCLUDED
