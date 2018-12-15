#include<bits/stdc++.h>
#include <iostream>
using namespace std;
class Node;

class Node
{
    public:
 int NodeNo;
 string name;
 //string colour;

	Node()
	{

	}
	Node(int x,string y)
	{
		this->NodeNo=x;
		this->name=y;

	}
 };

 class Graph
 {
 int V;
 vector<pair<Node,int>>*adj;
 public:
 Graph()
 {
 }
 Graph(int V)
 {
 this->V=V;
 adj=new vector<pair<Node,int>>[V];
 }
 void addEdge(Node src,Node dest,int weight)
 {
 adj[src.NodeNo].push_back(make_pair(dest,weight));
 adj[dest.NodeNo].push_back(make_pair(src,weight));
 }
 void DijkstraShortestPath(Node src,Node dest);
 void PrintPath(Node *parent,int size1);
 double GiveDiscount(double fare);
 }
 ;
 class Point
{
   int x;
   Node *n1;
public:
   Point(int _x, Node *_y)
   {
      x = _x;
      n1=_y;
   }
   int getX() const { return x; }
   Node* getn1() const { return n1; }
};


class myComparator
{
public:
    int operator() (const Point *p1, const Point *p2)
    {
        return p1->getX() > p2->getX();
    }
};

void Graph::DijkstraShortestPath(Node src,Node dest)
 {
 priority_queue <Point*, vector<Point*>, myComparator > pq;

vector<int>dist(V,INT_MAX);
Point *p1=new Point(0,&src);
pq.push(p1);
dist[src.NodeNo]=0;
while(!pq.empty())
{
    Point *temp=pq.top();
 Node *u=temp->getn1();
 pq.pop();
 for(auto i=adj[u->NodeNo].begin();i!=adj[u->NodeNo].end();i++)
 {
 	int x=(*i).first.NodeNo;
 	int weigh=(*i).second;
 	if(dist[x]>dist[(*u).NodeNo]+weigh)
 	{
 		dist[x]=dist[(*u).NodeNo]+weigh;
 		Point *p2=new Point(dist[x],&((*i).first));
 		pq.push(p2);
 	}
 }
}
   cout<<"Vertex   Distance from Source\n";
    for (int i = 0; i < V; ++i)
        printf("%d \t\t %d\n", i, dist[i]);

}
void Graph::PrintPath(Node *parent,int size1)
{
int i=0;
for(i=size1-1;i>=0;i--)
{
cout<<parent[i].name<<"->";
}
cout<<endl;
}
double Graph::GiveDiscount(double fare)
{
return 0.9*fare;
}
int main()
{
int V=9;
Graph g(V);
g.addEdge(Node(0,"A"),Node(1,"B"),4);
g.addEdge(Node(0,"B"), Node(7,"H"), 8);
g.addEdge(Node(1,"B"), Node(2,"C"), 8);
g.addEdge(Node(1,"B"),Node(7,"H"), 11);
g.addEdge(Node(2,"C"),Node(3,"D"), 7);
g.addEdge(Node(2,"C"), Node(8,"I"), 2);
g.addEdge(Node(2,"C"),Node (5,"F"), 4);
g.addEdge(Node(3,"D"),Node(4,"E"), 9);
g.addEdge(Node(3,"D"),Node( 5,"F"), 14);
g.addEdge(Node(4,"E"), Node(5,"F"),10);
g.addEdge(Node(5,"F"),Node (6,"G"), 2);
g.addEdge(Node(6,"G"), Node(7,"H"), 1);
g.addEdge(Node(6,"G"),Node( 8,"I"), 6);
g.addEdge(Node(7,"H"), Node(8,"I"), 7);
g.DijkstraShortestPath(Node(0,"A"),Node(4,"E"));
	return 0;
}
