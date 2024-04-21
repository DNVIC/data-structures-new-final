#include "AirportGraph.h"
#include "Flight.h"
#include <iostream>
#include <vector>
#include "MinHeap.h"
#include "MinHeap.cpp"

AirportGraph::~AirportGraph() {
  for (Airport *airport : airports) {
    delete airport;
  }
  // for (Flight *flight : flights) {
  //   delete flight;
  // }
}

void AirportGraph::addFlight(Airport *source, Airport *destination,
                             int distance, int cost) {
  int flag = 0;
  for (Airport *airport : airports) { // sets flag based on if the airport
                                      // already exists in the graph
    if (source == airport) {
      flag += 1;
    }
    if (destination == airport) {
      flag += 2;
    }
  }
  switch (flag) { // uses flag to add airports to graph if not already existing
  case 0: {
    airports.push_back(source);
    std::vector<Flight *> tmp;
    flights.push_back(tmp);
  }
  case 1: {
    airports.push_back(destination);
    std::vector<Flight *> tmp1;
    flights.push_back(tmp1);
  } break;
  case 2: {
    airports.push_back(source);
    std::vector<Flight *> tmp2;
    flights.push_back(tmp2);
  } break;
  }
  flights[get_airport_index(source)].push_back(
      new Flight(source, destination, distance, cost));
}

Airport *AirportGraph::getAirportByCode(std::string airportCode) {
  for (Airport *airport : airports) {
    if (airport->getAirportCode() == airportCode) {
      return airport;
    }
  }
  return nullptr;
}

int AirportGraph::get_airport_index(Airport *airport) {
  for (int i = 0; i < airports.size(); i++) {
    if (airport == airports[i]) {
      return i;
    }
  }
  return -1;
}

void AirportGraph::clean_visited() {
  for (Airport *airport : airports) {
    airport->isVisited = false;
  }
}

int AirportGraph::get_shortest_path(Airport *src, Airport *dest) {
  int i_src = get_airport_index(src);
  int i_dest = get_airport_index(dest);

  if (i_src == -1 || i_dest == -1) {
    throw std::string("get_shortest_path: Vertices do not exist");
  }
  clean_visited();
  std::vector<int> distances(airports.size());
  for (int i = 0; i < distances.size(); i++) {
    distances[i] = (i == i_src) ? 0 : 10000000;
  }

  MinHeap<Flight> heap;
  int airports_visited = 0;
  int cur_ver = i_src;

  while (airports_visited < airports.size()) {
    int i = cur_ver;
    for (int j = 0; j < flights[i].size();j++) {
      Airport *i_adjacent_ver = flights[i][j]->destination;
      if(i_adjacent_ver->isVisited == false) {
        heap.insert(*flights[i][j]);
        int dist_from_source = distances[i] + flights[i][j]->distance;
        if(dist_from_source < distances[get_airport_index(i_adjacent_ver)]) {
          distances[get_airport_index(i_adjacent_ver)] = dist_from_source;
        }
      }
    }
    Flight f = heap.delete_min();
    cur_ver = get_airport_index(f.destination);
    airports[i]->isVisited = true;
    airports_visited++;
  }
  clean_visited();
  return distances[i_dest];
}