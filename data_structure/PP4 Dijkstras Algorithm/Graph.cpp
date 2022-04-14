#include "Graph.hpp"

Graph::~Graph() {
    // Deconstructor for graphs
    for(auto& x : vertices) delete x;
    for(auto& x : edges) delete x;
    vertices.clear();
    edges.clear();
}

void Graph::addVertex(std::string label) {
    // No two vertices should have the same label
    for(std::vector<Vertex*>::iterator itr = vertices.begin(); itr != vertices.end(); ++itr) {
        if((*itr)->vertex_label == label) throw("There is the vertex already with the same label.\n");
    }

    // Creates and adds a vertex to the graph with label
    Vertex* new_vertex = new Vertex;
    new_vertex->vertex_label = label; 
    new_vertex->min_distance = INF; 
    new_vertex->shortest_path = { "" };
    new_vertex->marked = false;
    vertices.push_back(new_vertex);
}

void Graph::removeVertex(std::string label) {
    // Removes the vertex with label from the graph
    for(std::vector<Vertex*>::iterator itr = vertices.begin(); itr != vertices.end(); ++itr) {
        if((*itr)->vertex_label == label) vertices.erase(itr);
    }
    // Removes the edges between that vertex and the other vertices of the graph
    for(std::vector<Edge*>::iterator itr = edges.begin(); itr != edges.end(); ++itr) {
        if(((*itr)->current_edge_label == label) || ((*itr)->adjacent_edge_label == label)) edges.erase(itr);
    }
}

void Graph::addEdge(std::string label1, std::string label2, unsigned long weight) {
    // !!! A vertex with label1 and a vertex with label2 must both exist
    for(std::vector<Vertex*>::iterator itr = vertices.begin(); itr != vertices.end(); ++itr) {
        if((*itr)->vertex_label == label1) {
            
        }
        
        throw("One or both of vertices doesn't exist.\n");
    }

    // There must not already be an edge between those vertices
    for(std::vector<Edge*>::iterator itr = edges.begin(); itr != edges.end(); ++itr) {
        if((*itr)->edge_value) throw("The edge already exists between those vertices.\n");
    }

    // A vertex cannot have an edge to itself
    if(label1 == label2) throw("An edge to itself is not allowed.\n");

    // Adds an edge of value weight to the graph between the vertex with label1 and the vertex with label2
    Edge* new_edge1 = new Edge(label1, label2, weight);
    Edge* new_edge2 = new Edge(label2, label1, weight);
    edges.push_back(new_edge1);
    edges.push_back(new_edge2);
}

void Graph::removeEdge(std::string label1, std::string label2) {
    // !!! A vertex with label1 and a vertex with label2 must both exist


    // There must be an edge between those vertices
    for(std::vector<Edge*>::iterator itr = edges.begin(); itr != edges.end(); ++itr) {
        if(!((*itr)->edge_value)) throw("The edge doesn't exist between those vertices.\n");
    }
    
    // Removes the edge from the graph between the vertex with label1 and the vertex with label2
    for(std::vector<Edge*>::iterator itr = edges.begin(); itr != edges.end(); ++itr) {
        if(((*itr)->current_edge_label == label1) && ((*itr)->adjacent_edge_label == label2)) edges.erase(itr);
    }
}

unsigned long Graph::shortestPath(std::string startLabel, std::string endLabel, std::vector<std::string> &path) {
    // Calculates the shortest path between the vertex with startLabel and the vertex with endLabel using Dijkstra's Algorithm


    // A vector is passed into the method that stores the shortest path between the vertices


    // The return value is the sum of the edges between the start and end vertices on the shortest path
    
}