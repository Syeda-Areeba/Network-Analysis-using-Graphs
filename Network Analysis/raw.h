#pragma once

//	ifstream file("CA-GrQc.txt");
//	int count = -1;
//	int nodes = 0, edges = 0;
//	string s;
//	getline(file, s);
//	//cout << s << endl;
//	getline(file,s);
//	///cout << s << endl;
//	getline(file, s);
//	cout <<"S:" << s << endl;
//	stringstream word(s);
//	string data;
//
//	getline(word, data, ' '); //#
//	getline(word, data, ' ');  //Nodes:
//	getline(word, data, ' ');  //actual no of nodes
//	cout << "DATA: "  << data << endl;
//	nodes = atoi(data.c_str());
//	getline(word, data, ' ');   //Edges:
//	getline(word, data, ' ');   //actual no. of edges
//	cout << "DATA: " << data << endl;
//	edges = atoi(data.c_str());
//	cout << "Nodes: " << nodes << "Edges: " << edges << endl;
//	getline(file, s);
//	Graph *graph = new Graph(nodes,edges);
//	int prev_from_node = 0;
//
//	if (file.is_open())
//	{
//		int from_node = 0;
//		int to_node = 0;
//		while (file >> from_node >> to_node)
//		{
//			//cout << from_node << "---" << to_node << endl;
//			if (prev_from_node == from_node)
//			{
//				graph->add_edge(from_node, to_node, count);
//				//do not increment count if it has same source node
//				
//			}
//			else
//			{
//				count++;  //count becomes 0 for first time and 1 for second time
//				graph->add_edge(from_node, to_node, count);
//				//int hc = hash_codes(from_node, nodes,count);
//				//cout << "ID: " << from_node << " HASH CODE: " << hc << endl;
//			}
//			prev_from_node = from_node;
//			/*if (count == 4)
//			{
//				graph->calculate_in_degree();
//				graph->print();
//				break;
//			}*/
//		}
//	}
//	else
//	{
//		cout << "error" << endl;
//	}
//	file.close();
//	graph->calculate_in_degree();
//	//graph->print();
//	graph->find_articulation_nodes();

//----------------------------------------------------------------------

/*file.open("CA-GrQc.txt");
		getline(file, s);
		getline(file, s);
		getline(file, s);
		getline(file, s);
		count = 0;
		if (file.is_open() && !file.eof())
		{
			int from_node = 0;
			int to_node = 0;
			while (file >> from_node >> to_node)
			{
				graph->check_remaining(to_node);
				count++;
			}
		}
		else
		{
			cout << "error" << endl;
		}
		cout << "count: " << count << endl;*/

		//---------------------------------------------------------------------------------------------
//Graph* g = new Graph(8, 9);
//cout << "\nSCCs in first graph \n";

/*g->add_edge(1, 0, 1);
g->add_edge(0, 2, 0);
g->add_edge(2, 1, 2);
g->add_edge(0, 3, 0);
g->add_edge(3, 4, 3);
g->remain(4, 4);*/

//g->add_edge(0, 1, 0);
//g->add_edge(1, 2, 1);
//g->add_edge(2, 3, 2);
//g->add_edge(3, 0, 3);
//g->add_edge(2, 4, 2);
//g->add_edge(4, 5, 4);
//g->add_edge(5, 6, 5);
//g->add_edge(6, 4, 6);
//g->add_edge(6, 7, 6);
//g->remain(7, 7);
//
//g->find_SCC();

/*g->add_edge(0, 1, 0);
g->add_edge(1, 2, 1);
g->add_edge(2, 0, 2);
g->add_edge(2, 3, 2);
g->add_edge(3, 4, 3);
g->add_edge(4, 5, 4);
g->add_edge(5, 6, 5);
g->add_edge(6, 7, 6);
g->add_edge(6, 4, 6);
g->add_edge(4, 7, 4);
g->remain(7, 7);*/

//g->print_in_degree_table();
//g->print();

//g->directed();


//------
/*bool* visited = new bool[8];
for (int i = 0; i <8; i++)
{
	visited[i] = false;
}
g->DFS(0,visited);
cout << "recusrion" << endl;
for (int i = 0; i < 8; i++)
{
	visited[i] = false;
}
Stack stack;
g->Recursive_DFS(0, visited,stack);
cout << "Stack" << endl;
while (!stack.isEmpty())
{
	cout << stack.pop() << " ";
}*/
//---
//g->d();



