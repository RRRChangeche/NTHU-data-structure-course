// Ref: 
#include <iostream>
#include <algorithm>
// #include "Chain.h"   // this line can't work https://www.youtube.com/watch?v=0u9_u1d-y-4&ab_channel=ProgrammingWithHT
#include "Chain.cpp"    // this line can work
using namespace std;

class Graph
{// object: A nonempty set of vertices and a set of undirected edges. 
public:
    virtual ~Graph() {} // virtual destructor
    bool IsEmpty() const{return n == 0;}; // return true iff graph has no vertices

    int NumberOfVertices() const{return n;}; // return the # of vertices
    int NumberOfEdges() const{return e;}; // return the # of edges
    virtual int Degree(int u) const = 0; // return the degree of a vertex
    // virtual bool ExistsEdge(int u, int v) const = 0; // check the existence of edge 

    // virtual void InsertVertex(int v) = 0; // insert a vertex v
    // virtual void InsertEdge(int u, int v) = 0; // insert an edge (u, v)
    // virtual void DeleteVertex(int v) = 0; // delete a vertex v
    // virtual void DeleteEdge(int u, int v) = 0; // delete an edge (u, v)
    
    // More graph operations…
    virtual void DFS_by_Recursive() = 0;
    virtual void DFS_by_Recursive(const int) {};
protected:
    int n; // number of vertices
    int e; // number of edges
    bool* visited; 
};


class LinkedGraph: public Graph{
public: 
    // construcor
    // LinkedGraph(const int vertices = 0): n(vertices), e(0){
    LinkedGraph(const int vertices = 0){
        n = vertices; e = 0;
        adjLists = new Chain<int>[n];
    }

    int Degree(int u) const; // return the degree of a vertex
    bool ExistsEdge(int u, int v) const; // check the existence of edge 

    void InsertVertex(int v); // insert a vertex v
    void InsertEdge(int u, int v); // insert an edge (u, v)
    // void DeleteVertex(int v) = 0; // delete a vertex v
    // void DeleteEdge(int u, int v) = 0; // delete an edge (u, v)
    
    // More graph operations…
    void DFS_by_Recursive();
    void DFS_by_Recursive(const int);

private:
    Chain<int>* adjLists;   // adjacency lists
};


int LinkedGraph::Degree(int u) const {
    Chain<int> uList = adjLists[u];
    ChainNode<int>* node = uList.GetFirstNode();
    if (!node) cout << "Vertex " << u << " not exists" << endl;

    int degree = 0;
    while (node){
        degree++;
        node = node->link;
    }
    return degree;
}

bool LinkedGraph::ExistsEdge(int u, int v) const // check the existence of edge 
{
    int uDegree;
    Chain<int> u_adjList = adjLists[u];
    ChainNode<int>* u_adjNode = u_adjList.GetFirstNode();
    uDegree = Degree(u);
    // Chain<int> v_adjList = adjLists[v];
    // ChainNode<int>* v_adjNode = v_adjList.GetFirstNode();
    // vDegree = Degree(v);

    // check if u/v exist in each adjList, if not, add it
    for (int i=0; i<uDegree; i++){
        u_adjNode = u_adjNode->link;
        if (v == u_adjNode->data) return true;
    }
    return false;
}

void LinkedGraph::InsertVertex(int v) // insert a vertex v
{
    Chain<int> adjList = adjLists[v];
    adjList.InsertBack(v);
    adjLists[v] = adjList;
}

void LinkedGraph::InsertEdge(int u, int v) // insert an edge (u, v)
{
    int uDegree, vDegree;
    Chain<int> u_adjList = adjLists[u];
    ChainNode<int>* u_adjNode = u_adjList.GetFirstNode();
    uDegree = Degree(u);
    Chain<int> v_adjList = adjLists[v];
    ChainNode<int>* v_adjNode = v_adjList.GetFirstNode();
    vDegree = Degree(v);
    
    if (ExistsEdge(u,v)) return;
    else{
        // add u/ v into each adjList 
    }
}

// void LinkedGraph::DeleteVertex(int v) // delete a vertex v
// {

// }

// void LinkedGraph::DeleteEdge(int u, int v) // delete an edge (u, v)
// {

// }

void LinkedGraph::DFS_by_Recursive(){
    visited = new bool[n];
    fill_n(visited, n, false);
    DFS_by_Recursive(0); // start at first vertex
    delete [] visited;
}

void LinkedGraph::DFS_by_Recursive(const int v){
    // output(v);
    visited[v] = true;

    // loop each vertex adjacent to v
    Chain<int> vList = adjLists[v];
    // vList.Print();
    ChainNode<int>* currentVertex = vList.GetFirstNode();
    // for (int i = 0; i < vList.Size(); i++){
    while (currentVertex){
        int w = currentVertex->link->data;      // move to next adjacent vertex w
        if (!visited[w]) DFS_by_Recursive(w);   // if w not visited, then do DFS started with w again
    }
}


int main () {
    LinkedGraph linkgraph(10);

    // Insert vertex
    linkgraph.InsertVertex(1);
    linkgraph.InsertVertex(2);
    linkgraph.InsertVertex(3);
    linkgraph.InsertVertex(4);
    linkgraph.InsertVertex(5);
    linkgraph.InsertVertex(6);

    // degree example
    int degree;
    degree = linkgraph.Degree(6);
    cout << "vertex degree: " << degree << endl;
    degree = linkgraph.Degree(1);
    cout << "vertex degree: " << degree << endl;

    return 0;
}