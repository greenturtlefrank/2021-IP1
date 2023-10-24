#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <allegro5/allegro.h>
#include <allegro5/allegro_image.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_native_dialog.h>
#include <math.h>
#include "scene_menu_object.h"
#include "scene_settings.h"
#include "scene_game.h"
#include "scene_menu.h"
#include "utility.h"
#include "shared.h"

/* Internal Variables*/
static ALLEGRO_BITMAP* gameTitle = NULL;
static ALLEGRO_SAMPLE_ID menuBGM;
static int gameTitleW ;
static int gameTitleH ;


// [HACKATHON 3]
// TARGET : use a clickable button to enter setting scene.
// For `Button` struct(object) is defined in `scene_menu_object.h` and `scene_menu_object.c`
// STRONGLY recommend you trace both of them first. 

//	[HACKATHON 3-1]
//	TODO: Declare variable for button
//	Uncomment and fill the code below
static Button btnSettings;

static void init() {

	// [HACKATHON 3-2]
	// TODO: Create button to settings
	//	Uncomment and fill the code below
	btnSettings = button_create(730, 20, 50, 50, "Assets/settings.png", "Assets/settings2.png");

	gameTitle = load_bitmap("Assets/title.png");
	gameTitleW = al_get_bitmap_width(gameTitle);
	gameTitleH = al_get_bitmap_height(gameTitle);
	stop_bgm(menuBGM);
	menuBGM = play_bgm(themeMusic, music_volume);

}


static void draw() {

	al_clear_to_color(al_map_rgb(0, 0, 0));

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameTitleW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameTitleH;

	//draw title image
	al_draw_scaled_bitmap(
		gameTitle,
		0, 0,
		gameTitleW, gameTitleH,
		offset_w, offset_h,
		gameTitleW * scale, gameTitleH * scale,
		0
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W/2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"ENTER\""
	);

		// [HACKATHON 3-3]
		// TODO: Draw button
		// Uncomment and fill the code below
		drawButton(btnSettings);

}

static void on_mouse_move(int a, int mouse_x, int mouse_y, int f) {
	//	[HACKATHON 3-7]
	//	TODO: Update button's status(hovered), and utilize the function `pnt_in_rect`, which you just implemented
	//	Uncomment and fill the code below
		btnSettings.hovered = pnt_in_rect(mouse_x, mouse_y, btnSettings.body);
	//  btnSettings.hovered = buttonHover(btnSettings, mouse_x, mouse_y);
}


//	[HACKATHON 3-8]
//	TODO: When btnSettings clicked, switch to settings scene
//	Uncomment and fill the code below

static void on_mouse_down() {
	
	if (btnSettings.hovered)
		game_change_scene(scene_settings_create());
		
}


static void destroy() {
	stop_bgm(menuBGM);
	al_destroy_bitmap(gameTitle);
	//	[HACKATHON 3-10]
	//	TODO: Destroy button images
	//	Uncomment and fill the code below
	
	al_destroy_bitmap(btnSettings.default_img);
	al_destroy_bitmap(btnSettings.hovered_img);
	
}

static void on_key_down(int keycode) {

	extern int mapp;

	switch (keycode) {
		case ALLEGRO_KEY_ENTER:
			//mapp = 1;
			game_change_scene(scene_main_create());
			break;
		default:
			break;
	}
}

// TODO: Add more event callback functions such as update, ...

//gameover gameover gameover gameover gameover gameover gameover gameover gameover gameover gameover gameover gameover gameover 


extern int mapp;
extern int a;
int high[11] = { '0', '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0',  '0'};

