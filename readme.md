All-India Metro Navigator 🚇
A powerful and efficient command-line application built in C++ that finds the shortest path between any two metro stations in major Indian cities. This project leverages graph theory and Dijkstra's algorithm to provide users with a fast, interactive, and intuitive navigation tool.

✨ Features
🏙️ Multi-City Support: Seamlessly switch between different metro networks, including Delhi, Mumbai, and Bangalore.

⚡️ Fast & Accurate Pathfinding: Implements Dijkstra's algorithm from scratch for optimal and efficient shortest route calculation.

🎨 Rich Terminal Interface: A clean, color-coded, and user-friendly interface for an intuitive experience.

📊 Detailed Travel Summary: Provides a comprehensive summary including the full route, distance, station count, and an estimated fare.

🚀 Quick Start
Prerequisites
A C++ compiler (e.g., g++)

Installation & Running
Clone the repository:

Bash

git clone https://github.com/RajRajeshwar8863/Metro-For-All-Cities.git
Navigate to the project directory:

Bash

cd Metro-For-All-Cities
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
📁 Project Structure
Metro-For-All-Cities/
├── main.cpp                 # Main application driver, UI, and logic
├── Graph.h                  # Header file for the Graph class
├── Graph.cpp                # Implementation of the Graph class and algorithms
└── README.md                # This file
📸 Screenshots Of Project
(A GIF is highly recommended here to showcase the app's functionality! Replace the placeholder links below with your actual images.)

City Selection Menu:
![City Selection Menu](path/to/your/city_selection_image.png)

Final Travel Summary:
![Final Travel Summary](path/to/your/summary_image.png)

🎯 How to Use
Select a City: When the application starts, choose a city from the list.

Choose an Action: Select an option from that city's metro menu.

Find a Route:

Select option 3. Get Shortest Path and Fare.

Enter the full name of the Source Station.

Enter the full name of the Destination Station.

View Results: The application will display a detailed summary of the optimal route.

Change City: Select option 4. Change City to return to the main city selection screen.

🏙️ Supported Cities
The application currently supports navigation for the following metro networks:

Delhi

Mumbai

Bangalore

The architecture is designed to be easily expandable for more cities.

🛠️ Technical Details
Backend Logic: C++

Core Concepts: Data Structures & Algorithms (DSA)

Data Structures:

Graph: Adjacency List implementation to represent the metro network.

Priority Queue: std::priority_queue used as a Min-Heap to optimize Dijkstra's algorithm.

Hash Maps: std::unordered_map and std::map for efficient vertex lookups and multi-city management.

Algorithm: Dijkstra's Shortest Path Algorithm for route calculation.

Interface: Interactive Command-Line Interface (CLI) with ANSI color codes for a rich user experience.

🔧 Customization
Adding a new city to the navigator is simple:

Add City Data: In Graph.cpp, create a new function void Create_NewCity_Map(Graph& g) and populate it with the new city's station and connection data.

Declare the Function: Add the function declaration void Create_NewCity_Map(Graph& g); to Graph.h.

Integrate into Main: In main.cpp, create a new Graph object for the city and add it to the metroSystems map.

🤝 Contributing
Contributions are welcome! Please feel free to fork the repository, create a feature branch, and open a pull request.

Fork the Project

Create your Feature Branch (git checkout -b feature/AmazingFeature)

Commit your Changes (git commit -m 'Add some AmazingFeature')

Push to the Branch (git push origin feature/AmazingFeature)

Open a Pull Request

📝 License
This project is licensed under the MIT License - see the LICENSE file for details.

🔮 Future Enhancements
[ ] Add metro networks for more cities (Kolkata, Chennai, Hyderabad).

[ ] Load metro data from external files (.csv or .json) for better scalability.

[ ] Develop a Graphical User Interface (GUI) using a framework like Qt.

Made with ❤️ using C++ and a passion for problem-solving.
