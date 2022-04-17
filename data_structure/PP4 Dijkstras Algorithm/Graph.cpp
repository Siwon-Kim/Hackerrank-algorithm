#include "Graph.hpp"

Graph::~Graph()
{
    // Deconstructor for graphs
}

void Graph::check_two_vertices(std::string label1, std::string label2)
{
    int flag = 0;
    for (int i = 0; i <= vtx_count; i++)
    {
        if (vertices[i] == label1)
        {
            flag = 1; // when label1 exists
            break;
        }
    }
    if (flag == 1)
    {
        for (int i = 0; i <= vtx_count; i++)
        {
            if (vertices[i] == label2)
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
    if (vtx_count != -1)
    {
        for (int i = 0; i <= vtx_count; i++)
        {
            if (vertices[i] == label)
                throw("There is the vertex already with the same label.\n");
        }
    }

    // Creates and adds a vertex to the graph with label
    vtx_count++;
    vertices[vtx_count] = label;
    distance[vtx_count] = INF;
}

void Graph::removeVertex(std::string label)
{
    // Removes the vertex with label from the graph
    for (int i = 0; i <= vtx_count; i++)
    {
        if (vertices[i] == label)
        {
            vertices[i] = REMOVED;
            distance[i] = 0;
        }
    }
    // Removes the edges between that vertex and the other vertices of the graph
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight)
{
    // A vertex with label1 and a vertex with label2 must both exist
    check_two_vertices(label1, label2);

    // There must not already be an edge between those vertices
    int idx_label1, idx_label2;
    for (int i = 0; i <= vtx_count; i++)
    {
        if (vertices[i] == label1)
        {
            idx_label1 = i;
            for (int j = 0; j < vtx_count; j++)
            {
                if (adjMatrix[i][j].second == label2)
                {
                    idx_label2 = j;
                    throw("The edge already exists between those vertices.\n");
                }
            }
        }
    }

    // A vertex cannot have an edge to itself
    if (label1 == label2)
        throw("An edge to itself is not allowed.\n");

    // Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2
    adjMatrix[idx_label1].push_back(make_pair(weight, label2));
    adjMatrix[idx_label2].push_back(make_pair(weight, label1));
}

void Graph::removeEdge(std::string label1, std::string label2)
{
    // A vertex with label1 and a vertex with label2 must both exist
    check_two_vertices(label1, label2);

    // There must be an edge between those vertices
    bool isEdge = false;
    for (int i = 0; i <= vtx_count; i++)
    {
        if (vertices[i] == label1)
        {
            for (int j = 0; j < vtx_count; j++)
            {
                if (adjMatrix[i][j].second == label2)
                {
                    isEdge = true;
                    break;
                }
            }
            if (!isEdge)
                throw("The edge doesn't exist between those vertices.\n");
        }
    }
    // Removes the edge from the graph between the vertex with label1 and the vertex with label2
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    // Calculates the shortest path between the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm
    int idx_start, idx_end;
    for (int i = 0; i <= vtx_count; i++)
    {
        if (vertices[i] == startLabel)
            idx_start = i;
        else if (vertices[i] == endLabel)
            idx_end = i;
    }
    distance[idx_start] = 0;
    pq.push(make_pair(0, startLabel)); // start pq from the first vertex

    // A vector is passed into the method that stores the shortest path between the vertices
    while (!pq.empty())
    {
        unsigned long curr_distance = pq.top().first;
        std::string curr_vertex = pq.top().second;
        int idx_curr;
        for (int i = 0; i <= vtx_count; i++)
            if (vertices[i] == curr_vertex)
                idx_curr = i;
        shortest_path.push_back(curr_vertex);
        pq.pop();

        if (distance[idx_curr] < curr_distance)
            continue; // skip when the current distance is not a shortest

        for (int i = 0; i <= vtx_count; i++)
        { // iterate through all adjacent vertices
            unsigned long next_distance = distance[idx_curr] + curr_distance;
            std::string next_vertex_label = adjMatrix[idx_curr][i].second;
            int idx_next;
            for (int i = 0; i <= vtx_count; i++)
                if (vertices[i] == next_vertex_label)
                    idx_next = i;
            if (next_distance < distance[idx_next])
            {
                distance[idx_next] = next_distance;
                pq.push(make_pair(next_distance, next_vertex_label));
            }
        }
    }

    // Get the shortest distance
    shortest_distance = distance[idx_end];
    shortest_path.push_back(endLabel);
    path = shortest_path;

    // The return value is the sum of the edges between the start and end vertices on the shortest path
    return shortest_distance;
}