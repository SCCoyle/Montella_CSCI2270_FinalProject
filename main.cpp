//
//  main.cpp
//  FinalProject
//
//  Created by Michael Montella on 4/24/16.
//  Copyright © 2016 Michael Montella. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <sstream>
#include "statTree.h"

using namespace std;



int main(int argc, char * argv[]) {
    
    StatTree TreeStat;
    
    ifstream inFile;
    inFile.open(argv[1]);
    if (inFile.good()) {
        //cout << "Thou file twas opened with thy greatest of successes" << endl;
        string data;
        
        while(getline(inFile, data)) {
            stringstream ss(data);
            
            // Season
            string season;
            getline(ss, season, ',');
            // Points
            string points;
            getline(ss, points, ',');
            // Games
            string games;
            getline(ss, games, ',');
            // Games Started
            string gamesStarted;
            getline(ss, gamesStarted, ',');
            // Field Goal
            string fieldGoal;
            getline(ss, fieldGoal, ',');
            // 3 Point
            string threePoint;
            getline(ss, threePoint, ',');
            // 2 Point
            string twoPoint;
            getline(ss, twoPoint, ',');
            // Free Throw
            string freeThrow;
            getline(ss, freeThrow, ',');
            // Average Points
            string averagePoints;
            getline(ss, averagePoints, ',');
            
            TreeStat.addStatNode(season, stoi(points), stoi(games), stoi(gamesStarted), stod(fieldGoal), stod(threePoint), stod(twoPoint), stod(freeThrow), stod(averagePoints));
            
        }
    }
    
    int choice = 0;
    while (choice != 4) {
        TreeStat.printMenu();
        string choiceS;
	getline(cin,choiceS);
	stringstream convert(choiceS);
	convert >> choice;
        
        if (choice == 1) {      // Calculate total points scored
            TreeStat.printTotalPoints();
        } else if (choice == 2) {
            string choice2;
            
            cout << "What would you like to rank by?" << endl;
            cout << "1. Total points" << endl;
            cout << "2. Average Points per game" << endl;
            cout << "3. 3 Point percentage" << endl;
            
            getline(cin, choice2);
            if (stoi(choice2) == 1) {
                TreeStat.rankByPoints();
            } else if (stoi(choice2) == 2) {
                cout << endl;
                TreeStat.rankByAvgPoints();
                cout << endl;
            } else if (stoi(choice2) == 3) {
                TreeStat.rankByThreePoint();
            }
            
        } else if (choice == 3) {
            string year;
                        
            cout << "Which season would you like to look at?" << endl;
            cout << "Enter the last 2 digits of each year like this: 'yy-yy'  (i.e. for Kobe's first season, put '96-97'" << endl;
            
            getline(cin, year);
            
            TreeStat.printSeasonStats(year);
            
        } else if (choice == 4) {
            cout << "Goodbye" << endl;
        }
    }
}
