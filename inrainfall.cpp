
// create the rainfall file
#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
	double January = 2.65;
	double February = 3.4111;
	double March = 2;
	double April = 8.3;
	double May = 3.45;
	double June = 4.529;
	double July = 0.45;
	double August = 3.188;
	double September = 2.4;
	double October = 1.75;
	double November = 7.3;
	double December = 2.743;

	ofstream outputFile;
	outputFile.open("inrainfall.txt");

	outputFile << fixed << showpoint << setprecision(2) << January << endl;
	outputFile << fixed << showpoint << setprecision(2) << February << endl;
	outputFile << fixed << showpoint << setprecision(2) << March << endl;
	outputFile << fixed << showpoint << setprecision(2) << April << endl;
	outputFile << fixed << showpoint << setprecision(2) << May << endl;
	outputFile << fixed << showpoint << setprecision(2) << June << endl;
	outputFile << fixed << showpoint << setprecision(2) << July << endl;
	outputFile << fixed << showpoint << setprecision(2) << August << endl;
	outputFile << fixed << showpoint << setprecision(2) << September << endl;
	outputFile << fixed << showpoint << setprecision(2) << October << endl;
	outputFile << fixed << showpoint << setprecision(2) << November << endl;
	outputFile << fixed << showpoint << setprecision(2) << December << endl;

	outputFile.close();

	return 0;
}