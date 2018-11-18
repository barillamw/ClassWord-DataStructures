
# list the name of each file (without the .cpp file at the end)
EXE =  Graph IntArray IntInf IntegerSetArray MaxHeap hash hw4 pTest

all: $(EXE)

run: all $(addsuffix -run,$(EXE))

clean:
	rm -f $(EXE) *~ logfile.txt $(ECE)

%: %.cpp
	$(CXX) -o $@ $< -Wall -Werror -I ../include -L ../lib -lece309 -std=c++11

%-run:
	@./$*
