/*
 weather.cpp
 Shelley Wong (swong26)
 Last updated: Sep 20, 2023

 This program can be used to convert a CSV file with NOAA climate data to an
 input file that uses a format similar to the input (.in) files we have used in
 CSCI 211 programming assignments (e.g. Video descriptions where the title, url,
 comment, length, and rating are all on different lines). In the commands below,
 I am starting with the `chico-weather-2018-2022.csv` file, and the converted
 output is put into a file called `converted.in` (using .in to indicate that
 this file can be used as input for your Final Project program).

 You can compile and run this program with the following commands:
 $ g++ -std=c++11 -o weather weather.cpp
 $ ./weather chico-weather-2018-2022.csv converted.in
*/
#include <iostream>  // cin, cout, cerr, getline, endl
#include <fstream>  // ifstream, ofstream
#include <sstream>  // istringstream
using namespace std;

// If string is not empty, remove quotation marks at start and end of string
// Otherwise, set this string to be a value that indicates it is empty (none)
void formatString(string& str){
    if(str != ""){
        str = str.substr(1, str.size()-2);
    }
    else{
        str = '0';
    }
}

int main(int argc, char* argv[]) {
    if (argc < 3){
        cerr << "Must specify input and output file." << endl;
        return 1;
    }
    if (argc > 3){
        cerr << "Too many command line arguments specified." << endl;
        return 1;
    }

    // 1st command line argument should be the CSV file
    ifstream ifile(argv[1]);
    // 2nd arg is the name of the file that will hold the converted data
    ofstream ofile(argv[2]);

    // Make sure you can open the CSV file
    if (!ifile) {
        cerr << "Failed to open the file." << endl;
        return 1;
    }

    // remove line of table headers
    string table_headers;
    getline(ifile, table_headers);

    // Take each entry from the CSV file, grab the values (separated by commas),
    // remove the quotes from around each value, then create an instance of a
    // Data struct and add it to our dataList vector
    string line;
    while (getline(ifile, line)) {
        istringstream iss(line);
        string station;   // Station ID
        string name;      // Station Name/Location
        string name2;     // Station Name part 2 (State and Country)
        string date;      // date in YYYY-MM-DD format
        string dapr;      // num days included in multiday precipitation total
        string mdpr;      // multiday precipitation total (use with DAPR)
        string prcp;      // precipitation

        // Get historical daily input for one station on one day
        getline(iss, station, ',');
        getline(iss, name, ',');
        getline(iss, name2, ',');
        name = name + name2;  // creates name without comma
        getline(iss, date, ',');
        getline(iss, dapr, ',');
        getline(iss, mdpr, ',');
        getline(iss, prcp, ',');

        // remove quotation marks and give empty entries a placeholder value
        formatString(station);
        formatString(name);
        formatString(date);
        formatString(dapr);
        formatString(mdpr);
        formatString(prcp);

        // Add all data for one entry to the converted.in file
        // (each value will be on 1 line, so each entry will be 12 lines)
        ofile << station << endl;
        ofile << name << endl;
        ofile << date << endl;
        ofile << dapr << endl;
        ofile << mdpr << endl;
        ofile << prcp << endl;
        //ofile << snow << endl;
    }

    ifile.close();
    ofile.close();

    return 0;
}
