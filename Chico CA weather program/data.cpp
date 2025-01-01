// filename: data.cpp
// Short summary of the file contents: This file contains the function that prints out the data
#include "data.h"
#include <iostream>
using namespace std;
void Data::print()
{
        cout << "station: " << m_station << " location: "  << m_name << " date: " << m_date << " dapr: "<< m_dapr << " mdpr: " << m_mdpr << " prcp: " << m_prcp << "." << endl;
}
