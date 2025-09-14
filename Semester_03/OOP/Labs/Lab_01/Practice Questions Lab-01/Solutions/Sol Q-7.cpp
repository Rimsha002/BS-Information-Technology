#include<iostream>
#include<string>
using namespace std;


struct Rectangle
{
    int length;
    int width;
};

int main()
{
    struct Rectangle rectangleArray[5];
    for(int i=0;i<5;i++)
    {
        rectangleArray[i].length = (i+1)*2;
        rectangleArray[i].width = (i+1)*3;
    }


    for(int i=0;i<5;i++)
    {
        cout << "Length = " << rectangleArray[i].length << endl;
        cout << "Width = " << rectangleArray[i].width << endl;
        cout << endl;
    }
    return 0;
}
