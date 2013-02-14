#include <cstdlib>
#include <cmath>
#include <iostream>


using namespace std;

int count(int numLeft, int sumLeft)
{
	if (numLeft == 1)
	{
		if ((sumLeft <= 9) && (sumLeft >= 0))
		{
			return 1;
		}
		else
		{
			return 0;
		}
	}

	int c = 0;
	int choices = min(9, sumLeft);
	for (int i = 0; i <= choices; i++)
	{
		c = c + count(numLeft - 1, sumLeft - i);
	}

	return c;
}

int main()
{
	cout << count(6, 20) << endl;
}