EXE = bin/main.out
SRC = $(wildcard src/*.cpp)
HEADERS = $(wildcard src/*.h)
OBJ := $(SRC:src/%.cpp=obj/%.o)
FLAG = -ggdb -O3 -pedantic -Wall -Wextra -Werror -DDEBUG
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

.PHONY:clean
clean : ## supprime les dépendances, les fichiers objets, la doc et les executables
	@echo "suppression des objets"
	@rm -f $(OBJ)
	@echo "suppression des executables"
	@rm -f $(EXE)
	@echo "création des dossiers (si nécessaire)"
	@mkdir -p bin obj



.PHONY:zip
zip : clean ## prépare pour le rendu et met le dépot dans un zip
	zip -r ../MAISON-SERPINET.zip . -i *.cpp *.h Makefile */




