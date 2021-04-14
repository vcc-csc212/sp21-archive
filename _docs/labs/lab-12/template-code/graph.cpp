#include "graph.h"
#include <iostream>


Graph::Graph(){

}

void Graph::displayGraph(){
    for(unsigned int i = 0; i < this->adj_list.size(); i++){
        std::cout << i << ": ";
        for(unsigned int j = 0; j < this->adj_list[i].size(); j++){
            std::cout << "(" << this->adj_list[i][j].first << "," << this->adj_list[i][j].second << ") ";
        }
        std::cout << std::endl;
    }
}

void Graph::ensureValidGraph(int source, int destination){

}


void Graph::addEdge(int source, int destination, int cost){

}

void Graph::BFS(std::queue<int> &vertex_queue, std::vector<bool> &discovered, std::ostream& os){

}


void Graph::DFS(int vertex, std::vector<bool> &visited, std::ostream& os){

}
// Public Helper Functions
void Graph::DFS(int vertex, std::ostream& os){
    std::vector<bool> visited(this->adj_list.size(), false);
    DFS(vertex, visited, os);
}

void Graph::BFS(int vertex, std::ostream& os){
    std::queue<int> vertex_queue;
    std::vector<bool> discovered(this->adj_list.size(), false);

    discovered[vertex] = true;
    vertex_queue.push(vertex);

    BFS(vertex_queue, discovered, os);
}

