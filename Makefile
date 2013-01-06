all: 
	g++ src/*.cpp src/Input/*.cpp -lpthread -o test.out

test: all
	./test.out
	make clean

clean:
	rm test.out
