#pragma once
class Serializable
{
public:
	virtual void serialize() = 0;
	virtual void deserialize() = 0;
};
