#include "Game.h"
#include "Player.h"


void display_level(RenderWindow& window, const int height, const int width, char** lvl, Sprite& wallSprite1, const int cell_size)
{
	for (int i = 0; i < height; i += 1)
	{
		for (int j = 0; j < width; j += 1)
		{
			if (lvl[i][j] == 'g')
			{
				wallSprite1.setPosition(j * cell_size, i * cell_size);
				window.draw(wallSprite1);
			}
		}
	}
}



void Game::run()
{

	int screen_x = 1600;
	int screen_y = 900;

	// prototypes

	RenderWindow window(VideoMode(screen_x, screen_y), "Metal Slug", Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	/////////////////////////////////////////////////////////////////
	// a cell is 64 by 64 pixels
	// 'g' = grass tile

	const int cell_size = 64;
	const int height = 14;
	const int width = 110;



	char** lvl = NULL;

	lvl = new char* [height];
	for (int i = 0; i < height; i += 1)
	{
		lvl[i] = new char[width] {'\0'};
	}

	lvl[11][5] = 'g';
	lvl[11][6] = 'g';
	lvl[11][7] = 'g';
	lvl[11][8] = 'g';

	Texture wallTex1;
	Sprite wallSprite1;

	wallTex1.loadFromFile("Sprites/blocks/grass_block_side.png");
	wallSprite1.setTexture(wallTex1);

	////////////////////////////////////////////////////////
	
	// IMPORTANT NOTE: dt give approx 0.016 value
	float player_x = 500;
	float player_y = 100;	// row 11 * 64 - Pheight = 704 - 94

	float max_speed = 10;
	float jumpVelocity=70;
	float velocityX = 0;
	float acceleration = 100;

	int Pheight = cell_size*2;//raw_img_y * scale_y;	// 94
	int Pwidth = cell_size* 5/3 ;//raw_img_x * scale_x;	// 119

	Texture playerTex;
	Sprite playerSprite;

	playerTex.loadFromFile(("Sprites/Eri Kasamoto.png"));
	
	playerSprite.setTexture(playerTex);
	//playerSprite.setScale(scale_x, scale_y);

	Player* player = new Player(player_x, player_y, Pwidth/2, Pheight/2, playerTex, 0.0f, 0.0f, jumpVelocity, acceleration,max_speed);

	////////////////////////////////////////////////////////

	Event ev;
	while (window.isOpen())
	{
		// closing loop
		while (window.pollEvent(ev))
		{
			if (ev.type == Event::Closed)
			{
				window.close();
			}

			if (ev.type == Event::KeyPressed)
			{
			}
		}

		// set dt to make game platform independent
		float dt = clock.restart().asSeconds(); // get time in delta seconds this will be passed in update 
		


		//////////////////////////////////////////////////////////////////////// updates
		// 
			// makes sure that player does not get bellow screen
		if (player->getPosition().y + player->getHitBox().height >= screen_y)	
		{
			player->land();
			player->setPosition(player->getPosition().x,screen_y - player->getHitBox().height);
		}

		// Check bounds 
		bool isAtLeftWall = (player->getPosition().x - player->getHitBox().width <= 10);
		bool isAtRightWall = (player->getPosition().x + player->getHitBox().width >= screen_x);

		// Set both bounds
		player->setMovemntBound(isAtLeftWall, isAtRightWall);

			
			

		///////////////////////////////////////////////////////////////////////////////////////

		player->update(dt);

		
		//std::cout << player->getPosition().x << ' ' << player->getPosition().y << std::endl;
		
		// redering
		window.clear();

		display_level(window, height, width, lvl, wallSprite1, cell_size);
		player->render(window);

		window.display();
	}

	delete player;
}

