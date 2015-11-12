#include <iostream>
#include <vector>
#include <queue>

struct vec2i
{
	int x, y;
	vec2i(int x, int y) : x(x), y(y) {}
	int toIdx(int w) { return x + y * w; }
};

using namespace std;

typedef vector<int> vi;
typedef vector<string> vs;
typedef queue<vec2i> qi;
typedef pair<int, int> pii;
typedef pair<vec2i, int> p2i;

void visit(const vs &tree, const int &w, const int &h, const vec2i &n,
		   int &maxD, vec2i &max, vi &distance, const int &nd, qi &toVisit,
		   int dx, int dy)
{
	if (n.x + dx >= 0 && n.y + dy >= 0 && n.x + dx < w &&
		n.y + dy < h && tree[n.y + dy][n.x + dx] == '.')
	{
		vec2i neigh = vec2i(n.x + dx, n.y + dy);
		if (distance[neigh.toIdx(w)] == -1)
		{
			toVisit.push(neigh);
			int newDist = nd + 1;
			distance[neigh.toIdx(w)] = newDist;
			if (newDist > maxD)
			{
				maxD = newDist;
				max = neigh;
			}
		}
	}
}

p2i bfs(const vs &tree, vec2i first, int w, int h)
{
	qi toVisit;
	vi distance(w + h * w, -1);
	distance[first.toIdx(w)] = 0;
	toVisit.push(first);
	vec2i max = first;
	int maxD = 0;

	while (!toVisit.empty())
	{
		vec2i next = toVisit.front();
		toVisit.pop();
		int nd = distance[next.toIdx(w)];

		visit(tree, w, h, next, maxD, max, distance, nd, toVisit, -1, 0);
		visit(tree, w, h, next, maxD, max, distance, nd, toVisit, 1, 0);
		visit(tree, w, h, next, maxD, max, distance, nd, toVisit, 0, -1);
		visit(tree, w, h, next, maxD, max, distance, nd, toVisit, 0, 1);
	}

	return make_pair(max, maxD);
}

int main()
{
	int n;
	cin >> n;
	while (n--)
	{
		int w, h;
		cin >> w >> h;
		vector<string> mat(h);
		for (int i = 0; i < h; ++i)
		{
			cin >> mat[i];
		}

		vec2i first(-1, -1);
		for (int x = 0; x < w && first.x == -1; x++)
			for (int y = 0; y < h && first.x == -1; y++)
				if (mat[y][x] == '.') first = vec2i(x, y);

		int n = bfs(mat, bfs(mat, first, w, h).first, w, h).second;
		cout << "Maximum rope length is " << n << "." << endl;
	}
}
