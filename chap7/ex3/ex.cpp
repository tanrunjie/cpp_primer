#include <iostream>

using namespace std;

struct box{
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
};

void box_show(box b)
{
    cout <<b.maker << endl;
    cout <<b.height << endl;
    cout <<b.width << endl;
    cout <<b.length << endl;
    cout <<b.volume << endl;
}
void box_cal(box& b)
{
    b.volume = b.height * b.width * b.length;
}

int main()
{
    box b = {"tan run", 1.1,2.2,3.3, 0};
    box_show(b);
    box_cal(b);
    box_show(b);
    return 0;
}