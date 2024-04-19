#pragma once
#include "Flight.h"
#include <string>
#include <vector>

class Airport {
public:
  Airport(std::string _airportCode, std::string _airportName);
  const std::string &getAirportCode() const;
  const std::string &getAirportName() const;
  bool isVisited = false;

private:
  std::string airportCode;
  std::string airportName;
};
