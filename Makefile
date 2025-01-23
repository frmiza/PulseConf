APP_TARGET = build/app_executable
TEST_TARGET = build/teste

SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
TEST_DIR = test

INCLUDE_PATHS = -I$(INCLUDE_DIR) -I$(INCLUDE_DIR)/app

APP_SRCS = $(wildcard $(SRC_DIR)/app/*.cpp)
APP_OBJS = $(APP_SRCS:$(SRC_DIR)/%.cpp=$(BUILD_DIR)/%.o)
TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(TEST_SRCS:$(TEST_DIR)/%.cpp=$(BUILD_DIR)/%.o)

CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 $(INCLUDE_PATHS)
LDFLAGS = -lpulse

all: $(APP_TARGET) $(TEST_TARGET)

$(APP_TARGET): $(APP_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(APP_OBJS) -o $(APP_TARGET) $(LDFLAGS)
	@echo "Executável criado: $(APP_TARGET)"

$(TEST_TARGET): $(TEST_OBJS) $(APP_OBJS)
	@mkdir -p $(@D)
	$(CXX) $(TEST_OBJS) $(APP_OBJS) -o $(TEST_TARGET) $(LDFLAGS)
	@echo "Executável de teste criado: $(TEST_TARGET)"

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compilado: $< -> $@"

$(BUILD_DIR)/%.o: $(TEST_DIR)/%.cpp
	@mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) -c $< -o $@
	@echo "Compilado: $< -> $@"

clean:
	rm -rf $(BUILD_DIR)/*
	@echo "Build directory limpo."

distclean: clean
	rm -f $(APP_TARGET) $(TEST_TARGET)
	@echo "Executáveis removidos."

run: $(APP_TARGET)
	./$(APP_TARGET)

test: $(TEST_TARGET)
	./$(TEST_TARGET)

.PHONY: all clean distclean run test
