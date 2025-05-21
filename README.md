# 4-Way Traffic Light Simulator

This project simulates a standard 4-way traffic light intersection using a finite state machine in C. It models the flow of traffic at an intersection where only one direction (north-south or east-west) has the green or yellow light at a time, with short all-red intervals between direction changes for safety.

## Features

- Simulates 6 distinct traffic light states:
  1. North-South green, East-West red  
  2. North-South yellow, East-West red  
  3. All red (transition state before East-West green)  
  4. East-West green, North-South red  
  5. East-West yellow, North-South red  
  6. All red (transition state before North-South green)  
- Console-based visual display of the intersection, with:
  - North on top
  - South on bottom
  - East on the left
  - West on the right
- Adjustable light durations for green, yellow, and red

## Build and Run

### Requirements

- GCC or compatible C compiler
- `make`

### Make Targets

| Target       | Description                            |
|--------------|----------------------------------------|
| `make`       | Builds the traffic light simulator      |
| `make run`   | Builds and runs the simulator           |
| `make test`  | Builds and runs unit tests              |
| `make clean` | Removes build artifacts                 |

### Usage

```bash
make run
```

The simulation will run indefinitely, printing each light state to the terminal with delays between transitions.

To run unit tests:

```bash
make test
```

### License

MIT License