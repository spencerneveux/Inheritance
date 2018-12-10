//
//  main.cpp
//  Inheritance
//
//  Created by Spencer Neveux on 12/6/18.
//  Copyright © 2018 Spencer Neveux. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include "Luggage.hpp"
using namespace std;
void mainMenu();
void option1();
void showLuggage();
vector<Luggage*> storage;
static int totalLuggage;
static double totalVolume;

int main(int argc, const char * argv[]) {
    int firstOption;
    int secondOption;
    do {
    mainMenu();
    cin >> firstOption;
    
    // Determine user choice
    if (firstOption == 1) {
            option1();
            cin >> secondOption;
            if (secondOption == 1) {
                    double width,length,height;
                    cout << "Enter Width: ";
                    cin >> width;
                    cout << "Enter Length: ";
                    cin >> length;
                    cout << "Enter Height: ";
                    cin >> height;
                    storage.push_back(new Box(width, height, length));
                }
                else if (secondOption == 2)
                {
                    double radius;
                    cout << "Enter Radius: ";
                    cin >> radius;
                    storage.push_back(new Sphere(radius));
                }
                else if (secondOption == 3) {
                    double side;
                    cout << "Enter Width: ";
                    cin >> side;
                    storage.push_back(new Cube(side));
                }
                else if (secondOption == 4) {
                    double length, width, height;
                    cout << "Enter length: ";
                    cin >> length;
                    cout << "Enter width: ";
                    cin >> width;
                    cout << "Enter height: ";
                    cin >> height;
                    storage.push_back(new Pyramid(length, width, height));
                }
                else if (secondOption == 5) {
                    double radius, length;
                    cout << "Enter radius: ";
                    cin >> radius;
                    cout << "Enter length: ";
                    cin >> length;
                    storage.push_back(new Cylinder(radius, length));
                }
                else if (secondOption == 6) {
                    double radius, height;
                    cout << "Enter radius: ";
                    cin >> radius;
                    cout << "Enter height: ";
                    cin >> height;
                    storage.push_back(new Ungula(radius, height));
                }
                else if (secondOption == 7) {
                    double height, mD, tD;
                    cout << "Enter height: ";
                    cin >> height;
                    cout << "Enter middle diameter: ";
                    cin >> mD;
                    cout << "Enter top diameter: ";
                    cin >> tD;
                    storage.push_back(new Barrel(height, mD, tD));
                }
                else if (secondOption == 8) {
                    double height, tD, bD;
                    cout << "Enter height: ";
                    cin >> height;
                    cout << "Enter top diameter: ";
                    cin >> tD;
                    cout << "Enter bottom diameter: ";
                    cin >> bD;
                    storage.push_back(new Frustrum(height, tD, bD));
                }
    }else if (firstOption == 2){
            vector<Luggage*>::iterator it;
            int count = 0;
        for (it = storage.begin(); it != storage.end(); it++) {
            count++;
            cout << count << ")";
            totalVolume -= (*it)->volume();
            totalLuggage--;
            (*it)->display();
        }
            int luggageRemoval;
            cout << "Enter Luggage to remove(Number): ";
            cin >> luggageRemoval;
            storage.erase(storage.begin() + (luggageRemoval - 1));
        
    }else if (firstOption == 3) {
        showLuggage();
    }
    }while(firstOption != 4);
    
    return 0;
}

void mainMenu() {
    cout << "1) Add luggage to storage container" << endl;
    cout << "2) Remove luggage from storage container" << endl;
    cout << "3) Show all luggage" << endl;
    cout << "4) Quit" << endl;
}

void option1() {
    cout << "Choose type of luggage" << endl;
    cout << "1) Box" << endl;
    cout << "2) Sphere" << endl;
    cout << "3) Cube" << endl;
    cout << "4) Pyramid" << endl;
    cout << "5) Cylinder" << endl;
    cout << "6) Ungula" << endl;
    cout << "7) Barrel" << endl;
    cout << "8) Frustrum" << endl;
}

void showLuggage() {
    vector<Luggage*>::iterator it;
    for (it = storage.begin(); it != storage.end(); it++) {
        (*it)->display();
        totalVolume += (*it)->volume();
        totalLuggage++;
    }
    cout << "Total Luggage Items: " << totalLuggage << endl;
    cout << "Total Volume: " << totalVolume << endl;
}
