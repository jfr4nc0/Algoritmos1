//
// Created by neur0tik on 10/10/21.
//

#include "MetodoBSA.h"
#include <cstdio>

// Ejemplo de uso: Buscamos un abonado dentro del archivo ABONADOS.dat

// abrimos el archivo
FILE* f = fopen("ABONADOS.dat","r+b");

// id del abonado que vamos a buscar
int id = 6342;

bool  encontrado;
Abonado a = buscarAbonado(f,id,encontrado);

if( encontrado ){cout << abonadoToString(a) << endl;}

fclose(f);