#include <iostream>
#include <vector>
#include <list>
#include <iterator>
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

class AdjacencyList{
public:
    int size;
    vector < list<Edge>* > *graph;

    AdjacencyList(int size){
        this->size = size;
        graph = new vector<list<Edge>* >(size);
    }
    void addNode( Edge edge){
        //list<Edge> *listAtTheNode = graph->at(edge.from);

        if(graph->at(edge.from)== nullptr){
            cout<<"New node Added " <<edge.from <<"\n";
            graph->at(edge.from)= new list<Edge>();
        }
        graph->at(edge.from)->push_back(edge);
    }
};


class DFSTraverser{
    AdjacencyList *adjacencyList;
    vector<bool> *visited;
    int count;
public:
    DFSTraverser(AdjacencyList adjacencyList){
        this->adjacencyList = &adjacencyList;
        visited = new vector<bool>(adjacencyList.size);
        count = 0;
    }


public:
    int runDFS(int visitAtNode){
        if(visited->at(visitAtNode)){
            return 0;
        }
        visited->at(visitAtNode) = true;
        count++;

        list<Edge> *edges = adjacencyList->graph->at(visitAtNode);
        if(edges!= nullptr){
            auto it = edges->begin();
            while (it!=edges->end()){
                cout<<"next DFS at "<<it->to<<"\n";
                runDFS(it->to);
                it++;

            }
        }
        return count;

    }


};


/*
int main(){
    AdjacencyList *adjacencyList = new AdjacencyList(5);
    adjacencyList->addNode( *new Edge(0, 1, 4));
    adjacencyList->addNode(*new Edge(0, 2, 5));
    adjacencyList->addNode(*new Edge(1, 2, -2));
    adjacencyList->addNode(*new Edge(1,3,6));
    adjacencyList->addNode(*new Edge(2,3,1));
    adjacencyList->addNode(*new Edge(2,2,10));


    DFSTraverser *dfsTraverser = new DFSTraverser(*adjacencyList);
    int count = dfsTraverser->runDFS(0);
    cout <<count;



}

*/