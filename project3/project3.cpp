#include <iostream>
#include <iomanip>
#include <string.h> // why do I need to use string.h instead of just string??

using namespace std;

const int numStruct = 3;

struct item{
	char itemNumber[15]; //assuming the SKU could be alphanumeric.
	char itemName[35];
	char itemDesc[200];
	int itemQuantity;
};

void genDummyData(item* pItem);

int displayMenu();
void displaySingleItem(item* pItem);
void editItem(item* pItem);
void displayAllItems(item* pItem);

int main(void){
	
	int menuSelection;
	bool running = true;
	
	item items[numStruct];
	item* pItem;
	pItem = items;
	genDummyData( pItem);
	
	while(running){
		menuSelection = displayMenu();
		switch(menuSelection){
			case 1:
				displaySingleItem(pItem);
				break;
			case 2:
				editItem(pItem);
				break;
			case 3:
				displayAllItems(pItem);
				break;
			case 4:
				running = false;
				break;
		}
	}
}

int displayMenu(){
	
	int selection;

	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                           Inventory Management Menu\n";
	cout<<" ------------------------------------------------------------------------------\n\n";
	cout<<"                        1 - Display an items information.\n\n";
	cout<<"                        2 - Edit an items information.\n\n";
	cout<<"                        3 - Display all items.\n\n";
	cout<<"                        4 - Exit program.\n\n\n";
	cout<<"Select an option: ";
 
	cin>>setw(1)>>selection;
	cin.ignore();
	
	return selection;
}

void displaySingleItem(item* pItem){
	
	char searchString[15];
	bool found = false;
	int i = 0;

	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                               Item Information\n";
	cout<<" ------------------------------------------------------------------------------\n\n";

	cout<<"Enter item number to search for: ";
	cin.getline(searchString, 15, '\n');
	
	while(!found && i<numStruct)
	{
		if(!strcmp(pItem->itemNumber, searchString))
		{
			system("cls");
			cout<<" ------------------------------------------------------------------------------\n";
			cout<<"                               Item Information\n";
			cout<<" ------------------------------------------------------------------------------\n\n";
			cout<<"        Item Name: "<<pItem->itemName<<endl<<endl;
			cout<<"      Item Number: "<<pItem->itemNumber<<endl<<endl;
			cout<<" Item Description: "<<pItem->itemDesc<<endl<<endl;
			cout<<"    Item Quantity: "<<pItem->itemQuantity<<endl<<endl<<endl;
	
			found=true;
		}
		i++;
		pItem++;
	}
	if(i == numStruct)
		cout<<endl<<"No matching item was found"<<endl<<endl;
	
	system("pause");
}

