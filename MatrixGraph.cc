#include "MatrixGraph.h"

MatrixGraph::MatrixGraph(size_t size) {
    matrix.resize(size);
    for (size_t i = 0; i < size; ++i) {
        matrix[i].resize(size, 0);
    }
}

MatrixGraph::MatrixGraph(const IGraph& graph_) {
    matrix.resize(graph_.VerticesCount());
    for (unsigned int i = 0; i < matrix.size(); ++i) {
        matrix[i].resize(matrix.size(), 0);
        std::vector<int> b = graph_.GetNextVertices(i);
        for (unsigned int j = 0; j < b.size(); ++j) {
            matrix[i][j] = 1;
        }
    }
}

MatrixGraph::~MatrixGraph() {}
    
void MatrixGraph::AddEdge(int from, int to) {
    matrix[from][to] = 1;
    matrix[to][from] = 1;
}

int MatrixGraph::VerticesCount() const {
    return matrix.size();
}

std::vector<int> MatrixGraph::GetNextVertices(int vertex) const {
    std::vector<int> res;

    for (unsigned int i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i] == 1)
            res.push_back(matrix[vertex][i]);
    }

    return res;
}

std::vector<int> MatrixGraph::GetPrevVertices(int vertex) const {
    std::vector<int> res;

    for (unsigned int i = 0; i < matrix.size(); ++i) {
        if (matrix[vertex][i] == 1)
            res.push_back(matrix[vertex][i]);
    }

    return res;
}

