
#include <iostream>
#include <string.h>
#include "FuncionesGlobales.h"

using namespace std;

#include "proveedores.h"

void proveedores::cargar()
{
    cout << " NumeroProveedor: ";
    cin >> NumeroProveedor; // (1 a 60)
    cout << "Nombre: ";
    cargarCadena(Nombre, 25);
    cout << " Telefono: ";
    cin >> Telefono;
    cout << "Direccion:";
    cargarCadena(Direccion, 30);
    cout << "Provincia: ";
    cin >> Provincia;    // (1 a 24)
    cout << " Activo: "; // (si/no)
    cin >> Activo;
}
void proveedores::mostrar()
{
    cout<<"Numero Proveedor: "<<getNumeroProveedor()<<endl;
    cout<<"Nombre: "<<getNombre()<<endl;
    cout<<"Telefono: "<<getTelefono()<<endl;
    cout<<"Direccion: "<<getDireccion()<<endl;
    cout<<"Provincia"<<getProvincia()<<endl;
    cout<<"Activo"<<getActivo()<<endl<<endl;
}
bool proveedores::leerDeDisco(int pos)
{
    FILE *p;
    p = fopen("provedores.dat", "rb");
    if (p == NULL)
    {
        cout << "error1" << endl;
        return false;
    }
    fseek(p, sizeof(proveedores) * pos, 0);
    bool leyo = fread(this, sizeof(proveedores), 1, p);
    fclose(p);
    return leyo;
}
proveedores proveedores::leerRegistro(int pos){
    proveedores reg;
    FILE *p;
    p=fopen("provedores.dat", "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof(proveedores)*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}

bool proveedores::grabarEnDisco()
{
    FILE *p;
    p = fopen("provedores.dat", "ab");
    if (p == NULL)
    {
        cout << "ERROR AL CREAR EL P" << endl;
        return false;
    }
    bool escribio = fwrite(this, sizeof(proveedores), 1, p);
    fclose(p);
    return escribio;
}
void proveedores::LimpiarArchivo()
{
    FILE *p;

    proveedores ClassM;

    p = fopen("provedores.dat", "wb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }
    fclose(p);
}
int proveedores::contarRegistros(){
        FILE *p;
        p=fopen("provedores.dat", "rb");
        if(p==NULL) return -1;
        fseek(p, 0,2);
        int tam=ftell(p);
        fclose(p);
        return tam/sizeof(proveedores);
    }

void proveedores::CrearArchivo(int tam)
{
    FILE *p;
    proveedores ClassM;

    p = fopen("provedores.dat", "wb");
    if (p == NULL)
    {
        cout << "ERROR de ARCHIVO" << endl;
        system("pause");
    }

    for (int i = 0; i < tam; i++)
    {
        ClassM.cargar();
        fwrite(&ClassM, sizeof(proveedores), 1, p);
    }

    fclose(p);
}

// Getters
int proveedores::getNumeroProveedor() { return NumeroProveedor; }
char *proveedores::getNombre() { return Nombre; }
int proveedores::getTelefono() { return Telefono; }
char *proveedores::getDireccion() { return Direccion; }
int proveedores::getProvincia() { return Provincia; }
bool proveedores::getActivo() { return Activo; }

// Setters
void proveedores::setNumeroProveedor(int numero)
{
    if (numero >= 1 && numero <= 60)
    {
        NumeroProveedor = numero;
    }
    else
    {
        // Manejar error
    }
}

void proveedores::setNombre(char *nombre)
{
    strcpy(Nombre, nombre);
}

void proveedores::setTelefono(int telefono)
{
    Telefono = telefono;
}

void proveedores::setDireccion(char *direccion)
{
    strcpy(Direccion, direccion);
}

void proveedores::setProvincia(int provincia)
{
    if (provincia >= 1 && provincia <= 24)
    {
        Provincia = provincia;
    }
    else
    {
        // Manejar error
    }
}

void proveedores::setActivo(bool activo)
{
    Activo = activo;
}