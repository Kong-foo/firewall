#include <ncurses.h>

struct Position {
int x;
int y;
} pos;

//move to line, make it bold, then move back
int linebold(int y, int x) {
int prevy, prevx;
getyx(curscr, prevy, prevx);
move(y, x);
attron(COLOR_PAIR(5)|A_BOLD);
move(prevy, prevx);
}

//move to line, make it not bold, then move back
int lineunbold(int y, int x) {
int prevy, prevx;
getyx(curscr, prevy, prevx);
move(y, x);
attroff(COLOR_PAIR(5)|A_BOLD);
move(prevy, prevx);
}

int main() {
int ch;
struct Position prevpos;
pos.x = 1;
pos.y = 1;
initscr();
raw();
keypad(stdscr, TRUE);
noecho();
while (ch != KEY_F(1)) {
mvprintw(0,0, "(1)\t192.168.1.1\tDNS\n");
mvprintw(1, 0, "(1)\t192.168.1.8\tDNS\n");
move(pos.y, pos.x);
ch = getch();			
if(ch == KEY_F(1)) printw("F1 Key pressed");
else if (ch == 258) pos.y++;
else if (ch == 259) pos.y--;
else if (ch == 261) pos.x++;
else if (ch == 260) pos.x--;
else{
printw("The pressed key is ");
attron(A_BOLD);
printw("%d", ch);
attroff(A_BOLD);
}
refresh();
prevpos.x = pos.x;
prevpos.y = pos.y;
//attroff(COLOR_PAIR(5)|A_BOLD);
}
getch();			
endwin();			

return 0;
}
