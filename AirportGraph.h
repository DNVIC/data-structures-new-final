#pragma once
#include "Airport.h"
#include <unordered_map>
#include <vector>
#include <iostream>



class al { // helper class, simple enough to keep in header
    public:
        std::vector<Airport*> path;
        int length;
        int cost;
        al(int l, int c) {
            length = l;
            cost = c;
        }
        al(std::vector<Airport *> p, int l, int c) {
            path = p;
            length = l;
            cost = c;
        }
        bool operator>(const al &x) const { return length > x.length; }
        bool operator<(const al &x) const { return length < x.length; }
}; 

class AirportGraph {
public:
  void addFlight(Airport *source, Airport *destination, int distance, int cost);
  Airport *getAirportByCode(std::string airportCode);
  int get_airport_index(Airport* airport);
  void get_shortest_path(Airport *src, Airport *dest);
  void get_shortest_path_to_state(Airport *src, std::string state);
  void get_shortest_path_with_stops(Airport *src, Airport *dest, int stops);
  void get_total_connections();
  ~AirportGraph();
  std::vector<Airport *> airports;
  std::vector<std::vector<Flight*>> flights;

private:
  void recursiveHelper(std::vector<Airport*>& output, const std::vector<Airport*>& prev, int i);
  int recursiveHelper2(const std::vector<Airport*>& prev, int i);
  al depthFirstSearch(Airport *cur, Airport* target, int i);
};
