All-India Metro Navigator 🚇

A powerful and efficient command-line application built in C++ that finds the shortest path between any two metro stations in major Indian cities. This project leverages graph theory and Dijkstra's algorithm to provide users with a fast, interactive, and intuitive navigation tool.

🚀 Live Demo
Here is a quick demonstration of the application's features, from city selection to the final travel summary:

(This is the perfect spot to add a real GIF of your app! For now, this image shows the final output.)

✨ Key Features
Multi-City Support: Seamlessly switch between different metro networks, including Delhi, Mumbai, and Bangalore. The architecture is designed to be easily expandable with new city data.

Shortest Path Calculation: Implements Dijkstra's algorithm from scratch to accurately find the shortest route by distance between any two stations.

Detailed Travel Summary: Provides a clean, color-coded summary of your trip, including:

The complete step-by-step route.

The total number of stations in the path.

The total travel distance in kilometers.

An estimated fare for the journey.

Interactive Command-Line Interface (CLI): A user-friendly, menu-driven interface that makes navigation and input straightforward.

🛠️ Tech Stack & Concepts
Language: C++

Core Concepts: Data Structures & Algorithms (DSA)

Data Structures:

Graphs (Adjacency List implementation) to represent the metro network.

Priority Queue (std::priority_queue) to optimize Dijkstra's algorithm.

Hash Maps (std::unordered_map, std::map) for efficient vertex lookups and multi-city management.

Algorithm: Dijkstra's Shortest Path Algorithm for route calculation.

⚙️ How to Compile and Run
Follow these steps to get the project running on your local machine.

Prerequisites
You need a C++ compiler installed on your system (e.g., g++).

Steps
Clone the repository:

Bash

git clone https://github.com/your-username/your-repo-name.git
Navigate to the project directory:

Bash

cd your-repo-name
Compile the source code:

Bash

g++ main.cpp Graph.cpp -o MetroApp
Run the application:

On Windows (Command Prompt):

Bash

MetroApp
On Linux, macOS, or modern Windows terminals (PowerShell/Git Bash):

Bash

./MetroApp
📄 License
This project is licensed under the MIT License.
