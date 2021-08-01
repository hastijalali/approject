
all: server.cpp client.cpp header.h
	g++ -o server server.cpp -lpthread -I.
	g++ -o client client.cpp -lpthread -I.
	g++ -o header header.h‏

