#include<bits/stdc++.h>
using namespace std;
void startup();
char convert(int number,char A,char B);
void showboard(int matrix[8][8],char A,char B);
bool moveupright(int matrix[8][8],int x,int y);
bool moveupleft(int matrix[8][8],int x,int y);
bool movedownright(int matrix[8][8],int x,int y);
bool movedownleft(int matrix[8][8],int x,int y);
bool elimination1(int matrix[8][8],int x,int y);
bool elimination2(int matrix[8][8],int x,int y);
bool check1(int matrix[8][8]);
bool check2(int matrix[8][8]);
void eliminate(int matrix[8][8],int x,int y);
bool checkKing(int matrix[8][8],int x,int y);
bool kingmove(int matrix[8][8],int x,int y,int move);
bool moveupright_king(int matrix[8][8],int x,int y);
bool moveupleft_king(int matrix[8][8],int x,int y);
bool movedownright_king(int matrix[8][8],int x,int y);
bool movedownleft_king(int matrix[8][8],int x,int y);
bool winner1(int matrix[8][8]);
bool winner2(int matrix[8][8]);
void king_eliminate(int matrix[8][8],int x,int y);
int main()
{
bool turn =0;
int move;
int matrix[8][8] = {1,0,1,0,1,0,1,0,
                    0,1,0,1,0,1,0,1,
                    1,0,1,0,1,0,1,0,
                    0,0,0,0,0,0,0,0,
                    0,0,0,0,0,0,0,0,
                    0,2,0,2,0,2,0,2,
                    2,0,2,0,2,0,2,0,
                    0,2,0,2,0,2,0,2};
                    
char A,B;
int x,y;
startup();
cout<<"Choose player 1 piece : "<<endl;
cin>>B;
cout<<"Choose player 2 piece : "<<endl;
cin>>A;               
showboard(matrix,A,B);
cout<<endl;
while(A!=' '|| B!=' ')
{
	if(turn==0)
	{
		cout<<endl;
		cout<<"player 1 turn:\n";
		if (check1(matrix))
		{
			cout<<"you have to eliminate your opponent piece!\n";
			cout<<"Which square? "<<endl;
			cout<<"in format(row column)"<<endl;
			cin>>x>>y;
			if(matrix[x][y]==1 || matrix[x][y]==4 )
			{
				cout<<"choose your own piece!\n";
				continue;
			}
			else if (matrix[x][y]==0)
			{
				cout<<"You don't have a piece there";
				continue;
			}
			else if ( (x<0 && x>7)||(y<0 && y>7) )
			{
				cout<<"this coordination in incorect!\ntry again.\n";
				continue;
			}
			if (elimination1(matrix,x,y)==false)
			{
				cout<<"you have to choose a piece that can eliminate your opponent piece!\n";
				continue;
			}
			//zadan ba king
			if(checkKing(matrix , x,y))
			{
				if (elimination1(matrix,x,y))
				{
					king_eliminate(matrix,x,y);
					showboard(matrix,A,B);
				}
			}
			//zadan mohre addi
			else
			{
				 if (elimination1(matrix,x,y))
				{
					eliminate(matrix,x,y);
					showboard(matrix,A,B);
				}
			}
			
			turn=1;
		}
		else
		{
			cout<<"Which square? "<<endl;
			cout<<"in format(row column)"<<endl;
			cin>>x>>y;
			if(matrix[x][y]==1 || matrix[x][y]==4)
			{
					cout<<"choose your own piece!\n";
					continue;
			}
			else if (matrix[x][y]==0)
			{
				cout<<"You don't have a piece there";
				continue;
			}
			else if ( (x<0 && x>7)||(y<0 && y>7) )
			{
				cout<<"this coordination in incorect!\ntry again.\n";
				continue;
			}
		    if (checkKing(matrix,x,y))
			{
				if(kingmove(matrix,x,y,move))
					showboard(matrix,A,B);
				else
					continue;
			}
			else
			{
				cout<<"( 1-Move up right   2-Move up left ) :"<<endl;
				cin>>move;
				if(move==1)
				{
					if(moveupright(matrix,x,y))
					showboard(matrix,A,B);
					else 
					continue;
				}
				else if(move==2)
				{
					if(moveupleft(matrix,x,y))
					showboard(matrix,A,B);
					else 
					continue;
				}
				else
				{ 
					cout<<"Invalid move ";
					cout<<endl;
					continue;
				}
			}
		
		
		turn=1;
		}
		
	}
	else if(turn==1)
	{
		cout<<endl;
		cout<<"player 2 turn:\n";
		if (check2(matrix))
		{
			cout<<"you have to eliminate your opponent piece!\n";
			cout<<"Which square? "<<endl;
			cout<<"in format(row column)"<<endl;
			cin>>x>>y;
			if(matrix[x][y]==2 || matrix[x][y]==3)
			{
				cout<<"choose your own piece!\n";
				continue;
			}
			else if (matrix[x][y]==0)
			{
				cout<<"You don't have a piece there";
				continue;
			}
			else if ( (x<0 && x>7)||(y<0 && y>7) )
			{
				cout<<"this coordination in incorect!\ntry again.\n";
				continue;
			}
			if (elimination2(matrix,x,y)==false)
			{
				cout<<"you have to choose a piece that can eliminate your opponent piece!\n";
				continue;
			}
			//zadan ba king
			if(checkKing(matrix , x,y))
			{
				 if (elimination2(matrix,x,y))
				{
					king_eliminate(matrix,x,y);
					showboard(matrix,A,B);
				}
			}
			//zadan mohre addi
			else
			{
				 if (elimination2(matrix,x,y))
				{
					eliminate(matrix,x,y);
					showboard(matrix,A,B);	
				}
			}
			
			turn=0;
		}
		else
		{
			cout<<endl<<"Which square? "<<endl;
			cout<<"in format(row column)"<<endl;
			cin>>x>>y;
			if(matrix[x][y]==2 || matrix[x][y]==3)
			{
				cout<<"choose your own piece!";
				continue;
			}
			else if (matrix[x][y]==0)
			{
				cout<<"You don't have a piece there";
				continue;
			}
			else if ( (x<0 && x>7)||(y<0 && y>7) )
			{
				cout<<"this coordination in incorect!\ntry again.\n";
				continue;
			}
			if (checkKing(matrix,x,y))
			{
				if(kingmove(matrix,x,y,move))
					showboard(matrix,A,B);
				else
				continue;
			}
			else
			{
				cout<<"( 1-Move Down Right   2-Move Down Left ) :\n";
				cin>>move;
				if(move==1)
				{
					if(movedownright(matrix,x,y))
					showboard(matrix,A,B);
					else 
					continue;
				}
				else if(move==2)
				{
					if(movedownleft(matrix,x,y))
					showboard(matrix,A,B);
					else
					continue;
				}
				else
				{ 
					cout<<"Invalid move ";
					cout<<endl;
					continue;
				}
		    }
			turn =0;	
		}
		
	}
	
if(winner2(matrix))
{
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"\n******************  WINNER : PLAYER 1  ************************"<<endl;
	cout<<"****************  Thank you for playing  **********************"<<endl;
	cout<<endl;
	return 0;
}

else if(winner1(matrix))
{	
	cout<<endl<<endl<<endl<<endl<<endl;
	cout<<"\n******************  WINNER : PLAYER 2  ************************"<<endl;
	cout<<"****************  Thank you for playing  **********************"<<endl;
	cout<<endl;
	return 0;
}
	
}




}

