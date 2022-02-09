// 16.6
#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Review{
    string title;
    int rating;
};

bool FillReview(Review & rr)
{
    cout <<"Enter book title(quit to quit):";
    getline(cin,rr.title);
    if(rr.title=="quit")
        return false;
    cout <<"Enter book rating:";
    cin >> rr.rating;
    if(!cin)
        return false;
    cin.get();
    return true;
}

void ShowReview(const Review & rr)
{
    cout << rr.rating << "\t" << rr.title <<endl;
}

int main()
{
    vector<Review> books;
    Review temp;
    while(FillReview(temp))
        books.push_back(temp);
    int num = books.size();
    if(num>0)
    {
        cout <<"Thank you. You entered the following:" << endl 
            << "Rating\tBook\n";
        
        for(int i=0;i<num;i++)
            ShowReview(books[i]);
        cout <<"Reprising:\nRating\tBook\n";
        vector<Review>::iterator pr;
        for(pr=books.begin(); pr!=books.end();pr++)
            ShowReview(*pr);
            
        vector<Review> oldlist(books);

        if(num>3)
        {
            // remove 2 items
            books.erase(books.begin()+1, books.begin()+3);
            cout <<"After erasure:\n";
            for(pr = books.begin(); pr!=books.end(); pr++)
                ShowReview(*pr);

            books.insert(books.begin(), oldlist.begin()+1, oldlist.begin()+2);
            cout <<"After insertion:\n";
            for(pr = books.begin(); pr!=books.end(); pr++)
                ShowReview(*pr);
        }
        books.swap(oldlist);
        cout <<"Swapping oldlist with books:\n";
        for(pr = books.begin(); pr!=books.end(); pr++)
                ShowReview(*pr);
    }
    else
        cout <<"Nothing entered, nothing gained."  << endl;

    return 0;
}