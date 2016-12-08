#include "Graph.hpp"
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include <vector>



Graph GenerateData(){
	srand (time(NULL));
	const int numMovies = 10000;
	const int numActors = numMovies * 40;
	std::vector<int> Movies = std::vector<int>();
	std::vector<int> Actors = std::vector<int>();
	Graph graph = Graph)_;
	for(int i = 0; i < numMovies; i++){
		Movies.push_back(rand());
		graph.AddMovie(Movies[i]);
	}

	for(int i = 0; i < numActors; i++){
                Actors.push_back(rand());
		graph.AddActor(Actors[i]);
        }
	
	for(int i = 0; i < numMovies; i++){
		//this formula approximates the Pareto principle, that 20% of actors will be in 80% of movies
		int thisMovieLimit =   0.0000020012006203121563 * i * i  +  39.975985592556256 * i +  40.02401240624312;
		for (int j = 0; j < 40; j++){
			int thisActor = rand() % thisMovieLimit;
			graph.AddConnection(Actors[i], Movies[thisActor]);
		}
	}

	return Graph();
}

int main(){
	Graph output = GenerateData();
	return 0;
}
