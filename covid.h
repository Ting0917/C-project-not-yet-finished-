#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <iostream>
#include <string>
#include <cmath>
using std::ostream;
using std::string;



// TODO: your code  goes here
#include <math.h>

class CovidCase {

    private:
    //private data
    double latitude;
    double longitude;
    string name;
    int age;
    int time;

    public:

    // constructor
        CovidCase(double lat, double lon, string nm, int ag, int tm)
        {
            latitude= lat;
            longitude= lon;
            name = nm;
            age = ag;
            time = tm;
        }
        //method for operator
        friend ostream & operator << (ostream & print, const CovidCase& data)
        {
            print << "{"<< data.latitude <<", "<<data.longitude<<", \""<<data.name<<"\", "<<data.age<<", "<<data.time<<"}";
            return print;
        }

        //distance calculation
        double distanceTo(const CovidCase & data)
        {

            double dlong = (data.longitude*(M_PI/180))-(longitude*(M_PI/180)) ;
            double dlat = (data.latitude*(M_PI/180))-(latitude*(M_PI/180)) ;
            double a = pow((sin(dlat/2)), 2) + cos(latitude*(M_PI/180)) * cos(data.latitude*(M_PI/180)) * pow((sin(dlong/2)), 2);
            double c = 2 * atan2(sqrt(a), sqrt(1-a));
            double distance = 3960 * c;
            return distance;  
        }
};



// don't write any code below this line

#endif