/*g->add_edge(0, 1, 0);
g->add_edge(1, 2, 1);
g->add_edge(2, 3, 2);
g->remain(3, 3);*/




//g->print();
//g->find_articulation_nodes();
// 
//g->find_SCCs();

/*g->add_edge(1, 2, 0);
g->add_edge(1, 3, 0);
g->add_edge(1, 5, 0);
g->add_edge(2, 5, 1);
g->add_edge(3, 4, 2);

g->remain(4, 3);
g->remain(5, 4);*/

//-----
/*g->add_edge(1, 2, 0);
g->add_edge(2, 3, 1);
g->add_edge(2, 4, 1);
g->remain(3, 2);
g->add_edge(4, 3, 3);*/


/*g->add_edge(1, 2, 0);
g->add_edge(2, 3, 1);
g->add_edge(3, 1, 2);

g->add_edge(4, 1, 3);
g->add_edge(5, 4, 4);*/

/*g->add_edge(1, 2, 0);
g->add_edge(1, 3, 0);
g->add_edge(1, 4, 0);

g->add_edge(2, 1, 1);
g->add_edge(2, 3, 1);

g->add_edge(3, 1, 2);
g->add_edge(3, 2, 2);
g->add_edge(3, 4, 2);

g->add_edge(4, 1, 3);
g->add_edge(4, 3, 3);*/

//g->remain(3, 3);
//g->remain(4, 4);

//g->calculate_in_degree();
//g->print();
//g->DFS(4);

/*cout << "---------" << endl;
g->find_articulation_nodes();*/

//---------------------------------------------------------------------------------------

/*void find_SCCs()
	{
		int* low_time = new int[total_nodes];
		int* discovery_time = new int[total_nodes];
		bool* is_in_stack = new bool[total_nodes];

		for (int i = 0; i < total_nodes; i++)
		{
			is_in_stack[i] = false;
			low_time[i] = -1;
			discovery_time[i] = -1;
		}
		Stack stack;
		for (int i = 0; i < total_nodes; i++)
		{
			if (discovery_time[search_by_ID(head_of_list[i].get_head()->get_ID())] == -1)
			{
				SCCs(discovery_time, low_time, stack, is_in_stack, head_of_list[i].get_head()->get_ID());
			}
		}
	}*/

//-----------------------------------------------------------------------------------------

//void SCCs(int discovery_time[], int low_time[], Stack stack, bool is_in_stack[], int start)
	//{
	//	static int time = 0;
	//	int index_u = search_by_ID(start);
	//	discovery_time[index_u] = time;
	//	low_time[index_u] = time;
	//	time++;
	//
	//	stack.push(index_u);
	//	is_in_stack[index_u] = true;
	//
	//	Node* temp = head_of_list[index_u].get_head()->get_next();
	//	while (temp != NULL)
	//	{
	//		int index_adj_to_u = search_by_ID(temp->get_ID());
	//		if (discovery_time[index_adj_to_u] == -1)  //if node has not been discovered yet
	//		{
	//			SCCs(discovery_time, low_time, stack, is_in_stack, temp->get_ID());
	//
	//			low_time[index_u] = min(low_time[index_u], low_time[index_adj_to_u]);
	//		}
	//		else if (is_in_stack[index_adj_to_u])
	//		{
	//			low_time[index_u] = min(low_time[index_u], discovery_time[index_adj_to_u]);
	//		}
	//		temp = temp->get_next();
	//	}
	//
	//	if (low_time[index_u] == discovery_time[index_u])
	//	{
	//		cout << "SCC :" << endl;
	//		while (stack.peek() != index_u)
	//		{
	//			int ind = stack.peek();
	//			cout << head_of_list[ind].get_head()->get_ID() << " ";
	//			cout << "Index: " << stack.peek() << endl;
	//			is_in_stack[stack.peek()] = false;
	//			stack.pop();
	//		}
	//
	//		int ind = stack.peek();
	//		cout << head_of_list[ind].get_head()->get_ID() << " ";
	//		cout << "Index: " << stack.peek() << endl;
	//		is_in_stack[stack.peek()] = false;
	//		stack.pop();
	//	}
	//
	//}


