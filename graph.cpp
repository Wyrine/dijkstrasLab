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
  //f will be the array that contains list of the nodes that have been fixed
  vector<int> f;
  //declaring a DijkstraVariable array which has a distance and path
  DijkstraVariable* var = new DijkstraVariable [graphSize];
  //declaring some needed variables and setting least to be the biggest number
  //an int can be
  int i, j, least, prevMin, nextPath = startNode;
  for(i = 0; i < graphSize; i++){
    if(i == startNode){
      var[i].flipFixed();
    }
    var[i].setValue(startNode, adjacencyList[startNode][i]);
  }
  while(nextPath != targetNode){
    least = INT_MAX;
    for(i = 0; i < graphSize; i++){
      if(!var[i].isFixed() && var[i].dist > 0){
        prevMin = least;
        least = min(least, var[i].dist);
        if (prevMin != least) nextPath = i;
      }
    }
    if(least > 0 && least < INT_MAX){
      var[nextPath].flipFixed();
      for(i = 0; i < graphSize; i++){
        if(!var[i].isFixed()){
          least = min(var[i].dist, adjacencyList[nextPath][i] + var[nextPath].dist);
          if(least < var[i].dist){
            var[i].dist = least;
            var[i].path = nextPath;
          }
        }
      }
    }
  }
  nextPath = targetNode;
  do{
    f.push_back(nextPath);
    nextPath = var[nextPath].path;
  }while(nextPath != startNode);
  f.push_back(nextPath);
  for(i = 0; i < f.size(); i ++) cout << f[i] << " ";
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
  int** tempAdj;
  tempAdj = new int* [graphSize];
  for(int i = 0; i < graphSize; i++){
    tempAdj[i] = new int [graphSize];
    for(int j = 0; j < graphSize; j++){
      if(adjacencyList[i][j] == INT_MAX || adjacencyList[i][j] == 0)
        tempAdj[i][j] = adjacencyList[i][j];
      else
        tempAdj[i][j] = 1;
    }
  }
  //getting the shortest weighted path
  cout << "Weighted:\nPath1 = ";
  dijkstraAlgorithm(startNode-1, targetNode-1, adjacencyList);
  //getting the shortest unweighted path
  cout << "Unweighted:\nPath2 = ";
  dijkstraAlgorithm(startNode-1, targetNode-1, tempAdj);
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
