## File-Input-2D-Array  
CS 201 Project 21'

Read in text file of disasters into 2 dimensional array

Allow user to search in a range of dates,  
Disaster type,  
Generate summary report  

Text file included


Assignment Specifications

The file named catastrophe.txt contains the data set. Each line of the file contains the information of catastrophe which includes: name, disaster, year, Loss of property(million of dollars),Deaths, There is a comma character between fields.
The program will input the data set and list of catastrophe. If the list of catastrophe cannot be constructed, the program will display an appropriate error message and halt.
The program will display a menu of options and allow the user to search for catastrophe which meet certain criteria. The menu options are:
1. Display all catastrophe in a year range: Prompt the user for two years (a starting year and an ending year), then display all catastrophe between those two years (inclusive). For example, if the user entered “2015” and “2018”, display all catastrophe 2015,2016,2017,2018.
2. Search for an disaster: Prompt the user for a string, then display unique years when that disaster happens information whose disaster name contains that string (regardless of case). For example, if the user enters “FLOODING”, display all catastrophe whose disaster name contains (or matches) the string “flooding”, “Flooding”.
3. SUMMARY REPORT: Generate a text file with list of disasters per year and Total deaths per year. Sample summary report is shown below.
Assignment Notes
1. Your program will consist of at least 3 functions: a separate function to process each of the 3 menu options listed above.
2. You may use arrays or vectors to store the data.
3. Be sure to display the information in a reasonable and readable manner.
4. If no catastrophes are found for a particular search, your program will display an appropriate message (rather than simply displaying nothing).

Sample Output:
What would you like to do?
1: Look up year range
2: Look up disaster
3: Generate summary report
Select an option : 1
  Enter beginning year: 2018
  Enter ending year: 2019
All Disasters between 2018 and 2019 :
Central and Eastern Winter Storm (January 2018)
Northeast Winter Storm (March 2018)
Southeastern Tornadoes and Severe Weather (March 2018)
Southern and Eastern Tornadoes and Severe Weather (April 2018)
Central and Northeastern Severe Weather (May 2018)
Central and Eastern Severe Weather (May 2018)
Texas Hail Storm (June 2018)
Southeast, Ohio Valley and Northeast Severe Weather (February 2019)
Texas Hail Storm (March 2019)
South and Southeast Severe Weather (May 2019)
Rockies, Central and Northeast Tornadoes and Severe Weather (May 2019)
What would you like to do?
1: Look up year range
2: Look up disaster
3: Generate summary report
Select an option:2
  Enter an Disaster name: Flooding
Years when disaster happened are: 2013,2014,2015,2016,2017
What would you like to do?
1: Look up year range
2: Look up disaster
3: Generate summary report
Select an option:3
Enter output file name: Disasters_summary.txt
Year; Disasters; Total deaths
2018; Winter storm,Severe Storm ; 39
2019;Severe Storm;4
NOTE: Sample data of Disasters_summary.txt for 2018 and 2019 is shown here.
Generate for all the years.
