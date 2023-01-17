#include <iostream>
#include <map>

using namespace std;

int main(int argc, char* argv[]) {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;

	map<long long, int> m;
	
	int result = 0;
	long long input;

	for (int i = 0; i < n; i++)
	{
		cin >> input;
		m[input]++;
	}

	for (auto iter = m.begin(); iter != m.end(); iter++)
		result = max(iter->second, result);

	for (auto iter = m.begin(); iter != m.end(); iter++)
		if (iter->second == result)
		{
			cout << iter->first;
			break;
		}

	return 0;
}