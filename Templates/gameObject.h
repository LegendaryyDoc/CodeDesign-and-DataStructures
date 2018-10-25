#pragma once
#include <iostream>
#include "raylib.h"

template <typename T>
class gameObject
{
public:
	bool enabled;   // is this gameObject enabled?
	T * object;     // pointer to underlying instance of type T

	void update(float delta)
	{
		// todo: how to update the object?
		object->update(delta);
	}

	void render()
	{
		// todo: how to render the object?
		object->render();
	}

	gameObject(T& _obj)
	{
		object = &_obj;
	}

	// todo: What else would you need to include in this class declaration?
};