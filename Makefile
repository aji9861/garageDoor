all: 
	g++ src/*.cpp -o test.out

test: all
	./test.out
	make clean

clean:
	rm test.out
