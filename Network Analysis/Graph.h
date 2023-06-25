#pragma once
#include<iostream>
#include<iomanip>
#include"Stack.h"
using namespace std;

class Node  //if weight needs to be included then add it it node class
{
	int ID;
	Node* next;
public:
	Node()
	{
		ID = 0;
		next = NULL;
	}
	Node(int id)
	{
		ID = id;
		next = NULL;
	}
	void set_ID(int id)
	{
		ID = id;
	}
	void set_next(Node* ptr)
	{
		next = ptr;
	}
	int get_ID() const
	{
		return ID;
	}
	Node* get_next() const
	{
		return next;
	}
};

class AdjacencyList
{
	Node* head;
	Node* tail;
	int index;
	int out_degree;  //also includes the head/source/from  node
	int in_degree;

public:
	AdjacencyList()
	{
		head = NULL;
		tail = NULL;
		index = 0;
		out_degree = 0;
		in_degree = 0;
	}
	void set_index(int i)
	{
		index = i;
	}
	Node* get_head() const
	{
		return head;
	}
	Node* get_tail() const
	{
		return tail;
	}
	int get_index() const
	{
		return index;
	}
	int get_out_degree() const
	{
		return out_degree;
	}
	void set_in_degree(int in_deg)
	{
		in_degree = in_deg;
	}
	int get_in_degree()
	{
		return in_degree;
	}
	void add_node(int node_id)  //insert at head
	{
		if (head == NULL)
		{
			head = new Node(node_id);
			tail = head;
			//out_degree++;  //comment this if don't want the source/from node to be included in size
		}
		else
		{
			Node* new_node = new Node(node_id);
			tail->set_next(new_node);
			tail = tail->get_next();
			//new_node->set_next(head);
			//head = new_node;
			out_degree++;
		}
	}
	void delete_list() //starting deleting at head
	{
		Node* temp = this->head;
		while (temp != NULL)
		{
			temp = temp->get_next();
			delete head;
			head = temp;
		}
		tail = NULL;
	}
};

class Graph
{
	AdjacencyList* head_of_list;
	int total_nodes;
	int total_edges;
	int diameter = 0;

	void articulation_nodes(AdjacencyList* list, int parent[], bool visited[], int low_time[], 
		int discovery_time[], int& time, int index_u, int AP[])
	{
		visited[index_u] = true;
		int children = 0;
		time++;
		low_time[index_u] = time;
		discovery_time[index_u] = time;

		Node* temp = list[index_u].get_head()->get_next(); //exclude head because head is u
		while (temp != NULL)
		{
			int index_adj_to_u = search_by_ID(temp->get_ID());
			if (visited[index_adj_to_u] == false)
			{
				children++;
				parent[index_adj_to_u] = index_u;
				articulation_nodes(list, parent, visited, low_time, discovery_time, time, index_adj_to_u, AP);

				//when we start back tracking
				low_time[index_u] = min(low_time[index_u], low_time[index_adj_to_u]); 
				
				if (parent[index_u] == -1 && children > 1) //if it is root and has two child-only root will have NULL parent
				{
					AP[index_u] = true;
				}
				else if (parent[index_u] != -1 && low_time[index_adj_to_u] > discovery_time[index_u])
				{
					AP[index_u] = true;
				}
			}
			//if it is not the parent yet connected then surely it is back edge
			else if (index_adj_to_u != parent[index_u])  //if a back edge is present
			{
				low_time[index_u] = min(low_time[index_u], discovery_time[index_adj_to_u]);
			}
			temp = temp->get_next();
		}
	}

	void bridge_edges(int parent[], bool visited[], int low_time[], int discovery_time[],int& time, int index_u, int& count)
	{
		visited[index_u] = true;
	
		time++;
		low_time[index_u] = time;
		discovery_time[index_u] = time;

		Node* temp = head_of_list[index_u].get_head()->get_next(); //exclude head because head is u
		while (temp != NULL)
		{
			int index_adj_to_u = search_by_ID(temp->get_ID());
	
			if (visited[index_adj_to_u] == false)
			{
				parent[index_adj_to_u] = index_u;
			
				bridge_edges(parent, visited, low_time, discovery_time, time, index_adj_to_u, count);
			
				low_time[index_u] = min(low_time[index_u], low_time[index_adj_to_u]);

				if (low_time[index_adj_to_u] > discovery_time[index_u])
				{
					count++;
				}		
			}
			else if (index_adj_to_u != parent[index_u])
			{
				low_time[index_u] = min(low_time[index_u], discovery_time[index_adj_to_u]);
			}
			temp = temp->get_next();
		}
	}

