#include<bits/stdc++.h>
using namespace std;

bool entered(vector<int> b , int a)// A function to check whether the position entered by user is already entered or not.
{
  bool present=false;
  for( int x: b)
  {
      if( x == a)
      {
          present = true;
          break;
      }
  }
  return present;
}

void printgame(char a[][3])// A function to print The game scenario after each step of the game when for easy user reference.
{
    cout<<endl;
    cout<<"Current Game Scenario:"<<endl;
    cout<<"       "<<a[0][0]<<"  "<<"|"<<"  "<<a[0][1]<<"  "<<"|"<<"  "<<a[0][2]<<endl;
    cout<<"      "<<"---------------"<<endl;
    cout<<"       "<<a[1][0]<<"  "<<"|"<<"  "<<a[1][1]<<"  "<<"|"<<"  "<<a[1][2]<<endl;
    cout<<"      "<<"---------------"<<endl;
    cout<<"       "<<a[2][0]<<"  "<<"|"<<"  "<<a[2][1]<<"  "<<"|"<<"  "<<a[2][2]<<endl;
}

bool win( char a[][3], char p1)// A function I use after every move to check whether any side has won the game or not.
{
    bool winr = false;
    if( a[0][0] == p1 && a[0][1]== p1 && a[0][2]==p1)
    {
        winr = true;
    }
    else if( a[1][0] == p1 && a[1][1]== p1 && a[1][2]==p1)
    {
        winr = true;
    }
    else if( a[2][0] == p1 && a[2][1]== p1 && a[2][2]==p1)
    {
        winr = true;
    }
    else if( a[0][0] == p1 && a[1][0]== p1 && a[2][0]==p1)
    {
        winr = true;
    }
    else  if( a[0][0] == p1 && a[1][1]== p1 && a[2][2]==p1)
    {
        winr = true;
    }
    else  if( a[0][2] == p1 && a[1][1]== p1 && a[2][0]==p1)
    {
        winr = true;
    }
    else  if( a[0][1] == p1 && a[1][1]== p1 && a[2][1]==p1)
    {
        winr = true;
    }
    else  if( a[0][2] == p1 && a[1][2]== p1 && a[2][2]==p1)
    {
        winr = true;
    }
    return winr;
}

int makemove(char a[][3],int i,int d2,vector<int> b,char p1,char p2)// A function to decide the computer's move in single player mode.
{
    int pos;
     if(  ((i == 1 && d2==1)|| (i==0 && d2 == 2)) && a[1][1] == '-')
     {
         pos = 5;
         return pos;
     }
     if( i==2 && d2==2 && a[0][0]==p1)
     {
         pos =3;
         return pos;
     }
     vector<int> s;
     for( int j=1;j<=9;j++)
     {
         if(!entered(b,j))
         {
             s.push_back(j);
         }

     }
     bool foundmove=false;
     for( int z : s)
     {
       a[(z-1)/3][(z-1)%3] = p2;
       if(win(a,p2)){pos = z; a[(z-1)/3][(z-1)%3]='-';foundmove = true;return pos;}
       a[(z-1)/3][(z-1)%3]= p1;
       if(win(a,p1)){pos = z; a[(z-1)/3][(z-1)%3]='-';foundmove =true;return pos;}
       else{a[(z-1)/3][(z-1)%3]='-';}
     }
     if(!foundmove)
     {
         pos = s[0];
     }

     return pos;
}

