#include<iostream>

using namespace std;

#include"FuncionesGlobales.h"

/*****************************************************************/
void BorrarTexto(int tam){

    for(int i=0; i<tam; i++){
        cout<<endl<<endl<<endl<<endl<<endl;
    }

}
/*****************************************************************/
void cargarCadena(char *variable, int tam){
    int i;
    fflush(stdin);
    for(i=0; i<tam; i++)
    {
        variable[i]=cin.get();
        if(variable[i]=='\n') break;
    }
    variable[i]='\0';
    fflush(stdin);
}
/*****************************************************************/
void ponerCeroVector(int vec[],int tam){
    for(int i=0; i<tam; i++){
        vec[i]=0;
    }
}
/*****************************************************************/
void MostrarVector(int vec[],int tam){
    for(int i=0; i<tam; i++){
        cout<<"vec[i] :"<<vec[i]<<endl;
    }
}
/*****************************************************************/
