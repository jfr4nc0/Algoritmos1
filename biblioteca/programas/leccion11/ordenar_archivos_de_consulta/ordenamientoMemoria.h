//
// Created by neur0tik on 12/10/21.
//

#ifndef ALGORITMOS1_ORDENAMIENTOMEMORIA_H
#define ALGORITMOS1_ORDENAMIENTOMEMORIA_H

#include "../busqueda_sobre_archivos_de_consulta/MetodoSAMCO.h"
#include "string"

int cmpCiudadDescr(Ciudad a, Ciudad b)
{
     std::string aDescr = a.descr;
     std::string bDescr = b.descr;
    return aDescr<bDescr?-1:aDescr>bDescr?1:0;
}

#endif //ALGORITMOS1_ORDENAMIENTOMEMORIA_H
