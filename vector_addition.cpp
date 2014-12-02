#include <iostream>
#include <vector>
#include <iterator>

using namespace std;
   
void vector_addition(const vector<float> &a, const vector<float> &b, vector<float> &c)
{
   if (a.size() != b.size())
   {
      return;
   }

   c.clear();
   c.resize(a.size());

   #pragma omp parallel for
   for (size_t i = 0; i < a.size(); ++i)
   {
		c[i] = a[i] + b[i];
   }
}

int main()
{
	vector<float> a = {1.0, 2.1, 3.5, 6.1};
   vector<float> b = {1.0, 2.1, 3.5, 6.1};
   vector<float> c;

   vector_addition(a, b, c);

	copy(c.begin(), c.end(), ostream_iterator<float>(cout, " "));
   cout << endl;

	return 0;
}
