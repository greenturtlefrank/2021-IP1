// [HACKATHON 3-9]
// TODO: Create scene_settings.h and scene_settings.c.
// No need to do anything for this part. We've already done it for
// you, so this 2 files is like the default scene template.
#include "scene_menu_object.h"
#include "scene_settings.h"
#include "scene_game.h"
#include "scene_menu.h"
#include "utility.h"
#include "shared.h"

static ALLEGRO_BITMAP* gameTitle = NULL;
static ALLEGRO_SAMPLE_ID menuBGM;
static int gameTitleW;
static int gameTitleH;

int player = 1;

// Variables and functions with 'static' prefix at the top level of a
// source file is only accessible in that file ("file scope", also
// known as "internal linkage"). If other files has the same variable
// name, they'll be different variables.

/* Define your static vars / function prototypes below. */

// TODO: More variables and functions that will only be accessed
// inside this scene. They should all have the 'static' prefix.



static void draw_setset() {

	
	

	al_clear_to_color(al_map_rgb(0, 0, 0));

	
		
	

	

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameTitleW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameTitleH;

	extern int mapp;

	

	//draw title image
	/*
	al_draw_scaled_bitmap(
		gameTitle,
		0, 0,
		gameTitleW, gameTitleH,
		offset_w, offset_h,
		gameTitleW * scale, gameTitleH * scale,
		0
	);*/

	float ten = 1;
	float tenten = 1;
	char music[23] =  {'-', ' ', 'M', 'U', 'S', 'I', 'C', ' ', 'V', 'O', 'L', 'U', 'M', 'E', ' ', '+', ' ', ' ', ' ', ' ', '.', ' ', ' '};
	char effect[24] = {'-', ' ', 'E', 'F', 'F', 'E', 'C', 'T', ' ', 'V', 'O', 'L', 'U', 'M', 'E', ' ', '+', ' ', ' ', ' ', ' ', '.', ' ', ' '};

	for (int i = 22; i >= 18; i--)
	{
		music[i] = ((int)(music_volume * 100.0 / ten) % 10) + '0';
		ten *= 10;

		if (i == 21)
		{
			i--;
		}
	}
	for (int i = 23; i >= 19; i--)
	{
		effect[i] = ((int)(effect_volume * 100.0 / tenten) % 10) + '0';
		tenten *= 10;

		if (i == 22)
		{
			i--;
		}
	}

	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 - 60,
		ALLEGRO_ALIGN_CENTER,
		music
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 - 20,
		ALLEGRO_ALIGN_CENTER,
		effect
	);

	char oneone[24] = { 'P', 'L', 'A', 'Y', 'E', 'R', ':', ' ', 'O', 'N', 'E', ' ','P', 'L', 'A', 'Y', 'E', 'R' ,'\0'};
	char secsec[24] = { 'P', 'L', 'A', 'Y', 'E', 'R', ':', ' ', 'T', 'W', 'O', ' ','P', 'L', 'A', 'Y', 'E', 'R' ,'\0' };

	char mapone[14] = { 'M', 'A', 'P', ' ', ':', ' ', 'M', 'A', 'P', ' ', 'O', 'N', 'E', '\0' };
	char maptwo[14] = { 'M', 'A', 'P', ' ', ':', ' ', 'M', 'A', 'P', ' ', 'T', 'W', 'O', '\0' };

	/*
	if (player == 1)
	{
		al_draw_text(
			menuFont,
			al_map_rgb(255, 255, 0),
			SCREEN_W / 2,
			SCREEN_H / 2 + 80,
			ALLEGRO_ALIGN_CENTER,
			oneone
		);
	}
	else
	{
		al_draw_text(
			menuFont,
			al_map_rgb(255, 255, 0),
			SCREEN_W / 2,
			SCREEN_H / 2 + 80,
			ALLEGRO_ALIGN_CENTER,
			secsec
		);
	}*/

	if (mapp == 1)
	{
		al_draw_text(
			menuFont,
			al_map_rgb(255, 165, 0),
			SCREEN_W / 2,
			SCREEN_H / 2 + 80,
			ALLEGRO_ALIGN_CENTER,
			mapone
		);
	}
	else
	{
		al_draw_text(
			menuFont,
			al_map_rgb(255, 165, 0),
			SCREEN_W / 2,
			SCREEN_H / 2 + 80,
			ALLEGRO_ALIGN_CENTER,
			maptwo
		);
	}



	al_draw_text(
		BIGFont,
		al_map_rgb(30, 144, 255),
		SCREEN_W / 2,
		80,
		ALLEGRO_ALIGN_CENTER,
		"SETTING"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"ENTER\" BACK TO MENU"
	);



}

static void on_key_down_setset(int keycode) {

	extern int mapp;

	switch (keycode) {
	case ALLEGRO_KEY_RIGHT:
		if (effect_volume < 2.0)
		{
			effect_volume += 0.1;
		}
		break;
	case ALLEGRO_KEY_LEFT:
		if (effect_volume >= 0.1)
		{
			effect_volume -= 0.1;
		}
		break;
	case ALLEGRO_KEY_FULLSTOP:
		if (music_volume < 2.0)
		{
			music_volume += 0.1;
		}
		break;
	case ALLEGRO_KEY_COMMA:
		if (music_volume >= 0.1)
		{
			music_volume -= 0.1;
		}
		break;
	case ALLEGRO_KEY_1:
		mapp = 1;
		break;
	case ALLEGRO_KEY_2:
		mapp = 2;
		break;
	case ALLEGRO_KEY_ENTER:
		game_change_scene(scene_menu_create());
		break;
	default:
		break;
	}
}





static void init() {

	//btnSettings = button_create(730, 20, 50, 50, "Assets/settings.png", "Assets/settings2.png");

	//gameTitle = load_bitmap("Assets/title.png");
	//gameTitleW = al_get_bitmap_width(gameTitle);
	//gameTitleH = al_get_bitmap_height(gameTitle);
	stop_bgm(menuBGM);
	menuBGM = play_bgm(themeMusic, music_volume);

}


// The only function that is shared across files.


Scene scene_settings_create(void) {
	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Settings";
	scene.draw = &draw_setset;
	// TODO: Register more event callback functions such as keyboard, mouse, ...
	
	//scene.initialize = &init;
	//scene.destroy = &destroy;
	scene.on_key_down = &on_key_down_setset;
	//scene.on_mouse_move = &on_mouse_move;
	





	game_log("Settings scene created");





	return scene;
}