all: client.cpp server.cpp header.h
	g++ header.h -o header
	g++ -std=c++14 -o server server.cpp -lpthread -I.
	g++ -std=c++14 -o client client.cpp -lpthread -I.