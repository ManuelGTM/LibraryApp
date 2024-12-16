# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -O2 -std=c++17
BUILD_DIR = build
SRC_DIR = src
PROJECT_NAME = Biblioteca
TARGET = $(BUILD_DIR)/$(PROJECT_NAME)

# Archivos fuentes y objetos
SRCS = $(shell find $(SRC_DIR) -type f -name "*.cpp")
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Regla principal
all: $(TARGET)
	./${TARGET}

# Crear el ejecutable
$(TARGET): $(OBJS)
	@mkdir -p $(dir $(TARGET))
	@$(CXX) $(CXXFLAGS) $(OBJS) -o $@

# Crear objetos en build manteniendo la estructura
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@

# Limpiar archivos compilados
clean:
	@rm -rf $(BUILD_DIR)
	@echo "Carpeta build limpiada."

# Reconstruir todo
rebuild: clean all

