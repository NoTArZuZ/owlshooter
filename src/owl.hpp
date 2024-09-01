#pragma once
#include "main.hpp"

class Owl
{
  private:
  Texture2D image;
  
  public:
  float imgwidth;
  float imgheight;
  Vector2 pos;
  Rectangle colrec;
  void Init();
  void Draw();
};