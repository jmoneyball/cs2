/* ***did not do any extra credit
 * Program Name: cs2 final
 * Author: Jordan Johnson
 * IDE Used: Eclipse
 * Program description: simulates a management system for a video store
 */

//preprocessor directives
#include <fstream>
#include <vector>
#include "customer.h"
#include "video.h"

//function prototypes
int mainMenu();
void checkOut(vector<Customer>, vector<Video>&);
void checkIn(vector<Customer>, vector<Video>&);
void runReports(vector<Customer>, vector<Video>);
void overdueReport(vector<Customer>, vector<Video>);
void manageInv(vector<Video>&);
void manageCust(vector<Customer>&, vector<Video>);
void plagiarismPledge();

//main function
int main() {
	//opens files
	ifstream finC("customers.txt");
	ifstream finV("videos.txt");
	//object containers
	vector<Customer> customers;
	vector<Video> videos;
	//temporary storage
	string lName, fName; //customer class
	int custNr;
	string title; //video class
	int inventoryNumber, customer;
	bool checkedOut, overdue;

	//reads customer file
	while(finC >> lName) {
		finC >> fName;
		finC >> custNr;
		Customer tempCustomer(custNr, lName, fName);
		customers.push_back(tempCustomer);
	}
	//reads video file
	while(getline(finV, title)) {
		finV >> inventoryNumber >> checkedOut >> overdue >> customer;
		finV.ignore();
		Video tempVideo(title, inventoryNumber, checkedOut, overdue, customer);
		videos.push_back(tempVideo);
	}

	//main menu
	bool repeat = true;
	do {
		int choice = mainMenu();
		switch(choice)
		{
		case 1:
			checkOut(customers, videos);
			break;
		case 2:
			checkIn(customers, videos);
			break;
		case 3:
			runReports(customers, videos);
			break;
		case 4:
			manageInv(videos);
			break;
		case 5:
			manageCust(customers, videos);
			break;
		case 6:
			repeat = false;
			break;
		}
	} while(repeat == true);

	//ends program
	finC.close(); finV.close();
	plagiarismPledge();
	return(0);
}

//function that outputs the main menu and returns the user's choice for the menu
int mainMenu() {
	cout << "***VIDEO STORE MAIN MENU***\n"
		 << "[1] Check out videos\n"
		 << "[2] Check in videos\n"
		 << "[3] Run reports\n"
		 << "[4] Manage inventory\n"
		 << "[5] Manage customers\n"
		 << "[6] Quit\n"
		 << ">>> ";
	int choice; cin >> choice;
	while(choice < 1 || choice > 6) {
		cerr << "ERROR... choose an option 1-6\n>>> ";
		cin >> choice;
	}
	cout << endl;
	return(choice);
}

//function to check videos out from the system
void checkOut(vector<Customer> customers, vector<Video> &videos) {
	//declarations
	int vidChoice, custChoice;
	vector<Video> tempVideo;
	//checkOut video options
	for(int i = 0; i < videos.size(); i++)
		if(videos[i].getCheckedOut() == false)
			tempVideo.push_back(videos[i]);
	cout << "***VIDEO CHECK-OUT***\n"
		 << "Select video to check out:\n";
	for(int j = 0; j < tempVideo.size(); j++) {
		cout << '[' << j+1 << "] "
			 << tempVideo[j].getInvNr() << ' '
			 << tempVideo[j].getTitle() << endl;
	}
	if(tempVideo.size() == 0) cout << "No videos available...\n"; //let user know if no videos are available
	cout << '[' << tempVideo.size()+1 << "] Cancel and return to main menu\n"
		 << ">>> ";
	cin >> vidChoice;
	while(vidChoice < 1 || vidChoice > (tempVideo.size()+1)) {
		cerr << "ERROR... choose an option 1-" << tempVideo.size()+1 << "\n>>> ";
		cin >> vidChoice;
	}
	cout << endl;
	//returns to main menu if selected
	if(vidChoice == tempVideo.size()+1) return;
	//checkOut customer options
	cout << "Choose the customer that rented this title:\n";
	for(int k = 0; k < customers.size(); k++) {
		cout << '[' << k+1 << "] " << customers[k].getLName() << ", "
			 << customers[k].getFName() << " (" << customers[k].getCustNr() << ')' << endl;
	}
	cout << ">>> ";
	cin  >> custChoice;
	while(custChoice < 1 || custChoice > customers.size()) {
		cerr << "ERROR... choose an option 1-" << customers.size() << "\n>>> ";
		cin >> custChoice;
	}
	//updates video information in vector
	for(int l = 0; l < videos.size(); l++) {
		if(videos[l].getTitle() == tempVideo[vidChoice-1].getTitle()) {
			videos[l].setCheckedOut(true);
			videos[l].setCustomer(custChoice-1);
		}
	}
	cout << "Video checked out!\n\n";
}

