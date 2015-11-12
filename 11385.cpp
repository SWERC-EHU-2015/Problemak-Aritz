#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>
#include <sstream>

using namespace std;

vector<int64_t> fib;
map<int64_t, int> m;

void initFib()
{
	fib.push_back(1);
	m.insert(make_pair(1, 0));
	fib.push_back(2);
	m.insert(make_pair(2, 1));

	int64_t n = 49;

	for (int i = 2; i < n; i++)
	{
		int64_t f = fib[i - 1] + fib[i - 2];
		fib.push_back(f);
		m.insert(make_pair(f, i));
	}
}

int main()
{
	initFib();

	int n;
	cin >> n;
	while (n--)
	{
		int length;
		cin >> length;

		int pos[1000];

		int last = INT_MIN;

		for (int i = 0; i < length; ++i)
		{
			int fp;
			cin >> fp;
			int p = m.find(fp)->second;
			pos[i] = p;
			last = p > last ? p : last;
		}

		char out[1000];
		char in[1000];

		int i = 0;

		char next;
		while (cin.get(next))
		{
			if (next == '\n')
			{
				break;
			}
		}

		char c;
		while (true)
		{
			scanf("%c", &c);
			if ('A' <= c && c <= 'Z')
			{
				in[i++] = c;
			}
			else if (c == '\n')
			{
				break;
			}
		}

		for (int j = 0; j < last; j++)
		{
			out[j] = ' ';
		}

		for (int j = 0; j < i; j++)
		{
			out[pos[j]] = in[j];
		}

		out[last + 1] = '\0';

		cout << out << endl;
	}
}
