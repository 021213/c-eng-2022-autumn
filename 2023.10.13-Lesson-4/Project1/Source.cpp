#include<iostream>

#include<vector>
#include<deque>
#include<list>

#include<set>
#include<map>

#include<stack>
#include<queue>

int main(int argc, char* argv[])
{
	//sequentive
	std::vector<int> vect;
	std::deque<int> deq;
	std::list<int> list;

	//associative
	std::set<int> sset;
	std::multiset<int> mset;
	std::map<std::string, std::string> mmap;
	std::multimap<std::string, std::string> multimap;

	//adaptive
	std::stack<int> sstack;
	std::queue<int> ordqueue;
	std::priority_queue<int> pqueue;

	return EXIT_SUCCESS;
}