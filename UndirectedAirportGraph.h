#ifndef UNDIRECTED_AIRPORT_GRAPH_H
#define UNDIRECTED_AIRPORT_GRAPH_H

#include "Airport.h"
#include "Flight.h"
#include "AirportGraph.h"
class UndirectedAirportGraph {
    public:
        UndirectedAirportGraph(AirportGraph graph);
        ~UndirectedAirportGraph();
        std::vector<Airport*> airports;
        std::vector< std::vector<Flight*> > flights;
        int get_airport_index(Airport* airport);
        void add_flight_both_directions(Flight* flight);
        bool reversed_flight_exists(Flight* flight);
    private:
        std::vector<Airport*> airports;
        std::vector< std::vector<Flight*> > flights;
};
#endif
