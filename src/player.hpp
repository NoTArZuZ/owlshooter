#pragma once
#include "main.hpp"

class Player
{
  public:
  Texture2D cursor;
  double cursorwidth;
  double cursorheight;
  Vector2 mousepos;
  Sound shot;
  void Init();
  void Draw();
};