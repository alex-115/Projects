#include <iostream>
#include <numeric>
#include <vector>
#include <limits.h>
using namespace std;
//SECTION_A_END: Section A ends here. 
/***********************************************
*************SECTION-A-HEADERS-END**************
************************************************/

/***********************************************
*************SECTION-B-CLASSES******************
************************************************/
class Node{
        public:
                int id; // id of the city
		        int dist; // total distance accumulated
		        int remaining_charge; // remaining charge of the car
                bool charging_station; // if the city has a charging station or not
		        bool visited; // if the city has already been visited
                int version; // version number of the node being pushed onto the pqueue for dijkstras algorithm
                vector<int> path; // path taken to get to node (city)
		        vector<int> neighbors; // neighboring nodes (cities)
		        vector<int> weights; // weights of the neighboring nodes
		        // Default constructor
		        Node()
                {
                        id = 0;
	                    dist = INT_MAX;
	                    remaining_charge = 0;
                        charging_station = false;
	                    visited = false;
                        version = 0;
                        path = {};
	                    neighbors = {};
	                    weights = {};
                }
		        // Parameterized constructor
		        Node(int v, int s)
                {
                        id = v;
	                    dist = INT_MAX;
	                    remaining_charge = 0;
                        charging_station = s;
	                    visited = false;
                        version = 0;
                        path = {};
	                    neighbors = {};
	                    weights = {};
                }
};
class Edge{
        public:
                // Default constructor
		        Edge()
                {
                        city1 = 0;
	                    city2 = 0;
	                    weight = 0;
                }
		        // Parameterized constructor
		        Edge(int u, int v, int w)
                {
                        city1 = u;
	                    city2 = v;
	                    weight = w;
                }
                int city1; // node a 
		        int city2; // node b
		        int weight; // weight between node a and b
};
class Pqueue {
        public:
                // Default constructor
                Pqueue()
                {
                        min_heap.resize(0); // set the min heap to be size of 0
                }
                // function to determine if the min heap is empty
                bool empty() 
                {
                        return min_heap.size() == 0; // if min heap size is 0 then it's empty
                }
                // function to return the size of the min heap
                int size()
                {
                        return min_heap.size(); // returns the size of the min heap
                }
                // function to push the node onto the queue
                void push(Node* p)
                {
                        min_heap.push_back(p); // add the node onto the min heap
                        uwHeapify(min_heap.size() - 1); // heapify the node upwards
                }
                // function to remove the node with the highest priority
                Node* pop()
                {
                        Node* temp = nullptr;
                        if (!empty()) // if the min heap assign temp node to highest priority node and remove it 
                        {
                                temp = min_heap[0];
                                min_heap[0] = min_heap[min_heap.size() - 1];
                                dwHeapify(0);
                                min_heap.pop_back();
                        }
                        return temp;
                }
        private:
                vector<Node*> min_heap; // min heap vector of nodes
                //function to compare two nodes and determine which node has a smaller distance and version 
                bool compare(Node* a, Node* b)
                {
                        if (a->dist != b->dist)//if the distance of node a and b don't have the same distance then return true for smaller distance
                        {
                                return a->dist < b->dist; // return true if node a has a shorter distance
                        }
                        if (a->id != b->id) // since node has the same distance then if statement to check if nodes are duplicates
                        {
                                return a->id < b->id; // return true if node a has a smaller id
                        }
                        return a->version < b->version; // else return true if node a is the smaller version number
                }
                // function to downward heapify for a min heap
                void dwHeapify(int i)
                {
                        int left = 2 * i + 1; // left child
                        int right = 2 * i + 2; // right child
                        int size = min_heap.size(); // declaration of size for easy readability
                        int smallest = i; // smallest index
                        if (left < size && compare(min_heap[left], min_heap[smallest])) // if left child exists and is smaller 
                        {
                                smallest = left; // smallest index would be left child
                        }
                        if (right < size && compare(min_heap[right], min_heap[smallest])) // if right child exists and is smaller
                        {
                                smallest = right; // smallest index would be right child
                        }
                        if (smallest != i) // if the smallest isn't current index then swap
                        {
                                swap(min_heap[i], min_heap[smallest]); // swap function
                                dwHeapify(smallest); // downward heapify node
                        }
                }
                // function to upward heapify function for a min heap
                void uwHeapify(int i)
                {
                        if (i <= 0) return; // If we're at the root, no need to heapify upward
                        int pa = (i - 1) / 2; // parent index
                        if (compare(min_heap[i], min_heap[pa])) // compare parent node with current node to determine if it is smaller
                        {
                                swap(min_heap[i], min_heap[pa]); // function to swap the nodes
                                uwHeapify(pa); // upward heapify node
                        }

                }
};
class Graph {
        public:
                vector<Node*> nodes; // vector of nodes for the graph
                vector<Edge*> edges; // vector of edges for the graph
                // Default constructor
                Graph()
                {
                        nodes = {};
                        edges = {};
                        allPaths = {};
                        max_charge = 0;
                        initial_charge = 0;
                }
                // function to print vector p, which would be a path being passed in
                void printPath(vector<int> p)
                {
                        if (!p.empty()) // if the path is not empty then print the contents of the vector
                        {
                                cout << p.back() << ": " << p[0] << " "; // print the total distance and the starting node
		                        for(int i = 1; i < p.size()-2; i++) // iterate through the path printing between the first index and last index
                                {
                                        if(nodes[p[i]]->charging_station) // if node has a charging station then print it
                                        {
                                                cout << p[i] << " ";
			                            }
		                        }
		                        cout << p[p.size()-2] << " " << endl; // print the ending node
	                    }
                }
                // function to perform revised dijkstras algorithm
                void dijkstras_algorithm(int c, int i, int start, int end)
                {
                        max_charge = c; // initialize max charge to be the max charge passed in
                        initial_charge = i; // intialize intitial charge to be initial charged passed in
                        int min_distance = INT_MAX; // min distance would be infinity
                        nodes[start]->dist = 0; // intialize distance for start node
                        nodes[start]->remaining_charge = initial_charge; // initialize remaining charge for start node
                        Node* q = new Node(*nodes[start]); // create a new temporary node of start node
                        q->path.resize(1, start); // add the id of the starting node to the path
                        PQ.push(q); // push the node onto the priority queue
                        while (!PQ.empty()) // loop while the priority queue is not empty
                        {
                                vector<int> p = {}; // temporary node of path history
                                Node* current = PQ.pop(); // current node to equal the node in front of the priority queue
                                if (current->dist > min_distance) // if current current distance is greater than min distance then break out of loop
                                {
                                        break;
                                }
                                if (current->id == end)// if current node reaches the target node then add path history to the lists of all paths 
                                {
                                        p = current->path; // path history would equal current node path history
                                        p.resize(p.size() + 1, current->dist); // resize vector then add the current node distance to it 
                                        allPaths.push_back(p); // add the current path history to all possible paths 
                                        min_distance = current->dist; // smallest distance would equal current node distance
                                        continue; // continue to the next loop to calculate an alternate path history
                                }           
                                for (int i = 0; i < current->neighbors.size(); i++) // for loop for each neighbor in the adjacency list
                                {
                                        int id = current->neighbors[i];// declaration of current neighbors id for reduced redundancy
                                        int d = current->dist + current->weights[i]; // declaration for reduced redundancy 
                                        int c = current->remaining_charge - current->weights[i]; // declaration for reduced redundancy
                                        if (c >= 0 && node_check(id, d, c)) // if new remaining charge is greater than 0 and current node should be added to priority queue
                                        {
                                                Node* q = new Node(*nodes[id]); // creation of temp node q to be equal current neighbor node
                                                p = current->path; // path history would be equal to current path history
                                                p.resize(p.size() + 1, id); // resize the vector to add id of current node to path
                                                q->path = p; // temp node q will now equal new path history
                                                q->remaining_charge = c; // intialize charge 
                                                q->dist = d; // intialize distance
                                                PQ.push(q); // add the node onto the priority queue
                                        }
                                }           
                        }
                }
                // function to determine the weight of an edge between two nodes(v and u)
                int weightBetween(int v, int u)
                {
                        for (int i = 0; i < edges.size(); i++) // iterate through edges stored
                        {
                if ((edges[i]->city1 == v && edges[i]->city2 == u) || (edges[i]->city1 == u && edges[i]->city2 == v)) // if statement to check if weight is between two nodes
                {
                        return edges[i]->weight; // if so then return weight of edge between node v and u
                }
                        }
                        return -1; // else weight is not found
                }
                // function to determine which path has the minimum efficient path from all path solutions found
                vector<int> findMinPath()
                {
                        int min = 0; // intialize min to be equal to 0
                        vector<int> min_path; // temporary min path will be stored
                        if (allPaths.empty()) // if there is no solutions then return vector since it's empty
                        {
                                return min_path; // return empty vector
                        }
                        int min_sum = accumulate(allPaths[min].begin(), allPaths[min].end() - 1, 0); // compute the sum of the first path used an accumulate function
                        for (int i = 1; i < allPaths.size(); i++) // for loop to iterate through all path solutions
                        {
                                int current_sum = accumulate(allPaths[i].begin(), allPaths[i].end() - 1, 0); // calculate sum of current path solution
                                if (allPaths[min].back() > allPaths[i].back() || (allPaths[min].back() == allPaths[i].back() && i < min) || (allPaths[min].back() == allPaths[i].back() && i < min && current_sum < min_sum)) // if statement to compare the last element firs then consider the sum and index comparisons
                                {
                                min = i;
                                min_sum = current_sum; // Update the min_sum to be the new selected path
                                }
                        }
                        min_path = allPaths[min]; // assign the min path vector be the min path of all path solutions 
                        return min_path;
                }
        private:
                Pqueue PQ; // priority queue for graph
                vector<vector<int>> allPaths; // vector of all path solutions
                int max_charge, initial_charge; // intializations of variables
                // function to determine if node v can be added onto priority queue 
                bool node_check(int v, int d, int &c)
                {
                        if (nodes[v]->charging_station) // if node has a charging station the refill charge
                        {
                                c = max_charge;
                        }
                        // Check if the node's distance is greater than d or remaining charge is less than c 
                        if (nodes[v]->dist > d || nodes[v]->remaining_charge < c) // if statement to check if node's distance is bigger than d or the remaining charge is less than c
                        {
                                if (nodes[v]->visited) // increment version if the node has already been visited since it's a duplicate
                                {
                                        nodes[v]->version++;
                                }
                                // Update remaining charge and distance  
                                nodes[v]->remaining_charge = max(nodes[v]->remaining_charge, c); 
                                nodes[v]->dist = min(nodes[v]->dist, d); 
                                nodes[v]->visited = true; 
                                return true; // returns true so if the node can be added onto the priority queue
                        }
                        return false;
                      
                }
};
// function to determine if the path is the shortest efficient path
bool verifyPath(Graph G, vector<int> path, int i, int c)
{
        int charge = i;
	    int weight = 0;
        for(int j = 0; j+1 < path.size()-1; j++) // iterate through each node 
        {
                if((weight = G.weightBetween(path[j], path[j+1])) > 0) // if statement to check if there is an edge between two nodes in path
                {
                        charge -= weight; // subtract the charge based on weight
                        if(charge < 0) // if charge is less than 0 then it can't travel to city so return false
                        {
                                return false;
			            }
			            else if(G.nodes[path[j+1]]->charging_station) // checks if node has a charging station to charge the fuel for car
                        {
                                charge = c;
			            }           
		        }
	    }
	    return true; // returns true that the path works
}
//SECTION_B_END: Section B ends here. 
/***********************************************
*************SECTION-B-CLASSES-END**************
************************************************/


