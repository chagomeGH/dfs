# dfs
Depth First Search

Implementation Descriptions for Depth First Search Algorithm

Display the graph information and implement depth-first search using the ordering as given by the data starting at one. Display the node numbers in depth-first order. Implement the specified graph ADT functions.

The data to run this program is on data32.txt file and the first line tells the number of nodes, say n. Following is a text description of each of the 1 through n nodes, one description per line (50 chars max length). After that, each line consists of 2 ints representing an edge. If there is an edge from node 1 to node 2, the data is: 1 2.  A zero for the first integer signifies the end of the data for that one graph. 
All the edges for the first node will be together first, then all the edges for the second node, etc. Take them, as they come, no sorting. (Edges in input will always be in reverse order in the output, discussed below). There are several graphs, each having at most 100 nodes. Assume the input data file has correctly formatted data. For example:

Sample Input picture (not part of data)
5
Aurora and 85th
Green Lake Starbucks
Woodland Park Zoo
Troll under bridge
PCC
1 5
1 3
1 2
2 4
3 4
3 2
5 4
5 2
0 0 

Implement using an adjacency list (array of lists).  Add any needed data, e.g., a field in the graph node can be used to mark visiting a node. The object with the information on a graph node can neither be directly stored in GraphNode (as in NodeData) or as a pointer to an object (like NodeData*). As with part1, start in array element one. 


Assumptions:
The input data file has correctly formatted data meaning that there will be 2 ints on one line of data for an edge. 
The only methods implemented for this class are the constructor, destructor, buildGraph, displayGraph, and depthFirstSearch. A driver that (partially) tests your code is also provided. 

To simplify things, you should always insert EdgeNodes at the beginning of the adjacency list for a Node. Your output of the edges for each Node will, thus, be in the reverse order in which they are listed in the input file. An EdgeNode list may not be sorted. (They are sorted in the example for readability.) Make sure to follow this coding simplification (and process the edges in the order they are in the list,) since it affects the depth-first ordering that you will get. Note that you must handle a graph with disconnected components. 

