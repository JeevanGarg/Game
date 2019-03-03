#include<iostream>
using namespace std;

char a[3][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'}};
char turn= 'X';
int row,column;
bool draw=false;

void disp()
{
	system("cls");
	cout<<"\n\n  Tic Tac Toe Game"<<endl;
	cout<<"\tPlayer1 [X] \n\tPlayer2 [O]\n\n";
	
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<a[0][0]<<"  |  "<<a[0][1]<<"  |  "<<a[0][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<a[1][0]<<"  |  "<<a[1][1]<<"  |  "<<a[1][2]<<"  \n";
	cout<<"\t\t_____|_____|_____\n";
	cout<<"\t\t     |     |     \n";
	cout<<"\t\t  "<<a[2][0]<<"  |  "<<a[2][1]<<"  |  "<<a[2][2]<<"  \n";
	cout<<"\t\t     |     |     \n";
	
	
}
void player_turn()
{
	int choice;
	if(turn=='X')
	cout<<"\n\tPlayer1 [X] turn:";
	if(turn=='O')
	cout<<"\n\tPlayer2 [O] turn:";
	cin>>choice;
	switch(choice)
	{
		case 1:
		    row=0;column=0; break;
			break;
		
		case 2:
			row=0;column=1; break;
			break;
		
		case 3:
			row=0;column=2; break;
			break;
			
		case 4:
			row=1;column=0; break;
			break;
		
		case 5:
			row=1;column=1; break;
			break;
		
		case 6:
			row=1;column=2; break;
			break;
			
		case 7:
			row=2;column=0; break;
			break;
			
		case 8:
			row=2;column=1; break;
			break;
		case 9:
			row=2;column=2; break;
			break;
			
		default:
			cout<<"Invalid choice";
			break;
	}
	if(turn=='X' && a[row][column]!='X' && a[row][column]!='O')
	{
		a[row][column]='X';
		turn='O';
	}
	else if(turn=='O' && a[row][column]!='X' && a[row][column]!='O')
	{
		a[row][column]='O';
		turn='X';
	}
	else
	{
		cout<<"BOX already filled!\n Please try again";
		player_turn();
	}
}
bool gameover()
{//check who's win

	for(int i=0;i<3;i++)
	{
		if(a[i][0]==a[i][1] && a[i][0]==a[i][2] || a[0][i]==a[1][i] && a[0][i]==a[2][i])
		{
			return false;
		}
	}
	
if(a[0][0]==a[1][1] && a[0][0]==a[2][2] || a[0][2]==a[1][1] && a[0][2]==a[2][0])
{
	return false;
}
//check if there any empty box
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(a[i][j]!='X' && a[i][j]!='O')
			{
				return true;
			}
		}
	}

//draw game	
draw=true;
return false;
}
int main()
{
	while(gameover())
	{
	disp();
	player_turn();
	disp();	
	gameover();
	}
	
	if(turn=='X' && draw==false)
	{
		cout<<"Player2 [O] Wins!! Congratulations\n";
	}
	else if(turn=='O' && draw==false)
	{
		cout<<"Player1 [X] Wins!! Congratulations\n";
	}
	else
	{
		cout<<"GAME DRAW!! \n";
	}
	
}
