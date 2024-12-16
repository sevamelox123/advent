#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    FILE *input = fopen("input1.txt", "r");
    char c;
    double x1 = 0, x2 = 0, y1 = 0, y2 = 0, z1 = 0, z2 = 0;
    unsigned long long answer = 0;
    while ((c = fgetc(input)) != EOF)
    {
        if (c != '\n')
        {
            // cout << c;
            fseek(input, -1,SEEK_CUR);
            fscanf(input,"Button A: X+%lf, Y+%lf", &x1, &y1);
            // cout << " " << x1 << " " << y1;
            fseek(input, 1, SEEK_CUR);
            fscanf(input,"Button B: X+%lf, Y+%lf", &x2, &y2);
            // cout << " " << x2 << " " << y2;
            fseek(input, 1, SEEK_CUR);
            fscanf(input, "Prize: X=%lf, Y=%lf", &z1, &z2);
            // cout << " " << z1 << " " << z2;
            z1 += 10000000000000;
            z2 += 10000000000000;
            double det = x1 * y2 - x2 * y1;
            double det_a = z1 * y2 - x2 * z2;
            double det_b = x1 * z2 - z1 * y1;

            double presses_a = det_a / det;
            double presses_b = det_b / det;
            cout << presses_a << " " << presses_b;
            if(presses_a == static_cast<long long>(presses_a) && presses_b == static_cast<long long>(presses_b))
            {
                answer += static_cast<unsigned long long>(presses_a * 3 + presses_b);
            }
        }
        else
        {
            cout << endl;
        }
    }

    cout << answer << endl;

    fclose(input);
    return 0;
}