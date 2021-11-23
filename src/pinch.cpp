
//#define CATCH_CONFIG_MAIN
//#include "catch.hpp"
#include <bits/stdc++.h>
using namespace std;


struct TrajectoryBand {    // Abstract class (interface) for trajectories of
  virtual ~Trajectory() = default;
  virtual double GetMinPosition(double time) const;
  virtual double GetMaxPosition(double time) const;    // Could be probabilistic.
};

class FixedSpeedTrajectoryBand : public TrajectoryBand {
  double _speed;
  double _initialPosition;
  double _bandWidth;    // Move to base?
public:
  FixedSpeedTrajectory(double speed, double initialPosition, double bandWidth)
      : TrajectoryBand()
        , _speed(speed)
        , _initialPosition(initialPosition)
        , _bandWidth(bandWidth)    // validate, trailing
  {
  }
  GetPosition(double time) const
  {
    return _initialPosition + _speed * time;
  }
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

/*
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

