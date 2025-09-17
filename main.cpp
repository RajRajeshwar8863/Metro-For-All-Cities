#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream> // Required for splitting the path string

#include "Graph.h"

// --- ANSI Color Codes for a more professional look ---
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define RED     "\033[31m"

// --- Function to split a string by a delimiter ---
std::vector<std::string> split(const std::string& s, char delimiter) {
    std::vector<std::string> tokens;
    std::string token;
    std::istringstream tokenStream(s);
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

// --- Main application menu ---
void printMainMenu(const std::string& cityName) {
    std::cout << BOLD << "\n\n**** " << cityName << " METRO MENU ****" << RESET << std::endl;
    std::cout << "1. List All Stations" << std::endl;
    std::cout << "2. Show Metro Map" << std::endl;
    std::cout << "3. Get Shortest Path and Fare" << std::endl;
    std::cout << "4. Change City" << std::endl;
    std::cout << "5. Exit Application" << std::endl;
    std::cout << "Enter your choice: ";
}


int main() {
    // --- Setup all metro systems ---
    std::map<std::string, Graph> metroSystems;
    std::vector<std::string> cityNames;

    Graph delhiGraph;
    Create_Delhi_Map(delhiGraph);
    metroSystems["Delhi"] = delhiGraph;
    cityNames.push_back("Delhi");

    Graph mumbaiGraph;
    Create_Mumbai_Map(mumbaiGraph);
    metroSystems["Mumbai"] = mumbaiGraph;
    cityNames.push_back("Mumbai");

    Graph bangaloreGraph;
    Create_Bangalore_Map(bangaloreGraph);
    metroSystems["Bangalore"] = bangaloreGraph;
    cityNames.push_back("Bangalore");

    // --- Main Application Loop ---
    while (true) {
        // --- City Selection ---
        std::cout << BOLD << BLUE << "\n**** WELCOME TO THE ALL-INDIA METRO NAVIGATOR ****" << RESET << std::endl;
        std::cout << "Please select a city to begin:" << std::endl;
        for (size_t i = 0; i < cityNames.size(); ++i) {
            std::cout << i + 1 << ". " << cityNames[i] << std::endl;
        }
        std::cout << cityNames.size() + 1 << ". Exit" << std::endl;
        std::cout << "Enter your choice: ";
        
        int cityChoice;
        std::cin >> cityChoice;

        if (cityChoice > cityNames.size() || cityChoice <= 0) {
            std::cout << BOLD << RED << "Exiting application. Goodbye!" << RESET << std::endl;
            return 0;
        }

        std::string selectedCityName = cityNames[cityChoice - 1];
        Graph& selectedGraph = metroSystems.at(selectedCityName);

        // --- Metro Menu Loop for the selected city ---
        int menuChoice = 0;
        while (menuChoice != 4) {
            printMainMenu(selectedCityName);
            std::cin >> menuChoice;
            std::cin.ignore(); 

            switch (menuChoice) {
                case 1:
                    selectedGraph.display_Stations(selectedCityName);
                    break;
                case 2:
                    selectedGraph.display_Map(selectedCityName);
                    break;
                case 3: {
                    std::string src, dst;
                    std::cout << GREEN << "Enter the Source Station: " << RESET;
                    std::getline(std::cin, src);
                    std::cout << RED << "Enter the Destination Station: " << RESET;
                    std::getline(std::cin, dst);

                    if (!selectedGraph.containsVertex(src) || !selectedGraph.containsVertex(dst) || !selectedGraph.hasPath(src, dst)) {
                        std::cout << BOLD << RED << "\nINVALID INPUT! One or both stations do not exist or there is no path.\n" << RESET;
                    } else {
                        Graph::DijkstraPair result = selectedGraph.getShortestPath(src, dst);
                        std::vector<std::string> path = split(result.psf, ' ');

                        // --- NEW: Display the improved summary with Emojis ---
                        std::cout << BOLD << "\n======================================================\n" << RESET;
                        std::cout << BOLD << "              YOUR TRAVEL SUMMARY\n" << RESET;
                        std::cout << BOLD << "======================================================\n" << RESET;
                        std::cout << "🟢 FROM: " << src << "\n";
                        std::cout << "🔴 TO:   " << dst << "\n";
                        std::cout << "------------------------------------------------------\n";
                        std::cout << BOLD << "ROUTE:\n" << RESET;
                        for(const auto& station : path) {
                            std::cout << "  -> " << station << "\n";
                        }
                        std::cout << "------------------------------------------------------\n";
                        std::cout << BOLD << "STATS:\n" << RESET;
                        std::cout << "  🚉 Total Stations: " << path.size() << "\n";
                        std::cout << "  ↔️  Distance: " << result.cost << " KM\n";
                        float fare = 10.0 + result.cost * 2.5; // Example fare calculation
                        std::cout << "  💰 Estimated Fare: Rs. " << fare << ".00\n";
                        std::cout << BOLD << "======================================================\n" << RESET;
                    }
                    break;
                }
                case 4:
                    std::cout << YELLOW << "Changing city...\n" << RESET;
                    break;
                case 5:
                    std::cout << BOLD << RED << "Exiting application. Goodbye!" << RESET << std::endl;
                    return 0;
                default:
                    std::cout << BOLD << RED << "Invalid choice. Please try again.\n" << RESET;
                    break;
            }
        }
    }

    return 0;
}