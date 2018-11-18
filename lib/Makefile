
# add files you create here
OBJ = IntArray.o IntegerSetArray.o List.o MaxHeap.o ShortestPath.o StringArrayList.o hw2.o hw5.o lec04_hw.o pList.o DList.o Graph.o IntegerSet.o MaxHeap.o Queue.o MinHeap.o

all: libece309.a

test: all

# add files you want to remove here
clean:
	rm -f *~ libece309.a $(OBJ)

libece309.a: $(OBJ)
	$(AR) -r $@ $(OBJ)

%.o:%.cpp
	$(CXX) -c -o $@ -I . -I ../include $< -Wall -Werror
