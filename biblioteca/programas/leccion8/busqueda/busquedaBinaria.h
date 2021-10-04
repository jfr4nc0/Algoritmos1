//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_BUSQUEDABINARIA_H
#define ALGORITMOS1_BUSQUEDABINARIA_H


#include <iostream>
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/strings.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/tokens.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/files.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Array.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Map.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/tads/List.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Stack.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Queue.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_aÃ±o/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Coll.hpp"
using namespace std;

int binarySearch(Coll<int> c,int v)
{
    int k;
    bool enc = false;
    int i = 0;
    int j = collSize<int>(c)-1;

    while( i<=j && !enc )
    {
        k = (i+j)/2;
        int elm = collGetAt<int>(c,k,stringToInt);

        if( elm<v ) i=k+1;
        else if( elm>v ) j=k-1;
        else enc=true;
    }

    return i<=j?k:-1;
}

#endif //ALGORITMOS1_BUSQUEDABINARIA_H
