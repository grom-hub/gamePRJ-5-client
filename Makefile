start: Client
	./Client

Client: main.cpp
	g++ -o Client main.cpp units.cpp connector.cpp -lncurses -std=c++11

clean:
	rm Client
