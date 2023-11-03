#pragma once
#include <string.h>

class Obra{

private:
char _CodigoObra[5];
char _Direccion[30];
int _Provincia;
float _Superficie;
int _EstadoDeEjecion;
bool _Activo;
public:

    // Getters
    const char* getCodigoObra() const { return _CodigoObra; }
    const char* getDireccion() const { return _Direccion; }
    int getProvincia() const { return _Provincia; }
    float getSuperficie() const { return _Superficie; }
    int getEstadoDeEjecion() const { return _EstadoDeEjecion; }
    bool getActivo() const { return _Activo; }

    // Setters
    void setCodigoObra(const char *co) { strcpy(_CodigoObra, co); }
    void setDireccion(const char *d) { strcpy(_Direccion, d); }
    void setProvincia(int provincia) { _Provincia = provincia; }
    void setSuperficie(float superficie) { _Superficie = superficie; }
    void setEstadoDeEjecion(int estadoDeEjecion) { _EstadoDeEjecion = estadoDeEjecion; }
    void setActivo(bool activo) { _Activo = activo; }
    
    void Cargar();
    void Mostrar();

    void MostrarArchivo();
    void CargarArchivo();
    void CrearArchivo(int tam);
    void LimpiarARchivo();

    Obra leerRegistro(int pos);
    int contarRegistros();
};