#ifndef COVIDCASE_H
#define COVIDCASE_H

#include <iostream>
#include <string>
#include <cmath>
using std::ostream;
using std::string;
using namespace std;


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

        CovidCase(string str)
		{
			string lat1, long1, age1;
			int order;
			order = str.find(","); //try to find comma from the string
			lat1 = str.substr(0, order);

			str = str.substr(order + 1);
	
			latitude = stod(lat1);

			order = str.find(",");

			long1 = str.substr(0, order);

			str = str.substr(order+1);

			longitude = stod(long1);

			order = str.find("\"");

			str = str.substr(order +1);

			order = str.find("\"");

			name = str.substr(0, order);//removing name from the string

			order = str.find(",");

			str = str.substr(order +1);

			order = str.find(",");

			age1 = str.substr(0, order);

			str = str.substr(order +1);

			age = stoi(age1);

			time = stoi(str);
		};


        //method for operator
        friend ostream & operator << (ostream & print, const CovidCase& data)
        {
            print << "{"<< data.latitude <<", "<<data.longitude<<", \""<<data.name<<"\", "<<data.age<<", "<<data.time<<"}";
            return print;
        }

        //equality operator
        bool operator==(CovidCase &data)
        {
        	if(latitude == data.latitude && longitude == data.longitude && name == data.name && age == data.age && time == data.time)
        	{
        		return true;
        	}
        	
        	return false;
        }


        double getLatitude()
        {
        	return latitude;
        }

        double getLongitude()
        {
        	return longitude;
        }

        string getName()
        {
        	return name;
        }

        int getAge()
        {
        	return age;
        }

        int getTime()
        {
        	return time;
        }

        //distance calculation
        double distanceTo(const CovidCase & data)
        {

            double dlong = (data.longitude*(M_PI/180))-(longitude*(M_PI/180)) ;
            double dlat = (data.latitude*(M_PI/180))-(latitude*(M_PI/180)) ;
            double a = pow((sin(dlat/2)), 2) + cos(latitude*(M_PI/180)) * cos(data.latitude*(M_PI/180)) * pow((sin(dlong/2)), 2);
            double c = 2 * atan2(sqrt(a), sqrt(1-a));
            double distance make TestTreeD= 3960 * c;
            return distance;  
        }
};



// don't write any code below this line

#endif
