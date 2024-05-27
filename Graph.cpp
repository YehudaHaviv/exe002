
// Graph.cpp

#include "Graph.hpp"

using namespace ariel;
using namespace std;


ostream &ariel::operator<<(ostream &os, const Graph &g)
    {
        for (size_t i = 0; i < g.graph.size(); i++)
        {
            os << "|";
            for (size_t j = 0; j < g.graph.size(); j++)
            {
                os << g.graph[i][j];
                if (j < g.vertices - 1)
                {
                    os << ",";
                }
            }
            os << "|\n";
        }
        return os;
    }

// g3 = g1 + g2 (Graph g3, g1, g2)
Graph Graph::operator+(Graph &g2)
{
    Graph g3;
    // check same size
    if (this->vertices != g2.vertices)
    {
        perror("Error: the graphs are not in the same size\n");
        return g3;
    }
    // new graph to return
    g3.Graph::loadGraph(this->graph);
    g3.edges = 0;
    bool isDI = true;
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            g3.graph[i][j] += g2.graph[i][j];
            if (g3.graph[i][j] != 0 && g3.graph[i][j] != 1)
            {
                g3.valueEdgesGraph = true;
            }
            if (g3.graph[i][j] != 0)
            {
                g3.edges++;
            }
        }
    }
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (g3.graph[i][j] != g3.graph[j][i])
            {
                isDI = false;
            }
        }
    }
    if (isDI)
    {
        g3.edges /= 2;
    }
    return g3;
}

Graph Graph::operator-(Graph &g2)
{
    Graph g3;
    if (this->vertices != g2.vertices)
    {
        perror("Error: the graphs are not in the same size\n");
        return g3;
    }
    g3.Graph::loadGraph(this->graph);
    g3.edges = 0;
    bool isDI = true;
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            g3.graph[i][j] -= g2.graph[i][j];
            if (g3.graph[i][j] != 0 && g3.graph[i][j] != 1)
            {
                g3.valueEdgesGraph = true;
            }
            if (g3.graph[i][j] != 0)
            {
                g3.edges++;
            }
        }
    }
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (g3.graph[i][j] != g3.graph[j][i])
            {
                isDI = false;
            }
        }
    }
    if (isDI)
    {
        g3.edges /= 2;
    }
    return g3;
}

void Graph::operator+=(Graph &g2)
{
    if (this->vertices != g2.vertices)
    {
        perror("Error: the graphs are not in the same size\n");
        return;
    }
    this->edges = 0;
    bool isDI = true;
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {

            if (this->graph[i][j] != 0)
            {
                this->graph[i][j] += g2.graph[i][j];
            }
            if (this->graph[i][j] != 0 && this->graph[i][j] != 1)
            {
                this->valueEdgesGraph = true;
            }
            if (this->graph[i][j] != 0)
            {
                this->edges++;
            }
        }
    }
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != this->graph[j][i])
            {
                isDI = false;
            }
        }
    }
    if (isDI)
    {
        this->edges /= 2;
    }
}

void Graph::operator-=(Graph &g2)
{
    if (this->vertices != g2.vertices)
    {
        perror("Error: the graphs are not in the same size\n");
        return;
    }
    this->edges = 0;
    bool isDI = true;
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {

            if (this->graph[i][j] != 0)
            {
                this->graph[i][j] -= g2.graph[i][j];
            }
            if (this->graph[i][j] != 0 && this->graph[i][j] != 1)
            {
                this->valueEdgesGraph = true;
            }
            if (this->graph[i][j] != 0)
            {
                this->edges++;
            }
        }
    }
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != this->graph[j][i])
            {
                isDI = false;
            }
        }
    }
    if (isDI)
    {
        this->edges /= 2;
    }
}

Graph Graph::operator+()
{
    return *this; // Return the graph as is
}

// Unary minus operator
Graph Graph::operator-()
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            this->graph[i][j] *= (-1);
        }
    }
    if (!this->valueEdgesGraph)
    {
        this->valueEdgesGraph = true;
    }
    return *this;
}

