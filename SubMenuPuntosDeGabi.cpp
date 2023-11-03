#include <iostream>
#include <string.h>

using namespace std;

#include "FuncionesGlobales.h"
#include "Obra.h"
#include "Material.h"
#include "Compra.h"
#include "Proveedores.h"

#include "SubMenuPuntosDeGabi.h"

void SubMenuPuntosDeGabi()
{

    int opcion;
    ///////////////////////////////////////////////////////////////////////////
    while (true)
    {

        system("cls");
        cout << "Opcion 1 ---> Punto1" << endl;
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

void Punto1()
{

    Obra objO;
    Compra objC;
    ArchivoNuevo objAN;

    objAN.LimpiarArchivo(); //Primero lo limpia para que no tenga basura

    int tam = objO.contarRegistros();
    int tam2 = objC.contarRegistros();
    for (int i = 0; i < tam; i++)
    {
        bool contador2023 = false;
        objO = objO.leerRegistro(i);
        if (objO.getActivo() == true && objO.getEstadoDeEjecion() == 3)
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