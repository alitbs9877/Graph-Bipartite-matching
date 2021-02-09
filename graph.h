//
// Created by alitbs on 4/30/19.
//

#include <iostream>
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <queue>


#ifndef UNTITLED_GRAPH_H
#define UNTITLED_GRAPH_H
using namespace std ;
class graph{
private:
public:
    vector<edge*>  edges;
    vector<vertex*>  vertexes;

    graph(vector<edge*> Edges ,vector<vertex*>  Vertexes){
        vertexes=Vertexes;
        edges=Edges;
    }

};
#endif //UNTITLED_GRAPH_H
