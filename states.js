
var IDLE = {
  id: 0,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_IDLE = 0;
var OFF = {
  id: 1,
  master: {
    values: {
      
    },
    events: {
      
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_OFF = 1;
var ROBOTICARM = {
  id: 2,
  master: {
    values: {
      
    },
    events: {
      moveToHigh: function moveToHigh() { manager.sendEvent(0, 2); },
      moveToLow: function moveToLow() { manager.sendEvent(1, 2); },
      magnetOn: function magnetOn() { manager.sendEvent(2, 2); },
      magnetOff: function magnetOff() { manager.sendEvent(3, 2); },
      armUp: function armUp() { manager.sendEvent(4, 2); },
      armDown: function armDown() { manager.sendEvent(5, 2); },
      goHome: function goHome() { manager.sendEvent(6, 2); }
    }
  },
  tablet: {
    values: {
      
    },
    events: {
      
    }
  }
};
var STATE_ROBOTICARM = 2;

var STATES = {
  IDLE: IDLE,
  OFF: OFF,
  ROBOTICARM: ROBOTICARM
};
var manager = new Manager([IDLE, OFF, ROBOTICARM]);
