#include <iostream>
#include "/home/neur0tik/CLionProjects/Algoritmos1/biblioteca/programas/leccion9/estructuraDatos1.h"
#include "/home/neur0tik/CLionProjects/Algoritmos1/biblioteca/funciones/strings.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/tokens.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/funciones/files.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Array.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Map.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/List.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Stack.hpp"
#include "/home/neur0tik/Escritorio/Biblioteca/UTN/1er_año/AyED1/AlgoritmosAFondo/src/biblioteca/tads/Queue.hpp"
#include "/home/neur0tik/CLionProjects/Algoritmos1/biblioteca/tads/Coll.h"
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/tads/Coll.h"

using namespace std;

/*
int main()
{
    // Creo una coleccion de personas
    Coll<Persona> c = coll<Persona>();

    // Le agrego tres personas
    Persona p = {10,"Pedro"};
    collAdd<Persona>(c,p, personaToString);

    p = {20,"Pablo"};
    collAdd<Persona>(c,p, personaToString);

    p = {30,"Juan"};
    collAdd<Persona>(c,p, personaToString);

    // Itero la coleccion
    collReset<Persona>(c);
    while(collHasNext<Persona>(c))
    {
        // Obtengo siguiente persona
        Persona v = collNext<Persona>(c,personaFromString);
        cout << v.dni << "," << v.nom << endl;
    }

    // El usuario ingresa un numero de DNI
    int dni;
    cout << "Ingrese un dni: ";
    cin >> dni;

    // Busco una persona por DNI
    int pos = collFind<Persona,int>(
            c,
            dni,
            cmpPersonaDNI,
            personaFromString);

    // Si existe una persona con el DNI ingresado
    if(pos>=0)
    {
        // Obtengo la persona y la muestro
        Persona v = collGetAt<Persona>(
                c,
                pos,
                personaFromString);

        cout << v.dni << "," << v.nom << endl;
    }
    else
    {
        // No existe una persona con ese DNI
        cout << "Persona no encontrada" << endl;
    }

    // Ordeno la coleccion por nombre ascendente
    collSort<Persona>(c,
                      cmpPersonasNomAsc,
                      personaFromString,
                      personaToString);

    // Muestro la coleccion ordenada
    collReset<Persona>(c);
    while (collHasNext<Persona>(c))
    {
        Persona v = collNext<Persona>(c,personaFromString);
        cout << v.dni << "," << v.nom << endl;
    }

    // Ordeno la coleccion por nombre descendente
    collSort<Persona>(c,
                      cmpPersonasNomDesc,
                      personaFromString,
                      personaToString);

    // Muestro la coleccion ordenada por nombre descendente
    collReset<Persona>(c);
    while (collHasNext<Persona>(c))
    {
        Persona v = collNext<Persona>(c,personaFromString);
        cout << v.dni << "," << v.nom << endl;
    }

    // Ordeno la coleccion por DNI
    collSort<Persona>(c,
                      cmpPersonasDNI,
                      personaFromString,
                      personaToString);

    // Muestro la coleccion ordenada por nombre descendente
    collReset<Persona>(c);
    while (collHasNext<Persona>(c))
    {
        Persona v = collNext<Persona>(c,personaFromString);
        cout << v.dni << "," << v.nom << endl;
    }



    return 0;
}
*/

int main()
{
    Coll<Coll<int>> c = coll<Coll<int>>();

    // debemos especificar separador diferente a '|'
    Coll<int> x = coll<int>(',');
    collAdd<int>(x,1,intToString);
    collAdd<int>(x,2,intToString);
    collAdd<int>(x,3,intToString);

    // la agrego a la coleccion de colecciones
    collAdd<Coll<int>>(c,x,collIntToString);

    // otra coleccion
    x = coll<int>(',');
    collAdd<int>(x,4,intToString);
    collAdd<int>(x,5,intToString);
    collAdd<int>(x,6,intToString);

    // la agrego a la coleccion de colecciones
    collAdd<Coll<int>>(c,x,collIntToString);

    // otra coleccion mas...
    x = coll<int>(',');
    collAdd<int>(x,7,intToString);
    collAdd<int>(x,8,intToString);
    collAdd<int>(x,9,intToString);

    // la agrego a la coleccion de colecciones
    collAdd<Coll<int>>(c,x,collIntToString);

    // ahora itero la coleccion principal
    while( collHasNext<Coll<int>>(c) )
    {
        cout << "[";

        // obtengo el siguiente elemento (que es: Coll<int>)
        Coll<int> z= collNext<Coll<int>>(c,collIntFromString);

        collReset<int>(z);
        while( collHasNext<int>(z) )
        {
            int n = collNext<int>(z, stringToInt);
            cout << n << " ";
        }
        cout << "] " << endl;
        return 0;
    }
}