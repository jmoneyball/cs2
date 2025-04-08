/* Program Name: College Management System
 * Author: Jordan Johnson
 * IDE: Eclipse
 * Program description: college management system that allows user to
 * 						view and update attributes of people at the college
 */

//preprocessor directives
#include <vector>
#include <fstream>
#include "Professor.h"
#include "Staff.h"
#include "Graduate.h"
#include "Undergraduate.h"

//constants
const int SIZE = 0;

//function prototypes
template <class Type> void bubbleSort(vector <Type> &);
int mainMenu();
void viewDatabase(vector <Undergraduate>, int, vector <Graduate>, int,
				  vector <Staff>, int, vector <Professor>, int);
void editDatabase(vector <Undergraduate>&, int, vector <Graduate>&, int,
		  	  	  vector <Staff>&, int, vector <Professor>&, int);
void updateUndergrad(Undergraduate &);
void updateGrad(Graduate &);
void updateStaff(Staff &);
void updateProfessor(Professor &);
void plagiarismPledge();

//main function
int main()
{
	//declarations
	bool repeat = true;
	ifstream fin("input.txt");
	//general class declarations
	int classNum;
		/* determines which vector to place information
	 	 * read in from input file:
		 * undergrad - 1
		 * grad - 2
		 * staff - 3
		 * professor - 4
		 */
	string name;
	int age;
		//student declarations
		string major;
		float GPA;
			//graduate declarations
			vector <Graduate> vecGraduate(SIZE);
			int graduateIndex = 0;
			string goal;
			int gradYear;
			//undergraduate declarations
			vector <Undergraduate> vecUndergraduate(SIZE);
			int undergraduateIndex = 0;
			int year;
			int studentID;
		//employee declarations
		float salary;
		int employeeID;
		bool status;
			//staff declarations
			vector <Staff> vecStaff(SIZE);
			int staffIndex = 0;
			string position;
			//professor declarations
			vector <Professor> vecProfessor(SIZE);
			int professorIndex = 0;
			int roomNum;

	//reads from input file until all objects have been read
	while(fin >> classNum)
	{
		if (classNum == 1) //undergraduate
		{
			//reads undergraduate input data
			fin >> quoted(name) >> age >> GPA >> quoted(major) >> year >> studentID;
			//creates object using input data and adds to class vector
			Undergraduate tempU(name, age, GPA, major, year, studentID);
			vecUndergraduate.push_back(tempU);
			undergraduateIndex++;
		}
		else if (classNum == 2) //graduate
		{
			//reads graduate input data
			fin >> quoted(name) >> age >> GPA >> quoted(major) >> goal >> gradYear;
			//creates objects using input data and adds to class vector
			Graduate tempG(name, age, GPA, major, goal, gradYear);
			vecGraduate.push_back(tempG);
			graduateIndex++;
		}
		else if (classNum == 3) //staff
		{
			//reads staff input data
			fin >> quoted(name) >> age >> salary >> employeeID >> status >> quoted(position);
			//creates objects using input data and adds to class vector
			Staff tempS(name, age, salary, employeeID, status, position);
			vecStaff.push_back(tempS);
			staffIndex++;
		}
		else if (classNum == 4) //professor
		{
			//reads professor input data
			fin >> quoted(name) >> age >> salary >> employeeID >> status >> roomNum;
			//creates objects using input data and adds to class vector
			Professor tempP(name, age, salary, employeeID, status, roomNum);
			vecProfessor.push_back(tempP);
			professorIndex++;
		}
	}

	//sorts people in each vector by FIRST NAME
	bubbleSort(vecUndergraduate);
	bubbleSort(vecGraduate);
	bubbleSort(vecStaff);
	bubbleSort(vecProfessor);

	//main menu
	cout << "==============================\n"
		 << "Welcome! :)\n";
	do
	{
		int choice = mainMenu();
		switch(choice)
		{
			case 1:
				viewDatabase(vecUndergraduate, undergraduateIndex,
							 vecGraduate, graduateIndex,
							 vecStaff, staffIndex,
							 vecProfessor, professorIndex);
				break;
			case 2:
				editDatabase(vecUndergraduate, undergraduateIndex,
							 vecGraduate, graduateIndex,
							 vecStaff, staffIndex,
							 vecProfessor, professorIndex);
				break;
			case 3:
				repeat = false;
				cout << "==============================\n"
					 << "Thank you, program ending...\n"
					 <<	"==============================\n";
				break;
		}
	} while (repeat != false);

	//ends program
	plagiarismPledge();
	fin.close();
	return(0);
}

/* bubbleSort(): sorts the vector of objects by first name
 * Arguments: vector <Type> & | Returns: void
 */
template <class Type> void bubbleSort(vector <Type> &objVec)
{
    for (int maxElement = objVec.size() - 1; maxElement > 0; maxElement--)
        for (int index = 0; index < maxElement; index++)
            if (objVec[index].getName() > objVec[index + 1].getName())
            {
            	Type temp = objVec[index];
            	objVec[index] = objVec[index + 1];
            	objVec[index + 1] = temp;
            }
}

