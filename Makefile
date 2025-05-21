CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC_DIR = src
BUILD_DIR = build


all: $(BUILD_DIR) $(BUILD_DIR)/traffic_light_sim

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Compile traffic_light_sim.c
$(BUILD_DIR)/traffic_light_sim.o: $(SRC_DIR)/traffic_light_sim.c $(SRC_DIR)/traffic_light_sim.h $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Compile main.c
$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build main binary
$(BUILD_DIR)/traffic_light_sim: $(BUILD_DIR)/traffic_light_sim.o $(BUILD_DIR)/main.o
	$(CC) $(CFLAGS) -o $@ $^

run: $(BUILD_DIR)/traffic_light_sim
	./$(BUILD_DIR)/traffic_light_sim

# Compile test_traffic_light_sim.c
$(BUILD_DIR)/test_traffic_light_sim.o: $(SRC_DIR)/test_traffic_light_sim.c $(SRC_DIR)/traffic_light_sim.h $(BUILD_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Build and run test binary
test: $(BUILD_DIR)/test_runner

$(BUILD_DIR)/test_runner: $(BUILD_DIR)/traffic_light_sim.o $(BUILD_DIR)/test_traffic_light_sim.o
	$(CC) $(CFLAGS) -o $@ $^
	./$@

clean:
	rm -rf $(BUILD_DIR)
