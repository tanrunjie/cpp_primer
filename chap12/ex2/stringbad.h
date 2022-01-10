#ifndef STRINGBAD_H_
#define STRINGBAD_H_

#include <iostream>

class StringBad
{
    private:
        char * str;
        int len;
        static int num_strings;
        static const int CINLIM = 80;
    public:
        StringBad(const char * s);
        StringBad(const StringBad & s);

        StringBad();
        ~StringBad();
        friend std::ostream & operator<<(std::ostream & os, const StringBad & st);
        friend std::istream & operator>>(std::istream & is, StringBad & st);
        // important: deep copy
        StringBad & operator=(const StringBad & st);
        StringBad & operator=(const char * s);
        StringBad operator+(const StringBad & st) const;
        void Stringlow();
        void String();
        int FindTimes(char c) const;
        //extent
        int length() const { return len;}
        friend bool operator<(const StringBad & st1, const StringBad & st2);
        friend bool operator>(const StringBad & st1, const StringBad & st2);
        friend bool operator==(const StringBad & st1, const StringBad & st2);
        // friend istream & operator>>(istream & is, StringBad & st);
        char & operator[] (int i);
        const char & operator[] (int i) const;
        static int HowMany();
};
#endif