//function to check videos into the system
void checkIn(vector<Customer> customers, vector<Video> &videos) {
	//declarations
	int vidChoice;
	vector<Video> tempVideo;
	//checkIn video options
	for(int i = 0; i < videos.size(); i++)
		if(videos[i].getCheckedOut() == true)
			tempVideo.push_back(videos[i]);
	cout << "***VIDEO CHECK-IN***\n"
		 << "Select video to check in:\n";
	for(int j = 0; j < tempVideo.size(); j++) {
		cout << '[' << j+1 << "] "
			 << tempVideo[j].getInvNr() << ' '
			 << tempVideo[j].getTitle() << endl;
	}
	//let user know if no videos are available
	if(tempVideo.size() == 0) cout << "No videos available...\n";
	//gets user input
	cout << '[' << tempVideo.size()+1 << "] Cancel and return to main menu\n"
		 << ">>> ";
	cin >> vidChoice;
	while(vidChoice < 1 || vidChoice > (tempVideo.size()+1)) {
		cerr << "ERROR... choose an option 1-" << tempVideo.size()+1 << "\n>>> ";
		cin >> vidChoice;
	}
	if(vidChoice == tempVideo.size()+1) { cout << endl; return; } //returns to main menu if selected
	//updates video information in vector
	for(int k = 0; k < videos.size(); k++) {
		if(videos[k].getTitle() == tempVideo[vidChoice-1].getTitle()) {
			videos[k].setCheckedOut(false);
			videos[k].setCustomer(0);
		}
	}
	cout << "Video checked in!\n\n";
}

//function that pulls up a menu to output reports about their business
void runReports(vector<Customer> customers, vector<Video> videos) {
	//declarations
	int choice;

	//runReports menu
	cout << "***RUN REPORTS***\n"
		 << "[1] Overdue video report\n"
		 << "[2] Cancel and return to main menu\n"
		 << ">>> ";
	cin  >> choice;
	while(choice < 1 || choice > 2) {
		cerr << "ERROR... choose an option 1-2\n>>> ";
		cin >> choice;
	}

	//run according to choice
	if(choice == 1) { cout << endl; overdueReport(customers, videos); }//overdue video report
	else if(choice == 2) { cout << endl; return; }//return to main menu
}

//function to output a list of videos that are marked as overdue
void overdueReport(vector<Customer> customers, vector<Video> videos) {
	cout << "***OVERDUE VIDEOS***\n";
	for(int i = 0; i < videos.size(); i++) {
		if(videos[i].getOverdue() == true) {
			int ID = videos[i].getCustomer();
			cout << "Inventory #: " << videos[i].getInvNr() << ' '
				 << "Title: " << videos[i].getTitle() << endl
				 << "\tCustomer #: " << videos[i].getCustomer() << " (";
			for(int j = 0; j < customers.size(); j++) {
				if(customers[j].getCustNr() == ID) {
				 cout << customers[j].getLName() << ", "
				      << customers[j].getFName() << ")\n";
				}
			}
		}
	}
	cout << endl;
}

