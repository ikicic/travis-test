# https://spin.atomicobject.com/2016/08/26/makefile-c-projects/

CXX = g++
CPPFLAGS = -O3 -Wall -Wextra -std=c++11

BUILD_DIR = bin

SRCS := $(shell find src tests -name "*.cpp")
OBJS := $(SRCS:%=$(BUILD_DIR)/%.o)
DEPS := $(OBJS:.o=.d)

INC_DIRS := include/ # $(shell find $(SRC_DIRS) -type d)
INC_FLAGS := $(addprefix -I,$(INC_DIRS))


CPPFLAGS += $(INC_FLAGS) -MMD -MP

.phony: clean test

$(BUILD_DIR)/run_tests: $(OBJS)
	$(CXX) $(CPPFLAGS) $(OBJS) -o $@

$(BUILD_DIR)/%.cpp.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CPPFLAGS) -c $< -o $@

clean:
	rm -r $(BUILD_DIR)

test: $(BUILD_DIR)/run_tests
	$(BUILD_DIR)/run_tests


-include $(DEPS)
