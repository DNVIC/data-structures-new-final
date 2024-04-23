#include "UndirectedAirportGraph.h"

int UndirectedAirportGraph::get_airport_index(Airport* airport) {
    return -1;
}
Flight* UndirectedAirportGraph::get_shortest_path(Airport* source, Airport* destination) {
    return nullptr;
}
void UndirectedAirportGraph::add_flight_both_directions(Flight* flight) {
    Flight* reverseFlight = new Flight( flight->destination, flight->source, flight->cost );
    this->flights[get_airport_index(flight->source)].push_back(flight);
    this->flights[get_airport_index(flight->destination)].push_back(reverseFlight);
}
bool UndirectedAirportGraph::reversed_flight_exists(Flight* flight) {
    auto& adjacencyList = this->flights[get_airport_index(flight->destination)];
    for( const auto& f : adjacencyList ){
        if( f->destination == flight->source ){
            return true;
        }
    }
    return false;
}
