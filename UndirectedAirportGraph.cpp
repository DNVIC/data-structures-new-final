#include "UndirectedAirportGraph.h"
#include <iostream>
template <typename T>
std::vector<T> merge_sort(std::vector<T> input) { // needs to be in header since template functions need to be defined in header for some reason
    if(input.size() == 1) {
        return input;
    }
    int index = input.size() / 2;
    typename std::vector<T>::const_iterator mid = input.begin() + index; // if you're reading this, im aware these three lines are basically unreadable
    typename std::vector<T> l((typename std::vector<T>::const_iterator)input.begin(), mid); //they were readable at one point but the compiler yelled at me
    typename std::vector<T> r(mid, (typename std::vector<T>::const_iterator)input.end()); // so i needed to do a bunch of casting and typename shenanigans to shut it up
    l = merge_sort(l);
    r = merge_sort(r);
    typename std::vector<T> output;
    int li = 0;
    int ri = 0;
    while(ri < r.size()) {
        T a = r[ri];
        if(li == l.size()) {
            output.push_back(a);
            ri++;
            continue;
        }
        if(l[li] > a) {
            output.push_back(l[li]);
            li++;
        } else {
            output.push_back(a);
            ri++;
        }
    }
    if(li != l.size())
        output.insert(output.end(),l.begin() + li, l.end());
    return output;
}
Airport *UndirectedAirportGraph::getAirportByCode(std::string airportCode) {
  for (Airport *airport : airports) {
    if (airport->getAirportCode() == airportCode) {
      return airport;
    }
  }
  return nullptr;
}
UndirectedAirportGraph::~UndirectedAirportGraph() {
    for (int i = 0; i < flights.size(); i++) {
        std::vector<Flight *> flightlist = flights[i];
        for(Flight* flight: flightlist) {
            if(flight->source == airports[i]) {
                delete flight;
            }
        }
    }
    for (Airport *airport : airports) {
        delete airport;
    }
}

UndirectedAirportGraph::UndirectedAirportGraph(AirportGraph graph) {
    for(Airport* a : graph.airports) {
        Airport *b = new Airport(a);
        airports.push_back(b);
    }
    for(int i = 0; i < airports.size(); i++) {
        std::vector<Flight *> tmp;
        flights.push_back(tmp);
    }
    for(int i = 0; i < graph.flights.size(); i++) {
        for(int j = 0; j < graph.flights[i].size(); j++) {
            int cost = reversed_flight_cost(graph.flights[i][j], graph.flights[i]);
            if(cost != -1) {
                add_flight_both_directions(graph.flights[i][j], cost);
            }
        }
    }
}


int UndirectedAirportGraph::get_airport_index(Airport* airport) {
    for (int i = 0; i < airports.size(); i++) {
        if (airport == airports[i]) {
            return i;
        }
    }
    return -1;
}
void UndirectedAirportGraph::add_flight_both_directions(Flight* flight, int cost) {
    Flight* newFlight = new Flight( getAirportByCode(flight->destination->getAirportCode()), getAirportByCode(flight->source->getAirportCode()), 0, cost );
    flights[get_airport_index(newFlight->source)].push_back(newFlight);
    flights[get_airport_index(newFlight->destination)].push_back(newFlight); // source and destination aren't the same across flights for an index but that wont matter in the long run
}
int UndirectedAirportGraph::reversed_flight_cost(Flight* flight, std::vector<Flight *> flights) {
    int index = get_airport_index(flight->destination);
    for(int i = 0; i < flights.size(); i++){
        Flight *f = flights[i];
        if( f->destination == flight->source ){
            return flight->cost < f->cost ? flight->cost : -1;
        }
    }
    return flight->cost;
}

struct indexed_int {
    int index;
    int value;
    Flight *edge;
    indexed_int(int v = 0, int i = 0) {
        index = i;
        value = v;
        edge = nullptr;
    }
    bool operator>(const indexed_int &x) const { return value > x.value; }
    bool operator<(const indexed_int &x) const { return value < x.value; }
};

