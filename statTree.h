//
//  statTree.h
//  FinalProject
//
//  Created by Michael Montella on 4/24/16.
//  Copyright © 2016 Michael Montella. All rights reserved.
//

#ifndef statTree_h
#define statTree_h

struct statNode {
    std::string season;
    int points;
    int games;
    int gamesStarted;
    double fieldGoal;
    double threePoint;
    double twoPoint;
    double freeThrow;
    double avgPoints;
    
    statNode *parent;
    statNode *leftChild;
    statNode *rightChild;
    
    statNode(){};
    
    statNode(std::string in_season, int in_points, int in_games, int in_gamesStarted, double in_fieldGoal, double in_threePoint, double in_twoPoint, double in_freeThrow, double in_avgPoints)
    {
        
        season = in_season;
        points = in_points;
        games = in_games;
        gamesStarted = in_gamesStarted;
        fieldGoal = in_fieldGoal;
        threePoint = in_threePoint;
        twoPoint = in_twoPoint;
        freeThrow = in_freeThrow;
        avgPoints = in_avgPoints;
        
        parent = NULL;
        leftChild = NULL;
        rightChild = NULL;
        
    }
};

class StatTree {

public:
    StatTree();
    void addStatNode(std::string season, int points, int games, int gamesStarted, double fieldGoal, double threePoint, double twoPoint, double freeThrow, double avgPoints);
    
    void printTotalPoints();
    void rankByPoints();
    void rankByAvgPoints();
    void rankByThreePoint();
    void printSeasonStats(std::string season);
    int addToArrayAverage(statNode *node, double arr[], std::string arrayOfSeasons[], int i);
    int addToArrayThree(statNode *node, double arr[], std::string arrayOfSeasons[], int i);
    void sortArray(double arr[], std::string array[]);
    void printMenu();
    
    std::string arrayOfSeasons[20];
    double array[20];
    
private:
    void findSeason(statNode *node, std::string season);
    void findTotalPoints(statNode *node, int *totalPoints);
    void rankPoints(statNode *node);
    statNode *root;
};

#endif /* statTree_h */
