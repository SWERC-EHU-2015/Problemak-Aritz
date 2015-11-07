#include <iostream>
#include <climits>

using namespace std;

struct vec2i
{
	int x, y;
};

struct screen
{
	vec2i res, size;
};

bool readScreen(screen &s)
{
	return static_cast<bool>(cin >> s.res.x >> s.res.y >> s.size.x >> s.size.y);
}

inline const int &max(const int &i1, const int &i2)
{
	return i1 > i2 ? i1 : i2;
}

inline const int &min(const int &i1, const int &i2)
{
	return i1 < i2 ? i1 : i2;
}

inline int ceilDiv(const int &i1, const int &i2)
{
	return 1 + ((i1 - 1) / (float)i2);
}

int main()
{
	screen aim;
	while (readScreen(aim))
	{
		int n;
		int minPrice = INT_MAX;
		cin >> n;
		while (n--)
		{
			screen s;
			readScreen(s);
			int price;
			cin >> price;
			int x = max(ceilDiv(aim.res.x, s.res.x), ceilDiv(aim.size.x, s.size.x));
			int y = max(ceilDiv(aim.res.y, s.res.y), ceilDiv(aim.size.y, s.size.y));
			minPrice = min(minPrice, price * x * y);

			x = max(ceilDiv(aim.res.x, s.res.y), ceilDiv(aim.size.x, s.size.y));
			y = max(ceilDiv(aim.res.y, s.res.x), ceilDiv(aim.size.y, s.size.x));
			minPrice = min(minPrice, price * x * y);
		}
		cout << minPrice << endl;
	}
	return 0;
}
