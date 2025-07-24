#include <iostream>
#include <cstring>
using namespace std;

class CWH
{
protected:
    string title;
    float rating;

public:
    CWH(string s, float r)
    {
        title = s;
        rating = r;
    }
    virtual void display(){};
};

class CWHvideo : public CWH
{
    int videolength;

public:
    CWHvideo(string s, float r, int vl) : CWH(s, r)
    {
        videolength = vl;
    }
    void display()
    {
        cout << "This is an amazing video with title " << title << endl;
        cout << "Ratings : " << rating << " out of 5 stars" << endl;
        cout << "Length of this video is " << videolength << " minutes" << endl;
    }
};

class CWHtext : public CWH
{
    int words;

public:
    CWHtext(string s, float r, int wc) : CWH(s, r)
    {
        words = wc;
    }
    void display()
    {
        cout << "This is an amazing text with title " << title << endl;
        cout << "Ratings : " << rating << " out of 5 stars" << endl;
        cout << "Length of this text is " << words << " words" << endl;
    }
};

int main()
{
    string title;
    float rating, vl;
    int words;

    // for cwh video
    title = "Django tutorial";
    rating = 4.5;
    vl = 35;

    CWHvideo dj_video(title, rating, vl);
    dj_video.display();
    cout << endl;
    // for cwh text
    title = "Django text";
    rating = 3.9;
    words = 1400;

    CWHtext dj_text(title, rating, words);
    dj_text.display();

    CWH *tuts[2];
    tuts[0] = &dj_video;
    tuts[1] = &dj_text;
    cout << endl;
    tuts[0]->display();
    cout << endl;
    tuts[1]->display();
    return 0;
}