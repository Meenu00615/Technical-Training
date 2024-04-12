#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the total cost of a tour
int calculateCost(vector<vector<int>>& graph, vector<int>& tour) {
    int cost = 0;
    int n = graph.size();
    for (int i = 0; i < n - 1; i++) {
        cost += graph[tour[i]][tour[i + 1]];
    }
    // Add the cost of returning to the starting city
    cost += graph[tour[n - 1]][tour[0]];
    return cost;
}

// Function to find the minimum cost using a naive approach
int travelingSalesmanNaive(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> tour(n);
    for (int i = 0; i < n; i++) {
        tour[i] = i;
    }
    int minCost = INT_MAX;
    do {
        // Check if the current tour is a valid tour
        if (tour[0] == start) {
            int currentCost = calculateCost(graph, tour);
            minCost = min(minCost, currentCost);
        }
    } while (next_permutation(tour.begin(), tour.end()));
    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // Define the graph as an adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int startCity;
    cout << "Enter the index of the starting city: ";
    cin >> startCity;

    // Call the travelingSalesmanNaive function
    int minCost = travelingSalesmanNaive(graph, startCity);

    // Output the result
    cout << "Minimum cost of the tour: " << minCost << endl;

    return 0;
}#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

// Function to calculate the total cost of a tour
int calculateCost(vector<vector<int>>& graph, vector<int>& tour) {
    int cost = 0;
    int n = graph.size();
    for (int i = 0; i < n - 1; i++) {
        cost += graph[tour[i]][tour[i + 1]];
    }
    // Add the cost of returning to the starting city
    cost += graph[tour[n - 1]][tour[0]];
    return cost;
}

// Function to find the minimum cost using a naive approach
int travelingSalesmanNaive(vector<vector<int>>& graph, int start) {
    int n = graph.size();
    vector<int> tour(n);
    for (int i = 0; i < n; i++) {
        tour[i] = i;
    }
    int minCost = INT_MAX;
    do {
        // Check if the current tour is a valid tour
        if (tour[0] == start) {
            int currentCost = calculateCost(graph, tour);
            minCost = min(minCost, currentCost);
        }
    } while (next_permutation(tour.begin(), tour.end()));
    return minCost;
}

int main() {
    int n;
    cout << "Enter the number of cities: ";
    cin >> n;

    // Define the graph as an adjacency matrix
    vector<vector<int>> graph(n, vector<int>(n));

    cout << "Enter the adjacency matrix for the graph:\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    int startCity;
    cout << "Enter the index of the starting city: ";
    cin >> startCity;

    // Call the travelingSalesmanNaive function
    int minCost = travelingSalesmanNaive(graph, startCity);

    // Output the result
    cout << "Minimum cost of the tour: " << minCost << endl;

    return 0;
}

