#ifndef GRAPH_H
#define GRAPH_H

#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

class Graph {
private:
    struct Vertex {
        std::unordered_map<std::string, int> nbrs; // Neighbor name -> weight
    };
    std::unordered_map<std::string, Vertex> vtces;

public:
    Graph();
    void addVertex(const std::string& vname);
    void addEdge(const std::string& vname1, const std::string& vname2, int value);
    void display_Stations(const std::string& cityName) const;
    void display_Map(const std::string& cityName) const;
    bool hasPath(const std::string& vname1, const std::string& vname2);

    struct DijkstraPair {
        std::string vname;
        std::string psf; // Path so far
        int cost;

        bool operator<(const DijkstraPair& other) const {
            return this->cost > other.cost;
        }
    };

    DijkstraPair getShortestPath(const std::string& src, const std::string& dst);
    
    bool containsVertex(const std::string& vname) const;
};

// Declarations for city-specific map creation functions
void Create_Delhi_Map(Graph& g);
void Create_Mumbai_Map(Graph& g);
void Create_Bangalore_Map(Graph& g);

#endif // GRAPH_H