#ifndef CLSPACIENTES_H_INCLUDED
#define CLSPACIENTES_H_INCLUDED

class Paciente{
private:
    char nombre[40];
    char apellido[40];
    Fecha fechaNacimiento;
    int dni;
    int obraSocial;
    bool estado;
public:
    void Cargar(){
        cout<<"NOMBRE: ";
        cargarCadena(nombre, 40);
        cout<<"APELLIDO: ";
        cargarCadena(apellido, 40);
        cout<<"FECHA DE NACIMIENTO: "<<endl;
        fechaNacimiento.Cargar();
        cout<<"DNI: ";
        cin>>dni;
        cout<<"OBRA SOCIAL: ";
        cin>>obraSocial;
        estado=true;
    }
    void Mostrar(){
        cout<<"NOMBRE: "<<nombre<<endl;
        cout<<"APELLIDO: ";
        cargarCadena(apellido, 40);
        cout<<"FECHA DE NACIMIENTO: ";
        fechaNacimiento.Mostrar();
        cout<<"DNI: "<<dni<<endl;
        cout<<"OBRA SOCIAL: "<<obraSocial<<endl;
    }

    void setEstado(bool e){estado = e;}

    const char *getNombre(){return nombre;}
    const char *getApellido(){return apellido;}
    Fecha getFecha(){return fechaNacimiento;}
    int getDni(){return dni;}
    int getObraSocial(){return obraSocial;}
    bool getEstado(){return estado;}

};

#endif // CLSPACIENTES_H_INCLUDED
