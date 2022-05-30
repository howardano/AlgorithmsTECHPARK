#ifndef ARCGRAPH_H
#define ARCGRAPH_H

#include "IGraph.h"
#include <utility>

struct ArcGraph : public IGraph {

private:
    std::vector<std::pair<int, int>> graph;
    int amountOfVertices;

public:

    ArcGraph(size_t size);
    ArcGraph(const IGraph &graph_);
    virtual ~ArcGraph();
    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual std::vector<int> GetNextVertices(int vertex) const;
    virtual std::vector<int> GetPrevVertices(int vertex) const;
};

#endif // LISTGRAPH_HPP