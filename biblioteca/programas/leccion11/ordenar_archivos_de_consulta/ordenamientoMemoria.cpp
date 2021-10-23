//
// Created by neur0tik on 12/10/21.
//
// Si el archivo es relativamente pequeño podemos subirlo a una coleccion,
// ordenarla y acceder en orden a su contenido

#include "ordenamientoMemoria.h"

#include "../busqueda_sobre_archivos_de_consulta/MetodoSAMCO.h"
#include "../../../tads/Coll.h"

int main{
        Coll<Ciudad> c = subirCiudades();
        collSort<Ciudad>(c,
        cmpCiudadDescr,    // criterio de ordenamiento
        ciudadFromString,
        ciudadToString);

        collReset<Ciudad>(c);
        while ( collHasNext<Ciudad>(c))
        {
            Ciudad ciu = collNext<Ciudad>(c, ciudadFromString);
            cout << ciudadToString(ciu) << endl;
        }
};