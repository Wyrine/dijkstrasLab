//Kirolos Shahat
//Graph class methods
//graph.cpp

#include "graph.h"

using namespace std;

//buildGraph fills the adjacencyList with the appropriate weights for an undirected graph
void Graph::buildGraph(vector<int> start, vector<int> target, vector<int> weight){
  //looping from the start to the end of all three vectors at the same time
  //since they are all the same length
  for(int i = 0; i < start.size(); i++){
    //assign the weight from node a to b to be the current weight
    adjacencyList[start[i]-1][target[i]-1] = weight[i];
    //assign the weight from node b to a to be the current weight
    adjacencyList[target[i]-1][start[i]-1] = weight[i];
  }
}

//finding the shortest path between two nodes with weighted arcs
void Graph::shortestWeighted(int startNode, int targetNode){
  //f will be the array that contains list of the nodes that have been fixed
  vector<int> f;
  //the d array will be the distance to each node
  //the s array will be the path to each node
  DijkstraVariable *path, *dist;
  int i, j, least;
  path = new DijkstraVariable [graphSize];
  dist = new DijkstraVariable [graphSize];
  for(i = 0; i < graphSize; i++){
    if(i == startNode){
      path[i].flipFixed();
      dist[i].flipFixed();
    }
    path[i].setValue(startNode);
    dist[i].setValue(adjacencyList[startNode][i]);
  }
  f.push_back(startNode);
  while(f.back() != targetNode){
    for(i = 0; i < graphSize; i++){

    }
  }

  path = NULL;
  dist = NULL;
  delete[] path;
  delete[] dist;
}

//finding the shortest path between two nodes with unweighted arcs
void Graph::shortestUnweighted(int startNode, int targetNode){
  vector<int> f;

}

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
  buildGraph(start, target, weight);
}
//print method to print the matrix. Purely for error checking/debugging
void Graph::print(){
  //loop through the rows of the matrix
  for(int i = 0; i < graphSize; i++){
    //so we know the row number
    cout << i+1 << "| ";
    //loop through the columns of the matrix
    for(int j = 0; j < graphSize; j++)
      //print out the current value
      cout << adjacencyList[i][j] << "  ";
    cout << endl;
  }
}

//shortest path calls the shortWeighted method and the shortestUnweighted methods
//to find the shortest paths of an undirectd graph
void Graph::shortestPath(int startNode, int targetNode){
  //getting the shortest weighted path
  shortestWeighted(startNode-1, targetNode-1);
  //getting the shortest unweighted path
  shortestUnweighted(startNode-1, targetNode-1);
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
