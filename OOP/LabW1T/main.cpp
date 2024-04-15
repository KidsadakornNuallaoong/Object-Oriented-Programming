#include <iostream>
#include "MyCode.h"

using namespace std;

int main(){
	cout << "hello world" << endl;

	point p  = makePoint(10,20); // * (x,y)

	cout << p.x << endl;

	cout << p.y << endl;

	return 0;
}
