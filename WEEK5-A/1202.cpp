#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#define ll long long
#define pii pair<int, int>
using namespace std;

const int MAX = 300000;
int N, K;
int bag[MAX];
pii jewelry[MAX];
priority_queue<int> pq;

int main(void)

{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N >> K;

	for (int i = 0; i < N; i++)
	{
		cin >> jewelry[i].first >> jewelry[i].second;
	}

	for (int i = 0; i < K; i++)
	{
		cin >> bag[i];
	}

	sort(jewelry, jewelry + N);

	sort(bag, bag + K);

	ll result = 0;

	int idx = 0;
	for (int i = 0; i < K; i++)
	{
		while (idx < N && jewelry[idx].first <= bag[i])
			pq.push(jewelry[idx++].second);

		if (!pq.empty())
		{
			result += pq.top();
			pq.pop();
		}
	}
	cout << result << "\n";
	return 0;
}