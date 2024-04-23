#ifndef UNDIRECTED_AIRPORT_GRAPH_H
#define UNDIRECTED_AIRPORT_GRAPH_H

#include "Airport.h"
#include "Flight.h"
#include "AirportGraph.h"
class UndirectedAirportGraph {
    public:
        UndirectedAirportGraph(AirportGraph graph);
        ~UndirectedAirportGraph();
        int get_airport_index(Airport* airport);
        void add_flight_both_directions(Flight* flight, int cost);
        int reversed_flight_cost(Flight* flight, std::vector<Flight *> flights);
        void print_prims_algorithm();
        void print_kruskals_algorithm();
        Airport *getAirportByCode(std::string airportCode);
    private:
        std::vector<Airport*> airports;
        std::vector<std::vector<Flight*>> flights;
};
#endif
