#include "main.h"

/* The TimeBomb AO =======================================================*/
enum BombSignals { /* all signals for the Bomb FSM */
UP_SIG,
DOWN_SIG,
ARM_SIG,
TICK_SIG
};

enum BombStates { /* all states for the Bomb FSM */
SETTING_STATE,
TIMING_STATE
};

typedef struct EventTag {
  uint8_t sig; /* signal of the event */

} Event;