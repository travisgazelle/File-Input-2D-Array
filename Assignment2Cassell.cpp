// Travis Cassell
// 03/2021
// CS 201 03

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cstdlib>

using namespace std;

// Constants for menu choices and array size
const int COLUMNS = 5;
const int ROWS = 74;
const int YEARRANGE = 1;
const int DISASTER = 2;
const int SUMREPORT = 3;

// Function prototypes
int yearRange(string, string);
void searchDisaster(string);
void sumReport(string);

int main()
{
    // Defining array and variables for input loop
    string catastrophe[ROWS][COLUMNS];
    int column = 0;
    int row = 0;
    string data;
    
    // Rows are each successive disaster with columns denoting the following...
    // Column 0 is Name of disaster
    // Column 1 is Type of disaster
    // Column 2 is Year of occurrence
    // Column 3 is Loss of property in millions of dollars
    // Column 4 is Number of deaths
    
    // Read the contents of the file into a 2D array with a nested loop
    ifstream inputFile("catastrophe.txt");
    // If the file is open, read the contents
    if(inputFile)
    {
        while (getline(inputFile, data))
            {
                column = 0;
                stringstream iss(data);
          
                while (getline(iss, catastrophe[row][column++],','));
                row++;
            }
    }
    else
    {
        // Error message for incorrect file
        cout << "Error, unable to open the file\n";
        return 0;
    }
    inputFile.close();
    
    // *****************************************************
    
    // DISPLAY THE MENU OPTIONS
    int choice;
    cout << "Select from the following menu: \n\n"
         << "'1' look up a year range \n"
         << "'2' look up a disaster \n"
         << "'3' generate a summary report \n";
    cin >> choice;

    // VALIDATE THE MENU OPTIONS
    while (choice < YEARRANGE || choice > SUMREPORT)
    {
        cout << "Please enter a valid choice from the menu: \n";
        cin >> choice;
    }
    
    if (choice == YEARRANGE)
    {
        // LOGIC FOR YEAR RANGE
        // Prompt user for beginning and end year and hold in variables
        int start, end;
        cout << "Enter the beginning year for your search: ";
        cin >> start;
        cout << "Enter the ending year for your search: ";
        cin >> end;
        cout << "\nThe disasters between "<< start << " and " << end << " are: \n\n";
        // Loop through array, check for values between start and end inclusive
        for (int year = start; year <= end; year++)
        {
            for (int index = 0; index < ROWS; index++)
            {
                // Hold temporary value of year as a string to compare to array string
                std::string tempYear = std::to_string(year);
                // std::cout << tempYear << "\n";
                string current = catastrophe[index][2];
                // Call function to test if true or false
                int valid = yearRange(tempYear, current);
                if (valid == 1)
                    cout << catastrophe[index][0] << endl;
            }
        }
    }
    
    if (choice == DISASTER)
    {
        // LOGIC FOR SEARCH DISASTER
        // Prompt user for disaster type and recieve variable
        string disaster;
        cout << "Enter a disaster type: \n";
        cin >> disaster;
        // Convert all characters to lower case for comparison
        for_each(disaster.begin(), disaster.end(), [](char & c) {
            c = tolower(c);
        });
        disaster.c_str();
    
        string temp1;
        string temp2;
        // Loop through array to find matching disaster
        for (int index = 0; index < ROWS; index++)
        {
            // Takes the current line and similarly converts to all lower case
            string current = catastrophe[index][1];
            for_each(current.begin(), current.end(), [](char & c) {
                c = tolower(c);
            });
            current.c_str();
            // Tests whether the strings are equal, whether disaster is a match
            if (current.compare(1, (current.length() - 2), disaster) == 0)
            {
                string temp1 = catastrophe[index][2];
                // Check if year has already been printed out, if not, send to function
                // Update variable
                if (temp1 != temp2)
                {
                    temp2 = temp1;
                    searchDisaster(temp1);
                }
            }
        }
    }
    
    if (choice == SUMREPORT)
    {
        // LOGIC FOR SUM REPORT
        // Prompt user for a filename to write to
        string filename;
        cout << "Enter a file name: ";
        cin >> filename;
        ofstream outputFile;
        outputFile.open(filename);
        // Loop to process through all years on file from 2012 - 2019
        for (int currentYear = 2012; currentYear <= 2019; currentYear++)
        {
            // Initialize death counter
            int deaths = 0;
            outputFile << "Year: " << currentYear << ", Disasters: ";
            for (int index = 0; index < ROWS; index++)
            {
                string current = catastrophe[index][2];
                string strYear = to_string(currentYear);
        
                if (current == strYear)
                {
                    outputFile << catastrophe[index][1] << ", ";
                    string strDeaths = catastrophe[index][4];
                    int intDeaths = stoi(strDeaths);
                    deaths += intDeaths;
                }
            }
            outputFile << "Deaths: " << deaths << endl;
        }
        outputFile.close();
        sumReport(filename);
    }
    
    return 0;
}

// FUNCTION DEFINITIONS

// Function that accepts a string year and array's current year to test if equal
int yearRange(string year, string array)
{
    int test;
    if (year == array)
        test = 1;
    else
        test = 0;
        
    return test;
}

// Function that takes in a year and prints it out to screen with a space between
void searchDisaster(string year)
{
    cout << year << " ";
}

// Function that accepts the user's inputted filename, opens it and prints it out to screen
void sumReport(string filename)
{
    ifstream inputFile;
    string report;
    
    inputFile.open(filename);
    
    while (inputFile)
    {
        getline(inputFile, report);
        cout << report << endl;
    }
    inputFile.close();
    return;
}
