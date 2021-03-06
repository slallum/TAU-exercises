
#include "playit.h"

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

	if (on_cancel(window)) {
		return 1;
	}
	while (!quit) {

		quit = poll_event(window);
	}
	free_UI_tree(window);
	return 0;
}
