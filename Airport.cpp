#include "Airport.h"
#include "Flight.h"
#include <iostream>
// Constructor
Airport::Airport(std::string _airportCode, std::string _airportName) {
  airportCode = _airportCode;
  airportName = _airportName;
}

// Getter functions
std::string Airport::getAirportCode() const { return airportCode; }

std::string Airport::getAirportName() const { return airportName; }