int get_indexed_int(const std::vector<indexed_int>& v,int index) {
    for(int i = 0; i < v.size(); i++) {
        indexed_int ii = v[i];
        if(ii.index == index) {
            return i;
        }
    }
    return -1;
}

bool flightExistsAlready(const std::vector<Flight *>& flights, Flight* flight) {
    for(const Flight* f : flights) {
        if(f == flight) {
            return true;
        }
    }
    return false;
}


/* 
*  The below algorithm is unfinished and will crash if you try to run it. The
*  crash is the most confusing and annoying crash I have ever seen in C++. I have
*  no clue why it is crashing, and I've tried multiple things to fix it, including
*  going into the debugger, mutltiple times, putting a million print statements
*  everywhere. It is occuring despite the function in question working perfectly
*  fine in the previous two instances I used it, and in fact it works twice in this
*  loop, but the third time, it decides to die and no longer be able to be used.
*  I can't figure out why, and at this point, it is 6 hours before the due time (at 10am),
*  I'm incredibly tired, I've had little to no help with actually programming this 
*  project, despite it being a group project, and so I give up on this function.
*  I'd rewrite this function, but I need to sleep tonight at least a little bit.
*/
void UndirectedAirportGraph::print_prims_algorithm() { 
    std::vector<Airport *> MSTVertices;
    std::vector<Flight *> MSTEdges;
    std::vector<indexed_int> keyValues(airports.size());
    for(int i = 0; i < keyValues.size(); i++) {
        keyValues[i] = indexed_int(1000000, i);
    }
    keyValues[0].value = 0;
    int totalValue = 0;
    while(MSTVertices.size() < airports.size()) {
        
        keyValues = merge_sort(keyValues);
        if(keyValues.back().value == 1000000) {
            std::cout << "Not a connected graph\n";
            break;
        }
        if(keyValues.back().edge != nullptr) {
            MSTEdges.push_back(keyValues.back().edge);
        }
        
        
        int index = keyValues.back().index;
        int value = keyValues.back().value;
        totalValue += value;
        keyValues.pop_back();
        Airport* u = airports[index];
        MSTVertices.push_back(u);
        for(int i = 0; i < flights[index].size(); i++) {
            if(flightExistsAlready(MSTEdges, flights[index][i])) {
                continue;
            }
            Airport *v = u == flights[index][i]->destination ? flights[index][i]->source : flights[index][i]->destination;
            int cost = flights[index][i]->cost;
            int index2 = get_indexed_int(keyValues,get_airport_index(v));
            keyValues[index2].value = value + cost;
        }
    }
    MSTEdges.push_back(keyValues.back().edge);
    std::cout << totalValue;
}

void UndirectedAirportGraph::print_kruskals_algorithm() {
    std::vector<Flight> MSTEdges;
    std::vector<Airport*> MSTVertices;
    std::vector<Flight> dereferencedFlights;
    for(int i = 0; i < flights.size(); i++) {
        for(int j = 0; j < flights[i].size(); j++) {
            Flight f = *flights[i][j];
            if(f.source == airports[i]) { // remove duplicate edges
                dereferencedFlights.push_back(f);
            }
        }
    }
    dereferencedFlights = merge_sort(dereferencedFlights);
    while(dereferencedFlights.size() > 0) {
        Flight b = dereferencedFlights.back();
        dereferencedFlights.pop_back();
        bool src = 0;
        bool dst = 0;
        for(Airport* a : MSTVertices) {
            if(b.source == a) {
                src = 1;
            }
            if(b.destination == a) {
                dst = 1;
            }
        }
        if(!(src && dst)) {
            MSTEdges.push_back(b);
            MSTVertices.push_back(b.source);
            MSTVertices.push_back(b.destination);
        }
    }
    int totalCost = 0;
    std::cout << "Edge" << "\t\t\tWeight\n";
    for(Flight f : MSTEdges) {
        totalCost += f.cost;
        std::cout << f.source->getAirportCode() << " - ";
        std::cout << f.destination->getAirportCode() << "\t\t";
        std::cout << f.cost << '\n';
    }
    std::cout << "Total cost of MST: " << totalCost << '\n';
}
