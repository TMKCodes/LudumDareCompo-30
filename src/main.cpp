#include <iostream>
#include <string>
#include <unistd.h>
#include <random>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


bool checkMouseCoordinates(sf::Vector2i mouse, sf::Vector2i topLeft, sf::Vector2i bottomRight) {
	if(mouse.x > topLeft.x && mouse.x < bottomRight.x) {
		if(mouse.y > topLeft.y+40 && mouse.y < bottomRight.y+40) {
			return true;
		}
	}
	return false;
}

int main() {
	sf::RenderWindow window(sf::VideoMode(442, 890), "Connecting Nokia");

	sf::Texture texture;
	if(!texture.loadFromFile("nokia-ludum.png"))
		return EXIT_FAILURE;

	
	sf::RectangleShape nokia(sf::Vector2f(422, 890));
	nokia.setTexture(&texture);
	nokia.setPosition(0, 0);

	std::string number;
	bool calling = false;
	sf::Clock callstarted;
	bool connected = false;
	sf::Clock connectstarted;
	bool ended = false;
	sf::Clock endstarted;

	sf::Font font;
	if(!font.loadFromFile("arial.ttf"))
		return EXIT_FAILURE;

	sf::Text text;
	text.setFont(font);
	text.setCharacterSize(18);
	text.setColor(sf::Color::Black);
	text.setPosition(sf::Vector2f(117, 346));

	std::string callingtext = "Calling..";
	std::string connectedtext = "Connected.";
	std::string callendedtext = "ended.";

	sf::Music click;
	if(!click.openFromFile("click.ogg"))
		return EXIT_FAILURE;
	
	sf::Music connecting;
	if(!connecting.openFromFile("connecting.ogg"))
		return EXIT_FAILURE;
	
	sf::Music callended;
	if(!callended.openFromFile("callended.ogg"))
		return EXIT_FAILURE;

	sf::Music clip1;
	if(!clip1.openFromFile("clip1.ogg"))
		return EXIT_FAILURE;

	sf::Music clip2;
	if(!clip2.openFromFile("clip2.ogg"))
		return EXIT_FAILURE;

	sf::Music clip3;
	if(!clip3.openFromFile("clip3.ogg"))
		return EXIT_FAILURE;

	sf::Music clip4;
	if(!clip4.openFromFile("clip4.ogg"))
		return EXIT_FAILURE;

	sf::Music clip5;
	if(!clip5.openFromFile("clip5.ogg"))
		return EXIT_FAILURE;

	sf::Music clip6;
	if(!clip6.openFromFile("clip6.ogg"))
		return EXIT_FAILURE;

	sf::Music clip7;
	if(!clip7.openFromFile("clip7.ogg"))
		return EXIT_FAILURE;

	sf::Music clip8;
	if(!clip8.openFromFile("clip8.ogg"))
		return EXIT_FAILURE;

	sf::Music clip9;
	if(!clip9.openFromFile("clip9.ogg"))
		return EXIT_FAILURE;

	sf::Music clip10;
	if(!clip10.openFromFile("clip10.ogg"))
		return EXIT_FAILURE;

	sf::Music clip11;
	if(!clip11.openFromFile("gamewin.ogg"))
		return EXIT_FAILURE;

	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 11);

	int roll = 0;

	while(window.isOpen()) {
		sf::Event event;
		while(window.pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				window.close();
			if(event.type == sf::Event::Resized)
				window.setSize(sf::Vector2u(442, 890));
		}
		if(sf::Mouse::isButtonPressed(sf::Mouse::Button::Left)) {
			sf::Vector2i mousepos = sf::Mouse::getPosition(window);
			mousepos = (sf::Vector2i)window.mapPixelToCoords(mousepos);
			if(checkMouseCoordinates(mousepos, sf::Vector2i(140, 241), sf::Vector2i(270, 454))) {
				if(calling == false && connected == false && ended == false) {
					calling = true;
					callstarted.restart();
					connecting.setLoop(true);
					connecting.play();
				} else if(calling == false && connected == true && ended == false) {
					connected = false;
					ended = true;
					endstarted.restart();
					callended.setLoop(true);
					callended.play();
				}
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(93,450), sf::Vector2i(135,500))) {
				number.pop_back();
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(224,469), sf::Vector2i(340,518))) {
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(78,541), sf::Vector2i(133,577))) {
				number.append("1");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(183,558), sf::Vector2i(240,588))) {
				number.append("2");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(290,549), sf::Vector2i(349,581))) {
				number.append("3");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(74,603), sf::Vector2i(143,647))) {
				number.append("4");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(181,612), sf::Vector2i(244,653))) {
				number.append("5");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(288,612), sf::Vector2i(352,640))) {
				number.append("6");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(81,662), sf::Vector2i(148,714))) {
				number.append("7");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(174,674), sf::Vector2i(245,720))) {
				number.append("8");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(281,669), sf::Vector2i(345,707))) {
				number.append("9");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(82,722), sf::Vector2i(152,774))) {
				number.append("*");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(182,734), sf::Vector2i(247,780))) {
				number.append("0");
				click.play();
			} else if(checkMouseCoordinates(mousepos, sf::Vector2i(283,752), sf::Vector2i(338,766))) {
				number.append("#");
				click.play();
			}
			usleep(100000);
		}
		std::cout << number << std::endl;

		if(calling == true) {
			text.setString(callingtext);
			sf::Time time = callstarted.getElapsedTime();
			if(time.asSeconds() >= 5) {
				connecting.stop();	
				connected = true;
				calling = false;
				roll = distribution(generator);
				if(roll == 1) {
					clip1.setLoop(true);
					clip1.play();
				} else if(roll == 2) {
					clip2.setLoop(true);
					clip2.play();
				} else if(roll == 3) {
					clip3.setLoop(true);
					clip3.play();
				} else if(roll == 4) {
					clip4.setLoop(true);
					clip4.play();
				} else if(roll == 5) {
					clip5.setLoop(true);
					clip5.play();
				} else if(roll == 6) {
					clip6.setLoop(true);
					clip6.play();
				} else if(roll == 7) {
					clip7.setLoop(true);
					clip7.play();
				} else if(roll == 8) {
					clip8.setLoop(true);
					clip8.play();
				} else if(roll == 9) {
					clip9.setLoop(true);
					clip9.play();
				} else if(roll == 10) {
					clip10.setLoop(true);
					clip10.play();
				} else if(roll == 11) {
					clip11.setLoop(true);
					clip11.play();
				}
			}
		} else if(connected == true) {
			text.setString(connectedtext);
			sf::Time time = connectstarted.getElapsedTime();
			if(time.asSeconds() >= 30) {
				connected = false;
				ended = true;
			}
		} else if(ended == true) {
			text.setString(callendedtext);
			sf::Time time = endstarted.getElapsedTime();
			if(time.asSeconds() >= 3) {
				callended.stop();
				number = "";
				ended = false;
			}
			if(roll == 1) {
				clip1.stop();
			} if(roll == 2) {
				clip2.stop();
			} if(roll == 3) {
				clip3.stop();
			} if(roll == 4) {
				clip4.stop();
			} if(roll == 5) {
				clip5.stop();
			} if(roll == 6) {
				clip6.stop();
			} if(roll == 7) {
				clip7.stop();
			} if(roll == 8) {
				clip8.stop();
			} if(roll == 9) {
				clip9.stop();
			} if(roll == 10) {
				clip10.stop();
			} if(roll == 11) {
				clip11.stop();
			}
		} else {
			text.setString(number);
		}
		window.clear();
		window.draw(nokia);
		window.draw(text);
		window.display();
	}
	return EXIT_SUCCESS;
}
