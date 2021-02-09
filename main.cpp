


// A C++ program to find maximal
// Bipartite matching.
#include <iostream>
#include <string.h>
#include "graph.h"
#include "vertex.h"
#include "edge.h"
#include <vector>
#include <queue>
using namespace std;


vector< edge *>   Symmetric_difference(vector< edge* >  augmentingPath, vector< edge* >  matching){
    vector< edge* > result ;
    for (int i = 0; i <augmentingPath.size() ; ++i) {
        bool find=false;
        for (int j = 0; j <matching.size() ; ++j) {
            if ( augmentingPath.at(i)->equal(matching.at(j) ) ){
                find= true;

                break;
            }
        }
        if(find) continue;
        result.push_back(augmentingPath.at(i));
    }
    for (int i = 0; i <matching.size() ; ++i) {
        bool find=false;
        for (int j = 0; j <augmentingPath.size() ; ++j) {
            if ( augmentingPath.at(j)->equal(matching.at(i) ) ){
                find= true;

                break;
            }
        }
        if(find) continue;
        result.push_back(matching.at(i));
    }
    return result;

}
bool findAGMPath(graph G ,vector< edge* >  matching, vector< edge* >  *augmentingPath, bool isOdd  ){
    vector <edge* > newAgumentingPath ;
    vector <vertex * > matchingEdge;
    for (int k = 0; k <matching.size() ; ++k) {
        matchingEdge.push_back(matching.at(k)->a);

        matchingEdge.push_back(matching.at(k)->b);
    }
    int conter=0;
    edge *t2;
    bool Pass=false;
    for (int i = 0; i <G.edges.size() ; ++i) {
//        if( (G.edges.at(i).a.name==first.name ||G.edges.at(i).a.name==end.name  ) &&
//                (G.edges.at(i).b.name==first.name ||G.edges.at(i).b.name==end.name  )  ){
//            continue;
//        }
         //  TODO Shart yeki dar MIou


        bool sameLastInNewAgumentingPath=false;
        for (int l = 0; l < newAgumentingPath.size(); ++l) {
            if(newAgumentingPath.at(l)->b->name==G.edges.at(i)->a->name && newAgumentingPath.at(l)->a->name==G.edges.at(i)->b->name){
                sameLastInNewAgumentingPath=true;
                break;
            }
        }
        if(sameLastInNewAgumentingPath){
            continue;
        }
//        cout << "this edge "<< G.edges.at(i)->a->name << "---> "<< G.edges.at(i)->b->name << endl;
        bool TwosCondition=false;
        bool pass=false;
        for (int j = 0; j <matching.size() ; ++j) {
//
//            cout << "this  matching edge "<<matching.at(j)->a->name << "---> "<< matching.at(j)->b->name << endl;
            if (G.edges.at(i)->equal(matching.at(j)) ){
                TwosCondition=false;
                pass=true;

//                cout << "do  sar " << endl;
                newAgumentingPath.push_back(G.edges.at(i));
                break;
            }
            else if( G.edges.at(i)->a->name==matching.at(j)->a->name||G.edges.at(i)->a->name==matching.at(j)->b->name ||
                G.edges.at(i)->b->name==matching.at(j)->a->name||G.edges.at(i)->b->name==matching.at(j)->b->name  ){
                if(G.edges.at(i)->b->name==matching.at(j)->a->name &&G.edges.at(i)->a->name==matching.at(j)->b->name){
                    continue;
                }
                if(G.edges.at(i)->b->name==G.edges.at(i)->a->name){
                    continue;
                }
                bool duplicateedge=false;
                bool notPass=false;
                for (int k = 0; k <matchingEdge.size() ; ++k) {
                    if((matchingEdge.at(k)->name == G.edges.at(i)->a->name || matchingEdge.at(k)->name == G.edges.at(i)->b->name ) ){
                       if(!duplicateedge ){
                           duplicateedge=true;
                       }
                       else {
                           notPass=true;
                           break;
                       }
                    }
                }
                if(notPass){
                    continue;
                }
                if(!TwosCondition ) {
                    TwosCondition = true;
//                    cout << "ye sar " << endl;
                    continue;
                }
//                }else {
//                    if( (G.edges.at(i)->a->name==matching.at(j)->a->name||G.edges.at(i)->a->name==matching.at(j)->b->name) ||
//                        (G.edges.at(i)->b->name==matching.at(j)->a->name||G.edges.at(i)->b->name==matching.at(j)->b->name)  ) {
//                        pass=true;
//
//                        newAgumentingPath.push_back(G.edges.at(i));
//                        break;
//                    }
//                }

            }


        }
//        if(pass) break;

        if(TwosCondition && conter<2){
            conter++;

//            cout << "yekish jorre " << endl;
            newAgumentingPath.push_back(G.edges.at(i));
        }
        if(conter==2){
            break;
        }
    }

    if(conter==2){
        *augmentingPath=newAgumentingPath;

//        cout << "shoood " << endl;
        return true;

    }

//    cout << "na   shoood " << endl;
    return false;





}
void printGraph(vector<edge*> t) {
    for (int i = 0; i <t.size() ; ++i) {

        cout << t.at(i)->a->name<<"->"<<t.at(i)->b->name<<endl;
    }
}

// Driver Code
int main()
{
    vector< edge *>  matching ;
    vector<edge*> E;
    vector<vertex*> V;
    for (int i = 0; i <6  ; ++i) {
        vertex *a= new vertex('0'+i) ;
        V.push_back(a);
    }

//    cout << "@@@@@@@@@@"<<endl;

    edge *edge1 = new edge(V.at(0),V.at(1));

//    cout << edge1->a->name<<"->"<<edge1->b->name<<endl;
    E.push_back(edge1);

    edge *edge2 = new edge(V.at(0),V.at(2));

    E.push_back(edge2);


    edge *edge3 = new edge(V.at(1),V.at(0));
    E.push_back(edge3);


    edge *edge4 = new edge(V.at(1),V.at(3));
    E.push_back(edge4);


    edge *edge5 = new edge(V.at(2),V.at(2));
    E.push_back(edge5);


    edge *edge6 = new edge(V.at(3),V.at(2));
    E.push_back(edge6);


    edge *edge7 = new edge(V.at(3),V.at(3));
    E.push_back(edge7);





    graph G(E,V);
    printGraph(E);
    vector< edge *>  augmentingPath ;
    matching.push_back(G.edges.at(0));
    int conter = 0;


    while(conter<15 && findAGMPath(G ,matching,&augmentingPath,false)){
        conter++;

        cout << "mas " << endl;
        matching=Symmetric_difference(augmentingPath,matching);

        printGraph(matching);
    }
    cout << "matching is " << endl;
    printGraph(matching);

}


/*

#include <iostream>

int main() {
   std::cout << "Hello, World!" << std::endl;
   return 0;
}*/