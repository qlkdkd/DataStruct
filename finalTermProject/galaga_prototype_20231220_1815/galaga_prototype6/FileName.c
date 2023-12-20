// �Ѽ����б� 2023 2�б� �ڷᱸ�� �⸻���� <���ð���-������>
// 2171358 �Ŵ��� && 2393084 ��λ�
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>
#include <mmsystem.h>
#pragma comment(lib, "winmm.lib")

#define ENEMY_NUM 3 //���� ��
#define PLAYER_START_X 25 //�÷��̾� ���� x
#define PLAYER_START_Y 40 //�÷��̾� ���� y
#define BULLET_NUM 4 //�÷��̾ ���ÿ� �߻� ������ �Ѿ� ��
#define ENEMY_BULLET_NUM (ENEMY_NUM * 5) //���� �߻� ������ �Ѿ� ��

#define MAX_X 48 // �̵������� x��ǥ�� �ִ� ����
#define MIN_X 2 // �̵������� x��ǥ�� �ּ� ���� 
#define MAX_Y 40 // �̵������� y��ǥ�� �ִ� ����
#define MIN_Y 2 // �̵������� y��ǥ�� �ּ� ���� 
#define CENTER_LINE 20 // �÷��̾�� �� ������ �̵� ���

void gotoxy(int x, int y);
void PrintGameTitle();
void start_menu();
void QuitGame();
void game_manual();
void gotoxy(int x, int y);
void print_player(int x, int y, bool exist);
void print_enemy(int x, int y, bool exist);
void print_bullet(int x, int y, bool exist);
void hide_cursor(int num);
void bullet_moving();
int checking_hit();
void enemy_rand_moving_();
void print_enemy_bullet(int x, int y, bool exist);
void enemy_rand_shooting();
void print_gameover();
void print_win();
void print_hsu();
int checking_game_end();
void update_score();//���� ǥ��

//ȿ���� �Լ�
void play_background_music();//���� ���
void play_shot_sound();



typedef struct bullet_state { //�Ѿ��� ���� ��ǥ�� �˷��ִ� ����ü
    int x;
    int y;
    bool exist;
} bullet_state;

typedef struct player_state { //�÷��̾��� ���� ���¸� �˷��ִ� ����ü
    int x;
    int y;
    int health;
    int speed;
    bool exist; //���� ����
} player_state;

typedef struct enemy_state { // ���� ���� ���¸� �˷��ִ� ����ü
    int x;
    int y;
    int health;
    int speed;
    bool exist; // ���� ����
} enemy_state;

int score = 0;//����
clock_t  lastScoreUpdateTime;

player_state player;
enemy_state enemy[ENEMY_NUM];
bullet_state bullet[BULLET_NUM];
bullet_state enemy_bullet[ENEMY_BULLET_NUM];

