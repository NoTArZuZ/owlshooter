#include "owl.hpp"

Owl owl[MAX_OWLS];

void Owl::Init()
{
  image = LoadTexture("resources/goofyowl.png");
	imgwidth = image.width * 0.1f;
	imgheight = image.height * 0.1f;
  pos.x = GetRandomValue(0, GetScreenWidth() - imgwidth);
  pos.y = GetRandomValue(0, GetScreenHeight() - imgheight);
}

void Owl::Draw()
{
  DrawTextureEx(image, pos, 0, 0.1f, WHITE);
  colrec = Rectangle{pos.x, pos.y, imgwidth, imgheight};
}
