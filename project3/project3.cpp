#include <iostream>

char displayMenu();

void displaySingleItem();
void editItem();
void displayAllItems();

using namespace std;




int main(void){
	
	char menuSelection = 0;
	bool running = true;
	
	while(running){
		menuSelection = displayMenu();
		
		switch(menuSelection){
			case '1':
				displaySingleItem();
				break;
				
			case '2':
				editItem();
				break;
				
			case '3':
				displayAllItems();
				break;
			
			case '4':
				running = false;
				break;
		}
	}
}



char displayMenu(){
	
	char selection;

	system("cls");

	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                           Inventory Management Menu\n";
	cout<<" ------------------------------------------------------------------------------\n\n\n";
	cout<<"                        1 - Display an items information.\n\n";
	cout<<"                        2 - Edit an items information.\n\n";
	cout<<"                        3 - Display all items.\n\n";
	cout<<"                        4 - Exit program.\n\n\n";
	cout<<"Select an option: ";
	
	cin>>selection;

	return selection;	
}

void displaySingleItem(){
	
	char selection;
	int itemNumber;

	system("cls");

	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                             Inventory Information\n";
	cout<<" ------------------------------------------------------------------------------\n\n\n";

	cout<<"Enter item number: ";

//	cout<<"                        1 - Display an items information.\n\n";
//	cout<<"                        2 - Edit an items information.\n\n";
//	cout<<"                        3 - Display all items.\n\n";
//	cout<<"                        4 - Exit program.\n\n\n";
//	cout<<"Select an option: ";
//	
//	cin>>selection;

	system("pause");
}

void editItem(){

	char selection;
	int itemNumber;

	system("cls");

	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                              Inventory Editor\n";
	cout<<" ------------------------------------------------------------------------------\n\n\n";
	
	cout<<"Enter item number to edit: ";
	cin>>itemNumber;
	
	cout<<"you entered "<<itemNumber;
	system("pause");
	
//	cout<<"                        1 - Display an items information.\n\n";
//	cout<<"                        2 - Edit an items information.\n\n";
//	cout<<"                        3 - Display all items.\n\n";
//	cout<<"                        4 - Exit program.\n\n\n";
//	cout<<"Select an option: ";
	
//	cin>>selection;
}

void displayAllItems(){
	
	char selection;
	int itemNumber;

	system("cls");

	cout<<" ------------------------------------------------------------------------------\n";
	cout<<"                         Inventory Information Summary\n";
	cout<<" ------------------------------------------------------------------------------\n\n\n";


//	cout<<"                        1 - Display an items information.\n\n";
//	cout<<"                        2 - Edit an items information.\n\n";
//	cout<<"                        3 - Display all items.\n\n";
//	cout<<"                        4 - Exit program.\n\n\n";
//	cout<<"Select an option: ";
//	
//	cin>>selection;

	system("pause");	
}
