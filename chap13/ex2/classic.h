#ifndef CLASSIC_H_
#define CLASSIC_H_
#include <iostream>
#include <cstring>
using namespace std;

class Cd{
    private:
        enum {MAX = 50};
        char * performers;
        char * label;
        int selections;
        double playtime;
    public:
        Cd(char * s1, char * s2, int n, double x)
        {
            performers = new char[strlen(s1)+1];
            strcpy(performers,s1);

            label = new char[strlen(s2)+1];
            strcpy(label, s2);
            selections = n;
            playtime = x;
        }
        Cd(const Cd & d)
        {
            performers = new char[strlen(d.performers)+1];
            strcpy(performers,d.performers);
            label = new char[strlen(d.label)+1];
            strcpy(label, d.label);
            selections = d.selections;
            playtime = d.playtime;
        }
        Cd()
        {
            performers = new char[MAX];
            label = new char[MAX];
            strcpy(performers,"");
            strcpy(label, "");
            selections = 0;
            playtime = 0.0;
        }
        ~Cd(){
            delete [] performers;
            delete [] label;
        }
        virtual void Report() const
        {
            cout <<"performers: " << performers << endl;
            cout <<"label: " << label << endl;
            cout <<"selections: "<< selections << endl;
            cout <<"playtime: " << playtime << endl;
        }
        Cd & operator=(const Cd & d)
        {
            if(this==&d)   
                return *this;
            delete [] performers;
            delete [] label;

            performers = new char[strlen(d.performers)+1];
            label = new char[strlen(d.label)+1];
            strcpy(performers,d.performers);
            strcpy(label, d.label);
            selections = d.selections;
            playtime = d.playtime;
            return *this;
        }
};

class Classic:public Cd
{
    private:
        enum {MAX = 50};
        char * composer;
    public:
        Classic():Cd()
        {
            composer = new char[MAX];
            strcpy(composer,"");
        }
        Classic(char * s1, char * s2, char * s3, int n, double x)
        :Cd(s1,s2,n,x)
        {
            composer = new char[strlen(s3)+1];
            strcpy(composer, s3);
        }
        ~Classic(){
            delete []composer;
        }
        void Report() const
        {
            Cd::Report();
            cout <<"composer: "<<composer <<endl;
        }
        Classic & operator=(const Classic & d)
        {
            if(this==&d)
                return *this;
            Cd::operator=(d);
            delete []composer;
            composer = new char[strlen(d.composer)+1];
            strcpy(composer, d.composer);
            return *this;
        }

};

#endif