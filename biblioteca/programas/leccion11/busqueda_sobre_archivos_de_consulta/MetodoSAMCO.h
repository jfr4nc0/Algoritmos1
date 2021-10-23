//
// Created by neur0tik on 10/10/21.
//  El metodo de Subir el archivo a memoria, en una coleccion de objetos (SAMCO)

#ifndef ALGORITMOS1_METODOSAMCO_H
#define ALGORITMOS1_METODOSAMCO_H

struct Ciudad
{
    int idCiu;
    char descr[20]; // descripcion o nombre de la ciudad
    int millas;
};


// Subir archivo
Coll<Ciudad> subirCiudades()
{
    // abrimos el archivo
    FILE* f = fopen("CIUDADES.dat","r+b");

    // creamos una coleccion vacia
    Coll<Ciudad> c = coll<Ciudad>();

    // recorremos el archivo
    Ciudad r = read<Ciudad>(f);
    while ( !feof(f) )
    {
        // agregamos el registro a la coleccion
        collAdd<Ciudad>(c,r,ciudadToString);

        r = read<Ciudad>(f);
    }

    // cerramos el archivo y retornamos la coleccion
    fclose(f);
    return c;
}

// Buscar archivo
Ciudad buscarCiudad(Coll<Ciudad> c, int id, bool& encontrado)
{
    int pos = collFind<Ciudad,int>(c,
                                   id,
                                   cmpCiudadId,
                                   ciudadFromString);

    // asignamos boolean al parametro encontrado
    encontrado = pos>=0;

    Ciudad ret;
    if(encontrado) {ret = collGetAt<Ciudad>(c,pos,ciudadFromString);}
    return ret;
}

// Ejemplos de uso
// subimos el archivo a memoria
Coll<Ciudad> ciudades = subirCiudades();

// ciudad a buscar
int idCiu = 3;
bool encontrado;
Ciudad ciudad = buscarCiudad(ciudades,idCiu,encontrado);

if(encontrado) {cout << ciudadToString(ciudad) << endl;}

// Funciones de comparacion, tToString y tFromString

string ciudadToString(Ciudad c)
{
    string sIdCiu = intToString(c.idCiu);
    string sDescr = c.descr;
    string sMillas = intToString(c.millas);
    return sIdCiu+","+sDescr+","+sMillas;
}

Ciudad ciudadFromString(string s)
{
    Ciudad c;
    c.idCiu = stringToInt(getTokenAt(s,',',0));
    strcpy(c.descr,getTokenAt(s,',',1));
    c.millas = stringToInt(getTokenAt(s,',',2));
    return c;
}

int cmpCiudadId(Ciudad c, int id){return c.idCiu-id;}

#endif //ALGORITMOS1_METODOSAMCO_H
