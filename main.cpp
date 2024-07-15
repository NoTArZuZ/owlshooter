#include <raylib.h>

int points = 0;
Vector2 mousepos;

class Owl
{
  private:
  Vector2 pos;
  Texture2D image;
  Sound shot;
  bool curinside;
  Vector2 mousepos;
  Rectangle colrec;
  
  public:

  Owl()
  {
    image = LoadTexture("goofyowl.png");
    shot = LoadSound("shot.mp3");
    pos.x = GetRandomValue(0, GetScreenWidth() - 110);
    pos.y = GetRandomValue(0, GetScreenHeight() - 143);
  }
  
  void Draw()
  {
	// mousepos to fix uncentered scope idk how to not make it in better way
    mousepos.x = GetMouseX();
    mousepos.y = GetMouseY();
    DrawTextureEx(image, pos, 0, 0.1f, WHITE);
    colrec = Rectangle{pos.x, pos.y, 143, 110};
    curinside = CheckCollisionPointRec(mousepos, colrec);
  }

  void Kill()
  {
    if (curinside && IsMouseButtonPressed(MOUSE_BUTTON_LEFT))
    {
      points++;
      PlaySound(shot);
      pos.x = GetRandomValue(0, GetScreenWidth() - 110);
      pos.y = GetRandomValue(0, GetScreenHeight() - 143);
    }
  }
};

class Player
{
  private:
  Texture2D cursor;

  public:
  
  Player()
  {
    cursor = LoadTexture("scope.png");
  }
  
  void Draw()
  {
    HideCursor();
    DrawTextureEx(cursor, mousepos, 0, 0.1f, WHITE);
  }
};

class Owl2: public Owl{};
class Owl3: public Owl{};
class Owl4: public Owl{};
class Owl5: public Owl{};

int main()
{
  // Initialize Based Game Window
  InitWindow(1280, 800, "Owl Shooter");
  InitAudioDevice();
  SetTargetFPS(60);
  // Music
  Music music = LoadMusicStream("PovOwlShooting.wav");
  PlayMusicStream(music);
  // Load Background
  Texture2D background = LoadTexture("forest.png");
  // Load classes
  Owl owl;
  Owl2 owl2;
  Owl3 owl3;
  Owl4 owl4;
  Owl5 owl5;
  Player player;
  // Game Loop
  while (!WindowShouldClose())
  {
    BeginDrawing();
	// Update every frame
    ClearBackground(WHITE);
	// Draw Background
    DrawTexture(background, 0, 0, WHITE);
	// Update Music
    UpdateMusicStream(music);
	// Fix uncentered scope
    mousepos.x = GetMouseX() - 72;
    mousepos.y = GetMouseY() - 48;
	// Draw 5 owls
    owl.Draw();
    owl.Kill();
    owl2.Draw();
    owl2.Kill();
    owl3.Draw();
    owl3.Kill();
    owl4.Draw();
    owl4.Kill();
    owl5.Draw();
    owl5.Kill();
	// Draw score
    DrawText(TextFormat("KILLED OWLS %i", points), GetScreenWidth()/2 - 128, 20, 32, WHITE);
	// Draw scope
    player.Draw();
	// Press f to fullscreen
    if (IsKeyPressed(KEY_F))
    {
      ToggleFullscreen();
    }
    EndDrawing();
  }

  CloseWindow();
  return 0;
}
