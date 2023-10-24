// [shared.c]
// you should define the shared variable declared in the header here.

#include "shared.h"
#include "utility.h"
#include "game.h"
// #include "scene_menu.h"

ALLEGRO_FONT* font_pirulen_32;
ALLEGRO_FONT* font_pirulen_24;
ALLEGRO_SAMPLE* themeMusic = NULL;
ALLEGRO_SAMPLE* PACMAN_POWER_SOUND = NULL;
ALLEGRO_SAMPLE* PACMAN_EAT = NULL;
ALLEGRO_SAMPLE* DIE = NULL;
ALLEGRO_SAMPLE* HAPPY = NULL;
ALLEGRO_SAMPLE* PACMAN_MOVESOUND = NULL;
ALLEGRO_SAMPLE* PACMAN_DEATH_SOUND = NULL;
ALLEGRO_FONT* menuFont = NULL;
ALLEGRO_FONT* BIGFont = NULL;

int fontSize = 30;
int Bigfontsize = 60;
float music_volume = 0.5;
float effect_volume = 0.5;
bool gameDone = false;

/*
	A way to accelerate is load assets once.
	And delete them at the end.
	This method does provide you better management of memory.
	
*/
void shared_init(void) {
	
	menuFont = load_font("Assets/Minecraft.ttf", fontSize);
	BIGFont = load_font("Assets/Minecraft.ttf", Bigfontsize);
	themeMusic = load_audio("Assets/Music/original_theme.ogg");
	PACMAN_POWER_SOUND = load_audio("Assets/Music/pacman_intermission1.ogg");
	PACMAN_EAT = load_audio("Assets/Music/pacman_death.ogg");
	DIE = load_audio("Assets/Music/pacman_intermission1.ogg");
	HAPPY = load_audio("Assets/Music/happy.ogg");
	PACMAN_MOVESOUND = load_audio("Assets/Music/pacman-chomp.ogg");
	PACMAN_DEATH_SOUND = load_audio("Assets/Music/pacman_death.ogg");
}

void shared_destroy(void) {

	al_destroy_font(menuFont);
	al_destroy_font(BIGFont);
	al_destroy_sample(themeMusic);
	al_destroy_sample(DIE);
	al_destroy_sample(PACMAN_EAT);
	al_destroy_sample(HAPPY);
	al_destroy_sample(PACMAN_MOVESOUND);
	al_destroy_sample(PACMAN_POWER_SOUND);
	al_destroy_sample(PACMAN_DEATH_SOUND);
}