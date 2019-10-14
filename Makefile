SOURCE=$(wildcard Source/*.cpp)
TEST=$(wildcard Source/Tests/*.cpp)
OBJECTS=$(SOURCE:.cpp=.o) $(TEST:.cpp=.o)  
CXXFLAGS= -O3
all:$(OBJECTS)
	g++ $(CXXFLAGS) -o $@ $(OBJECTS)

%.o:%.cpp
	g++ $(CXXFLAGS) -c $< -o $@

print::
	@echo $(SOURCE)
	@echo $(OBJECTS)

clean:
	rm -rf Source/*.o Source/Tests/*.o *.exe