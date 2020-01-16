all: ev3dev.a ev3dev-lang-demo.o
	arm-linux-gnueabi-g++-4.7 -L. -o ev3dev-lang-demo ev3dev-lang-demo.o -lev3dev

ev3dev.a: ev3dev.cpp 
	arm-linux-gnueabi-g++-4.7 -c ev3dev.cpp -o ev3dev.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
	ar -r libev3dev.a ev3dev.o

ev3dev-lang-demo.o: ev3dev-lang-demo.cpp
		arm-linux-gnueabi-g++-4.7 -c ev3dev-lang-demo.cpp -o ev3dev-lang-demo.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
clean:
	rm *.a
	rm *.o