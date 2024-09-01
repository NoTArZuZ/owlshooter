#include "player.hpp"

Player player;

void Player::Init()
{
	cursor = LoadTexture("resources/scope.png");
	shot = LoadSound("resources/shot.mp3");
	cursorwidth = cursor.width * 0.1f;
	cursorheight = cursor.height * 0.1f;
}

void Player::Draw()
{
	mousepos.x = GetMouseX() - cursorwidth / 2;
	mousepos.y = GetMouseY() - cursorheight / 2;
	HideCursor();
	DrawTextureEx(cursor, mousepos, 0, 0.1f, WHITE);
}