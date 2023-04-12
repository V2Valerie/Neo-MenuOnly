#include <ncurses.h>

int main()
{

    // initialize ncurses
    initscr();
    cbreak();
    noecho();
    keypad(stdscr, true);

    // Create a new window
    WINDOW* win = newwin(42, 80, 1, 1);
    WINDOW* win2 = newwin(3, 8, 5, 10);
    WINDOW* win3 = newwin(3, 8, 5, 20);
    WINDOW* win4 = newwin(3, 8, 5, 30);
    WINDOW* win5 = newwin(3, 8, 5, 40);
    WINDOW* win6 = newwin(3, 8, 5, 50);
    WINDOW* win7 = newwin(3, 8, 5, 60);

    // Set the initial cursor position in the first box
    int cur_x = 10;
    int cur_y = 11;

    // Draw a box in the window
    box(win, 0, 0);
    box(win2, 0, 0);
    box(win3, 0, 0);
    box(win4, 0, 0);
    box(win5, 0, 0);
    box(win6, 0, 0);
    box(win7, 0, 0);

    // Text for boxes
    mvwprintw(win, 2, 37, "Neo");
    mvwprintw(win2, 1, 3, "1");
    mvwprintw(win3, 1, 3, "2");
    mvwprintw(win4, 1, 3, "3");
    mvwprintw(win5, 1, 3, "4");
    mvwprintw(win6, 1, 3, "5");
    mvwprintw(win7, 1, 3, "6");

    // Refresh the screen
    refresh();
    wrefresh(win);
    wrefresh(win2);
    wrefresh(win3);
    wrefresh(win4);
    wrefresh(win5);
    wrefresh(win6);
    wrefresh(win7);

    // Loop until the user hits 'q'
    bool running = true;
    while (running)
    {
        // Move the cursor to its current position
        wmove(win2, cur_y, cur_x);
        wmove(win3, cur_y, cur_x);
        wmove(win4, cur_y, cur_x);
        wmove(win5, cur_y, cur_x);
        wmove(win6, cur_y, cur_x);
        wmove(win7, cur_y, cur_x);

        // Wait for user input
        int ch = getch();

        // Handle arrow keys to move the cursor
        switch (ch)
        {
            case '1':
                if (cur_y > 11) cur_y--;
                wrefresh(win2);
                break;
            case '2':
                if (cur_y < 14) cur_y++;
                wrefresh(win3);
                break;
            case '3':
                if (cur_x > 12) cur_x--;
                wrefresh(win4);
                break;
            case '4':
                if (cur_x < 46) cur_x++;
                wrefresh(win5);
                break;
            case '5':
                if (cur_x < 46) cur_x++;
                wrefresh(win6);
                break;
            case '6':
                if (cur_x < 46) cur_x++;
                wrefresh(win7);
                break;
            case 'q':
                running = false;
                break;
        }
    }

    // Clean up
    delwin(win2);
    delwin(win3);
    delwin(win4);
    delwin(win5);
    delwin(win6);
    delwin(win7);
    endwin();

    return 0;
}