static void draw_gameover() {

	al_clear_to_color(al_map_rgb(0, 0, 0));

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameTitleW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameTitleH;

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

	extern int game_main_Score;
	

	high[mapp] = high[mapp] > game_main_Score ? high[mapp] : game_main_Score;

	int ten = 1;
	int tenn = 1;
	char happy[22] = { 'Y', 'O', 'U', 'R', ' ', 'P', 'O', 'I', 'N', 'T', ' ', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
	char highh[22] = { 'B', 'E', 'S', 'T', ' ', 'P', 'O', 'I', 'N', 'T', ' ', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };

	for (int i = 20; i >= 11; i--)
	{
		happy[i] = ((game_main_Score / ten) % 10) + '0';
		ten *= 10;
	}

	//game_log("%d\n", high);

	for (int i = 20; i >= 11; i--)
	{
		highh[i] = ((high[mapp] / tenn) % 10) + '0';
		tenn *= 10;
	}

	for (int j = 0; j < 9; j++)
	{
		//game_log("%d %c\n", j, highh[j]);
	}
	

	al_draw_text(
		BIGFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 - 250,
		ALLEGRO_ALIGN_CENTER,
		"GAME OVER"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(0, 255, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 + 20,
		ALLEGRO_ALIGN_CENTER,
		happy
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 0, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 - 20,
		ALLEGRO_ALIGN_CENTER,
		highh
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"ENTER\""
	);

	

}

static void on_key_down_gameover(int keycode) {

	switch (keycode) {
	case ALLEGRO_KEY_ENTER:
		a = 0;
		game_change_scene(scene_menu_create());
		break;
	default:
		break;
	}
}

static void destroy_gameover() {
	stop_bgm(menuBGM);
	//al_destroy_bitmap(gameTitle);
	//	[HACKATHON 3-10]
	//	TODO: Destroy button images
	//	Uncomment and fill the code below

	//al_destroy_bitmap(btnSettings.default_img);
	//al_destroy_bitmap(btnSettings.hovered_img);

}

//win win win win win win win win win win win win win win win win win win win win win win win win win win win win win win win win win win 

static void init_win() {

	// [HACKATHON 3-2]
	// TODO: Create button to settings
	//	Uncomment and fill the code below
	//btnSettings = button_create(730, 20, 50, 50, "Assets/settings.png", "Assets/settings2.png");

	//gameTitle = load_bitmap("Assets/title.png");
	//gameTitleW = al_get_bitmap_width(gameTitle);
	//gameTitleH = al_get_bitmap_height(gameTitle);
	stop_bgm(menuBGM);
	menuBGM = play_bgm(HAPPY, music_volume);

}

int winwin = 0;
int i = 0;
int j = 0;
int k = 0;

static void draw_win() {

	winwin++;

	int n = rand() % 256;

	if (winwin % 3 == 0)
	{
		i += n;
	}
	else if (winwin % 3 == 1)
	{
		j += n;
	}
	else if (winwin % 3 == 2)
	{
		k += n;
	}

	
	if (i > 255)
	{
		i = 0;
	}

	if (j > 255)
	{
		j = 0;
	}

	if (k > 255)
	{
		k = 0;
	}
	

	
	al_rest(0.000001);
	al_clear_to_color(al_map_rgb(i, j, k));
			

	

	const float scale = 0.7;
	const float offset_w = (SCREEN_W >> 1) - 0.5 * scale * gameTitleW;
	const float offset_h = (SCREEN_H >> 1) - 0.5 * scale * gameTitleH;

	extern int game_main_Score;

	high[mapp] = high[mapp] > game_main_Score ? high[mapp] : game_main_Score;

	int ten = 1;
	int tenn = 1;
	char happy[22] = { 'Y', 'O', 'U', 'R', ' ', 'P', 'O', 'I', 'N', 'T', ' ', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
	char highh[22] = { 'B', 'E', 'S', 'T', ' ', 'P', 'O', 'I', 'N', 'T', ' ', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };

	for (int i = 20; i >= 11; i--)
	{
		happy[i] = ((game_main_Score / ten) % 10) + '0';
		ten *= 10;
	}

	//game_log("%d\n", high);

	for (int i = 20; i >= 11; i--)
	{
		highh[i] = ((high[mapp] / tenn) % 10) + '0';
		tenn *= 10;
	}


	al_draw_text(
		BIGFont,
		al_map_rgb(255, 255, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 - 200,
		ALLEGRO_ALIGN_CENTER,
		"HAPPY WIN"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(0, 255, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 + 20,
		ALLEGRO_ALIGN_CENTER,
		happy
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 0, 0),
		SCREEN_W / 2,
		SCREEN_H / 2 - 20,
		ALLEGRO_ALIGN_CENTER,
		highh
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 150,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"ENTER\" TO NEXT MAP"
	);
	al_draw_text(
		menuFont,
		al_map_rgb(255, 255, 255),
		SCREEN_W / 2,
		SCREEN_H - 110,
		ALLEGRO_ALIGN_CENTER,
		"PRESS \"WHITE\" TO BACK MENU"
	);



}


static void on_key_down_win(int keycode) {

	extern int mapp;
	a = 0;

	switch (keycode) {
	case ALLEGRO_KEY_SPACE:
		game_change_scene(scene_menu_create());
		break;
	case ALLEGRO_KEY_ENTER:
		mapp++;
		if (mapp > 2)
		{
			mapp = 1;
		}
		game_change_scene(scene_main_create());
		break;
	default:
		break;
	}
}

static void destroy_win() {
	stop_bgm(menuBGM);
	//al_destroy_bitmap(gameTitle);

}



// Functions without 'static', 'extern' prefixes is just a normal
// function, they can be accessed by other files using 'extern'.
// Define your normal function prototypes below.

// The only function that is shared across files.
Scene scene_menu_create(void) {

	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Menu";
	scene.initialize = &init;
	scene.draw = &draw;
	scene.destroy = &destroy;
	scene.on_key_down = &on_key_down;
	scene.on_mouse_move = &on_mouse_move;
	// [HACKATHON 3-9]
	// TODO: Register on_mouse_down.
	// Uncomment the code below.
	scene.on_mouse_down = &on_mouse_down;
	// TODO: Register more event callback functions such as keyboard, mouse, ...

	game_log("Menu scene created");
	return scene;
}

Scene scene_gameover_create(void) {

	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "Gameover";
	//scene.initialize = &init;
	scene.draw = &draw_gameover;
	scene.destroy = &destroy_gameover;
	scene.on_key_down = &on_key_down_gameover;
	//scene.on_mouse_move = &on_mouse_move;
	
	//scene.on_mouse_down = &on_mouse_down;
	

	game_log("Gameover scene created");
	return scene;
}

Scene scene_win_create(void) {

	Scene scene;
	memset(&scene, 0, sizeof(Scene));
	scene.name = "win";
	scene.initialize = &init_win;
	scene.draw = &draw_win;
	scene.destroy = &destroy_win;
	scene.on_key_down = &on_key_down_win;
	//scene.on_mouse_move = &on_mouse_move;

	//scene.on_mouse_down = &on_mouse_down;


	game_log("win scene created");
	return scene;
}