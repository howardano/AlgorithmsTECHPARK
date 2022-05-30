#ifndef LISTGRAPH_HPP
#define LISTGRAPH_HPP

#include "IGraph.h"

struct ListGraph : public IGraph {

private:
    std::vector<std::vector<int>> graph;
    std::vector<std::vector<int>> reverse_graph;

public:

    ListGraph(size_t size);
    ListGraph(const IGraph &graph_);
    virtual ~ListGraph();
    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual std::vector<int> GetNextVertices(int vertex) const;
    virtual std::vector<int> GetPrevVertices(int vertex) const;
};

#endif // LISTGRAPH_HPP