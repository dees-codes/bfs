/**
 * breadth-first search
 * Deepson Shrestha
 */

#include <iostream>
#include <list>
#include <vector>
#include <queue>
#include "graph.h"
using namespace std;

/**
 * the routine to start at a vertex, find out all the tree edges leading    
   to its adjacent vertices and repeat the process until all the vertices   
   are visited in breadth first order
 * @param g the adjacency lists graph
 * @param q the queue to hold the newly visited vertices whose adjacent 
            vertices have not been searched for
 * @param dist the vector to hold the path length of vertex
 */
void explore(const Graph& g, queue<size_t>& q, vector<size_t>& dist);

/**
 * the bfs algorithm proper
 * @param g the graph to run bfs on
 */
void bfs(const Graph& g);

int main()
{
  // declare a graph and read it in from standard input
  Graph g;
  g.read_graph();

  g.dump(); // for seeing the contents of the graph

  bfs(g);
  return 0;
}

void bfs(const Graph& g)
{
  cout << "starting bfs \n";

  // vector of size g.size() for storing distances of vertices from their
  // root ancestor vertex with every element initialized to SIZE_MAX
  vector<size_t> distance(g.size(), SIZE_MAX);
  std::queue<size_t> q;

  // go through all the nodes, exploring each unvisited vertex one by one
  for (size_t vertex {0}; vertex < g.size(); vertex++)
  {	
    if (distance.at(vertex) == SIZE_MAX)
    {
      cout << "on connected component " << vertex << endl;
      distance.at(vertex) = 0;    // set distance of root vertex to 0	 
      q.push(vertex);             // push the unvisited vertex into queue
      explore(g, q, distance);    // explore the unvisited vertex
    }
  }

  cout << "the final distance vector:" << endl;
  for (size_t i {0}; i < g.size(); i++)
  {
    cout << i << " " << distance.at(i) << endl;
  }

  cout << endl << "finished bfs" << endl;
}

void explore(const Graph& g, queue<size_t>& q, vector<size_t>& dist)
{
  // vertex whose adjacent vertices is to be figured out
  size_t vertex;

  // go through the loop until q is empty i.e. until every vertex's
  // adjacent vertices have been searched for
  while (!q.empty())
  {
    vertex = q.front();   
    q.pop();

    cout << "found vertex " << vertex << endl;

    // store the adjacent vertices of the vertex in a list
    list<size_t> list_of_adjacent_vertices {g.get_list(vertex)};

    // go through the vertex's adjacent vertices, mark tree edges if
    // those adjacent vertices are being visited for the first time and
    // set the length of the path to one more than the path length of
    // parent vertex
    for (auto w : list_of_adjacent_vertices)
    {
      if (dist.at(w) == SIZE_MAX)
      {
        cout << "tree edge: " << "(" << vertex << "," << w
	  << ")" << endl ;
        dist.at(w) = dist.at(vertex) + 1;
        q.push(w);    // push the adjacent unvisited vertex into queue
      }
    } // end for    
  } // end while
  cout << endl;       // Blank line after the connected component
}

	    
	    
