#include "states.h"

static const StateInfo state_infos[3] = {
  {IDLE::setup, IDLE::enter, IDLE::exit, IDLE::loop, IDLE::event},
  {OFF::setup, OFF::enter, OFF::exit, OFF::loop, OFF::event},
  {ROBOTICARM::setup, ROBOTICARM::enter, ROBOTICARM::exit, ROBOTICARM::loop, ROBOTICARM::event}
};

static const WireValue wire_values[0] = {
  
};

MasterManager<State, 3, 0> manager(0xb1928129, state_infos, wire_values, 0);

namespace IDLE {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace OFF {


void event(uint8_t ev) {
  switch (ev) {
  
  default:
    break;
  }
}


}
namespace ROBOTICARM {


void event(uint8_t ev) {
  switch (ev) {
  case 0:
    events::moveToHigh();
    break;
  case 1:
    events::moveToLow();
    break;
  case 2:
    events::magnetOn();
    break;
  case 3:
    events::magnetOff();
    break;
  case 4:
    events::armUp();
    break;
  case 5:
    events::armDown();
    break;
  case 6:
    events::goHome();
    break;
  default:
    break;
  }
}


}

