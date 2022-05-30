#ifndef MATRIXGRAPH_HPP
#define MATRIXGRAPH_HPP

#include "IGraph.h"

struct MatrixGraph : public IGraph {
private:
    std::vector<std::vector<int>> matrix;
public:

    MatrixGraph(size_t size);
    MatrixGraph(const IGraph& graph_);
    virtual ~MatrixGraph();
    virtual void AddEdge(int from, int to);
    virtual int VerticesCount() const;
    virtual std::vector<int> GetNextVertices(int vertex) const;
    virtual std::vector<int> GetPrevVertices(int vertex) const;
};

#endif // MATRIXGRAPH_HPP