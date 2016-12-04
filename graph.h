//Kirolos Shahat
//Graph class where it contains the graph data
//graph.h

#include <iostream>
#include <vector>

#define CUR_START start[i]-1
#define CUR_TARGET target[i]-1

using namespace std;

class Graph;

class DijkstraVariable{
  friend class Graph;
  bool fixed;
  int value;
  DijkstraVariable(){ fixed = false; }
  void flipFixed(){ fixed = true; }
  void setValue(int v){ value = v; }
  bool isFixed(){ return fixed; }
};

//class definition
class Graph{
  //the matrix that will be built when the size is retrieved
  int** adjacencyList, graphSize;

  //the private methods
  void buildGraph(vector<int> start, vector<int> target, vector<int> weight);
  void shortestWeighted(int startNode, int targetNode);
  void shortestUnweighted(int startNode, int targetNode);
public:
  //the public methods
  void buildRelation(int graphSize, vector<int> start, vector<int> target, vector<int> weight);
  void print();
  void shortestPath(int startNode, int targetNode);
  ~Graph();
};
