CFLAGS = -fimplicit-constexpr -std=c++20
INCLUDES := $(shell find . -name '*.cpp')
OBJ := $(patsubst %.cpp,%.o,$(INCLUDES))
DEBUG = -g -Wall -Wextra -pedantic
OUT = ./bin/main

%.o: %.cpp 
	g++ $(CFLAGS) -c $< -o $@  	
	@echo "Compiled:" $@

run: $(OBJ)
	@echo "Compiling..."
	g++ $(CFLAGS) $(OBJ) -o $(OUT) 
	@$(OUT)

debug: 
	@echo "Compiling..."
	g++ $(DEBUG) $(CFLAGS) $(INCLUDES) -o $(OUT)d

clean:
	@echo "Deleting..."
	@rm $(OBJ)
	@rm $(OUT)
	@rm $(OUT)d
