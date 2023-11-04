#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class ArchivoNuevoPunto1
{
private:
    char _codigoDeObra[5];
    char _direccionDeLaObra[30];
    int _provinciaDeLaObra;

public:
    void setCodigoDeObra(const char *);
    void setDireccionDeObra(const char *);
    void setProvinciaDeObra(int);
    bool grabarRegistro();
    void Mostrar();
    void Cargar();

    void MostrarArchivo();
    void LimpiarArchivo();
};