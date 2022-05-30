#include "ArcGraph.h"

ArcGraph::ArcGraph(size_t size) {
    amountOfVertices = size;
    graph.resize(size);
}

ArcGraph::ArcGraph(const IGraph &graph_) {
    amountOfVertices = graph_.VerticesCount();
    graph.resize(graph_.VerticesCount());

    for (unsigned int i = 0; i < graph.size(); ++i) {
        std::vector<int> b = graph_.GetNextVertices(i);
        for (unsigned int j = 0; j < b.size(); ++j) {
            graph.push_back(std::make_pair(i, b[j]));
        }
    }
}

ArcGraph::~ArcGraph() {}

void ArcGraph::AddEdge(int from, int to) {
    graph.push_back(std::make_pair(from, to));
}

int ArcGraph::VerticesCount() const {
    return amountOfVertices;
}

std::vector<int> ArcGraph::GetNextVertices(int vertex) const {
    std::vector<int> res;
    for (auto pair : graph) {
        if (pair.first == vertex) {
            res.push_back(pair.second);
        }
    }

    return res;
}

std::vector<int> ArcGraph::GetPrevVertices(int vertex) const {
    std::vector<int> res;

    for (auto pair : graph) {
        if (pair.second == vertex) {
            res.push_back(pair.first);
        }
    }

    return res;
}