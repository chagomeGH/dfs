//  graphl.cpp
//  Created by Mariana Chagoyan
//  Date 10/23/14 to 10/31/14

#include "graphl.h"

//------------------------------------------------------------------------------
/*  constructor
    sets and initializes GraphNode adjList objects to the follwoing:
    size to zero
    adjList data to null, visited to fall and edgeHead to null
 */
GraphL::GraphL(){
    
    size = 0;
    
    for(int i = 0; i < MAX_GL_NODES; i++){
        
        adjList[i].data = NULL;
        adjList[i].visited = false;
        adjList[i].edgeHead = NULL;
    }
}
//------------------------------------------------------------------------------
/*  destructor
    deletes all the edgeHead and data memory pointers from GrapheNode adjList
    (array of lists) by calling delete funciton
 */
GraphL::~GraphL(){
    
    if(MAX_GL_NODES > 0){
        for(int i =0; i < MAX_GL_NODES; i++){
        
            remove(i);
            delete adjList[i].data;
            adjList[i].data = NULL;
            adjList[i].edgeHead = NULL;
        }
    }
}
//------------------------------------------------------------------------------
/*  remove
    manually deletes all the pointers and memory alocated startting with the 
    edgeHead and then the nextEdge pointer from all the EdgeNodes
    @param index, integer representing index location in the adjList( array of
    lists)
 */
void GraphL::remove(int index){

    EdgeNode *current;
    EdgeNode *currentNext;
    
    if(adjList[index].edgeHead != NULL){
        current = adjList[index].edgeHead;
        
        while (current != NULL) {
            currentNext = current->nextEdge;
            delete current;
            current = currentNext;
        }
    }
}
//------------------------------------------------------------------------------
/*  buildGraph
    builds a GraphNode adjList(array of lists) by calling insert function 
    to insert EdgeNode right at the head of each adjList and not assorted value.
    By reading, extracting data from a text file and using getline function, 
    The first data are strings and they are stored in struct GraphNode by
    creating a NodeData pointer in array. 
    The second data are two integers in each line are the follwoing:
    First integer, represents the fromNode stored in adjList[index]
    Second integer, represents the toNode store in EdgeNode.
    @param infile, the text file containing all the data necessary to build 
    the node graph.
 */
void GraphL::buildGraph(ifstream& infile){
    
    int fromNode = 0, toNode = 0;
    
    infile >> size;
    
    if(infile.eof())
        return;

    string s;
    getline(infile, s);
    
    if(size > 0){
        for(int i = 1; i <= size; i++){
            adjList[i].data = new NodeData();
            adjList[i].data->setData(infile);
            adjList[i].visited = false;
            adjList[i].edgeHead = NULL;
        }
        for(;;){
            
            infile >> fromNode >> toNode;
            if(fromNode == 0 || toNode == 0){
                return;
            }
            else{
                if(fromNode > 0 && toNode > 0 && fromNode <= size){
                    insert(fromNode, toNode);
                }
                else{
                    break;
                }
            }
        }
    }
}
//------------------------------------------------------------------------------
/*  insert
    insert and EdgeNode right at the head of each adjList as the data is
    extracted from a text file and without assorting the values.
    @param fromNode, first integer value representing the origin node
    @param toNode, integer value representing the nextEdge node
 */
void GraphL::insert(int fromNode, int toNode){
    
    EdgeNode *newEdgeNode = new EdgeNode;
    newEdgeNode->adjGraphNode = toNode;
    
    // list is empty
    if(adjList[fromNode].edgeHead == NULL){
        
        newEdgeNode->nextEdge = NULL;
        adjList[fromNode].edgeHead = newEdgeNode;
        
    }// list is not empty
    else{
        
        newEdgeNode->nextEdge = adjList[fromNode].edgeHead;
        adjList[fromNode].edgeHead = newEdgeNode;
    }
}
//------------------------------------------------------------------------------
/*  displayGraph
    displays all data stored on graph starting with the string store in NodeData
    and then the integer data store in the edgeNode starting on the EdgeHead
 */
void GraphL::displayGraph(){
    
    EdgeNode *tempEdgeNode;
    cout << "Graph:" << endl;
    
    for(int i = 1; i < size + 1; i++){
        cout << left << "Node  " << setw(10) << i;
        cout << *adjList[i].data << endl;
        
        if(adjList[i].edgeHead != NULL){
            tempEdgeNode = adjList[i].edgeHead;
            
            while (tempEdgeNode != NULL) {
                
                cout << "   edge  " << i << " ";
                cout << tempEdgeNode->adjGraphNode << endl;
                tempEdgeNode = tempEdgeNode->nextEdge;
            }
        }
    }
    cout << endl;
}
//------------------------------------------------------------------------------
/*  depthFirstSearch
    retrieves the most deep data store on edgeNodes by traversing the adjList
    from EdgeHead all the way to the last next EdgeNode. Begins by marking all 
    the EdgeNode visited variables to false, and checks again if they are not 
    visitied before calling dfs method to help traverse the adjList recursiverly
    all to the last Edgenode in reverse order
 */
void GraphL::depthFirstSearch(){
    
    // mark all vertices (GraphNode) as not visited
    for(int i = 1; i < size; i++){
        
        adjList[i].visited = false;
    }
    cout << "Depth-first ordering:";
    
    // loop through vertices index in adjList to check if they haven't visited
    for(int v = 1; v < size; v++){
        if(adjList[v].visited == false){
         
            dfs(v);
        }
    }
    cout << endl;
}
//------------------------------------------------------------------------------
/*  dfs
    displays index conttents by traversing adjList recursively all the way to 
    the last edgeNode by checking if an EdgeNode has not been visited
    @param v, integer representing index(GraphNode) at the head of each adjList
 */
void GraphL::dfs(int v){
    
    adjList[v].visited = true;
    cout << v << " ";
    
    for(EdgeNode *tempEdgeNode = adjList[v].edgeHead;
                tempEdgeNode != NULL;
                tempEdgeNode = tempEdgeNode->nextEdge){
        if(adjList[tempEdgeNode->adjGraphNode].visited == false){
            
            dfs(tempEdgeNode->adjGraphNode);
        }
    }
}
//------------------------------------------------------------------------------
