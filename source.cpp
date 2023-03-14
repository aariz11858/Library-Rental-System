#include<iostream>
#include"Library.h"
#include"Transaction.h"
using namespace std;

int menu()
{
	int option;
	cout << "1)View all items\n2)Borrow Items\n3)View Borrowed Items\n4)Return Borrowed Item\n5)Quit\nEnter Option : ";
		cin >> option;
	return option;
}
int login(Library lib)
{
	string id, pass;
	cout << endl;
	cout << "Enter ID: ";
	cin >> id;
	cout << "Enter password: ";
	cin >> pass;
	return lib.validate(id, pass);
}
int main()
{
	//initializing a library instance
	string libraryId = "123";
	Library lib(libraryId);
	//is account validated?
	int accountIndex = login(lib);
	//if validated, show the menu
	if (accountIndex != -1)
	{
		//retreived the account object
		Account account = lib.getAccountList()[accountIndex];
		//holds the option, input for the menu option
		int option;
		do {
			option = menu();
			//Option 1 displays all items in the library both books and videos
			if (option == 1)
			{
				//implementation goes here
				for (int i = 0; i < lib.getItemList().size(); i++)
				{
					lib.getItemList()[i]->print();
				}
			}
			//if option borrow item
			if (option == 2)
			{
				Transaction trans;
				int numItems;
				string itemId;
				cout << "\nHow many items to borrow: ";
				cin >> numItems;
				for (int i = 0; i < numItems; i++)
				{
					cout << "\nEnter the ID of the item to borrow: ";
					cin >> itemId;
					//check if the itemId is borrowed by the user
					int foundInd = lib.SearchItem(itemId);
					if (foundInd != -1)
					{

//borrow the item by calling the transaction object
//note that the item should not be available to be borrowed
						//again if it is borrowed by a user

						int count = 0;
for (int i = 0; i < lib.getAccountList().size(); i++)
						{

for (int j = 0; j < lib.getAccountList()[i].getTransaction().size(); j++)
							{
if(lib.getAccountList()[i].getTransaction()[j].findBorrowedItem(lib.getItemList()[foundInd]) != -1)
							{

								count++;

							}
							
							}
						}
						if (count==0)
						{
							trans.borrowItems(lib.getItemList()[foundInd]);
						}
if (lib.removeItem(lib.getItemList()[foundInd]) == true)
						{
cout << endl << "Item was borrowed successfully." << endl << endl;
						}
						else
						{
cout << endl << "Item is borrowed by someone else." << endl << endl;
						}
						
					}
					else
					{
cout << "Item not found in the library..." << endl;
						i--;
					}
				}
				//add the transaction to the account
				account.addTransaction(trans);

				

				
			}
			//if option is to view borrowed items
			if (option == 3)
			{
//View the borrowed items. Borrowed items can be of type book or video
cout << endl << "============== Borrowed Items =============" << endl;
				for (int i = 0; i < account.getTransaction().size(); i++)
				{
for (int j = 0; j < account.getTransaction()[i].getItemVector().size(); j++)
					{
account.getTransaction()[i].getItemVector()[j]->print();
					}
				}
	cout << "========== End of Borrowed Items ==========" << endl << endl;
			}
			//option to return an item back to the library
			if (option == 4)
			{
				string itemId;
				//return the item back to the library
				cout << endl<<  "Enter item ID to return: ";
				cin >> itemId;
				vector<Transaction> temp;
				int count = 0;
				for (int i = 0; i < account.getTransaction().size(); i++)
				{
for (int j = 0; j < account.getTransaction()[i].getItemVector().size(); j++)
					{
if (account.getTransaction()[i].getItemVector()[j]->getItemid() == itemId)
						{
						lib.addItem(account.getTransaction()[i].getItemVector()[j]);
cout << endl << "Return successful" << endl << endl;
							count++;
						}
						else 
						{
							Transaction temp2;
								temp2.borrowItems(account.getTransaction()[i].getItemVector()[j]);
							temp.push_back(temp2);
						}
					}
				
				}
				account.setTransaction(temp);
				if (count ==0)
				{
cout << endl << "Item not found in account." << endl <<endl;
				}

			}
		} while (option != 5); //end of do while
	}
	system("pause");
	return 0;
}
