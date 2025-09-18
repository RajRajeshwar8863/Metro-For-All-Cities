🚇 All-India Metro Navigator

A powerful and efficient command-line application built in C++ that finds the shortest path between any two metro stations in major Indian cities.
This project leverages graph theory and Dijkstra's algorithm to provide users with a fast, interactive, and intuitive navigation tool.

✨ Features

🏙️ Multi-City Support: Seamlessly switch between metro networks, including Delhi, Mumbai, and Bangalore

⚡️ Fast & Accurate Pathfinding: Implements Dijkstra’s algorithm from scratch for optimal route calculation

🎨 Rich Terminal Interface: Color-coded, clean, and user-friendly command-line UI

📊 Detailed Travel Summary: Shows full route, station count, distance, and estimated fare

🚀 Quick Start
📋 Prerequisites

A C++ compiler (e.g., g++)

🛠️ Installation & Running

Clone the repository:

git clone https://github.com/RajRajeshwar8863/Metro-For-all-Cities.git


Navigate to the project folder:

cd Metro-For-all-Cities


Compile the source code:

g++ main.cpp Graph.cpp -o MetroApp


Run the application:

On Windows (CMD):

MetroApp


On Linux/macOS or PowerShell/Git Bash:

./MetroApp

📁 Project Structure
Metro-For-All-Cities/
├── main.cpp        # Main driver, UI, and program logic
├── Graph.h         # Graph class header
├── Graph.cpp       # Graph algorithms implementation
└── README.md       # Project documentation

🎯 How to Use

Select a City
Choose a metro network (Delhi, Mumbai, or Bangalore).

Choose an Action
Pick an option from that city’s menu.

Find a Route

Select option 3. Get Shortest Path and Fare

Enter Source Station (full name)

Enter Destination Station (full name)

View Results
Get the optimal route, total distance, station count, and fare.

Change City
Use option 4. Change City to return to the main menu.

🏙️ Supported Cities

Delhi Metro

Mumbai Metro

Bangalore Metro

(Easily expandable to more cities in future.)

🛠️ Technical Details

Language: C++

Core Concepts: Graphs + DSA

Data Structures:

Graph: Adjacency List

Priority Queue: std::priority_queue (Min-Heap)

Hash Maps: std::unordered_map, std::map

Algorithm: Dijkstra’s Shortest Path

Interface: Interactive CLI with ANSI colors

🔧 Customization
➕ Adding New City

In Graph.cpp, create a new function:

void Create_NewCity_Map(Graph& g) { ... }


Declare it in Graph.h.

Add the new Graph object in main.cpp under metroSystems.

🤝 Contributing

Contributions are welcome! 🚀

Fork the repo

Create a feature branch

git checkout -b feature/AmazingFeature


Commit your changes

git commit -m "Add some AmazingFeature"


Push to the branch

git push origin feature/AmazingFeature


Open a Pull Request

📝 License

This project is licensed under the MIT License – see the LICENSE
 file for details.

🔮 Future Enhancements

 Add metro networks for Kolkata, Chennai, Hyderabad

 Load metro data from external .csv or .json files

 GUI version using Qt framework

💡 Made with ❤️ in C++ for problem-solving and efficient urban navigation.
