#include "main.hpp"
#include "owl.hpp"
#include "player.hpp"
#include "discord.hpp"
#include "core.hpp"

int points = 0;

int main()
{
  // Classes
  extern Base base;
  extern Mechanics mech;
  extern Background background;
  extern Owl owl[MAX_OWLS];
  extern Player player;
  extern Discord discordrpc;
  // Init
  base.Init();
  discordrpc.Init();
  background.Init();
  player.Init();
  for (int i = 0; i < MAX_OWLS; ++i)
  {
    owl[i].Init();
  }
  // Game Loop
  while (!WindowShouldClose())
  {
    BeginDrawing();
    background.Draw();
  	for (int i = 0; i < MAX_OWLS; i++)
  	{
    	owl[i].Draw();
    }
    base.Draw();
    player.Draw();
    mech.Kill();
    discordrpc.Update();
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
