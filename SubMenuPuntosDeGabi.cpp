#include <iostream>
#include <string.h>

using namespace std;

#include "FuncionesGlobales.h"
#include "Obra.h"
#include "Material.h"
#include "Compra.h"
#include "Proveedores.h"

#include"SubMenuPuntosDeGabi.h"

void SubMenuPuntosDeGabi()
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

            Punto1();
            system("pause");
        }
        break;
            /*************************************************************************/
        case 2:
        {
            BorrarTexto();
            system("cls");
            Punto2();
            system("pause");
        }
        break;
            /*************************************************************************/
        case 3:
        {
            BorrarTexto();
            system("cls");
            Punto3();
            system("pause");
        }
        break;
            /*************************************************************************/
        case 4:
        {
            BorrarTexto();
            system("cls");
            float valor1,valor2;
            cout<<"ingrese superficie"<<endl;
            cin>>valor1;
            cout<<"ingrese Registro que quiere comparar con su superficie Registrado"<<endl;
            cin>>valor2;

            Punto4(valor1,valor2);
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
void Punto1()
{

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
                    if (objC.getFecha().getAnio() < 2023)
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
void Punto2(){
    Obra objO;

    int vec[5]={0};

    int tam;
    tam = objO.contarRegistros();

    for(int i=0; i<tam; i++){
        objO = objO.leerRegistro(i);
        if(objO.getActivo()==true){
            vec[(objO.getEstadoDeEjecion()-1)]++;
        }
    }

    int max,pos,band=false;

    for(int i=0; i<5; i++){

        if(band==false){
            max=vec[i];
            pos=i+1;
            band=true;
        }else if((band==true)&&(vec[i]>max)){
            max=vec[i];
            pos=i+1;
        }

    }
    MostrarVector(vec,5);

    cout<<"El estado de ejecucicion "<<pos<<" tiene un total de: "<<max<<endl;

}

///////////////////////////////////////////////////////////////////////////
void Punto3(){
    Material objM;
    int tam=0,precioUnitario;

    tam = objM.contarRegistros();

    int *vecPrecio = new int[tam];
    char **vecNombre = new char*[tam];
    

    //cargue todos incluyendo los que son Activo == falso

    for(int i=0; i<tam; i++){
        objM = objM.leerRegistro(i);
        vecPrecio[i]=objM.getPrecio();

        vecNombre[i] = new char[50];  // Asignar memoria para cada vecNombre[i]
        strcpy(vecNombre[i], objM.getNombre());
    }

    cout<<"ingrese precio unitario: ";
    cin>>precioUnitario;

    //aqui calcula todo el archivo, excepto los que son Activo == falso

    for(int i=0; i<tam; i++){
        objM = objM.leerRegistro(i);

        if(((vecPrecio[i])>precioUnitario)&&(objM.getActivo()==true)){
            cout<<"Precio: "<<vecPrecio[i]<<endl;
            cout<<"Nombre: "<<vecNombre[i]<<endl<<endl;
        }
    }


//LIBERAR MEMORIA DINAMICA
    for(int i=0; i<tam; i++){
    delete [] vecNombre[i];
    }

    delete vecPrecio;

}

///////////////////////////////////////////////////////////////////////////
void Punto4(float valor,float registro){

Obra objO1;

int pos=registro;
objO1 = objO1.leerRegistro(pos-1);


Obra objO2(objO1.getSuperficie());

if(((objO1.getSuperficie())==0)|(objO1.getActivo()==false)){
    cout<<"Registro Ingresado no existe"<<endl;
}else{

if(objO2==valor){
    cout<<"SON IGUALES"<<endl;
}else{
    cout<<"SON DISTINTOS"<<endl;
}

}

}

///////////////////////////////////////////////////////////////////////////