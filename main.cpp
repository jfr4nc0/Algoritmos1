#include <iostream>

#include "/home/neur0tik/CLionProjects/Algoritmos1/biblioteca/programas/leccion9/estructuraDatos1.h"
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