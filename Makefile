##start: clientMy
##	./clientMy

clientMy: main.cpp
	g++ -o clientMy main.cpp connector.cpp -lncurses -std=c++11

clean:
	rm clientMy