int main()
{
  char a[3][3]{'-','-','-','-','-','-','-','-','-'};// Declaring the game board.
  vector<int> b;                                    // Declaring the vector that contains entered positions so far in the current game.
  int pos;                                          // the variable that is always asked to the user
  char d;                                           // decision variable for multi/single player game
  char p2,p1;
  cout<<"!!!Welcome To Tic-Tac-Toe!!!!"<<endl;
again4 :                                            // To redirect from bad input message
      cout<<"How do you want to play?"<<endl<<"To go Multiplayer type m(small m)!!"<<endl;
      cout<<"To go Singleplayer type s(small s) !!!"<<endl;
      cin>>d;
      if( d == 'm'){ goto multiplayer;}
      else if( d == 's'){ goto singleplayer;}
      else { cout<<"Please enter valid choice!!!!"<<endl; goto again4;}


  multiplayer:
      cout<<"In this multi player game , Player 2 gets the chance to choose the character!!"<<endl;
      cout<<"But Player 1 gets the first chance!!"<<endl;
      again3:
         cout<<"So,Player 2 choose your character by typing x/O(small x and capital O)"<<endl;
         cin>>p2;
         if(p2=='x'){ p1 = 'O';}
         else if(p2=='O'){p1= 'x';}
         else{ cout<<"Please enter valid character."<<endl; goto again3;}
         cout<<"So, Player 2 got: "<<p2<<endl<<"and Player 1 got:"<<p1<<endl<<endl;

         for( int i=0; i<9; i++)
         {
              if( i %2==0)
              {
                  again:
                       printgame(a);
                       cout<<"The positions are marked as follows:"<<endl<<"1  2  3"<<endl;
                       cout<<"4  5  6"<<endl<<"7  8  9"<<endl<<"Player 1 ,please enter your Position"<<endl<<endl;
                       cin>>pos;
                       if( entered(b,pos))
                       {
                           cout<<"Position already entered!!"<<endl<<"Enter your Position again,Player 1!"<<endl<<endl;
                           goto again;
                       }
                         if( pos>9 || pos<1)
                       {
                           cout<<"Invalid position entered!!!!"<<endl<<"Position is valid from 1 to 9 only."<<endl;
                           cout<<"Enter your position again, Player 1!"<<endl<<endl;
                           goto again;
                       }
                       else
                       {
                           b.push_back(pos);
                            a[(pos-1)/3][(pos-1)%3]=p1;
                       }
                       if( win(a,p1))
                       {
                           printgame(a);
                           cout<<"Player 1 wins!!!"<<endl<<"Player 2 , Please don't be Sad !!"<<endl;
                           goto endi;
                       }
                       if(i == 8 &&!win(a,p1) && !win(a,p2))
                       {
                           printgame(a);
                           cout<<"Game Tied !!!"<<endl<<"Looks like you both are good rivals!!!!"<<endl;
                           goto endi;
                       }

              }
              else
              {
                   again2:
                           printgame(a);
                           cout<<"The positions are marked as follows:"<<endl<<"1  2  3"<<endl;
                           cout<<"4  5  6"<<endl<<"7  8  9"<<endl<<"Player 2 ,please enter your Position"<<endl<<endl;
                           cin>>pos;
                           if( entered(b,pos))
                           {
                               cout<<"Position already entered!!"<<endl<<"Enter your Position again,Player 2!"<<endl<<endl;
                               goto again2;
                           }
                           if( pos>9 || pos<1)
                           {
                               cout<<"Invalid position entered!!!!"<<endl<<"Position is valid from 1 to 9 only."<<endl;
                               cout<<"Enter your position again, Player 2!"<<endl<<endl;
                               goto again2;
                           }
                           else
                           {
                               b.push_back(pos);
                                a[(pos-1)/3][(pos-1)%3]=p2;
                           }
                           if( win ( a,p2))
                           {
                               printgame(a);
                               cout<<"Player 2 wins!!!"<<endl<<"Player 1 , Please don't be Sad !!"<<endl;
                               goto endi;
                           }

              }
       }


  singleplayer:
      int d2;
      cout<<"In this Single player game , You get the chance to choose the character!!"<<endl;
      cout<<"Also you get to choose your chance!!"<<endl;
  again7:
      cout<<"Type 1 for first chance or type 2 for second chance."<<endl;
      cin>>d2;
      if( d2!=1 && d2!=2){cout<<"Please type correct choice.";goto again7;}
      cout<<"Let's see if you can beat the Computer!!!!"<<endl;
      again5:
         cout<<"So, choose your character by typing x/O(small x and capital O)"<<endl;
         cin>>p1;
         if(p1=='x'){ p2 = 'O';}
         else if(p1=='O'){p2= 'x';}
         else{ cout<<"Please enter valid character."<<endl; goto again5;}
         cout<<"So, You got: "<<p1<<endl<<"and Computer got:"<<p2<<endl<<endl;
         for( int i=0; i<9; i++)
         {
                  if( (i+d2+1) %2==0)
                  {
                  again6:
                           printgame(a);
                           cout<<"The positions are marked as follows:"<<endl<<"1  2  3"<<endl;
                           cout<<"4  5  6"<<endl<<"7  8  9"<<endl<<"Player 1 ,please enter your Position"<<endl<<endl;
                           cin>>pos;
                           if( entered(b,pos))
                           {
                               cout<<"Position already entered!!"<<endl<<"Enter your Position again,Player 1!"<<endl<<endl;
                               goto again6;
                           }
                             if( pos>9 || pos<1)
                           {
                               cout<<"Invalid position entered!!!!"<<endl<<"Position is valid from 1 to 9 only."<<endl;
                               cout<<"Enter your position again, Player 1!"<<endl<<endl;
                               goto again6;
                           }
                           else
                           {
                               b.push_back(pos);
                                a[(pos-1)/3][(pos-1)%3]=p1;
                           }
                           if( win(a,p1))
                           {
                               printgame(a);
                               cout<<"Player 1 wins!!!"<<endl<<"Looks like you Defeated the computer!!!"<<endl;
                               goto endi;
                           }
                           if( i==8 && !win(a,p1) && !win(a,p2))
                           {
                               printgame(a);
                               cout<<"Game Tied!!"<<endl;
                               cout<<"Well played!!"<<endl;
                               goto endi;
                           }

                 }

                 else
                 {
                     pos = makemove(a,i,d2,b,p1,p2);
                     b.push_back(pos);
                     a[(pos-1)/3][(pos-1)%3]=p2;
                     cout<<"Computer thought to place at position "<<pos<<endl;
                      if( win(a,p2))
                           {
                               printgame(a);
                               cout<<"Computer  wins!!!"<<endl;
                               goto endi;
                           }
                      if( i==8 && !win(a,p1) && !win(a,p2))
                           {
                               printgame(a);
                               cout<<"Game Tied!!"<<endl;
                               cout<<"Well played!!"<<endl;
                               goto endi;
                           }

                }

          }

  endi:
      char d3;
      cout<<"Do you want to play again?"<<endl;
      cout<<"Type y (small y) to replay the game!!"<<endl;
      cout<<"Or Type any other character to exit!"<<endl;
      cin>>d3;
      if(d3 == 'y' || d3 == 'Y'){main();}
      else {cout<<"Bye!!"<<endl<<"Hope you enjoyed the game!!!!"<<endl; }
  return 0;
}