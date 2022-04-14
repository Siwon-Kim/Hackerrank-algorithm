#include "Graph.hpp"

Graph::~Graph()
{
    // Deconstructor for graphs
    for (const auto elem : vertices)
        delete elem;
    for (const auto elem : edges)
        delete elem;
    vertices.clear();
    edges.clear();
}

void Graph::check_two_vertices(std::string label1, std::string label2)
{
    int flag = 0;
    for (vtx_itr = vertices.begin(); vtx_itr != vertices.end(); ++vtx_itr)
    {
        if ((*vtx_itr)->vertex_label == label1)
        {
            flag = 1; // when label1 exists
            break;
        }
    }
    if (flag == 1)
    {
        for (vtx_itr = vertices.begin(); vtx_itr != vertices.end(); ++vtx_itr)
        {
            if ((*vtx_itr)->vertex_label == label2)
            {
                flag = 2; // when both label1 and label2 exist
                break;
            }
        }
    }

    if (flag != 2)
        throw("One or both of vertices doesn't exist.\n");
}

void Graph::addVertex(std::string label)
{
    // No two vertices should have the same label
    for (vtx_itr = vertices.begin(); vtx_itr != vertices.end(); ++vtx_itr)
    {
        if ((*vtx_itr)->vertex_label == label)
            throw("There is the vertex already with the same label.\n");
    }

    // Creates and adds a vertex to the graph with label
    Vertex *new_vertex = new Vertex;
    new_vertex->vertex_label = label;
    new_vertex->min_distance = INF;
    new_vertex->shortest_path = {""};
    new_vertex->isVisited = false;
    vertices.push_back(new_vertex);
}

void Graph::removeVertex(std::string label)
{
    // Removes the vertex with label from the graph
    for (vtx_itr = vertices.begin(); vtx_itr != vertices.end(); ++vtx_itr)
    {
        if ((*vtx_itr)->vertex_label == label)
            vertices.erase(vtx_itr);
    }
    // Removes the edges between that vertex and the other vertices of the graph
    for (edg_itr = edges.begin(); edg_itr != edges.end(); ++edg_itr)
    {
        if (((*edg_itr)->current_edge_label == label) || ((*edg_itr)->adjacent_edge_label == label))
            edges.erase(edg_itr);
    }
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    // A vertex with label1 and a vertex with label2 must both exist
    check_two_vertices(label1, label2);

    // There must not already be an edge between those vertices
    for (edg_itr = edges.begin(); edg_itr != edges.end(); ++edg_itr)
    {
        if (((*edg_itr)->current_edge_label == label1) && ((*edg_itr)->adjacent_edge_label == label2) && ((*edg_itr)->edge_value == weight))
            throw("The edge already exists between those vertices.\n");
    }

    // A vertex cannot have an edge to itself
    if (label1 == label2)
        throw("An edge to itself is not allowed.\n");

    // Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2
    Edge *new_edge1 = new Edge(label1, label2, weight);
    Edge *new_edge2 = new Edge(label2, label1, weight);
    edges.push_back(new_edge1);
    edges.push_back(new_edge2);
}

void Graph::removeEdge(std::string label1, std::string label2)
{
    // A vertex with label1 and a vertex with label2 must both exist
    check_two_vertices(label1, label2);

    // There must be an edge between those vertices
    int flag = 0;
    for (edg_itr = edges.begin(); edg_itr != edges.end(); ++edg_itr)
    {
        if (((*edg_itr)->current_edge_label == label1) && ((*edg_itr)->adjacent_edge_label == label2))
        {
            flag = 1;
            break;
        }
    }
    if (flag == 1)
    {
        // Removes the edge from the graph between the vertex with label1 and the vertex with label2
        for (edg_itr = edges.begin(); edg_itr != edges.end(); ++edg_itr)
        {
            if (((*edg_itr)->current_edge_label == label1) && ((*edg_itr)->adjacent_edge_label == label2))
                edges.erase(edg_itr);
        }
    }
    else
        throw("The edge already exists between those vertices.\n");
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    // Calculates the shortest path between the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm

    // A vector is passed into the method that stores the shortest path between the vertices

    // The return value is the sum of the edges between the start and end vertices on the shortest path
}