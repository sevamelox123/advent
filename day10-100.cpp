#include <iostream>
#include <vector>
#include <cstdio>
#include <math.h>

using namespace std;

int GetDigitCount(int n)
{
    int res = 0;
    while (n)
    {
        res++;
        n /= 10;
    }
    return res;
}

int main()
{
    FILE *input = fopen("input1.txt", "r");
    char c;
    int blinks = 25;
    vector<int> vec;
    while ((c = fgetc(input)) != EOF)
    {
        fseek(input, -1, SEEK_CUR);
        int num = 0;
        fscanf(input, "%d", &num);
        vec.push_back(num);
        cout << num << " ";
    }
    for (int lapse = 0; lapse < blinks; lapse++)
    {
        cout << lapse << " " << vec.size() << endl;
        for (int i = 0; i < vec.size(); i++)
        {
            // cout << i << endl;
            if (vec[i] == 0) {
                vec[i] = 1;
            }
            else if (GetDigitCount(vec[i]) % 2 == 0)
            {
                int left_half = vec[i] / pow(10, GetDigitCount(vec[i]) / 2);
                int right_half = vec[i] % static_cast<int>(pow(10, GetDigitCount(vec[i]) / 2));

                vec[i] = left_half;
                vec.insert(next(vec.begin(), i + 1), right_half);
                i++;
            }
            else
            {
                vec[i] *= 2024;
            }
        }
    }

    cout << vec.size() << endl;

    return 0;
}