//-----------------------------------------Functions--------------------------------------------------------
void startup()
{
cout<<"=============================WELCOME TO CHECKERS============================="<<endl;
cout<<"                           By Mohammad Amir & Sina\n";
cout<<"==========================*************************=========================="<<endl<<endl<<endl<<endl;
}

void showboard(int matrix[8][8],char A,char B)
{
          cout <<  "  |----|----|----|----|----|----|----|----|" << endl;
 int z=0;
    for(int i=0;i<8;i++)
    {
    	cout<<z<<" ";
        for(int j=0;j<8;j++)
        {
            cout<< "| " << convert(matrix[i][j],A,B) << "  ";
        }
        z++;
 
        cout<<  "|" << endl << "  |----|----|----|----|----|----|----|----|" << endl;
    }
    cout<<"    0    1    2    3    4    5    6    7";
}
   
char convert(int number,char A,char B)
{
    switch(number)
    {
        case 0  :   return(' ');
                    break;
        case 1  :   return(A);
                    break;
        case 2  :   return(B);
                    break;
        case 3  :   return('K');
                    break;
        case 4  :   return('Q');
                    break;
        default :   return('!');
    }
}
bool moveupright(int matrix[8][8],int x,int y)
	{
		
		if(matrix[x-1][y+1]==0 && x>=2 && y<=6)
		{
		matrix[x-1][y+1]=2;
		matrix[x][y]=0;
		return true;
		}
		else if (matrix[x-1][y+1]==0 && x==1 && y<=6)
		{
			matrix[x-1][y+1]=3;
			matrix[x][y]=0;
			return true;
		}
		else if(matrix[x-1][y+1]!=0 && x>=1 && y<=6)
		{
			cout<<"There is already a piece ! \n";
			return false;
		}
		else if(x<1 || y>6)
		{
			cout<<"it is out of range!\n";
			return false;
		}
			
	}
