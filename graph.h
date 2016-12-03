//Kirolos Shahat
//Graph class where it contains the graph data
//graph.h

#include <iostream>
#include <vector>

//class definition
class Graph{
  //the matrix that will be built when the size is retrieved
  int** adjacencyList;
public:
  //the function that builds the graph
  void buildGraph(int graphSize, vector<int> start, vector<int> target, vector<int> weight);
};
