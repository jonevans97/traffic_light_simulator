#include "traffic_light_sim.h"

int main() {
    TrafficLightState light_state = { RED, RED };
    State state = STATE_ALL_RED_EW;

    while (1) {
        state = iterate_state(state, &light_state);
    }
}
