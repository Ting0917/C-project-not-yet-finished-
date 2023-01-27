#ifndef COVIDCASEMAP_H
#define COVIDCASEMAP_H

#include "CovidCase.h"
#include <vector>
#include <iostream>
#include <string>
#include <math.h>


using std::ostream;

// TODO: your code goes here


class TimeAndCaseData{

private:
int time;
int numOfCases;

public:

TimeAndCaseData(int tm, int numOfCasess)
    {
        time = tm;
        numOfCases = numOfCasess;
    }

int getTime()
    {
        return time;
    }

int getNumberOfCases()
    {
        return numOfCases;
    }

};


class CovidCaseMap{
private:

std::vector <CovidCase> listOfCases;

public:

void addCase(CovidCase addNew)
    {

        listOfCases.push_back(addNew);
    }

vector <TimeAndCaseData> getCasesOverTime (int hrsOfActive)
    {
        int total = 0; 
        
        vector <TimeAndCaseData> theData;
        int c = 0;
        int count =0;

        theData.push_back(TimeAndCaseData(total,count));
        //120 hrs of active time then eliminate
        while( c<listOfCases.size() && total<(listOfCases[listOfCases.size()-1].getTime()+120))
        {
           if(total==listOfCases[c].getTime()){
                 count += 1;
                 c += 1;
                 theData.push_back(TimeAndCaseData(total,count));
             }
             
             total += 1;
             
             for(int i=0;i<listOfCases.size();i++){
                if(total-listOfCases[i].getTime()==120){
                    //120 hrs of active time then eliminate
                    count -= 1;
                    theData.push_back(TimeAndCaseData(total,count));
                }
             }
         }
         
         return theData;
    }

    double calcTSP(double tempLat, double tempLong, int tempLat2, int tempLong2)
        
    {
            
    double dlong = 0;
    double longg = tempLong;
    double long2 = tempLong2;
    double dlat = 0;
    double lat1 = tempLat;
    double lat2 = tempLat2;
    double result = 0;
    double final = 0;
    double distance = 0;


    longg = longg * M_PI / 180;
    long2 = long2 * M_PI / 180;
    lat1 = lat1 * M_PI / 180;
    lat2 = lat2 * M_PI / 180;


    dlong = (long2) - (longg);
    dlat = (lat2) - (lat1);
    result = pow((sin(dlat/2)), 2) + cos(lat1) * cos(lat2) * pow((sin(dlong/2)), 2);
    final = 2 * atan2(sqrt(result), sqrt(1-result));
    distance = 3960 * final;

    return distance;

    }

    bool whetherExist (vector <double> tempVec, double tempDouble)
        {
            for (int b = 0 ; b<tempVec.size() ; b++)
            {
                if (tempVec[b] ==tempDouble)
                {
                    return false;
                    break;
                }
                else
                {
                    continue;
                }
        }
        return true;
    }


    double supportVisitGreedyTSP(double currentLat, double currentLong, int time, int isolationPeriod)
        {
            //plug in cases into the vector
            vector <double> tempList;


            double startLat = currentLat;
            double startLong = currentLong;
            double lastLat = 0;
            double lastLong = 0;
            double currentRoute = 0;
            double totalRoute = 0;
            double minimumRoute;
            double finalLat;
            double finalLong;
            bool assume = true;

            tempList.push_back(100000);

            while (tempList.size()<= listOfCases.size())
            {
                minimumRoute = 100000;
                for (int i =0; i<listOfCases.size(); i++)
                {
                    assume = whetherExist(tempList, listOfCases[i].getLatitude());

                    if (assume == true)
                    {
                        if (listOfCases[i].getTime() > time || listOfCases[i].getTime() + isolationPeriod < time)
                        {
                            tempList.push_back(listOfCases[i].getLatitude());
                        }
                        else
                        {
                            lastLat=listOfCases[i].getLatitude();
                            lastLong=listOfCases[i].getLongitude();
                            currentRoute = calcTSP(startLat, startLong, lastLat, lastLong);

                        }

                        if (currentRoute< minimumRoute)
                        {
                            minimumRoute= currentRoute;
                            finalLat= lastLat;
                            finalLong= lastLong;
                        }
                        } else
                        {
                            continue;
                        }

                }

                startLong= finalLong;
                startLat = finalLat;

                totalRoute= totalRoute+minimumRoute;
                tempList.push_back(startLat);
            }
            
            totalRoute = totalRoute + calcTSP(startLat, startLong, currentLat, currentLong);
                return totalRoute;

        }

        
    };


// don't write any code below this line

#endif
