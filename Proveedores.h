#pragma once
#include <iostream>
#include <cstring>

using namespace std;
#include "FuncionesGlobales.h"
class proveedores
{

private:
    int NumeroProveedor; // (1 a 60)
    char Nombre[25];
    int Telefono;
    char Direccion[30];
    int Provincia; // (1 a 24)
    bool Activo;   // (si/no)
public:
    void cargar();
    void mostrar();
    bool leerDeDisco(int);
    bool grabarEnDisco();
    void LimpiarArchivo();
    int contarRegistros();
    void CrearArchivo(int);
    // Getters
    int getNumeroProveedor();
    char *getNombre();
    int getTelefono();
    char *getDireccion();
    int getProvincia();
    bool getActivo();

    // Setters
    void setNumeroProveedor(int numero);

    void setNombre(char *nombre);

    void setTelefono(int telefono);

    void setDireccion(char *direccion);
    void setProvincia(int provincia);

    void setActivo(bool activo);


};