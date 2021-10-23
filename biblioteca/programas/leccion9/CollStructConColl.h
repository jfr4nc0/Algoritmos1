//
// Created by neur0tik on 6/10/21.
//

#ifndef ALGORITMOS1_COLLSTRUCTCONCOLL_H
#define ALGORITMOS1_COLLSTRUCTCONCOLL_H

struct Conjunto
{
    string nom; // nombre del conjunto
    Coll<int> c; //elementos del conjunto
};

string conjuntoToString(Conjunto conjunto)
{
    string s=conjunto.nom+"#";
    collReset<int>(conjunto.c);

    int size = collSize<int>(conjunto.c);
    for(int i=0;i<size;i++)
    {
        int v = collGetAt<int>(conjunto.c,i,stringToInt);
        s+=intToString(v)+((i<size-1)?",":"");
    }

    return s;
}

Conjunto conjuntoFromString(string s)
{
    Conjunto conjunto;

    // nombre del conjunto
    conjunto.nom = getTokenAt(s,'#',0);

    // coleccion de elementos
    conjunto.c = coll<int>(',');

    // cadena tokenizada con los elementos del conjunto
    string x = getTokenAt(s,'#',1);

    int n=tokenCount(x,',');
    for(int i=0;i<n;i++)
    {
        // agrego los elementos a la coleccion del conjunto
        int v = stringToInt(getTokenAt(x,',',i));
        collAdd<int>(conjunto.c,v,intToString);
    }

    return conjunto;
}

#endif //ALGORITMOS1_COLLSTRUCTCONCOLL_H