bool moveupleft(int matrix[8][8],int x,int y)
	{
		
		if(matrix[x-1][y-1]==0 && x>=2 && y>=1)
		{
			matrix[x-1][y-1]=2;
			matrix[x][y]=0;
				return true;
		}
		else if(matrix[x-1][y-1]==0 && x==1 && y>=1)
		{
			matrix[x-1][y-1]=3;
			matrix[x][y]=0;
				return true;
		}
		else if(matrix[x-1][y-1]!=0 && x>=1 && y>=1)
		{
			cout<<"There is already a piece ! ";
			return false;
		}	
		else if(x<1 || y<1)
		{
			cout<<"it is out of range!\n";
			return false;
		}
	
	}
	
bool movedownright(int matrix[8][8],int x,int y)
	{
		
		
		if(matrix[x+1][y+1]==0 && x<=5 && y<=6)
		{
			matrix[x+1][y+1]=1;
			matrix[x][y]=0;
			return true;
		}
		else if(matrix[x+1][y+1]==0 && x==6 && y<=6)
		{
			matrix[x+1][y+1]=4;
			matrix[x][y]=0;
			return true;
		}
		else if(matrix[x+1][y+1]!=0 && x<=6 && y<=6)
		{
			cout<<"There is already a piece ! ";
			return false;
		}
		else if (x>6 || y>6)
		{
			cout<<"it is out of range!\n";
			return false;
		}	
	}
	
bool movedownleft(int matrix[8][8],int x,int y)
	{
		
		if(matrix[x+1][y-1]==0 && x<=5 && y>=1)
		{
			matrix[x+1][y-1]=1;
			matrix[x][y]=0;
			return true;
		}
		else if(matrix[x+1][y-1]==0 && x==6 && y>=1)
		{
			matrix[x+1][y-1]=4;
			matrix[x][y]=0;
			return true;
		}
		else if(matrix[x+1][y-1]!=0 && x<=6 && y>=1)
		{
			cout<<"There is already a piece ! ";
			return false;
		}
		else if (x>6 || y<1)	
		{
			cout<<"it is out of range!\n";
			return false;
		}
	}
	
