#pragma once

class SelfCounting{

public:
	SelfCounting();
	SelfCounting(int val);
	SelfCounting(const SelfCounting& other);
	~SelfCounting();

public:
	static unsigned getLiveObjectsCount();
	static unsigned getCreatedCount();

private:
	static unsigned liveObjectsCount;
	static unsigned createdCount;

private:
	const int const_val;

};