// Ref: http://alrightchiu.github.io/SecondRound/graph-introjian-jie.html#course
#include <iostream>
#include <algorithm>
// #include "Chain.h"   // this line can't work https://www.youtube.com/watch?v=0u9_u1d-y-4&ab_channel=ProgrammingWithHT
#include "Chain.cpp"    // this line can work
#include <stack>
#include <queue>
using namespace std;

class Graph
{// object: A nonempty set of vertices and a set of undirected edges. 
public:
    virtual ~Graph() {} // virtual destructor
    bool IsEmpty() const{return n == 0;}; // return true iff graph has no vertices

    int NumberOfVertices() const{return n;}; // return the # of vertices
    int NumberOfEdges() const{return e;}; // return the # of edges
    virtual int Degree(int u) const = 0; // return the degree of a vertex
    virtual bool ExistsEdge(int u, int v) const = 0; // check the existence of edge 

    virtual void InsertVertex(int v) = 0; // insert a vertex v
    virtual void InsertEdge(int u, int v) = 0; // insert an edge (u, v)
    // virtual void DeleteVertex(int v) = 0; // delete a vertex v
    // virtual void DeleteEdge(int u, int v) = 0; // delete an edge (u, v)
    
    // More graph operations…
    virtual void DFS(const int) = 0;
    virtual void DFS_by_Recursive() = 0;
    virtual void DFS_by_Recursive(const int) {};
    virtual void BFS(const int) = 0;
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
    void DFS(const int);
    void DFS_by_Recursive();
    void DFS_by_Recursive(const int);
    void BFS(const int);

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

    // check if u/v exist in each adjList, if not, add it
    for (int i=0; i<uDegree; i++){      // O(n)
        u_adjNode = u_adjNode->link;
        if (u_adjNode && v == u_adjNode->data) {
            printf("Edge (%d,%d) exists\n", u, v);
            return true;
        }
    }
    printf("Edge (%d,%d) not exists\n", u, v);
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
    
    if (ExistsEdge(u,v)) {
        printf("Edge (%d,%d) already exists\n", u, v);
        return;
    }
    else{
        // add u/ v into each adjList 
        adjLists[u].InsertBack(v);
        adjLists[v].InsertBack(u);
    }
}

// void LinkedGraph::DeleteVertex(int v) // delete a vertex v
// {

// }

// void LinkedGraph::DeleteEdge(int u, int v) // delete an edge (u, v)
// {

// }

void LinkedGraph::DFS(const int v){
    visited = new bool[n];
    fill_n(visited, n , false);

    stack<int> s;
    s.push(v);
    while(!s.empty()){
        int v = s.top();
        s.pop();
        if (!visited[v]){
            visited[v] = true;
            cout << v << " ";

            // search each adjacent vertex
            // if not visited, push into stack
            Chain<int> v_adjList = adjLists[v];
            ChainNode<int>* currentNode = v_adjList.GetFirstNode();
            for (int i=0; i<adjLists[v].Size(); i++){
                int w = currentNode->data;
                if (!visited[w]) s.push(w);
                currentNode = currentNode->link;
            }
            // or
            // while (currentNode->link){
            //     currentNode = currentNode->link;
            //     int w = currentNode->data;
            //     if (!visited[w]) s.push(w);
            // }
        }        
    }
    delete [] visited;
}

void LinkedGraph::DFS_by_Recursive(){
    visited = new bool[n];
    fill_n(visited, n, false);
    DFS_by_Recursive(0); // start at first vertex
    delete [] visited;
}


void LinkedGraph::DFS_by_Recursive(const int v){
    // output(v);
    cout << v << " ";
    visited[v] = true;

    // loop each vertex adjacent to v
    Chain<int> v_adjList = adjLists[v];
    ChainNode<int>* currentVertex = v_adjList.GetFirstNode();
    while (currentVertex->link){
        currentVertex = currentVertex->link;
        int w = currentVertex->data;            // move to next adjacent vertex w
        if (!visited[w]) DFS_by_Recursive(w);   // if w not visited, then do DFS started with w again
    }
}

void LinkedGraph::BFS(const int v){
    visited = new bool[n];
    fill_n(visited, n, false);

    queue<int> q;
    q.push(v);
    while(!q.empty()){
        int v = q.front(); q.pop();
        if (!visited[v]){
            visited[v] = true;
            cout << v << " ";

            Chain<int> v_adjList = adjLists[v];
            ChainNode<int>* currentNode = v_adjList.GetFirstNode();
            while(currentNode->link){
                currentNode = currentNode->link;
                int w = currentNode->data;
                if (!visited[w]) q.push(w);
            }
        }
    }
}


int main () {
    LinkedGraph linkgraph(10);

    // Insert vertex
    linkgraph.InsertVertex(0);
    linkgraph.InsertVertex(1);
    linkgraph.InsertVertex(2);
    linkgraph.InsertVertex(3);
    linkgraph.InsertVertex(4);
    linkgraph.InsertVertex(5);
    linkgraph.InsertVertex(6);
    linkgraph.InsertVertex(7);

    // Insert Edge
    linkgraph.InsertEdge(0,1);
    linkgraph.InsertEdge(0,2);
    linkgraph.InsertEdge(1,3);
    linkgraph.InsertEdge(1,4);
    linkgraph.InsertEdge(2,5);
    linkgraph.InsertEdge(2,6);
    linkgraph.InsertEdge(3,7);
    linkgraph.InsertEdge(4,7);
    linkgraph.InsertEdge(5,7);
    linkgraph.InsertEdge(6,7);

    linkgraph.ExistsEdge(6,7);

    // degree example
    int degree;
    degree = linkgraph.Degree(6);
    cout << "vertex degree: " << degree << endl;
    degree = linkgraph.Degree(1);
    cout << "vertex degree: " << degree << endl;

    // DFS
    cout << "DFS: ";
    linkgraph.DFS_by_Recursive();
    cout << endl;
    // linkgraph.DFS(1);

    // BFS
    cout << "BFS: ";
    linkgraph.BFS(0);
    cout << endl;

    return 0;
}