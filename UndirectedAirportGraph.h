#ifndef UNDIRECTED_AIRPORT_GRAPH_H
#define UNDIRECTED_AIRPORT_GRAPH_H

#include "Airport.h"
#include "Flight.h"
class UndirectedAirportGraph {
public:
    std::vector<Airport*> airports;
    std::vector< std::vector<Flight*> > flights;
    int get_airport_index(Airport* airport);
    Flight* get_shortest_path(Airport* source, Airport* destination);
    void add_flight_both_directions(Flight* flight);
    bool reversed_flight_exists(Flight* flight);
};
#endif
