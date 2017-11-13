#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
#include"shuntingyard.h"
#include"allconstants.h"

class Game
{
public:
    Game();
    void processEvents();

    void update();

    void Draw();
    void render();
    void run();
private:
    sf::RenderWindow _window;

    sf::VertexArray line;
    sf::VertexArray XCoor;
    sf::VertexArray YCoor;

    sf::View V;
};

Game::Game():line(sf::LinesStrip,10000),XCoor(sf::LinesStrip,2) , YCoor(sf::LinesStrip,2){
    _window.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT),"Graphng Calculator");

}

void Game::processEvents(){
    sf::Event event;
    while(_window.pollEvent(event)){
        switch(event.type){
             case sf::Event::Closed:
                        _window.close();
                        break;
             case sf::Event::KeyPressed:
                        if(event.key.code==sf::Keyboard::Escape)
                        {
                            _window.close();
                        }
                        if(event.key.code==sf::Keyboard::T){
                            V.zoom(1.1f);
                            V.setCenter(450,250);
                            _window.setView(V);
                        }
                        if(event.key.code==sf::Keyboard::R){
                            V.zoom(0.9f);
                            V.setCenter(450,250);
                            _window.setView(V);
                        }
                        break;
             case sf::Event::MouseMoved:
                        break;
             case sf::Event::MouseButtonPressed:
             case sf::Event::MouseButtonReleased:
                       cout<<"Click"<<endl;
                       break;
             default:
                    cout<<"Yo!"<<endl;
                    break;
        }
    }
}

void Game::update(){
     XCoor[0].position = sf::Vector2f(450, -10000);
     XCoor[1].position = sf::Vector2f(450, 10000);

     YCoor[0].position = sf::Vector2f(-10000, 250);
     YCoor[1].position = sf::Vector2f(10000, 250);

     double org_x = SCREEN_WIDTH/2;
     double org_y = SCREEN_HEIGHT/2;

     int pos = 0;
     for(int i = -5000; i<5000;i++){
         ShuntingYard func(myFunction,i);
         func.postFix();
         double Y = func.calculateIt();
         line[pos].position = sf::Vector2f(org_x + i,org_y - Y/Def);
         pos++;
     }
}

void Game::Draw(){
    _window.draw(XCoor);
    _window.draw(YCoor);
    _window.draw(line);
}

void Game::run(){
    while(_window.isOpen()){
        processEvents();
        update();
        render();
    }

}
void Game::render(){
    _window.clear();
    Draw();
    _window.display();
}

#endif // GAME_H
