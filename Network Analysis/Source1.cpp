//#include <iostream>
//#include<iomanip>
//using namespace std;
//
//int main_menu()
//{
//    int choice = 0;
//    cout << "----------------------------------------------------------" << endl;
//    cout << "     CHOOSE NUMBER FOR WHICH TASK YOU WANT TO CHECK" << endl;
//    cout << "----------------------------------------------------------" << endl;
//    cout << "PRESS 1 for First Set of Tasks -> Graph Stats" << endl;
//    cout << "PRESS 2 for Second Set of Tasks –> Degree Distributions" << endl;
//    cout << "PRESS 3 for Third Set of Tasks –> Connected Components " << endl;
//    cin >> choice;
//
//    return choice;
//}
//
//void menu_1()
//{
//    int option = 0;
//    cout << '*' << setw(100) << setfill('*') << '*' << endl;
//    cout << '|' << setw(100) << setfill(' ') << '|' << endl;
//    cout << '|' << setw(65) << setfill(' ') << "First Set of Tasks -> Graph Stats" << setw(35) << setfill(' ') << '|' << endl;
//    cout << '|' << setw(100) << setfill(' ') << '|' << endl;
//    /* cout << '|' << setw(100) << setfill('-') << '|' << endl;*/
//    cout << '*' << setw(100) << setfill('*') << '*' << endl << endl;
//
//    cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 1 for Display the number of nodes" << "                    " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 2 for Display the number of edges" << "                    " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 3 for Display the number of source nodes" << "             " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 4 for Display the number of sink nodes" << "               " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 5 for Display the number of isolated nodes" << "           " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 6 for Display the number of bridge edges" << "             " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 7 for Display the number of articulation nodes" << "       " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 8 for Display the shortest path length distribution" << "  " << "\t" << "|" << endl;
//    cout << "\t\t" << "|" << "\t" << "PRESS 9 for Display the diameter of the graph" << "              " << "\t" << "|" << endl;
//    cout << "\t\t" << setw(73) << setfill('-') << '-' << endl;
//    cin >> option;
//    switch (option)
//    {
//    case 1:
//        system("cls");
//        cout << "The total number of nodes : " << endl;
//        break;
//
//    case 2:
//        system("cls");
//        cout << "The total number of edges : " << endl;
//        break;
//
//    case 3:
//        system("cls");
//        cout << "The total number of source nodes : " << endl;
//        break;
//
//    case 4:
//        system("cls");
//        cout << "The total number of sink nodes : " << endl;
//        break;
//
//    case 5:
//        system("cls");
//        cout << "The total number of isolated nodes : " << endl;
//        break;
//
//    case 6:
//        system("cls");
//        cout << "The total number of bridge edges : " << endl;
//        break;
//
//    case 7:
//        system("cls");
//        cout << "The total number of articulation nodes : " << endl;
//        break;
//
//    case 8:
//        system("cls");
//        cout << "Shortest path length distribution is " << endl;
//        break;
//
//    case 9:
//        system("cls");
//        cout << "The diameter of the graph is  " << endl;
//        break;
//
//    default:
//        cout << "Invalid option, Please try again" << endl;
//    }
//}
//
//void menu_2()
//{
//    int option = 0;
//    cout << "PRESS 1 for Display the in-degree distribution in the form of a table" << endl;
//    cout << "PRESS 2 for Display the out-degree distribution in the form of a table" << endl;
//    cin >> option;
//    switch (option)
//    {
//    case 1:
//        cout << "In-degree Disribution is : " << endl;
//        break;
//
//    case 2:
//        cout << "Out-degree Distribution is : " << endl;
//        break;
//
//    default:
//        cout << "Invalid option, Please try again" << endl;
//    }
//}
//
//void menu_3()
//{
//    int option = 0;
//    cout << "PRESS 1 for Display the size of the largest strongly connected component (SCC)" << endl;
//    cout << "PRESS 2 for Display the size distribution of all SCCs" << endl;
//    cout << "PRESS 3 for Display the size of the largest weakly connected component (WCC)" << endl;
//    cout << "PRESS 4 for Display the size distribution of all WCCs" << endl;
//    cin >> option;
//    switch (option)
//    {
//    case 1:
//        cout << "PRESS 12 for Display the size of the largest strongly connected component (SCC)" << endl;
//        break;
//
//    case 2:
//        cout << "PRESS 13 for Display the size distribution of all SCCs" << endl;
//        break;
//
//    case 3:
//        cout << "PRESS 14 for Display the size of the largest weakly connected component (WCC)" << endl;
//        break;
//
//    case 4:
//        cout << "PRESS 15 for Display the size distribution of all WCCs" << endl;
//        break;
//
//    default:
//        cout << "Invalid option, Please try again" << endl;
//    }
//}
//
//void main_interface()
//{
//    int choice = 0;
//    do
//    {
//        choice = main_menu();
//        switch(choice)
//        {
//        case 1:
//            system("cls");
//            menu_1();
//            break;
//
//        case 2:
//            system("cls");
//            menu_2();
//            break;
//
//        case 3:
//            system("cls");
//            menu_3();
//            break;
//
//        default:
//            system("cls");
//            cout << "Invalid choice. Please try again" << endl;
//        }
//    } while (choice < 0 || choice > 3);
//}
//
//int main()
//{
//    main_interface();
//}




