main: main.cpp rossler_equation.cpp
	g++ -Wall -o cpp_exercise main.cpp rossler_equation.cpp -std=c++1z -I/usr/include/python2.7 -lpython2.7
	