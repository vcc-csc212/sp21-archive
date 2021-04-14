#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "graph.h"
#include <iostream>

TEST_CASE("Add Edge") {
    Graph g;

    g.addEdge(0, 1, 3);
    g.addEdge(0, 2, 3);
    g.addEdge(1, 3, 2);
    g.addEdge(2, 3, 1);

    g.displayGraph();
}

TEST_CASE("DFS") {
    SUBCASE("From 0"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.DFS(0, oss);

        REQUIRE(oss.str() == "0 1 3 2 ");
    }
    SUBCASE("From 1"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.DFS(1, oss);

        REQUIRE(oss.str() == "1 3 ");
    }
    SUBCASE("From 2"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.DFS(2, oss);

        REQUIRE(oss.str() == "2 3 ");
    }
    SUBCASE("From 3"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.DFS(3, oss);

        REQUIRE(oss.str() == "3 ");
    }
}

TEST_CASE("BFS") {
    SUBCASE("From 0"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.BFS(0, oss);
        REQUIRE(oss.str() == "0 1 2 3 ");
    }
    SUBCASE("From 1"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.BFS(1, oss);
        REQUIRE(oss.str() == "1 3 ");
    }
    SUBCASE("From 2"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.BFS(2, oss);
        REQUIRE(oss.str() == "2 3 ");
    }
    SUBCASE("From 3"){
        Graph g;
        std::ostringstream oss;

        g.addEdge(0, 1, 3);
        g.addEdge(0, 2, 3);
        g.addEdge(1, 3, 2);
        g.addEdge(2, 3, 1);

        g.BFS(3, oss);
        REQUIRE(oss.str() == "3 ");
    }
}
