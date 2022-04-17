#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <tuple>

const unsigned long INF = 999999999999;
typedef std::pair<unsigned long, std::string> Pair;

class Edge
{
private:
    unsigned long edge_value;
    Vertex* from;
    Vertex* to;

public:
    friend class Graph;
    Edge(unsigned long val = 0)
    {
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

    struct Vertex* next;

public:
    friend class Graph;
    Vertex() { vertex_label = ""; }
    ~Vertex() {}
};

class Graph : public GraphBase
{
private:
    std::vector<Vertex*> adjList;
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq;
    std::vector<Vertex*>::iterator itr;
    unsigned long shortest_distance;

protected:
    void check_two_vertices(std::string label1, std::string label2);

public:
    Graph() { }
    ~Graph();
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};

#endif // !GRAPH_HPP