all: main client server
	
client: client.o list.o list_node.o record.o command.o
	g++ -o client main.o list.o record.o list_node.o command.o

server: server.o list.o list_node.o record.o command.o
	g++ -o server main.o list.o record.o list_node.o command.o

main: main.o list.o list_node.o record.o command.o
	g++ -o main main.o list.o record.o list_node.o command.o

main.o: main.cpp
	g++ -c main.cpp

client.o: client.cpp
	g++ -c client.cpp

server.o: server.cpp
	g++ -c server.cpp

list.o: list.cpp
	g++ -c list.cpp

list_node.o: list_node.cpp
	g++ -c list_node.cpp

record.o: record.cpp
	g++ -c record.cpp

command.o: command.cpp
	g++ -c command.cpp