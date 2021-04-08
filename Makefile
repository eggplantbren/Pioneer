CXX = g++
INCLUDE = -I . -I ./include
OPTIM = -O2 -g
WARN = -Wall -Wextra -pedantic
FLAGS = -std=c++2a $(INCLUDE) $(OPTIM) $(WARN)

default:
	$(CXX) $(FLAGS) -c src/Compare.cpp
	$(CXX) $(FLAGS) -c src/Database.cpp
	$(CXX) $(FLAGS) -c src/Example.cpp
	$(CXX) $(FLAGS) -c src/Target.cpp
	ar rcs libpioneer.a *.o
	$(CXX) $(FLAGS) -L . -o main main.cpp -lpioneer -lsqlite3
	rm -f *.o

