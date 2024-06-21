#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

class Fecha{
private:
    int dia, mes, anio;
    int minuto, hora;
public:
    Fecha(){
        dia=1;
        mes=1;
        anio=1900;
    }

    ///SE UTILIZA ESTA FUNCION PARA CARGAR LAS FECHAS DE LA CLASE PACIENTE Y PROFESIONAL
    void Cargar(){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
    }
    ///SE UTILIZA ESTA FUNCION PARA CARGAR TURNOS
    void CargarFechaYHora(){
        cout<<"DIA: ";
        cin>>dia;
        cout<<"MES: ";
        cin>>mes;
        cout<<"ANIO: ";
        cin>>anio;
        cout<<"HORA: ";
        cin>>hora;
        cout<<"MINUTO: ";
        cin>>minuto;
    }
    void Mostrar(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
    void MostrarHoraYMinuto(){
        cout<<hora<<" : "<<minuto<<endl;
    }
};

class FechaActual{
private:
    int dia, mes, anio;
    int minuto, hora;
public:
    FechaActual(){
        time_t t = time(0);
        tm* now = localtime(&t);

        dia=now->tm_mday;
        mes=now->tm_mon + 1;
        anio=now->tm_year + 1900;
        hora=now->tm_hour;
        minuto=now->tm_min;
    }
    void MostrarFecha(){
        cout<<dia<<"/"<<mes<<"/"<<anio<<endl;
    }
    void MostrarHora(){
        cout<<hora<<" : "<<minuto<<endl;
    }
};

#endif // CLSFECHA_H_INCLUDED
