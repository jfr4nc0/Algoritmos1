//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_INSERCIONSIMPLE_H
#define ALGORITMOS1_INSERCIONSIMPLE_H

#include <iostream>
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/strings.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/tokens.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/files.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Array.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Map.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/List.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Stack.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Queue.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Coll.hpp"

using namespace std;

void insertionSort(Coll<int>& c)
{
    // coleccion auxiliar vacia
    Coll<int> aux = coll<int>();

    //itero mientras queden elementos en c
    while(collSize<int>(c)>0)
    {
        //busco el menor en c
        int pos = 0;
        int min = collGetAt<int>(c,0,stringToInt);
        for(int i=0; i<collSize<int>(c); i++)
        {
            int elm = collGetAt<int>(c,i,stringToInt);
            if(elm<min)
            {
                min = elm;
                pos = i;
            }
        }

        collAdd<int>(aux,min,intToString);
        collRemoveAt<int>(c,pos);
    }

    c = aux;
}

#endif //ALGORITMOS1_INSERCIONSIMPLE_H