void editItem(item* pItem){

	char searchString[15];
	bool correct = false;
	char choice;
	
	char newNumber[15];
	char newName[35];
	char newDesc[200];
	int newQuantity;
	
	bool found = false;
	int i = 0;

	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                              Inventory Editor\n";
	cout<<" ------------------------------------------------------------------------------\n\n";

	cout<<"Enter item number to edit: ";
	cin.getline(searchString, 15, '\n');
	
	while(!found && i<numStruct)
	{
		if(!strcmp(pItem->itemNumber, searchString))
		{
			found=true;
			break;
		}
		i++;
		pItem++;
	}
	if(i == numStruct)
		cout<<endl<<"No matching item was found"<<endl<<endl;
	else
	{
		
			system("cls");
			cout<<" ------------------------------------------------------------------------------\n";
			cout<<"                              Inventory Editor\n";
			cout<<" ------------------------------------------------------------------------------\n\n";
			cout<<"        Item Name: "<<pItem->itemName<<endl<<endl;
			cout<<"      Item Number: "<<pItem->itemNumber<<endl<<endl;
			cout<<" Item Description: "<<pItem->itemDesc<<endl<<endl;
			cout<<"    Item Quantity: "<<pItem->itemQuantity<<endl<<endl<<endl;
			
			while(!correct){
				cout<<"Enter new item name: ";
				cin.getline(newName, 35, '\n');
			
				cout<<"Enter new item number: ";
				cin.getline(newNumber, 15, '\n');
			
				cout<<"Enter new item description: ";
				cin.getline(newDesc, 200, '\n');
				
				cout<<"Enter new item quantity: ";
				cin>>newQuantity;
				cin.ignore(999,'\n');
				
				while(cin.fail())
				{
					cout<<"Input invalid."<<endl;
					cin.clear();
					cin.ignore(999,'\n');
					cout<<"Enter new item quantity: ";
					cin>>newQuantity;
				}
				
				system("cls");
				cout<<" ------------------------------------------------------------------------------\n";
				cout<<"                              Inventory Editor\n";
				cout<<" ------------------------------------------------------------------------------\n\n";
				cout<<"        Item Name: "<<newName<<endl<<endl;
				cout<<"      Item Number: "<<newNumber<<endl<<endl;
				cout<<" Item Description: "<<newDesc<<endl<<endl;
				cout<<"    Item Quantity: "<<newQuantity<<endl<<endl<<endl;
				
				cout<<"Does this look correct? (y|n)";
				cin>>choice;
				
				if(choice == 'y')
					{
						correct = true;
						
						strcpy(pItem->itemName , newName);
						strcpy(pItem->itemNumber , newNumber);
						strcpy(pItem->itemDesc , newDesc);
						pItem->itemQuantity = newQuantity;
						cout<<endl;
						
					}
				else if(choice == 'n')
					{
						correct = false;
						system("cls");
						cout<<" ------------------------------------------------------------------------------\n";
						cout<<"                              Inventory Editor\n";
						cout<<" ------------------------------------------------------------------------------\n\n";
						cout<<"        Item Name: "<<pItem->itemName<<endl<<endl;
						cout<<"      Item Number: "<<pItem->itemNumber<<endl<<endl;
						cout<<" Item Description: "<<pItem->itemDesc<<endl<<endl;
						cout<<"    Item Quantity: "<<pItem->itemQuantity<<endl<<endl<<endl;
					}
				else
					{
						correct = false;
						cout<<"There was an error. Please try again."<<endl;
					}
				cin.get();
	
			}
	}

	system("pause");
}

void displayAllItems(item* pItem){
	
	int count = 0;

	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                               Inventory Summary\n";
	cout<<" ------------------------------------------------------------------------------\n\n";

	for(int i = 0; i < numStruct; i++)
	{
		if(i!=0 && i%2==0){
			system("pause");
			system("cls");
			cout<<" ------------------------------------------------------------------------------\n";
			cout<<"                               Inventory Summary\n";
			cout<<" ------------------------------------------------------------------------------\n\n";
		}
		
		cout<<"        Item Name: "<<pItem->itemName<<endl<<endl;
		cout<<"      Item Number: "<<pItem->itemNumber<<endl<<endl;
		cout<<" Item Description: "<<pItem->itemDesc<<endl<<endl;
		cout<<"    Item Quantity: "<<pItem->itemQuantity<<endl<<endl;
		cout<<" ------------------------------------------------------------------------------\n\n";
		
		pItem++;
	}

	system("pause");	
}

void genDummyData(item* pItem){
		
		strcpy(pItem->itemNumber , "abc123");
		strcpy(pItem->itemName ,"abc 123");
		strcpy(pItem->itemDesc ,"If dev c++ was a real person");
		pItem->itemQuantity = 1;
		
		pItem++;
		
		strcpy(pItem->itemNumber , "def456");
		strcpy(pItem->itemName ,"def 456");
		strcpy(pItem->itemDesc ,"I would punch them in the throat.");
		pItem->itemQuantity = 2;
		
		pItem++;
		
		strcpy(pItem->itemNumber , "ghi789");
		strcpy(pItem->itemName ,"ghi 789");
		strcpy(pItem->itemDesc ,"OMG!!1!1!wtfBBQHAX  I did it for the lulz.");
		pItem->itemQuantity = 3;
}
