//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_ESTRUCTURADATOS1_H
#define ALGORITMOS1_ESTRUCTURADATOS1_H


#include <iostream>
#include <cstdlib>
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

struct Persona
{
    int dni;
    string nom;
};

string personaToString(Persona p) {return intToString(p.dni)+","+p.nom;}

Persona personaFromString(string s)
{
    Persona p;
    p.dni = stringToInt(getTokenAt(s,0,','));
    p.nom = getTokenAt(s,1,',');

    return p;
}
// Recibe persona e int
int cmpPersonaDNI(Persona p,int dni) {return p.dni-dni;}

// Recibe persona y nombre
int cmpPersonaNombre(Persona p,string nom) {return p.nom<nom?-1:p.nom>nom?1:0;}

// Recibe dos personas
int cmpPersonasNomAsc(Persona p1,Persona p2) {return p1.nom<p2.nom?-1:p1.nom>p2.nom?1:0;}

int cmpPersonasNomDesc(Persona p1,Persona p2) {return p2.nom<p1.nom?-1:p2.nom>p1.nom?1:0;}

int cmpPersonasDNI(Persona p1, Persona p2) {return p1.dni-p2.dni;}

#endif //ALGORITMOS1_ESTRUCTURADATOS1_H
