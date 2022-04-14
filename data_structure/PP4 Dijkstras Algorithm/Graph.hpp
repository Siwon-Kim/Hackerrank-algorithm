#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <algorithm>
#include <tuple>

const unsigned long INF = 999999999999;

class Graph : public GraphBase
{
private:
    std::vector<Vertex *> vertices;
    std::vector<Edge *> edges;
    std::priority_queue<std::pair<unsigned long, std::string>> pq;
    std::vector<Vertex *>::iterator vtx_itr;
    std::vector<Edge *>::iterator edg_itr;

protected:
    void check_two_vertices(std::string label1, std::string label2);

public:
    Graph() {}
    ~Graph();
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};

class Edge
{
private:
    std::string current_edge_label;
    std::string adjacent_edge_label;
    unsigned long edge_value;

public:
    friend class Graph;
    Edge(std::string curr = "", std::string adja = "", unsigned long val = 0)
    {
        current_edge_label = curr;
        adjacent_edge_label = adja;
        edge_value = val;
    }
    ~Edge() {}
};

class Vertex
{
private:
    std::string vertex_label;
    unsigned long min_distance;
    std::vector<std::string> shortest_path;
    bool isVisited;

public:
    friend class Graph;
    Vertex() { vertex_label = ""; }
    ~Vertex() {}
};

#endif // !GRAPH_HPP