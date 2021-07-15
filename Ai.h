#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
class Ai
{
private:
	sf::RectangleShape shape;
	float moveSpeed;
	
	void initShape();
	
public:
	Ai();
	~Ai();

	//functions
	const sf::RectangleShape getShape() const;
	int compareBalltoAi(int y);

	//game loop functions
	void logic(const sf::RenderTarget* target,int y);
	void render(sf::RenderTarget* target);
};

