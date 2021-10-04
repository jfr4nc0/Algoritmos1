//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_INSERCIONAVANZADA_H
#define ALGORITMOS1_INSERCIONAVANZADA_H

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

void insercionSortAdv(Coll<int>& c)
{
    int p = collSize<int>(c);

    while( p>0 )
    {
        int pos = 0;
        int min = collGetAt<int>(c,0,stringToInt);
        for(int i=0; i<p; i++)
        {
            int elm = collGetAt<int>(c,0,stringToInt);
            if( elm<min )
            {
                min = elm;
                pos = i;
            }
        }

        collAdd<int>(c,min,intToString);
        collRemoveAt<int>(c,pos);
        p--;
    }
}

#endif //ALGORITMOS1_INSERCIONAVANZADA_H
