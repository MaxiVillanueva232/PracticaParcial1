#include<iostream>

using namespace std;

#include"menu.h"
#include"FuncionesGlobales.h"
#include"Obra.h"
#include"Material.h"
#include"Compra.h"
#include"Proveedores.h"
#include"SubMenuPuntosDeGabi.h"
#include"SubMenuPuntosDeMaxi.h"

void Menu(){


//VARIABLES CREADAS
int opcion;
Obra ClassO;
Material ClassM;
Compra ClassC;
proveedores ClassP;

    while(true){

        system("cls");

        cout<<"Opcion 1 ---> Cargar archivo obras.dat"<<endl; //ab
        cout<<"Opcion 2 ---> Cargar archivo materiales.dat"<<endl; //ab
        cout<<"Opcion 3 ---> Cargar archivo compras.dat"<<endl; //ab
        cout<<"Opcion 4 ---> Cargar archivo proveedores.dat"<<endl<<endl; //ab

        cout<<"Opcion 5 ---> Crear archivo obras.dat"<<endl; //wb
        cout<<"Opcion 6 ---> Crear archivo materiales.dat"<<endl; //wb
        cout<<"Opcion 7 ---> Crear archivo compras.dat"<<endl; //wb
        cout<<"Opcion 8 ---> Crear archivo proveedores.dat"<<endl<<endl; //wb

        cout<<"Opcion 9 ---> Mostrar archivo obras.dat"<<endl; //rb
        cout<<"Opcion 10 ---> Mostrar archivo materiales.dat"<<endl; //rb
        cout<<"Opcion 11 ---> Mostrar archivo compras.dat"<<endl; //rb
        cout<<"Opcion 12 ---> Mostrar archivo proveedores.dat"<<endl<<endl; //rb

        cout<<"Opcion 13 ---> Limpiar archivo obras.dat"<<endl; //rb
        cout<<"Opcion 14 ---> Limpiar archivo materiales.dat"<<endl; //rb
        cout<<"Opcion 15 ---> Limpiar archivo compras.dat"<<endl; //rb
        cout<<"Opcion 16 ---> Limpiar archivo proveedores.dat"<<endl<<endl; //rb

        cout<<"Opcion 17 ---> Puntos de Gabi"<<endl;
        cout<<"Opcion 18 ---> Puntos de Maxi"<<endl<<endl;

        cout<<"Opcion 0 ---> Salir"<<endl;

        cin>>opcion;
//////////////////////////////////////////////////////////////////
        switch (opcion)
        {
/****************************************************************/
        case 1:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

            for(int i=0; i<opcion; i++){
                ClassO.CargarArchivo();
            }

        }break;
/****************************************************************/
        case 2:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

            for(int i=0; i<opcion; i++){
                ClassM.CargarArchivo();
            }

        }break;
/****************************************************************/
        case 3:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

            for(int i=0; i<opcion; i++){
                ClassC.CargarArchivo();
            }

        }break;
/****************************************************************/
        case 4:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

            for(int i=0; i<opcion; i++){
                ClassP.cargar();
                if(ClassP.grabarEnDisco()){
                        cout<<"Archivo Cargado"<<endl;}

            }

        }break;
/****************************************************************/
        case 5:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

                ClassO.CrearArchivo(opcion);
        }break;
/****************************************************************/
        case 6:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

                ClassM.CrearArchivo(opcion);
        }break;
/****************************************************************/
        case 7:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

                ClassC.CrearArchivo(opcion);
        }break;
/****************************************************************/
        case 8:{
            cout<<"Ingrese cuantos registros quiere cargar"<<endl;
            cin>>opcion;

                ClassP.CrearArchivo(opcion);
        }break;
/****************************************************************/
        case 9:{
            BorrarTexto();
            system("cls");
            ClassO.MostrarArchivo();
            system("pause");
        }break;
/****************************************************************/
        case 10:{
            BorrarTexto();
            system("cls");
            ClassM.MostrarArchivo();
            system("pause");
        }break;
/****************************************************************/
        case 11:{
            BorrarTexto();
            system("cls");
            ClassC.MostrarArchivo();
            system("pause");
        }break;
/****************************************************************/
        case 12:{
            BorrarTexto();
            system("cls");
            int pos=-1;
            while(ClassP.leerDeDisco(pos++)==true){
                ClassP.mostrar();
            }
            system("pause");
        }break;
/****************************************************************/
        case 13:{
            BorrarTexto();
            system("cls");
            ClassO.LimpiarARchivo();
            cout<<"Se borro Correctamente"<<endl;
            system("pause");
        }break;
/****************************************************************/
        case 14:{
            BorrarTexto();
            system("cls");
            ClassM.LimpiarARchivo();
            cout<<"Se borro Correctamente"<<endl;
            system("pause");
        }break;
/****************************************************************/
        case 15:{
            BorrarTexto();
            system("cls");
            ClassC.LimpiarARchivo();
            cout<<"Se borro Correctamente"<<endl;
            system("pause");
        }break;
/****************************************************************/
        case 16:{
            BorrarTexto();
            system("cls");
            ClassP.LimpiarArchivo();
            cout<<"Se borro Correctamente"<<endl;
            system("pause");
        }break;
/****************************************************************/
        case 17:{
            BorrarTexto();
            system("cls");
            SubMenuPuntosDeGabi();
            system("pause");
        }break;
/****************************************************************/
        case 18:{
            BorrarTexto();
            system("cls");
            SubMenuPuntosDeMaxi();
            system("pause");
        }break;
/****************************************************************/
        case 0:{
            system("cls");
            cout<<"Fin del programa"<<endl;
            system("pause");
            system("cls");
            return;
        }break;
/****************************************************************/
        default:{
            system("cls");
            cout<<"Valor ingresado no existe"<<endl;
            system("pause");
        }break;
/****************************************************************/
        }
//////////////////////////////////////////////////////////////////


    }
}