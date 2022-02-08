#include <iostream>
#include "sales.h"

using namespace std;

int main()
{
    double vals1[12] =
        {
            1220, 1100, 1122, 2212, 1232, 2334,
            2884, 2393, 3302, 2922, 3002, 2544};

    double vals2[12] =
        {
            12, 11, 22, 21, 32, 34,
            28, 29, 33, 29, 32, 35};

    Sales sales1(2004, vals1, 12);
    LabeledSales sales2("Blogstar", 2005, vals2, 12);

    cout << "First try block:" << endl;

    try
    {
        int i;
        cout << "Year = " << sales1.Year() << endl;
        for (i = 0; i < 12; i++)
        {
            cout << sales1[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "Year = " << sales2.Year() << endl;
        cout << "Label = " << sales2.Label() << endl;
        for (i = 0; i <= 12; i++)
        {
            cout << sales2[i] << ' ';
            if (i % 6 == 5)
                cout << endl;
        }
        cout << "End of try block 1.\n";
    }
    catch (LabeledSales::nbad_index &bad)
    {
        cout << bad.what();
        cout << "Company: " << bad.label_val() << endl;
        cout << "bad index: " << bad.bi_val() << endl;
    }
    catch (Sales::bad_index &bad)
    {
        cout << bad.what();
        cout << "bad index: " << bad.bi_val() << endl;
    }
    cout << endl
         << "Next try block:" << endl;

    try
    {
        sales2[2] = 37.5;
        sales1[20] = 23345;
        cout << "End of try block 2." << endl;
    }
    catch (Sales::bad_index &bad)
    {
        Sales::bad_index *pb;
        LabeledSales::nbad_index *pn;
        if (pn = dynamic_cast<LabeledSales::nbad_index*>(&bad))
        {
            cout << pn->what();
            cout << "Company: " << pn->label_val() << endl;
            cout << "bad index: " << pn->bi_val() << endl;
        }
        else if(pb = dynamic_cast<Sales::bad_index*>(&bad))
        {
            cout << pb->what();
            cout << "bad index: " << pb->bi_val() << endl;
        }
        else
        {

        }
    }

    cout << "done" << endl;

    return 0;
}