//
// Created by neur0tik on 12/10/21.
//
// Si el archivo es extenso podemos ibdexarlo y ordenar su indice. Tendremos acceso directo a sus registros,
// que apareceran ordenador en funcion del criterio de precedencia establecido para el campo clave que figura
// en la estructura del indice

#include <cstdio>
#include "ordenamientoIndexacion.h"
#include "../busqueda_sobre_archivos_de_consulta/MetodoIndexarArchivo.h"

// abrimos el archivo
FILE* f = fopen("ABONADOS.dat","r+b");

// lo indexamos
Coll<AbonadoIdx> idx = indexarAbonados(f);

// ordenamos el indice
collSort<AbonadoIdx>(idx,
                     cmpAbonadoId,  // criterio de ordenamiento
                     abonadoIdxFromString,
                     abonadoIdxToString);

// recorremos el indice y accedemos en orden a los registros del archivo
collReset<AbonadoIdx>(idx);
while( collHasNext<AbonadoIdx>(idx) )
{
    AbonadoIdx x = collNext<AbonadoIdx>(idx,
                                        abonadoIdxFromString);
    // accedo al archivo
    seek<Abonado>(f,x.pos);
    Abonado a = read<Abonado>(f);

    // muestro
    cout << abonadoToString(a)  << endl;
}
fclose(f);