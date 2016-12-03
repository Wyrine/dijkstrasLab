//Kirolos Shahat
//Graph class methods
//graph.cpp

#include "graph.h"

using namespace std;

//buildRelation builds the adjacency relation through memory allocation and initializes
//the indices with -1 if not in the main diagonal otherwise with 0 and then calls buildGraph
//to fill the graph with the proper values
void Graph::buildRelation(int graphSize, vector<int> start, vector<int> target, vector<int> weight){
  //storing the graphSize into the table
  this->graphSize = graphSize;
  //dynamically allocating the number of rows in the array
  adjacencyList = new int* [graphSize];
  //looping to allocate the colums
  for(int i = 0; i < graphSize; i++){
    //allocating the memory per column
    adjacencyList[i] = new int [graphSize];
    for(int j = 0; j < graphSize; j++){
      //looping to initialize the matrix with -1 if it's not the main diagonal
      adjacencyList[i][j] = -1;
      //setting the main diagonal to 0
      adjacencyList[i][i] = 0;
    }
  }
  //calling the buildGraph method to fill the matrix with the proper values
  //builGraph(vector<int> start, vector<int> target, vector<int> weight);
}

//destructor for the Graph class to deallocate the adjacencyList allocation
Graph::~Graph(){
  //loop through the rows of the adjacencyList
  for(int i = 0; i < graphSize; i++){
    //deallocate the column in the current index
    adjacencyList[i] = NULL;
    delete[] adjacencyList[i];
  }
  //deallocate the row allocated
  adjacencyList = NULL;
  delete[] adjacencyList;
}
