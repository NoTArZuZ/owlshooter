#pragma once

#include "main.hpp"
#include "player.hpp"
#include "owl.hpp"

class Base
{
	public:
	Music music;
	void Init();
	void Draw();
};

class Mechanics
{
	public:
	void Kill();
};

class Background
{
	private:
	Texture2D background;
	Vector2 pos;
	double bgscale;

	public:
	void Init();
	void Draw();
};