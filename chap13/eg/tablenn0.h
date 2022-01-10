#ifndef TABLENN0_H_
#define TABLENN0_H_

class TableTennisPlayer
{
    private:
        enum{LIM= 20};
        char firstname[LIM];
        char lastname[LIM];
        bool hasTable;
    public:
        TableTennisPlayer(const char * fn = "none",
        const char * ln ="none", bool ht=false);
        
        void Name() const;
        bool HasTable() const { return hasTable;};
        void ResetTable(bool v){ hasTable=v;};
};

#endif