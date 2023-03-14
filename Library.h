#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Account.h"
using namespace std;


class Library
{
public:
	//Todo: constructor that takes a library ID (string)
	Library(string libid)
	{
		libId = libid;
		readBookItems();
		readVideoItems();
		readAccount();
	}

// Todo: readBookItems function reads from the book.txt, creates the book object and 
	//stores them in the ItemList vector. Note the name of the file is “book”
	//followed by the library ID.

	void readBookItems()
	{
		string id;
		string title;
		string author;

		ifstream ifile("book" + libId + ".txt");
if (ifile.fail()) //if function used to make sure the file is properly loaded into the program, if not, then the program is exited right then.
		{
			cout << "Failed to load the file, exiting...";
			exit(2);
		}

		while (!ifile.eof())
		{
			

			getline(ifile, id);
			getline(ifile, title);
			getline(ifile, author);

			Book* bookt = new Book(id, title, author);
			itemList.push_back(bookt);
		}
		ifile.close();


		
	}

	// Todo: readVideoItems function that reads from the video.txt, creates the video 
//object and stores them in the ItemList vector. Note the name of the file is “video”
	//followed by the library ID.

	void readVideoItems()
	{
		string id;
		string title;
		string genre;
		string directors;
		string producers;

		ifstream ifile("video" + libId + ".txt");
if (ifile.fail()) //if function used to make sure the file is properly loaded into the program, if not, then the program is exited right then.
		{
			cout << "Failed to load the file, exiting...";
			exit(2);
		}

		while (!ifile.eof())
		{


			getline(ifile, id);
			getline(ifile, title);
			getline(ifile,genre);
			getline(ifile,directors);
			getline(ifile,producers);


			Video* videot = new Video(id, title, genre, directors, producers);
			itemList.push_back(videot);
		}
		ifile.close();


		
	}
	 
	
// Todo: readAccount function reads from the account.txt, creates the account object 
//and stores them in the accountList vector. Note the name of the file is “account”
	//followed by the library ID.
	void readAccount()
	{
		string id;
		string pass;

		ifstream ifile("account" + libId + ".txt");

if (ifile.fail()) //if function used to make sure the file is properly loaded into the program, if not, then the program is exited right then.
		{
			cout << "Failed to load the file, exiting...";
			exit(2);
		}
		while (!ifile.eof())
		{


			ifile >> id;
			ifile >> pass;


			Account t(id, pass);
			accountList.push_back(t);
		}
		ifile.close();



	}

	// Todo: validate function validates the passed id and password. 
	//the function returns -1 if invalid, and the index of the account if valid
	int validate(string aid, string apass)
	{
		for (int i = 0; i < accountList.size(); i++)
		{
if ((aid == accountList[i].getid())&&(apass==accountList[i].getpass()))
			{
				return i;
			}

		}

		return -1;
	}




	// Todo: getItemList function returns the vector of Items addresses
	vector<Item*> getItemList()
	{
		return itemList;
	}

	// Todo: addItem function adds an Item into the itemList
	void addItem(Item* item)
	{
		if (dynamic_cast<Book*>(item))
		{
Book* b = new Book((*static_cast<Book*>(item)).getItemid(), (*static_cast<Book*>(item)).getItemtitle(), (*static_cast<Book*>(item)).getauthor());
			itemList.push_back(b);
		}
		if (dynamic_cast<Video*>(item))
		{
Video* v = new Video((*static_cast<Video*>(item)).getItemid(), (*static_cast<Video*>(item)).getItemtitle(), (*static_cast<Video*>(item)).getgenre(),
(*static_cast<Video*>(item)).getdirector(), (*static_cast<Video*>(item)).getproducer());
			itemList.push_back(v);
		}


	}

	// Todo: getAccountList function returns the accountList
	vector<Account>getAccountList()
	{
		return accountList;
	}

	// Todo: removeItem function removes an item from the itemList and returns true if 
	//item is found and removed successfully
	bool removeItem(Item* item)
	{
		for (int i = 0; i < itemList.size(); i++)
		{
			if ((item->getItemid())==(itemList[i]->getItemid()))
			{
				itemList.erase(itemList.begin() + i);
				return true;
			}
		}

		
		return false;
	}


	//SearchItem function searches for an item. 
	//the function returns the index of the found item. If no item is found,
	//the function returns -1
	int SearchItem(string id)
	{
		for (int i = 0; i < itemList.size(); i++)
		{
			if (id == (itemList[i]->getItemid()))
			{
				return i;
			}
		}

		return -1;
	}



	Library(const Library& lib)
	{
		libId = lib.libId;
		itemList.clear();
		for (int i = 0; i < lib.itemList.size(); i++)
		{
			if (dynamic_cast<Book*>(lib.itemList[i]))
			{
Book* temp = new Book(lib.itemList[i]->getItemid(), lib.itemList[i]->getItemtitle(), dynamic_cast<Book*>(lib.itemList[i])->getauthor());

				this->itemList.push_back(temp);
			}


			if (dynamic_cast<Video*>(lib.itemList[i]))
			{
Video* temp = new Video(lib.itemList[i]->getItemid(), lib.itemList[i]->getItemtitle(),
dynamic_cast<Video*>(lib.itemList[i])->getgenre(), dynamic_cast<Video*>(lib.itemList[i])->getdirector(), dynamic_cast<Video*>(lib.itemList[i])->getproducer());

				this->itemList.push_back(temp);
			}

		}
		accountList = lib.accountList;

	}

	//equal operator
	void operator=(const Library& lib)
	{
		libId = lib.libId;
for (int i = 0; i < itemList.size(); i++)
		{
			delete itemList[i];
		}
		itemList.clear();
		for (int i = 0; i < lib.itemList.size(); i++)
		{
			if (dynamic_cast<Book*>(lib.itemList[i]))
			{
Book* temp = new Book(lib.itemList[i]->getItemid(), lib.itemList[i]->getItemtitle(), dynamic_cast<Book*>(lib.itemList[i])->getauthor());

				this->itemList.push_back(temp);
			}


			if (dynamic_cast<Video*>(lib.itemList[i]))
			{
Video* temp = new Video(lib.itemList[i]->getItemid(), lib.itemList[i]->getItemtitle(),
dynamic_cast<Video*>(lib.itemList[i])->getgenre(), dynamic_cast<Video*>(lib.itemList[i])->getdirector(), dynamic_cast<Video*>(lib.itemList[i])->getproducer());

				this->itemList.push_back(temp);
			}

		}
		accountList = lib.accountList;
	}

	//destructor
	~Library()
	{
		for (int i = 0; i < itemList.size(); i++)
		{
			delete itemList[i];
		}

	}
private:
	//libId: holds the library ID
	string libId;
	//itemList hold the items objects in the library
	vector<Item*> itemList;
	//accountList hold the account objects 
	vector<Account> accountList;
};
