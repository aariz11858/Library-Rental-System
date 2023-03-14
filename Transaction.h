#pragma once
#include "Item.h"
#include <vector>

class Transaction
{
public:
	Transaction() {}

	//this function adds an item to the itemVector
	void borrowItems(Item* item);
	

	//this function returns the itemVector
	vector<Item*> getItemVector();

	//this function is a setter to the itemVector attribute
	void setItemVector(vector<Item*> iVector);

	//this function returns the index location of the found item in the a transaction. 
	//the function return -1 if the item is not found
	int findBorrowedItem(Item* item);


	//copy constructor
	Transaction(const Transaction& transaction1)
	{
		itemVector.clear();

		for (int i = 0; i < transaction1.itemVector.size(); i++)
		{
			if (dynamic_cast<Book*>(transaction1.itemVector[i]))
			{
Book* temp = new Book(transaction1.itemVector[i]->getItemid(), transaction1.itemVector[i]->getItemtitle(), dynamic_cast<Book*>(transaction1.itemVector[i])->getauthor());

				itemVector.push_back(temp);
			}


			if (dynamic_cast<Video*>(transaction1.itemVector[i]))
			{
Video* temp = new Video(transaction1.itemVector[i]->getItemid(), transaction1.itemVector[i]->getItemtitle(),
dynamic_cast<Video*>(transaction1.itemVector[i])->getgenre(), dynamic_cast<Video*>(transaction1.itemVector[i])->getdirector(), dynamic_cast<Video*>(transaction1.itemVector[i])->getproducer());

				itemVector.push_back(temp);
			}

		}
		
	}

	//equal operator
	void operator=(const Transaction& transaction1)
	{
		for (int i = 0; i < itemVector.size(); i++)
		{
			delete itemVector[i];
		}
		itemVector.clear();
		for (int i = 0; i < transaction1.itemVector.size(); i++)
		{
			if (dynamic_cast<Book*>(transaction1.itemVector[i]))
			{
Book* temp = new Book(transaction1.itemVector[i]->getItemid(), transaction1.itemVector[i]->getItemtitle(), dynamic_cast<Book*>(transaction1.itemVector[i])->getauthor());

				itemVector.push_back(temp);
			}


			if (dynamic_cast<Video*>(transaction1.itemVector[i]))
			{
Video* temp = new Video(transaction1.itemVector[i]->getItemid(), transaction1.itemVector[i]->getItemtitle(),
dynamic_cast<Video*>(transaction1.itemVector[i])->getgenre(), dynamic_cast<Video*>(transaction1.itemVector[i])->getdirector(), dynamic_cast<Video*>(transaction1.itemVector[i])->getproducer());

				itemVector.push_back(temp);
			}

		}
	}

	//destructor
	~Transaction()
	{
		for (int i = 0; i < itemVector.size(); i++)
		{
			delete itemVector[i];
		}

	}

private:
	//holds the items borrowed in the vector
	vector<Item*> itemVector;
};

void Transaction::borrowItems(Item* item)
{
	if (dynamic_cast<Book*>(item))
	{
		Book* b = new Book((*static_cast<Book*>(item)).getItemid(), (*static_cast<Book*>(item)).getItemtitle(), (*static_cast<Book*>(item)).getauthor());
		itemVector.push_back(b);
	}
	if (dynamic_cast<Video*>(item))
	{
		Video* v = new Video((*static_cast<Video*>(item)).getItemid(), (*static_cast<Video*>(item)).getItemtitle(), (*static_cast<Video*>(item)).getgenre(),
			(*static_cast<Video*>(item)).getdirector(), (*static_cast<Video*>(item)).getproducer());
		itemVector.push_back(v);
	}
}

vector<Item*> Transaction::getItemVector()
{
	return itemVector;
}

void Transaction::setItemVector(vector<Item*> iVector)
{
	itemVector = iVector;
}

int Transaction::findBorrowedItem(Item* item)
{
	for (int i = 0; i < itemVector.size(); i++)
	{
		if (itemVector[i] == item)
		{
			return i;
		}

	}

	return -1;
}
