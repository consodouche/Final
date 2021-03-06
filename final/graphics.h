#ifndef GRAPHICS_H
#define GRAPHICS_H
#include <SDL2/SDL.h>  //include the image library
#include <string>
#include "bird.h"
#include "pipes.h"
using namespace std;
class graphics {
	private:
		int SCREEN_HEIGHT;
		int colorcount; //keeps track of the score-bar colors
		int colorcount1; //keeps track of the score-bar colors
		int colorcount2; //keeps track of the score-bar colors
		int SCREEN_WIDTH;
		SDL_Window* gWindow; // the graphics window
		SDL_Surface* gScreenSurface; //The screen surface
		SDL_Surface* whichSurface[12]; //array of five different surfaces which might be loaded
		SDL_Surface* birdA[8]; //array of five different surfaces which might be loaded
		SDL_Surface* background;
		SDL_Renderer* gRenderer;
		SDL_Event e; //for quitting etc	public:
		bool michaelscott; //press m to find out!
		int score; //how many pipes have been passed
		bool QUIT1;  //force quit
		bool ufo; //to go into UFO mode
		bool Invisible;  //these variables have fun effects ;)
		bool invincible; 
		int highscore;
		int currentscore;
		int newpipe; //integer that keeps track of how far the pipe has moved
	public:
		graphics(int = 450, int = 350); //constructor which sets the screen height and width
		~graphics();
		void findscore();
		bird jack;
		pipes bar;
		void init(); //initializes window etc, return boolean
		void loadMedia(); //takes an image and loads it
		SDL_Surface* loadSurface(string path);
		void blitSurface(SDL_Surface*); //blits the background image
		void animate();
		void blitbird(int, int, int); //takes length and width and draws bird		
		void blitground(int);
		void checkCrash(int); // sees if the bird has crashed
		void menu(); //displays the menu
		void initialFreeze();
		void drawSky(); //draw the top rectangle
		void drawPipes(); //draws the pipes, takes which pipe 
		void lose();
		void QUIT(); //quits
		void UFO(); //turns on UFO mode
		void off(); //turns cheats off
		void newhighscore();  //if new highscore is set
		void addscore(); //adds point every time bird passes pipe
		void drawscore(); //draws tallys on bottom of screen for score
};
#endif
