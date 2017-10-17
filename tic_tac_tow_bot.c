#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#define Play_Again printf("Wanna Play again(Y/N): "); \
    for(i = 0; i < 9; i++) \
            *(*be + i) = 0;   \
    scanf("%s", &choice); \
    if(choice == 'Y' || choice == 'y'){ \
       main(); }\
    else if(choice == 'n' || choice == 'N'){   \
    printf("Thank You For Playing!! Powered by www.Livethecodewith.me "); getch();}
#define clear_show system("cls"); show(board);
void show(char board[][3]){         //Function To show Tic Tac Toe Board
    printf("\n\n\n\n\t\t\t\t");
		printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
		printf("\t\t\t\t---|---|---\n\t\t\t\t");
		printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
		printf("\t\t\t\t---|---|---\n\t\t\t\t");
        printf(" %c | %c | %c\n\n\n", board[2][0], board[2][1], board[2][2]);
}
void score_board(char *name,int game_X, int game_O){
    printf("\n\n\n\t\t\t");
    printf("     Manish | %s\n", name);
    printf("\t\t\t\t----|-----\n");
    printf("\t\t\t %10d | %d\n", game_X, game_O);
    printf("\t\t\t\t----|-----\n\n\n");
}
int win(int be[][3]){           //Function to check the winning of user(O)
    int i;
    if((be[0][0] + be[1][1] + be[2][2] == 3 || be[0][2] + be[1][1] + be[2][0] == 3))
		   return 1;
		else{
			for(i = 0; i <=2; i++)
				if((be[i][0] + be[i][1] + be[i][2] == 3)|| (be[0][i] + be[1][i] + be[2][i] == 3))
					return 1;
        }
        return 0;
}
int check(char board[][3], int be[][3], int a){
//Function to check if there is occurence of 2 O's and also to input X on 3rd postion
// after O's.Also it checks the winning of 'X', If two X is found in single stream, it
//puts 3rd X on remaing one
    int i, j, sum1, sum2, k1, k2;
        for(i = 0; i < 3; i++){         //for horizontal and vertical
            sum1 = 0, sum2 = 0, k1 = -1, k2 = -1;
            for(j = 0; j < 3; j++){
                if(be[i][j] == 0)
                    k1 = j;
                if(be[j][i] == 0)
                    k2 = j;
                sum1 += be[i][j];
                sum2 += be[j][i];
            }
            if(sum1 == 2*a){
                board[i][k1] = 'X';
                be[i][k1] = 10;
                clear_show
                return 1;
            }
            if(sum2 == 2*a){
                board[k2][i] = 'X';
                be[k2][i] = 10;
                clear_show
                return 1;
            }
        }
        if(be[0][0] + be[1][1] + be[2][2] == 2*a){
            for(i = 0; i < 3; i++){
                if(be[i][i] == 0){
                    board[i][i] = 'X';
                    be[i][i] = 10;
                    clear_show
                    return 1;
                }
            }
        }
        if(be[0][2] + be[1][1] + be[2][0] == 2*a){
            for(i = 0; i < 3; i++){
                if(be[i][2-i] == 0){
                    board[i][2-i] = 'X';
                    be[i][2-i] = 10;
                    clear_show
                    return 1;
                }
            }
        }
        return 0;
}
int main(void){     //Main Funtion Starts
    char board [3][3] = { {'1','2','3'}, {'4','5','6'}, {'7','8','9'} }, choice, pos;
    static char name[20];
    int be[3][3]={0}, i, r = 0, x = 0, *ptr;
    static int total_game, game_O, game_X;
    if(!(total_game)){
        printf("Enter your name: ");
        scanf("%s", name);
        clear_show
    }
    total_game++;
    do{
        printf("Howdy, %s!!.You have O, I have X. Now Enter the postion: ", name);
        scanf("%c", &pos);              //first move of user
        clear_show
    }while(pos < 49 || pos > 57);
    pos = pos - 48;
    *(*board + pos - 1) = 'O';
    *(*be + pos - 1) = 1;           //end of first move of user
    if(*(*be + 4) == 0){        //first move of my
        *(*board + 4) = 'X';
        *(*be + 4) = 10;
        clear_show
    }
    else{
        ptr = (int*)malloc(4*sizeof(int));
        for(i = 0; i < 4; i++){
            ptr[i] = x;
            if(x == 2)
                x = x + 2;
            x = x + 2;
        }
        r = clock()%4;
        *(*(board) + ptr[r]) = 'X';
        *(*(be) + ptr[r]) = 10;
        show(board);
        clear_show
        free(ptr);
    }                                     //end of my first move
    for(i = 0; i <= 3; i++){
       do{
            printf("Your Turn Now, Enter the postion: ");
            scanf("%c", &pos);                         //Enter postion O from user
                clear_show
        }
        while(*(*be + pos - 48 - 1) == 10 || *(*be + pos - 48 - 1) == 1 || pos < 49 || pos > 57);
        pos = pos - 48;
           *(*board + pos - 1) = 'O';
           *(*be + pos - 1) = 1;
           clear_show                          //end processing of inputting postion
        if(win(be) == 1){                     //check winning of 'O' USER
            printf("%s is won!! ", name);
            game_O++;
            score_board(name, game_X, game_O);
            Play_Again
            clear_show
            return 0;
        }
        if(check(board, be, 10) == 1){          // Checking My winning 'X'
            printf("You Lose!! ");
            game_X++;
            score_board(name, game_X, game_O);
            Play_Again
            clear_show
            return 0;
        }
        if(check(board, be, 1) == 1)
            continue;
        else if(*(*be + pos - 1 - 1) == 0){         //random put of X
            *(*be + pos - 1 - 1) = 10;
            *(*board + pos - 1 - 1) = 'X';
            clear_show;
            continue;
        }
        else if(*(*(be - 1) + pos - 1) == 0){
            *(*(be - 1) + pos - 1) = 10;
            *(*(board - 1) + pos - 1) = 'X';
            clear_show;
            continue;
        }
        else if(*(*be + pos) == 0){
            *(*be + pos) = 10;
            *(*board + pos) = 'X';
            clear_show;
            continue;
        }
        else if(*(*(be + 1) + pos - 1) == 0){
            *(*(be + 1) + pos - 1) = 10;
            *(*(board + 1) + pos - 1) = 'X';
            clear_show;
            continue;
        }
        else{
            for(r = 0; r < 9; r++){
                if(*(*(be) + r - 1) == 0){
                    *(*(be) + r - 1) = 10;
                    *(*(board) + r - 1) = 'X';
                    break;
                    clear_show;
                }
            }
        }
    }
    printf("Match Draw!! ");
        score_board(name, game_X, game_O);
        Play_Again
        clear_show
        return 0;
}
