#include<iostream>
#include<cstring>

using namespace::std;

int main(){
    const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	strcat(r, c1);
	strcat(r, c2);
	cout << r << endl;

	delete[] r;
	r = nullptr;
	return 0;
}