//David Walker
//Project 4

#include <iostream>
#include <iomanip>
#include <string.h>
#include <new>
#include <fstream>

using namespace std;

struct item{
	char itemNumber[15]; //assuming the SKU could be alphanumeric.
	char itemName[35];
	char itemDesc[200];
	int itemQuantity;
};

void readData(ifstream& inDataFile, int& numStruct, item*& pItem);
void writeData(ofstream& outDataFile, int numStruct, item*& pItem);

int displayMenu();
void displaySingleItem(item* pItem, int numStruct);
void editItem(item* pItem, int numStruct, ofstream& outDataFile);
void addItem(item*& pItem, int& numStruct, ofstream& outDataFile);
void displayAllItems(item* pItem, int numStruct);
void delItem(item*& pItem, int& numStruct, ofstream& outDataFile);

bool isDupe(char searchString[], item* pItem, int numStruct);

int main(void){
	
	ifstream inDataFile;
	ofstream outDataFile;
	
	int numStruct;
	int menuSelection;
	
	bool running = true;
	
	item* pItem;
	readData( inDataFile, numStruct, pItem);

	while(running){
		menuSelection = displayMenu();
		switch(menuSelection){
			case 1:
				displaySingleItem(pItem, numStruct);
				break;
			case 2:
				editItem(pItem, numStruct, outDataFile);
				break;
			case 3:
				displayAllItems(pItem, numStruct);
				break;
			case 4:
				addItem(pItem, numStruct, outDataFile);
				break;
			case 5:
				delItem(pItem, numStruct, outDataFile);
				break;
			case 6:
				running = false;
				break;
			default: 
				cout<<endl<<"Input invalid."<<endl<<endl;
				system("pause");
				break;
		}
	}
}

int displayMenu(){
	
	int selection;
	char temp[200];
	
	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                           Inventory Management Menu\n";
	cout<<" ------------------------------------------------------------------------------\n\n";
	cout<<"                        1 - Display an items information.\n\n";
	cout<<"                        2 - Edit an items information.\n\n";
	cout<<"                        3 - Display all items.\n\n";
	cout<<"                        4 - Add an item.\n\n";
	cout<<"                        5 - Delete an item.\n\n";
	cout<<"                        6 - Exit program.\n\n\n";
	cout<<"Select an option: ";
 
	cin.getline(temp, 20);
	
	while(cin.fail()){
	
		cout<<endl<<"Input invalid."<<endl;
		cin.clear();
		cin.sync();
		cout<<endl<<"Select an option: ";
		cin.getline(temp, 20);
	}
	
	cin.clear();
	cin.sync();
	
	selection = atoi(temp);
		
	return selection;
}

void displaySingleItem(item* pItem, int numStruct){
	
	char searchString[15];
	bool found = false;
	int i = 0;
	
	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                               Item Information\n";
	cout<<" ------------------------------------------------------------------------------\n\n";

	cout<<"Enter item number to search for: ";
	cin.getline(searchString, 15);
	
	while(cin.fail() || searchString[0]=='\0'){
		cout<<endl<<"Input invalid."<<endl;
		cin.clear();
		cin.sync();
		cout<<endl<<"Enter item number to search for: ";
		cin.getline(searchString, 15);
	}
	
	cin.clear();
	cin.sync();
	
	while(!found && i<numStruct){
		if(!strcmp(pItem->itemNumber, searchString)){
			found=true;
		}
		else{
			i++;
			pItem++;
		}
	}
	if(found){
		system("cls");
		cout<<" ------------------------------------------------------------------------------\n";
		cout<<"                               Item Information\n";
		cout<<" ------------------------------------------------------------------------------\n\n";
		cout<<"        Item Name: "<<pItem->itemName<<endl<<endl;
		cout<<"      Item Number: "<<pItem->itemNumber<<endl<<endl;
		cout<<" Item Description: "<<pItem->itemDesc<<endl<<endl;
		cout<<"    Item Quantity: "<<pItem->itemQuantity<<endl<<endl<<endl;
	}
	else{
		cout<<endl<<"No matching item was found"<<endl<<endl;
	}
	system("pause");
}

