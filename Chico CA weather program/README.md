# Weather program
## Name: Alejandro Barajas
## Chico Portal/INGInious username: Ajbarajas
## CSCI 211 Programming and Algorithms II, Spring 2024
## list of the files/directories: ADT.h - Abstract data type of linked lists, ADT.cpp - funtions that create a linked list, data.h - contains a class where the data is inserted at, data.cpp - has one function that prints what's in the data set, main.cpp - the main file that has the functions to calculate the total number of days it has rained over 0.5 inches. csv.cpp csv file that contains the data of stations in Chico california over the past 6 years. weather.cpp - creates a converted file of data that can be used in main, converted2.in - the data from csv.cpp that has been converted to be useable, Makefile - compiles the code.
## The goal of this program is to answer one simple question, is there a recent trend in the frequency or intensity of rainstorms in Chico California?
### In order to use this program, the user will begin by typing "make" in order to compile the file. The next step the user need to do is to redirect the ADT program to the file labeled "converted2.in", which is done by typing "./ADT < converted2.in".
### Once the file is redirected the program will then output the total number of days it has rained over 0.5 inches from2018 to 2024. The data is received from the four weather stations in Chico California.
### With the results of the program Chico locals can investigate if there is a trend in the frequency or intensity of rainstorms in their area. The results can be useful to farmers or researchers who are comparing the frequency or intensity of rainstorms in each city of Butte County as it shows how the amount of rain can vary over time within one city, especially in one area compared to another.
### I approached this project by analyzing how the data from the weather stations can be used to determine if there has been a trend in the frequency of rainstorms. The key variables that were needed to determine this, are the daily amounts of precipitation as It helps me determine the amount of days that had over 0.5 inches of rain and the stations as each station covers a different part of chico. The main file uses data type class to store the data of a certain day from a certain station. The data then stores the data in a linked lists, since the linked list is dynamically it would make sense for each node to represent a day and as the further you traverse the nodes the more days you are passing.