bool elimination1(int matrix[8][8],int x,int y)	
{
	if (matrix[x][y]==2)
	{
		if((matrix[x-1][y+1]==1&&matrix[x-2][y+2]==0&&x>=2&&y<=5)||(matrix[x-1][y-1]==1&&matrix[x-2][y-2]==0&&x>=2&&y>=2))
			return true;
		if((matrix[x-1][y+1]==4&&matrix[x-2][y+2]==0&&x>=2&&y<=5)||(matrix[x-1][y-1]==4&&matrix[x-2][y-2]==0&&x>=2&&y>=2))
			return true;
		else	
			return false;
	}
	else if (matrix[x][y]==3)
	{
		if((matrix[x-1][y+1]==1&&matrix[x-2][y+2]==0&&x>=2&&y<=5)||(matrix[x-1][y-1]==1&&matrix[x-2][y-2]==0&&x>=2&&y>=2))
			return true;
		if((matrix[x-1][y+1]==4&&matrix[x-2][y+2]==0&&x>=2&&y<=5)||(matrix[x-1][y-1]==4&&matrix[x-2][y-2]==0&&x>=2&&y>=2))
			return true;
		if((matrix[x+1][y+1]==1&&matrix[x+2][y+2]==0&&x<=5&&y<=5)||(matrix[x+1][y-1]==1&&matrix[x+2][y-2]==0&&x<=5&&y>=2))
			return true;	
		if((matrix[x+1][y+1]==4&&matrix[x+2][y+2]==0&&x<=5&&y<=5)||(matrix[x+1][y-1]==4&&matrix[x+2][y-2]==0&&x<=5&&y>=2))
			return true;
		else
			return false;
	}
}
bool elimination2(int matrix[8][8],int x,int y)	
{
	if (matrix[x][y]==1)
	{
		if((matrix[x+1][y+1]==2&&matrix[x+2][y+2]==0&&x<=5&&y<=5)||(matrix[x+1][y-1]==2&&matrix[x+2][y-2]==0&&x<=5&&y>=2))
			return true;	
		if((matrix[x+1][y+1]==3&&matrix[x+2][y+2]==0&&x<=5&&y<=5)||(matrix[x+1][y-1]==3&&matrix[x+2][y-2]==0&&x<=5&&y>=2))
			return true;
		else
			return false;
	}
	else if(matrix[x][y]==4)
	{
		if((matrix[x-1][y+1]==2&&matrix[x-2][y+2]==0&&x>=2&&y<=5)||(matrix[x-1][y-1]==2&&matrix[x-2][y-2]==0&&x>=2&&y>=2))
			return true;
		if((matrix[x-1][y+1]==3&&matrix[x-2][y+2]==0&&x>=2&&y<=5)||(matrix[x-1][y-1]==3&&matrix[x-2][y-2]==0&&x>=2&&y>=2))
			return true;
		if((matrix[x+1][y+1]==2&&matrix[x+2][y+2]==0&&x<=5&&y<=5)||(matrix[x+1][y-1]==2&&matrix[x+2][y-2]==0&&x<=5&&y>=2))
			return true;	
		if((matrix[x+1][y+1]==3&&matrix[x+2][y+2]==0&&x<=5&&y<=5)||(matrix[x+1][y-1]==3&&matrix[x+2][y-2]==0&&x<=5&&y>=2))
			return true;
		else
			return false;
	}
 
}
bool check1(int matrix[8][8])
{
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
		{
			if (elimination1(matrix,i,j) && matrix[i][j]==2)
			return true;
			else if(elimination1(matrix,i,j) && matrix[i][j]==3)
			return true;
		}
	return false;
}
bool check2(int matrix[8][8])
{
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
		{
			if (elimination2(matrix,i,j) && matrix[i][j]==1)
			return true;
			else if(elimination2(matrix,i,j) && matrix[i][j]==4)
			return true;
		}
	return false;
}
void eliminate(int matrix[8][8],int x,int y)
{
	if(matrix[x][y]==2 )
	{
		if((matrix[x-1][y+1]==1 || matrix[x-1][y+1]==4) && matrix[x-2][y+2]==0 && ((matrix[x-1][y-1]!=1 && matrix[x-1][y-1]!=4) || matrix[x-2][y-2]!=0))
		{
			if (x==2)
			{
				matrix[x][y]=0;
				matrix[x-1][y+1]=0;
				matrix[x-2][y+2]=3;
			}
			else if(matrix[x][y]==2 && x!=2)
			{
				matrix[x][y]=0;
				matrix[x-1][y+1]=0;
				matrix[x-2][y+2]=2;
			}
		
			if(elimination1(matrix,x-2,y+2))
			eliminate(matrix,x-2,y+2);		
		}
	
		else if((matrix[x-1][y-1]==4 || matrix[x-1][y-1]==1) && matrix[x-2][y-2]==0 && ((matrix[x-1][y+1]!=1 && matrix[x-1][y+1]!=4) || matrix[x-2][y+2]!=0))
		{
			if (x==2)
			{
				matrix[x][y]=0;
				matrix[x-1][y-1]=0;
				matrix[x-2][y-2]=3;
			}
			else if(matrix[x][y]==2 && x!=2)
			{
				matrix[x][y]=0;
				matrix[x-1][y-1]=0;
				matrix[x-2][y-2]=2;
			}
		
			if(elimination1(matrix,x-2,y-2))
			eliminate(matrix,x-2,y-2);	
		}
		else if ((matrix[x-1][y+1]==1 || matrix[x-1][y+1]==4) && matrix[x-2][y+2]==0 && (matrix[x-1][y-1]==1 || matrix[x-1][y-1]==4) && matrix[x-2][y-2]==0)	
		{
			int choose;
			cout<<"choose which one do you want to eliminate(choose a number):\n1-left or 2-right?\n";
			cin>>choose;
			if (choose==1)
			{
				if (x==2)
				{
					matrix[x][y]=0;
					matrix[x-1][y-1]=0;
					matrix[x-2][y-2]=3;
				}
				else if(matrix[x][y]==2 && x!=2)
				{
					matrix[x][y]=0;
					matrix[x-1][y-1]=0;
					matrix[x-2][y-2]=2;
				}		
			
				if(elimination1(matrix,x-2,y-2))
				eliminate(matrix,x-2,y-2);
			}
			else if (choose == 2)
			{
				if (x==2)
				{
					matrix[x][y]=0;
					matrix[x-1][y+1]=0;
					matrix[x-2][y+2]=3;
				}
				else if(matrix[x][y]==2 && x!=2)
				{
					matrix[x][y]=0;
					matrix[x-1][y+1]=0;
					matrix[x-2][y+2]=2;
				}
			
				if(elimination1(matrix,x-2,y+2))
				eliminate(matrix,x-2,y+2);	
			}
			else
			{
				cout<<"you have to choose between 1 and 2!\n";
				eliminate(matrix,x,y);
			}
		}
	}
	//*************************************************
	else if(matrix[x][y]==1  )
	{
		if((matrix[x+1][y+1]==3 || matrix[x+1][y+1]==2) && matrix[x+2][y+2]==0 && ((matrix[x+1][y-1]!=2 && matrix[x+1][y-1]!=3)  || matrix[x+2][y-2]!=0))
		{
			if (x==5)
			{
				matrix[x][y]=0;	
				matrix[x+1][y+1]=0;
				matrix[x+2][y+2]=4;
			}
			else if(matrix[x][y]==1 && x!=5)
			{
				matrix[x][y]=0;	
				matrix[x+1][y+1]=0;
				matrix[x+2][y+2]=1;
			}
		
			if(elimination2(matrix,x+2,y+2))
			eliminate(matrix,x+2,y+2);	
		}
		
		
		else if((matrix[x+1][y-1]==2 || matrix[x+1][y-1]==3) && matrix[x+2][y-2]==0 && ((matrix[x+1][y+1]!=2 && matrix[x+1][y+1]!=3) ||  matrix[x+2][y+2]!=0))
		{
			if (x==5)
			{
				matrix[x][y]=0;
				matrix[x+1][y-1]=0;
				matrix[x+2][y-2]=4;
			}
			else if(matrix[x][y]==1 && x!=5)
			{
				matrix[x][y]=0;
				matrix[x+1][y-1]=0;
				matrix[x+2][y-2]=1;
			}
		
			if(elimination2(matrix,x+2,y-2))
			eliminate(matrix,x+2,y-2);	
		}
		else if ((matrix[x+1][y+1]==3 || matrix[x+1][y+1]==2) && matrix[x+2][y+2]==0 && (matrix[x+1][y-1]==3 || matrix[x+1][y-1]==2) && matrix[x+2][y-2]==0)	
		{
			int choose;
			cout<<"choose which one do you want to eliminate(choose a number):\n1-left or 2-right?\n";
			cin>>choose;
			if (choose == 1)
			{
				if (x==5)
				{
					matrix[x][y]=0;
					matrix[x+1][y-1]=0;
					matrix[x+2][y-2]=4;
				}
				else if(matrix[x][y]==1 && x!=5)
				{
					matrix[x][y]=0;
					matrix[x+1][y-1]=0;
					matrix[x+2][y-2]=1;
				}
			
				if(elimination2(matrix,x+2,y-2))
				eliminate(matrix,x+2,y-2);
			}
			else if (choose == 2)
			{
				if (x==5)
				{
					matrix[x][y]=0;	
					matrix[x+1][y+1]=0;
					matrix[x+2][y+2]=4;
				}
				else if(matrix[x][y]==1 && x!=5)
				{
					matrix[x][y]=0;	
					matrix[x+1][y+1]=0;
					matrix[x+2][y+2]=1;
				}
				
				if(elimination2(matrix,x+2,y+2))
				eliminate(matrix,x+2,y+2);	
			}
			else
			{
				cout<<"you have to choose between 1 and 2!\n";
				eliminate(matrix,x,y);
			}
		}
		
	}

}
bool checkKing(int matrix[8][8],int x,int y)
{
	if(matrix[x][y]==3 || matrix[x][y]==4)
	{
		
		return true;	
	}
	
	else
	return false;
}
bool kingmove(int matrix[8][8],int x,int y,int move)
{
		cout<<"( 1-Move Up Right   2-Move Up Left   3-Move Down Right   4-Move Down Left) :"<<endl;
		cin>>move;
		if(move==1)
				{
					if(moveupright_king(matrix,x,y))
					return true;
					else 
					return false;
				}
		while(move==2)
				{
					if(moveupleft_king(matrix,x,y))
					return true;
					else 
					return false;
				}
		while(move==3)
				{
					if(movedownright_king(matrix,x,y))
					return true;
					else 
					return false;
				}
		while(move==4)
				{
					if(movedownleft_king(matrix,x,y))
					return true;
					else
					return false;
				}

}



