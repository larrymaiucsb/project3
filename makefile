all: project3.out

project3.out: avl.cpp main.cpp project3.out
	g++ -std=c++11 $^ -o $@

clean:
	rm -f *.out