//Header files
#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

//Function prototypes
double readRainfall (double[],ifstream &);
double totalRainfall (double[]);
double highestRainfall (double[]);
double lowestRainfall (double[]);
 
//function main starts
int main()
{
	//Declare variables
	const int MONTHS_OF_YEAR = 12;
	double monthlyRainfall[MONTHS_OF_YEAR];
	//initialization list of the namesOfTheMonths
	string namesOfTheMonths[MONTHS_OF_YEAR] = { "January","February","March","April","May","June","July","August","September","October","November","December" };
	double totalRainfallForYear = 0.00;
	double averageMonthlyRainfall = 0.00;
	int highestRainfallAmount;
	int lowestRainfallAmount;
	string fileName;
	
	//title on the console
	cout << "\tYEARLY RAINFALL CALCULATIONS" << endl;
	
	cout << "\nPlease enter the name of the output file ";
	getline(cin, fileName); //read the file name
	ofstream outputFile; //stream object
	outputFile.open(fileName); //open the file 
	
	//title on the file output
	outputFile << "\tYEARLY RAINFALL CALCULATIONS" << endl;
	outputFile << "\n\tMonth";
	outputFile << "\t\tRainfall(in inches)" << endl;
		
	cout << "Please enter the name of the input file ";
	getline(cin, fileName);
	ifstream inputFile(fileName); //stream object
	
	
	//call the function readRainfall
	readRainfall(monthlyRainfall, inputFile);
	outputFile << endl;

	for (int index = 1; index <= MONTHS_OF_YEAR; index++)
		outputFile << left << setw(9) << namesOfTheMonths[index - 1] << right << setw(24) << fixed << showpoint << setprecision(2) << monthlyRainfall[index - 1] << endl;

	//call the function totalRainfall
	totalRainfallForYear = totalRainfall(monthlyRainfall);
	outputFile << "\nThe total rainfall for the year is " << fixed << showpoint << setprecision(2) << totalRainfallForYear << " inches." << endl;
	
	averageMonthlyRainfall = totalRainfallForYear / MONTHS_OF_YEAR;
	outputFile << "The average monthly rainfall is " << fixed << showpoint << setprecision(2) << averageMonthlyRainfall << " inches." << endl;
	
	//call the function  highestRainfall
	highestRainfallAmount = highestRainfall(monthlyRainfall);
	outputFile <<"The highest rainfall for the year of " << fixed << showpoint << setprecision(2) << monthlyRainfall[highestRainfallAmount] << " occurred in " << namesOfTheMonths[highestRainfallAmount] << endl;
	
	//call the function lowestRainfall
	lowestRainfallAmount = lowestRainfall(monthlyRainfall);
	outputFile << "The lowest rainfall for the year of " << fixed << showpoint << setprecision(2) << monthlyRainfall[lowestRainfallAmount] << " occurred in " << namesOfTheMonths[lowestRainfallAmount] << endl;

	//months with rainfalls of four inches or more
	for (int count = 0; count < MONTHS_OF_YEAR; count++)
		if (monthlyRainfall[count] >= 4.00)
			outputFile << "\nRainfall of 4 inches or more occured in " << namesOfTheMonths[count] << endl;

	cout << "\nProcessing complete\n";
	
	outputFile.close();
	inputFile.close();


	return 0; //ends of main function
}

/**************************************************************************************
 * Definition of readRainfall function                                                *
 * The function has two parameters: monthlyRainfall array and inputFile as a reference*
 * MONTHS_OF_YEAR is a constant integer used as size for the array                    *
 * test for error, return -1                                                          *
 * read the input file if the file open, return 0                                     *
***************************************************************************************/

double readRainfall(double monthlyRainfall[],ifstream &inputFile)
{
	const int MONTHS_OF_YEAR = 12;
	
	//Test for error
	if (!inputFile)
	{
		//display error message
		cout << "Error opening file.\n";
		return -1;
	}
	else
	{
		//loop to get each month the rainfall
		double rainfalls;
		for (int index = 0; index < MONTHS_OF_YEAR; index++) 
		{ 
			//read the rainfall from the file
			inputFile >> rainfalls;
			monthlyRainfall[index] = rainfalls;
		}
		return 0;
	}
	inputFile.close();
}

/****************************************************************
 * Definition of totalRainfall function                         *
 * The function takes one parameter: rainfalls array as a double*
 * MONTHS is a constant integer used as size for the array      *
 * total is accumulator, double to get the sum of the rainfalls *
 * counter is an integer for loop counter                       *
 * the function returns total as a double                       *
*****************************************************************/

double totalRainfall(double rainfalls[])
{
	const int MONTHS = 12;
	double total = 0;
	for (int counter = 0; counter < MONTHS; counter++)
		total += rainfalls[counter];
	
	return total;
}

/************************************************************
 * Definition of highestRainfall function                   *
 * NUM_OF_MONTHS is a constant integer as size for the array*
 * highestMonth is an integer to hold the rainfall          *
 * index is an integer as loop counter                      *
 * The function return highestMonth                         *
*************************************************************/

double highestRainfall(double amounts[])
{
	const int NUM_MONTHS = 12;
    //hold the highest rainfall
	int highestMonth=0;
	for (int index = 0; index < NUM_MONTHS; index++)
	{
		if (amounts[index]>amounts[highestMonth])
		{
			highestMonth = index;
		}
	}
	return highestMonth;
}

/***********************************************************
* Definition of lowestRainfall function                   *
* NUM_OF_MONTHS is a constant integer as size for the array*
* highestMonth is an integer to hold the rainfall          *
* index is an integer as loop counter                      *
* The function return lowestMonth                          *
************************************************************/

double lowestRainfall(double amounts[])
{
	const int NUM_MONTHS = 12;
	//hold the lowest rainfall
	int lowestMonth=0;
	for (int index = 0; index < NUM_MONTHS; index++)
	{
		if (amounts[index]<amounts[lowestMonth])
		{
			lowestMonth = index;
		}
	}
	return lowestMonth;
}