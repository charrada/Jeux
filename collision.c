
#include <stdlib.h>
#include <stdio.h>
#include <SDL/SDL_image.h>
#include "SDL/SDL.h"
#include "collision.h"
Uint32 getpixel(SDL_Surface *collision, int X, int Y)
		{
		    int bpp = collision->format->BytesPerPixel;
		    	
		    Uint8 *p = (Uint8 *)collision->pixels + Y * collision->pitch + X * bpp;
		 
		    switch(bpp) 
                    {
		    case 1:
			return *p;
			break;
		 
		    case 2:
			return *(Uint16 *)p;
			break;
		 
		    case 3:
			if(SDL_BYTEORDER == SDL_BIG_ENDIAN)
			    return p[0] << 16 | p[1] << 8 | p[2];
			else
			    return p[0] | p[1] << 8 | p[2] << 16;
			break;
		 
		    case 4:
			return *(Uint32 *)p;
			break;
		 
		    default:
			return 0;       
		    }
		 }
		 



SDL_Surface *init_coll()
{
SDL_Surface *collision;
collision = IMG_Load("back1.png");
return (collision);
}

/* Au niveau de la fonction principale : 
	- On utilisie SDL_GetRGB(getpixel(collision, X+100, Y), collision->format, &r, &g, &bl);
	- Verifier puis r,g et bl :
		-Par exemple r+g+bl=0 : couleur noir ===> Obstacles.
		-            r=255,g=0,bl=0 : rouge ====> coin
			    etc ....
*/





















