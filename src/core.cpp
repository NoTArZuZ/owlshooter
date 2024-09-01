#include "core.hpp"

extern Owl owl[MAX_OWLS];
extern Player player;
Base base;
Mechanics mech;
Background background;

void Base::Init()
{
	InitWindow(1280, 800, "Owl Shooter");
	InitAudioDevice();
	SetTargetFPS(60);
	Image icon = LoadImage("resources/icon.png");
	SetWindowIcon(icon);
	music = LoadMusicStream("resources/PovOwlShooting.wav");
	PlayMusicStream(music);
}

void Base::Draw()
{
	ClearBackground(WHITE);
	UpdateMusicStream(music);
	DrawText(TextFormat("KILLED OWLS %i", points), GetScreenWidth()/2 - 128, 20, 32, WHITE);
	if (IsKeyPressed(KEY_F))
	{
	  ToggleFullscreen();
	}
}

void Background::Init()
{
	background = LoadTexture("resources/forest.png");
}

void Background::Draw()
{
	bgscale = background.width / GetScreenWidth() * 0.75f;
	DrawTextureEx(background, Vector2{0,0}, 0, bgscale, WHITE);
}

void Mechanics::Kill()
{
	for (int i = 0; i < MAX_OWLS; ++i)
	{
		if (CheckCollisionPointRec(GetMousePosition(), owl[i].colrec) && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
		{
		  points++;
		  PlaySound(player.shot);
		  owl[i].pos.x = GetRandomValue(0, GetScreenWidth() - owl[i].imgwidth);
		  owl[i].pos.y = GetRandomValue(0, GetScreenHeight() - owl[i].imgheight);
		}
	}
}