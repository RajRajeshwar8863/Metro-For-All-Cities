# All-India Metro Navigator 🚇

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue.svg)
![License](https://img.shields.io/badge/License-MIT-yellow.svg)

[cite_start]A powerful and efficient command-line application built in C++ that finds the shortest path between any two metro stations in major Indian cities. [cite_start]This project leverages graph theory and Dijkstra's algorithm to provide users with a fast, interactive, and intuitive navigation tool[cite: 1, 2, 3].

---

## 🚀 Live Demo

Here is a quick demonstration of the application's features, from city selection to the final travel summary:

*(This is the perfect spot to add a real GIF of your app! For now, this image shows the final output.)*

![App Demo](https://i.imgur.com/8QjUj5J.png)

---

## ✨ Key Features

* [cite_start]**Multi-City Support** [cite: 3][cite_start]: Seamlessly switch between different metro networks, including Delhi, Mumbai, and Bangalore. [cite_start]The architecture is designed to be easily expandable with new city data[cite: 1].
* [cite_start]**Shortest Path Calculation** [cite: 1][cite_start]: Implements Dijkstra's algorithm from scratch to accurately find the shortest route by distance between any two stations.
* [cite_start]**Detailed Travel Summary** [cite: 3][cite_start]: Provides a clean, color-coded summary of your trip, including:
    * [cite_start]The complete step-by-step route.
    * [cite_start]The total number of stations in the path.
    * [cite_start]The total travel distance in kilometers.
    * [cite_start]An estimated fare for the journey.
* [cite_start]**Interactive Command-Line Interface (CLI)**: A user-friendly, menu-driven interface that makes navigation and input straightforward.

---

## 🛠️ Tech Stack & Concepts

* **Language:** **C++**
* **Core Concepts:** **Data Structures & Algorithms (DSA)**
* **Data Structures:**
    * [cite_start]**Graphs** (Adjacency List implementation) to represent the metro network[cite: 2].
    * [cite_start]**Priority Queue** (`std::priority_queue`) to optimize Dijkstra's algorithm[cite: 1].
    * [cite_start]**Hash Maps** (`std::unordered_map`, `std::map`) for efficient vertex lookups and multi-city management[cite: 2, 3].
* [cite_start]**Algorithm:** **Dijkstra's Shortest Path Algorithm** for route calculation.

---

## ⚙️ How to Compile and Run

Follow these steps to get the project running on your local machine.

### **Prerequisites**
You need a C++ compiler installed on your system (e.g., `g++`).

### **Steps**

1.  **Clone the repository:**
    ```sh
    git clone [https://github.com/your-username/your-repo-name.git](https://github.com/your-username/your-repo-name.git)
    ```
2.  **Navigate to the project directory:**
    ```sh
    cd your-repo-name
    ```
3.  **Compile the source code:**
    ```sh
    g++ main.cpp Graph.cpp -o MetroApp
    ```
4.  **Run the application:**
    * On Windows (Command Prompt):
        ```sh
        MetroApp
        ```
    * On Linux, macOS, or modern Windows terminals (PowerShell/Git Bash):
        ```sh
        ./MetroApp
        ```

---

## 📄 License

This project is licensed under the MIT License.
