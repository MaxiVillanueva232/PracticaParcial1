#include <iostream>
#include <string.h>
#include "FuncionesGlobales.h"

using namespace std;

#include "Material.h"

/******************************************************************/
void Material::Cargar()
{
    int CodigoMaterial;
    char Nombre[30];
    char Marca[30];
    int Tipo;
    int Precio;
    bool Activo;

    cout << "CodigoMaterial: " << endl;
    cin >> CodigoMaterial;
    setCodigoMaterial(CodigoMaterial);

    cout << "Nombre: " << endl;
    cargarCadena(Nombre, 30);
    setNombre(Nombre);

    cout << "Marca: " << endl;
    cargarCadena(Marca, 30);
    setMarca(Marca);

    cout << "Tipo: " << endl;
    cin >> Tipo;
    setTipo(Tipo);

    cout << "Precio: " << endl;
    cin >> Precio;
    setPrecio(Precio);

    cout << "Activo: " << endl;
    cin >> Activo;
    setActivo(Activo);
}
/******************************************************************/
void Material::Mostrar(){
    cout << "CodigoMaterial: " <<getCodigoMaterial()<< endl;
    cout << "Nombre: " <<getNombre()<< endl;
    cout << "Marca: " <<getMarca()<< endl;
    cout << "Tipo: " <<getTipo()<< endl;
    cout << "Precio: " <<getPrecio()<< endl;
    cout << "Activo: " <<getActivo()<< endl;
}
/******************************************************************/
void Material::MostrarArchivo(){
Material ClassM;
FILE *p;

p=fopen("materiales.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Material),1,p)==1){
ClassM.Mostrar();
cout<<endl;
}
fclose(p);
}
/******************************************************************/
void Material::CargarArchivo(){
FILE *p;
Material ClassM;

p=fopen("materiales.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.Cargar();

fwrite(&ClassM,sizeof (Material),1,p);

fclose(p);


}
/******************************************************************/
void Material::CrearArchivo(int tam){
FILE *p;
Material ClassM;

p=fopen("materiales.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

for(int i=0; i<tam; i++){
ClassM.Cargar();
fwrite(&ClassM,sizeof (Material),1,p);
}

fclose(p);

}
/******************************************************************/
void Material::LimpiarARchivo(){
FILE *p;
Material ClassM;

p=fopen("materiales.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}
fclose(p);

}
/******************************************************************/
Material Material::leerRegistro(int pos){
    Material reg;
    FILE *p;
    p=fopen("materiales.dat", "rb");
    if(p==NULL) return reg;
    fseek(p, sizeof(Material)*pos,0);
    fread(&reg, sizeof reg,1, p);
    fclose(p);
    return reg;
}
/******************************************************************/
int Material::contarRegistros(){
    FILE *p;
    p=fopen("materiales.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Material);
}
/******************************************************************/