//-\-\-\-\-\-\-\-\-
// 
//void DFS(int starting_node, bool visited[])
//{
//	int start_index = search_by_ID(starting_node);
//	Stack stack;
//
//	//if (start_index != -1)
//	stack.push(start_index);
//	visited[start_index] = true;
//
//	while (!stack.isEmpty())
//	{
//		int index = stack.pop();
//		//if (index != -1)
//		cout << head_of_list[index].get_head()->get_ID() << " ";
//
//		Node* temp = head_of_list[index].get_head()->get_next(); //start from 1 node after head
//		while (temp != NULL) //(temp->next !=NULL) ->because last node is head and will not be included
//		{
//			index = search_by_ID(temp->get_ID());
//			if (visited[index] == false)
//			{
//				/*stack.push(index);
//				visited[index] = true;*/
//				DFS(temp->get_ID(), visited);
//			}
//			temp = temp->get_next();
//		}
//	}

//-\-\-\-\-\-\-\-\-

	//int ind = search_by_ID(starting_node);
	//visited[ind] = true;
	//cout << "Visited enter: " << endl;
	//display_array(visited);

	//Node* temp = head_of_list[ind].get_head()->get_next(); //start from 1 node after head
	//if (temp == NULL)
	//{
	//	stack.push(ind);
	//	return;
	//}
	//while (temp->get_next() != NULL) //(temp->next !=NULL) ->because last node is head and will not be included
	//{
	//	
	//	temp = temp->get_next();
	//}
	//int index = search_by_ID(temp->get_ID());
	//if (visited[index] == false)
	//{
	//	DFS(temp->get_ID(), visited, stack);
	//}
	//stack.push(ind);
//}

//--------------------------

//void articulation_nodes(AdjacencyList* list, int parent[], bool visited[], int low_time[], int discovery_time[],
//	int& time, int index_u, int AP[], int& count)
//{
//	//int index_u = search_by_ID(u);
//	//cout << "U when enter: " << u << " index_u: " << index_u << endl;
//	visited[index_u] = true;
//	//cout << "visited " << endl;
//	//display_array(visited);
//	int children = 0;
//	time++;
//	low_time[index_u] = time;
//	//cout << "low_time " << endl;
//	//display_array(low_time);
//	discovery_time[index_u] = time;
//	//cout << "disc_time " << endl;
//	//display_array(discovery_time);
//
//
//	Node* temp = list[index_u].get_head()->get_next(); //exclude head because head is u
//	while (temp != NULL)
//	{
//		int index_adj_to_u = search_by_ID(temp->get_ID());
//		//cout << "index_adj_to_u: " << index_adj_to_u << "  temp ID: " << temp->get_ID() << endl;
//		if (visited[index_adj_to_u] == false)
//		{
//			children++;
//			parent[index_adj_to_u] = index_u;
//			visited[index_adj_to_u] = true;
//			//display_array(parent);
//			articulation_nodes(list, parent, visited, low_time, discovery_time, time, index_adj_to_u, AP, count);
//			//up till now we have reached to on depth-edn of DFS tree
//
//			//cout << "low time 2:" << endl;
//			//display_array(low_time);
//			low_time[index_u] = min(low_time[index_u], low_time[index_adj_to_u]);
//			//cout << "low time after assigning" << endl;
//			//display_array(low_time);
//
//
//			//cout << "parent 2:" << endl;
//			//display_array(parent);
//			if (parent[index_u] == -1 && children > 1) //if it is root and has two child-only root will have NULL parent
//			{
//				cout << head_of_list[index_u].get_head()->get_ID() << "<--->" << endl;
//				AP[index_u] = true;
//				count++;
//			}
//			if (parent[index_u] != -1 && low_time[index_adj_to_u] >= discovery_time[index_u])
//			{
//				cout << head_of_list[index_u].get_head()->get_ID() << "<--->" << endl;
//				AP[index_u] = true;
//				count++;
//			}
//		}
//		else if (index_adj_to_u != parent[index_u])
//		{
//			low_time[index_u] = min(low_time[index_u], discovery_time[index_adj_to_u]);
//		}
//		temp = temp->get_next();
//	}
//}


//-----------------------------------------------

