all: ev3dev.a example.o h_crane.o
	arm-linux-gnueabi-g++-4.7 -L. -o example example.o h_crane.o -lev3dev

ev3dev.a: ev3dev.cpp 
	arm-linux-gnueabi-g++-4.7 -c ev3dev.cpp -o ev3dev.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
	ar -r libev3dev.a ev3dev.o

example.o: example.cpp
		arm-linux-gnueabi-g++-4.7 -c example.cpp -o example.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
		
h_crane.o: h_crane.cpp
		arm-linux-gnueabi-g++-4.7 -c h_crane.cpp -o h_crane.o -std=c++11 -D_GLIBCXX_USE_NANOSLEEP
clean:
	rm *.a
	rm *.o