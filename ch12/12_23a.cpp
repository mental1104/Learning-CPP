#include<iostream>
#include<string>
#include<cstring>
#include<memory>

using namespace::std;

int main(){
    const char *c1 = "Hello ";
	const char *c2 = "World";
	unsigned len = strlen(c1) + strlen(c2) + 1;
	char *r = new char[len]();
	strcat_s(r, len, c1);
	strcat_s(r, len, c2);
	cout << r << endl;

}