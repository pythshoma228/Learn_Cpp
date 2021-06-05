#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

void makeField(RectangleShape* sea, int size, Vector2f xy)
{
	for (int i = 0, Row = 0, Col = 0; i < size; i++)
	{

		sea[i].setSize(Vector2f(30.f, 30.f));
		sea[i].setOutlineThickness(2.f);
		sea[i].setOutlineColor(Color::Black);
		sea[i].setPosition(xy);

		if (i % 10 != 0)
			Col++;
		else
		{
			Col = 0;
			Row++;
		}

		sea[i].move(
			(sea[i].getSize().x + sea[i].getOutlineThickness()+ 4.f) * Col,
			(sea[i].getSize().y + sea[i].getOutlineThickness() + 4.f) * Row
		);
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	RenderWindow app(VideoMode::getDesktopMode(), "Sea War", Style::Fullscreen);
	Event e;
	Mouse mouse;
	Cursor cur;
	Keyboard keyboard;
	
	int size = 100;

	int* counter1 = new int();
	int* counter2 = new int();

	RectangleShape seaSaved1[100];
	RectangleShape seaSaved2[100];
	
	makeField(seaSaved1, size, Vector2f(100.f, 200.f));
	makeField(seaSaved2, size, Vector2f(800.f, 200.f));

	

	Font font;
	font.loadFromFile("Fonts/arial.ttf");

	Text textP1;
	textP1.setString("Player 1");
	textP1.setCharacterSize(30);
	textP1.setFillColor(Color::Black);
	textP1.setPosition(150.f, 150.f);
	textP1.setStyle(Text::Style::Regular);
	textP1.setFont(font);

	Text textP2;
	textP2.setString("Player 2");
	textP2.setFillColor(Color::Black);
	textP2.setPosition(1000.f, 150.f);
	textP2.setStyle(Text::Style::Regular);
	textP2.setFont(font);
	
	String strPlayerTurn;

	bool playerTurn = 0;
	bool setShips = true;
	
	Texture cross;
	Texture miss;
	cross.loadFromFile("Sprites/cross.png");
	miss.loadFromFile("Sprites/miss.png");

	while (app.isOpen())
	{
		app.clear(Color::White);

		if (keyboard.isKeyPressed(Keyboard::Escape))
		{
			app.close();
			sleep(Time(microseconds(Int64(100000))));
		}

		RectangleShape* sea1 = new RectangleShape[size];
		RectangleShape* sea2 = new RectangleShape[size];

		
		Text playerTurnText(strPlayerTurn, font);
		playerTurnText.setFillColor(Color::Black);
		playerTurnText.setPosition(480.f, 150.f);
		playerTurnText.setStyle(Text::Style::Regular);

		makeField(sea1, size, Vector2f(100.f, 200.f));
		makeField(sea2, size, Vector2f(800.f, 200.f));
		
		for (int i = 0; i < size; i++)
		{
			sea1[i].setTexture(seaSaved1[i].getTexture());
			sea2[i].setTexture(seaSaved2[i].getTexture());
		}
		
		//Условие выполняется если очередь первого игрока и идет расстановка кораблей
		if (playerTurn == 0 && setShips == true)
		{
			strPlayerTurn = "Player 1, set the Ships!";
			for (int i = 0; i < size; i++)
			{
				if (
					sea1[i].getGlobalBounds().contains(Vector2f(mouse.getPosition()))
					&& mouse.isButtonPressed(Mouse::Left) && seaSaved1[i].getOutlineThickness() != 6.f)
				{
					(*counter1)++;
					seaSaved1[i].setOutlineThickness(6.f);
					seaSaved1[i].setFillColor(Color::Black);
					sleep(Time(microseconds(Int64(250000))));
				}
				sea1[i] = seaSaved1[i];
				sea2[i].setFillColor(Color::Black);
			}
			if (*counter1 >= 20)
			{
				playerTurn = 1;
				*counter1 = 1;
			}
		}
		//Условие выполняется после расстановки
		else if (playerTurn == 0)
		{
			strPlayerTurn = "Player 1 turn!";
			for (int i = 0; i < size; i++)
			{
				if (
					sea2[i].getGlobalBounds().contains(Vector2f(mouse.getPosition()))
					&& mouse.isButtonPressed(Mouse::Left))
				{
					if (seaSaved2[i].getOutlineThickness() == 6.f && seaSaved2[i].getTexture() == nullptr)
					{
						(*counter2)++;
						seaSaved2[i].setTexture(&cross);
						sleep(Time(microseconds(Int64(250000))));
					}
					else if(seaSaved2[i].getTexture() == nullptr)
					{
						seaSaved2[i].setTexture(&miss);
						playerTurn = 1;
					}
				}
				sea1[i].setFillColor(Color::Black);
			}
			if (*counter2 == 20)
			{
				strPlayerTurn = "Player 1 won !";
				delete counter1;
				delete counter2;
			}
		}

		//Условие выполняется если очередь второго игрока и идет расстановка кораблей
		if (playerTurn == 1 && setShips == true)
		{
			strPlayerTurn = "Player 2, set the Ships!";
			for (int i = 0; i < size; i++)
			{
				if (
					sea2[i].getGlobalBounds().contains(Vector2f(mouse.getPosition()))
					&& mouse.isButtonPressed(Mouse::Left) && seaSaved2[i].getOutlineThickness() != 6.f)
				{
					(*counter2)++;
					seaSaved2[i].setOutlineThickness(6.f);
					seaSaved2[i].setFillColor(Color::Black);
					sleep(Time(microseconds(Int64(250000))));
				}
				
				sea2[i] = seaSaved2[i];
				sea1[i].setFillColor(Color::Black);
			}
			if (*counter2 >= 20)
			{
				setShips = false;
				*counter2 = 1;
			}
		}
		//Условие выполняется после расстановки
		else if (playerTurn == 1)
		{
			strPlayerTurn = "Player 2 turn!";
			for (int i = 0; i < size; i++)
			{
				if (
					sea1[i].getGlobalBounds().contains(Vector2f(mouse.getPosition()))
					&& mouse.isButtonPressed(Mouse::Left))
				{
					if (seaSaved1[i].getOutlineThickness() == 6.f && seaSaved1[i].getTexture() == nullptr)
					{
						(*counter1)++;
						seaSaved1[i].setTexture(&cross);
						sleep(Time(microseconds(Int64(250000))));
					}
					else if (seaSaved1[i].getTexture() == nullptr)
					{
						seaSaved1[i].setTexture(&miss);
						playerTurn = 0;
					}
				}
				sea2[i].setFillColor(Color::Black);
			}
			if (*counter1 == 20)
			{
				strPlayerTurn = "Player 2 won !";
				delete counter1;
				delete counter2;
			}
		}

		//(keyboard.isKeyPressed(Keyboard::R)) ? system("cls") : NULL;
		/*if (keyboard.isKeyPressed(Keyboard::R))
		{
			for (int i = 0; i < size; i++)
			{
				sea1[i] = seaSaved1[i];
				sea2[i] = seaSaved2[i];
			}
		}*/

		

		app.draw(textP1);
		app.draw(textP2);
		app.draw(playerTurnText);
		for (int i = 0; i < size; i++)
		{
			app.draw(sea1[i]);
			app.draw(sea2[i]);
		}
		app.display();

		delete[] sea1;
		delete[] sea2;
		while (app.pollEvent(e))
		{
			if (e.type == Event::Closed)
			{
				app.close();
			}
		}
	}
	
	return 0;
}