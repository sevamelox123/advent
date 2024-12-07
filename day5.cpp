#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <math.h>
using namespace std;
bool makeEquationTrue(u_int64_t target, const vector<u_int64_t> vec)
{
    for (u_int64_t i = 0; i < pow(3, vec.size() - 1); i++)
    {
        vector<char> operators(vec.size() - 1);
        u_int64_t tmp = i;
        for (u_int64_t j = 0; j < operators.size(); j++)
        {
            if (tmp % 3 == 0)
            {
                operators[operators.size() - 1 - j] = '+';
            }
            else if (tmp % 3 == 1)
            {
                operators[operators.size() - 1 - j] = '*';
            }
            else
            {
                operators[operators.size() - 1 - j] = '|';
            }
            tmp /= 3;
        }
        u_int64_t result = vec[0];
        for (u_int64_t j = 1; j < vec.size(); j++)
        {
            if (operators[j - 1] == '+')
            {
                result += vec[j];
            }
            if (operators[j - 1] == '*')
            {
                result *= vec[j];
            }
            if (operators[j - 1] == '|')
            {
                std::string tmp_s = std::to_string(result);
                tmp_s.append(std::to_string(vec[j]));
                result = std::stol(tmp_s);
            }
        }
        if (result == target)
        {
            return true;
        }
    }
    return false;
}

int main()
{
    FILE *input = fopen("input1.txt", "r");

    char c;
    int state = 0;
    u_int64_t firstnum = 0;
    u_int64_t result = 0;
    vector<u_int64_t> vec;

    while ((c = fgetc(input)) != EOF)
    {
        if (c == '\n')
        {
            if (makeEquationTrue(firstnum, vec))
            {
                result += firstnum;
            }
            state = 0;
            vec.clear();
        }
        else
        {
            fseek(input, -1, SEEK_CUR);
            u_int64_t num = 0;
            char d;
            if (c != ':' && (state == 0))
            {
                fscanf(input, "%li", &firstnum);
            }
            else
            {
                state = 1;
                fseek(input, 1, SEEK_CUR);
                fscanf(input, "%li", &num);
                vec.push_back(num);
            }
        }
    }
    cout << result;
    return 0;
}
