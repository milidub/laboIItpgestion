class Login{
    private:
        char usuario[40];
        char contrasena[40];
    public:
        void Cargar(){
            cout<<"USUARIO: ";
            cargarCadena(usuario,40);
            cout<<"CONTRASENA: ";
            cargarCadena(contrasena,40);
        }
        char *getUsuario(){return usuario;}
        char *getContrasena(){return contrasena;}

        bool operator==(Login obj){
            if(strcmp(obj.getUsuario(), usuario)==0){
                if(strcmp(obj.getContrasena(), contrasena)==0){
                    return true;
                }
                return false;
            }
            return false;
        }

};

bool grabarLogin(Login l){
    FILE *p=fopen("Login.dat","ab");
    if(p==NULL)return false;
    fwrite(&l, sizeof l, 1, p);
    fclose(p);
    return true;
}



#endif // CLSLOGIN_H_INCLUDED
