#include "AirportGraph.h"
#include "UndirectedAirportGraph.h"
#include "Flight.h"
#include <iostream>
#include <vector>
#include <string>

AirportGraph::~AirportGraph() {
  for (Airport *airport : airports) {
    delete airport;
  }
  for (std::vector<Flight *>flightlist : flights) {
    for(Flight* flight: flightlist) {
        delete flight;
    }
  }
}

void AirportGraph::addFlight(Airport *source, Airport *destination, int distance, int cost) {
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
  std::vector<Flight *> tmp1;
  std::vector<Flight *> tmp2;
  switch (flag) { // uses flag to add airports to graph if not already existing
      case 0:
        airports.push_back(source);
        flights.push_back(tmp1);
      case 1: 
        airports.push_back(destination);
        flights.push_back(tmp2);
        break;
      case 2:
        airports.push_back(source);
        flights.push_back(tmp1);
        break;
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

template <typename T>
std::vector<T> merge_sort(std::vector<T> input) {
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


void AirportGraph::recursiveHelper(std::vector<Airport*>& output, const std::vector<Airport*>& prev, int i) {
    if(prev[i] == nullptr) {
        return;
    }
    recursiveHelper(output, prev, get_airport_index(prev[i]));
    output.push_back(prev[i]);
}

void AirportGraph::get_shortest_path_to_state(Airport *src, std::string state) {
    std::vector<int> indices;
    for(int i = 0; i < airports.size(); i++) {
        std::string airportName = airports[i]->getAirportName();
        if(airportName.compare(airportName.size() - state.size(),
            state.size(),
            state) == 0) {
                indices.push_back(i);
            }
    }
    std::vector<Airport *> Q(airports.size());
    std::vector<Airport *> prev(airports.size());
    std::vector<int> distances(airports.size());
    std::vector<int> costs(airports.size());
    for (int i = 0; i < airports.size(); i++) {
        distances[i] = 100000000;
        costs[i]=-1;
        Q[i] = airports[i];
        prev[i] = nullptr;
    }
    distances[get_airport_index(src)] = 0;
    costs[get_airport_index(src)] = 0;
    
    int num_airports_visited = 0;
    while(num_airports_visited < Q.size()) {
        int min = 100000001;
        int minIndex;
        for(int i = 0; i < Q.size(); i++) { //bad way find the minimum, but i tried all the good ways and got frustrated
            if(Q[i] == nullptr) {
                continue;
            }
            if(distances[i] < min) {
                min = distances[i];
                minIndex = i;
            }
        }
        Q[minIndex] = nullptr;
        
        
        for(int i = 0; i < flights[minIndex].size(); i++) {
            Flight* flight = flights[minIndex][i];
            int alt = distances[minIndex] + flight->distance;
            if(alt < distances[get_airport_index(flight->destination)]) {
                distances[get_airport_index(flight->destination)] = alt;
                costs[get_airport_index(flight->destination)] = costs[minIndex] + flight->cost;
                prev[get_airport_index(flight->destination)] = flight->source;
            }
        }
        num_airports_visited++;
    }
    
    std::cout << "Shortest route from " << src->getAirportCode() << " to " << state << " state airports are: \n\n";
    std::cout << "Path\t\t\t\tLength\t\tCost\n";
    
    for(int index : indices) {
        std::vector<Airport *> output;
        if(distances[index] == 100000000) {
            std::cout << "None for " << airports[index]->getAirportCode() << '\n';
            continue;
        }
        recursiveHelper(output, prev, index);
        for(int i = 0; i < output.size(); i++) {
            Airport *a = output[i];
            if(i == 0) {
                std::cout << a->getAirportCode();
                continue;
            }
            std::cout << "->" << a->getAirportCode();
        }
        if(output.size() == 0) {
            std::cout << airports[index]->getAirportCode();
        } else {
            std::cout << "->" << airports[index]->getAirportCode();
        }
        std::cout << "\t\t\t" << distances[index] << "\t\t" << costs[index] << "\n";
    }
}


void AirportGraph::get_shortest_path(Airport *src, Airport *dest) {
    std::vector<Airport *> Q(airports.size());
    std::vector<Airport *> prev(airports.size());
    std::vector<int> distances(airports.size());
    std::vector<int> costs(airports.size());
    for (int i = 0; i < airports.size(); i++) {
        distances[i] = 100000000;
        costs[i]=-1;
        Q[i] = airports[i];
        prev[i] = nullptr;
    }
    distances[get_airport_index(src)] = 0;
    costs[get_airport_index(src)] = 0;
    
    int num_airports_visited = 0;
    while(num_airports_visited < Q.size()) {
        int min = 100000001;
        int minIndex;
        for(int i = 0; i < Q.size(); i++) { //bad way find the minimum, but i tried all the good ways and got frustrated
            if(Q[i] == nullptr) {
                continue;
            }
            if(distances[i] < min) {
                min = distances[i];
                minIndex = i;
            }
        }
        if(minIndex == get_airport_index(dest)) {
            break;//return distances[minIndex];
        }
        Q[minIndex] = nullptr;
        
        
        for(int i = 0; i < flights[minIndex].size(); i++) {
            Flight* flight = flights[minIndex][i];
            int alt = distances[minIndex] + flight->distance;
            if(alt < distances[get_airport_index(flight->destination)]) {
                distances[get_airport_index(flight->destination)] = alt;
                costs[get_airport_index(flight->destination)] = costs[minIndex] + flight->cost;
                prev[get_airport_index(flight->destination)] = flight->source;
            }
        }
        num_airports_visited++;
    }
    std::vector<Airport *> output;
    std::cout << "Shortest Route from " << src->getAirportCode() << " to " << dest->getAirportCode() << ": ";
    if(distances[get_airport_index(dest)] == 100000000) {
        std::cout << "None\n";
        return;
    }
    recursiveHelper(output, prev, get_airport_index(dest));
    for(int i = 0; i < output.size(); i++) {
        Airport *a = output[i];
        if(i == 0) {
            std::cout << a->getAirportCode();
            continue;
        }
        std::cout << "->" << a->getAirportCode();
    }
    if(output.size() == 0) {
        std::cout << dest->getAirportCode();
    } else {
        std::cout << "->" << dest->getAirportCode();
    }
    std::cout << ". The length is " << distances[get_airport_index(dest)] << ". The cost is " << costs[get_airport_index(dest)] << ".\n";
}

int AirportGraph::recursiveHelper2(const std::vector<Airport*>& prev, int i) {
    if(prev[i] == nullptr) {
        return 1;
    }
    return recursiveHelper2(prev, get_airport_index(prev[i])) + 1;
}



al AirportGraph::depthFirstSearch(Airport *cur, Airport* target, int i) {

    if(i == 0) {
        if(cur == target) {
            std::vector<Airport*> path;
            path.push_back(cur);
            return al(path, 0, 0);
        } else {
            return al(-1, 0);
        }
    }
    std::vector<al> lengths;
    for(int j = 0; j < flights[get_airport_index(cur)].size();j++) {
        al l = depthFirstSearch(flights[get_airport_index(cur)][j]->destination, target, i-1);
        if(l.length != -1) {
            lengths.push_back(al(l.path, l.length + flights[get_airport_index(cur)][j]->distance, l.cost + flights[get_airport_index(cur)][j]->cost));
        }
    }
    if(lengths.size() == 0) {
        return al(-1, 0);
    }
    lengths = merge_sort(lengths);
    al back = lengths.back();
    std::vector<Airport *> path = back.path;
    path.push_back(cur);
    return al(path, back.length, back.cost);
}

void AirportGraph::get_shortest_path_with_stops(Airport *src, Airport *dest, int stops) {
    stops +=1; //off by one error i dont feel like finding the source of
    std::vector<Airport *> Q(airports.size());
    std::vector<Airport *> prev(airports.size());
    for (int i = 0; i < airports.size(); i++) {
        Q[i] = airports[i];
        prev[i] = nullptr;
    }
    
    al result = depthFirstSearch(src, dest, stops);
    std::cout << (prev[get_airport_index(prev[get_airport_index(dest)])] == nullptr);
    std::cout << "Shortest Route from " << src->getAirportCode() << " to " << dest->getAirportCode() << " with " << stops - 1 << " stops: ";
    if(result.length == -1) {
        std::cout << "None\n";
        return;
    }
    for(int i = result.path.size()-1; i > 0; i--) {
        Airport *a = result.path[i];
        if(i == result.path.size()-1) {
            std::cout << a->getAirportCode();
            continue;
        }
        std::cout << "->" << a->getAirportCode();
    }
    if(result.path.size() == 0) {
        std::cout << dest->getAirportCode();
    } else {
        std::cout << "->" << dest->getAirportCode();
    }
    std::cout << ". The length is " << result.length << ". The cost is " << result.cost << ".\n";
}

class ac { // helper class, only used in this file
    public:
        Airport* airport;
        int connections;
        ac(Airport *a, int c) {
            airport = a;
            connections = c;
        }
        ac() {
            airport = nullptr;
            connections = 0;
        }
        bool operator>(const ac &x) const { return connections > x.connections; }
        bool operator<(const ac &x) const { return connections < x.connections; }
};


void AirportGraph::get_total_connections() {
    std::vector<ac> arr(airports.size());
    for(int i = 0; i < arr.size(); i++) {
        arr[i].airport = airports[i];
        arr[i].connections = 0;
    }
    for(int i = 0; i < arr.size(); i++) {
        Airport *airport = arr[i].airport;
        for(int j = 0; j < flights[i].size(); j++) {
            arr[i].connections++;
            arr[get_airport_index(flights[i][j]->destination)].connections++;
        }
    }
    arr = merge_sort(arr);
    
    std::cout << "Airport\t\tConnections\n";
    for(int i = 0; i < arr.size(); i++) {
        std::cout << arr[i].airport->getAirportCode() << "\t\t" << arr[i].connections << '\n';
    }
   
   
   
    
}