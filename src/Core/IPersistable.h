#pragma once

#include <iostream>

class IPersistable
{
public:
	virtual std::string ToLine(const std::string& separetor = "#//#") = 0;
	virtual void FromLine(std::string Line, const std::string& separetor = "#//#") = 0;
	virtual inline std::string GetKey() const = 0;
};