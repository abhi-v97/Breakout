#ifndef GAME_H
#define GAME_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "game_level.h"
#include "power_up.h"

// Variables that hold current game state
enum GameState {
    GAME_ACTIVE,
    GAME_MENU,
    GAME_WIN
};

// Represents the four possible (collision) directions
enum Direction {
    UP,
    RIGHT,
    DOWN,
    LEFT
};
// Defines a Collision typedef that represents collision data
typedef std::tuple<bool, Direction, glm::vec2> Collision; // <collision?, what direction?, difference vector center - closest point>

// Initial size of the player paddle
const glm::vec2 PLAYER_SIZE(100.0f, 20.0f);
// Initial velocity of the player paddle
const float PLAYER_VELOCITY(500.0f);
// Initial velocity of the Ball
const glm::vec2 INITIAL_BALL_VELOCITY(100.0f, -350.0f);
// Radius of the ball object
const float BALL_RADIUS = 12.5f;

// An uber game class that contains all relevant render and gameplay code
// links together all the different components that form the game
// decouples code and object from the game window itself, 
// which lets you use the same code for a different window library easily
class Game
{
public:
    // game state
    GameState               State;	
    bool                    Keys[1024];
    bool                    KeysProcessed[1024];
    unsigned int            Width, Height;
    std::vector<GameLevel>  Levels;
    std::vector<PowerUp>    PowerUps;
    unsigned int            Level;
    unsigned int            Lives;
    // constructor/destructor
    Game(unsigned int width, unsigned int height);
    ~Game();
    // initialise game state, load all shaders/textures/levels
    void Init();

    // process input within the Keys array
    void ProcessInput(float dt); 
    // update all gameplay elements
    void Update(float dt); 
    void Render();
    void DoCollisions();
    // reset
    void ResetLevel();
    void ResetPlayer();
    // powerups
    void SpawnPowerUps(GameObject &block);
    void UpdatePowerUps(float dt);
};

#endif