//function to manage videos in the system (add, remove)
void manageInv(vector<Video> &videos) {
	//declarations
	int choice;
	//manageInv menu
	cout << "***MANAGE INVENTORY***\n"
		 << "[1] Add video to inventory\n"
		 << "[2] Remove video from inventory\n"
		 << "[3] Cancel and return to main menu\n"
		 << ">>> ";
	cin  >> choice;
	while(choice < 1 || choice > 3) {
		cerr << "ERROR... choose an option 1-3\n>>> ";
		cin >> choice;
	}
	//executes chosen option
	switch(choice) {
	case 1: { //add a video
		Video temp; //create temporary video object
		string title;
		int invNmr;
		//gets user input
		cout << "\n***ADDING VIDEO...***\n"
			 << "What is the title of the movie?\n>>> "; cin.ignore(); getline(cin, title);
		cout << "What is the 3-digit inventory number?\n>>> "; cin >> invNmr;
		while(invNmr < 100 || invNmr > 999) {
			cerr << "ERROR... choose a number 100-999\n>>> ";
			cin  >> invNmr;
		}
		//pushes temp video w/ data into vector
		temp.setTitle(title); temp.setInvNr(invNmr);
		videos.push_back(temp);
		cout << "Video added to inventory!\n\n";
		break;
	}
	case 2: { //remove a video
		//gets user input
		cout << "\n***REMOVING VIDEO...***\n"
			 << "Select a video to remove:\n";
		for(int i = 0; i < videos.size(); i++) {
			cout << '[' << i+1 << "] "
				 << videos[i].getInvNr() << ' '
				 << videos[i].getTitle() << endl;
		}
		cout << ">>> ";
		cin  >> choice;
		while(choice < 1 || choice > videos.size()) {
			cerr << "ERROR... choose an option 1-" << videos.size() << "\n>>> ";
			cin >> choice;
		}
		//removes video from vector
		videos.erase(videos.begin()+(choice-1));
		cout << "Video removed from inventory!\n\n";
		break;
	}
	case 3: //return to main menu
		cout << endl;
		return;
	}
}

//function to manage customers in the system (view, add, remove)
void manageCust(vector<Customer> &customers, vector<Video> videos) {
	//declarations
	int choice;
	//manageCust menu
	cout << "***MANAGE CUSTOMERS***\n"
		 << "[1] List customers\n"
		 << "[2] Add customer\n"
		 << "[3] Remove customer\n"
		 << "[4] Cancel and return to main menu\n"
		 << ">>> ";
	cin  >> choice;
	while(choice < 1 || choice > 4) {
		cerr << "ERROR... choose an option 1-4\n>>> ";
		cin >> choice;
	}
	//executes chosen option
	switch(choice) {
	case 1://list customers
		cout << "\n***LIST OF CUSTOMERS***\n";
		for(int i = 0; i < customers.size(); i++) {
			cout << '[' << i+1 << "] " << customers[i].getLName()
				 << ", " << customers[i].getFName() << " ("
				 << customers[i].getCustNr() << ")\n";
		}
		break;
	case 2: { //add customers
		string fName, lName;
		int custNr;
		//get user input
		cout << "\n***ADDING A CUSTOMER...***\n"
			 << "What is their first name?\n>>> "; cin.ignore(); getline(cin, fName);
		cout << "What is their last name?\n>>> "; getline(cin, lName);
		cout << "What is the 4-digit customer number?\n>>> "; cin >> custNr;
		while(custNr < 1000 || custNr > 9999) {
			cerr << "ERROR... choose a number 1000-9999\n>>> ";
			cin >> custNr;
		}
		//adds customer to list
		Customer temp(custNr, lName, fName);
		customers.push_back(temp);
		cout << "Customer added to list!\n";
		break;
	}
	case 3://remove customers
		//gets user input
		cout << "\n***REMOVING A CUSTOMER...***\n" << "Select a customer to remove:\n";
		for(int i = 0; i < customers.size(); i++) {
			cout << '[' << i+1 << "] " << customers[i].getLName()
				 << ", " << customers[i].getFName() << " ("
				 << customers[i].getCustNr() << ")\n";
		}
		cout << ">>> ";
		cin  >> choice;
		while(choice < 1 || choice > customers.size()) {
			cerr << "ERROR... choose an option 1-" << customers.size() << "\n>>> ";
			cin >> choice;
		}
		//removes customer
		for(int j = 0; j < videos.size(); j++) {
			if(customers[choice-1].getCustNr() == videos[j].getCustomer()) { //checks to see if they have any overdue books
				if(videos[j].getOverdue() == true) {
				cout << "Customer cannot be removed from the system\nuntil their overdue video(s) is returned.\n\n";
				return;
				}
			}
		}
		customers.erase(customers.begin()+(choice-1));
		cout << "Customer removed from list!\n";
		break;
	case 4://main menu
		break;
	}
	cout << endl;
}

//plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
//Arguments: none | Returns: void
void plagiarismPledge() {
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
}
