#include "UndirectedAirportGraph.h"

for (Airport *airport : airports) {
    delete airport;
  }
  for (std::vector<Flight *>flightlist : flights) {
    for(Flight* flight: flightlist) {
        delete flight;
    }
  }

int UndirectedAirportGraph::get_airport_index(Airport* airport) {
    return -1;
}
void UndirectedAirportGraph::add_flight_both_directions(Flight* flight) {
    Flight* reverseFlight = new Flight( flight->destination, flight->source, flight->cost );
    this->flights[get_airport_index(flight->source)].push_back(flight);
    this->flights[get_airport_index(flight->destination)].push_back(reverseFlight);
}
bool UndirectedAirportGraph::reversed_flight_exists(Flight* flight) {
    vector<Flight *> adjacencyList = this->flights[get_airport_index(flight->destination)];
    for( const Flight* f : adjacencyList ){
        if( f->destination == flight->source ){
            return true;
        }
    }
    return false;
}