//void BFS(int start)
	//{
	//	bool* visited = new bool[total_nodes];
	//	for (int i = 0; i < total_nodes; i++)
	//	{
	//		visited[i] = false;
	//	}
	//	Queue queue;

	//	visited[start] = true;
	//	queue.Enqueue(start);

	//	while (!queue.Is_Empty())
	//	{
	//		int node = queue.Dequeue();
	//		cout << node << " ";

	//		Node* temp = list[node].get_head();
	//		while (temp != NULL)
	//		{
	//			if (visited[temp->get_data()] == false) //if a node is not visited before
	//			{
	//				visited[temp->get_data()] = true;
	//				queue.Enqueue(temp->get_data());
	//			}
	//			temp = temp->get_next();
	//		}
	//	}
	//}
//=========================
/*Graph g(5, 8);
	g.add_edge(2, 1);
	g.add_edge(1, 2);
	g.add_edge(3, 2);
	g.add_edge(2, 3);
	g.add_edge(4, 5);
	g.add_edge(5, 4);
	g.add_edge(1, 5);
	g.add_edge(5, 1);*/

	/*g.print_in_degree_table();
	g.print_out_degree_table();
	g.print();
	*/



	//graph->find_SCCs();

	//graph->find_SCCs();

	/*g->add_edge(1, 2, 0);
	g->add_edge(2, 1, 1);
	g->add_edge(1, 4, 0);
	g->add_edge(2, 4, 1);
	g->add_edge(3, 2, 2);
	g->remain(4, 3);*/


	/*g->add_edge(0, 1, 0);
	g->add_edge(1, 2, 1);
	g->add_edge(2, 3, 2);
	g->remain(3, 3);*/

	/*g->add_edge(0, 1, 0);
	g->add_edge(1, 2, 1);
	g->add_edge(2, 0, 2);
	g->add_edge(1, 3, 1);
	g->add_edge(1, 4, 1);
	g->add_edge(1, 6, 1);
	g->add_edge(3, 5, 3);
	g->add_edge(4, 5, 4);

	g->remain(5, 5);
	g->remain(6, 6);

	g->path_length_dist();*/

	//Graph* g = new Graph(7, 6);

	/*g->add_edge(0, 1, 0);
	g->add_edge(0, 2, 0);
	g->add_edge(3, 1, 3);
	g->add_edge(3, 2, 3);
	g->add_edge(4, 5, 4);
	g->remain(1, 1);
	g->remain(2, 2);
	g->remain(5, 5);*/

	/*g->add_edge(0, 1, 0);
	g->add_edge(1, 2, 1);
	g->add_edge(2, 3, 2);
	g->add_edge(3, 4, 3);
	g->add_edge(4, 0, 4);
	g->add_edge(5, 6, 5);
	g->remain(6, 6);

	g->find_WCCs();*/

	/*cout << "NO. of articulation nodes: " << endl;
	g->find_articulation_nodes();*/

	//cout << "No. of Bridges: " << g->find_bridge_edges() << endl;

//--------=====================-------------------

