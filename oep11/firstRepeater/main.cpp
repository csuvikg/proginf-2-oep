#include <iostream>
#include <vector>

#include "seqinfileenumerator.hpp"
#include "intervalenumerator.hpp"
#include "linsearch.hpp"
#include "summation.hpp"
#include "intervalenumerator.hpp"

using namespace std;

class Copy : public Summation<int, vector<int> >
{
    int  func(const int &e) const override { return e; }
};



int main()
{
    // Tömb feltöltése szöveges állományból
    vector<int> x;
    Copy pr1;
    SeqInFileEnumerator<int> enor1("input.txt");
    pr1.addEnumerator(&enor1);
    pr1.run();
    x = pr1.result();

    // Tömb elsõ olyan elemének keresése, amely azt megelõzõen már szerepelt a tömbben
/*    OuterSearch pr2(x);
    IntervalEnumerator enor2(1, x.size()-1);
    pr2.addEnumerator(&enor2);
    pr2.run();

    if(pr2.found())
        cout << "A(z) " << x[pr2.elem()] << " ismetlodott eloszor.\n";
    else
        cout << "Csupa kulonbozo elem.\n";
*/
    return 0;
}
