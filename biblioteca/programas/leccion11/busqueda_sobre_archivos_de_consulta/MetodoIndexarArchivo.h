//
// Created by neur0tik on 10/10/21.
//

#ifndef ALGORITMOS1_METODOINDEXARARCHIVO_H
#define ALGORITMOS1_METODOINDEXARARCHIVO_H

#include <cstdio>
#include "MetodoBSA.h"
#include "../../../tads/Coll.h"

// Estructura del indice
struct AbonadoIdx
{
    int idAbo;  // clave
    int pos;    // posicion
};

// Indexar
Coll<AbonadoIdx> indexarAbonados(FILE* f)
{
    Coll<AbonadoIdx> c = coll<AbonadoIdx>();

    // nos movemos al inicio del archivo
    seek<Abonado>(0);

    Abonado a = read<Abonado>(f);
    while( !feof(f) )
    {
        // creo el elemento con el id y la posicion
        AbonadoIdx elm = {a.idAbo, filePos<Abonado>(f)-1};

        // lo agrego a la coleccion
        collAdd<AbonadoIdx>(c,elm,abonadoIdxToString);

        a = read<Abonado>(f);
    }
    return c;
}

// Buscar un registro
Abonado buscarAbonadoIdx(FILE* f,
                         Coll<AbonadoIdx> c,
                         int id,
                         bool encontrado)
{
    int pos = collFind<AbonadoIdx,int>(c,
                                       id,
                                       cmpAbonadoIdx,
                                       abonadoIdxFromString);

    encontrado = false;
    Abonado ret;
    if( pos>= 0 )
    {
        encontrado = true;

        // obtengo el elemento de la coleccion
        AbonadoIdx elm = collGetAt<AbonadoIdx>{c,
                                               pos,
                                               abonadoIdxFromString};
        // accedo al archivo y veo si encuentro lo que busco
        seek<Abonado>(f,elm.pos);
        ret = read<Abonado>(f);
    }

    return ret;
}

// Funciones de comparacion, tToString y tFromString
string abonadoIdxToString(AbonadoIdx::AbonadoIdx x)
{
    return intToString(x.idAbo)+","+ intToString(x.pos);
}

AbonadoIdx abonadoIdxFromString(string s)
{
    AbonadoIdx x;
    x.idAbo = stringToInt(getTokenAt(s,',',0));
    x.pos   = stringToInt(getTokenAt(s,',',1));
    return x;
}

int cmpAbonadoIdxId(AbonadoIdx x, int id)
{
    return x.idAbo-id;
}

#endif //ALGORITMOS1_METODOINDEXARARCHIVO_H
