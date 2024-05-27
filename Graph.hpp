
// Graph.hpp

#ifndef GRAPH_HPP
#define GRAPH_HPP

#include <iostream>
#include <vector>
#include <stdexcept>

using namespace std;

namespace ariel
{

    class Graph
    {

    public:
        int edges;
        int vertices;
        bool valueEdgesGraph;
        vector<vector<int>> graph;

        Graph operator+(Graph &g2);

        Graph operator-(Graph &g2);

        void operator+=(Graph &g2);

        void operator-=(Graph &g2);

        Graph operator+();

        Graph operator-();

        bool operator>(Graph &g2);

        bool operator>=(Graph &g2);

        bool operator<(Graph &g2);

        bool operator<=(Graph &g2);

        bool operator==(Graph &g2);

        bool operator!=(Graph &g2);

        void operator++();

        void operator--();

        void operator+(int num);

        void operator-(int num);

        void operator*(int num);

        void operator*=(int num);

        void operator/(int num);

        void operator/=(int num);

        void operator+=(int num);

        void operator-=(int num);

        Graph operator*(Graph &g2);

        friend std::ostream &operator<<(std::ostream &os, const Graph &graph);

        void loadGraph(vector<vector<int>> &g);

        void printGraph();
    };

}

#endif
