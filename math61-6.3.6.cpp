#include <set>
#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

set<string> sets;

void count(string s, string left)
{
	if (s.length() > 0)
	{
		//cout << s << endl;
		sets.insert(s);
	}

	if (left.length() == 0)
	{
		return;
	}

	for (int i = 0; i < left.length(); i++)
	{
		string temp = left;
		char c = left[i];
		left = left.substr(0, i) + left.substr(i + 1, left.length() - i - 1);
		//cout << "LEFT: " << left << endl;
		count(s + c, left);
		left = temp;
	}
}

int main()
{
	string s = "school";
	count("", s);
	cout << sets.size() << endl;

	string test;
	while (true)
	{
		getline(cin, test); //input something to see if it was already in our set
		bool ret = sets.insert(test).second;

		if (ret == true)	//if it was inserted successfully into set, then it was not there originally and we have a problem
							//That is, if the string we tried to insert fits the description of the problem.
		{
			cout << "Nope" << endl;
		}
		else
		{
			cout << "Yup" << endl;
		}
	}
}