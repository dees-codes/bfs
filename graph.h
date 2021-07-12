#ifndef GRAPH_BECK
#define GRAPH_BECK

#include <iostream>
#include <iomanip>
#include <list>
#include <sstream>
#include <string>
#include <vector>

const unsigned WIDTH = 3; // assume < 100 vertices

class Graph
{
 public:
  /**
    * Read in the adjacency lists structure from std input.
    * Each line must take the form
    * label vertex vertex vertex ...
    * where label is the current vertex, starting at 0 and
    * numbered consecutively. Each vertex is adjacent to label.
    * All values whitespace separated, all lines newline terminated.
    * No error checking is done.
    */
  void read_graph()
  {
    // clear out the vector if there's anything in it
    if (g.size() != 0)
    {
      g.resize(0);
    }

    // read in the n lists
    std::string line;
    while (getline(std::cin, line))
    {
      // since we do no error checking, we assume label is the
      // correct next integer
      std::list<size_t> list_of_adjacent_vertices;
      std::stringstream line_stream(line);
      size_t vertex;
      line_stream >> vertex; // throw away the label
      while (line_stream >> vertex)
      {
        list_of_adjacent_vertices.push_back(vertex);
      }
      g.push_back(list_of_adjacent_vertices);
    } // while !eof
  } // read_graph

  /**
   * the number of nodes in the graph
   * @return the number of nodes in the graph
   */
  size_t size() const
  {
    return g.size();
  }

  /**
   * constant access to a list
   * @param label the node whose list we're asking for
   * @return a list of adjacency nodes
   */
  const std::list<size_t>& get_list(size_t label) const
  {
    return g.at(label);
  }

  /**
   * just for debugging, dump the entire graph to screen
   */
  void dump()
  {
    size_t vertex {0};
    for (auto thislist : g)
    {
      std::cout << '[' << std::setw(WIDTH) << vertex << ']';
      for (auto adjacent_vertex : thislist)
      {
        std::cout << " -> " << adjacent_vertex;
      }
      std::cout << std::endl;
      vertex++;
    }
  }

 private:
  std::vector<std::list<size_t>> g;
};
#endif
