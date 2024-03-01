EXE = bin/main.out
SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
OBJ := $(SRC:src/%.cpp=obj/%.o)
FLAG = -ggdb -O3 -pedantic -Wall -Wextra -Werror
CXX = g++

# $@ nom de la cible
# $< nom de la premiere dependance
# $^ nom de toutes les dependances

all: $(EXE)

$(EXE): $(OBJ)
	$(CXX) $(FLAG) $^ -o $(EXE)

.PHONY:obj/%.o
obj/%.o : src/%.cpp
	$(CXX) $(FLAG) -c $< -o $@

# --------------------  -------------------- #

clean : ## supprime les dépendances, les fichiers objets, la doc et les executables
	@echo "suppression des objets"
	@rm -f $(OBJ)
	@echo "suppression de la documentation"
	@rm -rf doc/html* doc/xml*
	@echo "suppression des executables"
	@rm -f $(EXE)





