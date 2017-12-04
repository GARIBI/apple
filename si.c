#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <termio.h>

int getch(void)
{
    int ch;
    struct termios buf, save;
    tcgetattr(0,&save);
    buf = save;
    buf.c_lflag &= ~(ICANON|ECHO);
    buf.c_cc[VMIN] = 1;
    buf.c_cc[VTIME] = 0;
    tcsetattr(0, TCSAFLUSH, &buf);
    ch = getchar();
    tcsetattr(0, TCSAFLUSH, &save);
    return ch;
}

void gotoxy(int x, int y) 
{
    printf("\033[%d;%df",y,x);

    fflush(stdout);
}

void MenuPrint();
void Name();
void Infor();
void OX_game();
void buy_things();

struct shop
{
    char name[20];
    int money;
    int su; 
};

void gugu();
void menu_output();


//메뉴를 정의
#define menu1 "A4 paper"
#define menu2 "poketmon dall"
#define menu3 "24K GOLD pencel"
#define menu4 "nintendo"
#define menu5 "GTA game pack"
#define menu6 "double-deck bed"
#define menu7 "play station"
#define menu_end "8. END"

//해당 메뉴의 가격을 정의
#define M1 30
#define M2 5000
#define M3 10000
#define M4 40000
#define M5 50000
#define M6 300000
#define M7 500000


//메뉴의 최대 개수(구매완료 제외)
#define menumax 7


int game_score=0;

void start_game()
{//게임시작
    int select;
    system("clear");
    MenuPrint();    
    scanf("%d", &select);//메뉴 1.2.3.번 중 선택
    
    switch(select)                                                      
     {    
        case 1://1번 선택시
            system("clear");//창 깨끗하게
            Name();//Name 함수로 이동
            break;//끝
        case 2:/*2번 선택시*/
            system("clear");//창 깨끗하게
            printf("END THE GAME.\n");
            break;//종료
        case 3://3번 선택시
            system("clear");//창 깨끗하게
            { 
                int a;
                time_t   current_time;
                time( &current_time);

                printf( "%ld\n", current_time);
                puts(ctime( &current_time));
                printf("GO BACK: Put any number.\n");
                scanf("%d",&a);
                if (a = 1)
                {
                    start_game();
                }
                system("clear");
            }//case3 종료

        default://아무것도 아닐시
            break;//끝
    }//switch끝
}//strat_game함수 끝

int main(void)
{
    start_game();//게임시작
}

void MenuPrint()
{
    system("clear");
    gotoxy(25,2); printf("   ________________________\n");
    gotoxy(25,3); printf("  1  ____________________  1\n");
    gotoxy(25,4); printf("  l 1     ___     ___    1 1\n");
    gotoxy(25,5); printf("  1 1                    l 1 \n");
    gotoxy(25,6); printf("  1 1      o       o     l 1 \n");
    gotoxy(25,7); printf("  1 1                    1 1\n");
    gotoxy(25,8); printf("  1 1          U         1 1\n");
    gotoxy(25,9); printf("  1 1                    1 1 \n");
    gotoxy(25,10); printf("  1 1____________________1 1\n");
    gotoxy(25,11); printf("  l  _____________         1\n");
    gotoxy(17,12); printf("  ________l [_____________]    O   1________     \n");
    gotoxy(17,13); printf(" [________1    _                   1________]\n");
    gotoxy(25,14); printf("  l  _l 1_       (X)  __   1 \n");
    gotoxy(25,15); printf("  1 [_   _]        _ [__]  1    \n");
    gotoxy(25,16); printf("  l   1_1         [_]      1\n");
    gotoxy(25,17); printf("  1________________________1 \n");
    gotoxy(25,18); printf("      1 1               1 1         \n");
    gotoxy(25,19); printf("      l 1               1 1  \n");
    gotoxy(25,20); printf("      l 1               1 1 \n");
    gotoxy(25,21); printf("    __l 1             __1 1 \n");
    gotoxy(25,22); printf("   [____1            [____1 \n");
    gotoxy(25,23); printf("_______________MENU_______________\n");
    gotoxy(25,24); printf("    1   G a m e   S t a r t \n");
    gotoxy(25,25); printf("    2   E n d    G a m e  \n");
    gotoxy(25,26); printf("    3   C u r r e n t   T i m e \n");
    gotoxy(25,27); printf("___________________________________\n");
    }