bool moveupright_king(int matrix[8][8],int x,int y)
	{	
		if(x<1 || y>6)
		{
			cout<<"it is out of range!\n";
			return false;
		}
		else if(matrix[x-1][y+1]!=0)
		{
			cout<<"There is already a piece ! \n";
			return false;
		}

		else if(matrix[x-1][y+1]==0)
		{
		if(matrix[x][y]==3)
		{
		matrix[x-1][y+1]=3;
		matrix[x][y]=0;
		return true;
		}
		if(matrix[x][y]==4)
		{
		matrix[x-1][y+1]=4;
		matrix[x][y]=0;
		return true;
		}
		}

		else
		return false;
	}
bool moveupleft_king(int matrix[8][8],int x,int y)
	{
		if(x<1 || y<1)
		{
			cout<<"it is out of range!\n";
			return false;
		}
		
		else if(matrix[x-1][y-1]!=0)
		{
			cout<<"There is already a piece ! ";
			return false;
		}	

		else if(matrix[x-1][y-1]==0)
		{
		if(matrix[x][y]==3)
		{
		matrix[x-1][y-1]=3;
		matrix[x][y]=0;
		return true;
		}
		if(matrix[x][y]==4)
		{
		matrix[x-1][y-1]=4;
		matrix[x][y]=0;
		return true;
		}
		}

		else
		return false;
	}
	
