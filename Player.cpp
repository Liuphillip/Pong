#include "Player.h"

void Player::initShape()
{
	this->shape.setFillColor(sf::Color::Green);
	this->shape.setSize(sf::Vector2f(50, 100));
	shape.setPosition(0, 200);
}

Player::Player()
	:moveSpeed{ 5 }
{
	initShape();
	
}
Player::~Player()
{
}

const sf::RectangleShape Player::getShape() const
{
	return shape;
}




void Player::input(sf::Event& ev,sf::RenderWindow* target)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
		this->shape.move(0, -this->moveSpeed);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
		this->shape.move(0, this->moveSpeed);
	}
}



void Player::logic(const sf::RenderTarget* target)
{

	//COLLISION
	//top
	sf::FloatRect playerBounds = this->shape.getGlobalBounds();
	if (playerBounds.top <= 0) {
		shape.move(0, moveSpeed);
	}
	//bottom
	else if (playerBounds.top + playerBounds.height >= target->getSize().y) {
		shape.move(0, -moveSpeed);
	}
}

void Player::render(sf::RenderTarget* target)
{
	target->draw(shape);
}
