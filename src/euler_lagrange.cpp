
#include <catch2/catch_test_macros.hpp>

#include <iomanip>
#include <iostream>
#include <ostream>
//class PinchDifferentiator;

/**
 * @brief Differentiable, piecewise quadratic function of distance from a 1D
 * agent going from one "inside" the agent to
 */
class FixedBandwidthQuadraticPlateau {
  double innerRadius_m_;
  double outerRadius_m_;
};

/**
 * @brief 1D projection of a non-ego vehicle model whose position can be
 * queried over time. In this case the agent has a fixed speed. (It could be
 * generalized to support
 */
class FixedSpeedAgent {
  double speed_mps_;
  double initialPosition_m_;
public:
  FixedSpeedAgent(double speed_mps, double initialPosition_m)
      : speed_mps_(speed_mps), initialPosition_m_(initialPosition_m) {}
  double GetPosition(double time_s) const {
    return initialPosition_m_ + speed_mps_ * time_s;
  }
};

TEST_CASE("GetPosition", "[FixedSpeedAgent]") {
  CHECK(FixedSpeedAgent(-25.0, 50.0).GetPosition(2.0) == 0.0);
}

class

#include <boost/numeric/odeint.hpp>
#include <array>

typedef std::array<double, 3> state_type;

TEST_CASE("operator[]", "[state_type]") {
    state_type state;
    size_t n = state.size();
    for (size_t i = 0; i < n; ++i) {
      CHECK_NOTHROW(state[i]);
    }
}

std::ostream &operator<<(std::ostream &os, const state_type &state) {
  for (const auto & dim : state) {
    os << std::setw(16) << dim;
  }
  return os;
}

const double gam = 0.15;

struct harm_osc {
  harm_osc( double gam ) : m_gam(gam) { }
  void operator() ( const state_type &x , state_type &dxdt , const double /* t */ ) {
    dxdt[0] = x[1];
    dxdt[1] = -x[0] - m_gam*x[1];
  }
private:
  double m_gam;
};

struct push_back_state_and_time
{
  std::vector< state_type >& m_states;
  std::vector< double >& m_times;
  push_back_state_and_time( std::vector< state_type > &states , std::vector< double > &times )
      : m_states( states ) , m_times( times ) {}
  void operator()( const state_type &x , double t ) {
    m_states.push_back( x );
    m_times.push_back( t );
  }
};

struct write_state {
  void operator()( const state_type &x ) const {
    std::cout << x << "\n";
  }
};


int main2(int /* argc */ , char** /* argv */ )
{
  using namespace std;
  using namespace boost::numeric::odeint;

  state_type x;
  x[0] = 1.0; // start at x=1.0, p=0.0
  x[1] = 0.0;

  vector<state_type> x_vec;
  vector<double> times;
  
  harm_osc ho(0.15);

  auto steps = integrate(ho, x, 0.0, 10.0, 0.1,
                         push_back_state_and_time(x_vec, times));
  for (size_t i = 0; i < times.size(); ++i) {
    cout << setw(8) << times[i] << " " << x_vec[i] << endl;
  }
}

