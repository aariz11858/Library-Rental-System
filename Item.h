#pragma once
#include <string>
#include<iostream>
using namespace std;


class Item
{
public:
	//constructors 
	Item() {}
	Item(string iid, string ititle)
	{
		id = iid;
		title = ititle;
	}

	Item(string iid)
	{
		id = iid;
	}


	//getters and setters
	string getItemid()
	{
		return id;
	}

	string getItemtitle()
	{
		return title;
	}

	//Include virtual function print
	virtual void print() = 0;


private:
	//common attributes for video and book items
	string id;
	string title;
};

class Book :public Item
{
public:
	Book(string iid, string itile, string author) :Item(iid, itile)
	{
		this->author = author;
	}

	Book();

	string getauthor()
	{
		return author;
	}

	void print()
	{
		cout << endl <<  "---------------Book Item----------------" << endl;
		cout << "Book Id: " << getItemid() << endl;
		cout << "Book Title: " << getItemtitle() << endl;
		cout << "Book Author: " << author << endl;
		cout << "-----------------------------------------" << endl << endl;
	}

private:
	string author;
};

class Video : public Item
{
public:
Video(string iid, string itile, string genre, string directors, string producers) :Item(iid, itile)
	{
		this->genre = genre;
		this->directors = directors;
		this->producers = producers;
	}

	Video();

	string getgenre()
	{
		return genre;
	}

	string getdirector()
	{
		return directors;
	}

	string getproducer()
	{
		return producers;
	}

	void print()
	{
		cout << endl << "---------------Video Item----------------" << endl;
		cout << "Video Information: " << endl;
		cout << "Video Id: " << getItemid() << endl;
		cout << "Video Title: " << getItemtitle() << endl;
		cout << "Video Director: " << directors << endl;
		cout << "Video Genre: " << genre << endl;
		cout << "Video Producer: " << producers << endl;
		cout << "-----------------------------------------" << endl << endl;
	}

private:
	string genre;
	string directors;
	string producers;

};
