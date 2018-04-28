#pragma once
#include "DxLib.h"
#include <map>
#include <string>
#include <memory>

using namespace std;


class GraphFactory {
	map<string, int> pool;

	int CreateGraph(const char*);

public:
	int GetGraph(const char*);
};

extern std::unique_ptr<GraphFactory> grafac;