#include <iostream>
#include <string.h>
#include "FuncionesGlobales.h"

using namespace std;

#include "Compra.h"

/******************************************************************/
void Compra::Cargar()
{
    int NumeroCompra;
    int NumeroDeProveedor; //1 al 60
    int CodigoDeMaterial;
    char CodigoDeObra[5];
    int Cantidad;
    int Importe;
    //int dia,mes,anio;
    Fecha fecha;
    bool Activo;

    cout << "NumeroCompra: " << endl;
    cin >> NumeroCompra;
    setNumeroCompra(NumeroCompra);

    cout << "NumeroDeProveedor: " << endl;
    cin >> NumeroDeProveedor;
    setNumeroDeProveedor(NumeroDeProveedor);

    cout << "CodigoDeMaterial: " << endl;
    cin >> CodigoDeMaterial;
    setCodigoDeMaterial(CodigoDeMaterial);

    cout << "CodigoDeObra: " << endl;
    cargarCadena(CodigoDeObra, 5);
    setCodigoDeObra(CodigoDeObra);

    cout << "Cantidad: " << endl;
    cin >> Cantidad;
    setCantidad(Cantidad);

    cout << "Importe: " << endl;
    cin >> Importe;
    setImporte(Importe);

    // cout<<"DIA:";
    // cin>>dia;
    // ObjC.getFecha().setDia(dia);
    // cout<<"MES:";
    // cin>>mes;
    // ObjC.getFecha().setMes(mes);
    // cout<<"Anio:";
    // cin>>anio;
    // ObjC.getFecha().setAnio(anio);
    fecha.Cargar();
    setFecha(fecha);

    cout << "Activo: " << endl;
    cin >> Activo;
    setActivo(Activo);

}
/******************************************************************/
void Compra::Mostrar(){
    cout << "NumeroCompra: " <<getNumeroCompra()<< endl;
    cout << "NumeroDeProveedor: " <<getNumeroDeProveedor()<< endl;
    cout << "CodigoDeMaterial: " <<getCodigoDeMaterial()<< endl;
    cout << "CodigoDeObra: " <<getCodigoDeObra()<< endl;
    cout << "Cantidad: " <<getCantidad()<< endl;
    cout << "Importe: " <<getImporte()<< endl;
    getFecha().Mostrar();
    cout << "Activo: " <<getsActivo()<< endl;
}
/******************************************************************/
void Compra::MostrarArchivo(){
Compra ClassM;
FILE *p;

p=fopen("compras.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Compra),1,p)==1){
ClassM.Mostrar();
cout<<endl;
}
fclose(p);
}
/******************************************************************/
void Compra::CrearArchivo(int tam){
FILE *p;
Compra ClassM;

p=fopen("compras.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

for(int i=0; i<tam; i++){
ClassM.Cargar();
fwrite(&ClassM,sizeof (Compra),1,p);
}

fclose(p);

}
/******************************************************************/
void Compra::LimpiarARchivo(){
FILE *p;
Compra ClassM;

p=fopen("compras.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

fclose(p);
}
/******************************************************************/
void Compra::CargarArchivo(){
FILE *p;
Compra ClassM;

p=fopen("compras.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.Cargar();

fwrite(&ClassM,sizeof (Compra),1,p);

fclose(p);


}
/******************************************************************/
Compra Compra::leerRegistro(int pos)
{
       Compra reg;
    reg.setImporte(-1);
    FILE *p;
    p=fopen("compras.dat", "rb");
    if(p==NULL) return 0;
    fseek(p, sizeof(Compra)*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}
/******************************************************************/

    int Compra::contarRegistros(){
         FILE *p;
    p=fopen("compras.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Compra);
    }
/******************************************************************/