void editItem(item* pItem, int numStruct, ofstream& outDataFile){

	char searchString[15];
	bool correct = false;
	char choice;
	
	char newNumber[15];
	char newName[35];
	char newDesc[200];
	int newQuantity = -1;
	
	bool found = false;
	int i = 0;

	item* pWalk = pItem;

	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                              Inventory Editor\n";
	cout<<" ------------------------------------------------------------------------------\n\n";

	cout<<"Enter item number to edit: ";
	cin.getline(searchString, 15);
	
	while(cin.fail()  || searchString[0]=='\0'){
		cout<<endl<<"Input invalid."<<endl;
		cin.clear();
		cin.sync();
		cout<<endl<<"Enter item number to edit: ";
		cin.getline(searchString, 15);
	}
	
	cin.clear();
	cin.sync();
	
	while(!found && i<numStruct)
	{
		if(!strcmp(pWalk->itemNumber, searchString))
		{
			found=true;	
		}
		else{
			i++;
			pWalk++;
		}
	}
	if(found){
		system("cls");
			cout<<" ------------------------------------------------------------------------------\n";
			cout<<"                              Inventory Editor\n";
			cout<<" ------------------------------------------------------------------------------\n\n";
			cout<<"        Item Name: "<<pWalk->itemName<<endl<<endl;
			cout<<"      Item Number: "<<pWalk->itemNumber<<endl<<endl;
			cout<<" Item Description: "<<pWalk->itemDesc<<endl<<endl;
			cout<<"    Item Quantity: "<<pWalk->itemQuantity<<endl<<endl<<endl;
			
			while(!correct){
				cout<<"Enter new item name: ";
				cin.getline(newName, 35);
				
				while(cin.fail() || newName[0]=='\0'){
					cout<<endl<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<endl<<"Enter new item name: ";
					cin.getline(newName, 35);
				}
				
				cin.clear();
				cin.sync();
		
				cout<<"Enter new item number: ";
				cin.getline(newNumber, 15, '\n');
				
				while(cin.fail() || newNumber[0]=='\0'){
					cout<<endl<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<endl<<"Enter new item number: ";
					cin.getline(newNumber, 15, '\n');
				}
				
				cin.clear();
				cin.sync();
		
				cout<<"Enter new item description: ";
				cin.getline(newDesc, 200, '\n');
				
				while(cin.fail() || newDesc[0]=='\0'){
					cout<<endl<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<endl<<"Enter new item description: ";
					cin.getline(newDesc, 200, '\n');
				}
				
				cin.clear();
				cin.sync();
		
				cout<<"Enter new item quantity: ";
				cin>>noskipws>>newQuantity;
				
				
				while(cin.fail() || newQuantity == -1)
				{
					cout<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<"Enter new item quantity: ";
					cin>>noskipws>>newQuantity;
				}
				
				cin.clear();
				cin.sync();
				
				system("cls");
				cout<<" ------------------------------------------------------------------------------\n";
				cout<<"                              Inventory Editor\n";
				cout<<" ------------------------------------------------------------------------------\n\n";
				cout<<"        Item Name: "<<newName<<endl<<endl;
				cout<<"      Item Number: "<<newNumber<<endl<<endl;
				cout<<" Item Description: "<<newDesc<<endl<<endl;
				cout<<"    Item Quantity: "<<newQuantity<<endl<<endl<<endl;
				
				cout<<"Does this look correct? (y|n)";
				cin>>noskipws>>choice;
				
				if(choice == 'y')
					{
						correct = true;
						
						strcpy(pWalk->itemName , newName);
						strcpy(pWalk->itemNumber , newNumber);
						strcpy(pWalk->itemDesc , newDesc);
						pWalk->itemQuantity = newQuantity;
						
						writeData(outDataFile, numStruct, pItem);
						
						cout<<endl;	
					}
				else
					{
						correct = false;
						system("cls");
						cout<<" ------------------------------------------------------------------------------\n";
						cout<<"                              Inventory Editor\n";
						cout<<" ------------------------------------------------------------------------------\n\n";
						cout<<"        Item Name: "<<pWalk->itemName<<endl<<endl;
						cout<<"      Item Number: "<<pWalk->itemNumber<<endl<<endl;
						cout<<" Item Description: "<<pWalk->itemDesc<<endl<<endl;
						cout<<"    Item Quantity: "<<pWalk->itemQuantity<<endl<<endl<<endl;
					}
				cin.clear();
				cin.sync();
			}
	}
	else
	{
		cout<<endl<<"No matching item was found"<<endl<<endl;
	}
	system("pause");
}

