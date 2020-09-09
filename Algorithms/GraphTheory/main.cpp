#include <iostream>
#include <vector>
#include <list>
#include <queue>
#define bug cout<<"\nHello "
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


class BFSTraverser{
    UndirectedAdjacencyList *adjacencyList;
    vector<bool> *visited;
    int count;
    queue<int> queue;
public:
    BFSTraverser(UndirectedAdjacencyList adjacencyList){
        this->adjacencyList = &adjacencyList;
        visited = new vector<bool>(adjacencyList.size);
        count = 0;
    }


public:
    int runBFS(int visitAtNode){
        visited->at(visitAtNode) = true;
        count++;
        queue.push(visitAtNode);
        int currentNode;
        while (!queue.empty()) {
            currentNode = queue.front();
            queue.pop();
            list<Edge> *edges = adjacencyList->graph->at(currentNode);
            //  bug << 4;

            if(edges== nullptr)
                continue;

            auto it = edges->begin();


            // bug << 5;

            while (it != edges->end()) {
                if (!(visited->at(it->to))) {
                    //  bug << 0;
                    queue.push(it->to);
                    //  bug << 1;
                    //  bug << "to " << it->to;
                    count++;
                    //  bug << "2";
                    visited->at(it->to) = true;
                }

                it++;
            }
        }

        return count;
    }






};



int main(){
    UndirectedAdjacencyList *undirectedAdjacencyList = new UndirectedAdjacencyList(5);
    undirectedAdjacencyList->addNode(*new Edge(0, 1, 4));
    undirectedAdjacencyList->addNode(*new Edge(0, 2, 5));
    undirectedAdjacencyList->addNode(*new Edge(1, 2, -2));
    undirectedAdjacencyList->addNode(*new Edge(1, 3, 6));
    undirectedAdjacencyList->addNode(*new Edge(2, 3, 1));
    undirectedAdjacencyList->addNode(*new Edge(2, 2, 10));


    BFSTraverser *pBfsTraverser = new BFSTraverser(*undirectedAdjacencyList);
    int count = pBfsTraverser->runBFS(4);
    cout <<count;



}

