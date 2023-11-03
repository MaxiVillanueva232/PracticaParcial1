#pragma once
#include <string.h>

class Material{

private:
    int _CodigoMaterial;
    char _Nombre[30];
    char _Marca[30];
    int _Tipo;
    int _Precio;
    bool _Activo;

public:
    // Getters
    int getCodigoMaterial() const { return _CodigoMaterial; }
    const char* getNombre() const { return _Nombre; }
    const char* getMarca() const { return _Marca; }
    int getTipo() const { return _Tipo; }
    int getPrecio() const { return _Precio; }
    bool getActivo() const { return _Activo; }

    // Setters
    void setCodigoMaterial(int codigoMaterial) { _CodigoMaterial = codigoMaterial; }
    void setNombre(const char *nombre) { strcpy(_Nombre, nombre); }
    void setMarca(const char *marca) { strcpy(_Marca, marca); }
    void setTipo(int tipo) { _Tipo = tipo; }
    void setPrecio(int precio) { _Precio = precio; }
    void setActivo(bool activo) { _Activo = activo; }

    void Cargar();
    void Mostrar();

    void MostrarArchivo();
    void CargarArchivo();
    void CrearArchivo(int tam);
    void LimpiarARchivo();

    Material leerRegistro(int pos);
    int contarRegistros();

};
