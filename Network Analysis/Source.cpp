#include<iostream>
#include<iomanip>
#include<fstream>
#include<string>
#include<sstream>
#include"Graph.h"
using namespace std;

Graph* read_file(string filename)
{
	ifstream file(filename);
	
	string s;
	getline(file, s);
	getline(file,s);
	getline(file, s);

	stringstream word(s);
	string data;
	
	int count = -1;
	int nodes = 0, edges = 0;

	getline(word, data, ' '); //#
	getline(word, data, ' ');  //Nodes:
	getline(word, data, ' ');  //actual no of nodes

	nodes = atoi(data.c_str());
	getline(word, data, ' ');   //Edges:
	getline(word, data, ' ');   //actual no. of edges

	edges = atoi(data.c_str());

	getline(file, s);  //From node and to node line
	Graph *graph = new Graph(nodes,edges);
	int prev_from_node = 0;
	
	if (file.is_open())
	{
		int from_node = 0;
		int to_node = 0;
		while (file >> from_node >> to_node)
		{
			graph->add_edge(from_node, to_node);
		}
	}
	else
	{
		cout << "error" << endl;
	}
	return graph;
}

int main_menu()
{
	int choice = 0;
	cout << '*' << setw(100) << setfill('*') << '*' << endl;
	cout << '|' << setw(100) << setfill(' ') << '|' << endl;
	cout << '|' << setw(65) << setfill(' ') << "MAIN MENU FOR NETWORK ANALYSIS USING GRAPHS" << setw(35) << setfill(' ') << '|' << endl;
	cout << '|' << setw(100) << setfill(' ') << '|' << endl;

	cout << '*' << setw(100) << setfill('*') << '*' << endl << endl;
	cout << "\t\t*----------------------------------------------------------*\t\t" << endl;
	cout << "\t\t|      CHOOSE NUMBER FOR WHICH TASK YOU WANT TO CHECK      |\t\t" << endl;
	cout << "\t\t*----------------------------------------------------------*\t\t" << endl;
	cout << endl;
	cout << "PRESS 1 for First Set of Tasks ( Graph Stats )" << endl;
	cout << "PRESS 2 for Second Set of Tasks ( Degree Distributions )" << endl;
	cout << "PRESS 3 for Third Set of Tasks ( Connected Components )" << endl;
	cout << "PRESS 4 for exiting the program " << endl;
	cin >> choice;

	return choice;
}

void menu_1(Graph* graph)
{
	int option = 0;
	do 
	{
		cout << '*' << setw(100) << setfill('*') << '*' << endl;
		cout << '|' << setw(100) << setfill(' ') << '|' << endl;
		cout << '|' << setw(65) << setfill(' ') << "First Set of Tasks ( Graph Stats )" << setw(35) << setfill(' ') << '|' << endl;
		cout << '|' << setw(100) << setfill(' ') << '|' << endl;
		cout << '*' << setw(100) << setfill('*') << '*' << endl << endl;

		cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 1 for Display the number of nodes" << "                    " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 2 for Display the number of edges" << "                    " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 3 for Display the number of source nodes" << "             " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 4 for Display the number of sink nodes" << "               " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 5 for Display the number of isolated nodes" << "           " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 6 for Display the number of bridge edges" << "             " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 7 for Display the number of articulation nodes" << "       " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 8 for Display the shortest path length distribution" << "  " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 9 for Display the diameter of the graph" << "              " << "\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 10 to Go back to main menu" << "                           " << "\t" << "|" << endl;
		cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
		cin >> option;
		switch (option)
		{
		case 1:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The total number of nodes : " << graph->get_nodes() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 2:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The total number of edges : " << graph->get_edges() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 3:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The total number of source nodes : " << graph->source_nodes() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 4:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The total number of sink nodes : " << graph->sink_nodes() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 5:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The total number of isolated nodes : " << graph->isolated_nodes() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 6:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|    The total number of bridge edges : " << graph->find_bridge_edges() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 7:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|   The total number of articulation nodes : " << graph->find_articulation_nodes() << "  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			graph->find_articulation_nodes();
			break;

		case 8:
			system("cls");
			graph->path_length_dist();
			break;

		case 9:
			system("cls");
			if (graph->get_diameter() == -1)
			{
				graph->path_length_dist(false);
			}
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The diameter of the graph is:  " << graph->get_diameter() << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 10:
			return;

		default:
			system("cls");
			cout << "Invalid option, Please try again" << endl << endl;
		}
	} while (option != 10);
}

