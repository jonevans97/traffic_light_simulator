// 4-way traffic light simulator
// Assume we have standard green, yellow and red traffic lights with no turn signals (for simplicity sake). Also
// assume that the intersection must be in one of the following five states:
//   1. North -> south flow green, East -> West stop for red
//   2. North -> south flow yellow, East -> West stop for red
//   3. All directions stop for red (assuming the desired behavior is to have all directions stop before the next direction turns green)
//   4. East -> West flow green, North -> South stop red
//   5. East -> West flow yellow, North -> South stop red
//   6. All directions stop for red, preceding NS green
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include "traffic_light_sim.h"

#define GREEN_DURATION 4
#define YELLOW_DURATION 1
#define RED_DURATION 1

// Translate from LightColor to the human-readable string
const char* color_to_str(LightColor color) {
    switch (color) {
        case RED: return "Red";
        case YELLOW: return "Yellow";
        case GREEN: return "Green";
        default: return "Unknown";
    }
}

// Print the current state of the lights, with the
// north light on top, east on the left, west on the right,
// and south on the bottom
void print_current_state(TrafficLightState state) {
    const char* color_ns = color_to_str(state.ns_color);
    const char* color_ew = color_to_str(state.ew_color);

    // Calculate necessary padding for labels by assuming
    // longest label string length is 6 (yellow)
    int west_padding = 6 - (int)strlen(color_ew);
    if (west_padding < 0) west_padding = 0;

    int ns_padding = 6 - (int)strlen(color_ns);
    if (ns_padding < 0) ns_padding = 0;


    printf("\n");
    printf("             %*s[%s]\n", ns_padding / 2, "", color_ns);    // North
    printf("                ↑\n");
    printf("                |\n");

    printf("   %*s[%s] ←───+───→ [%s]\n", west_padding, "", color_ew, color_ew); // West/East

    printf("                |\n");
    printf("                ↓\n");
    printf("             %*s[%s]\n", ns_padding / 2, "", color_ns);    // South
    printf("\n");
}

// Take the current state and iterate to the next, setting and printing the new state
State iterate_state(State current_state, TrafficLightState* light_state) {
    switch (current_state) {
        case STATE_NS_GREEN:
            light_state->ns_color = GREEN;
            light_state->ew_color = RED;
            print_current_state(*light_state);
            sleep(GREEN_DURATION);
            return STATE_NS_YELLOW;

        case STATE_NS_YELLOW:
            light_state->ns_color = YELLOW;
            light_state->ew_color = RED;
            print_current_state(*light_state);
            sleep(YELLOW_DURATION);
            return STATE_ALL_RED_NS;

        case STATE_ALL_RED_NS:
            light_state->ns_color = RED;
            light_state->ew_color = RED;
            print_current_state(*light_state);
            sleep(RED_DURATION);
            return STATE_EW_GREEN;

        case STATE_EW_GREEN:
            light_state->ns_color = RED;
            light_state->ew_color = GREEN;
            print_current_state(*light_state);
            sleep(GREEN_DURATION);
            return STATE_EW_YELLOW;

        case STATE_EW_YELLOW:
            light_state->ns_color = RED;
            light_state->ew_color = YELLOW;
            print_current_state(*light_state);
            sleep(YELLOW_DURATION);
            return STATE_ALL_RED_EW;

        case STATE_ALL_RED_EW:
            light_state->ns_color = RED;
            light_state->ew_color = RED;
            print_current_state(*light_state);
            sleep(RED_DURATION);
            return STATE_NS_GREEN;
    }

    return STATE_NS_GREEN;
}