bool movedownright_king(int matrix[8][8],int x,int y)
	{
		if (x>6 || y>6)
		{
			cout<<"it is out of range!\n";
			return false;
		}
		else if(matrix[x+1][y+1]!=0)
		{
			cout<<"There is already a piece ! ";
			return false;
		}
		else if(matrix[x+1][y+1]==0)
		{
		if(matrix[x][y]==3)
		{
		matrix[x+1][y+1]=3;
		matrix[x][y]=0;
		return true;
		}
		if(matrix[x][y]==4)
		{
		matrix[x+1][y+1]=4;
		matrix[x][y]=0;
		return true;
		}
		}
		else
		return false;
	}	
bool movedownleft_king(int matrix[8][8],int x,int y)
	{
		if (x>6 || y<1)	
		{
			cout<<"it is out of range!\n";
			return false;
		}
		else if(matrix[x+1][y-1]!=0)
		{
			cout<<"There is already a piece ! ";
			return false;
		}
		if(matrix[x+1][y-1]==0)
		{
		if(matrix[x][y]==3)
		{
		matrix[x+1][y-1]=3;
		matrix[x][y]=0;
		return true;
		}
		if(matrix[x][y]==4)
		{
		matrix[x+1][y-1]=4;
		matrix[x][y]=0;
		return true;
		}
		}
		else
		return false;
		
	}
bool winner1(int matrix[8][8])
{
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
		{
			if (matrix[i][j]==2 || matrix[i][j]==3)
			return false;
		}
	return true;	
}
bool winner2(int matrix[8][8])
{
	for (int i=0;i<8;i++)
		for (int j=0;j<8;j++)
		{
			if (matrix[i][j]==1 || matrix[i][j]==4)
			return false;
		}
	return true;	
}

