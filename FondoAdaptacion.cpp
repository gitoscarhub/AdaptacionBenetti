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
		enum serie { tama�o1,tama�o2 };
		serie tama�o;
		tama�o = tama�o1;
		Font font;
		font.loadFromFile("arial.ttf");

		Text text;
		text.setFont(font);
		text.setString("USE LA TECLA SPACE PARA CAMBIAR EL TAMA�O VENTANA!");
		text.setCharacterSize(24);
		text.setFillColor(Color::White);
		text.setPosition(100, 100);

		while (App.isOpen()){
			
			Event evt{};

			evt.type;

			while (App.pollEvent(evt)) {



				if (evt.type == Event::EventType::Closed)
					App.close();
				
				switch (tama�o)
				{

				case tama�o1:
					if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Space)
					{
						Vector2u minimo = App.getSize();
						App.setSize(Vector2u(minimo.x -700, minimo.y -500));
						tama�o = tama�o2;
					}break;
				case tama�o2:
					if (evt.type == Event::KeyPressed && evt.key.code == Keyboard::Space)
					{
						Vector2u maximo ;
					   App.setSize(Vector2u(maximo.x +700, maximo.y +500));
					   tama�o = tama�o2;
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