//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_BURBUJEO_H
#define ALGORITMOS1_BURBUJEO_H


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

void bubbleSort(Coll<int>& c)
{
    int n = collSize<int>(c);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n-1; j++)
        {
            int a = collGetAt<int>(c,j,stringToInt);
            int b = collGetAt<int>(c,j+1,stringToInt);

            if( a>b )
            {
                int aux = a;
                collSetAt<int>(c,b,j,intToString);
                collSetAt<int>(c,aux,j+1,intToString);
            }
        }
    }
}


#endif //ALGORITMOS1_BURBUJEO_H
