# Diretórios
SRC_DIR = src
INC_DIR = inc
BIN_DIR = bin

# Nome do executável
TARGET = $(BIN_DIR)/allegro-ffge

# Fontes e objetos
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(SRCS:$(SRC_DIR)/%.cpp=$(SRC_DIR)/%.o)

# Compilador e flags
CXX = g++
CXXFLAGS = -Wall -O2 -std=c++11 -I$(INC_DIR)
LDFLAGS = `allegro-config --libs`

# Criação do binário
all: $(BIN_DIR) $(TARGET)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDFLAGS)

$(SRC_DIR)/%.o: $(SRC_DIR)/%.cpp $(INC_DIR)/%.h
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(SRC_DIR)/*.o
	rm -rf $(BIN_DIR)

.PHONY: all clean