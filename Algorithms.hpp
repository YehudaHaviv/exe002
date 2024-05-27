//Algorithms.hpp

#ifndef ALGO_HPP
#define ALGO_HPP

#include "Graph.hpp"
#include <string>

using namespace std;

namespace ariel{

    class Algorithms
    {
        public:
            static vector<pair<string, size_t>> bfsSreach(const Graph& g, size_t start);

            static vector<pair<std::string, int>> bellmanFord(const Graph& g, size_t start);

            static int isConnected(const Graph& g);

            static string shortestPath(const Graph& g, int start, int end);

            static string isContainsCycle(const Graph& g);

            static string isBipartite(const Graph& g);

            static string negativeCycle(const Graph& g);
    };
}
#endif

