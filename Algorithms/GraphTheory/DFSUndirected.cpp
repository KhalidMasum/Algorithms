#include <iostream>
#include <vector>
#include <list>

using namespace std;
class Edge{
public:
    int from, to, cost;
    Edge(int from, int to, int cost){
        this->from = from;
        this->to=to;
        this->cost = cost;
    }
};

class UndirectedAdjacencyList {
public:
    int size;
    vector < list<Edge>* > *graph;

    UndirectedAdjacencyList(int size){
        this->size = size;
        graph = new vector<list<Edge>* >(size);
    }
    void addNode( Edge edge){
        Edge reverseEdge = *new Edge(edge.to,edge.from,edge.cost);
        addEdgeToGraph(edge);
        addEdgeToGraph(reverseEdge);
    }

    void addEdgeToGraph(const Edge &edge) {
        if(graph->at(edge.from) == nullptr){
            graph->at(edge.from)= new list<Edge>();
        }
        graph->at(edge.from)->push_back(edge);
    }
};


class DFSTraverser{
    UndirectedAdjacencyList *adjacencyList;
    vector<bool> *visited;
    int count;
public:
    DFSTraverser(UndirectedAdjacencyList adjacencyList){
        this->adjacencyList = &adjacencyList;
        visited = new vector<bool>(adjacencyList.size);
        count = 0;
    }


public:
    int runDFS(int visitAtNode){
        if(visited->at(visitAtNode)){
            return 0;
        }
        visitTheNode(visitAtNode);
        visitTheNeighbors(visitAtNode);
        return count;
    }

    void visitTheNeighbors(int visitAtNode) {
        list<Edge> *edges = adjacencyList->graph->at(visitAtNode);
        if(edges!= nullptr){
            auto it = edges->begin();
            while (it!=edges->end()){
                cout<<"next DFS at "<<it->to<<"\n";
                runDFS(it->to);
                it++;
            }
        }
    }

    void visitTheNode(int visitAtNode) {
        visited->at(visitAtNode) = true;
        count++;
    }


};

/*

int main(){
    UndirectedAdjacencyList *adjacencyList = new UndirectedAdjacencyList(5);
    adjacencyList->addNode( *new Edge(0, 1, 4));
    adjacencyList->addNode(*new Edge(0, 2, 5));
    adjacencyList->addNode(*new Edge(1, 2, -2));
    adjacencyList->addNode(*new Edge(1,3,6));
    adjacencyList->addNode(*new Edge(2,3,1));
    adjacencyList->addNode(*new Edge(2,2,10));


    DFSTraverser *dfsTraverser = new DFSTraverser(*adjacencyList);
    int count = dfsTraverser->runDFS(1);
    cout <<count;

}
*/