	int search_by_ID(int ID) 
	{
		for (int i = 0; i < total_nodes; i++)
		{
			if (head_of_list[i].get_head() != NULL && head_of_list[i].get_head()->get_ID() == ID)
			{
				return head_of_list[i].get_index();
			}
		}
		return -1;   //-1 is not a valid index so it means that value is not there in array
	}

	int calculate_in_degree(bool flag = true)
	{
		static int check = 0;   //to calculate in-degree only once

		if (check == 0)
		{
			for (int i = 0; i < total_nodes; i++)
			{
				if (head_of_list[i].get_head() != NULL)
				{
					Node* temp = head_of_list[i].get_head()->get_next(); //exclude head
					while (temp != NULL)
					{
						int ind = search_by_ID(temp->get_ID());
						if (ind != -1)//increment in degree
						{
							head_of_list[ind].set_in_degree(head_of_list[ind].get_in_degree() + 1);
						}
						temp = temp->get_next();
					}
				}
			}
			check++;
		}
		if (flag == true)   //if flag is false it will not return the max in-degree
		{
			int max_in = 0;
			for (int i = 0; i < total_nodes; i++)
			{
				if (head_of_list[i].get_head() != NULL)
				{
					if (head_of_list[i].get_in_degree() > max_in)
					{
						max_in = head_of_list[i].get_in_degree();
					}
				}
			}
			return max_in;
		}
		else
		{
			return 0;
		}
	}

public:

	/*Graph()
	{
		total_nodes = 0;
		total_edges = 0;
		diameter = -1;
		head_of_list = NULL;
	}*/

	Graph(int N, int E)
	{
		total_nodes = N;
		total_edges = E;
		diameter = -1;
		head_of_list = new AdjacencyList[total_nodes];
	}

	int get_nodes() const
	{
		return total_nodes;
	}
	int get_edges() const
	{
		return total_edges;
	}
	int get_diameter() const
	{
		return diameter;
	}

	void add_edge(int source, int destination)  //count represents pair no.
	{
		static int count = 0;
		int ind_src = search_by_ID(source);

		if (ind_src == -1) //means that the source node is not there in the array
		{
			if (head_of_list[count].get_head() == NULL)
			{
				head_of_list[count].set_index(count);
				head_of_list[count].add_node(source);
				head_of_list[count].add_node(destination);
				count++;
			}
		}
		else  //if src is found in array at ind_src
		{
			head_of_list[ind_src].add_node(destination);
		}
		
		int ind_dest = search_by_ID(destination);
		if(ind_dest == -1) 
		{	
			if (head_of_list[count].get_head() == NULL)
			{
				head_of_list[count].set_index(count);
				head_of_list[count].add_node(destination);
				count++;
			}
		}
		//if destination node is already there at index ind_dest then do nothing
	}

	/*void print()
	{
		for (int i = 0; i < total_nodes; i++)
		{
			if (head_of_list[i].get_head() != NULL)
			{
				cout << "Index: " << head_of_list[i].get_index() << endl;
				Node* temp = head_of_list[i].get_head();

				while (temp != NULL)
				{
					if (temp->get_next() != NULL)
					{
						cout << temp->get_ID() << "--->";
					}
					else
					{
						cout << temp->get_ID();
					}
					temp = temp->get_next();
				}
				cout << endl;
				cout << "In-degree: " << head_of_list[i].get_in_degree() << endl;
				cout << "Out-degree: " << head_of_list[i].get_out_degree() << endl;
				cout << "Node " << i << " finished" << endl;
				cout << endl << "---------------------------" << endl;
			}
		}
	}*/

	void print_out_degree_table()
	{
		int out_max = 0;
		for (int i = 0; i < total_nodes; i++)
		{
			if (head_of_list[i].get_head() != NULL)
			{
				if (head_of_list[i].get_out_degree() > out_max)
				{
					out_max = head_of_list[i].get_out_degree();
				}
			}
		}
		int* arr = new int[out_max + 1];
		for (int i = 0; i <= out_max; i++)
		{
			arr[i] = 0;
		}
		for (int i = 0; i < total_nodes; i++)
		{
			arr[head_of_list[i].get_out_degree()] += 1;
		}

		cout << endl << endl;
		cout << "\t\t * OUT-DEGREE DISTRIBUTION TABLE * \t\t" << endl << endl;
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;
		cout << "\t|\t" << "OUT-DEGREE" << setw(7) << setfill(' ') << left << "\t|" << "No.of Nodes" << setw(7) << setfill(' ') << left << "\t|" << endl;
		for (int i = 0; i <= out_max; i++)
		{
			if (arr[i] != 0)
				cout << "\t|\t" << "    " << i << setw(7) << setfill(' ') << left << "\t\t|\t" << arr[i] << setw(7) << setfill(' ') << left << "\t\t|" << endl;
		}
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;

		delete[] arr;
		arr = NULL;
		cout << endl;

	}