bool Graph::operator>(Graph &g2)
{
    bool thisINg2 = true;
    bool g2INthis = true;
    int min = this->vertices > g2.vertices ? this->vertices : g2.vertices;
    for (size_t i = this->graph.size(); i < g2.graph.size(); i++)
    {
        for (size_t j = this->graph.size(); j < g2.graph.size(); j++)
        {
            if (g2.graph[i][j] != 0 && this->graph[i][j] == 0)
            {
                g2INthis = false;
            }
            if (g2.graph[i][j] == 0 && this->graph[i][j] != 0)
            {
                thisINg2 = false;
            }
        }
    }
    if (g2.vertices > this->vertices && g2INthis)
    {
        for (size_t i = this->graph.size(); i < g2.graph.size(); i++)
        {
            for (size_t j = this->graph.size(); j < g2.graph.size(); j++)
            {
                if (g2.graph[i][j] != 0 || g2.graph[j][i] != 0)
                {
                    g2INthis = false;
                }
            }
        }
    }
    if (g2.vertices < this->vertices && thisINg2)
    {
        for (size_t i = g2.graph.size(); i < this->graph.size(); i++)
        {
            for (size_t j = g2.graph.size(); j < this->graph.size(); j++)
            {
                if (this->graph[i][j] != 0 || this->graph[j][i] != 0)
                {
                    thisINg2 = false;
                }
            }
        }
    }
    if (g2INthis && thisINg2)
    {
        return false;
    }
    if (thisINg2)
    {
        return false;
    }
    if (g2INthis)
    {
        return true;
    }

    if (this->edges > g2.edges)
    {
        return true;
    }
    if (this->edges == g2.edges && this->vertices > g2.vertices)
    {
        return true;
    }

    return false;
}

bool Graph::operator>=(Graph &g2)
{
    return (*this > g2) || (*this == g2);
}

bool Graph::operator<(Graph &g2)
{
    return !(*this >= g2);
}

bool Graph::operator<=(Graph &g2)
{
    return (*this < g2) || (*this == g2);
}

bool Graph::operator==(Graph &g2)
{
    if (this->vertices != g2.vertices)
    {
        return false;
    }
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != g2.graph[i][j])
            {
                return false;
            }
        }
    }
    return true;
}

bool Graph::operator!=(Graph &g2)
{
    return !(*this == g2);
}

void Graph::operator/(int num)
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (num != 0)
            {
                this->graph[i][j] /= num;
            }
        }
    }
}

void Graph::operator/=(int num)
{
    *this / num;
}

void Graph::operator++()
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j]++;
            }
        }
    }
}

void Graph::operator--()
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j]--;
            }
        }
    }
}
void Graph::operator*(int num)
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            this->graph[i][j] *= num;
        }
    }
}

void Graph::operator*=(int num)
{
    *this *num;
}

void Graph::operator+(int num)
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j] += num;
            }
        }
    }
}

void Graph::operator-(int num)
{
    for (size_t i = 0; i < this->graph.size(); i++)
    {
        for (size_t j = 0; j < this->graph.size(); j++)
        {
            if (this->graph[i][j] != 0)
            {
                this->graph[i][j] -= num;
            }
        }
    }
}

void Graph::operator+=(int num)
{
    *this + num;
}

void Graph::operator-=(int num)
{
    *this - num;
}

Graph Graph::operator*(Graph &g2)
{
    if (this->vertices != g2.vertices)
    {
        throw std::invalid_argument("Error: different size graph");
    }

    size_t n = this->graph.size();
    vector<vector<int>> result(n, vector<int>(n, 0));
    Graph ans;
    ans.loadGraph(result);
    ans.edges = 0;
    ans.valueEdgesGraph = false;

    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            for (size_t k = 0; k < n; ++k)
            {
                ans.graph[i][j] += this->graph[i][k] * g2.graph[k][j];
            }
            if (ans.graph[i][j] != 0)
            {
                ans.edges++;
            }
        }
    }

    bool isDI = true;
    for (size_t i = 0; i < n; ++i)
    {
        for (size_t j = 0; j < n; ++j)
        {
            if (ans.graph[i][j] != ans.graph[j][i])
            {
                isDI = false;
            }
        }
    }
    if (isDI)
    {
        ans.edges /= 2;
    }
    return ans;
}


void Graph::loadGraph(vector<vector<int>> &g)
{

    // check g is valid and not NULL or empty
    if (g.empty())
    {
        throw invalid_argument("Invalid graph: The graph is empty.");
    }
    bool isDirections = false;

    // check matrix is square then put the numbers in there place in the graph
    size_t rows = g.size();
    for (size_t i = 0; i < rows; i++)
    {

        const auto &row_vector = g[i];
        if (row_vector.size() != rows)
        {
            throw invalid_argument("Invalid graph: The graph is not a square matrix.");
        }
        if (g[i][i] != 0)
        {
            throw invalid_argument("Invalid graph: cant be edge for ver from him self.");
        }
    }

    this->edges = 0;
    this->vertices = 0;
    this->valueEdgesGraph = false;

    this->graph.resize(rows, vector<int>(rows));
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < rows; j++)
        {
            if (g[i][j] != 0 && g[i][j] != 1)
            {
                this->valueEdgesGraph = true;
            }
            if (g[i][j] != g[j][i])
            {
                isDirections = true;
            }

            this->graph[i][j] = g[i][j];
            if (g[i][j] != 0)
            {
                this->edges++;
            }
        }
    }

    if (!isDirections)
    {
        this->edges /= 2;
    }
    this->vertices = (int)rows;
}

void Graph::printGraph()
{
    cout << "Graph with " << to_string(this->vertices) << " vertices and " << to_string(this->edges) << " edges." << '\n';
}
