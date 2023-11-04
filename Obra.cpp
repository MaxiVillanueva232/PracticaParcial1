#include <iostream>
#include <string.h>
#include "FuncionesGlobales.h"

using namespace std;

#include "Obra.h"

/******************************************************************/
void Obra::Cargar()
{

    char CodigoObra[5];
    char Direccion[30];
    int Provincia;
    float Superficie;
    int EstadoDeEjecion;
    bool Activo;

    cout << "_CodigoObra: " << endl;
    cargarCadena(CodigoObra, 5);
    setCodigoObra(CodigoObra);

    cout << "_Direccion: " << endl;
    cargarCadena(Direccion, 30);
    setDireccion(Direccion);

    cout << "_Provincia: " << endl;
    cin >> Provincia;
    setProvincia(Provincia);

    cout << "_Superficie: " << endl;
    cin >> Superficie;
    setSuperficie(Superficie);

    cout << "_EstadoDeEjecion: " << endl;
    cin >> EstadoDeEjecion;
    setEstadoDeEjecion(EstadoDeEjecion);

    cout << "Activo: " << endl;
    cin >> Activo;
    setActivo(Activo);
}

/******************************************************************/
void Obra::Mostrar(){
    cout << "_CodigoObra: " <<getCodigoObra()<< endl;
    cout << "_Direccion: " <<getDireccion()<< endl;
    cout << "_Provincia: " <<getProvincia()<< endl;
    cout << "_Superficie: " <<getSuperficie()<< endl;
    cout << "_EstadoDeEjecion: " <<getEstadoDeEjecion()<< endl;
    cout << "Activo: " <<getActivo()<< endl;
}
/******************************************************************/
void Obra::ponerCero(){

    char CodigoObra[] = "0";
    char Direccion[] = "0";
    int Provincia=0;
    float Superficie=0;
    int EstadoDeEjecion=0;
    bool Activo=false;
    setCodigoObra(CodigoObra);
    setDireccion(Direccion);
    setProvincia(Provincia);
    setSuperficie(Superficie);
    setEstadoDeEjecion(EstadoDeEjecion);
    setActivo(Activo);
}
/******************************************************************/
void Obra::MostrarArchivo(){
Obra ClassM;
FILE *p;

p=fopen("obras.dat","rb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

while(fread(&ClassM,sizeof (Obra),1,p)==1){
ClassM.Mostrar();
cout<<endl;
}
fclose(p);
}
/******************************************************************/
void Obra::CargarArchivo(){
    FILE *p;
Obra ClassM;

p=fopen("obras.dat","ab");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}


ClassM.Cargar();

fwrite(&ClassM,sizeof (Obra),1,p);

fclose(p);


}
/******************************************************************/
void Obra::CrearArchivo(int tam){
FILE *p;
Obra ClassM;

p=fopen("obras.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

for(int i=0; i<tam; i++){
ClassM.Cargar();
fwrite(&ClassM,sizeof (Obra),1,p);
}

fclose(p);
}
/******************************************************************/
void Obra::LimpiarARchivo(){
FILE *p;
Obra ClassM;

p=fopen("obras.dat","wb");
if(p==NULL){
    cout<<"ERROR de ARCHIVO"<<endl;
    system("pause");
}

fclose(p);
}
/******************************************************************/
Obra Obra::leerRegistro(int pos){
    Obra reg;
    FILE *p;
    p=fopen("obras.dat", "rb");
    if(p==NULL){
        return 0;
    }

    fseek(p, sizeof(Obra)*pos,0);
   
    bool verificar =  fread(&reg, sizeof reg,1, p);

    if(verificar==true){
        return reg;
    }else{
        reg.ponerCero();
        return reg;
    }

    fclose(p);
    
}
/******************************************************************/
int Obra::contarRegistros(){
    FILE *p;
    p=fopen("obras.dat", "rb");
    if(p==NULL) return -1;
    fseek(p, 0,2);
    int tam=ftell(p);
    fclose(p);
    return tam/sizeof(Obra);
}
/******************************************************************/