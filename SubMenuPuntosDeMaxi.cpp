#include <iostream>
#include <string.h>
#include "FuncionesGlobales.h"

using namespace std;

#include "Obra.h"
#include "Material.h"
#include "Compra.h"
#include "Proveedores.h"
#include"ArchivoNuevoPunto1.h"
#include "SubMenuPuntosDeMaxi.h"


void SubMenuPuntosDeMaxi()
{

    int opcion;
    ///////////////////////////////////////////////////////////////////////////
    while (true)
    {

        system("cls");
        cout << "Opcion 1 ---> Punto1" << endl;
        cout << "Opcion 2 ---> Punto2" << endl;
        cout << "Opcion 3 ---> Punto3" << endl;
        cout << "Opcion 4 ---> Punto4" << endl;
        cout << "Opcion 0 ---> salir" << endl;
        cin >> opcion;
        switch (opcion)
        {
            /*************************************************************************/
        case 1:
        {
            BorrarTexto();
            system("cls");
            // 1 Generar un archivo con las obras en ejecución que no hayan realizado compras este año.
            // Por cada obra que no hizo compras este año se debe
            // registrar el código de obra, la dirección de la obra y la provincia de la obra.

            _Punto1();
            system("pause");
        }
        break;
            /*************************************************************************/
        case 2:
        {
            BorrarTexto();
            system("cls");
            _Punto2();
            system("pause");
        }
        break;
            /*************************************************************************/
        case 3:
        {
            BorrarTexto();
            system("cls");
            _Punto3();
            system("pause");
        }
        break;
            /*************************************************************************/
        case 4:
        {
            BorrarTexto();
            system("cls");
            int valor1,valor2;
            cout<<"ingrese importe"<<endl;
            cin>>valor1;
            cout<<"ingrese Registro que quiere comparar con su importe Registrado"<<endl;
            cin>>valor2;

            _Punto4(valor1,valor2);
            system("pause");
        }
        break;
            /*************************************************************************/
        case 0:
        {
            system("cls");
            cout << "Fin del programa" << endl;
            system("pause");
            system("cls");
            return;
        }
        break;
            /*************************************************************************/
        default:
        {
            system("cls");
            cout << "Valor ingresado no existe" << endl;
            system("pause");
        }
        break;
            /*************************************************************************/
        }
    }
    ///////////////////////////////////////////////////////////////////////////
}

///////////////////////////////////////////////////////////////////////////
void _Punto1(){

    Obra objO;
    Compra objC;
    ArchivoNuevoPunto1 objAN;

    objAN.LimpiarArchivo(); //Primero lo limpia para que no tenga basura

    int tam = objO.contarRegistros();
    int tam2 = objC.contarRegistros();
    for (int i = 0; i < tam; i++)
    {
        bool contador2023 = false;
        objO = objO.leerRegistro(i);
        if ((objO.getActivo() == true) && (objO.getEstadoDeEjecion() == 3))
        {
            for (int j = 0; j < tam2; j++)
            {
                objC = objC.leerRegistro(j);
                if ((objC.getsActivo() == true) && (strcmp(objC.getCodigoDeObra(), objO.getCodigoObra()) == 0))
                {
                    if (objC.getFecha().getAnio() == 2023)
                    {
                        contador2023 = true;
                    }
                }
            }
        }
        if (contador2023 == true)
        {
            objAN.setCodigoDeObra(objO.getCodigoObra());
            objAN.setDireccionDeObra(objO.getDireccion());
            objAN.setProvinciaDeObra(objO.getProvincia());
            if(objAN.grabarRegistro()){}//cout<<"Perfeto PA"<<endl;}
        }
    }
    objAN.MostrarArchivo();
    objAN.LimpiarArchivo(); //y al final tambien lo borro para RE UTILIZARLO en otro punto
}
///////////////////////////////////////////////////////////////////////////
void _Punto2(){
    Obra objO;

    int vec[24]={0};

    int tam;
    tam = objO.contarRegistros();

    for(int i=0; i<tam; i++){
        objO = objO.leerRegistro(i);
        if(objO.getActivo()==true){
            vec[(objO.getProvincia()-1)]++;
        }
    }

    int max,pos,band=false;

    for(int i=0; i<24; i++){

        if(band==false){
            max=vec[i];
            pos=i+1;
            band=true;
        }else if((band==true)&&(vec[i]>max)){
            max=vec[i];
            pos=i+1;
        }

    }
    MostrarVector(vec,24);

    cout<<"El estado de ejecucicion "<<pos<<endl<<"tiene un total de: "<<max<<endl;

}
///////////////////////////////////////////////////////////////////////////
void _Punto3(){
    proveedores objM;
    int tam=0;
    char direccion[100];

    tam = objM.contarRegistros();



    //int *vecPrecio = new int[tam];
    int *vecNumProveedor = new int[tam];

    //char **vecNombre = new char*[tam];
    char **vecDireccion = new char*[tam];

    //cargue todos incluyendo los que son Activo == falso

    for(int i=0; i<tam; i++){
        objM = objM.leerRegistro(i);
        vecNumProveedor[i]=objM.getNumeroProveedor();

        vecDireccion[i] = new char[50];  // Asignar memoria para cada vecDireccion[i]
        strcpy(vecDireccion[i], objM.getDireccion());
    }

    cout<<"ingrese Direccion: ";
    cargarCadena(direccion,100);
    cout<<endl;

    //aqui calcula todo el archivo, excepto los que son Activo == falso

    for(int i=0; i<tam; i++){
        objM = objM.leerRegistro(i);

        if((strcmp((vecDireccion[i]), direccion) == 0)&&(objM.getActivo()==true)){
            cout<<"Numero de proveedor: "<<vecNumProveedor[i]<<endl;
            //cout<<"Direccion: "<<vecDireccion[i]<<endl<<endl;
        }
    }
    
//LIBERAR MEMORIA DINAMICA

    delete vecNumProveedor;

    for(int i=0; i<tam; i++){
    delete [] vecDireccion[i];
    }
}
///////////////////////////////////////////////////////////////////////////
void _Punto4(int valor,int registro){


Compra objC;

objC = objC.leerRegistro(registro-1);

Compra ObjC2(objC.getImporte());

//cout<<"importe:"<<objC.getImporte()<<endl;

if((ObjC2==-1)|(objC.getsActivo()==false)){
    cout<<"Registro Ingresado no existe"<<endl;
}else{

if(ObjC2<valor){
    cout<<"El mayor es el Registro "<<registro<<" con un valor del objeto "<<(objC.getImporte())<<endl;
}else{
    cout<<"El mayor es valor Ingresado es: "<<valor<<endl;
}



}

}
///////////////////////////////////////////////////////////////////////////