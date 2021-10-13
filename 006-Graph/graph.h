//
// Created by lindsey on 2021/8/25.
//

#ifndef DATASTRUCTURE_GRAPH_H
#define DATASTRUCTURE_GRAPH_H

#include "../002-LinkList/DLinklist.h"

#define MAX 100;
class Graph {
    char nodes[MAX];
    int edges[MAX][MAX];
    int n;
    Graph();
    ~Graph();
    void addNode(char from,char to,int weight);

};

Graph::Graph(){

}

Graph::~Graph(){

}

void Graph::addNode(char from,char to,int weight){
    
}


#endif //DATASTRUCTURE_GRAPH_H
