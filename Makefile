# Variables
CXX = g++
CXXFLAGS = -Wall -Wextra -O2
BUILD_DIR = build
SRC_DIR = src
PROJECT_NAME = Biblioteca
TARGET = ${BUILD_DIR}/${PROJECT_NAME}

# Archivos fuentes y objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

# Regla principal
all: ${TARGET}
	@./${TARGET}

# Regla para crear el ejecutable
${TARGET}: ${OBJS}
	@${CXX} ${OBJS} -o ${TARGET}

# Regla para crear la carpeta build
${BUILD_DIR}/%.o: ${SRC_DIR}/%.cpp
	@mkdir -p ${BUILD_DIR}
	@${CXX} ${CXXFLAGS} -c $< -o $@

# Regla para limpiar la carpeta
clean:
	@rm -rf ${BUILD_DIR}

# Compilar y ejecutar de nuevo
rebuild: clean all
