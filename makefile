all: fork1 fork2

fork1: fork1.cpp

fork2: fork2.cpp

clean:
	rm -f *~ fork[12]
