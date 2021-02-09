//
// Created by alitbs on 4/30/19.
//
#include <iostream>
#include "vertex.h"
#ifndef UNTITLED_EDGE_H
#define UNTITLED_EDGE_H
class edge{
private:
public:

    vertex *a,*b;
edge();
    edge(vertex *f1,vertex *f2 ){
        a=f1;
        b=f2;
    }
    bool equal(edge *t){
        if((this->a->name==t->a->name&&this->b->name==t->b->name) ){
            return true;
        }
        return false;
    }

};



#endif //UNTITLED_EDGE_H
