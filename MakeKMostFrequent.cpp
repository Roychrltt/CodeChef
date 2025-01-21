#include <iostream>
#include <iostream>
#include <functional>
#include <cmath>
#include <ctime>
#include <numeric>
#include <iterator>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <string>
#include <utility>

void	solve(std::vector<int>& v, int k)
{
	int n = v.size();
	int count = 0;
	std::unordered_map<int, int> map;
	for (int num : v)
	{
		map[num]++;
		count = std::max(count, map[num]);
	}
	if (map[k] == count)
	{
		std::cout << "0" << std::endl;
		return ;
	}
	count = 0;
	map.clear();
	for (int i = 0; i < n; i++)
	{
		map[v[i]]++;
		count = std::max(count, map[v[i]]);
		if (map[k] >= count)
		{
			std::cout << "1" << std::endl;
			return ;
		}
	}
	count = 0;
	map.clear();
	for (int i = n - 1; i >= 0; i--)
	{
		map[v[i]]++;
		count = std::max(count, map[v[i]]);
		if (map[k] >= count)
		{
			std::cout << "1" << std::endl;
			return ;
		}
	}
	std::cout << "2" << std::endl;
	return ;
}

int main(void)
{
	int n;
	std::cin >> n;
	while (n--)
	{
		int x, k;
		std::cin >> x;
		std::cin >> k;
		std::vector<int> v(x);
		for (int i = 0; i < x; i++)
		{
			std::cin >> v[i];
		}
		solve(v, k);
	}
	return 0;
}