	void print_in_degree_table()
	{
		int in_max = this->calculate_in_degree();

		int* arr1 = new int[in_max + 1];  //if any node has max degree so that's why +1

		for (int i = 0; i <= in_max; i++)
		{
			arr1[i] = 0;
		}
		for (int i = 0; i < total_nodes; i++)
		{
			arr1[head_of_list[i].get_in_degree()] += 1;  //no of nodes saves at a particluar index indicates the total nodes of that deg
		}  

		cout << endl << endl;
		cout << "\t\t * IN-DEGREE DISTRIBUTION TABLE * \t\t" << endl << endl;
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;
		cout << "\t|\t" << "IN-DEGREE" << setw(7) << setfill(' ') << left << "\t|" << "No.of Nodes" << setw(7) << setfill(' ') << left << "\t|" << endl;
		for (int i = 0; i <= in_max; i++)
		{
			if(arr1[i] != 0)
			cout << "\t|\t" << "    " << i << setw(7) << setfill(' ') << left << "\t\t|\t" << arr1[i] << setw(7) << setfill(' ') << left << "\t\t|" << endl;
		}
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;

		delete[] arr1;
		arr1 = NULL;
		cout << endl;
	}

	void Recursive_DFS(int v, bool visited[],Stack& stack)
	{
		int ind = search_by_ID(v);
		visited[ind] = true;
		//cout << head_of_list[ind].get_head()->get_ID() << " ";
		
		Node* temp = head_of_list[ind].get_head()->get_next(); //excluding head because v is our head
		while (temp != NULL)
		{
			int i = search_by_ID(temp->get_ID());
			if (!visited[i])
			{
				Recursive_DFS(temp->get_ID(), visited,stack);
			}
			temp = temp->get_next();
		}
		stack.push(ind);  //when we are on a node such that it has no unvisited neighbours then start pushing
	}

	int sink_nodes()  //out-degree =0
	{
		int count = 0;
		for (int i = 0; i < total_nodes; i++)
		{
			if (head_of_list[i].get_head() != NULL)
			{
				if (head_of_list[i].get_out_degree() == 0)
				{
					count++;
				}
			}
		}
		return count;
	}

	int source_nodes()   //in-degree =0
	{
		int count = 0;
		calculate_in_degree(false);
		for (int i = 0; i < total_nodes; i++)
		{
			if (head_of_list[i].get_head() != NULL)
			{
				if (head_of_list[i].get_in_degree() == 0)
				{
					count++;
				}
			}
		}
		return count;
	}

	int isolated_nodes()  //in and out degree both equal to zero
	{
		int count = 0;
		for(int i = 0; i < total_nodes; i++)
		{
			count++;
		}
		return (total_nodes - count);
	}
	
	int find_articulation_nodes()
	{
		int* parent_nodes = new int[total_nodes];
		bool* visited = new bool[total_nodes];
		int* low_time = new int[total_nodes];
		int* discovery_time = new int[total_nodes];
		int* AP = new int[total_nodes];   //articulation points

		for (int i = 0; i < total_nodes; i++)
		{
			parent_nodes[i] = -1;
			visited[i] = false;
			low_time[i] = 0;
			discovery_time[i] = 0;
			AP[i] = -1;
		}
		int start = head_of_list[0].get_head()->get_ID();
		int time = 0, parent = -1;

		for (int i = 0; i < total_nodes; i++)
		{
			if (visited[i]==false)
			{
				articulation_nodes(head_of_list, parent_nodes, visited, low_time,
					discovery_time, time, i, AP);
			}
		}
		
		int count = 0;
		
		for (int i = 0; i < total_nodes; i++)
		{
			if (AP[i] != -1)
			{
				//cout << head_of_list[i].get_head()->get_ID() << endl;
				count++;
			}
		}

		delete[] parent_nodes;
		delete[] visited;
		delete[] low_time;
		delete[] discovery_time;
		delete[] AP;

		return count;
	}

