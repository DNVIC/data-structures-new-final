#pragma once
#include "Airport.h"
#include <unordered_map>
#include <vector>

class AirportGraph {
public:
  void addFlight(Airport *source, Airport *destination, int distance, int cost);
  Airport *getAirportByCode(const std::string &airportCode);
  int get_airport_index(Airport* airport);
  int get_shortest_path(Airport *src, Airport *dest);
  void countDirectConnections();
  void createUndirectedGraph();
 
  ~AirportGraph();

private:
  void clean_visited();
  std::vector<Airport *> airports;
  std::vector<std::vector<Flight*>> flights;
};