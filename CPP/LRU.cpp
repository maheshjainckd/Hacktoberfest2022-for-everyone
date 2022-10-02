#include <bits/stdc++.h>

using namespace std;

class Node
{
public:
	string key;
	int value;
	Node(string key, int value)
	{
		this->key = key;
		this->value = value;
	}
	
};

class LRUCache
{
public:
	int maxSize;
	list<Node> l;
	unordered_map<string, list<Node>::iterator> m;
	
	LRUCache(int maxSize)
	{
		this->maxSize = maxSize > 1 ? maxSize : 1;
	}

	void insertKeyValue(string key, int value)
	{
		if(m.count(key) != 0)
		{
			auto it = m[key];
			it->value = value;
		}
		else{
			if(l.size() == maxSize)
			{
				Node last = l.back();
				m.erase(last.key);
				l.pop_back();
			}
			Node n(key, value);
			l.push_front(n);
			m[key] = l.begin();
		}
	}

	int* getValue(string key)
	{
		if(m.count(key) != 0)
		{
			auto it = m[key];
			int value = it->value;
			l.push_front(*it);
			l.erase(it);
			m[key] = l.begin();
			return &l.begin()->value;
		}
		return NULL;
	}

	string mostRecentKey(){
		return l.front().key;
	}

};

int main(int argc, char const *argv[])
{
	LRUCache lru(3);
	lru.insertKeyValue("Iron Man", 10);
	lru.insertKeyValue("Captain America", 20);
	lru.insertKeyValue("Thor", 30);

	cout << lru.mostRecentKey() << endl;

	lru.insertKeyValue("Iron Man", 40);
	cout << lru.mostRecentKey() << endl;

	if(lru.getValue("Captain America") == NULL)
	{
		cout << "Captain America doesn't exist" << endl;
	}

	if(lru.getValue("Thor") == NULL)
	{
		cout << "Thor doesn't exist" << endl;
	}

	if(lru.getValue("Black Widow") == NULL)
	{
		cout << "Black Widow doesn't exist" << endl;
	}

	if(lru.getValue("Iron Man") == NULL)
	{
		cout << "Iron Man doesn't exist" << endl;
	}	

	return 0;
}