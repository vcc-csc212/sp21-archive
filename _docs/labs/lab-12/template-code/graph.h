#include <vector>
#include <utility> //pair
#include <queue>
#include <ostream>

class Graph{
    private:
        // 2D Vector of Pair objects. Each pair represents <destination, cost> with
        // source being determined by the index in the list the pair is at.
        std::vector<std::vector<std::pair<int,int>>> adj_list;
        void ensureValidGraph(int source, int destination);
        void DFS(int vertex, std::vector<bool> &visited, std::ostream& os);
        void BFS(std::queue<int> &vertex_queue, std::vector<bool> &discovered, std::ostream& os);

    public:
        Graph();
        void displayGraph();
        void addEdge(int source, int destination, int cost);
        void DFS(int vertex, std::ostream& os);
        void BFS(int vertex, std::ostream& os);
};