#include <stdio.h>
#include <stdlib.h>
#include <SDL2/SDL.h>

int main() {
    FILE *in = stdin;	
    char *pthroway = calloc(1000, sizeof(char));
    //Reads the first line
    fgets(pthroway, 1000, in);
    //Redas the second line
    fgets(pthroway, 1000, in);
   //Read the third line(Width and height)
        char *pdimensions = calloc(1000, sizeof(char));
        fgets(pdimensions, 1000, in);
	//Reads the fourth line
	fgets(pthroway,1000,in);
	free(pthroway);
	
	int width = -1;
	int height = -1;

        sscanf(pdimensions, "%d %d\n",&width,&height);
	free(pdimensions);
        printf("%d %d",width,height);
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    }

    SDL_Window *pwindow = SDL_CreateWindow(
        "Image viewer",
        SDL_WINDOWPOS_CENTERED,
        SDL_WINDOWPOS_CENTERED,
       width,
       height,
        0
    );

    if (!pwindow) {
        printf("SDL_CreateWindow Error: %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Surface *psurface = SDL_GetWindowSurface(pwindow);
    Uint32 color = 0;
    SDL_Rect pixel = (SDL_Rect){0,0,1,1};
    for(int y=0; y<height; y++){
          for(int x=0; x<width; x++){
          Uint8 r,g,b;
    r =(char) getchar();
    g =(char) getchar();
    b =(char) getchar();
    color =  SDL_MapRGB(psurface->format,r,g,b);		  
           pixel.x = x;
	   pixel.y = y;
	   SDL_FillRect(psurface, &pixel, color);  
	  }
    }
   SDL_UpdateWindowSurface(pwindow);
   int app_running = 1;
   while(app_running){
        SDL_Event event;
	while(SDL_PollEvent(&event)){
	     if(event.type == SDL_QUIT){
	         app_running = 0;
	     }
	}
	SDL_Delay(100);
   }
}

