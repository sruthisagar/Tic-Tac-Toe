#include <iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string>
#define Size 3
#include"conio2.h"

using namespace std;



class Player
{
    private:
        char symbol;
        char name[30];
        int color;
    public:
        void get_details();
        void display_details();
        char get_symbol();
        char *get_name();
        void set_color(int);
        int get_color();
        Player()
        {
        }
};

void Player::get_details()
{
    cin.sync();
    cout<<"\nName: ";
    gets(name);
    cout<<"Symbol: ";
    cin>>symbol;

}

void Player::display_details()
{
    cout<<"\nName: ";
    cout<<name;
    cout<<"\nSymbol: ";
    cout<<symbol <<endl;

}

char Player::get_symbol()
{
    return symbol;
}

char * Player::get_name()
{
    return name;
}

void Player::set_color(int c)
{
    color=c;
}

int Player::get_color()
{
    return color;
}

class Game
{
    private:
        Player player1, player2;
        char matrix[Size][Size];

    public:
        Game(Player p1,Player p2)
        {
            player1=p1;
            player2=p2;
            matrix_initialise();
        }
        void matrix_initialise();
        void display_matrix();
        int symbol_unique_check();
        int* box_number_to_index(char);
        int insert_symbol(char,char);
        int check_row();
        int check_column();
        int check_diagonals();
        int check_draw();
        int check_game_over();
        void start_game();

};

void Game::matrix_initialise()
{
    int element=1;
    for(int i=0;i<Size;i++)
        for(int j=0;j<Size;j++)
        {
            matrix[i][j]= '0' + element ;
            element++;
        }
}

void Game::display_matrix()
{
    //system("cls");

    for(int i=0;i<Size;i++)
    {
        for(int j=0;j<Size;j++)

        {
            if(matrix[i][j]==player1.get_symbol())
                textcolor(player1.get_color());
            else if(matrix[i][j]==player2.get_symbol())
                textcolor(player2.get_color());
            else
                textcolor(WHITE);
            cout<<matrix[i][j]<<"\t";
        }
        cout<<endl<<endl;
    }
}

int Game::symbol_unique_check()
{
    if(player1.get_symbol()==player2.get_symbol())
        return 0;
    return 1;
}

int* Game::box_number_to_index(char number)
{
    int arr[2] = {0};
    for(int i=0;i<Size;i++)
        for(int j=0;j<Size;j++)
        {
            if(matrix[i][j]==number)
            {
                arr[0]=i;
                arr[1]=j;
                return arr;
            }

        }
    arr[0]=-1;
    return arr;

}

int Game::insert_symbol(char number, char symbol)
{
    int*a=box_number_to_index(number);
    if(a[0]==-1){
        cout<<"\n\nInvalid Box Number\n";
        return -1;
    }

    int m=a[0];
    int n=a[1];
    matrix[m][n]=symbol;
    return 1;
}

int Game::check_row()
{
    for(int i=0;i<Size;i++)
    {
        int symbol1_count=0;
        int symbol2_count=0;
        for(int j=0;j<Size;j++)
        {
            if(matrix[i][j]==player1.get_symbol())
                symbol1_count++;
            if(matrix[i][j]==player2.get_symbol())
                symbol2_count++;
        }
        if(symbol1_count==Size)
            return 1;
        if(symbol2_count==Size)
            return 2;
    }
    return 0;
}

int Game::check_column()
{
     for(int i=0;i<Size;i++)
    {
        int symbol1_count=0;
        int symbol2_count=0;
        for(int j=0;j<Size;j++)
        {
            if(matrix[j][i]==player1.get_symbol())
                symbol1_count++;
            if(matrix[j][i]==player2.get_symbol())
                symbol2_count++;
        }
        if(symbol1_count==Size)
            return 1;
        if(symbol2_count==Size)
            return 2;
    }
    return 0;
}

int Game::check_diagonals()
{
    int symbol1_count=0;
    int symbol2_count=0;

    //diagonal1
    for(int i=0;i<Size;i++)
    {
        if(matrix[i][i]==player1.get_symbol())
            symbol1_count++;
        if(matrix[i][i]==player2.get_symbol())
            symbol2_count++;
    }
    if(symbol1_count==Size)
            return 1;
    if(symbol2_count==Size)
            return 2;
    //diagonal2

    symbol1_count=0;
    symbol2_count=0;


    for(int i=0;i<Size;i++)
    {
        if(matrix[i][Size-i-1]==player1.get_symbol())
            symbol1_count++;
        if(matrix[i][Size-i-1]==player2.get_symbol())
            symbol2_count++;
    }
    if(symbol1_count==Size)
            return 1;
    if(symbol2_count==Size)
            return 2;
    return 0;
}

int Game::check_draw()
{
    for(int i=0;i<Size;i++)
        for(int j=0;j<Size;j++)
        {
            if(matrix[i][j]!=player1.get_symbol()&&matrix[i][j]!=player2.get_symbol())
                return 0;
        }
    return 3;
}

int Game::check_game_over()
{
    int r;
    r=check_row();
    if(r==1||r==2)
        return r;
    r=check_column();
    if(r==1||r==2)
        return r;
    r=check_diagonals();
    if(r==1||r==2)
        return r;
    r=check_draw();
    if(r==3)
        return r;
    return 0;
}

void Game::start_game()
{
    char number;
    int u=symbol_unique_check();
    if(u==0)
    {
        cout<<"You idiots...Both of you can't have the same symbol!";
        return;
    }
    display_matrix();
    int currentplayer = 0; // 0 for player1 and 1 for player2
    while(true)
    {
        if(currentplayer == 0)
        {     //player 1
            textcolor(player1.get_color());
            cout<<"\nEnter box number "<<player1.get_name()<<": ";
            cin>>number;
            int i = insert_symbol(number,player1.get_symbol());

            if(i==-1)
            {
                continue;
            }
            else
            {
                currentplayer = !currentplayer;
                system("cls");
            }
            display_matrix();
            int g=check_game_over();
            textcolor(YELLOW);
            if(g==1)
            {
                cout<<player1.get_name()<<" won!\n\n\n";
                return;
            }
            if(g==2)
            {
                cout<<player2.get_name()<<" won!\n\n\n";
                return;
            }
            if(g==3)
            {
                cout<<"Draw!\n\n\n";
                return;
            }
        }
        else
        {    //player 2
            textcolor(player2.get_color());
            cout<<"\nEnter box number "<<player2.get_name()<<": ";
            cin>>number;
            int i = insert_symbol(number,player2.get_symbol());

            if(i==-1)
            {
                continue;
            }
            else
            {
                currentplayer = !currentplayer;
                system("cls");
            }
            display_matrix();
            int g=check_game_over();
            textcolor(YELLOW);
            if(g==1)
            {
                cout<<player1.get_name()<<" won!\n\n\n";
                return;
            }
            if(g==2)
            {
                cout<<player2.get_name()<<" won!\n\n\n";
                return;
            }
            if(g==3)
            {
                cout<<"Draw!\n\n\n";
                return;
            }
        }
    }
}


int main()
{
    Player p1,p2;

    p1.set_color(3);
    textcolor(p1.get_color());
    cout<<"PLAYER 1\n________\n";
    p1.get_details();

    p2.set_color(13);
    textcolor(p2.get_color());
    cout<<"\nPLAYER 2\n________\n";
    p2.get_details();
    system("cls");
    Game game(p1,p2);
    game.start_game();
    system("PAUSE");
    return 0;
}
