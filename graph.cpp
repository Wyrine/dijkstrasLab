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
void Graph::dijkstraAlgorithm(int startNode, int targetNode, int** adjacencyList){
  //solution will have the path from start to finish
  vector<int> solution;
  //declaring a DijkstraVariable array which has a distance and path
  DijkstraVariable* var = new DijkstraVariable [graphSize];
  //declaring some needed variables
  int i, j, least, numFixed, nextPath = startNode;
  for(i = 0; i < graphSize; i++){
    if(i == startNode) var[i].flipFixed();
    var[i].setValue(startNode, adjacencyList[startNode][i]);
  }
  while(!var[targetNode].isFixed()){
    least = INT_MAX;
    for(i = 0; i < graphSize; i++){
      if(!var[i].isFixed()){
        if(var[i].dist != INT_MAX && var[i].dist != 0 ){
          if(var[i].dist < least) {
            nextPath = i;
            least = var[i].dist;
          }
        }
      }
    }
    var[nextPath].flipFixed();
    least = INT_MAX;
    for(j = 0; j < graphSize; j++){
      cout << "hey";

      if(!var[j].isFixed()){
        least = min(var[j].dist, adjacencyList[nextPath][j] + var[nextPath].dist);
        if(least < var[j].dist){
          var[j].setValue(nextPath, least);
        }
      }
    }
  }
  solution.clear();
  nextPath = targetNode;
  do{
    solution.push_back(nextPath);
    nextPath = var[nextPath].path;
  }while(nextPath != startNode);
  solution.push_back(nextPath);
  for(i = solution.size()-1; i > 0; i--) cout << solution[i]+1 << " ";
  cout << endl;
  cout << "D = " << var[targetNode].dist << endl;
  var = NULL;
  delete[] var;
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
      //looping to initialize the matrix with INT_MAX if it's not the main diagonal
      adjacencyList[i][j] = INT_MAX;
      //setting the main diagonal to 0
      adjacencyList[i][i] = 0;
    }
  }
  //calling the buildGraph method to fill the matrix with the proper values
  buildGraph(start, target, weight);
}
//print method to print the matrix. Purely for error checking/debugging
void Graph::print(){
  char infinity = 236;
  //loop through the rows of the matrix
  for(int i = 0; i < graphSize; i++){
    //so we know the row number
    cout << i+1 << "| ";
    //loop through the columns of the matrix
    for(int j = 0; j < graphSize; j++){
      //print out the current value
      if(adjacencyList[i][j] == INT_MAX) cout << infinity << " ";
      else cout << adjacencyList[i][j] << "  ";
    }
    cout << endl;
  }
}

//shortest path calls the shortWeighted method and the shortestUnweighted methods
//to find the shortest paths of an undirectd graph
void Graph::shortestPath(int startNode, int targetNode){
  //creating a temp 2D array and allocating/initializing it
  //and it will be used to find the unweighted shortest path
  //and it essentially changes all of the weights to be 1
  int** tempAdj;
  tempAdj = new int* [graphSize];
  for(int i = 0; i < graphSize; i++){
    tempAdj[i] = new int [graphSize];
    for(int j = 0; j < graphSize; j++){
      if(adjacencyList[i][j] == INT_MAX || adjacencyList[i][j] == 0)
        tempAdj[i][j] = adjacencyList[i][j];
      else //if the index had a weight that wasn't the max or 0
        //set it to 1. All weights will be 1
        tempAdj[i][j] = 1;
    }
  }
  cout << "Weighted:\nPath1 = ";
  //calling dijkstraAlgorithm with the adjacencyList because it's the weighted one
  dijkstraAlgorithm(startNode-1, targetNode-1, adjacencyList);
  cout << "Unweighted:\nPath2 = ";
  //calling dijkstraAlgorithm with the tempAdj because it's the unweighted one
  dijkstraAlgorithm(startNode-1, targetNode-1, tempAdj);
  //deallocating the tempAdj matrix
  for(int i = 0; i < graphSize; i++){
    tempAdj[i] = NULL;
    delete[] tempAdj[i];
  }
  tempAdj = NULL;
  delete[] tempAdj;
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
