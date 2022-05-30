#ifndef SETGRAPH_HPP
#define SETGRAPH_HPP

#include "IGraph.h"
#include <unordered_set>

struct SetGraph : public IGraph {
private:
    std::vector<std::unordered_set<int>> graph;

public:
    SetGraph(size_t size);
    SetGraph(const IGraph & graph_);
    virtual ~SetGraph();
    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual std::vector<int> GetNextVertices(int vertex) const;
    virtual std::vector<int> GetPrevVertices(int vertex) const;
};

#endif // IGRAPH_H