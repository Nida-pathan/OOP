/*
THIS CODE HAS BEEN TESTED AND IS FULLY OPERATIONAL.

Problem Statement: Imagine a publishing company which does marketing for book and audio cassette versions. Create a class publication that stores the title (a string) and price (type float) of a publication.
From this class derive two classes: book, which adds a page count (type int), and tape, which adds a playing time in minutes (type float). Write a program that instantiates the book and tape classes, allows user to enter data and displays the data members. If an exception is caught, replace all the data member values with zero values.

Code from Object Oriented Programming (SPPU - Second Year - Computer Engineering - Content) repository on KSKA Git: https://git.kska.io/sppu-se-comp-content/ObjectOrientedProgramming
*/

// BEGINNING OF CODE
#include <iostream>
#include <limits> // For exception handling.
using namespace std;

class KPublications {
// Base class that holds title and price for books.
	protected:
		string title;
		float price;
	public:
		KPublications() {
		// Constuctor to initialize zero values.
			title="";
			price=0.0;
		}
};

// ----- BOOK -----
class BookPublication : protected KPublications {
// Derived class (from base class KPublications) for books.
	private:
		int bookPages;
	public:
		BookPublication() {
		// Constuctor to initialize zero values.
			bookPages=0;
		}

		void aboutBook() {
		// Storing information bout the book.
			cout<<endl<<"----- ENTER ACCURATE BOOK INFORMATION BELOW -----";
			cout<<endl<<"Title of your book:\t";
			cin>>title;
			cout<<"Price of your book:\tRs. ";
			cin>>price;

			try {
			// Exception handling for total pages in book.
				cout<<"Total pages in your book:\t";
				cin>>bookPages;

				if (cin.fail()) {
					throw invalid_argument("Invalid input. Please enter integer value.\n---- INFORMATION DISCARDED -----\n");
				}
				else {
					cout<<"----- INFORMATION SAVED -----"<<endl;
				}
			}
			catch (const invalid_argument& invalArg) {
				cerr << invalArg.what();
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				title="";
				price=0.0;
				bookPages=0;
			}
		}

		void displayBook() {
		// Displaying information about the book.
			cout<<endl<<"---- INFORMATION ABOUT YOUR BOOK: -----";
			cout<<endl<<"Title of your book:\t"<<title;
			cout<<endl<<"Price of your book:\tRs. "<<price;
			cout<<endl<<"Number of pages in your book:\t"<<bookPages;
			cout<<endl<<"----- END OF INFORMATION -----"<<endl;
		}
};

// ----- TAPE -----
class TapePublication : protected KPublications {
// Derived class (from base class KPublications) for tape.
	private:
		float tapeLength;
	public:
		TapePublication() {
		// Displaying information about the book.
			tapeLength=0.0;
		}

		void aboutTape() {
		// Storing information about the tape.
			cout<<endl<<"---- ENTER ACCURATE TAPE INFORMATION ----";
			cout<<endl<<"Title of your tape:\t";
			cin>>title;
			cout<<"Price of your tape:\tRs. ";
			cin>>price;

			try {
			// Exception handling for tape length input.
				cout<<"Length of your tape (in minutes):\t";
				cin>>tapeLength;

				if (cin.fail()) {
					throw invalid_argument("Invalid input. Please enter float value.\n----- INFORMATION DISCARDED -----\n");
				}
				else {
					cout<<"----- INFORMATION SAVED -----"<<endl;
				}
			}
			catch (const invalid_argument& invalArg) {
				cerr<<invalArg.what()<<endl;
				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				title="";
				price=0.0;
				tapeLength = 0.0;
			}
		}

		void displayTape() {
		// Displaying information about the tape.
		cout<<endl<<"---- INFORMATION ABOUT YOUR TAPE: -----";
		cout<<endl<<"Title of your tape:\t"<<title;
		cout<<endl<<"Price of your tape:\tRs. "<<price;
		cout<<endl<<"Length of your tape (in minutes):\t"<<tapeLength;
		cout<<endl<<"----- END OF INFORMATION -----"<<endl;
		}
};

int main() {
	BookPublication pubBook;
	TapePublication pubTape;
	int optn;

	while (1) {
	// Diplaying main option menu.
		cout<<endl<<"---- MAIN MENU ----";
		cout<<endl<<"1 -> STORE information about BOOK";
		cout<<endl<<"2 -> STORE information about TAPE";
		cout<<endl<<"3 -> SHOW information about BOOK";
		cout<<endl<<"4 -> SHOW information about TAPE";
		cout<<endl<<"5 -> Exit";

	// User input for option.
		cout<<endl<<"Choose an option (1-5):\t";
		cin>>optn;

	// Switch case.
		switch (optn) {
			case 1:
				pubBook.aboutBook();
				break;
			case 2:
				pubTape.aboutTape();
				break;
			case 3:
				pubBook.displayBook();
				break;
			case 4:
				pubTape.displayTape();
				break;
			case 5:
				cout<<endl<<"## END OF CODE\n\n";
				exit(0);
			default:
				cout<<endl<<"Please choose a valid option (1-5)"<<endl;
				break;
		}
	}

	return 0;
}
// END OF CODE
