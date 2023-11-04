#pragma once
#include "ArchivoNuevoPunto1.h"
/////////////////////////////////////////////////////////////////////
void SubMenuPuntosDeGabi();
void Punto1();
void Punto2();
void Punto3();
void Punto4(float valor,float registro);

//PUNTOS MAL ECHOS

//void Punto2(){
//     Obra objO;
//     Compra objC;
//     ArchivoNuevoPunto1 objAN;

//     objAN.LimpiarArchivo(); //Primero lo limpia para que no tenga basura

//     int tam = objO.contarRegistros();
//     int tam2 = objC.contarRegistros();
//     for (int i = 0; i < tam; i++)
//     {
//         bool contador2023 = false;
//         objO = objO.leerRegistro(i);
//         if (objO.getActivo() == true && objO.getEstadoDeEjecion() == 3)
//         {
//             for (int j = 0; j < tam2; j++)
//             {
//                 objC = objC.leerRegistro(j);
//                 if ((objC.getsActivo() == true) && (strcmp(objC.getCodigoDeObra(), objO.getCodigoObra()) == 0))
//                 {
//                     if (objC.getFecha().getAnio() < 2023)
//                     {
//                         contador2023 = true;
//                     }
//                 }
//             }
//         }
//         if (contador2023 == true)
//         {
//             objAN.setCodigoDeObra(objO.getCodigoObra());
//             objAN.setDireccionDeObra(objO.getDireccion());
//             objAN.setProvinciaDeObra(objO.getProvincia());
//             if(objAN.grabarRegistro()){}//cout<<"Perfeto PA"<<endl;}
//         }
//     }
//     objAN.MostrarArchivo();
//     objAN.LimpiarArchivo(); //y al final tambien lo borro para RE UTILIZARLO en otro punto
// }

// void Punto2(){
//     Obra objO;
//     Compra objC;

//     int tam1,tam2;

//     int max,maxACT,band1=false,band2=0;
//     char CodigoDeObra[5];

//     tam1 = objO.contarRegistros();
//     tam2 = objC.contarRegistros();

// /*----------------------------------------------*/
//     for(int y=0; y<tam2; y++){

//         objC = objC.leerRegistro(y);

//     if(band2==0){

//     if((band1==false) && (objC.getsActivo()==true)){
//         max=objC.getCantidad();
//         strcpy(CodigoDeObra, objC.getCodigoDeObra());

//         band1=true;
//     }else if((objC.getCantidad()>max)&&(objC.getsActivo()==true)){
//         max=objC.getCantidad();
//         strcpy(CodigoDeObra, objC.getCodigoDeObra());
//     }
//     }
//     }

// int fin=0;

// do
// {
//     for(int x=0; x<tam1; x++){
//         objO = objO.leerRegistro(x);

//         if((objO.getActivo()==true)){
            
//             int valor_devuelto=strcmp(CodigoDeObra,objO.getCodigoObra());

//             if(valor_devuelto!=0){
//                 maxACT=max;
//                 band2=1;
//             }else if(valor_devuelto==0){
//                 fin=1;
//                 x=tam1+1;
//                 band2=2;
//             }
//         }
//     }


//     for(int y=0; y<tam2; y++){

//     if(band2==1){
        
//         if((objC.getsActivo()==true)&&(objC.getCantidad()<maxACT)){
//             max=objC.getCantidad();
//             strcpy(CodigoDeObra, objC.getCodigoDeObra());
//         }else if((objC.getsActivo()==true)&&(objC.getCantidad()>max)&&(objC.getCantidad()<maxACT)){
//             max=objC.getCantidad();
//             strcpy(CodigoDeObra, objC.getCodigoDeObra());
//         }

//     }

// }
// cout<<"maxACT: "<<maxACT<<endl;
// cout<<"el codigo de obra con mayor Cantidad es: "<<max<<endl;
// cout<<"Y su codigo de obra es: "<<CodigoDeObra<<endl;

// } while (fin==0);











// /*----------------------------------------------*/
// //cout<<"el codigo de obra con mayor Cantidad es: "<<max<<endl;
// //cout<<"Y su codigo de obra es: "<<CodigoDeObra<<endl;


// }
// }
























