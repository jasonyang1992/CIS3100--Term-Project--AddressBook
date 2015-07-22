/*
 * Menu.cpp
 * Class definitions for Menu class
 *  Created on: July 21, 2015
 *      Author: Maria Piletskaya
 */
#include "Menu.h"
#include "ContactList.h"
#include <iostream>
#include <string>

using namespace std;
//l

ContactList cl;

Menu::Menu(void)
{
}


Menu::~Menu(void)
{
}

int Menu::showMenu()
{
	int choice;
	start_menu:

	  cout << " _____________________________________" << endl;
      cout << "|         Address Book Menu           |" << endl;
      cout << "|                                     |" << endl;
      cout << "| 1. Show all contacts                |" << endl;
      cout << "| 2- Search for an entry by last name |" << endl;
	  cout << "| 3- Sort by last name                |" << endl;
      cout << "| 4- Add a contact                    |" << endl;
	  cout << "| 5- Edit a contact                   |" << endl;
	  cout << "| 6- Delete a contact                 |" << endl;
      cout << "| 7- Exit                             |" << endl;
      cout << "|_____________________________________|" << endl;
	
		cin >> choice;

// process the menu option entered by the user
	switch(choice)
	{
		case 1:showAll();break;
		case 2:filterList();break;
		case 3:sortLName();break;
		case 4:;break;
		case 5:;break;
		case 6:;break;
		case 7:goto stop;break;
		default:cout <<"Goodbye ..";
					goto stop;
	}
	goto start_menu;
	stop:
	return 0; 
}

void Menu::showAll()
{
	cl.readData();
	cl.displayList(cl.getList());
}

void Menu::filterList()
{
	cl.readData();
	string input;
	cout << "Enter a last name(Case sensitive): ";
	cin >> input;

	cl.displayList(cl.searchByLName(input));
}

void Menu::sortLName()
{
	cl.readData();
	cl.sortAlphabetically();
	cl.displayList(cl.getList());
}