void king_eliminate(int matrix[8][8],int x,int y)
{
	if (matrix[x][y]==3)
	{
		if((matrix[x-1][y+1]==4 || matrix[x-1][y+1]==1) && matrix[x-2][y+2]==0 && ((matrix[x-1][y-1]!=4 && matrix[x-1][y-1]!=1) || matrix[x-2][y-2]!=0) && ((matrix[x+1][y-1]!=4 && matrix[x+1][y-1]!=1) || matrix[x+2][y-2]!=0) && ((matrix[x+1][y+1]!=4 && matrix[x+1][y+1]!=1) || matrix[x+2][y+2]!=0) )
		{
			matrix[x][y]=0;
			matrix[x-1][y+1]=0;
			matrix[x-2][y+2]=3;
			if(elimination1(matrix,x-2,y+2))
			king_eliminate(matrix,x-2,y+2);
		}
		else if((matrix[x-1][y-1]==4 || matrix[x-1][y-1]==1) && matrix[x-2][y-2]==0 && ((matrix[x-1][y+1]!=4 && matrix[x-1][y+1]!=1) || matrix[x-2][y+2]!=0) && ((matrix[x+1][y-1]!=4 && matrix[x+1][y-1]!=1) || matrix[x+2][y-2]!=0) && ((matrix[x+1][y+1]!=4 && matrix[x+1][y+1]!=1) || matrix[x+2][y+2]!=0) )
		{
			matrix[x][y]=0;
			matrix[x-1][y-1]=0;
			matrix[x-2][y-2]=3;	
			if(elimination1(matrix,x-2,y-2))
			king_eliminate(matrix,x-2,y-2);
		}
		else if((matrix[x+1][y+1]==4 || matrix[x+1][y+1]==1) && matrix[x+2][y+2]==0 && ((matrix[x-1][y-1]!=4 && matrix[x-1][y-1]!=1) || matrix[x-2][y-2]!=0) && ((matrix[x-1][y+1]!=4 && matrix[x-1][y+1]!=1) || matrix[x-2][y+2]!=0) && ((matrix[x+1][y-1]!=4 && matrix[x+1][y-1]!=1) || matrix[x+2][y-2]!=0) )
		{
			matrix[x][y]=0;	
			matrix[x+1][y+1]=0;
			matrix[x+2][y+2]=3;
			if(elimination1(matrix,x+2,y+2))
			king_eliminate(matrix,x+2,y+2);
		}
		else if((matrix[x+1][y-1]==4 || matrix[x+1][y+1]==1) && matrix[x+2][y-2]==0 && ((matrix[x-1][y-1]!=4 && matrix[x-1][y-1]!=1) || matrix[x-2][y-2]!=0) && ((matrix[x-1][y+1]!=4 && matrix[x-1][y+1]!=1) || matrix[x-2][y+2]!=0) && ((matrix[x+1][y+1]!=4 && matrix[x+1][y+1]!=1) || matrix[x+2][y+2]!=0) )
		{
			
			matrix[x][y]=0;
			matrix[x+1][y-1]=0;
			matrix[x+2][y-2]=3;
			if(elimination1(matrix,x+2,y-2))
			king_eliminate(matrix,x+2,y-2);
		}
		else 
		{
			cout<<"choose which one you want to eliminate !\n(1-up right  2-up left  3-down right  4-down left)\n";
			int w;
			cin>>w;
			if (w==1 && (matrix[x-1][y+1]==4 || matrix[x-1][y+1]==1) && matrix[x-2][y+2]==0)
			{
				matrix[x][y]=0;
				matrix[x-1][y+1]=0;
				matrix[x-2][y+2]=3;
				if(elimination1(matrix,x-2,y+2))
				king_eliminate(matrix,x-2,y+2);
			}
			else if(w==2  && (matrix[x-1][y-1]==4 || matrix[x-1][y-1]==1) && matrix[x-2][y-2]==0)
			{
				matrix[x][y]=0;
				matrix[x-1][y-1]=0;
				matrix[x-2][y-2]=3;	
				if(elimination1(matrix,x-2,y-2))
				king_eliminate(matrix,x-2,y-2);
			}
			else if (w==3 && (matrix[x+1][y+1]==4 || matrix[x+1][y+1]==1) && matrix[x+2][y+2]==0)
			{
				matrix[x][y]=0;	
				matrix[x+1][y+1]=0;
				matrix[x+2][y+2]=3;
				if(elimination1(matrix,x+2,y+2))
				king_eliminate(matrix,x+2,y+2);
			}
			else if (w==4 && (matrix[x+1][y-1]==4 || matrix[x+1][y+1]==1) && matrix[x+2][y-2]==0)
			{
				matrix[x][y]=0;
				matrix[x+1][y-1]=0;
				matrix[x+2][y-2]=3;
				if(elimination1(matrix,x+2,y-2))
				king_eliminate(matrix,x+2,y-2);
			}
			else if (w!=1 && w!=2 && w!=3 && w!=4)
			{
				cout<<"try again! choose from 1 to 4.\n";
				king_eliminate(matrix,x,y);
			}
			else 
			{
				cout<<"this move in not available!\n";
				king_eliminate(matrix,x,y);
			}
		}
	}
	else if (matrix[x][y]==4)
	{
		if((matrix[x-1][y+1]==3 || matrix[x-1][y+1]==2) && matrix[x-2][y+2]==0 && ((matrix[x-1][y-1]!=3 && matrix[x-1][y-1]!=2) || matrix[x-2][y-2]!=0) && ((matrix[x+1][y-1]!=3 && matrix[x+1][y-1]!=2) || matrix[x+2][y-2]!=0) && ((matrix[x+1][y+1]!=3 && matrix[x+1][y+1]!=2) || matrix[x+2][y+2]!=0) )
		{
			matrix[x][y]=0;
			matrix[x-1][y+1]=0;
			matrix[x-2][y+2]=4;
			if(elimination2(matrix,x-2,y+2))
			king_eliminate(matrix,x-2,y+2);
		}
		else if((matrix[x-1][y-1]==3 || matrix[x-1][y-1]==2) && matrix[x-2][y-2]==0 && ((matrix[x-1][y+1]!=3 && matrix[x-1][y+1]!=2) || matrix[x-2][y+2]!=0) && ((matrix[x+1][y-1]!=3 && matrix[x+1][y-1]!=2) || matrix[x+2][y-2]!=0) && ((matrix[x+1][y+1]!=3 && matrix[x+1][y+1]!=2) || matrix[x+2][y+2]!=0) )
		{
			matrix[x][y]=0;
			matrix[x-1][y-1]=0;
			matrix[x-2][y-2]=4;	
			if(elimination2(matrix,x-2,y-2))
			king_eliminate(matrix,x-2,y-2);
		}
		else if((matrix[x+1][y+1]==3 || matrix[x+1][y+1]==2) && matrix[x+2][y+2]==0 && ((matrix[x-1][y-1]!=3 && matrix[x-1][y-1]!=2) || matrix[x-2][y-2]!=0) && ((matrix[x-1][y+1]!=3 && matrix[x-1][y+1]!=2) || matrix[x-2][y+2]!=0) && ((matrix[x+1][y-1]!=3 && matrix[x+1][y-1]!=2) || matrix[x+2][y-2]!=0) )
		{
			matrix[x][y]=0;	
			matrix[x+1][y+1]=0;
			matrix[x+2][y+2]=4;
			if(elimination2(matrix,x+2,y+2))
			king_eliminate(matrix,x+2,y+2);
		}
		else if((matrix[x+1][y-1]==3 || matrix[x+1][y+1]==2) && matrix[x+2][y-2]==0 && ((matrix[x-1][y-1]!=3 && matrix[x-1][y-1]!=2) || matrix[x-2][y-2]!=0) && ((matrix[x-1][y+1]!=3 && matrix[x-1][y+1]!=2) || matrix[x-2][y+2]!=0) && ((matrix[x+1][y+1]!=3 && matrix[x+1][y+1]!=2) || matrix[x+2][y+2]!=0) )
		{
			
			matrix[x][y]=0;
			matrix[x+1][y-1]=0;
			matrix[x+2][y-2]=4;
			if(elimination2(matrix,x+2,y-2))
			king_eliminate(matrix,x+2,y-2);
		}
		else 
		{
			cout<<"choose which one you want to eliminate !\n(1-up right  2-up left  3-down right  4-down left)\n";
			int w;
			cin>>w;
			if (w==1 && (matrix[x-1][y+1]==3 || matrix[x-1][y+1]==2) && matrix[x-2][y+2]==0)
			{
				matrix[x][y]=0;
				matrix[x-1][y+1]=0;
				matrix[x-2][y+2]=4;
				if(elimination2(matrix,x-2,y+2))
				king_eliminate(matrix,x-2,y+2);
			}
			else if(w==2  && (matrix[x-1][y-1]==3 || matrix[x-1][y-1]==2) && matrix[x-2][y-2]==0)
			{
				matrix[x][y]=0;
				matrix[x-1][y-1]=0;
				matrix[x-2][y-2]=4;	
				if(elimination2(matrix,x-2,y-2))
				king_eliminate(matrix,x-2,y-2);
			}
			else if (w==3 && (matrix[x+1][y+1]==3 || matrix[x+1][y+1]==2) && matrix[x+2][y+2]==0)
			{
				matrix[x][y]=0;	
				matrix[x+1][y+1]=0;
				matrix[x+2][y+2]=4;
				if(elimination2(matrix,x+2,y+2))
				king_eliminate(matrix,x+2,y+2);
			}
			else if (w==4 && (matrix[x+1][y-1]==3 || matrix[x+1][y+1]==2) && matrix[x+2][y-2]==0)
			{
				matrix[x][y]=0;
				matrix[x+1][y-1]=0;
				matrix[x+2][y-2]=4;
				if(elimination2(matrix,x+2,y-2))
				king_eliminate(matrix,x+2,y-2);
			}
			else if (w!=1 && w!=2 && w!=3 && w!=4)
			{
				cout<<"try again! choose from 1 to 4.\n";
				king_eliminate(matrix,x,y);
			}
			else 
			{
				cout<<"this move in not available!\n";
				king_eliminate(matrix,x,y);
			}
		}
	}
	
	
}
