#ifndef DMA_H_
#define DMA_H_

#include <iostream>

using std::cout;
using std::endl;
class ABC
{
    protected:
        char * label;
        int rating;
    public:
        ABC();
        ABC(const char * l="null", int r=0);
        ABC(const ABC& rs);

        ABC & operator=(const ABC & rs);
        ~ABC();
        friend std::ostream & operator<<(std::ostream &os, const ABC & rs);
};
class baseDMA:public ABC
{
    public:
        baseDMA(const char * l = "null", int r=0);
        baseDMA(const baseDMA & rs);
        ~baseDMA(){cout <<"in baseDMA" << endl;}
        baseDMA & operator=(const baseDMA & rs);
        friend std::ostream & operator<<(std::ostream & os, const baseDMA & rs);
};

class lacksDMA : public ABC
{
    private:
        enum {COL_LEN=40};
        char color[COL_LEN];
    public:
        lacksDMA(const char * c = "blank", const char * l ="null", int r=0);
        lacksDMA(const ABC & rs, const char * c = "blank" );
        
        ~lacksDMA(){cout <<"in lacksDMA" << endl;}
        friend std::ostream& operator<<(std::ostream & os, const lacksDMA & rs);
};

class hasDMA: public ABC
{
    private:
        char * style;
    public:
        hasDMA(const char* s="none", const char * l ="null", int r=0);
        hasDMA(const char * s, const ABC & rs);
        hasDMA(const hasDMA & hs);
        ~hasDMA();
        hasDMA & operator=(const hasDMA & hs);
        friend std::ostream & operator<<(std::ostream & os, const hasDMA & rs);
};

#endif