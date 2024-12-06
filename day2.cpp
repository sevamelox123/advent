#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <vector>
#include <math.h>
using namespace std;

bool Checker(vector<int> *pivnaya_kega)
{
    vector<int> Vec = *pivnaya_kega;
    for (int i = 1; i < Vec.size(); i++)
        if (!((abs(Vec[i] - Vec[i - 1]) >= 1) && (abs(Vec[i] - Vec[i - 1]) <= 3)))
        {
            return false;
            break;
        }
        else
        {
            if (i >= 2)
            {
                if ((Vec[i] - Vec[i - 1] < 0 && Vec[i - 1] - Vec[i - 2] > 0) ||
                    (Vec[i] - Vec[i - 1] > 0 && Vec[i - 1] - Vec[i - 2] < 0))
                {
                    return false;
                    break;
                }
            }
        }
    return true;
}
int main()
{
    string filePath = "input1.txt";

    ifstream file(filePath);

    if (!file.is_open())
    {
        cerr << "Failed to open file: " << filePath << endl;

        return 1;
    }
    string line;
    int num = 0;
    int counter = 0;
    int line_count = 0;
    while (getline(file, line))
    {
        line_count++;
        stringstream ss(line);
        vector<int> Vec;
        while (ss >> num)
        {
            Vec.push_back(num);
        }
        for (int i = 0; i < Vec.size(); i++)
        {
            std::cout << Vec[i] << " ";
        }
        std::cout << endl;

        if (Checker(&Vec))
        {
            counter++;
        }
        else
        {
            for(int i = 0; i <Vec.size(); i++)
            {
                vector<int> parasha = Vec;
                parasha.erase(parasha.begin()+i);
                if(Checker(&parasha))
                {
                    counter++;
                    break;
                }
            }
        }

        Vec.clear();
    }
    cout << counter << endl;
    file.close();
    return 0;
}