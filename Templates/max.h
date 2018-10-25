#pragma once

template<typename T>
T max(T v1, T v2)
{
	if (v1 > v2)
	{
		return v1;
	}
	else
	{
		return v2;
	}
}
