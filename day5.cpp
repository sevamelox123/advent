#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
struct PlayerPos{
    int _ypos = 0;
    int _xpos = 0;
};
int main()
{
    FILE *input;
    input = fopen("input1.txt", "r");
    char c;
    int width = 0, height = 0;
    vector<vector<char>*> pivo;
    while ((c = fgetc(input)) != EOF)
    {
        if (c == '\n')
        {
            
            break;
        }
        width++;
    }
    fseek(input, 0, SEEK_SET);
    while ((c = fgetc(input)) != EOF) {
        if (c == '\n') {
            height++;
        }
    }
    fseek(input, 0, SEEK_SET);
    // cout << width << " " << height << endl;
    for(int i = 0 ; i<width; i++)
    {
        pivo.push_back(new vector<char>);
        for(int j = 0; j<height; j++)
        {
            char c = fgetc(input);
            pivo[i]->push_back(c);
            cout << (*pivo[i])[j];
        }
        cout << endl;
        fseek(input, 1, SEEK_CUR);
    }
    fclose(input);
    return 0;
}