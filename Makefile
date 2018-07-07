CC = g++
CFLAGS = -g -Wall -std=c++11

simulator: test_shortest_path.o priority_queue.o shortest_path.o weighted_graph.o undirected_edge.o vertex.o
	$(CC) $(CFLAGS) -o simulator test_shortest_path.o priority_queue.o shortest_path.o weighted_graph.o undirected_edge.o vertex.o

test_shortest_path.o: test_shortest_path.cpp shortest_path.h weighted_graph.h undirected_edge.h vertex.h priority_queue.h
	$(CC) $(CFLAGS) -c test_shortest_path.cpp

shortest_path.o: shortest_path.cpp weighted_graph.h undirected_edge.h vertex.h priority_queue.h
	$(CC) $(CFLAGS) -c shortest_path.cpp

priority_queue.o: priority_queue.cpp priority_queue.h
	$(CC) $(CFLAGS) -c priority_queue.cpp

weighted_graph.o: weighted_graph.cpp undirected_edge.h vertex.h
	$(CC) $(CFLAGS) -c weighted_graph.cpp

undirected_edge.o: undirected_edge.cpp vertex.h
	$(CC) $(CFLAGS) -c undirected_edge.cpp

vertex.o: vertex.cpp
	$(CC) $(CFLAGS) -c vertex.cpp

clean:
	rm *.o simulator
