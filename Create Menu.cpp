#include <Windows.h>
#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <SDL_image.h>
#include <SDL_mixer.h>
#undef main 
int ShowMenu(SDL_Surface* screen, TTF_Font* font)
{
	Uint32 time;
	int x, y;
	const int NUMMENU = 2;
	const char* labels[NUMMENU] = { "Start", "Option" };
	SDL_Surface* menu[NUMMENU];
	bool selected[NUMMENU] = { 0, 0 }; //Do chua chon option nao
	//Doi mau lua chon
	//Chon mau do khong chon mau trang
	SDL_Color color[2] = { {255,255,255}, {255, 0, 0} };

	menu[0] = TTF_RenderText_Solid(font, labels[0], color[0]); //Start 
	menu[1] = TTF_RenderText_Solid(font, labels[1], color[0]); //Option
	SDL_Rect pos[NUMMENU];
	//move to the center
	pos[0].x = screen->clip_rect.w / 2 - menu[0]->clip_rect.w / 2;
	pos[0].y = screen->clip_rect.h / 2 - menu[0]->clip_rect.h;
	pos[1].x = screen->clip_rect.w / 2 - menu[0]->clip_rect.w / 2;
	pos[1].y = screen->clip_rect.h / 2 + menu[0]->clip_rect.h;

	//fill screen with black 
	SDL_FillRect(screen, &screen->clip_rect, SDL_MapRGB(screen->format, 0x00, 0x00, 0x00));
	int i = ShowMenu(screen, font);
	SDL_Event event;
	while (1)
	{
		time = SDL_GetTicks();
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
			{
				for (int i = 0; i < NUMMENU; i++)
				{
					SDL_FreeSurface(menu[0]);
					SDL_FreeSurface(menu[1]);
					return 1;
				}
				break;
			}
			case SDL_MOUSEMOTION:
			{
				x = event.motion.x;
				y = event.motion.y;
				for (int i = 0; i < NUMMENU; i++)
				{
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && x <= pos[i].y + pos[i].h)
					{
						if (!selected[i])
						{
							selected[i] = 1;
							SDL_FreeSurface(menu[i]);
							menu[i] = TTF_RenderText_Solid(font, labels[i], color[1]);
						}
						else
						{
							if (selected[i])
							{
								selected[i] = 0;
								SDL_FreeSurface(menu[i]);
								menu[i] = TTF_RenderText_Solid(font, labels[i], color[0]);

							}
						}
					}
				}
				break;
			}
			case SDL_MOUSEBUTTONDOWN:
			{
				x = event.button.x;
				y = event.button.y;
				for (int i = 0; i < NUMMENU; i++)
				{
					if (x >= pos[i].x && x <= pos[i].x + pos[i].w && y >= pos[i].y && x <= pos[i].y + pos[i].h)
					{
						for (int j = 0; j < NUMMENU; j++)
						{
							SDL_FreeSurface(menu[i]);
						}
						return i;
					}
				}
				break;
			}
			case SDL_KEYDOWN:
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					for (int i = 0; i < NUMMENU; i++)
					{
						SDL_FreeSurface(menu[i]);
					}
				}
				return 0;
				break;
			}
			}
		}
		for (int i = 0; i < NUMMENU; i++)
		{
			SDL_BlitSurface(menu[i], NULL, screen, &pos[i]);
		}
		SDL_Flip(screen);
		if (1000 / 30 > SDL_GetTicks() - time)
		{
			SDL_Delay(1000 / 30 - (SDL_GetTicks() - time));
		}
	}
}