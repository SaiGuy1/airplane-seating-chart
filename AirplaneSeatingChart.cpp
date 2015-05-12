//********************************************************************************
//
//	Author:           Shairam (Sai) Narendran
//	Date Created:     4/21/15
//	Revisions:        None.
//
//	Purpose:          Create a program to populate arrays and print out a seating
//					  chart.
//
//	Input:            menuSelection, ticketType, row, and column 
//                   
//	Output:           seating chart 
//
//********************************************************************************

#include<iostream>
#include<iomanip>

using namespace std;
void showMenu(int& selection); 
void assignSeat(char& ticketType, int& row,
char& column);
//void cancelSeat(char& ticketType, int& row,
//char& column);
void printForm(char form[][6], int row, char column);

int main()
{
int selection;
char ch, ticketType, column;
int row;
char form[13][6];

showMenu(selection);

while(selection != 4)   
{

switch(selection)
{
case 1:
assignSeat(ticketType, row, column);
break;
case 2:
//cancelSeat(ticketType, row, column);
break;
case 3:
printForm(form, row, column);
break;
case 4:
break;
}
showMenu(selection);
}// end while   
system("PAUSE");
return 0;
}

void showMenu(int& selection){
	cout << "Choose an option from the following: " << endl;
	cout << "1 -> Reserve a Seat " << endl;
	cout << "2 -> Cancel a Reservation " << endl;
	cout << "3 -> Print Seating Chart " << endl; 
	cout << "4 -> Exit Program" << endl; 
	cin >> selection;
}

void assignSeat(char& ticketType, int& row, char& column)
{   

cout << "The airplane has 13 rows, with six seats in each row. " << endl;

cout << "Enter ticket type,\n"
<< "F for first class, \n"
<< "B for business class,\n"
<< "E for economy class:" << endl;
cin >> ticketType;
ticketType = static_cast<char>(toupper(ticketType));
while(ticketType != 'F' && ticketType != 'B' && ticketType != 'E')
{
cout << "Invalid ticket type." << endl;
cout << "Enter ticket type,\n"
<< "F/f for first class, \n"
<< "B/b for business class,\n"
<< "E/e for economy class:" << endl;
cin >> ticketType;
ticketType = static_cast<char>(toupper(ticketType));
}
switch(ticketType)
{
case 'F':
cout << "Row 1 and 2 are first class,\n" ;
break;
case 'B':
cout << "row 3 throuh 7 are business class,\n";
break;
case 'E':
cout << "row 8 through 13 are economy class." << endl;
break;
}// end switch
  
cout << "Enter the row number you want to sit: " << endl ;
cin >> row;
  
cout << "Enter the seat number (from A to F). " << endl;
cin >> column;
column = static_cast<char>(toupper(column));
}

//void cancelSeat(char& ticketType, int& row, char& column)
//{
//
//cout << "Enter ticket type,\n"
//<< "F for first class, \n"
//<< "B for business class,\n"
//<< "E for economy class:" << endl;
//cin >> ticketType;
//
// if(ticketType = 'F')
//        {
//		
//		}
//}



void printForm(char form[][6], int row, char column)
{
int i, j;
  
cout << "* indicates that the seat is available; " << endl;
cout << "X indicates that the seat is occupied. " << endl;
cout << setw(12) << "A" << setw(6) << "B" << setw(6) << "C"
<< setw(6) << "D" << setw(6) << "E" << setw(6) << "F" << endl;

for(i = 0; i < 13; i++)
{
cout << left << setw(3) << "Row " << setw(2)<< i+1 ;
for(j = 0; j < 6; j++)
{
if(i == row - 1 && j == static_cast<int>(column)-65)
cout << right << setw(6) << "X";
else
cout << right << setw(6) << "*";

}
cout << endl;
}
}
