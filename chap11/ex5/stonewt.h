#ifndef STONEWT_H_
#define STONEWT_H_

class Stonewt
{
    private:
        char m; // s:stone, i:int pounds, p:pounds
        enum {Lbs_per_stn=14};
        int stone;
        double pds_left;
        double pounds;
    public:
        Stonewt(double lbs);
        Stonewt(int stn, double lbs);
        Stonewt();
        ~Stonewt();
        void show(char m) const;
        Stonewt operator+(const Stonewt& s) const;
        Stonewt operator-(const Stonewt& s) const;
        Stonewt operator*(double n) const;

        friend Stonewt operator*(double n, const Stonewt & s) { return s*n;}
        friend std::ostream & operator<<(std::ostream & os, const Stonewt & s);
};

#endif