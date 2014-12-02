#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

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
   const size_t vector_size = 5;
   vector<float> a;
   vector<float> b;
   vector<float> c;

   a.reserve(vector_size);
   b.reserve(vector_size);
   c.reserve(vector_size);

   // Generate random vectors.
   srand(time(NULL));
   generate_n(back_inserter(a), vector_size, []() { return rand() % 100; });
   generate_n(back_inserter(b), vector_size, []() { return rand() % 100; });

   vector_addition(a, b, c);

	copy(c.begin(), c.end(), ostream_iterator<float>(cout, " "));
   cout << endl;

	return 0;
}
