#ifndef INTERFAZ_H_INCLUDED
#define INTERFAZ_H_INCLUDED

///INTERFAZ PARA LOS MENUS

void interfaz(){
    rlutil::locate(46, 5);
    cout<<"============================================="<<endl;
    rlutil::locate(47, 6);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 7);
    cout<<"|                                        |"<<endl;
    rlutil::locate(46, 8);
    cout<<"============================================="<<endl;
    rlutil::locate(47, 9);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 10);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 11);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 12);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 13);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 14);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 15);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 16);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 17);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 18);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 19);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 20);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 21);
    cout<<"|                                        |"<<endl;
    rlutil::locate(47, 22);
    cout<<"|                                        |"<<endl;
    rlutil::locate(46, 23);
    cout<<"============================================="<<endl;

    rlutil::setColor(rlutil::WHITE);
    FechaActual fa;
    rlutil::locate(53, 6);
    cout<<"FECHA: ";
    fa.Mostrar();
}

///INTERFAZ PARA EL LOGEO

void interfazLogin(){
    rlutil::locate(47, 10);
    cout<<"==================================="<<endl;
    rlutil::locate(47, 11);
    cout<<"|                                 |"<<endl;
    rlutil::locate(47, 12);
    cout<<"|                                 |"<<endl;
    rlutil::locate(47, 13);
    cout<<"|                                 |"<<endl;
    rlutil::locate(47, 14);
    cout<<"|                                 |"<<endl;
    rlutil::locate(47, 15);
    cout<<"|                                 |"<<endl;
    rlutil::locate(47, 16);
    cout<<"==================================="<<endl;
}

#endif // INTERFAZ_H_INCLUDED
