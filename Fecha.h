#pragma once

#include<iostream>

using namespace std;

class Fecha{

private:
    int dia,mes, anio;
public:
    void Cargar(){
        cout<<"DIA:";
        cin>>dia;
        cout<<"MES:";
        cin>>mes;
        cout<<"DIA:";
        cin>>anio;
    }
    void Mostrar(){
        cout<<dia<<"/";
        cout<<mes<<"/";
        cout<<anio<<endl;
    }
    int getDia(){return dia;}
    int getMes(){return mes;}
    int getAnio(){return anio;}

    void setDia(int d){dia=d;}
    void setMes(int m){mes=m;}
    void setAnio(int a){anio=a;}


};