#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "GraphBase.hpp"

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>

const unsigned long INF = 99999;
std::string REMOVED = "Removed";
typedef std::pair<unsigned long, std::string> Pair;

class Graph : public GraphBase
{
private:
    std::string vertices[101];                                           // contains the vertices
    unsigned long distance[101];                                         // contains the distance of each vertex
    std::vector<Pair> adjMatrix[101];                                    // contains the adjacent vertices
    std::priority_queue<Pair, std::vector<Pair>, std::greater<Pair>> pq; // priority queue with the smallest value in the root
    std::vector<std::string> shortest_path;                              // keeps the shortest paths in the vector
    unsigned long shortest_distance = 0;                                 // gets the shortest distance of the path
    int vtx_count = -1;                                                  // counts the number of vertices

protected:
    void check_two_vertices(std::string label1, std::string label2); // check if two vertices exist

public:
    Graph() {}
    ~Graph();
    void addVertex(std::string label);
    void removeVertex(std::string label);
    void addEdge(std::string label1, std::string label2, unsigned long weight);
    void removeEdge(std::string label1, std::string label2);
    unsigned long shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path);
};

#endif // !GRAPH_HPP