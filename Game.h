#pragma once
#include <SFML/Graphics.hpp>
#include "Player.h"
#include "Ball.h"
#include "Ai.h"
class Game
{
private:

	sf::RenderWindow* window;
	sf::Event event;
	
	bool play;
	//game objects
	Player player;
	Ball ball;
	Ai ai;

	//functions
	void initWindow();
public:
	Game();
	~Game();

	//getters / setters
	bool InPlay();

	//functions
	const bool running() const;
	void pollEvents();
	void updateCollisions();


	//game loop functions
	void input();
	void logic();
	void render();

};


