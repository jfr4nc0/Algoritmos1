//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_BUSQUEDALINEAL_H
#define ALGORITMOS1_BUSQUEDALINEAL_H



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

int search(Coll<int> c, int v)
{
    int i = 0;

    // recorro mientras no encuentre y no llegue el final
    int n = collSize<int>(c);
    while(i<n && collGetAt<int>(c,i,stringToInt)!=v ) i++;

    // retorno la posicion donde encontre negativo
    return i<n?i:-1;
}


#endif //ALGORITMOS1_BUSQUEDALINEAL_H
