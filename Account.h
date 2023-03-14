#pragma once
#include "Transaction.h"

class Account
{
public:
	//Todo: default constructor and a non-default constructor that takes in the ID and password
	Account(string id, string pass)
	{
		this->id = id;
		this->pass = pass;
	}

	Account()
	{
		id = "None";
		pass = "None";
	}

//Todo: getTransaction that function returns the vector of all transactions for the account
	vector<Transaction> getTransaction()
	{
		return translist;
	}

	//Todo: addTransaction function that adds a transaction to the transaction list
	void addTransaction(Transaction t)
	{
		translist.push_back(t);
	}

	//Todo: setTransaction function set the transaction vector in the account
	void setTransaction(vector<Transaction> t)
	{
		translist = t;
	}

	//id getter
	string getid()
	{
		return id;
	}


	//pass getter
	string getpass()
	{
		return pass;
	}


	//Todo: Any required operators that is to be overloaded
	void operator=(Account a1)
	{
		id = a1.id;
		pass = a1.pass;
		translist.clear();

		for (int i = 0; i < a1.translist.size(); i++)
		{

			for (int j = 0; j < a1.translist[i].getItemVector().size(); j++)
			{
				if (dynamic_cast<Book*>(a1.translist[i].getItemVector()[j]))
				{
Book* temp = new Book(a1.translist[i].getItemVector()[j]->getItemid(), a1.translist[i].getItemVector()[j]->getItemtitle(), 
dynamic_cast<Book*>(a1.translist[i].getItemVector()[j])->getauthor());
					Transaction t;
					t.borrowItems(temp);
					translist.push_back(t);
				}


				if (dynamic_cast<Video*>(a1.translist[i].getItemVector()[j]))
				{
Video* temp = new Video(a1.translist[i].getItemVector()[j]->getItemid(), a1.translist[i].getItemVector()[j]->getItemtitle(), dynamic_cast<Video*>(a1.translist[i].getItemVector()[j])->getgenre(), dynamic_cast<Video*>(a1.translist[i].getItemVector()[j])->getdirector(), dynamic_cast<Video*>(a1.translist[i].getItemVector()[j])->getproducer());
					Transaction t;
					t.borrowItems(temp);
					translist.push_back(t);
				}


			}
		}
		
	}


	Account(const Account& a1)
	{
		id = a1.id;
		pass = a1.pass;
		translist.clear();

		for (int i = 0; i < a1.translist.size(); i++)
		{
			translist.push_back(a1.translist[i]);
		}

	}


	~Account()
	{
		
	}
private:
	//id holds the id of the account, pass holds the password
	string id, pass;
	//vector holds all the transactions associated to the account
	vector<Transaction> translist;
};