	int find_bridge_edges()
	{
		int* parent_nodes = new int[total_nodes];
		bool* visited = new bool[total_nodes];
		int* low_time = new int[total_nodes];
		int* discovery_time = new int[total_nodes];

		for (int i = 0; i < total_nodes; i++)
		{
			parent_nodes[i] = -1;
			visited[i] = false;
			low_time[i] = 0;
			discovery_time[i] = 0;
		}

		int time = 0;
		int count = 0;

		for (int i = 0; i < total_nodes; i++)
		{
			if (visited[i] == false)
			{
				bridge_edges(parent_nodes, visited, low_time, discovery_time, time, i, count);
			}
		}

		delete[] parent_nodes;
		delete[] visited;
		delete[] low_time;
		delete[] discovery_time;

		return count;
	}

	void dfs(int start, bool visited[], int** ptr ,int& comp_size)
	{
		//cout << start << " ";
		comp_size++;
		visited[start] = true;

		for (int i = 0; i < total_nodes; i++) 
		{
			if (ptr[start][i] != INT_MAX && ptr[start][i] != 0 && (!visited[i]))
			{
				dfs(i, visited, ptr, comp_size);
			}
		}
	}
	
	void path_length_dist(bool flag = true)
	{
		int** ptr = new int* [total_nodes];  //creating adjacency matrix
		for (int i = 0; i < total_nodes; i++)
		{
			ptr[i] = new int[total_nodes];
			for (int j = 0; j < total_nodes; j++)
			{
				if (i == j)  //place zeros on all diagonals
				{
					ptr[i][j] = 0;
				}
				else
				{
					ptr[i][j] = INT_MAX;
				}
			}
		}

		for (int i = 0; i < total_nodes; i++)  
		{
			Node* temp = head_of_list[i].get_head()->get_next();

			while (temp != NULL)
			{
				int ind = search_by_ID(temp->get_ID());
				ptr[i][ind] = 1;
				temp = temp->get_next();
			}
		}

		int max_path_len = 0;
		for (int k = 0; k < total_nodes; k++)   //floyd Warshall algo
		{	
			for (int i = 0; i < total_nodes; i++) 
			{
				for (int j = 0; j < total_nodes; j++) 
				{
					if (ptr[i][j] > (ptr[i][k] + ptr[k][j]) && (ptr[k][j] != INT_MAX && ptr[i][k] != INT_MAX))
					{
						ptr[i][j] = ptr[i][k] + ptr[k][j];
					}
				}
			}
		}

		for (int i = 0; i < total_nodes; i++)
		{
			for (int j = 0; j < total_nodes; j++)
			{
				if (ptr[i][j] > max_path_len && ptr[i][j] != INT_MAX && ptr[i][j] != 0)
				{
					max_path_len = ptr[i][j];
				}
			}
		}

		this->diameter = max_path_len;

		if (flag == false)
		{
			for (int i = 0; i < total_nodes; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;
			return;
		}

		int* arr = new int[max_path_len + 1];
		for (int i = 0; i <= max_path_len; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < total_nodes; i++)
		{
			for (int j = 0; j < total_nodes; j++)
			{
				if (ptr[i][j] != 0 && ptr[i][j] != INT_MAX)
				{
					arr[ptr[i][j]] += 1;
				}
			}
		}

		cout << endl << endl;
		cout << "\t\t* SHORTEST PATH LENGTH DISTRIBUTION TABLE *\t\t" << endl << endl;
		cout << "\t" << setw(57) << setfill('-') << '-' << endl;
		cout << "\t|\t" << "PATH LENGTH" << setw(12) << setfill(' ') << left << "\t|" << "No.of Nodes" << setw(12) << setfill(' ') << left << "\t\t|" << endl;
		for (int i = 0; i <= max_path_len; i++)
		{
			if (i != 0)
				cout << "\t|\t" << "    " << i << setw(12) << setfill(' ') << left << "\t\t|\t" << arr[i] << setw(12) << setfill(' ') << left << "\t\t|" << endl;
		}
		cout << "\t" << setw(57) << setfill('-') << '-' << endl;

		delete[] arr;
		for (int i = 0; i < total_nodes; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}

	int find_WCCs(bool flag = true) //creating a bidirectional graph and traversing depth wise on it
	{
		int** ptr = new int* [total_nodes];
		for (int i = 0; i < total_nodes; i++)
		{
			ptr[i] = new int[total_nodes];
			for (int j = 0; j < total_nodes; j++)
			{
				if (i == j)
				{
					ptr[i][j] = 0;
				}
				else
				{
					ptr[i][j] = INT_MAX;
				}
			}
		}

		for (int i = 0; i < total_nodes; i++)  //bidirectional
		{
			Node* temp = head_of_list[i].get_head()->get_next();

			while (temp != NULL)
			{
				int ind = search_by_ID(temp->get_ID());
				ptr[i][ind] = 1;
				ptr[ind][i] = 1;
				temp = temp->get_next();
			}
		}

		bool* visited = new bool[total_nodes];
		for (int i = 0; i < total_nodes; i++)
		{
			visited[i] = false;
		}

		int max_size = 0;

		int* arr = new int[total_nodes + 1];
		for (int i = 0; i <= total_nodes; i++)
		{
			arr[i] = 0;
		}

		for (int i = 0; i < total_nodes; i++)
		{
			if (visited[i] == false)
			{
				int Size = 0;
				dfs(i, visited, ptr, Size);
				arr[Size] += 1;

				if (Size > max_size)
				{
					max_size = Size;
				}
			}
		}

		if (flag == false)
		{
			delete[] visited;
			delete[] arr;

			for (int i = 0; i < total_nodes; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;

			return max_size;
		}
		
		cout << endl << endl;
		cout << "\t\t * WCCs SIZE DISTRIBUTION TABLE * \t\t" << endl << endl;
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;
		cout << "\t|\t" << "SIZE" << setw(7) << setfill(' ') << left << "\t\t|" << "No.of WCCs" << setw(7) << setfill(' ') << left << "\t\t|" << endl;
		for (int i = 0; i <= total_nodes; i++)
		{
			if (arr[i] != 0)
				cout << "\t|\t" << "  " << i << setw(7) << setfill(' ') << left << "\t\t|\t" << arr[i] << setw(7) << setfill(' ') << left << "\t\t|" << endl;
		}
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;

		delete[] arr;
		delete[] visited;
		for (int i = 0; i < total_nodes; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}
	
	int find_SCCs(bool flag = true)
	{
		Stack stack;

		bool* visited = new bool[total_nodes];
		for (int i = 0; i < total_nodes; i++)
		{
			visited[i] = false;
		}

		for (int i = 0; i < total_nodes; i++)
		{
			if (visited[i] == false)
			{
				Recursive_DFS(head_of_list[i].get_head()->get_ID(), visited, stack);
			}
		}

		//Allocating a 2D array dynamically
		int** ptr = new int* [total_nodes];
		for (int i = 0; i < total_nodes; i++)
		{
			ptr[i] = new int[total_nodes];
			for (int j = 0; j < total_nodes; j++)
			{
				if (i == j)
				{
					ptr[i][j] = 0;
				}
				else
				{
					ptr[i][j] = INT_MAX;
				}
			}
		}

		for (int i = 0; i < total_nodes; i++)  //reverse graph/tranpose
		{
			Node* temp = head_of_list[i].get_head()->get_next();

			while (temp != NULL)
			{
				int ind = search_by_ID(temp->get_ID());
				if(ind!=-1)
				ptr[ind][i] = 1;  //for reverse links
				temp = temp->get_next();
			}
		}

		for (int i = 0; i < total_nodes; i++)
		{
			visited[i] = false;
		}
		
		int* arr = new int[total_nodes + 1];
		for (int i = 0; i <= total_nodes; i++)
		{
			arr[i] = 0;
		}

		int max_size = 0;

		while (!stack.isEmpty())
		{
			int start = stack.pop();

			if (visited[start] == false)
			{
				int Size = 0;  //calculates the size of 1 SCC
				dfs(start, visited, ptr, Size);
				arr[Size] += 1;

				if (Size > max_size)
				{
					max_size = Size;
				}
			}
		}

		if (flag == false)
		{
			delete[] visited;
			delete[] arr;

			for (int i = 0; i < total_nodes; i++)
			{
				delete[] ptr[i];
			}
			delete[] ptr;

			return max_size;
		}

		cout << endl << endl;
		cout << "\t\t * SCCs SIZE DISTRIBUTION TABLE * \t\t" << endl << endl;
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;
		cout << "\t|\t" << "SIZE" << setw(7) << setfill(' ') << left << "\t\t|" << "No.of SCCs" << setw(7) << setfill(' ') << left << "\t\t|" << endl;
		for (int i = 0; i <= total_nodes; i++)
		{
			if (arr[i] != 0)
				cout << "\t|\t" << "  " << i << setw(7) << setfill(' ') << left << "\t\t|\t" << arr[i] << setw(7) << setfill(' ') << left << "\t\t|" << endl;
		}
		cout << "\t" << setw(49) << setfill('-') << '-' << endl;

		delete[] visited;
		delete[] arr;

		for (int i = 0; i < total_nodes; i++)
		{
			delete[] ptr[i];
		}
		delete[] ptr;
	}

	virtual ~Graph()
	{
		delete[] head_of_list;
	}
};