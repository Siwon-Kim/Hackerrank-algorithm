#include "Graph.hpp"

Graph::~Graph()
{
    // Deconstructor for graphs
    for (const auto elem : adjList)
        delete elem;
    adjList.clear();
}

void Graph::check_two_vertices(std::string label1, std::string label2)
{
    int flag = 0;
    for (itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if ((*itr)->vertex_label == label1)
        {
            flag = 1; // when label1 exists
            break;
        }
    }
    if (flag == 1)
    {
        for (itr = adjList.begin(); itr != adjList.end(); ++itr)
        {
            if ((*itr)->vertex_label == label2)
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
    for (itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if ((*itr)->vertex_label == label)
            throw("There is the vertex already with the same label.\n");
    }

    // Creates and adds a vertex to the graph with label
    Vertex *new_vertex = new Vertex;
    new_vertex->vertex_label = label;
    new_vertex->min_distance = INF;
    adjList.push_back(new_vertex);
}

void Graph::removeVertex(std::string label)
{
    // Removes the vertex with label from the graph
    for (itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if ((*itr)->vertex_label == label)
            adjList.erase(itr);
    }
    // @@ Removes the edges between that vertex and the other vertices of the graph
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

    // @@ There must not already be an edge between those vertices
    for (itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if (((*itr)->vertex_label == label1)) {
            while(itr->next != nullptr) {
                if(itr->next->adjacent_label == label2 && itr->next->edge_value == weight) {
                    throw("The edge already exists between those vertices.\n");
                }
                itr = itr->next;
            }
        } 
    }

    // A vertex cannot have an edge to itself
    if (label1 == label2)
        throw("An edge to itself is not allowed.\n");

    // Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2
    Edge *new_edge = new Edge(weight);
    Vertex *label1;
    Vertex *label2;
    // label1과 label2를 가지고 있는 vertex 찾기
    for (itr = adjList.begin(); itr != adjList.end(); ++itr) {
        if((*itr)->vertex_label == label1) {
            label1 = itr; // itr 인덱스를 label1에 넣기
        }
        if((*itr)->vertex_label == label2) {
            label2 = itr;
        }
    }
    // edge 연결 부여
    new_edge->from = label1;
    new_edge->to = label2;
}

void Graph::removeEdge(std::string label1, std::string label2)
{
    // A vertex with label1 and a vertex with label2 must both exist
    check_two_vertices(label1, label2);

    // There must be an edge between those vertices
    // @@ Removes the edge from the graph between the vertex with label1 and the vertex with label2
    for (itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if ((*itr)->vertex_label == label1)
        {
            while((*itr)->next != nullptr) {
                if(itr->next->adjacent_label == label2) {
                    adjList.erase(itr->next);
                    return;
                }
                itr = itr->next;
            }
        }
    } throw("The first vertex doesn't exist.\n");
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path)
{
    // Calculates the shortest path between the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm
    // start from the first vertex
    for (itr = adjList.begin(); itr != adjList.end(); ++itr)
    {
        if ((*itr)->vertex_label == startLabel)
        {
            (*itr)->min_distance = 0;
            (*itr)->shortest_path.clear();
            (*itr)->shortest_path.push_back(startLabel);
            break;
        }
    }
    pq.push(std::make_pair(0, startLabel));

    while (!pq.empty())
    {
        unsigned long current_distance = pq.top().first;
        bool know_shorter = false;
        std::string current_vertex_label = pq.top().second; // set pq for the smallest value in the root node
        for (itr = adjList.begin(); itr != adjList.end(); ++itr) {
            if((*itr)->vertex_label == current_vertex_label) {
                (*itr)->shortest_path.push_back(current_vertex_label);
                if((*itr)->min_distance < current_distance) 
                    know_shorter = true;
                break;
            }
        }
        pq.pop();
        if(know_shorter) continue; // 만약 지금 꺼낸 것보다 더 짧은 경로를 알고 있는 경우 지금 꺼낸 것 무시

        // 반복문: current_vertex의 adjacent vertices 탐색
        /*  std::string next_vertex_label = **;
            unsigned long next_distance = **;
            long updated_distance = current_distance + next_distance; // 선택된 노드를 인접 노드로 거쳐서 가는 비용
            if(updated_distance < next_vertex->min_distance) {
                next_vertex->min_distance = updated_distance;
                pq.push(make_pair(next_vertex->vertex_label, updated_distance));
            } 
        */

    }

    // A vector is passed into the method that stores the shortest path between the vertices

    // Get the shortest distance
    for (itr = adjList.begin(); itr != adjList.end(); ++itr) {
        if((*itr)->vertex_label == endLabel) {
            shortest_distance = (*itr)->min_distance;
            (*itr)->shortest_path.push_back(endLabel);
            path = (*itr)->shortest_path;
            break;
        }
    }

    // Reset the path
    for (itr = adjList.begin(); itr != adjList.end(); ++itr) {
        (*itr)->min_distance = INF;
        (*itr)->shortest_path = {""};
    }

    // The return value is the sum of the edges between the start and end vertices on the shortest path
    return shortest_distance;
}