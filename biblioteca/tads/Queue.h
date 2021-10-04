//
// Created by neur0tik on 4/10/21.
//

#ifndef ALGORITMOS1_QUEUE_H
#define ALGORITMOS1_QUEUE_H

#include <iostream>
#include "../funciones/lists.hpp"

using namespace std;

template<typename T>
struct Queue
{
};

template<typename T>
Queue<T> queue()
{
    Queue<T> q;
    return q;
}

template<typename T>
T* queueEnqueue(Queue<T>& q,T e)
{
    return NULL;
}

template<typename T>
T queueDequeue(Queue<T>& q)
{
    T t;
    return t;
}

template<typename T>
bool queueIsEmpty(Queue<T> q)
{
    return true;
}

template<typename T>
int queueSize(Queue<T> q)
{
    return 0;
}

#endif //ALGORITMOS1_QUEUE_H