void StartGame() { //�� ���� �ڵ�
    printf("������ ���۵˴ϴ�!\n");
    PlaySound(TEXT("Enemy_Division.wav"), NULL, SND_FILENAME | SND_ASYNC);
    system("cls"); // �ܼ�â ����� ��ɾ�

    player.x = PLAYER_START_X; //�÷��̾� ���� �ʱ�ȭ
    player.y = PLAYER_START_Y;
    player.health = 0;
    player.speed = 0;
    player.exist = true;

    for (int i = 0; i < ENEMY_NUM; i++) { //�� ���� �ʱ�ȭ
        enemy[i].x = 5 + 15 * i;
        enemy[i].y = 1 + 3 * i;
        enemy[i].health = 0;
        enemy[i].speed = 0;
        enemy[i].exist = true;
    }

    lastScoreUpdateTime = clock();//������ ������ �ʱ�ȭ
    while (1) {
        print_player(player.x, player.y, player.exist); // �÷��̾� ���

        for (int i = 0; i < ENEMY_NUM; i++) { // �� ���
            print_enemy(enemy[i].x, enemy[i].y, enemy[i].exist);
        }

        int hit = checking_hit();
        bullet_moving(); // �Ѿ� �̵� ��Ű�� �Լ� �۵�
        if (checking_game_end() == 0) break; // ������ ���� ��Ȳ���� Ȯ���ϴ� �Լ�&���ǹ�
        enemy_rand_moving_(); // ���� �����ϰ� �̵���Ű�� �Լ�
        enemy_rand_shooting(); // ���� �����ϰ� �Ѿ��� ��� �Լ�

        // �÷��̾� �����¿� ����Ű�� �̵��ϰ� �ϴ� ���ǹ�
        if ((GetAsyncKeyState(VK_UP) & 0x0001) && (MIN_Y < player.y) && (player.y > CENTER_LINE)) {
            print_player(player.x, player.y, false);
            player.y--;
            print_player(player.x, player.y, true);
        }
        if ((GetAsyncKeyState(VK_DOWN) & 0x0001) && (MAX_Y > player.y)) {
            print_player(player.x, player.y, false);
            player.y++;
            print_player(player.x, player.y, true);
        }
        if ((GetAsyncKeyState(VK_RIGHT) & 0x0001) && (MAX_X > player.x)) {
            print_player(player.x, player.y, false);
            player.x++;
            print_player(player.x, player.y, true);
        }
        if ((GetAsyncKeyState(VK_LEFT) & 0x0001) && (MIN_X < player.x)) {
            print_player(player.x, player.y, false);
            player.x--;
            print_player(player.x, player.y, true);
        }

        //�����̽��� Ű�� �Ѿ� �߻��ϴ� ���ǹ�
        if (GetAsyncKeyState(VK_SPACE) & 0x0001) {
            int i = 0;
            while (i < BULLET_NUM && bullet[i].exist) { //��� �Ұ����� �Ѿ� �� ����ϴ� �ݺ���
                i++;
            }
            if (i != BULLET_NUM) {
                bullet[i].x = player.x;
                bullet[i].y = player.y + 2;
                bullet[i].exist = true;
                play_shot_sound();
            }
        }
        //0.1�ʸ��� 1���� �߰�
        clock_t currentTime = clock();
        double elapsedSeconds = (double)(currentTime - lastScoreUpdateTime) / CLOCKS_PER_SEC;
        if (elapsedSeconds >= 0.1) {
            score++;
            update_score();
            lastScoreUpdateTime = currentTime;
        }

        //�� ������ 100�� ȹ��
        if (hit) {
            score += 100;
        }
        update_score();

        gotoxy(0, 42);
        printf("HANSUNG UNIVERSITY DEPARTMENT OF APPLIED AI");

        Sleep(20); // 0.02�� �������� ȭ�� ������Ʈ
    }
    Sleep(5000); // 5�� ��� �� ���� �޴��� �Ѿ
}

