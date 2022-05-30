#include "SetGraph.h"

SetGraph::SetGraph(size_t size) {
    graph.resize(size);
}

SetGraph::SetGraph(const IGraph & graph_) {
    graph.resize(graph_.VerticesCount());

    for (unsigned int i = 0; i < graph.size(); ++i) {
        std::unordered_set<int> b;
        std::vector<int> v = graph_.GetNextVertices(i);
        for (unsigned int j = 0; j < v.size(); ++j) {
            b.insert(v[j]);
        }
    }
}

SetGraph::~SetGraph() {}
    
void SetGraph::AddEdge(int from, int to) {
    graph[from].insert(to);
}

int SetGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> SetGraph::GetNextVertices(int vertex) const {
    std::vector<int> res;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        if (graph[vertex].find(i) != graph[vertex].end()) {
            res.push_back(i);
        }
    }

    return res;
}

std::vector<int> SetGraph::GetPrevVertices(int vertex) const {
    std::vector<int> res;

    for (unsigned int i = 0; i < graph.size(); ++i) {
        if (graph[i].find(vertex) != graph[i].end()) {
            res.push_back(i);
        }
    }

    return res;
}

