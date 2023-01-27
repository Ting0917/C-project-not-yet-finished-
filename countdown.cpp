#ifndef COUNTDOWN_H
#define COUNTDOWN_H

#include <string>
#include <sstream>
#include <vector>


using std::vector;
using std::ostream;
using std::string;
using std::stod;


// this is provided code for the last part of the README

std::string intToString(const int x) {
    std::ostringstream str;
    str << x;
    return str.str();
}

class CountdownSolution {
  
private:
    std::string solution;
    int value;
    
public:
    
    CountdownSolution() : solution(), value(0) {}
    
    CountdownSolution(const std::string & solutionIn, const int valueIn)
        : solution(solutionIn), value(valueIn) {
    }
    
    const std::string & getSolution() const {
        return solution;
    }
    
    int getValue() const {
        return value;
    }
    
};

// Do not edit above this line

// TODO: write code here:

double evaluateCountdown(std::string tokens)
{
    vector<std::string> vector;

    string s;

    for (int i = 0; i < tokens.length(); i++)
    {   
        
        if (string(1,tokens[i]).compare(" ") != 0)
        {
            s += (tokens[i]);
            
        }
        else {
            vector.push_back(s);
            s = "";

        }
        if (i== tokens.length()-1 && !s.empty()){
            vector.push_back(s);
        }
    }
    
    double temp = 0, k = 0;
    for (int i = 0; i < vector.size(); ++i, k++)
    {
        double a1 = 0, a2 = 0;
        if (k > 1)
        {
            if (i != 2)
            {
                a1 = temp;
            }

            if (vector[i] == "+")
            {
                a2 = std::stod(vector[i - 1]);
                if (i != 2)
                {
                    a1 = temp;
                }else {
                    a1 = std::stod(vector[i - 2]);
                }
                temp = a1 + a2;
            }
            else if (vector[i] == "-")
            {
                a2 = std::stod(vector[i - 1]);
                if (i != 2)
                {
                    a1 = temp;
                }else {
                    a1 = std::stod(vector[i - 2]);
                }
            
                temp = a1 - a2;
            }
            else if (vector[i] == "*")
            {   
                a2 = std::stod(vector[i - 1]);
                if (i != 2)
                {
                    a1 = temp;
                }else {
                    a1 = std::stod(vector[i - 2]);
                }

                temp = a1 * a2;
            }
            else if (vector[i] == "/")
            {   
                a2 = std::stod(vector[i - 1]);
                if (i != 2)
                {
                    a1 = temp;
                }else {
                    a1 = std::stod(vector[i - 2]);
                }
                temp = a1 / a2;
            }
        }
        
    }

    return temp;
};


void recursiveFunc(vector<int> vec, int t, int &value)
{
    if (vec.size() <= 1)
    {

        if (abs(vec[0] - t) < abs(value - t))
        {
            value = vec[0];
        }
        return;
    }
    
    if (vec.size() >= 2)
    {
        for (int i = 0; i < 4; i++)
        {
            vector<int> ar;
            int start;

            if (i == 0)
            {
                start = vec[0] + vec[1];
            }

            else if (i == 1)
            {
                start = vec[0] - vec[1];
            }
            else if (i == 2)
            {
                start = vec[0] * vec[1];
            }
            else
            {
                start = vec[0] / vec[1];
            }

            if (abs(start - t) < abs(value - t))//absolute value
            {
                value = start;
            }
            ar.push_back(start);
            for (int j = 2; j < vec.size(); j++)
            {
                ar.push_back(vec[j]);
            }
            recursiveFunc(ar, t, value);
        }
    }
}
CountdownSolution solveCountdownProblem(vector<int> vec, int t)
{
    int value = 999999;
    recursiveFunc(vec, t, value); //calling helper function
    CountdownSolution ans("answer", value);
    return ans;
};


// Do not edit below this line


#endif
