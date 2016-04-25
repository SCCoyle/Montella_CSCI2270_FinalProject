//
//  statTree.cpp
//  FinalProject
//
//  Created by Michael Montella on 4/24/16.
//  Copyright © 2016 Michael Montella. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include "statTree.h"

using namespace std;

StatTree::StatTree() {
    root = NULL;
}

// Adds node to binary treeeeeeeeeeeeeeee
void StatTree::addStatNode(string season, int points, int games, int gamesStarted, double fieldGoal, double threePoint, double twoPoint, double freeThrow, double avgPoints)
{
   
    statNode *temp = new statNode;
    statNode *parent = NULL;
    
    temp -> parent = NULL;
    temp -> leftChild = NULL;
    temp -> rightChild = NULL;
    
    statNode *node = new statNode(season, points, games, gamesStarted, fieldGoal, threePoint, twoPoint, freeThrow, avgPoints);
    
    node -> parent = NULL;
    node -> leftChild = NULL;
    node -> rightChild = NULL;
    
    temp = root;
    bool left = true;
    while (temp != NULL) {
        parent = temp;
        if (node -> points < temp -> points) {
            temp = temp -> leftChild;
            left = true;
        } else {
            temp = temp -> rightChild;
            left = false;
        }
    }
    
    if (parent == NULL) {
        root = node;
    } else if (left) {
        parent -> leftChild = node;
        node -> parent = parent;
    } else {
        parent -> rightChild = node;
        node -> parent = parent;
    }
    
}

// Calls private findSeason function
void StatTree::printSeasonStats(string season) {
    findSeason(root, season);
}

// Traverses tree until it finds the right season
void StatTree::findSeason(statNode *node, string season) {
    
    bool exists = false;
    
    // In Order Tree Traversal
    if (node) {
        if (node -> season == season) {
            exists = true;
        } else {
            findSeason(node -> leftChild, season);
            
            findSeason(node -> rightChild, season);
        }
    }
    
    // If it exists, print all dis cheese
    if (exists) {
        cout << endl;
        cout << "----- " << node -> season << " -----" << endl;
        cout << "Points: " << node ->points << endl;
        cout << "Games: " << node -> games << endl;
        cout << "Games Started: " << node -> gamesStarted << endl;
        cout << "Field Goal Percentage: " << node -> fieldGoal << endl;
        cout << "3 Point Percentage: " << node -> threePoint << endl;
        cout << "2 Point Percentage: " << node -> twoPoint << endl;
        cout << "Free Throw Percentage: " << node -> freeThrow << endl;
        cout << "Average Points Per Game: " << node -> avgPoints << endl;
        cout << endl;
    }
}

// Calls private findTotalPoints function
// I could have hard coded... but I didn't
void StatTree::printTotalPoints() {
    int totalPoints = 0;
    findTotalPoints(root, &totalPoints);
    cout << "Total Points Scored: " << totalPoints << endl;
}

// Traverses tree and adds up all the points
void StatTree::findTotalPoints(statNode *node, int *totalPoints) {
    if (node -> leftChild != NULL) {
        findTotalPoints(node -> leftChild, totalPoints);
    }
    *totalPoints += node -> points;
    if (node -> rightChild != NULL) {
        findTotalPoints(node -> rightChild, totalPoints);
    }
}


// Calls private rankPoints function
void StatTree::rankByPoints(){
    rankPoints(root);
}

// Traverses tree and prints out the ranking of seasons by points scored
// Jokes on you, it was already sorted by points so this was easy
void StatTree::rankPoints(statNode *node) {
    if (node -> leftChild != NULL) {
        rankPoints(node -> leftChild);
    }
    cout << node -> season << " : " << node -> points << endl;
    if (node -> rightChild != NULL) {
        rankPoints(node -> rightChild);
    }
}

// Calls addToArray function and sortFunction
// Prints results
void StatTree::rankByAvgPoints() {
    int i = 0;
    addToArrayAverage(root, array, arrayOfSeasons, i);
    sortArray(array, arrayOfSeasons);
    
    for (int i = 0; i < 20; i++) {
        cout << arrayOfSeasons[i] << " : " << array[i] << endl;
    }
}

// Calls addToArray function and sortFunction
// Prints dank memes... I mean... results
void StatTree::rankByThreePoint() {
    int i = 0;
    addToArrayThree(root, array, arrayOfSeasons, i);
    sortArray(array, arrayOfSeasons);
    
    for (int i = 0; i < 20; i++) {
        cout << arrayOfSeasons[i] << " : " << array[i] << endl;
    }
}

// Traverses tree and adds average points to one array and season to another
int StatTree::addToArrayAverage(statNode *node, double *arr, string *arrayOfSeasons, int i) {
    if (node == NULL) {
        return i;
    }
    
    arr[i] = node -> avgPoints;
    arrayOfSeasons[i] = node -> season;
    i++;
    
    if (node -> leftChild != NULL) {
        i = addToArrayAverage(node -> leftChild, arr, arrayOfSeasons, i);
    }
    if (node -> rightChild != NULL) {
        i = addToArrayAverage(node -> rightChild, arr, arrayOfSeasons, i);
    }
    
    return i;
}

// Traverses tree and adds three point % to one array and season to another
int StatTree::addToArrayThree(statNode *node, double *arr, string *arrayOfSeasons, int i) {
    if (node == NULL) {
        return i;
    }
    
    arr[i] = node -> threePoint;
    arrayOfSeasons[i] = node -> season;
    i++;
    
    if (node -> leftChild != NULL) {
        i = addToArrayThree(node -> leftChild, arr, arrayOfSeasons, i);
    }
    if (node -> rightChild != NULL) {
        i = addToArrayThree(node -> rightChild, arr, arrayOfSeasons, i);
    }
    
    return i;
}

// Sorts array with values in it
// Array of seasons gets sorted with it so they stay paired up because buddy system
void StatTree::sortArray(double *arr, string *array) {
    double temp;
    string temp2;
    for (int i = 0; i < 20; i++) {
        for (int j = 0; j < 19; j++) {
            if (arr[j] > arr[i]) {
                temp = arr[i];
                temp2 = array[i];
                
                arr[i] = arr[j];
                arr[j] = temp;
                
                array[i] = array[j];
                array[j] = temp2;
            }
        }
    }
}


// Prints the super sick menu
void StatTree::printMenu() {
    cout << "===== MENU =====" << endl;
    cout << "1. Calculate Total points scored" << endl;
    cout << "2. Rank seasons" << endl;
    cout << "3. View specific season" << endl;
    cout << "4. Quit" << endl;
}
