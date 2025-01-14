CFLAGS =
INCLUDES = core/unitTester/unitTester.hpp
DEBUG = -g -Wall -Wextra -pedantic

% : %.cpp
	g++ $(CFLAGS) $(INCLUDES) -o $@ $<

run:
	@echo "Compiling..."
	g++ $(CFLAGS) $(INCLUDES) -o main main.cpp
	@cls
	@./main.exe

debug:
	@echo "Compiling..."
	g++ $(DEBUG) $(CFLAGS) $(INCLUDES) -o main main.cpp

clean:
	@echo "Deleting..."
	@rm main
