#ifndef CLSLOGIN_H_INCLUDED
#define CLSLOGIN_H_INCLUDED

class Login{
private:
    char *usuario;
    char *contrasena;
    char *nombre;

public:
    void Logear(){
        FILE *p=fopen("UsuarioContrasena.dat","rb");
        if(p==NULL)return;
        cout<<"NOMBRE: ";
        cin>>nombre;
        while(fread(this, sizeof this, 1, p)){
            if(strcmp(nombre, usuario)==0){
                break;
            }
        }
        cout<<"CONTRASENA: ";
        cin>>nombre;
        while(fread(this, sizeof this, 1, p)){
            if(strcmp(nombre, contrasena)==0){
                break;
            }
        }
        fclose(p);
    }
};

class Registro{
private:
    char *usuario;
    char *contrasena;
    char *n;
public:
    void Registrar(){
        cout<<"NOMBRE DE USUUARIO: ";
        cin>>n;
        usuario = new char [strlen(n)];
        strcpy(usuario, n);
        cout<<"CONTRASENA: ";
        cin>>n;
        contrasena = new char [strlen(n)];
        strcpy(contrasena, n);
        cout<<"CONTRASENA OTRA VEZ: ";
        cin>>n;
        if(strcmp(n, contrasena)==0){
            cout<<"Ingresado"<<endl;
        }else{
            cout<<"No ingresado"<<endl;
        }
        system("pause");
        FILE *p=fopen("UsuarioContrasena.dat","ab");
        if(p==NULL)return;
        fwrite(this, sizeof this, 1, p);
        fclose(p);

        delete[] usuario;
        delete[] contrasena;
    }
};



#endif // CLSLOGIN_H_INCLUDED
