#ifndef IGRAPH_H
#define IGRAPH_H

#include <string>
#include <algorithm>
#include <iostream>
#include <vector>
#include <ctype.h>
#include <queue>

struct IGraph {
    virtual ~IGraph() {}
        
    virtual void AddEdge(int from, int to) = 0;
    virtual int VerticesCount() const  = 0;

    virtual std::vector<int> GetNextVertices(int vertex) const = 0;
    virtual std::vector<int> GetPrevVertices(int vertex) const = 0;
};

#endif // IGRAPH_H