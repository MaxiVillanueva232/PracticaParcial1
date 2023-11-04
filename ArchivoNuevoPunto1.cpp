#include<iostream>

using namespace std;

#include "ArchivoNuevoPunto1.h"
#include "FuncionesGlobales.h"
/******************************************************************/
void ArchivoNuevoPunto1::setCodigoDeObra(const char *codigoDeObra)
{
    strcpy(_codigoDeObra, codigoDeObra);
}
/******************************************************************/
void ArchivoNuevoPunto1::setDireccionDeObra(const char *direccionDeObra)
{
    strcpy(_direccionDeLaObra, direccionDeObra);
}
void ArchivoNuevoPunto1::setProvinciaDeObra(int provincia)
{
    _provinciaDeLaObra = provincia;
}
bool ArchivoNuevoPunto1::grabarRegistro()
/******************************************************************/
{
    FILE *p;
    p = fopen("ArchivoNuevoPunto1.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool escribio = fwrite(this, sizeof(ArchivoNuevoPunto1), 1, p);
    fclose(p);
    return escribio;
}
/******************************************************************/
void ArchivoNuevoPunto1::Mostrar()
{
    cout << "Codigo De Obra: " << _codigoDeObra << endl;
    cout << "Direccion de Obra: " << _direccionDeLaObra << endl;
    cout << "Numero de Provincia: " << _provinciaDeLaObra << endl;
}
/******************************************************************/
void ArchivoNuevoPunto1::Cargar()
{
    cout << "Codigo De Obra: ";
    cargarCadena(_codigoDeObra, 5);
    cout << "Direccion de Obra: " << _direccionDeLaObra << endl;
    cargarCadena(_direccionDeLaObra, 30);
    cout << "Numero de Provincia: ";
    cin >> _provinciaDeLaObra;
}
/******************************************************************/
void ArchivoNuevoPunto1::LimpiarArchivo(){
FILE *p;
ArchivoNuevoPunto1 ClassM;

p=fopen("ArchivoNuevoPunto1.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

fclose(p);
}
/******************************************************************/
void ArchivoNuevoPunto1::MostrarArchivo(){
ArchivoNuevoPunto1 ClassM;
FILE *p;

p=fopen("ArchivoNuevoPunto1.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (ArchivoNuevoPunto1),1,p)==1){
ClassM.Mostrar();
cout<<endl;
}
fclose(p);
}
/******************************************************************/