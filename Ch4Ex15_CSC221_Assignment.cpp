/*
Title: Chapter 4 Exercise 15 - Shipping Charges
File Name : Ch4Ex15_CSC221_Assignment
Programmer : Brion Blais
Date : 10 / 2024
Requirements :
Write a program that asks for the weight of the package and the distance to ship.  Then display charges.
Use input validation: Weight greater than 0, but less than 20kg.  No distances less than 10 miles or more than 3000 miles.
    

 */

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double weight;
double miles;

double valWeight();
double valDistance();
double calcCharge();

int main()
{
    bool makingEntries = 1;
    double cost;
    
    cout << "Welcome to the shipping charge calculator.\n" << endl;
    while (makingEntries == 1) {
        cout << "Please enter the weight of the package in kilograms. ";
        cin >> weight;
        weight = valWeight();
        cout << endl;
        cout << "Please enter the distance to ship the package in miles. ";
        cin >> miles;
        miles = valDistance();        
        miles = round(miles);
        cost = calcCharge();
        cout << setprecision(2) << fixed;
        cout << endl << "The cost to ship this package is: $" << cost << endl;
        cout << "Press 1 to calculate the cost of another package. ";
        cin >> makingEntries;
     }
    return 0;
    
}

double valWeight() {
    while ((weight <= 0) || (weight > 20)) {
        cout << "You have made an invalid weight entry, please enter a package weight 20 kilograms or less.\n";
        cin.clear();
        cin >> weight;
    }
    return weight;
}

double valDistance() {
    while ((miles < 10) || (miles > 3000)) {
        cout << "You have made an invalid mileage entry, please enter a distance between 10 and 3000 miles.\n";
        cin.clear();
        cin >> miles;
    }
    return miles;
}

double calcCharge() {
    double rate = 0.00;
    if (weight <= 2.00) {
        rate = 1.10 / 500;
    }
    else if ((weight > 2.00) && (weight <= 6.00)) {
        rate = 2.20 / 500;
    }
    else if ((weight > 6.00) && (weight <= 10.00)) {
        rate = 3.70 / 500;
    }
    else if ((weight > 10.00) && (weight <= 20.00)) {
        rate = 4.80 / 500;
    }
    else cout << "The program has made an error.";

    return (rate * miles);
}
