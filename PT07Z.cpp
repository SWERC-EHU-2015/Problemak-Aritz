#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef queue<int> qi;
typedef pair<int, int> pii;

pii bfs(vvi tree, int first)
{
	qi toVisit;
	vi distance(tree.size(), -1);
	distance[first] = 0;
	toVisit.push(first);
	int max = -1, maxD = -1;

	while (!toVisit.empty())
	{
		int next = toVisit.front();
		toVisit.pop();
		for (unsigned int i = 0; i < tree[next].size(); i++)
		{
			int neigh = tree[next][i];
			if (distance[neigh] == -1)
			{
				toVisit.push(neigh);
				distance[neigh] = distance[next] + 1;
				if (distance[neigh] > maxD) {
					maxD = distance[neigh];
					max = neigh;
				}
			}
		}
	}

	return make_pair(max, maxD);
}

int main()
{
	int n;
	cin >> n;
	vvi tree(n, vi(0));

	while (--n)
	{
		int v1, v2;
		cin >> v1 >> v2;
		tree[v1 - 1].push_back(v2 - 1);
		tree[v2 - 1].push_back(v1 - 1);
	}
	pii first = bfs(tree, tree.front().front());
	pii last = bfs(tree, first.first);
	cout << last.second << endl;
}
