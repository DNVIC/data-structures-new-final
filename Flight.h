#pragma once
class Airport;
#include <iostream>

class Flight {
public:
  Flight(Airport *_src, Airport *_dest = nullptr, int _dist = 0,
         int _cost = 0) {
    source = _src;
    destination = _dest;
    distance = _dist;
    cost = _cost;
  }
  bool operator>(const Flight &x) const { return distance > x.distance; }
  bool operator<(const Flight &x) const { return distance < x.distance; }
  Airport *source;
  Airport *destination;
  int distance;
  int cost;
};
