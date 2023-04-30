#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;

constexpr auto inf = int{ 987'654'321 };

vi dist;
vector<vector<pair<int, int>>> edges;

void dijk(int b) {
	dist[b] = 0;

	auto q = priority_queue<pair<int, int>>{};
	q.push({ 0, b });

	while (!q.empty()) {
		auto f = q.top();
		q.pop();

		const auto& d = -f.first;
		const auto& x = f.second;

		if (dist[x] < d) {
			continue;
		}

		for (const auto& yw : edges[x]) {
			const auto& y = yw.first;
			const auto& w = yw.second;

			const auto& newDist = d + w;

			if (newDist < dist[y]) {
				dist[y] = newDist;
				q.push({ -newDist, y });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n;
	cin >> n;
	dist = vi(n + 1, inf);
	edges = vector<vector<pair<int, int>>>(n + 1);

	int m;
	cin >> m;
	for (auto i = 0; i < m; ++i) {
		int x, y, w;
		cin >> x >> y >> w;

		edges[x].push_back({ y, w });
	}

	int b, e;
	cin >> b >> e;

	dijk(b);
	cout << dist[e];

	return 0;
}