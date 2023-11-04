#pragma once
#include <string.h>
#include"Fecha.h"

class Compra{

private:
int _NumeroCompra;
int _NumeroDeProveedor; //1 al 60
int _CodigoDeMaterial;
char _CodigoDeObra[5];
int _Cantidad;
int _Importe;
Fecha _Fecha;
bool _Activo;

public:
    // Getters
    int getNumeroCompra() const { return _NumeroCompra; }
    int getNumeroDeProveedor() const { return _NumeroDeProveedor; }
    int getCodigoDeMaterial() const { return _CodigoDeMaterial; }
    const char* getCodigoDeObra() const { return _CodigoDeObra; }
    int getCantidad() const { return _Cantidad; }
    int getImporte() const { return _Importe; }
    Fecha getFecha() const {return _Fecha;}
    bool getsActivo() const { return _Activo; }

    // Setters
    void setNumeroCompra(int numeroCompra) { _NumeroCompra = numeroCompra; }
    void setNumeroDeProveedor(int numeroDeProveedor) { _NumeroDeProveedor = numeroDeProveedor; }
    void setCodigoDeMaterial(int codigoDeMaterial) { _CodigoDeMaterial = codigoDeMaterial; }
    void setCodigoDeObra(const char *codigoObra) { strcpy(_CodigoDeObra, codigoObra); }
    void setCantidad(int cantidad) { _Cantidad = cantidad; }
    void setImporte(int importe) { _Importe = importe; }
    void setFecha(Fecha fecha){_Fecha = fecha;}
    void setActivo(bool activo) { _Activo = activo; }

    void Cargar();
    void Mostrar();

    void MostrarArchivo();
    void CargarArchivo();
    void CrearArchivo(int tam);
    void LimpiarARchivo();
    Compra leerRegistro(int pos);
    int contarRegistros();

//SOBRACARGA DE OPERADORES
    bool operator<(int tamanio) {
        if(this->_Importe > tamanio) {
            return true;
        } else {
            return false;
        }
    }

    bool operator<(const Compra &obj) {
        if(this->_Importe < obj._Importe) {
            return true;
        } else {
            return false;
        }
    }
    bool operator==(const int *obj) {
        if(this->_Importe == *obj) {
            return true;
        } else {
            return false;
        }
    }

    bool operator==(const Compra &obj) {
        if(this->_Importe == obj._Importe) {
            return true;
        } else {
            return false;
        }
    }


//CONSTRUCTORES
    Compra(){}

    Compra(int _Importe) : _Importe(_Importe) {}
};