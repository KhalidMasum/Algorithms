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


class DijkstraSearcher{
    UndirectedAdjacencyList *adjacencyList;
    vector<bool> *visited;
    vector<int> *distance;



    int count = 0;
    priority_queue<pair<int,int>> priorityQueue;

    void pq_push(int node, int weight){
        priorityQueue.push(make_pair(weight,node));
    }

    void pq_poll(){
        index = priorityQueue.top().second;
        minimumWeight = priorityQueue.top().first;
        priorityQueue.pop();
    }

    int index, minimumWeight;
public:
    explicit DijkstraSearcher(UndirectedAdjacencyList adjacencyList){
        this->adjacencyList = &adjacencyList;
        visited = new vector<bool>(adjacencyList.size);
        distance = new vector<int>(adjacencyList.size,INT_MAX);
    }


public:

    vector<int> * runSearch(int start){
        distance->at(start)=0;
        pq_push(start,0);
        while (!priorityQueue.empty()){
            pq_poll();
            if(visited->at(index)){
                list<Edge> *edges = adjacencyList->graph->at(index);
                auto edge = edges->begin();
                while(edge!=edges->end()){
                    if(visited->at(edge->to)) continue;
                    int newDistance = distance->at(index)+edge->cost;
                    if(newDistance<distance->at(edge->to)){
                        distance->at(edge->to) = newDistance;
                        pq_push(edge->to,newDistance);
                    }

                }
            }

        }

        return distance;



        return 0;
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


    DijkstraSearcher *pDijkstraSearcher = new DijkstraSearcher(*undirectedAdjacencyList);

    //cout <<pDijkstraSearcher->distance->at(10)<<pDijkstraSearcher->distance->at(40);



}

