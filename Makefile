SOURCE=$(wildcard Source/*.cpp)
OBJECTS=$(SOURCE:.cpp=.o) 

all:$(OBJECTS)
	g++ -o $@ $(OBJECTS)

%.o:%.cpp
	g++ -c $< -o $@

print::
	@echo $(SOURCE)
	@echo $(OBJECTS)

clean:
	rm -rf Source/*.o *.exe