//
// Created by neur0tik on 10/10/21.
//

#ifndef ALGORITMOS1_METODOBSA_H
#define ALGORITMOS1_METODOBSA_H

#include <cstdio>
#include "../../../funciones/files.hpp"
#include "../../../funciones/strings.hpp"
#include "../../../funciones/tokens.hpp"
#include <cstring>
#include <string>
using namespace std;


struct Abonado
{
    int idAbo;
    char nombre[50];
    char direccion[200];
    Fecha fechaAlta;
};

// Buscar registro
Abonado buscarAbonado(FILE* f, int id, bool& encontrado)
{
    encontrado = false;

    int i = 0;              // primer registro
    int j = fileSize(f)-1;  // ultimo registro

    Abonado ret;
    while( i<=j && !encontrado )
    {
        // posicion intermedia entre i y j
        int k = (i+j)/2;

        // accedo al archivo y veo si encuentro lo que busco
        seek<Abonado>(f,k);
        ret = read<Abonado>(f);

        // actualizo los indices
        i = id>a.idAbo?k+1:i;
        j = id<a.idAbo?k-1:j;
        encontrado = i>=j;
    }

    return ret;
}

// Funciones de comparacion, tToString y tFromString
string abonadoToString(Abonado a)
{
    string  sIdAbo  =   intToString(a.idAbo);
    string  sNom    =   a.nombre;
    string  sDir    =   a.direccion;
    string  sFec    =   fechaToString(a.fechaAlta);
    return  sIdAbo+","+sNom+","+","+sFec;
}

Abonado abonadoFromString(string s)
{
    Abonado a;
    a.idAbo = stringToInt(getTokenAt(s,',',0));
    strcpy(a.nombre,getTokenAt(s,',',1).c_str());
    strcpy(a.direccion, getTokenAt(s,',',2).c_str());
    a.fechaAlta = getTokenAt(s,',',3);
    return a;
}

string fechaToString(Fecha f)
{
    string sAnio    = intToString(f.anio);
    string sMes     = intToString(f.mes);
    string sDia     = ToString(f.dia);
    return sAnio+"-"+sMes+"-"+sDia;
}

Fecha fechaFromString(string s)
{
    Fecha f;
    f.anio  = stringToInt(getTokenAt(s,'-',0));
    f.mes   = stringToInt(getTokenAt(s,'-',1));
    f.dia   = stringToInt(getTokenAt(s,'-',2));
    return f;
}

string abonadoIdxToString(AbonadoIdx)


#endif //ALGORITMOS1_METODOBSA_H
