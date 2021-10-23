//
// Created by neur0tik on 10/10/21.
//

#include "MetodoIndexarArchivo.h"

// Ejemplo de uso

// abrimos el archivo
FILE* f = fopen("ABONADOS.dat","r+b");

// lo indexamos
Coll<AbonadoIdx> idx = indexarAbonados(f);

// id del abonado que vamos a buscar
int id = 6342;
bool  encontrado;

Abonado a = buscarAbonadoIdx(f,idx,id,encontrado);

if( encontrado ){cout << abonadoToString(a) << endl;}