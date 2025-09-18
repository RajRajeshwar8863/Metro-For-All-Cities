#include "Graph.h"
#include <queue>
#include <algorithm>
#include <map>
#include <climits>

Graph::Graph() {}

void Graph::addVertex(const std::string& vname) {
    if (vtces.find(vname) == vtces.end()) {
        vtces[vname] = Vertex();
    }
}

void Graph::addEdge(const std::string& vname1, const std::string& vname2, int value) {
    if (vtces.find(vname1) == vtces.end() || vtces.find(vname2) == vtces.end()) {
        return;
    }
    vtces[vname1].nbrs[vname2] = value;
    vtces[vname2].nbrs[vname1] = value;
}

bool Graph::containsVertex(const std::string& vname) const {
    return vtces.count(vname);
}

void Graph::display_Stations(const std::string& cityName) const {
    std::cout << "\n******************** " << cityName << " Metro Stations ********************\n";
    int i = 1;
    for (const auto& pair : vtces) {
        std::cout << i++ << ". " << pair.first << std::endl;
    }
    std::cout << "\n******************************************************************\n";
}

void Graph::display_Map(const std::string& cityName) const {
    std::cout << "\t " << cityName << " Metro Map\n";
    std::cout << "\t------------------\n";
    for (const auto& pair : vtces) {
        std::cout << pair.first << " =>\n";
        for (const auto& nbr_pair : pair.second.nbrs) {
            std::cout << "\t" << nbr_pair.first << "\t(" << nbr_pair.second << " KM)\n";
        }
        std::cout << std::endl;
    }
    std::cout << "\t------------------\n";
}

bool Graph::hasPath(const std::string& vname1, const std::string& vname2) {
    std::map<std::string, bool> processed;
    std::queue<std::string> q;

    q.push(vname1);
    processed[vname1] = true;

    while(!q.empty()) {
        std::string current = q.front();
        q.pop();

        if(current == vname2) return true;

        for(const auto& nbr_pair : vtces[current].nbrs) {
            if(processed.find(nbr_pair.first) == processed.end()) {
                q.push(nbr_pair.first);
                processed[nbr_pair.first] = true;
            }
        }
    }
    return false;
}

// This function now returns the full DijkstraPair with the path string and cost
Graph::DijkstraPair Graph::getShortestPath(const std::string& src, const std::string& dst) {
    std::priority_queue<DijkstraPair> pq;
    std::unordered_map<std::string, bool> visited;

    pq.push({src, src, 0});
    
    while (!pq.empty()) {
        DijkstraPair current = pq.top();
        pq.pop();

        if (visited.count(current.vname)) {
            continue;
        }
        visited[current.vname] = true;

        if (current.vname == dst) {
            return current; // Return the pair with path and cost
        }

        for (const auto& nbr_pair : vtces[current.vname].nbrs) {
            if (!visited.count(nbr_pair.first)) {
                pq.push({
                    nbr_pair.first,
                    current.psf + " " + nbr_pair.first,
                    current.cost + nbr_pair.second
                });
            }
        }
    }
    return {"", "", -1}; // Path not found
}


// --- NEW: City-Specific Map Creation Functions ---

void Create_Delhi_Map(Graph& g) {
    g.addVertex("Noida Sector 62~B");
    g.addVertex("Botanical Garden~B");
    g.addVertex("Yamuna Bank~B");
    g.addVertex("Rajiv Chowk~BY");
    g.addVertex("Vaishali~B");
    g.addVertex("Moti Nagar~B");
    g.addVertex("Janak Puri West~BO");
    g.addVertex("Dwarka Sector 21~B");
    g.addVertex("Huda City Center~Y");
    g.addVertex("Saket~Y");
    g.addVertex("Vishwavidyalaya~Y");
    g.addVertex("Chandni Chowk~Y");
    g.addVertex("New Delhi~YO");
    g.addVertex("AIIMS~Y");
    g.addVertex("Shivaji Stadium~O");
    g.addVertex("DDS Campus~O");
    g.addVertex("IGI Airport~O");
    g.addVertex("Rajouri Garden~BP");
    g.addVertex("Netaji Subhash Place~PR");
    g.addVertex("Punjabi Bagh West~P");

    g.addEdge("Noida Sector 62~B", "Botanical Garden~B", 8);
    g.addEdge("Botanical Garden~B", "Yamuna Bank~B", 10);
    g.addEdge("Yamuna Bank~B", "Vaishali~B", 8);
    g.addEdge("Yamuna Bank~B", "Rajiv Chowk~BY", 6);
    g.addEdge("Rajiv Chowk~BY", "Moti Nagar~B", 9);
    g.addEdge("Moti Nagar~B", "Janak Puri West~BO", 7);
    g.addEdge("Janak Puri West~BO", "Dwarka Sector 21~B", 6);
    g.addEdge("Huda City Center~Y", "Saket~Y", 15);
    g.addEdge("Saket~Y", "AIIMS~Y", 6);
    g.addEdge("AIIMS~Y", "Rajiv Chowk~BY", 7);
    g.addEdge("Rajiv Chowk~BY", "New Delhi~YO", 1);
    g.addEdge("New Delhi~YO", "Chandni Chowk~Y", 2);
    g.addEdge("Chandni Chowk~Y", "Vishwavidyalaya~Y", 5);
    g.addEdge("New Delhi~YO", "Shivaji Stadium~O", 2);
    g.addEdge("Shivaji Stadium~O", "DDS Campus~O", 7);
    g.addEdge("DDS Campus~O", "IGI Airport~O", 8);
    g.addEdge("Moti Nagar~B", "Rajouri Garden~BP", 2);
    g.addEdge("Punjabi Bagh West~P", "Rajouri Garden~BP", 2);
    g.addEdge("Punjabi Bagh West~P", "Netaji Subhash Place~PR", 3);
}

void Create_Mumbai_Map(Graph& g) {
    // Example data, you can find real data online to make this accurate
    g.addVertex("Ghatkopar");
    g.addVertex("Sakinaka");
    g.addVertex("Andheri");
    g.addVertex("Dahisar");
    g.addVertex("CSMT");
    
    g.addEdge("Ghatkopar", "Sakinaka", 4);
    g.addEdge("Sakinaka", "Andheri", 5);
    g.addEdge("Andheri", "Dahisar", 15);
    g.addEdge("Ghatkopar", "CSMT", 20); // Not a real direct line, just for example
}

void Create_Bangalore_Map(Graph& g) {
    // Example data for Namma Metro
    g.addVertex("Baiyappanahalli");
    g.addVertex("MG Road");
    g.addVertex("Majestic");
    g.addVertex("Mysore Road");
    
    g.addEdge("Baiyappanahalli", "MG Road", 6);
    g.addEdge("MG Road", "Majestic", 4);
    g.addEdge("Majestic", "Mysore Road", 7);
}
