#include "Game.h"

void Game::initWindow()
{
	this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Dogwater Game");
	this->window->setFramerateLimit(60);
}

Game::Game()
	:play{ true }
{
	initWindow();
}

Game::~Game()
{
	delete this->window;
}

//getter
bool Game::InPlay()
{
	return play;
}

void Game::updateCollisions()
{
	//checks if player collides with ball
	int playerPosY = player.getShape().getPosition().y;
	int ballPosY = ball.getShape().getPosition().y;
	int aiPosY = ai.getShape().getPosition().y;
	if (player.getShape().getGlobalBounds().intersects(ball.getShape().getGlobalBounds())) {

		if ((ballPosY + 10) > playerPosY && (ballPosY + 10) < (playerPosY + 33)) ball.updateMovement(1); //if ball hits top of padel
		if ((ballPosY + 10) > (playerPosY + 32) && (ballPosY + 10) < (playerPosY + 66)) ball.updateMovement(2); //if ball hits middle of padel
		if ((ballPosY + 10) > (playerPosY + 65) && (ballPosY + 10) < (playerPosY + 101)) ball.updateMovement(3); //if ball hits bottom of padel

		//problem: yVelocity gets set to 0 then stays at 0
	}
	//check if ai collides with ball
	if (ai.getShape().getGlobalBounds().intersects(ball.getShape().getGlobalBounds())) {
		if ((ballPosY + 10) > aiPosY && (ballPosY + 10) < (aiPosY + 33)) ball.updateMovement(1); //if ball hits top of padel
		if ((ballPosY + 10) > (aiPosY + 32) && (ballPosY + 10) < (aiPosY + 66)) ball.updateMovement(2); //if ball hits middle of padel
		if ((ballPosY + 10) > (aiPosY + 65) && (ballPosY + 10) < (aiPosY + 101)) ball.updateMovement(3); //if ball hits bottom of padel
	}
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	while (this->window->pollEvent(this->event)) {
		switch (this->event.type) {
			// close window if 'x' button is pressed
		case sf::Event::Closed:
			this->window->close();
			break;
			//close window if escape key is pressed
		case sf::Event::KeyPressed:
			if (this->event.key.code == sf::Keyboard::Escape)
				this->window->close();
			break;
		}
	}
}


//check user input
void Game::input()
{
	player.input(event,window);
	pollEvents();
}

//game logic
void Game::logic()
{
	player.logic(window);
	ball.logic(window);
	ai.logic(window, ball.getBallmiddle());
	updateCollisions();
}

//draw onto window function
void Game::render()
{
	//clear window
	this->window->clear();

	//render stuff
	player.render(window);
	ai.render(window);
	ball.render(window);
	
	//display
	this->window->display();
}
