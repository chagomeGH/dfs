//  graphl.h
//  Created by Mariana Chagoyan
//  Dates 10/23/14 to 10/31/14

#ifndef graphl_h
#define graphl_h

#include "nodedata.h"
#include <iomanip>

//------------------------------------------------------------------------------
/*  GraphL class implements an unweighted graph represented through an adjacency 
    list(array of lists) which main objects are GraphNodes, EdgeNode and 
    addition to the follwoing:
    1. Struct GraphNode containing three parts:
        a) EdgeHead pointer pointing to the head of each list.
        b) NodeData pointer pointing to string data value store at GraphNode.
        c) Boolean visited variable to verify if a node is visited or not.
    2. Struct EdgeNode containing two parts:
        a) adjGraphNode containing the integer that represents origin node(fromNode)
        b) EdgeNode pointer (nextEdge) pointing to the next node or edge(toNode)
    3. GraphNode adjList[] representing the array part of adjList
    4. Size which represetns the size for adjList
    5. Does not include copy constructor
    
    GraphL class builds adjList objected by extracting all the data from a text
    file and inserted as it comes at the edgeHead of the list and all the node 
    values do not need to be assorted. In addition, this class implements a 
    depth-first search function that searches for the deepest node of the graph 
    and displays data from the nodes in reverse order from the deepest(last) to 
    the most superficially(first).
 
    Assumtions:
    User knows the follwoing information:
 1. Maximum capacity of nodes for the arrayList is 100 nodes.
 2. Firs line integer represetns the number of total nodes on arraylist
 3. Lines with texts represent node location with NodeData(string) values
 4. Lines with 2 integers represent: fromNode and toNode
 5. A zero in one line represent the end of the data for one graph
 6. Negative integers are ignored as well as other incorrect input data
 7. The data from the node in the graph will only be display if all its nodes
    are connected
 */
//------------------------------------------------------------------------------

const int MAX_GL_NODES = 100;

class GraphL{
    
public:
    
    GraphL();                       // constructor
    ~GraphL();                      // destructor
    
    void remove(int);               // removes an edge value between two nodes
    void buildGraph(ifstream&);     // builds adjList by adding edgeNodes values
    void insert(int, int);          // insert an edge value between two nodes
    
    void displayGraph();            // displays data contents in adjList
    void depthFirstSearch();        // searches, marks and checks visited nodes
    void dfs(int);                  // searches the deepest node from adjList
    
private:
    
    struct EdgeNode;                // forward reference for the compile
    
    struct GraphNode{               // GraphNode struct contains:
        
        EdgeNode *edgeHead;         // head pointer to each list
        NodeData *data;             // NodeData pointer to string value
        bool visited;               // holds boolean visited value
    };
    
    struct EdgeNode{                // EdgeNode stuct contains:
        
        int adjGraphNode;           // subscript of the adjacent graph node
        EdgeNode *nextEdge;         // EdgeNode pointer to the nextEdge node
    };
    
    GraphNode adjList[MAX_GL_NODES]; // array of list type GraphNode
    int size;                        // size of the array list
    
};

#endif
