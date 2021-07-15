#pragma once
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <ctime>
#include <iostream>
class Ball
{
private:
	sf::CircleShape shape;
	float xVelocity, yVelocity;
	int radius;

	void initVelocity();
	void initShape();
	
public:
	Ball();
	~Ball();

	//functions
	void updateMovement(int i);
	const sf::CircleShape getShape() const;
	int getBallmiddle();

	//game loop functions
	void logic(const sf::RenderTarget* target);
	void render(sf::RenderTarget* target);
};

