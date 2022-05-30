#include "ListGraph.h"
#include "MatrixGraph.h"
#include "SetGraph.h"
#include "ArcGraph.h"

void dfs_aux(const IGraph& graph, int vertex, std::vector<bool> & visited, void(*callback)(int)) {
    visited[vertex] = true;
    callback(vertex);

    std::vector<int> children = graph.GetNextVertices(vertex);

    for (int child : children) {
        if (!visited[child]) {
            dfs_aux(graph, child, visited, callback);
        }
    }
}

void dfs(const IGraph & graph, void (*callback)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);

    for (int i = 0; i < graph.VerticesCount(); ++i) {
        if (!visited[i]) {
            dfs_aux(graph, i, visited, callback);
        }
    }
}

void bfs(const IGraph & graph, void (*callback)(int)) {
    std::vector<bool> visited(graph.VerticesCount(), false);
    std::queue<int> q; 

    for (int v = 0; v < graph.VerticesCount(); ++v) {
        if (!visited[v]) {
            visited[v] = true;
            callback(v);
            q.push(v);

            while (q.empty()) {
                int cur_v = q.front();
                q.pop();


                std::vector<int> children = graph.GetNextVertices(cur_v);

                for (int child : children) {
                    if (!visited[child]) {
                        visited[child] = true;
                        callback(child);
                        q.push(child);
                    }
                }
            }
        }
    }
}

int main() {
    std::cout << "CHECKING DETOURS: " << std::endl;

    ListGraph lst_graph(6);
    lst_graph.AddEdge(0, 1);
    lst_graph.AddEdge(1, 2);
    lst_graph.AddEdge(2, 3);
    lst_graph.AddEdge(3, 1);
    lst_graph.AddEdge(1, 4);

    std::cout << "ListGraph : ... " << std::endl;
    dfs(lst_graph, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "------------" << std::endl;

    bfs(lst_graph, [](int v) {
        std::cout << v << std::endl;
    });

    MatrixGraph mat_graph(6);
    mat_graph.AddEdge(0, 1);
    mat_graph.AddEdge(1, 2);
    mat_graph.AddEdge(2, 3);
    mat_graph.AddEdge(3, 1);
    mat_graph.AddEdge(1, 4);

    std::cout << "\nMatrixGraph : ... " << std::endl;
    dfs(mat_graph, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "------------" << std::endl;

    bfs(mat_graph, [](int v) {
        std::cout << v << std::endl;
    });

    
    SetGraph set_graph(6);
    set_graph.AddEdge(0, 1);
    set_graph.AddEdge(1, 2);
    set_graph.AddEdge(2, 3);
    set_graph.AddEdge(3, 1);
    set_graph.AddEdge(1, 4);

    std::cout << "\nSetGraph : ... " << std::endl;
    dfs(set_graph, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "------------" << std::endl;

    bfs(set_graph, [](int v) {
        std::cout << v << std::endl;
    });

    ArcGraph arc_graph(6);
    arc_graph.AddEdge(0, 1);
    arc_graph.AddEdge(1, 2);
    arc_graph.AddEdge(2, 3);
    arc_graph.AddEdge(3, 1);
    arc_graph.AddEdge(1, 4);

    std::cout << "\nArcGraph : ... " << std::endl;
    dfs(arc_graph, [](int v) {
        std::cout << v << std::endl;
    });

    std::cout << "------------" << std::endl;

    bfs(arc_graph, [](int v) {
        std::cout << v << std::endl;
    });
}