# Directories
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

# Compiler
CXX = g++
OPT = -O1
CXXFLAGS = -std=c++17 -g $(OPT) -MMD -MP

# Source files
SOURCES = main.cpp

# Target
TARGET = $(BIN_DIR)/graph

# Derived files
OBJECTS = $(addprefix $(OBJ_DIR)/,$(SOURCES:.cpp=.o))
DEPS = $(OBJECTS:.o=.d)

.PHONY: all clean mrun val

all: $(TARGET)

$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	$(CXX) $^ -o $@

$(OBJ_DIR)/%.o: %.cpp
	@mkdir -p $(dir $@)
	$(CXX) $(CXXFLAGS) -c $< -o $@

mrun: $(TARGET)
	@clear
	./$(TARGET)

val: $(TARGET)
	@clear
	valgrind ./$(TARGET)

clean:
	rm -rf $(BUILD_DIR)

-include $(DEPS)