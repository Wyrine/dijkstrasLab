//Kirolos Shahat
//Graph class where it contains the graph data
//graph.h

#include <iostream>
#include <vector>

#define CUR_START start[i]-1
#define CUR_TARGET target[i]-1

using namespace std;

//class definition
class Graph{
  //the matrix that will be built when the size is retrieved
  int** adjacencyList, graphSize;

  //the private methods
  void buildGraph(vector<int> start, vector<int> target, vector<int> weight);
public:
  //the public methods
  void buildRelation(int graphSize, vector<int> start, vector<int> target, vector<int> weight);
  void print();
  ~Graph();
};
