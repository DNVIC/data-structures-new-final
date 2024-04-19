#include "MST.h"
#include <queue>
#include <unordered_set>
#include <algorithm>

/*
std::vector<Flight*> MST::primMST(const Graph& graph) {
    std::vector<Flight*> result;

    std::priority_queue<Flight*, std::vector<Flight*>, CompareFlightCost> minHeap;
    std::unordered_set<std::string> visited;
    visited.reserve(graph.getAirports().size());

    // Add flights from the first airport to the heap
    for (const auto& pair : graph.getAirports()) {
        for (Flight* flight : pair.second->getOutgoingFlights()) { // Assuming getOutgoingFlights() returns outgoing flights
            minHeap.push(flight);
        }
        visited.insert(pair.second->getAirportName()); // Assuming getName() returns the airport name
        break;
    }

    // Greedily select the cheapest flight and add it to the MST
    while (!minHeap.empty()) {
        Flight* cheapest = minHeap.top();
        minHeap.pop();

        if (visited.find(cheapest->getDestination()->getName()) == visited.end()) {
            visited.insert(cheapest->getDestination()->getName());
            result.push_back(cheapest);
            for (Flight* flight : cheapest->getDestination()->getOutgoingFlights()) { // Assuming getOutgoingFlights() returns outgoing flights
                minHeap.push(flight);
            }
        }
    }

    return result;
}

std::vector<Flight*> MST::kruskalMST(const Graph& graph) {
    std::vector<Flight*> result;
    std::vector<Flight*> flights;

    // Collect all flights
    for (const auto& pair : graph.getAirports()) {
        for (Flight* flight : pair.second->getOutgoingFlights()) { // Assuming getOutgoingFlights() returns outgoing flights
            flights.push_back(flight);
        }
    }

    // Sort flights by cost and distance
    std::sort(flights.begin(), flights.end(), compareFlightsByCost);

    // Disjoint set data structure for cycle detection
    std::unordered_map<std::string, std::string> parent;

    // Function to find the parent of a node
    auto find = [&](std::string node) -> std::string {
        if (parent.find(node) == parent.end()) {
            parent[node] = node;
        }
        if (parent[node] != node) {
            parent[node] = find(parent[node]);
        }
        return parent[node];
    };

    // Function to merge two sets
    auto merge = [&](std::string node1, std::string node2) {
        std::string parent1 = find(node1);
        std::string parent2 = find(node2);
        if (parent1 != parent2) {
            parent[parent1] = parent2;
        }
    };

    // Iterate through sorted flights
    for (Flight* flight : flights) {
        if (find(flight->getSource()->getName()) != find(flight->getDestination()->getName())) {
            result.push_back(flight);
            merge(flight->getSource()->getName(), flight->getDestination()->getName());
        }
    }

    return result;
}
*/