#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

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
            FechaActual fa;
            while(true){
                bool bandera = true;
                cout<<"DIA: ";
                cin>>dia;
                if(dia<1 || dia>31){
                    cout<<"ERROR DIA"<<endl;
                    bandera = false;
                }
                cout<<"MES: ";
                cin>>mes;
                if((mes<1 || mes>12)){
                    cout<<"ERROR MES"<<endl;
                    bandera = false;
                }
                cout<<"ANIO: ";
                cin>>anio;
                if(anio<1976 || anio > fa.getAnio()){
                    cout<<"ERROR ANIO"<<endl;
                    bandera = false;
                }

                if(bandera==true){
                    break;
                }
                else{}
            }
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

#endif // CLSFECHA_H_INCLUDED
