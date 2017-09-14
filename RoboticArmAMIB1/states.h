#pragma once

#include <Manager.h>

namespace IDLE {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}

namespace OFF {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {

}
}

namespace ROBOTICARM {

__attribute__((weak)) void setup();
__attribute__((weak)) void enter();
__attribute__((weak)) void loop();
void event(uint8_t);
__attribute__((weak)) void exit();



namespace events {
void moveToHigh();
void moveToLow();
void magnetOn();
void magnetOff();
void armUp();
void armDown();
void goHome();
}
}



enum State {
  STATE_IDLE,
  STATE_OFF,
  STATE_ROBOTICARM
};

extern MasterManager<State, 3, 0> manager;