void Name()
{
    int num;//
    printf("PUT YOUR NAME ON! : ");
    scanf("%d" , &num);
    system("clear");//창 깨끗하게
    Infor();//Infor함수로 이동
}
void Infor()
{
    char name[20];//이름변수
    int a;//시작,종료 입력 변수
    scanf("%s",name,sizeof(name));
    printf("%s! You have to play the game! I will give you money AS MUCH AS you got a SCORE! You can buy things with that money. GOOD LUCK!\n", name, name);
    printf("\n");
    printf("put 1 to start, put 2 to end.\n");
    scanf("%d", &a,sizeof(a));//1번 누르면 시작, 2번 누르면 종료

    switch(a)
    {
        case 1://1번 누를시
            system("clear");//창 깨끗하게
            OX_game();//OX_game함수로 이동
                break;//끝
        case 2://2번 누를시
            printf("END THE GAME.\n");
                break;//끝
    }
}

void OX_game()
{
    int num, answer;//입력변수,정답변수      
    srand(time(NULL));//랜덤함수 난수생성
   
    int i;

    printf("First game is OX game. Match up the FIVE random questions! 5 points per One question.\n");
    for(i=0;i<5;i++)
    {

        printf("(O=put 1, X=put 2!!)\n");
        printf("\n");
                                  
        switch(rand()%11)//11개의수 중 1개 랜덤으로 고름
        {
            case 0://랜덤수 0이 골라졌을때

                printf("An ASCII code is a method of expressing the symbols used by a person in a computer.\n");
                answer=1;//답은 1번
                scanf("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
                if(answer==num)//정답과 입력한 숫자가 일치할때
                {
                    printf("GOOD!\n");
                    game_score+=5;//게임점수 5점 증가
                }

            else//오답일 시 실패
                printf("WRONG!\n");
                break;
        case 1://랜덤수 1이 골라졌을때

            printf("'Float' data type and 'short' data type are 'real type'.\n");
            answer=2;//답은 1번
            scanf("%d",&num,sizeof(num));//1.2번중 답 선택해서 입력
            if(answer==num)//정답과 입력한 숫자가 일치할때
            {
                printf("GOOD!\n");
                game_score+=5;//게임점점수 5점 증가
            }
            else//오답일 시 실패
                printf("WRONG!('short' is 'integer data type'.)\n");
                break;
        case 2:

            printf("'a!=b' means if a and b are same, judge as 1, and if a and b are ditterent, judge as 0.\n");
            answer=1;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;
        case 3:

            printf("If the 'if-else' statement is nested, the 'else' matches the nearest 'if'.\n");
            answer=1;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;
        case 4:

            printf("A 'char' array with a maximum value of 4 subscripts is 'char ary[4]';.\n");
            answer=2;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!(declared as 'char ary[5]';)\n");
                break;
        case 5:

            printf("The order in which functions are written must be the same as the order in which they are called.\n");
            answer=2;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;

        case 6:

            printf("'Local variables' are used in preference to 'global variables' of the same name.\n");
            answer=1;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;

        case 7:

            printf("The parameter contains a garbage value if not initialized.\n");
            answer=2;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!(The parameter is populated when the function is called.)\n");
                break;

        case 8:

            printf("The value of array 'a[2]' declared 'int a[3]={1};' is 0.\n");
            answer=1;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;

        case 9:

            printf("'Pointer variables' can be used in exactly the same way as 'arrays'.\n");
            answer=1;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!\n");
                break;

        case 10:

            printf("Passing a 'large array' as a function argument takes a 'long time' to pass data.\n");
            answer=2;
            scanf("%d",&num,sizeof(num));
            if(answer==num)
            {
                printf("GOOD!\n");
                game_score+=5;
            }
            else
                printf("WRONG!(same time!)\n");
                break;

            case 11:
                
                printf("In 'int a[i]={0};', the array size 'i' uses only 'global variables'.\n");
                answer=2;
                scanf("%d",&num,sizeof(num));
                if(answer==num)
                {
                    printf("GOOD!\n");
                    game_score+=5;
                }   
                else
                    printf("WRONG!\n");
                    break;
        }
    }
    buy_things();
}

    void gugu()
    {
        //구조체를 초기화
        struct shop gujo[menumax]={
        {menu1, M1, 0},
        {menu2, M2, 0},
        {menu3, M3, 0},
        {menu4, M4, 0},
        {menu5, M5, 0},
        {menu6, M6, 0},
        {menu7, M7, 0}
        };
        int select, i, money_tot, real=0, my_money;
        double save_tot=0;
                       
        do{
            //수량과 금액 변수들을 다시 0으로 초기화
            for(i=0;i<menumax-1;i++)
                gujo[i].su=0;
                my_money=0;
                money_tot=0;
                //메뉴 출력함수
                menu_output();
                //상품과 수량을 고르는 반복문
            while(1)
            {
                printf("Please select the item you wish to purchase.(1-7) END is 8.\n");
                scanf("%d", &select);

                if(select==8)
                {
                    printf("\nyou ENDED!.\n");
                    break;
                }
                else if(select<1 || select>menumax)
                {
                    printf("\nwrong number!\n\n");
                    continue;
                }
                printf("you choose %s!\n", gujo[select-1].name);
                while(1)
                {
                    printf("How many? (1-10)");
                    scanf("%d", &gujo[select-1].su);

                    if(gujo[select-1].su<1 || gujo[select-1].su>10)   
                        printf("\nwrong number!\n\n");      
                    else
                        break;
                }
            }

            printf("\n-----TOTAL-----\n");
            //수량을 1개이상 선택했으면 선택사항을 출력해주는 반복문
            for(i=0;i<menumax-1;i++)
            {
                if(gujo[i].su==0) continue;
                    printf("%s = \\%d * %d = \\%d \n", gujo[i].name, gujo[i].money, gujo[i].su, gujo[i].money * gujo[i].su);
                    money_tot+=gujo[i].money * gujo[i].su;
            }  
            //총 합계금액을 출력
            printf("total = \\%d\n", money_tot);
            //낼 돈을 입력 받는다.
            do{
                if(money_tot==0) break; //하나도 안골랐을경우는 입력 받지 않고 반복문을 종료
                    printf("\nPut 'how much you pay': ");
                    scanf("%d", &my_money);
              }while(my_money<money_tot);
            //받은 금액과 거스름돈 출력
            printf("you pay : \\%d\n", my_money);
            printf("change : \\%d - \\%d = \\%d \n", my_money, money_tot, my_money-money_tot);
            //계속 쇼핑할지를 물어봄
            printf("Continue shopping? (1:continue, 0:end)");
            scanf("%d", &real);
            //1,0이 아니고 귀차나서 걍 0이면 종료 나머지는 쇼핑으로 했어여...
            }while(real);

            printf("\n----------------------------------------\n");
            printf("thak you~~~~~~~~~~~~~~\n");
            printf("----------------------------------------\n");  
    }

    void menu_output()
    {    
        puts("\n-------------------------------");
        printf("1. %s : \\%d\n", menu1, M1);
        printf("2. %s : \\%d\n", menu2, M2);
        printf("3. %s : \\%d\n", menu3, M3);
        printf("4. %s : \\%d\n", menu4, M4);
        printf("5. %s : \\%d\n", menu5, M5);
        printf("6. %s : \\%d\n", menu6, M6);
        printf("7. %s : \\%d\n", menu7, M7);
        puts(menu_end);
        puts("-------------------------------");
    }   

void buy_things()
{
    printf("\nyour score is %d\n",game_score);
    

    gugu();

}
