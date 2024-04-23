#include "Airport.h"
#include "AirportGraph.h"
#include "UndirectedAirportGraph.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

// Function to load airport data from a CSV file
void loadAirportData(const std::string &filename, AirportGraph &graph) {
  std::ifstream file(filename);
  if (!file.is_open()) {
    std::cerr << "Error: Unable to open file " << filename << std::endl;
    return;
  }

  std::string line;
  std::getline(file, line);
  while (std::getline(file, line)) {
    if (line.back() == '\r') { // windows is stupid and puts a \r before every
                               // newline in txt files
      line.pop_back();
    }


    std::string airportCode, airportName, destCode, destName;
    int distance, cost;
    bool inQuotes = false;
    int index = 0;
    int start = 0;
    for (int i = 0; i < line.length(); i++) {
      char c = line.at(i);
      //if (c == '\n') {
      //  break;
      //}
      if(c == '\"') {
        inQuotes = !inQuotes;
      }
      if (!inQuotes && (c == ',' || i == line.length() - 1)) {
        switch (index) {
          case 0:
            airportCode = line.substr(start, i - start);
            start = i + 1;
            break;
          case 1:
            destCode = line.substr(start, i - start);
            start = i + 1;
            break;
          case 2:
            airportName = line.substr(start + 1, i - start - 2);
            start = i + 1;
            break;
          case 3:
            destName = line.substr(start + 1, i - start - 2);
            start = i + 1;
            break;
          case 4:   
            distance = std::stoi(line.substr(start, i - start));
            start = i + 1;
            break;
          case 5:
            cost = std::stoi(line.substr(start, i));
            start = i + 1;
            break;
        }
        index++;
      }
    }
    Airport *airport = graph.getAirportByCode(airportCode);
    if (airport == nullptr)
      airport = new Airport(airportCode, airportName);
    Airport *destAirport = graph.getAirportByCode(destCode);
    if (destAirport == nullptr)
      destAirport = new Airport(destCode, destName);
    graph.addFlight(airport, destAirport, distance, cost);
  }

  file.close();
}


int main() {
  AirportGraph graph;
  loadAirportData("airports.csv", graph);
  std::cout << graph.getAirportByCode("ORD")->getAirportName();
  graph.get_shortest_path(graph.getAirportByCode("IAD"),graph.getAirportByCode("MIA"));
  graph.get_shortest_path(graph.getAirportByCode("PIT"),graph.getAirportByCode("ACT"));
  graph.get_shortest_path_to_state(graph.getAirportByCode("ATL"), "FL");
  graph.get_shortest_path_with_stops(graph.getAirportByCode("IAD"),graph.getAirportByCode("MIA"),3);
  graph.get_shortest_path_with_stops(graph.getAirportByCode("PIT"),graph.getAirportByCode("ACT"),2);
  graph.get_total_connections();
  UndirectedAirportGraph u_g(graph);
  //u_g.print_prims_algorithm();
  u_g.print_kruskals_algorithm();
  return 0;
}
