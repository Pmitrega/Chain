#include <iostream>
#include "SFML/Graphics.hpp"
#include "atoms.hpp"
#include "physics_interface.hpp"
#include <random>
#include <iostream>
int main() {
    double gravity = 500000;
    std::random_device dev;
    std::mt19937 rng(dev());
    std::uniform_int_distribution<std::mt19937::result_type> random(1,1000);
    sf::RenderWindow wind;
    wind.create(sf::VideoMode(1600,900),"My window");
    wind.setFramerateLimit(60);
    sf::Font font;
    font.loadFromFile("Arial.ttf");
    sf::Text text("gravity", font);
    text.setPosition(sf::Vector2f(1000, 20));
    text.setFillColor(sf::Color::White);
    text.setCharacterSize(20);
    text.setStyle(sf::Text::Bold);
    Slider slider(1000, 50, 20 , 200 );
    sf::RectangleShape slider_rect(sf::Vector2f(100,20));
    slider_rect.setFillColor(sf::Color::Green);
    slider_rect.setPosition(1000, 50);
    sf::RectangleShape slider_background(sf::Vector2f(  200 + 10,30));
    slider_background.setFillColor(sf::Color::Red);
    slider_background.setPosition(1000 - 5, 50 - 5);
    AtomNet at;
    AtomChain ac;
    ac.arrangeChain();
    //at.arrangeNet();
    auto atoms = ac.getAtoms();
    ac.set_gravity(gravity);
    //at.disturb(0, Point2D{5,5});
    int counter = 0;
    while(wind.isOpen()) {
        sf::Event event{};
        while (wind.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                wind.close();
            }
            if (sf::Mouse::isButtonPressed(sf::Mouse::Left)){
                int x_pos = sf::Mouse::getPosition(wind).x;
                int y_pos = sf::Mouse::getPosition(wind).y;
                int ind = ac.getNearest(x_pos,y_pos);
                if(ind >= 0) {
                    ac.setPos(ind, x_pos, y_pos);
                    ac.setVel(ind, 0, 0);
                }
                slider.set_value(x_pos, y_pos);
                std::cout <<slider.get_length();
                slider_rect.setSize(sf::Vector2f(slider.get_length(),20));
                ac.set_gravity(gravity * slider.get_value());
            }
        }
        wind.clear(sf::Color::Black);
        wind.draw(slider_background);
        wind.draw(slider_rect);
        wind.draw(text);
        atoms = ac.getAtoms();
        for(auto atom:atoms){
            sf::CircleShape cr(3);
            cr.setFillColor(sf::Color::White);
            //std::cout<<"x: " << (float)atom.get_pos().x_<<" y: " <<(float)atom.get_pos().y_<<std::endl;
            cr.setPosition((float)atom.get_pos().x_,(float)atom.get_pos().y_ );
            wind.draw(cr);
        }
        if(counter == 100){
            //ac.disturb(0, Point2D{0,-20});
            //at.disturb(random(rng));
        }
        counter+=1;
        ac.simChain();
        wind.display();
    }
}
































//    sf::RenderWindow wind;
//    Player player;
//    Physics phys;
//    Map map;
//    map.initMap();
//    wind.create(sf::VideoMode(1600,900),"My window");
//    wind.setFramerateLimit(60);
//    sf::Texture* wall_texture = new sf::Texture;
//    sf::Texture* background_text = new sf::Texture;
//    background_text->loadFromFile(getCurrentPath()+"\\textures\\grass_field.jpg");
//    sf::Sprite bckgSprt(*background_text);
//    sf::View view;
//    view.setSize(1600,900);
//    while(wind.isOpen()){
//        sf::Event event;
//        while(wind.pollEvent(event)){
//            if (event.type == sf::Event::Closed){
//                wind.close();
//            }
//            if(event.type == sf::Event::KeyPressed){
//                if(event.key.code == sf::Keyboard::Space){
//                    phys.jumpPlayer(player);
//                }
//            }
//
//        }
//        view.setCenter(player.getLocation());
//        phys.accelerateByPlayer(player);
//        phys.accByGravity(player);
//        phys.applyPhysics(player);
//        phys.collisionDetection(player,map);
//        bckgSprt.setPosition(view.getCenter().x - 800, view.getCenter().y - 450);
//        wind.setView(view);
//        wind.clear(sf::Color::Cyan);
//        wind.draw(bckgSprt);
//        map.drawMap(wind);
//        wind.draw(player.getSprite());
//        wind.display();
//    }
//    delete  wall_texture;
//    delete background_text;
//    return 0;//    sf::RenderWindow wind;
////    Player player;
////    Physics phys;
////    Map map;
////    map.initMap();
////    wind.create(sf::VideoMode(1600,900),"My window");
////    wind.setFramerateLimit(60);
////    sf::Texture* wall_texture = new sf::Texture;
////    sf::Texture* background_text = new sf::Texture;
////    background_text->loadFromFile(getCurrentPath()+"\\textures\\grass_field.jpg");
////    sf::Sprite bckgSprt(*background_text);
////    sf::View view;
////    view.setSize(1600,900);
////    while(wind.isOpen()){
////        sf::Event event;
////        while(wind.pollEvent(event)){
////            if (event.type == sf::Event::Closed){
////                wind.close();
////            }
////            if(event.type == sf::Event::KeyPressed){
////                if(event.key.code == sf::Keyboard::Space){
////                    phys.jumpPlayer(player);
////                }
////            }
////
////        }
////        view.setCenter(player.getLocation());
////        phys.accelerateByPlayer(player);
////        phys.accByGravity(player);
////        phys.applyPhysics(player);
////        phys.collisionDetection(player,map);
////        bckgSprt.setPosition(view.getCenter().x - 800, view.getCenter().y - 450);
////        wind.setView(view);
////        wind.clear(sf::Color::Cyan);
////        wind.draw(bckgSprt);
////        map.drawMap(wind);
////        wind.draw(player.getSprite());
////        wind.display();
////    }
////    delete  wall_texture;
////    delete background_text;
////    return 0;