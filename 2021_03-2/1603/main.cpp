#include <iostream>
#include <vector>

class ParkingSystem {
public:
  int big, medium, small;
  ParkingSystem(int big, int medium, int small):
  big(big), medium(medium), small(small)
   {}

  bool addCar(int carType) {
    switch (carType) {
    case 1:
      return (big-- > 0);
    case 2:
      return (medium-- > 0);
    case 3:
      return (small -- > 0);
    }
    return false;
  }
};