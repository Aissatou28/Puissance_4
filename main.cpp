#include <SFML/Graphics.hpp>
#include <iostream>


//
bool playColumn(int column, int state[7][6], bool playerTurn)
{
	int i;
	for (i = 0; i < 6; i++)
	{
		if (state[column][5 - i] == 0)
		{
			break;
		}
	}
	//std::cout << "click sur la colonne 1" << std::endl;
	state[column][5 - i] = playerTurn ? 1 : 2;
	
	return true;
}

void alignCol(int colonne, int state[7][6]) {
	for (colonne = 0; colonne < 7; colonne++) {
		if (state[6 - colonne][0] == 1 && state[6 - colonne][1] == 1 && state[6 - colonne][2] == 1 && state[6 - colonne][3] == 1
			|| state[6 - colonne][1] == 1 && state[6 - colonne][2] == 1 && state[6 - colonne][3] == 1 && state[6 - colonne][4] == 1
			|| state[6 - colonne][2] == 1 && state[6 - colonne][3] == 1 && state[6 - colonne][4] == 1 && state[6 - colonne][5] == 1
			) {
			std::cout << "Le joueur 1 (rouge) a gagne" << std::endl;
		}
		else if (state[6 - colonne][0] == 2 && state[6 - colonne][1] == 2 && state[6 - colonne][2] == 2 && state[6 - colonne][3] == 2
			|| state[6 - colonne][1] == 2 && state[6 - colonne][2] == 2 && state[6 - colonne][3] == 2 && state[6 - colonne][4] == 2
			|| state[6 - colonne][2] == 2 && state[6 - colonne][3] == 2 && state[6 - colonne][4] == 2 && state[6 - colonne][5] == 2
			) {
			std::cout << "Le joueur 2 (jaune) a gagne" << std::endl;
		}
	}
}

void alignLig(int ligne, int state[7][6]) {
	for (ligne = 0; ligne < 6; ligne++) {
		if (state[0][5 - ligne] == 1 && state[1][5 - ligne] == 1 && state[2][5 - ligne] == 1 && state[3][5 - ligne] == 1
			|| state[1][5 - ligne] == 1 && state[2][5 - ligne] == 1 && state[3][5 - ligne] == 1 && state[4][5 - ligne] == 1
			|| state[2][5 - ligne] == 1 && state[3][5 - ligne] == 1 && state[4][5 - ligne] == 1 && state[5][5 - ligne] == 1
			|| state[3][5 - ligne] == 1 && state[4][5 - ligne] == 1 && state[5][5 - ligne] == 1 && state[6][5 - ligne] == 1
			) {
			std::cout << "Le rouge a gagne" << std::endl;
		}
		else if (state[0][5 - ligne] == 2 && state[1][5 - ligne] == 2 && state[2][5 - ligne] == 2 && state[3][5 - ligne] == 2
			|| state[1][5 - ligne] == 2 && state[2][5 - ligne] == 2 && state[3][5 - ligne] == 2 && state[4][5 - ligne] == 2
			|| state[2][5 - ligne] == 2 && state[3][5 - ligne] == 2 && state[4][5 - ligne] == 2 && state[5][5 - ligne] == 2
			|| state[3][5 - ligne] == 2 && state[4][5 - ligne] == 2 && state[5][5 - ligne] == 2 && state[6][5 - ligne] == 2
			) {
			std::cout << "Le jaune a gagne" << std::endl;
		}
	}
}


