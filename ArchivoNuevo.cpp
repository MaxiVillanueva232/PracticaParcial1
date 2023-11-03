#include<iostream>

using namespace std;

#include "ArchivoNuevo.h"
#include "FuncionesGlobales.h"
/******************************************************************/
void ArchivoNuevo::setCodigoDeObra(const char *codigoDeObra)
{
    strcpy(_codigoDeObra, codigoDeObra);
}
/******************************************************************/
void ArchivoNuevo::setDireccionDeObra(const char *direccionDeObra)
{
    strcpy(_direccionDeLaObra, direccionDeObra);
}
void ArchivoNuevo::setProvinciaDeObra(int provincia)
{
    _provinciaDeLaObra = provincia;
}
bool ArchivoNuevo::grabarRegistro()
/******************************************************************/
{
    FILE *p;
    p = fopen("ArchivoNuevo.dat", "ab");
    if (p == NULL)
    {
        return false;
    }
    bool escribio = fwrite(this, sizeof(ArchivoNuevo), 1, p);
    fclose(p);
    return escribio;
}
/******************************************************************/
void ArchivoNuevo::Mostrar()
{
    cout << "Codigo De Obra: " << _codigoDeObra << endl;
    cout << "Direccion de Obra: " << _direccionDeLaObra << endl;
    cout << "Numero de Provincia: " << _provinciaDeLaObra << endl;
}
/******************************************************************/
void ArchivoNuevo::Cargar()
{
    cout << "Codigo De Obra: ";
    cargarCadena(_codigoDeObra, 5);
    cout << "Direccion de Obra: " << _direccionDeLaObra << endl;
    cargarCadena(_direccionDeLaObra, 30);
    cout << "Numero de Provincia: ";
    cin >> _provinciaDeLaObra;
}
/******************************************************************/
void ArchivoNuevo::LimpiarArchivo(){
FILE *p;
ArchivoNuevo ClassM;

p=fopen("ArchivoNuevo.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

fclose(p);
}
/******************************************************************/
void ArchivoNuevo::MostrarArchivo(){
ArchivoNuevo ClassM;
FILE *p;

p=fopen("ArchivoNuevo.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (ArchivoNuevo),1,p)==1){
ClassM.Mostrar();
cout<<endl;
}
fclose(p);
}
/******************************************************************/