//int main()
//{
//	
//	//g->find_SCC();
//	
//
//	Graph* g = new Graph(5, 14);
//	g->add_edge(0, 1, 0);
//	g->add_edge(0, 4, 0);
//
//	g->add_edge(1, 0, 1);
//	g->add_edge(1, 2, 1);
//	g->add_edge(1, 3, 1);
//	g->add_edge(1, 4, 1);
//
//	g->add_edge(2, 1, 2);
//	g->add_edge(2, 3, 2);
//
//	g->add_edge(3, 1, 3);
//	g->add_edge(3, 2, 3);
//	g->add_edge(3, 4, 3);
//
//	g->add_edge(4, 0, 4); 
//	g->add_edge(4, 1, 4); 
//	g->add_edge(4, 3, 4);
//
//	g->path_length_dist();
//
//	//g->print_in_degree_table();
//	//g->find_articulation_nodes();
//
//	//---------------------------------------------------------------------------------------------
//	/*Graph* g = new Graph(8, 9);
//	cout << "\nSCCs in first graph \n";*/
//	
//	/*g->add_edge(1, 0, 1);
//	g->add_edge(0, 2, 0);
//	g->add_edge(2, 1, 2);
//	g->add_edge(0, 3, 0);
//	g->add_edge(3, 4, 3);
//	g->remain(4, 4);*/
//
//	/*g->add_edge(0, 1, 0);
//	g->add_edge(1, 2, 1);
//	g->add_edge(2, 3, 2);
//	g->add_edge(3, 0, 3);
//	g->add_edge(2, 4, 2);
//	g->add_edge(4, 5, 4);
//	g->add_edge(5, 6, 5);
//	g->add_edge(6, 4, 6);
//	g->add_edge(6, 7, 6);
//	g->remain(7, 7);*/
//
//	
//
//	/*g->add_edge(0, 1, 0);
//	g->add_edge(1, 2, 1);
//	g->add_edge(2, 0, 2);
//	g->add_edge(2, 3, 2);
//	g->add_edge(3, 4, 3);
//	g->add_edge(4, 5, 4);
//	g->add_edge(5, 6, 5);
//	g->add_edge(6, 7, 6);
//	g->add_edge(6, 4, 6);
//	g->add_edge(4, 7, 4);
//	g->remain(7, 7);*/
//
//	//g->print_in_degree_table();
//	//g->print();
//
//	//g->directed();
//	
//
//	//------
//	/*bool* visited = new bool[8];
//	for (int i = 0; i <8; i++)
//	{
//		visited[i] = false;
//	}
//	g->DFS(0,visited);
//	cout << "recusrion" << endl;
//	for (int i = 0; i < 8; i++)
//	{
//		visited[i] = false;
//	}
//	Stack stack;
//	g->Recursive_DFS(0, visited,stack);
//	cout << "Stack" << endl;
//	while (!stack.isEmpty())
//	{
//		cout << stack.pop() << " ";
//	}*/
//	//---
//	//g->d();
//
//	
//
//	/*g->add_edge(0, 1, 0);
//	g->add_edge(1, 2, 1);
//	g->add_edge(2, 3, 2);
//	g->remain(3, 3);*/
//
//
//
//
//	//g->print();
//	//g->find_articulation_nodes();
//	// 
//	//g->find_SCCs();
//
//	/*g->add_edge(1, 2, 0);
//	g->add_edge(1, 3, 0);
//	g->add_edge(1, 5, 0);
//	g->add_edge(2, 5, 1);
//	g->add_edge(3, 4, 2);
//
//	g->remain(4, 3);
//	g->remain(5, 4);*/
//
//	//-----
//	/*g->add_edge(1, 2, 0);
//	g->add_edge(2, 3, 1);
//	g->add_edge(2, 4, 1);
//	g->remain(3, 2);
//	g->add_edge(4, 3, 3);*/
//
//
//	/*g->add_edge(1, 2, 0);
//	g->add_edge(2, 3, 1);
//	g->add_edge(3, 1, 2);
//
//	g->add_edge(4, 1, 3);
//	g->add_edge(5, 4, 4);*/
//
//	/*g->add_edge(1, 2, 0);
//	g->add_edge(1, 3, 0);
//	g->add_edge(1, 4, 0);
//
//	g->add_edge(2, 1, 1);
//	g->add_edge(2, 3, 1);
//
//	g->add_edge(3, 1, 2);
//	g->add_edge(3, 2, 2);
//	g->add_edge(3, 4, 2);
//
//	g->add_edge(4, 1, 3);
//	g->add_edge(4, 3, 3);*/
//
//	//g->remain(3, 3);
//	//g->remain(4, 4);
//
//	//g->calculate_in_degree();
//	//g->print();
//	//g->DFS(4);
//
//	/*cout << "---------" << endl;
//	g->find_articulation_nodes();*/
//	return 0;
//
//} 


//=\=\=\\==\\=\=\  ---imp

//if (prev_from_node == from_node)
			//{
			//	graph->add_edge(from_node, to_node, count);
			//	//do not increment count if it has same source node	
			//}
			//else
			//{
			//	count++;  //count becomes 0 for first time and 1 for second time
			//	graph->add_edge(from_node, to_node, count);
			//}
			//prev_from_node = from_node;

//							---------------imp----------------

//void remain(int source, int count)
	//{
	//	if (head_of_list[count].get_head() == NULL) //if NULL then insert both source and destination
	//	{
	//		head_of_list[count].set_index(count); //index will only be set when a new source node comes
	//		head_of_list[count].add_node(source);
	//	}
	//}

//						----------------imp----------------

//void add_edge(int source, int destination, int count)  //count represents pair no.
	//{
	//	if (head_of_list[count].get_head() == NULL) //if NULL then insert both source and destination
	//	{
	//		head_of_list[count].set_index(count); //index will only be set when a new source node comes
	//		head_of_list[count].add_node(source);
	//		head_of_list[count].add_node(destination);
	//	}
	//	else
	//	{
	//		head_of_list[count].add_node(destination);
	//	}
	//}