/* mainMenu(): outputs main menu options and returns user choice to main
 * Arguments: none | Returns: int
 */
int mainMenu()
{
	//declares choice
	int choice;

	//output of menu
	cout << "==============================\n"
		 << "Enter a number to continue:\n"
		 << "==============================\n"
		 << "  (1) View database info\n"
		 << "  (2) Edit database info\n"
		 << "  (3) Quit\n"
		 << "==============================\n"
		 << "    > ";
	//gets choice
	cin  >> choice;
	//choice input validation
	while (choice < 1 || choice > 3)
	{
		cout << "    > ERROR... please input a number 1-3 only.\n"
			 << "    > ";
		cin  >> choice;
	}

	//returns choice to main
	return choice;
}

/* viewDatabase(): drives the "view database" selection of the main menu
 * Arguments: vector <Undergraduate>, int, vector <Graduate>, int,
			  vector <Staff>, int, vector <Professor>, int
 * Returns: void
 */
void viewDatabase(vector <Undergraduate> undergrad, int undergradIndex, vector <Graduate> grad, int gradIndex,
				  vector <Staff> staff, int staffIndex, vector <Professor> prof, int profIndex)
{
	//declarations
	int choice, subChoice1, subChoice2;
	bool repeat = true;

	do
	{
		bool subRepeat1 = true; //reinitializes bool variable

		cout << "==============================\n"
			 << "Please select a group to view:\n"
			 << "==============================\n"
			 << "  (1) Students\n"
			 << "  (2) Employees\n"
			 << "  (3) View all people\n"
			 << "  (4) Return to main menu\n"
			 << "==============================\n"
			 << "    > ";
		cin  >> choice;
		//choice input validation
		while (choice < 1 || choice > 4)
		{
			cout << "    > ERROR... please input a number 1-4 only.\n"
				 << "    > ";
			cin  >> choice;
		}

		//group selection menu
		switch(choice)
		{
			case 1: //student sub menu
				do
				{
					bool subRepeat2 = true; //reinitializes bool variable

					cout << "==============================\n"
						 << "Select a student filter:\n"
						 << "==============================\n"
						 << "  (1) Undergraduate students\n"
						 << "  (2) Graduate students\n"
						 << "  (3) View all students\n"
						 << "  (4) Return to last page\n"
						 << "==============================\n"
						 << "    > ";
					cin  >> subChoice1;
					//subChoice1 input validation
					while (subChoice1 < 1 || subChoice1 > 4)
					{
						cout << "    > ERROR... please input a number 1-4 only.\n"
							 << "    > ";
						cin  >> subChoice1;
					}

					//student filter menu
					switch(subChoice1)
					{
						case 1: //undergrad filter menu
							do
							{
								cout << "==============================\n"
									 << "Select an undergraduate filter:\n"
									 << "==============================\n"
									 << "  (1) Year 1\n"
									 << "  (2) Year 2\n"
									 << "  (3) Year 3\n"
									 << "  (4) Year 4\n"
									 << "  (5) View all undergraduates\n"
									 << "  (6) Return to last page\n"
									 << "==============================\n"
									 << "    > ";
								cin  >> subChoice2;
								//subChoice2 input validation
								while (subChoice2 < 1 || subChoice2 > 6)
								{
									cout << "    > ERROR... please input a number 1-6 only.\n"
										 << "    > ";
									cin  >> subChoice2;
								}

								//subChoice2 outputs
								switch(subChoice2)
								{
									case 1: //year 1
										cout << "==============================\n"
											 << "Year 1 undergraduate students:\n"
											 << "==============================\n";
										for (int i = 0; i < undergradIndex; i++)
										{
											if (undergrad[i].getYear() == 1) //if undergrad year == 1
											{
												cout << "------------------------------\n";
												undergrad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 2: //year 2
										cout << "==============================\n"
											 << "Year 2 undergraduate students:\n"
											 << "==============================\n";
										for (int i = 0; i < undergradIndex; i++)
										{
											if (undergrad[i].getYear() == 2) //if undergrad year == 2
											{
												cout << "------------------------------\n";
												undergrad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 3: //year 3
										cout << "==============================\n"
											 << "Year 3 undergraduate students:\n"
											 << "==============================\n";
										for (int i = 0; i < undergradIndex; i++)
										{
											if (undergrad[i].getYear() == 3) //if undergrad year == 3
											{
												cout << "------------------------------\n";
												undergrad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 4: //year 4
										cout << "==============================\n"
											 << "Year 4 undergraduate students:\n"
											 << "==============================\n";
										for (int i = 0; i < undergradIndex; i++)
										{
											if (undergrad[i].getYear() == 4) //if undergrad year == 4
											{
												cout << "------------------------------\n";
												undergrad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 5: //view all undergraduates
										cout << "==============================\n"
											 << "Undergraduate Students:\n"
											 << "==============================\n";
										for (int i = 0; i < undergradIndex; i++)
										{
											cout << "------------------------------\n";
											undergrad[i].print();
											cout << "------------------------------\n";
										}
										break;
									case 6: //return to last page
										subRepeat2 = false;
										break;
								}
							} while (subRepeat2 != false);
							break;
						case 2: //grad submenu
							do
							{
								cout << "==============================\n"
									 << "Select an graduate filter:\n"
									 << "==============================\n"
									 << "  (1) Associate's degree\n"
									 << "  (2) Bachelor's degree\n"
									 << "  (3) Master's degree\n"
									 << "  (4) Doctorate degree\n"
									 << "  (5) View all graduates\n"
									 << "  (6) Return to last page\n"
									 << "==============================\n"
									 << "    > ";
								cin  >> subChoice2;
								//subChoice2 input validation
								while (subChoice2 < 1 || subChoice2 > 6)
								{
									cout << "    > ERROR... please input a number 1-6 only.\n"
										 << "    > ";
									cin  >> subChoice2;
								}

								//subChoice2 outputs
								switch(subChoice2)
								{
									case 1: //associates
										cout << "==============================\n"
											 << "Grads w/ Associate's degree:\n"
											 << "==============================\n";
										for (int i = 0; i < gradIndex; i++)
										{
											if (grad[i].getGoal() == "Associate's") //if goal == associate's deg
											{
												cout << "------------------------------\n";
												grad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 2: //bachelors
										cout << "==============================\n"
											 << "Grads w/ Bachelor's degree:\n"
											 << "==============================\n";
										for (int i = 0; i < gradIndex; i++)
										{
											if (grad[i].getGoal() == "Bachelor's") //if goal == bachelor's deg
											{
												cout << "------------------------------\n";
												grad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 3: //masters
										cout << "==============================\n"
											 << "Grads w/ Master's degree:\n"
											 << "==============================\n";
										for (int i = 0; i < gradIndex; i++)
										{
											if (grad[i].getGoal() == "Master's") //if goal == master's deg
											{
												cout << "------------------------------\n";
												grad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 4: //doctorate
										cout << "==============================\n"
											 << "Grads w/ Doctorate degree:\n"
											 << "==============================\n";
										for (int i = 0; i < gradIndex; i++)
										{
											if (grad[i].getGoal() == "Doctorate") //if goal == doctorate deg
											{
												cout << "------------------------------\n";
												grad[i].print();
												cout << "------------------------------\n";
											}
										}
										break;
									case 5: //view all grads
										cout << "==============================\n"
											 << "Graduate Students:\n"
											 << "==============================\n";
										for (int i = 0; i < gradIndex; i++)
										{
											cout << "------------------------------\n";
											grad[i].print();
											cout << "------------------------------\n";
										}
										break;
									case 6: //return to last page
										subRepeat2 = false;
										break;
								}
							} while (subRepeat2 != false);
							break;
						case 3: //view all students
							cout << "==============================\n"
								 << "Undergraduate Students:\n"
								 << "==============================\n";
								for (int i = 0; i < undergradIndex; i++)
								{
									cout << "------------------------------\n";
									undergrad[i].print();
									cout << "------------------------------\n";
								}
							cout << "==============================\n"
								 << "Graduate Students:\n"
								 << "==============================\n";
								for (int i = 0; i < gradIndex; i++)
								{
									cout << "------------------------------\n";
									grad[i].print();
									cout << "------------------------------\n";
								}
							break;
						case 4:
							subRepeat1 = false;
							break;
						}
				} while (subRepeat1 != false);
				break;
			case 2: //employee sub menu
				do
				{
					bool subRepeat2 = true; //reinitializes bool variable

					cout << "==============================\n"
						 << "Select a employee filter:\n"
						 << "==============================\n"
						 << "  (1) Staff members\n"
						 << "  (2) Professors\n"
						 << "  (3) View all employees\n"
						 << "  (4) Return to last page\n"
						 << "==============================\n"
						 << "    > ";
					cin  >> subChoice1;
					//subChoice1 input validation
					while (subChoice1 < 1 || subChoice1 > 4)
					{
						cout << "    > ERROR... please input a number 1-4 only.\n"
							 << "    > ";
						cin  >> subChoice1;
					}

					switch(subChoice1)
					{
					case 1: //staff members
						do
						{
							cout << "==============================\n"
								 << "Select a staff member filter:\n"
								 << "==============================\n"
								 << "  (1) Managers\n"
								 << "  (2) Non-managers\n"
								 << "  (3) View all staff members\n"
								 << "  (4) Return to last page\n"
								 << "==============================\n"
								 << "    > ";
							cin  >> subChoice2;
							//subChoice2 input validation
							while (subChoice2 < 1 || subChoice2 > 4)
							{
								cout << "    > ERROR... please input a number 1-4 only.\n"
									 << "    > ";
								cin  >> subChoice2;
							}

							switch(subChoice2) //staff member filter output
							{
								case 1: //managers
									cout << "==============================\n"
										 << "Managers in staff:\n"
										 << "==============================\n";
									for (int i = 0; i < staffIndex; i++)
									{
										if (staff[i].getStatus() == true) //if staff member is manager
										{
											cout << "------------------------------\n";
											staff[i].print();
											cout << "------------------------------\n";
										}
									}
									break;
								case 2: //non-managers
									cout << "==============================\n"
										 << "Non-managers in staff:\n"
										 << "==============================\n";
									for (int i = 0; i < staffIndex; i++)
									{
										if (staff[i].getStatus() == false) //if staff member is non-manager
										{
											cout << "------------------------------\n";
											staff[i].print();
											cout << "------------------------------\n";
										}
									}
									break;
								case 3: //view all staff members
									cout << "==============================\n"
										 << "Staff members:\n"
										 << "==============================\n";
									for (int i = 0; i < staffIndex; i++)
									{

										cout << "------------------------------\n";
										staff[i].print();
										cout << "------------------------------\n";
									}
									break;
								case 4: //return to last page
									subRepeat2 = false;
									break;
							}
						} while(subRepeat2 != false);
						break;
					case 2: //professors
						do
						{
							cout << "==============================\n"
								 << "Select a professor filter:\n"
								 << "==============================\n"
								 << "  (1) Full-time\n"
								 << "  (2) Part-time\n"
								 << "  (3) View all professors\n"
								 << "  (4) Return to last page\n"
								 << "==============================\n"
								 << "    > ";
							cin  >> subChoice2;
							//subChoice2 input validation
							while (subChoice2 < 1 || subChoice2 > 4)
							{
								cout << "    > ERROR... please input a number 1-4 only.\n"
									 << "    > ";
								cin  >> subChoice2;
							}

							switch(subChoice2) //professor filter output
							{
								case 1: //full time
									cout << "==============================\n"
										 << "Full-time professors:\n"
										 << "==============================\n";
									for (int i = 0; i < profIndex; i++)
									{
										if (prof[i].getStatus() == true) //if professor is full time
										{
											cout << "------------------------------\n";
											prof[i].print();
											cout << "------------------------------\n";
										}
									}
									break;
								case 2: //part time
									cout << "==============================\n"
										 << "Part-time professors:\n"
										 << "==============================\n";
									for (int i = 0; i < profIndex; i++)
									{
										if (prof[i].getStatus() == false) //if professor is part time
										{
											cout << "------------------------------\n";
											prof[i].print();
											cout << "------------------------------\n";
										}
									}
									break;
								case 3: //view all professors
									cout << "==============================\n"
										 << "Professors:\n"
										 << "==============================\n";
									for (int i = 0; i < profIndex; i++)
									{
										cout << "------------------------------\n";
										prof[i].print();
										cout << "------------------------------\n";
									}
									break;
								case 4: //return to last page
									subRepeat2 = false;
									break;
							}
						} while(subRepeat2 != false);
						break;
					case 3: //view all employees
						cout << "==============================\n"
							 << "Staff members:\n"
							 << "==============================\n";
							for (int i = 0; i < staffIndex; i++)
							{
								cout << "------------------------------\n";
								staff[i].print();
								cout << "------------------------------\n";
							}
						cout << "==============================\n"
							 << "Professors:\n"
							 << "==============================\n";
							for (int i = 0; i < profIndex; i++)
							{
								cout << "------------------------------\n";
								prof[i].print();
								cout << "------------------------------\n";
							}
						break;
					case 4: //return to last page
						subRepeat1 = false;
						break;
					}
				} while(subRepeat1 != false);
				break;
			case 3: //view all people
				cout << "==============================\n"
					 << "Students:\n"
					 << "==============================\n"
					 << "++++++++++++++++++++++++++++++\n"
					 << "    > Undergraduate students:\n"
					 << "++++++++++++++++++++++++++++++\n";
					for (int i = 0; i < undergradIndex; i++)
					{
						cout << "------------------------------\n";
						undergrad[i].print();
						cout << "------------------------------\n";
					}
				cout << "++++++++++++++++++++++++++++++\n"
					 <<	"    > Graduate students:\n"
					 << "++++++++++++++++++++++++++++++\n";
					for (int i = 0; i < gradIndex; i++)
					{
						cout << "------------------------------\n";
						grad[i].print();
						cout << "------------------------------\n";
					}
				cout << "==============================\n"
					 << "Employees:\n"
					 << "==============================\n"
					 << "++++++++++++++++++++++++++++++\n"
					 <<	"    > Staff members:\n"
					 << "++++++++++++++++++++++++++++++\n";
					for (int i = 0; i < staffIndex; i++)
					{
						cout << "------------------------------\n";
						staff[i].print();
						cout << "------------------------------\n";
					}
				cout << "++++++++++++++++++++++++++++++\n"
					 <<	"    > Professors:\n"
					 << "++++++++++++++++++++++++++++++\n";
					for (int i = 0; i < profIndex; i++)
					{
						cout << "------------------------------\n";
						prof[i].print();
						cout << "------------------------------\n";
					}
				break;
			case 4:
				repeat = false;
				break;
		}
	} while (repeat != false);
}

/* editDatabase(): drives the "edit database" selection of the main menu
 * Arguments: vector <Undergraduate>&, int, vector <Graduate>&, int,
			  vector <Staff>&, int, vector <Professor>&, int
 * Returns: void
 */
void editDatabase(vector <Undergraduate> &undergrad, int undergradIndex, vector <Graduate> &grad, int gradIndex,
				  vector <Staff> &staff, int staffIndex, vector <Professor> &prof, int profIndex)
{
	//declarations
	int choice, subChoice1, subChoice2;
	bool repeat = true;

	do
	{
		bool subRepeat1 = true;

		cout << "==============================\n"
			 << "Please make a selection to edit:\n"
			 << "==============================\n"
			 << "  (1) Students\n"
			 << "  (2) Employees\n"
			 << "  (3) Return to main menu\n"
			 << "==============================\n"
			 << "    > ";
		cin  >> choice;
		//choice input validation
		while (choice < 1 || choice > 3)
		{
			cout << "    > ERROR... please input a number 1-3 only.\n"
				 << "    > ";
			cin  >> choice;
		}

		//group selection menu
		switch(choice)
		{
			case 1: //student sub menu
				do
				{
					bool subRepeat2 = true; //reinitializes bool variable

					cout << "==============================\n"
						 << "Select a student filter:\n"
						 << "==============================\n"
						 << "  (1) Undergraduate students\n"
						 << "  (2) Graduate students\n"
						 << "  (3) Return to last page\n"
						 << "==============================\n"
						 << "    > ";
					cin  >> subChoice1;
					//subChoice1 input validation
					while (subChoice1 < 1 || subChoice1 > 3)
					{
						cout << "    > ERROR... please input a number 1-3 only.\n"
							 << "    > ";
						cin  >> subChoice1;
					}

					//student filter menu
					switch(subChoice1)
					{
						case 1: //undergrad filter menu
							do
							{
								cout << "==============================\n"
									 << "Select an undergraduate to edit:\n"
									 << "==============================\n";
								for (int i = 0; i < undergradIndex; i++)
									cout << "  (" << i + 1 << ") " << undergrad[i].getName() << endl;

								cout << "  (" << undergradIndex + 1 << ") Return to last page\n"
									 << "==============================\n"
									 << "    > ";
								cin  >> subChoice2;
								//subChoice2 input validation
								while (subChoice2 < 1 || subChoice2 > (undergradIndex + 1))
								{
									cout << "    > ERROR... please input a number 1-" << (undergradIndex + 1) << " only.\n"
										 << "    > ";
									cin  >> subChoice2;
								}

								//subChoice2 outputs
								switch(subChoice2)
								{
									case 1:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 2:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 3:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 4:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 5:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 6:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 7:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 8:
										updateUndergrad(undergrad[subChoice2 - 1]); //sends object to be updated
										break;
									case 9:
										subRepeat2 = false;
										break;
								}
							} while (subRepeat2 != false);
							break;
						case 2: //grad submenu
							do
							{
								cout << "==============================\n"
									 << "Select an graduate to edit:\n"
									 << "==============================\n";
								for (int i = 0; i < gradIndex; i++)
									cout << "  (" << i + 1 << ") " << grad[i].getName() << endl;

								cout << "  (" << gradIndex + 1 << ") Return to last page\n"
									 << "==============================\n"
									 << "    > ";
								cin  >> subChoice2;
								//subChoice2 input validation
								while (subChoice2 < 1 || subChoice2 > (gradIndex + 1))
								{
									cout << "    > ERROR... please input a number 1-" << (gradIndex + 1) << " only.\n"
										 << "    > ";
									cin  >> subChoice2;
								}

								//subChoice2 outputs
								switch(subChoice2)
								{
									case 1:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 2:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 3:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 4:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 5:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 6:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 7:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 8:
										updateGrad(grad[subChoice2 - 1]); //sends object to be updated
										break;
									case 9:
										subRepeat2 = false;
										break;
								}
							} while (subRepeat2 != false);
							break;
						case 3:
							subRepeat1 = false;
							break;
						}
				} while (subRepeat1 != false);
				break;
			case 2: //employee sub menu
				do
				{
					bool subRepeat2 = true; //reinitializes bool variable

					cout << "==============================\n"
						 << "Select a employee filter:\n"
						 << "==============================\n"
						 << "  (1) Staff members\n"
						 << "  (2) Professors\n"
						 << "  (3) Return to last page\n"
						 << "==============================\n"
						 << "    > ";
					cin  >> subChoice1;
					//subChoice1 input validation
					while (subChoice1 < 1 || subChoice1 > 3)
					{
						cout << "    > ERROR... please input a number 1-3 only.\n"
							 << "    > ";
						cin  >> subChoice1;
					}

					switch(subChoice1)
					{
					case 1: //staff members
						do
						{
							cout << "==============================\n"
								 << "Select an staff member to edit:\n"
								 << "==============================\n";
							for (int i = 0; i < staffIndex; i++)
								cout << "  (" << i + 1 << ") " << staff[i].getName() << endl;

							cout << "  (" << staffIndex + 1 << ") Return to last page\n"
								 << "==============================\n"
								 << "    > ";
							cin  >> subChoice2;
							//subChoice2 input validation
							while (subChoice2 < 1 || subChoice2 > (staffIndex + 1))
							{
								cout << "    > ERROR... please input a number 1-" << (staffIndex + 1) << " only.\n"
									 << "    > ";
								cin  >> subChoice2;
							}

							switch(subChoice2) //staff member filter output
							{
								case 1:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 2:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 3:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 4:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 5:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 6:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 7:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 8:
									updateStaff(staff[subChoice2 - 1]); //sends object to be updated
									break;
								case 9:
									subRepeat2 = false;
									break;
							}
						} while(subRepeat2 != false);
						break;
					case 2: //professors
						do
						{
							cout << "==============================\n"
								 << "Select an professor to edit:\n"
								 << "==============================\n";
							for (int i = 0; i < profIndex; i++)
								cout << "  (" << i + 1 << ") " << prof[i].getName() << endl;

							cout << "  (" << profIndex + 1 << ") Return to last page\n"
								 << "==============================\n"
								 << "    > ";
							cin  >> subChoice2;
							//subChoice2 input validation
							while (subChoice2 < 1 || subChoice2 > (profIndex + 1))
							{
								cout << "    > ERROR... please input a number 1-" << (profIndex + 1) << " only.\n"
									 << "    > ";
								cin  >> subChoice2;
							}

							switch(subChoice2) //staff member filter output
							{
								case 1:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 2:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 3:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 4:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 5:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 6:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 7:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 8:
									updateProfessor(prof[subChoice2 - 1]); //sends object to be updated
									break;
								case 9:
									subRepeat2 = false;
									break;
							}
						} while(subRepeat2 != false);
						break;
					case 3: //return to last page
						subRepeat1 = false;
						break;
					}
				} while(subRepeat1 != false);
				break;
			case 3:
				repeat = false;
				break;
		}
	} while (repeat != false);
}

/* updateUndergrad(): updates user specified attributes of objects from the Undergrad class vector
 * Arguments: Undergraduate& | Returns: void
 */
void updateUndergrad(Undergraduate &undergrad)
{
	//declarations
	int editChoice, intInput;
	float floatInput;
	string stringInput;

	cout << "==============================\n"
		 << "Select an attribute to edit\n"
		 << "==============================\n"
		 << "   > (1) Name: " << undergrad.getName() << endl
		 << "   > (2) Age: " << undergrad.getAge() << endl
		 << "   > (3) GPA: " << undergrad.getGPA() << endl
		 << "   > (4) Major: " << undergrad.getMajor() << endl
		 << "   > (5) Year #: " << undergrad.getYear() << endl
		 << "   > (6) Student ID #: " << undergrad.getStudentID() << endl
		 << "   > (7) Return to last page\n"
		 << "==============================\n"
		 << "    > ";
	cin  >> editChoice;
	//editChoice input validation
	while (editChoice < 1 || editChoice > 7)
	{
		cout << "    > ERROR... please input a number 1-7 only.\n"
			 << "    > ";
		cin  >> editChoice;
	}

	switch(editChoice)
	{
		case 1: //updates name
			cout << "    > Enter a new name:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			undergrad.setName(stringInput);
			cout << "    > Name successfully updated!\n";
			break;
		case 2: //updates age
			cout << "    > Enter a new age:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			undergrad.setAge(intInput);
			cout << "    > Age successfully updated!\n";
			break;
		case 3: //updates GPA
			cout << "    > Enter a new GPA:\n"
				 << "    > ";
			cin  >> floatInput;
			//floatInput validation
			while (floatInput < 0 || floatInput > 4)
			{
				cout << "    > ERROR... please input a number 0-4 only.\n"
					 << "    > ";
				cin  >> floatInput;
			}
			undergrad.setGPA(floatInput);
			cout << "    > GPA successfully updated!\n";
			break;
		case 4: //updates major
			cout << "    > Enter a new major:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			undergrad.setMajor(stringInput);
			cout << "    > Major successfully updated!\n";
			break;
		case 5: //updates year#
			cout << "    > Enter a new year (1-4):\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput < 1 || intInput > 4)
			{
				cout << "    > ERROR... please input a number 1-4 only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			undergrad.setYear(intInput);
			cout << "    > Year successfully updated!\n";
			break;
		case 6: //updates studentID
			cout << "    > Enter a new student ID #:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput < 0)
			{
				cout << "    > ERROR... please input a positive number.\n"
					 << "    > ";
				cin  >> intInput;
			}
			undergrad.setStudentID(intInput);
			cout << "    > Student ID # successfully updated!\n";
			break;
		case 7:
			break;
	}
}

/* updateGrad(): updates user specified attributes of objects from the Graduate class vector
 * Arguments: Graduate& | Returns: void
 */
void updateGrad(Graduate &grad)
{
	//declarations
	int editChoice, degChoice, intInput;
	float floatInput;
	string stringInput;

	cout << "==============================\n"
		 << "Select an attribute to edit\n"
		 << "==============================\n"
		 << "   > (1) Name: " << grad.getName() << endl
		 << "   > (2) Age: " << grad.getAge() << endl
		 << "   > (3) GPA: " << grad.getGPA() << endl
		 << "   > (4) Major: " << grad.getMajor() << endl
		 << "   > (5) Year graduated: " << grad.getGradYear() << endl
		 << "   > (6) Degree: " << grad.getGoal() << " degree" << endl
		 << "   > (7) Return to last page\n"
		 << "==============================\n"
		 << "    > ";
	cin  >> editChoice;
	//editChoice input validation
	while (editChoice < 1 || editChoice > 7)
	{
		cout << "    > ERROR... please input a number 1-7 only.\n"
			 << "    > ";
		cin  >> editChoice;
	}

	switch(editChoice)
	{
		case 1: //updates name
			cout << "    > Enter a new name:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			grad.setName(stringInput);
			cout << "    > Name successfully updated!\n";
			break;
		case 2: //updates age
			cout << "    > Enter a new age:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			grad.setAge(intInput);
			cout << "    > Age successfully updated!\n";
			break;
		case 3: //updates GPA
			cout << "    > Enter a new GPA:\n"
				 << "    > ";
			cin  >> floatInput;
			//floatInput validation
			while (floatInput < 0 || floatInput > 4)
			{
				cout << "    > ERROR... please input a number 0-4 only.\n"
					 << "    > ";
				cin  >> floatInput;
			}
			grad.setGPA(floatInput);
			cout << "    > GPA successfully updated!\n";
			break;
		case 4: //updates major
			cout << "    > Enter a new major:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			grad.setMajor(stringInput);
			cout << "    > Major successfully updated!\n";
			break;
		case 5: //updates gradYear
			cout << "    > Enter a new graduation year:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			grad.setGradYear(intInput);
			cout << "    > Graduation year successfully updated!\n";
			break;
		case 6: //updates goal
			cout << "    > Select a new degree type:\n"
				 << "    > (1) Associate's\n"
				 << "    > (2) Bachelor's\n"
				 << "    > (3) Master's\n"
				 << "    > (4) Doctorate\n"
				 << "    > ";
			cin  >> degChoice;
			//degChoice validation
			while (degChoice < 1 || degChoice > 4)
			{
				cout << "    > ERROR... please input a number 1-4 only.\n"
					 << "    > ";
				cin  >> degChoice;
			}
			if (degChoice == 1) //updates degree based on degChoice
				grad.setGoal("Associate's");
			else if(degChoice == 2)
				grad.setGoal("Bachelor's");
			else if(degChoice == 3)
				grad.setGoal("Master's");
			else if(degChoice == 4)
				grad.setGoal("Doctorate");

			cout << "    > Degree type successfully updated!\n";
			break;
		case 7:
			break;
	}
}

/* updateStaff(): updates user specified attributes of objects from the Staff class vector
 * Arguments: Staff& | Returns: void
 */
void updateStaff(Staff &staff)
{
	//declarations
	int editChoice, intInput, statusChoice;
	float floatInput;
	string stringInput;

	cout << "==============================\n"
		 << "Select an attribute to edit\n"
		 << "==============================\n"
		 << "   > (1) Name: " << staff.getName() << endl
		 << "   > (2) Age: " << staff.getAge() << endl
		 << "   > (3) Salary: $" << staff.getSalary() << endl
		 << "   > (4) Employee ID #: " << staff.getEmployeeID() << endl
		 << "   > (5) Status: ";
						if (staff.getStatus() == 1) cout << "Manager\n";
						else cout << "Non-manager\n";
	cout << "   > (6) Position: " << staff.getPosition() << endl
		 << "   > (7) Return to last page\n"
		 << "==============================\n"
		 << "    > ";
	cin  >> editChoice;
	//editChoice input validation
	while (editChoice < 1 || editChoice > 7)
	{
		cout << "    > ERROR... please input a number 1-7 only.\n"
			 << "    > ";
		cin  >> editChoice;
	}

	switch(editChoice)
	{
		case 1: //updates name
			cout << "    > Enter a new name:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			staff.setName(stringInput);
			cout << "    > Name successfully updated!\n";
			break;
		case 2: //updates age
			cout << "    > Enter a new age:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			staff.setAge(intInput);
			cout << "    > Age successfully updated!\n";
			break;
		case 3: //updates salary
			cout << "    > Enter a new Salary:\n"
				 << "    > ";
			cin  >> floatInput;
			//floatInput validation
			while (floatInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> floatInput;
			}
			staff.setSalary(floatInput);
			cout << "    > Salary successfully updated!\n";
			break;
		case 4: //updates employeeID
			cout << "    > Enter a employee ID #:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			staff.setEmployeeID(intInput);
			cout << "    > Employee ID # successfully updated!\n";
			break;
		case 5: //updates status
			cout << "    > Select a new status:\n"
				 << "    > (1) Non-manager\n"
				 << "    > (2) Manager\n"
			 	 << "    > ";
			cin  >> statusChoice;
			//statusChoice input validation
			while (statusChoice < 1 || statusChoice > 2)
			{
				cout << "    > ERROR... please input a number 1-2 only.\n"
					 << "    > ";
				cin  >> statusChoice;
			}
			if (statusChoice == 1) staff.setStatus(false);
			else if (statusChoice == 2) staff.setStatus(true);
			cout << "    > Status successfully updated!\n";
			break;

		case 6: //updates Position
			cout << "    > Enter a new position:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			staff.setPosition(stringInput);
			cout << "    > Position successfully updated!\n";
			break;
		case 7:
			break;
	}
}

/* updateProfessor(): updates user specified attributes of objects from the Professor class vector
 * Arguments: P& | Returns: void
 */
void updateProfessor(Professor &professor)
{
	//declarations
	int editChoice, intInput, statusChoice;
	float floatInput;
	string stringInput;

	cout << "==============================\n"
		 << "Select an attribute to edit\n"
		 << "==============================\n"
		 << "   > (1) Name: " << professor.getName() << endl
		 << "   > (2) Age: " << professor.getAge() << endl
		 << "   > (3) Salary: $" << professor.getSalary() << endl
		 << "   > (4) Employee ID #: " << professor.getEmployeeID() << endl
		 << "   > (5) Status: ";
						if (professor.getStatus() == 1) cout << "Full-time\n";
						else cout << "Part-time\n";
	cout << "   > (6) Room #: " << professor.getRoomNum() << endl
		 << "   > (7) Return to last page\n"
		 << "==============================\n"
		 << "    > ";
	cin  >> editChoice;
	//editChoice input validation
	while (editChoice < 1 || editChoice > 7)
	{
		cout << "    > ERROR... please input a number 1-7 only.\n"
			 << "    > ";
		cin  >> editChoice;
	}

	switch(editChoice)
	{
		case 1: //updates name
			cout << "    > Enter a new name:\n"
				 << "    > ";
			cin.ignore();
			getline(cin, stringInput);
			professor.setName(stringInput);
			cout << "    > Name successfully updated!\n";
			break;
		case 2: //updates age
			cout << "    > Enter a new age:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			professor.setAge(intInput);
			cout << "    > Age successfully updated!\n";
			break;
		case 3: //updates salary
			cout << "    > Enter a new Salary:\n"
				 << "    > ";
			cin  >> floatInput;
			//floatInput validation
			while (floatInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> floatInput;
			}
			professor.setSalary(floatInput);
			cout << "    > Salary successfully updated!\n";
			break;
		case 4: //updates employeeID
			cout << "    > Enter a employee ID #:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput validation
			while (intInput <= 0)
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> intInput;
			}
			professor.setEmployeeID(intInput);
			cout << "    > Employee ID # successfully updated!\n";
			break;
		case 5: //updates status
			cout << "    > Select a new status:\n"
				 << "    > (1) Part-time\n"
				 << "    > (2) Full-time\n"
			 	 << "    > ";
			cin  >> statusChoice;
			//statusChoice input validation
			while (statusChoice < 1 || statusChoice > 2)
			{
				cout << "    > ERROR... please input a number 1-2 only.\n"
					 << "    > ";
				cin  >> statusChoice;
			}
			if (statusChoice == 1) professor.setStatus(false);
			else if (statusChoice == 2) professor.setStatus(true);
			cout << "    > Status successfully updated!\n";
			break;
		case 6: //updates roomNum
			cout << "    > Enter a new room #:\n"
				 << "    > ";
			cin  >> intInput;
			//intInput input validation
			while (statusChoice <= 0 )
			{
				cout << "    > ERROR... please input a positive number only.\n"
					 << "    > ";
				cin  >> statusChoice;
			}
			professor.setRoomNum(intInput);
			cout << "    > Room # successfully updated!\n";
			break;
		case 7:
			break;
	}
}

/* plagiarismPledge(): function to simply output the plagiarism pledge at the end of the program
 * Arguments: none | Returns: void
 */
void plagiarismPledge()
{
	cout << "\n\nI attest that this code is my original programming work,\nand that I received "
		 << "no help creating it. I attest that I did not\ncopy this code or any portion of this"
		 << "code from any source.";
};
