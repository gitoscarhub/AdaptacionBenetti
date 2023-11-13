#include<SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
using namespace sf;
Texture fondo;
Sprite bkg;

int main(){

		RenderWindow App(sf::VideoMode(800, 600, 32), "Adaptacion Ventana con fondo");

		fondo.loadFromFile("fondobis.jpg");
		bkg.setTexture(fondo);
		bkg.setPosition(0, 0);
		enum serie { tamaño1,tamaño2 };
		serie tamaño;
		tamaño = tamaño1;
		Font font;
		font.loadFromFile("arial.ttf");

		Text text;
		text.setFont(font);
		text.setString("USE LA TECLA SPACE PARA CAMBIAR EL TAMAÑO VENTANA!");
		text.setCharacterSize(24);
		text.setFillColor(Color::White);
		text.setPosition(100, 100);

		while (App.isOpen()){
			
			Event evt{};

			evt.type;

			while (App.pollEvent(evt)) {



				if (evt.type == Event::EventType::Closed)
					App.close();
				
				switch (tamaño)
				{

				case tamaño1:
					if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Space)
					{
						Vector2u minimo = App.getSize();
						App.setSize(Vector2u(minimo.x -700, minimo.y -500));
						tamaño = tamaño2;
					}break;
				case tamaño2:
					if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Space)
					{
						Vector2u maximo ;
					   App.setSize(Vector2u(maximo.x +700, maximo.y +500));
					   tamaño = tamaño2;
					}break;

				default: break;
				}
				
			}
			App.clear();
			App.draw(bkg);
			App.draw(text);
			App.display();
		
		}
		return 0;
	
}