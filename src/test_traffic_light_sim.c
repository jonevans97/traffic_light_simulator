#include <assert.h>
#include <stdio.h>
#include "traffic_light_sim.h"  // Header with declarations of your code

// Iterate through each state once and make sure it transitions correctly to the next
void test_state_transitions() {
    TrafficLightState state = { RED, RED };

    State s = STATE_NS_GREEN;
    s = iterate_state(s, &state);
    assert(state.ns_color == GREEN && state.ew_color == RED);

    s = iterate_state(s, &state);
    assert(state.ns_color == YELLOW && state.ew_color == RED);

    s = iterate_state(s, &state);
    assert(state.ns_color == RED && state.ew_color == RED);

    s = iterate_state(s, &state);
    assert(state.ns_color == RED && state.ew_color == GREEN);

    s = iterate_state(s, &state);
    assert(state.ns_color == RED && state.ew_color == YELLOW);

    s = iterate_state(s, &state);
    assert(state.ns_color == RED && state.ew_color == RED);

    printf("All state transition tests passed.\n");
}

// Make sure that at least one direction is always red
//   (never have both NS and EW allowed to drive at the same time)
void test_at_least_one_red() {
    TrafficLightState state = { RED, RED };

    State s = STATE_NS_GREEN;
    for (int i=0; i < 10; i++) {
        s = iterate_state(s, &state);
        assert(state.ns_color == RED || state.ew_color == RED);
    }

    printf("Ten transitions all had at least one red light at all times.\n");
}

int main() {
    test_state_transitions();
    test_at_least_one_red();

    printf("Passed all tests\n");
    return 0;
}
