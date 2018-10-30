#include <iostream>
#include "skiing.h"
using namespace std;
int main()
{
    Skiing ski;
	ski.initializer();
	ski.get_dp();
	//cout<<ski.BackTrackPath();
    return 0;
}