void gotoxy(int x, int y) { //Ŀ���� Ư�� ��ǥ�� �̵���Ű�� �Լ�
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void print_player(int x, int y, bool exist) { // �÷��̾ ȭ�鿡 ����ϴ� �Լ�
    if (exist == true) {
        gotoxy(x-1, y); printf("��");
        gotoxy(x - 2, y + 1); printf("�ޡ��");
    }

    if (exist != true) {
        gotoxy(x, y); printf("   ");
        gotoxy(x - 2, y + 1); printf("         ");
    }
}

void print_enemy(int x, int y, bool exist) { // ���� ȭ�鿡 ����ϴ� �Լ�
    if (exist == true) {
        gotoxy(x - 2, y - 1); printf("�ߡ��");
        gotoxy(x-1, y); printf("��");
    }

    if (exist != true) {
        gotoxy(x - 2, y - 1); printf("      ");
        gotoxy(x, y); printf("   ");
    }
}

void print_bullet(int x, int y, bool exist) { // �÷��̾��� �Ѿ��� ȭ�鿡 ����ϴ� �Լ�
    if (exist == true) {
        gotoxy(x, y);
        printf("��");
    }

    if (exist != true) {
        gotoxy(x, y);
        printf("  ");
    }
}

void print_enemy_bullet(int x, int y, bool exist) { // ���� �Ѿ��� ȭ�鿡 ����ϴ� �Լ�
    if (exist == true) {
        gotoxy(x, y);
        printf("v");
    }

    if (exist != true) {
        gotoxy(x, y);
        printf("  ");
    }
}

void bullet_moving() { // �Ѿ� �̵���Ű�� �Լ�
    int i, j;
    //�÷��̾��� �Ѿ� �̵�
    for (i = 0; i < BULLET_NUM; i++) {
        print_bullet(bullet[i].x, bullet[i].y, false);
        if (bullet[i].y == 0) {
            bullet[i].exist = false;
        }
        else {
            bullet[i].y--;
            print_bullet(bullet[i].x, bullet[i].y, bullet[i].exist);
        }
    }

    //���� �Ѿ� �̵�
    for (j = 0; j < ENEMY_BULLET_NUM; j++) {
        print_enemy_bullet(enemy_bullet[j].x, enemy_bullet[j].y, false);
        if (enemy_bullet[j].y == 42) {
            enemy_bullet[j].exist = false;
        }
        else {
            enemy_bullet[j].y++;
            print_enemy_bullet(enemy_bullet[j].x, enemy_bullet[j].y, enemy_bullet[j].exist);
        }
    }
}

int checking_hit() { // �Ѿ� �ǰ� ���� ����ϴ� �Լ�
    int hit = 0;
    //���� �ǰ� ����
    int i = 0, j = 0, p = 0;
    for (i = 0; i < ENEMY_NUM; i++) {
        for (j = 0; j < BULLET_NUM; j++) {
            if ((bullet[j].x == enemy[i].x) && (bullet[j].y == enemy[i].y) && (bullet[j].exist == true) && (enemy[i].exist == true)) {
                PlaySound(TEXT("Hit_on_Zako.wav"), NULL, SND_FILENAME | SND_ASYNC);
                bullet[j].exist = false;
                enemy[i].exist = false;
                hit = 1;
            }
        }
    }

    //�÷��̾��� �ǰ� ����
    for (p = 0; p < ENEMY_BULLET_NUM; p++) {
        if ((p < ENEMY_BULLET_NUM) && (enemy_bullet[p].x == player.x) && (enemy_bullet[p].y == player.y) && (enemy_bullet[p].exist == true) && (player.exist == true)) {
            bullet[p].exist = false;
            player.exist = false;
        }
    }
    return hit;
}

void enemy_rand_moving_() { // ���� �������� �̵���Ű�� �Լ�
    srand((unsigned int)time(NULL));
    int rand_x, rand_y;
    int i = 0;

    for (i = 0; i < ENEMY_NUM; i++) {
        rand_x = (rand() % 3) - 1; // x = -1, 0, 1
        rand_y = (rand() % 3) - 1; // y = -1, 0, 1

        //�̵� ������ xy������ �ִ밪�� ���� �ʴ� ��쿡�� �̵��ϴ� ���ǹ�
        if (enemy[i].exist == true) {
            print_enemy(enemy[i].x, enemy[i].y, false);
            if (((enemy[i].x + rand_x) > MIN_X + 3) && ((enemy[i].x + rand_x) < MAX_X - 3)) {
                enemy[i].x += rand_x;
            }

            if (((enemy[i].y + rand_y) > MIN_Y + 3) && ((enemy[i].y + rand_y) < CENTER_LINE)) {
                enemy[i].y += rand_y;
            }
            print_enemy(enemy[i].x, enemy[i].y, enemy[i].exist);
        }
    }
}

void enemy_rand_shooting() { //���� �������� �Ѿ��� �߻��ϴ� �Լ�
    srand((unsigned int)time(NULL));
    int i = 0;
    int r_num;

    while (i < ENEMY_BULLET_NUM && enemy_bullet[i].exist) { //��� �Ұ����� �Ѿ� �� ����ϴ� �ݺ���
        i++;
    }
    if (i != ENEMY_BULLET_NUM) {
        while (i == 0) {
            r_num = rand() % ENEMY_NUM; //���� �ε����� �������� ����
            if (enemy[r_num].exist == true) {
                enemy_bullet[i].x = enemy[r_num].x;
                enemy_bullet[i].y = enemy[r_num].y - 2;
                enemy_bullet[i].exist = true;
                i--;
            }
        }
    }
}

void update_score() {
    gotoxy(0, 43);
    printf("Score: %d", score);
}


int checking_game_end() { // ������ ���� ��Ȳ���� Ȯ���ϴ� �Լ�
    if (player.exist != true) { //�÷��̾��� �й踦 Ȯ���ϴ� ���ǹ�
        system("cls"); // ȭ�� �����
        print_gameover(); // ���� ���� ȭ�� ���
        PlaySound(TEXT("Game_Over.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 0;
    }

    int i = 0;
    while (i < ENEMY_NUM && !enemy[i].exist) { //������ �� ���� ����ϴ� �ݺ���
        i++;
    }
    if (i == ENEMY_NUM) { //�÷��̾��� �¸��� Ȯ���ϴ� ���ǹ�
        system("cls"); // ȭ�� �����
        print_win(); // ���� �¸� ȭ�� ���
        PlaySound(TEXT("Game_Clear.wav"), NULL, SND_FILENAME | SND_ASYNC);
        return 0;
    }

    return 1;
}

void print_gameover() { // ���ӿ��� ȭ�� ����ϴ� �Լ� 
    int start_x, start_y, length;
    length = 26;

    start_x = (52 - length) / 2;
    start_y = 5;

    gotoxy(start_x, start_y);
    printf(" ###     #    #   #  #####");
    gotoxy(start_x, start_y + 1);
    printf("#   #   # #   #   #  #    ");
    gotoxy(start_x, start_y + 2);
    printf("#      #   #  ## ##  #    ");
    gotoxy(start_x, start_y + 3);
    printf("#      #   #  # # #  #### ");
    gotoxy(start_x, start_y + 4);
    printf("#  ##  #####  #   #  #    ");
    gotoxy(start_x, start_y + 5);
    printf("#   #  #   #  #   #  #    ");
    gotoxy(start_x, start_y + 6);
    printf(" ###   #   #  #   #  #####");

    gotoxy(start_x, start_y + 8);
    printf(" ###   #   #  #####  #### ");
    gotoxy(start_x, start_y + 9);
    printf("#   #  #   #  #      #   #");
    gotoxy(start_x, start_y + 10);
    printf("#   #  #   #  #      #   #");
    gotoxy(start_x, start_y + 11);
    printf("#   #   # #   ####   #### ");
    gotoxy(start_x, start_y + 12);
    printf("#   #   # #   #      # #  ");
    gotoxy(start_x, start_y + 13);
    printf("#   #   # #   #      #  # ");
    gotoxy(start_x, start_y + 14);
    printf(" ###     #    #####  #   #");
}

void print_win() { // �¸� ȭ�� ����ϴ� �Լ�
    int start_x, start_y, length;
    length = 19;

    start_x = (52 - length) / 2;
    start_y = 5;

    gotoxy(start_x, start_y);
    printf("#   #   ###   #   #");
    gotoxy(start_x, start_y + 1);
    printf("#   #  #   #  #   #");
    gotoxy(start_x, start_y + 2);
    printf(" # #   #   #  #   #");
    gotoxy(start_x, start_y + 3);
    printf("  #    #   #  #   #");
    gotoxy(start_x, start_y + 4);
    printf("  #    #   #  #   #");
    gotoxy(start_x, start_y + 5);
    printf("  #    #   #  #   #");
    gotoxy(start_x, start_y + 6);
    printf("  #     ###    ### ");

    gotoxy(start_x, start_y + 8);
    printf("#   #   ###   #   #");
    gotoxy(start_x, start_y + 9);
    printf("#   #    #    #   #");
    gotoxy(start_x, start_y + 10);
    printf("#   #    #    ##  #");
    gotoxy(start_x, start_y + 11);
    printf("# # #    #    # # #");
    gotoxy(start_x, start_y + 12);
    printf("# # #    #    #  ##");
    gotoxy(start_x, start_y + 13);
    printf("## ##    #    #   #");
    gotoxy(start_x, start_y + 14);
    printf("#   #   ###   #   #");
}

void print_hsu() { // HSU ����ϴ� �Լ�
    int start_x, start_y, length;
    length = 19;

    start_x = (52 - length) / 2;
    start_y = 5;

    gotoxy(start_x, start_y);
    printf("#   #   ###   #   #");
    gotoxy(start_x, start_y + 1);
    printf("#   #  #   #  #   #");
    gotoxy(start_x, start_y + 2);
    printf("#   #  #      #   #");
    gotoxy(start_x, start_y + 3);
    printf("#####   ###   #   #");
    gotoxy(start_x, start_y + 4);
    printf("#   #      #  #   #");
    gotoxy(start_x, start_y + 5);
    printf("#   #  #   #  #   #");
    gotoxy(start_x, start_y + 6);
    printf("#   #   ###    ### ");
}

void PrintGameTitle() { // Ÿ��Ʋ ����ϴ� �Լ�
    int title_x;

    title_x = (52 - 23) / 2;

    gotoxy(title_x, 5);
    printf("### ### #   ### ### ###");
    gotoxy(title_x, 6);
    printf("#   # # #   # # #   # #");
    gotoxy(title_x, 7);
    printf("# # ### #   ### # # ###");
    gotoxy(title_x, 8);
    printf("### # # ### # # ### # #");
}

void game_manual() {
    system("cls");
    print_hsu();
    int start_x, start_y, length;
    length = 36;

    start_x = (52 - length) / 2;
    start_y = 15;

    gotoxy(start_x, start_y);
    printf("�Ѽ� �������� ���۹��� �����ϰڽ��ϴ�.");
    gotoxy(start_x, start_y + 2);
    printf("�����¿� ����Ű�� ���ּ��� �����մϴ�.");
    gotoxy(start_x, start_y + 4);
    printf("�����̽��� ��ư���� �Ѿ��� �߻��մϴ�.");
    gotoxy(start_x, start_y + 6);
    printf("�� ���ּ��� ��� �����ϸ� �¸��մϴ�.");
    Sleep(5000);
}

void QuitGame() {
    printf("������ �����մϴ�.\n");
    exit(0);
}

void hide_cursor(int num) { //Ŀ�� ����� �Լ�
    CONSOLE_CURSOR_INFO console_cursor;
    HANDLE handle_console = GetStdHandle(STD_OUTPUT_HANDLE);

    console_cursor.bVisible = num;
    console_cursor.dwSize = 1;
    SetConsoleCursorInfo(handle_console, &console_cursor);
}

void play_background_music() {
    PlaySound(TEXT("Game_Start_Music.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void play_shot_sound() {
    PlaySound(TEXT("Shot.wav"), NULL, SND_FILENAME | SND_ASYNC);
}

void start_menu() { //���� �޴� ����ϴ� �Լ�
    int choice = 1;
    char key;
    int menuX, menuY;

    while (1) {
        system("cls");

        menuX = (52 - 12) / 2;
        menuY = (42 - 4) / 2;

        PrintGameTitle(); // ���� ���� ���

        gotoxy(menuX, menuY);
        printf("1. ���� ����");
        if (choice == 1) printf(" <--");
        gotoxy(menuX, menuY + 1);
        printf("2. ���� ���");
        if (choice == 2) printf(" <--");
        gotoxy(menuX, menuY + 2);
        printf("3. ����");
        if (choice == 3) printf(" <--");

        key = _getch();

        switch (key) {
        case 72:
            if (choice > 1) choice--;
            break;
        case 80:
            if (choice < 3) choice++;
            break;
        case 13:
            switch (choice) {
            case 1:
                StartGame();
                break;
            case 2:
                //printf("���� ���\n");
                game_manual();
                break;
            case 3:
                QuitGame();
                break;
            }
            break;
        }
    }
}

int main() {
    hide_cursor(0);
    system("cls");
    system("title 2023_Hansung_Galaga");
    system("mode con: cols=52 lines=43"); // 52�� 43�� 

    play_background_music();
    lastScoreUpdateTime = clock();
    start_menu();
    return 0;
}