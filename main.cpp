#include "Airport.h"
#include "AirportGraph.h"
//#include "MST.h"
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

    // std::stringstream ss(line);
    std::string airportCode, airportName, destCode, destName;
    int distance, cost;
    bool inQuotes = false;
    int index = 0;
    int start = 0;
    for (int i = 0; i < line.length(); i++) {
      char c = line.at(i);
      if (c == '\n') {
        break;
      }
      if(c == '\"') {
        inQuotes = !inQuotes;
      }
      if (!inQuotes && c == ',') {
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
            cost = std::stoi(line.substr(start, i - start));
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
  //std::cout << graph.getAirportByCode("ORD")->getAirportName();
  std::cout << graph.get_shortest_path(graph.getAirportByCode("ORD"),graph.getAirportByCode("ATL"));
  /*
    //I commented all this out for now, that way I could resove syntax
    //issues and other problems with the graph. Getting the fundamental building
    //blocks of the program (in this case, the graph) is much more important
    //than working on the MST stuff at the start, as if the graph is implemented
    //incorrectly, the entire program needs to be rewritten, since it's the
    //basis on which everything else is built



      // Load airport data
      loadAirportData("airports.csv", graph);


      // Compute MST using Prim's algorithm
      std::vector<Flight*> primMST = MST::primMST(graph);
      std::cout << "MST using Prim's algorithm:\n";
      for (Flight* flight : primMST) {
          std::cout << flight->getSource()->getAirportCode() << " -> " <<
    flight->getDestination()->getAirportCode() << "\n";
      }

      // Compute MST using Kruskal's algorithm
      std::vector<Flight*> kruskalMST = MST::kruskalMST(graph);
      std::cout << "\nMST using Kruskal's algorithm:\n";
      for (Flight* flight : kruskalMST) {
          std::cout << flight->getSource()->getAirportCode() << " -> " <<
    flight->getDestination()->getAirportCode() << "\n";
      }

      // Cleanup
      for (const auto& pair : graph.getAirports()) {
          delete pair.second;
      }
      for (Flight* flight : graph.getFlights()) {
          delete flight;
      }
  */
  return 0;
}