/***********************************************
*************SECTION-C-MAIN-FUNCTION************
************************************************/
int main()
{
        // four space seperated integers for the first line
        int n; // number of nodes in graph
        int m; // number of edges in graph
        int c; // max distance in miles the vehicle can travel on a full charge
        int initial_charge; // the range of the vehicle with its intial charge
        // pair of integers for the second line indicating the start and end nodes for the trip
        int start, end; 
        // pair of integers for the following n lines, v and s representing nodes.
        int v; // the name of a node that will be an int between 0 and n - 1
        int s; // is 1 if the node v has a charging station and 0 otherwise
        // the following m lines of three space seperated ints, u v d representing edges.
        int u; // starting edge point
        int V; // ending edge point
        int d; // distance in miles between them
        // creation of graph
        cin >> n >> m >> c >> initial_charge; // first line of intergers
        Graph graph; // modify the constructor to account for this
        cin >> start >> end; // second line of a pair of integers
         v, s = 0;
         vector<int> path = {};
        for (int i = 0; i < n; i++) // for loop to input nodes based on n requirement
        {
                cin >> v >> s; 
                Node* node = new Node(v, s); // create a new node with id and charging station indicator
                graph.nodes.push_back(node); // add the nodes to the graph
        }
        u = 0;
        int z, w = 0;
        for (int i = 0; i < m; i++) // input edges based on m requirement
        {
                cin >> u >> z >> w;
                Edge* edge = new Edge(u, z, w); // create a new edge 
                graph.edges.push_back(edge); // add the edge to the graph
                graph.nodes[u]->neighbors.push_back(z); // add node z to be a neighbor of node u
                graph.nodes[z]->neighbors.push_back(u); // add node u to be a neighbor of node z
                graph.nodes[u]->weights.push_back(w); // add the weight of edge to nodes u and z
                graph.nodes[z]->weights.push_back(w); // add the weight of edge to nodes z and u
        }
        graph.dijkstras_algorithm(c,initial_charge,start,end); // perform dijkstras algorithm on graph
        if((path = graph.findMinPath()).size() > 0) // if the path return is the shortest path then print the path
        {
                cout << "Verify Path: " << verifyPath(graph, path, initial_charge, c) << endl;
		        graph.printPath(path);
	    }
	    else // else there was no path found 
        {
		        cout << "No suitable path from " << start << " to " << end << " exists" << endl;
	    }
        return 0;
} 




//SECTION_C_END: Section C ends here. 
/***********************************************
************SECTION-C-MAIN-FUNCTION-END*********
************************************************/
