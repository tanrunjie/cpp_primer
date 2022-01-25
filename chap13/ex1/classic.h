#ifndef CLASSIC_H_
#define CLASSIC_H_
#include <iostream>
#include <cstring>
using namespace std;

class Cd{
    private:
        
        char performers[50];
        char label[20];
        int selections;
        double playtime;
    public:
        Cd(char * s1, char * s2, int n, double x)
        {
            strcpy(performers,s1);
            strcpy(label, s2);
            selections = n;
            playtime = x;
        }
        Cd(const Cd & d)
        {
            strcpy(performers,d.performers);
            strcpy(label, d.label);
            selections = d.selections;
            playtime = d.playtime;
        }
        Cd()
        {
            strcpy(performers,"");
            strcpy(label, "");
            selections = 0;
            playtime = 0.0;
        }
        ~Cd(){}
        virtual void Report() const
        {
            cout <<"performers: " << performers << endl;
            cout <<"label: " << label << endl;
            cout <<"selections: "<< selections << endl;
            cout <<"playtime: " << playtime << endl;
        }
        Cd & operator=(const Cd & d)
        {
            strcpy(performers,d.performers);
            strcpy(label, d.label);
            selections = d.selections;
            playtime = d.playtime;
        }
};

class Classic:public Cd
{
    private:
        char composer[30];
    public:
        Classic():Cd()
        {
            strcpy(composer,"");
        }
        Classic(char * s1, char * s2, char * s3, int n, double x)
        :Cd(s1,s2,n,x)
        {
            strcpy(composer, s3);
        }
        ~Classic(){}
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
            strcpy(composer, d.composer);
            return *this;
        }

};

#endif