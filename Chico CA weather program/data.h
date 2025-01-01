// filename: data.h
// Short summary of the file contents: This file contains the contents of a class called Data. The data is the data of a day from the Chico weather station
#ifndef DATA_H
#define DATA_H
#include <iostream>
using namespace std;
    class Data
{
        public:
                Data(string station, string name, string date, string dapr, double mdpr, double prcp)       
                       {
                               m_station = station;
                               m_name = name;
                               m_date = date;
                               m_dapr = dapr;
                               m_mdpr = mdpr;
                               m_prcp = prcp;
                       }
                string GetStation() { return m_station;}
                string GetDapr() { return m_dapr;}
                double GetMdpr() { return m_mdpr;}
                string GetName() { return m_name;}
                string GetDate() { return m_date;}
                double GetPrcp() { return m_prcp;}
                void print();
        private:
                string m_station;
                string m_name;
                string m_dapr;
                double m_mdpr;
                string m_date; 
                double m_prcp;
};
#endif
