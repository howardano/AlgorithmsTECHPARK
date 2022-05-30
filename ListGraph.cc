#include "ListGraph.h"

ListGraph::ListGraph(size_t size) {
    graph.resize(size);
    reverse_graph.resize(size);
};

ListGraph::ListGraph(const IGraph &graph_) {
    this->graph.resize(graph_.VerticesCount());
    for (unsigned int i = 0; i < graph.size(); ++i) {
        graph[i] = graph_.GetNextVertices(i);
    }
};

ListGraph::~ListGraph() {}
    
void ListGraph::AddEdge(int from, int to) {
    graph[from].push_back(to);
    reverse_graph[to].push_back(from);
};

int ListGraph::VerticesCount() const {
    return graph.size();
}

std::vector<int> ListGraph::GetNextVertices(int vertex) const {
    std::vector<int> result(graph[vertex].begin(), graph[vertex].end());
    return result;
}

std::vector<int> ListGraph::GetPrevVertices(int vertex) const {
    std::vector<int> result(reverse_graph[vertex].begin(), reverse_graph[vertex].end());
    return result;
}

