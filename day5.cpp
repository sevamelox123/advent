#include <iostream>
#include <cstdio>
#include <vector>

int main()
{
    FILE *input = fopen("input1.txt", "r");
    std::string line;
    std::vector<int> _line;
    char c;
    int counter = 0;
    u_int64_t sum = 0;
    while ((c = fgetc(input)) != EOF)
    {
        if (c != '\n')
        {
            counter++;
        }
    }

    fseek(input, 0, SEEK_SET);
    for (int i = 0; i < counter; i++)
    {
        c = fgetc(input);
        if (i % 2 != 0)
        {
            for (int g = 0; g < (c - '0'); g++)
            {
                line += '.';
                _line.push_back(-1);
            }
        }
        else
        {
            for (int f = 0; f < (c - '0'); f++)
            {
                line += std::to_string(i / 2);
                _line.push_back(i / 2);
            }
        }
    }
    // std::cout << line << std::endl;
    fseek(input, 0, SEEK_SET);
    int l = 0, r = _line.size() - 1;
    while (l < r)
    {
        while (_line[l] != -1)
        {
            l++;
        }
        while (_line[r] == -1)
        {
            r--;
        }
        if (l >= r)
            break;
        _line[l] = _line[r];
        _line[r] = -1;
    }
    std::cout << line << std::endl;
    for (size_t i = 0; i < _line.size(); i++)
    {
        // c = fgetc(input);
        if (_line[i] == -1)
            continue;
        sum += i * _line[i];
    }
    std::cout << sum << std::endl;
    return 0;
}