#include <iostream>
#include <fstream>
#include <iostream>
using namespace std;

int main()
{
	ofstream myfile;
	myfile.open("Credentials.JSON");
	myfile << "Writing this to a file \n";
	myfile.close();
	return 0;
}