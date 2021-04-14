#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.h"
#include <iostream>

TEST_CASE("Add Edge") {
    Graph g;

    g.addEdge(0, 1, 7);
    g.addEdge(0, 2, 9);
    g.addEdge(0, 5, 14);
    g.addEdge(1, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 11);
    g.addEdge(2, 5, 2);
    g.addEdge(3, 4, 6);
    g.addEdge(4, 5, 9);

    g.displayGraph();
}

TEST_CASE("DFS") {
    SUBCASE("From 0"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.DFS(0, oss);

        REQUIRE(oss.str() == "0 1 2 3 4 5 ");
    }
    SUBCASE("From 1"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.DFS(1, oss);

        REQUIRE(oss.str() == "1 0 2 3 4 5 ");
    }
    SUBCASE("From 2"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.DFS(2, oss);

        REQUIRE(oss.str() == "2 0 1 3 4 5 ");
    }
    SUBCASE("From 3"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.DFS(3, oss);

        REQUIRE(oss.str() == "3 1 0 2 5 4 ");
    }
}

TEST_CASE("BFS") {
    SUBCASE("From 0"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.BFS(0, oss);
        REQUIRE(oss.str() == "0 1 2 5 3 4 ");
    }
    SUBCASE("From 1"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.BFS(1, oss);
        REQUIRE(oss.str() == "1 0 2 3 5 4 ");
    }
    SUBCASE("From 2"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.BFS(2, oss);
        REQUIRE(oss.str() == "2 0 1 3 5 4 ");
    }
    SUBCASE("From 3"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 7);
        g.addEdge(0, 2, 9);
        g.addEdge(0, 5, 14);
        g.addEdge(1, 2, 10);
        g.addEdge(1, 3, 15);
        g.addEdge(2, 3, 11);
        g.addEdge(2, 5, 2);
        g.addEdge(3, 4, 6);
        g.addEdge(4, 5, 9);

        g.BFS(3, oss);
        REQUIRE(oss.str() == "3 1 2 4 0 5 ");
    }
}
