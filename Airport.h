#pragma once
#include "Flight.h"
#include <string>
#include <vector>



class Airport {
public:
  Airport(std::string _airportCode, std::string _airportName);
  std::string getAirportCode() const;
  std::string getAirportName() const;

private:
  std::string airportCode;
  std::string airportName;
};
