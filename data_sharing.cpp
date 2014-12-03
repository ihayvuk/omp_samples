#include <string>
#include <iostream>

using namespace std;
 
int main()
{
	string a = "x";
    string b = "y";
    int c = 3;
     
    #pragma omp parallel private(a,c) shared(b) num_threads(2)
    {
        a += "k";
        c += 7;
        cout << "a becomes (" << a << "), b is (" << b << ")" << endl;
    }
}
