#ifndef TRAFFIC_LIGHT_SIM_H
#define TRAFFIC_LIGHT_SIM_H

typedef enum {
    GREEN,
    YELLOW,
    RED,
} LightColor;

typedef enum {
    STATE_NS_GREEN,
    STATE_NS_YELLOW,
    STATE_ALL_RED_NS,
    STATE_EW_GREEN,
    STATE_EW_YELLOW,
    STATE_ALL_RED_EW,
} State;

typedef struct {
    LightColor ns_color;
    LightColor ew_color;
} TrafficLightState;

const char* color_to_str(LightColor color);
void print_current_state(TrafficLightState state);
State iterate_state(State current_state, TrafficLightState* light_state);

#endif
