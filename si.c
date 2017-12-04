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


//�޴��� ����
#define menu1 "A4 paper"
#define menu2 "poketmon dall"
#define menu3 "24K GOLD pencel"
#define menu4 "nintendo"
#define menu5 "GTA game pack"
#define menu6 "double-deck bed"
#define menu7 "play station"
#define menu_end "8. END"

//�ش� �޴��� ������ ����
#define M1 30
#define M2 5000
#define M3 10000
#define M4 40000
#define M5 50000
#define M6 300000
#define M7 500000


//�޴��� �ִ� ����(���ſϷ� ����)
#define menumax 7


int game_score=0;

void start_game()
{//���ӽ���
    int select;
    system("clear");
    MenuPrint();    
    scanf("%d", &select);//�޴� 1.2.3.�� �� ����
    
    switch(select)                                                      
     {    
        case 1://1�� ���ý�
            system("clear");//â �����ϰ�
            Name();//Name �Լ��� �̵�
            break;//��
        case 2:/*2�� ���ý�*/
            system("clear");//â �����ϰ�
            printf("END THE GAME.\n");
            break;//����
        case 3://3�� ���ý�
            system("clear");//â �����ϰ�
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
            }//case3 ����

        default://�ƹ��͵� �ƴҽ�
            break;//��
    }//switch��
}//strat_game�Լ� ��

int main(void)
{
    start_game();//���ӽ���
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
    system("clear");//â �����ϰ�
    Infor();//Infor�Լ��� �̵�
}
void Infor()
{
    char name[20];//�̸�����
    int a;//����,���� �Է� ����
    scanf("%s",name,sizeof(name));
    printf("%s! You have to play the game! I will give you money AS MUCH AS you got a SCORE! You can buy things with that money. GOOD LUCK!\n", name, name);
    printf("\n");
    printf("put 1 to start, put 2 to end.\n");
    scanf("%d", &a,sizeof(a));//1�� ������ ����, 2�� ������ ����

    switch(a)
    {
        case 1://1�� ������
            system("clear");//â �����ϰ�
            OX_game();//OX_game�Լ��� �̵�
                break;//��
        case 2://2�� ������
            printf("END THE GAME.\n");
                break;//��
    }
}

void OX_game()
{
    int num, answer;//�Էº���,���亯��      
    srand(time(NULL));//�����Լ� ��������
   
    int i;

    printf("First game is OX game. Match up the FIVE random questions! 5 points per One question.\n");
    for(i=0;i<5;i++)
    {

        printf("(O=put 1, X=put 2!!)\n");
        printf("\n");
                                  
        switch(rand()%11)//11���Ǽ� �� 1�� �������� ��
        {
            case 0://������ 0�� ���������

                printf("An ASCII code is a method of expressing the symbols used by a person in a computer.\n");
                answer=1;//���� 1��
                scanf("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
                if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
                {
                    printf("GOOD!\n");
                    game_score+=5;//�������� 5�� ����
                }

            else//������ �� ����
                printf("WRONG!\n");
                break;
        case 1://������ 1�� ���������

            printf("'Float' data type and 'short' data type are 'real type'.\n");
            answer=2;//���� 1��
            scanf("%d",&num,sizeof(num));//1.2���� �� �����ؼ� �Է�
            if(answer==num)//����� �Է��� ���ڰ� ��ġ�Ҷ�
            {
                printf("GOOD!\n");
                game_score+=5;//���������� 5�� ����
            }
            else//������ �� ����
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
        //����ü�� �ʱ�ȭ
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
            //������ �ݾ� �������� �ٽ� 0���� �ʱ�ȭ
            for(i=0;i<menumax-1;i++)
                gujo[i].su=0;
                my_money=0;
                money_tot=0;
                //�޴� ����Լ�
                menu_output();
                //��ǰ�� ������ ���� �ݺ���
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
            //������ 1���̻� ���������� ���û����� ������ִ� �ݺ���
            for(i=0;i<menumax-1;i++)
            {
                if(gujo[i].su==0) continue;
                    printf("%s = \\%d * %d = \\%d \n", gujo[i].name, gujo[i].money, gujo[i].su, gujo[i].money * gujo[i].su);
                    money_tot+=gujo[i].money * gujo[i].su;
            }  
            //�� �հ�ݾ��� ���
            printf("total = \\%d\n", money_tot);
            //�� ���� �Է� �޴´�.
            do{
                if(money_tot==0) break; //�ϳ��� �Ȱ�������� �Է� ���� �ʰ� �ݺ����� ����
                    printf("\nPut 'how much you pay': ");
                    scanf("%d", &my_money);
              }while(my_money<money_tot);
            //���� �ݾװ� �Ž����� ���
            printf("you pay : \\%d\n", my_money);
            printf("change : \\%d - \\%d = \\%d \n", my_money, money_tot, my_money-money_tot);
            //��� ���������� ���
            printf("Continue shopping? (1:continue, 0:end)");
            scanf("%d", &real);
            //1,0�� �ƴϰ� �������� �� 0�̸� ���� �������� �������� �߾...
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