void menu_2(Graph* graph)
{
	int option = 0;
	do
	{
		cout << '*' << setw(100) << setfill('*') << '*' << endl;
		cout << '|' << setw(100) << right << setfill(' ') << '|' << endl;
		cout << '|' << setw(65) << right << setfill(' ') << "Second Set of Tasks ( Degree Distributions )" << setw(35) << setfill(' ') << '|' << endl;
		cout << '|' << setw(100) << setfill(' ') << '|' << endl;
		cout << '*' << setw(100) << setfill('*') << '*' << endl << endl;

		cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 1 to display in-degree distribution table" << "  " << "\t\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 2 to display out-degree distribution table" << " " << "\t\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 3 to go back to main menu" << "                  " << "\t\t" << "|" << endl;
		cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "In-degree Disribution is : " << endl;
			system("cls");
			graph->print_in_degree_table();
			break;

		case 2:
			cout << "Out-degree Distribution is : " << endl;
			system("cls");
			graph->print_out_degree_table();
			break;

		case 3:
			return;

		default:
			system("cls");
			cout << "Invalid option, Please try again" << endl << endl;
		}
	} while (option != 3);
}

void menu_3(Graph* graph)
{
	int option = 0;
	do
	{
		cout << '*' << setw(100) << setfill('*') << '*' << endl;
		cout << '|' << setw(100) << setfill(' ') << '|' << endl;
		cout << '|' << setw(65) << setfill(' ') << "Third Set of Tasks ( Connected Components )" << setw(35) << setfill(' ') << '|' << endl;
		cout << '|' << setw(100) << setfill(' ') << '|' << endl;
		cout << '*' << setw(100) << setfill('*') << '*' << endl << endl;

		cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 1 to display the size of largest SCC" << "            " << "\t\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 2 to display the size distribution of all SCCs" << "  " << "\t\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 3 to display the size of largest WCC" << "            " << "\t\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 4 to display the size distribution of all WCCs" << "  " << "\t\t" << "|" << endl;
		cout << "\t\t" << "|" << "\t" << "PRESS 5 to go back to main menu" << "                       " << "\t\t" << "|" << endl;
		cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
		cin >> option;

		switch (option)
		{
		case 1:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The size of largest SCC is:  " << graph->find_SCCs(false) << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 2:
			system("cls");
			graph->find_SCCs();
			break;

		case 3:
			system("cls");
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t|\t The size of largest WCC is:  " << graph->find_WCCs(false) << "\t  |" << endl;
			cout << "\t\t|" << setw(50) << setfill(' ') << '|' << endl;
			cout << "\t\t" << setw(51) << setfill('-') << '-' << endl;
			break;

		case 4:
			system("cls");
			graph->find_WCCs();
			break;

		case 5:
			return;

		default:
			system("cls");
			cout << "Invalid option, Please try again" << endl << endl;
		}
	} while (option != 5);
}

void main_interface(Graph* graph)
{
	int choice = 0;
	do
	{
		choice = main_menu();
		switch (choice)
		{
		case 1:
			system("cls");
			menu_1(graph);
			system("cls");
			break;

		case 2:
			system("cls");
			menu_2(graph);
			system("cls");
			break;

		case 3:
			system("cls");
			menu_3(graph);
			system("cls");
			break;

		case 4:
			system("cls");
			cout << "Exiting Program" << endl;
			return;

		default:
			system("cls");
			cout << "Invalid choice. Please try again" << endl;
		}
	} while (choice != 4);
}

int main()
{
	string filename = "CA-GrQc.txt";
	Graph* graph = read_file(filename);
	main_interface(graph);

	return 0;
}