#include <string>
#include <vector>

struct Vertex {
	std::string Name;
	int Index;
	bool IsActor;

	Vertex() = default;

	Vertex(std::string n, int i, bool a)
	:Name(n), Index(i), IsActor(a){}
};

struct Edge {
	Vertex A;
	Vertex B;

	Edge(Vertex A, Vertex B)
	:A(A), B(B){}
};

struct Graph{
	std::vector<std::vector<Edge>> Actors;
	std::vector<std::vector<Edge>> Movies;

	Graph() = default;

	void AddActor(){

	}

	void AddMovie(){

	}

	void AddConnection(){

	}
};