void displayAllItems(item* pItem, int numStruct){
	
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

void addItem(item*& pItem, int& numStruct, ofstream& outDataFile){

	bool correct = false;
	char choice;
	
	char newNumber[15];
	char newName[35];
	char newDesc[200];
	int newQuantity = -1;
	
	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                            Add Inventory Item\n";
	cout<<" ------------------------------------------------------------------------------\n\n";
			
	while(!correct){
		cout<<"Enter new item name: ";
		cin.getline(newName, 35);
		
		while(cin.fail()  || newName[0]=='\0'){
			cout<<endl<<"Input invalid."<<endl;
			cin.clear();
			cin.sync();
			cout<<endl<<"Enter new item name: ";
			cin.getline(newName, 35);
		}
		
		cin.clear();
		cin.sync();
		
		if(isDupe(newName, pItem, numStruct)){
			cout << endl << "This item already exists."<< endl << endl;
			continue;
		}
	
		cout<<"Enter new item number: ";
				cin.getline(newNumber, 15, '\n');
				
				while(cin.fail() || newNumber[0]=='\0'){
					cout<<endl<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<endl<<"Enter new item number: ";
					cin.getline(newNumber, 15, '\n');
				}
				
				cin.clear();
				cin.sync();
		
				cout<<"Enter new item description: ";
				cin.getline(newDesc, 200, '\n');
				
				while(cin.fail() || newDesc[0]=='\0'){
					cout<<endl<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<endl<<"Enter new item description: ";
					cin.getline(newDesc, 200, '\n');
				}
				
				cin.clear();
				cin.sync();
		
				cout<<"Enter new item quantity: ";
				cin>>noskipws>>newQuantity;
				
				
				while(cin.fail() || newQuantity == -1)
				{
					cout<<"Input invalid."<<endl;
					cin.clear();
					cin.sync();
					cout<<"Enter new item quantity: ";
					cin>>noskipws>>newQuantity;
				}
				
				cin.clear();
				cin.sync();
		
		system("cls");
		cout<<" ------------------------------------------------------------------------------\n";
		cout<<"                            Add Inventory Item\n";
		cout<<" ------------------------------------------------------------------------------\n\n";
		cout<<"        Item Name: "<<newName<<endl<<endl;
		cout<<"      Item Number: "<<newNumber<<endl<<endl;
		cout<<" Item Description: "<<newDesc<<endl<<endl;
		cout<<"    Item Quantity: "<<newQuantity<<endl<<endl<<endl;
		
		cout<<"Does this look correct? (y|N)";
		cin>>noskipws>>choice;
		
		if(choice == 'y'){
			correct = true;
			
			item* tempItem;
			tempItem = new(nothrow) item[numStruct +1];
			if(tempItem == nullptr){
				cout << "There was a problem." << endl;
				system("pause");
				exit(1);
			}
			item* tempWalk = tempItem;
			item* pWalk = pItem;
			
			for( int i = 0; i < numStruct; i++){
				strcpy(tempWalk->itemNumber , pWalk->itemNumber );
				strcpy(tempWalk->itemName, pWalk->itemName);
				strcpy(tempWalk->itemDesc, pWalk->itemDesc);
				tempWalk->itemQuantity = pWalk->itemQuantity;
				tempWalk++;
				pWalk++;
			}
			strcpy(tempWalk->itemName , newName);
			strcpy(tempWalk->itemNumber , newNumber);
			strcpy(tempWalk->itemDesc , newDesc);
			tempWalk->itemQuantity = newQuantity;

			delete [] pItem;					
			pItem = tempItem;
			tempItem = nullptr;
			
			numStruct++;
			writeData(outDataFile, numStruct, pItem);
			cout<<"Data successfully written."<<endl;				
			cout<<endl;
		}
		else{
			correct = false;
			system("cls");
			cout<<" ------------------------------------------------------------------------------\n";
			cout<<"                            Add Inventory Item\n";
			cout<<" ------------------------------------------------------------------------------\n\n";
		}
		cin.clear();
		cin.sync();
	}
	system("pause");
}

void delItem(item*& pItem, int& numStruct, ofstream& outDataFile){

	bool correct = false;
	char choice;
	
	char searchString[15];
	bool found = false;
	int i = 0 ;
	item* pWalk1 = pItem;
	
	system("cls");
	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                          Delete Inventory Item\n";
	cout<<" ------------------------------------------------------------------------------\n\n";
		
			
	cout<<"Enter item number to delete: ";
	cin.getline(searchString, 15);
	
	while(cin.fail() || searchString[0]=='\0')
	{
		cout<<endl<<"Input invalid."<<endl;
		cin.clear();
		cin.sync();
		cout<<"Enter item number to delete: ";
		cin.getline(searchString, 15);
	}
	
	cin.clear();
	cin.sync();
		
	while(!found && i<numStruct)
	{
		if(!strcmp(pWalk1->itemNumber, searchString))
		{
			found=true;
		}
		else
		{
			i++;
			pWalk1++;
		}
	}
	
	if(found)
	{
		system("cls");
		cout<<" ------------------------------------------------------------------------------\n";
		cout<<"                          Delete Inventory Item\n";
		cout<<" ------------------------------------------------------------------------------\n\n";
		cout<<"        Item Name: "<<pWalk1->itemName<<endl<<endl;
		cout<<"      Item Number: "<<pWalk1->itemNumber<<endl<<endl;
		cout<<" Item Description: "<<pWalk1->itemDesc<<endl<<endl;
		cout<<"    Item Quantity: "<<pWalk1->itemQuantity<<endl<<endl<<endl;

		cout<<"Really delete this item? (y|N)";
		cin>>noskipws>>choice;
		
		if(choice == 'y')
		{
							
			item* tempItem;
			tempItem = new(nothrow) item[numStruct -1];
			if(tempItem == nullptr){
				cout << "There was a problem." << endl;
				system("pause");
				exit(1);
			}
			item* tempWalk = tempItem;
			item* pWalk2 = pItem;
				
			for( int i = 0; i < numStruct; i++){
					
					if(pWalk2->itemNumber == pWalk1->itemNumber)
					{
						pWalk2++;
					}
					else
					{
						strcpy(tempWalk->itemNumber , pWalk2->itemNumber );
						strcpy(tempWalk->itemName, pWalk2->itemName);
						strcpy(tempWalk->itemDesc, pWalk2->itemDesc);
						tempWalk->itemQuantity = pWalk2->itemQuantity;
						tempWalk++;
						pWalk2++;
					}
					
			}
				
	
			delete [] pItem;					
			pItem = tempItem;
			tempItem = nullptr;
				
			numStruct--;
			writeData(outDataFile, numStruct, pItem);
			cout<<"Data successfully written."<<endl;				
			cout<<endl;
		}
		else
		{

			system("cls");
			cout<<" ------------------------------------------------------------------------------\n";
			cout<<"                          Delete Inventory Item\n";
			cout<<" ------------------------------------------------------------------------------\n\n\n";
			
			cout<<"                             No Item Deleted\n\n";

		}
	}
	else
	{
		cout<<endl<<"No matching item was found"<<endl<<endl;
	}

	cin.clear();
	cin.sync();
	
	system("pause");
}

void readData(ifstream& inDataFile, int& numStruct, item*& pItem){
		
	inDataFile.open("inv.dat");
	if(inDataFile.fail()){
		cout << "Error opening inventory data file." << endl;
		system("pause");
		exit(1);
	}
	
	inDataFile >> numStruct;
    inDataFile.ignore();
    
    pItem = new(nothrow) item[numStruct];
	if(pItem == nullptr){
		cout << "There was a problem." << endl;
		system("pause");
		exit(1);
	}
	
	item* pWalk = pItem;
	
	for( int i = 0; i < numStruct; i++){
		inDataFile.getline(pWalk->itemNumber, 15);
		inDataFile.getline(pWalk->itemName, 35);
		inDataFile.getline(pWalk->itemDesc, 200);
		inDataFile >> pWalk->itemQuantity;
		inDataFile.ignore();
		pWalk++;
	}
	
	inDataFile.close();
}

void writeData(ofstream& outDataFile, int numStruct, item*& pItem){

	outDataFile.open("inv.dat");
	if(outDataFile.fail()){
		cout << "Error writing to inventory data file." << endl;
		system("pause");
		exit(1);
	}
	
	item* pWalk = pItem;
	
	outDataFile << numStruct << endl;
	
	for( int i = 0; i < numStruct; i++){
		outDataFile << pWalk->itemNumber << endl;
		outDataFile << pWalk->itemName << endl;
		outDataFile << pWalk->itemDesc << endl;
		outDataFile << pWalk->itemQuantity << endl;
		pWalk++;
	}
	
	outDataFile.close();
}

bool isDupe(char searchString[],item* pItem, int numStruct ){
	
	bool found = false;
	int i = 0;
	
	while(!found && i<numStruct){
		if(!strcmp(pItem->itemNumber, searchString)){
			found=true;
		}
		else{
			i++;
			pItem++;
		}
	}	
	
	return found;
}
