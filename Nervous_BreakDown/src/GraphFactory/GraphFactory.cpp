#include "GraphFactory.h"

int GraphFactory::CreateGraph(const char* fileName) {
	int handle = LoadGraph(fileName);
	return handle;
}

int GraphFactory::GetGraph(const char* fileName) {
	auto it = pool.find(string(fileName));
	if (it != pool.end())
		return it->second;
	int newGraph = CreateGraph(fileName);
	pool.insert(make_pair(fileName, newGraph));
	return newGraph;
}


extern std::unique_ptr<GraphFactory> grafac(new GraphFactory);