
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <bits/stdc++.h>
using namespace std;

class FixedSpeedTrajectoryBand {//: public TrajectoryBand {
  double _speed;  // m/s
  double _initialPosition;  // m
  double _bandWidth;    // Move to base?
public:
  FixedSpeedTrajectoryBand(double speed, double initialPosition, double bandWidth)
      : FixedSpeedTrajectoryBand()
        , _speed(speed)
        , _initialPosition(initialPosition)
        , _bandWidth(bandWidth)    // validate, trailing
  {
  }
private:
  GetPosition(double time) const  // s
  {
    return _initialPosition + _speed * time;  // units?
  }
};

int main() {
  FixedSpeedTrajectoryBand oncoming(-26.8, 100.0, 4.0), parked(0.0, 50.0, 3.0);
  
}

/*
struct TrajectoryBand {    // Abstract class (interface) for trajectories of
  virtual ~TrajectoryBand() = default;
  virtual double GetMinPosition(double time) const = 0;
  virtual double GetMaxPosition(double time) const = 0;    // Could be
  // probabilistic.
};

class PinchExplorerInterface {
public:
  virtual void AddTrajectoryBand(const TrajectoryBand &trajectoryBand) = 0;
};

class SparsePinchExplorer : public PinchExplorerInterface {
public:
  void AddTrajectoryBand(const TrajectoryBand &newTrajectoryBand) {
    for (const auto &oldTrajectoryBand : _trajectoryBands) {
      _pinches.emplace_back(newTrajectoryBand,
                            oldTrajectoryBand);
    }
  }
  double QueryPinch(double position, double time) const {
  
  }
private:

};

class DensePinchExplorer : public PinchExplorerInterface {
public:
  void AddTrajectoryBand(const TrajectoryBand &trajectoryBand) {
  }
  double QueryPinch(double position, double time) const {
  
  }
private:

};

class ClosedLoopSpeedController {
public:
  double GetSpeed(double position, double time) const {
  
  }
};

class SpaceTime {
    vector<double> _space;
    vector<double> _time;
public:
    SpaceTime(double t0, double dt, size_t nt)
        : _space()
};

class PinchMap {
    vector<vector<double>> _pinch;
public:
    PinchMap(const SpaceTime &spaceTime, vector<FixedSpeedTrajectory> const &
};
*/

