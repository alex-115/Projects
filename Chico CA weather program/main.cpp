// filename: main.cpp
// your name (first and last): Alejandro Barajas
// your Chico Portal/INGInious username: Ajbarajas1
// Short summary of the file contents: This file is the main file that will utilize the data sets and linked lists. This prorgam will recieve the input from the redirected file then input them into data sets then the data sets will be inputed into a linked list to the corressponding year and station.
#include "ADT.h"
#include <sstream>
#include "data.h"
#include <iostream>
using namespace std;
int main()
{
       string station, name, date, dapr;
       string command;
       double mdpr;
       double prcp;
       List tmp;
       List station1list1, station1list2, station1list3, station1list4, station1list5, station1list6;
       List station2list1, station2list2, station2list3, station2list4, station2list5, station2list6;
       List station3list1, station3list2, station3list3, station3list4, station3list5, station3list6;
       List station4list1, station4list2, station4list3, station4list4, station4list5, station4list6;
       int station1list1days = 0, station1list2days = 0, station1list3days = 0, station1list4days = 0, station1list5days = 0, station1list6days = 0;
        int station2list1days = 0, station2list2days = 0, station2list3days = 0, station2list4days = 0, station2list5days = 0, station2list6days = 0;             
 int station3list1days = 0, station3list2days = 0, station3list3days = 0, station3list4days = 0, station3list5days = 0, station3list6days = 0;                
 int station4list1days = 0, station4list2days = 0, station4list3days = 0, station4list4days = 0, station4list5days = 0, station4list6days = 0;
 while(getline(cin,station))
               {
               getline(cin,name);
               getline(cin,date);
               getline(cin,dapr);
               cin >> mdpr;
               cin >> prcp;
               if ( station == "US1CABT0012" && date < "2019" && date > "2018")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station1list1.insert(m_data);
               station1list1days += station1list1.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0012" && date < "2020" && date > "2019")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station1list2.insert(m_data);
               station1list2days += station1list2.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0012" && date > "2020" && date < "2021")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station1list3.insert(m_data);
               station1list3days += station1list3.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0012" && date > "2021" && date < "2022")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station1list4.insert(m_data);
               station1list4days += station1list4.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0012" && date > "2022" && date < "2023")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station1list5.insert(m_data);
               station1list5days += station1list5.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0012" && date > "2023" && date < "2024")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station1list6.insert(m_data);
               station1list6days += station1list6.daysaboveonehalf(prcp);
               }
                if (station == "US1CABT0008" && date < "2019" && date > "2018")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station2list1.insert(m_data);
               station2list1days += station2list1.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0008" && date < "2020" && date > "2019")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station2list2.insert(m_data);
               station2list2days += station2list2.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0008" && date > "2020" && date < "2021")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station2list3.insert(m_data);
               station2list3days += station2list3.daysaboveonehalf(prcp);               
               }
               if (station == "US1CABT0008" && date > "2021" && date < "2022")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station2list4.insert(m_data);
               station2list4days += station2list4.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0008" && date > "2022" && date < "2023")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); 
               station2list5.insert(m_data);
               station2list5days += station2list5.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0008" && date > "2023" && date < "2024")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); 
               station2list6.insert(m_data);
               station2list6days += station2list6.daysaboveonehalf(prcp);                                                              }
               if (station == "US1CABT0019" && date < "2019" && date > "2018")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station3list1.insert(m_data);
               station3list1days += station3list1.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0019" && date < "2020" && date > "2019")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station3list2.insert(m_data);
               station3list2days += station3list2.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0019" && date > "2020" && date < "2021")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station3list3.insert(m_data);
               station3list3days += station3list3.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0019" && date > "2021" && date < "2022")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station3list4.insert(m_data);
               station3list4days += station3list4.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0019" && date > "2022" && date < "2023")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station3list5.insert(m_data);
               station3list5days += station3list5.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0019" && date > "2023" && date < "2024")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station3list6.insert(m_data);
               station3list6days += station3list6.daysaboveonehalf(prcp);                                                              }
               if (station == "US1CABT0009" && date < "2019" && date > "2018")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station4list1.insert(m_data);
               station4list1days += station4list1.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0009" && date < "2020" && date > "2019")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station4list2.insert(m_data);
               station4list2days += station4list2.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0009" && date > "2020" && date < "2021")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp); // line is to insert nodes into list
               station4list3.insert(m_data);
               station4list3days += station4list3.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0009" && date > "2021" && date < "2022")
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station4list4.insert(m_data);
               station4list4days += station4list4.daysaboveonehalf(prcp);
               }
               if (station == "US1CABT0009" && date > "2022" && date < "2023")                                      
               {                                                                                                      
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);                                              
               station4list5.insert(m_data);                                                                           
               station4list5days += station4list5.daysaboveonehalf(prcp);                                                              }
               if (station == "US1CABT0009" && date > "2023" && date < "2024")                                         
               {
               Data *m_data = new Data(station,name,date,dapr,mdpr,prcp);
               station4list6.insert(m_data);
               station4list6days += station4list6.daysaboveonehalf(prcp);                                                              }
               cin.ignore();
               }
       cout << "This program is designed to determine if there is a trend in frequencies of rainstorms by evaluating the change in perpication over the past six years" << endl;
       cout << "The four chico weather stations, US1CABT0012 US1CABT0008 US1CABT0019 US1CABT0009, cover different areas of chico. The program will display the the total days it has rained over 0.5 inches in the past 6 years." << endl;
       cout << "Station US1CABT0012, CHICO 1.8 SW, CA US" << endl;
       cout << "The total number of days it rained over 0.5 inches in 2018 is: " << station1list1days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2019 is: " << station1list2days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2020 is: " << station1list3days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2021 is: " << station1list4days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2022 is: " << station1list5days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2023 is: " << station1list6days << endl;
       cout << endl;
       cout << "Station US1CABT0008, CHICO 1.7 SW, CA US" << endl;
       cout << "The total number of days it rained over 0.5 inches in 2018 is: " << station2list1days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2019 is: " << station2list2days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2020 is: " << station2list3days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2021 is: " << station2list4days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2022 is: " << station2list5days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2023 is: " << station2list6days << endl;
       cout << endl;
       cout << "Station US1CABT0019, CHICO 0.2 ESE, CA US" << endl;
       cout << "The total number of days it rained over 0.5 inches in 2018 is: " << station3list1days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2019 is: " << station3list2days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2020 is: " << station3list3days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2021 is: " << station3list4days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2022 is: " << station3list5days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2023 is: " << station3list6days << endl;
       cout << endl;
       cout << "Station US1CABT0009, CHICO 2.9 W, CA US" << endl;
       cout << "The total number of days it rained over 0.5 inches in 2018 is: " << station4list1days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2019 is: " << station4list2days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2020 is: " << station4list3days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2021 is: " << station4list4days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2022 is: " << station4list5days << endl;
       cout << "The total number of days it rained over 0.5 inches in 2023 is: " << station4list6days << endl;
        return 0;
}
