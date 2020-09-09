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


class AdjacencyList{
public:
    int size;
    vector < list<Edge>* > *graph;

    AdjacencyList(int size){
        this->size = size;
        graph = new vector<list<Edge>* >(size);
    }
    void addEdge( Edge edge){
        //list<Edge> *listAtTheNode = graph->at(edge.from);

        if(graph->at(edge.from)== nullptr){

            graph->at(edge.from)= new list<Edge>();
        }
        graph->at(edge.from)->push_back(edge);
    }
};



class DijkstraSearcher{
    AdjacencyList *adjacencyList;
    vector<bool> *visited;
    vector<int> *distance;



    int count = 0;
    priority_queue<pair<int,int>> priorityQueue;

    void pq_push(int node, int weight){
        priorityQueue.push(make_pair(-weight,-node));
    }

    void pq_poll(){
        index = -priorityQueue.top().second;
        minimumWeight = -priorityQueue.top().first;
        priorityQueue.pop();
    }

    int index, minimumWeight;
public:
    explicit DijkstraSearcher(AdjacencyList adjacencyList){
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

            visited->at(index) = true;
            if(distance->at(index)<minimumWeight) continue;

            cout <<"\nret "<<index;
            list<Edge> *edges = adjacencyList->graph->at(index);
            if(edges== nullptr) {
                return distance;}
            for(auto edge = edges->begin(); edge!=edges->end();edge++){


                //  if(visited->at(edge->to)){bug<<"before continue"; continue;}
                // bug<<5;

                int newDistance = distance->at(index)+edge->cost;
                //    bug;
                if(newDistance<distance->at(edge->to)){
                    distance->at(edge->to) = newDistance;
                    pq_push(edge->to,newDistance);
                }
            }

        }

        return distance;
    }






};



int main(){


    // Create a fully connected graph
    //           (0)
    //           / \
    //        5 /   \ 4
    //         /     \
    // 10     <   1   >
    //   +->(2)<------(1)      (4)
    //   +--- \       /
    //         \     /
    //        1 \   / 6
    //           > <
    //           (3)


    AdjacencyList *adjacencyList = new AdjacencyList(5);
    adjacencyList->addEdge(*new Edge(0, 1, 4));
    adjacencyList->addEdge(*new Edge(0, 2, 5));
    adjacencyList->addEdge(*new Edge(1, 2, 1));
    adjacencyList->addEdge(*new Edge(1, 3, 6));
    adjacencyList->addEdge(*new Edge(2, 3, 1));
    adjacencyList->addEdge(*new Edge(2, 2, 10));


    DijkstraSearcher *pDijkstraSearcher = new DijkstraSearcher(*adjacencyList);

    vector <int> *distance = pDijkstraSearcher->runSearch(0);
    auto  it = distance->begin();
    int i = 0;
    while (it!=distance->end()){
        bug<<"Answer"<< it[i];
        it++;
    }



}

