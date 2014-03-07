
#include "PlayIt.h"

/**
 * Here it all begins...
 */
int main() {
	return start_game_console();
}

/**
 * Opens the game console's main page, asking user to select:
 * New Game \ Load Game \ Quit
 *
 * Creates both main panel and game selection panel.
 */
int start_game_console() {
	Control* window;
	int quit = 0;
	if (!init_fw()) {
		return 1;
	}
	window = create_window(NULL);
	if (window == NULL) {
		return 1;
	}
	if (!show_start_screen(window)) {
		return 1;
	}

	while (!quit) {
		// Poll for keyboard & mouse events
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
				case (SDL_QUIT):
					quit = 1;
					break;
			}
		}
	}
	free_tree(window);
	return 0;
}
