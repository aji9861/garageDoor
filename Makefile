all: 
	g++ -Wall src/*.cpp src/Input/*.cpp src/Motor/*.cpp -lpthread -o test.out

test: all
	./test.out
	make clean

clean:
	rm test.out
