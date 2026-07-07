#include <SFML/Graphics.hpp>

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "DVD Screensaver");
    
    sf::Texture texture;
    if (!texture.loadFromFile("dvd.png")) {
        return -1; 
    }

    sf::Sprite dvd;
    dvd.setTexture(texture);
    dvd.setScale(0.2f, 0.2f);

    float posX = 400.f, posY = 300.f;
    float velX = 0.05f, velY = 0.07f;

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) window.close();
        }

        posX += velX;
        posY += velY;

        float width = dvd.getGlobalBounds().width;
        float height = dvd.getGlobalBounds().height;

        if (posX <= 0 || posX + width >= 800) velX = -velX;
        if (posY <= 0 || posY + height >= 600) velY = -velY;

        dvd.setPosition(posX, posY);

        window.clear();
        window.draw(dvd);
        window.display();
    }
    return 0;
}