int main(int argc, char **argv)
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "My window");
	sf::Texture image;
	image.loadFromFile("./assets/GrillePuissance4.png");

	bool playerTurn = true;

	int click = 0;

	//tableau
	int state[7][6];
	for (int i = 0; i < 7; i++)
	{
		for (int j = 0; j < 6; j++)
		{
			state[i][j] = 0;
		}
	}

	/*
	if(int x==0 &&){
		for(y=0; y<4; y++;){
			if (state[x][y]=playerturn){
				std::cout << "Le rouge a gagné" << std::endl;
			}
		}
	}
	*/

	sf::Sprite sprite;
	sprite.setTexture(image);
	sprite.setScale(0.5f, 0.6f);
	sprite.setPosition(sf::Vector2f(200, 75));

	sf::CircleShape cercleJ;
	cercleJ.setFillColor(sf::Color(255, 255, 0));
	cercleJ.setRadius(23);
	cercleJ.setPosition(100, 50);

	sf::CircleShape cercleR;
	cercleR.setFillColor(sf::Color(255, 0, 0));
	cercleR.setRadius(23);
	cercleR.setPosition(50, 50);
	


	sf::Clock clock;

	if (!image.loadFromFile("./assets/GrillePuissance4.png"))
	{
		std::cout << "Erreur lors chargement del'image" << std::endl;
	}

	// on fait tourner le programme jusqu'à ce que la fenêtre soit fermée
	while (window.isOpen())
	{
		// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
		sf::Event event;
		while (window.pollEvent(event))
		{
			// évènement "fermeture demandée" : on ferme la fenêtre
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseButtonPressed)
			{
				if (event.mouseButton.button == sf::Mouse::Left)
				{
					std::cout << "the left button was pressed" << std::endl;
					std::cout << "mouse x: " << event.mouseButton.x << std::endl;
					std::cout << "mouse y: " << event.mouseButton.y << std::endl;

					int x = event.mouseButton.x;
					int y = event.mouseButton.y;

					//pour vérifier si une colonne est déjà cliqué
					bool clickColumn = false;

					//int nbJ = 0; int nbR = 0;

					// Colonne 1 :
					if (x >= 200 && x <= 250 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 1" << std::endl;
						clickColumn = playColumn(0, state, playerTurn);
					}
					//Colonne 2 :
					if (x >= 250 && x <= 300 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 2" << std::endl;
						//state[1][5] = playerTurn ? 1 : 2;
						//clickColumn = true;
						clickColumn = playColumn(1, state, playerTurn);
					}
					//Colonne 3 :
					if (x >= 300 && x <= 350 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 3" << std::endl;
						clickColumn = playColumn(2, state, playerTurn);
					}
					//Colonne 4 :
					if (x >= 350 && x <= 400 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 4" << std::endl;
						clickColumn = playColumn(3, state, playerTurn);
					}
					//Colonne 5 :
					if (x >= 400 && x <= 450 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 5" << std::endl;
						clickColumn = playColumn(4, state, playerTurn);
					}
					//Colonne 6 :
					if (x >= 450 && x <= 500 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 6" << std::endl;
						clickColumn = playColumn(5, state, playerTurn);
					}
					//Colonne 7 :
					if (x >= 500 && x <= 550 && y >= 75 && y <= 432)
					{
						std::cout << "click sur la colonne 7" << std::endl;
						clickColumn = playColumn(6, state, playerTurn);
					}

					if (clickColumn)
							playerTurn = !playerTurn;

					/*if (x >= 200 && x <= 250 && y >= 192 && y <= 432) {
						//state[0][3] = playerTurn ? 1 : 2;
					}*/


					}
				}
			}



			window.clear();

			window.draw(sprite);

			window.draw(cercleJ);


			cercleR.setPosition(50, 50);
			cercleJ.setPosition(100, 50);
			window.draw(cercleR);
			window.draw(cercleJ);


			int rouge = 0;
			int colonne1 = 0;

			for (int x = 0; x < 7; x++)
			{
				for (int y = 0; y < 6; y++)
				{
					if (state[x][y] == 1)
					{
						cercleR.setPosition(200 + x * 50, 75 + 8 + y * 59.5);
						window.draw(cercleR);
					}
					else if (state[x][y] == 2)
					{
						cercleJ.setPosition(200 + x * 50, 75 + 8 + y * 59.5);
						window.draw(cercleJ);
					}
				}
			}

			
			alignCol(6, state);
			alignCol(5, state);
			alignCol(4, state);
			alignCol(3, state);
			alignCol(2, state); 
			alignCol(1, state);
			alignCol(0, state);

			alignLig(0, state);
			alignLig(1, state);
			alignLig(2, state);
			alignLig(3, state);
			alignLig(4, state);
			alignLig(5, state);






			/*int x = 0;
			if (x == 0) {
				if (state[x][0] == 1 && state[x][1] == 1 && state[x][2] == 1 && state[x][3] == 1 
					|| state[x][1] == 1 && state[x][2] == 1 && state[x][3] == 1 && state[x][4] == 1
					|| state[x][2] == 1 && state[x][3] == 1 && state[x][4] == 1 && state[x][5] == 1

				{
					std::cout << "Le rouge a gagne" << std::endl;
				}
				else if (state[x][0] == 2 && state[x][1] == 2 && state[x][2] == 2 && state[x][3] == 2
					|| state[x][1] == 2 && state[x][2] == 2 && state[x][3] == 2 && state[x][4] == 2
					|| state[x][2] == 2 && state[x][3] == 2 && state[x][4] == 2 && state[x][5] == 2)
				{
					std::cout << "Le jaune a gagne" << std::endl;
				}
			}*/
			
			
			window.display();

		}

		return 0;



		/*
						se référer à la fonction playcolumn pour plus d'efficacité
						if (click == 0) {
							std::cout << "click sur la colonne 1" << std::endl;
							state[0][5] = playerTurn ? 1 : 2;
							clickColumn = true;
							click++;
						}
						else if (click == 1) {
							state[0][4] = playerTurn ? 1 : 2;
							clickColumn = true;
							click++;
						}
						else if (click == 2) {
							state[0][3] = playerTurn ? 1 : 2;
							clickColumn = true;
							click++;
						}
						else if (click == 3) {
							state[0][2] = playerTurn ? 1 : 2;
							clickColumn = true;
							click++;
						}
						else if (click == 4) {
							state[0][1] = playerTurn ? 1 : 2;
							clickColumn = true;
							click++;
						}
						else if (click == 5) {
							state[0][0] = playerTurn ? 1 : 2;
							clickColumn = true;
							click++;
						}
						*/


		/*playerTurn ? 1 : 2 signifie
		if(playerTurn){
		state[0][5] = 1
		}else{
		state[0][5] = 2
		}*/

		/*
		Classe game state avec
		des attributs (propriétés):
		-state: tableau double entrées
		-player turn de type booléen
		méthodes
		+Play Move
		+getAll
		*/
	}
