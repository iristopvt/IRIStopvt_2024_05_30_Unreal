#pragma once
#include <iostream>
class DisJointSet
{
public:
	DisJointSet(int n)
	{
		_parent = vector<int>(n, 0);
		_rank = vector<int>(n, 1);
		for (int i = 0; i < n; i++)
		{
			_parent[i] = i;
		}
	}
	int FindLeader(int u)
	{
		if (u == _parent[u])
			return u;

		int parent = _parent[u];
		return FindLeader(parent);
	}


	// [0] [2]    [5]
	// [1] 
	// [3]
	void Merge(int u, int v)
	{
		int uLeader = FindLeader(u);
		int vLeader = FindLeader(v);

		if (uLeader == vLeader)
			return;

		if (_rank[uLeader] > _rank[vLeader])
		{
			std::swap(uLeader, vLeader);

		}
		_parent[uLeader] = vLeader;

		if (_rank[uLeader] == _rank[vLeader])
			_rank[vLeader]++;

	}

private:
	vector<int> _parent;
	vector<int> _rank;

};

int main()
{
	DisJointSet set(10);

	set.Merge(5, 6);
	set.Merge(0, 1);
	set.Merge(3, 5);
	set.Merge(1, 3);

	cout << set.FindLeader(1) << endl;
	return 0;
}