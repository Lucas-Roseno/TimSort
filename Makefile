# Variáveis de compilação
BUILD     := build
OBJ_DIR   := $(BUILD)/objects
APP_DIR   := $(BUILD)
TARGET    := app

# Fontes e Includes
# Corrigido para procurar headers na pasta 'src'
INCLUDE   := -Isrc/
SRC       := $(wildcard src/*.cpp)
OBJECTS   := $(patsubst src/%.cpp,$(OBJ_DIR)/%.o,$(SRC))

# Compilador e Flags
CXX       := g++
CXXFLAGS  := -Wall -Wextra -Werror
LDFLAGS   := -lm

# --- Regras ---

# MODIFICADO: A regra 'all' agora compila e roda o programa.
# Ela faz isso simplesmente chamando a regra 'run'.
all: run

# Compilar o executável
$(APP_DIR)/$(TARGET): $(OBJECTS)
	@mkdir -p $(dir $@)
	@$(CXX) $(OBJECTS) -o $@ $(LDFLAGS)
	@chmod +x $@
	@echo "Compilado com sucesso!"

# Compilar os arquivos objeto (.o)
$(OBJ_DIR)/%.o: src/%.cpp
	@mkdir -p $(dir $@)
	@$(CXX) $(CXXFLAGS) $(INCLUDE) -c $< -o $@

# Limpar arquivos compilados
clean:
	@rm -rf $(BUILD)
	@echo "Build limpo!"

# Rodar o programa.
# Esta regra primeiro garante que o programa está compilado (dependência),
# e então o executa.
run: $(APP_DIR)/$(TARGET)
	@clear
	@echo "Executando $(APP_DIR)/$(TARGET)..."
	@./$(APP_DIR)/$(TARGET)

# MODIFICADO: A regra 'full' agora só precisa chamar 'clean' e 'all',
# pois 'all' já inclui a execução do programa.
full: clean all

# Define regras que não geram arquivos
.PHONY: all clean run full
