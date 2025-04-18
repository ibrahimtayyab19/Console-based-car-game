#include<iostream>
#include<ctime>
#include<conio.h>
using namespace std;

static int blink=0;
const int MAX = 3;
int Random1[MAX] = {5,9,13};
int Random2[MAX] = {13,5,9};

void start()
{
    char ch;
        cout << "+---------------------------------------+\n"
        "|         WELCOME TO CAR GAME!         |\n"
        "+---------------------------------------+\n\n"
        "Instructions to Play:\n\n"
        "- You control the car marked with `#`.\n"
        "- Your mission is to AVOID hitting (enemy cars) \n"
        "  coming from the front.\n"
        "- Stay on the road and survive as long as possible!\n\n"
        "Controls:\n"
        "    W  -> Move Forward\n"
        "    A  -> Move Left\n"
        "    D  -> Move Right\n\n"
        "Rules:\n"
        "- Avoid collisions with enemy vehicles or the edges.\n"
        "- The longer you survive, the higher your score!\n"
        "- Press E key anytime to exit the game.\n\n"
        "Tips:\n"
        "- Stay alert! Enemies approach quickly.\n"
    
        "- Stick to your lane to stay safe.\n\n"
        ">> Press any key to START the game <<\n";   
        ch=getch();
        cout<<"\a";
}

class Car
{
    private:
        float x;
        int y;
        int score;
        int enemyPass;
        int enemy2Pass;
        float enemyPosition;
    	float enemy_X;
        float enemy_Y;
        float enemy2_X;
        float enemy2_Y;
        const int min_Y=3;//These are the boundries or limits
        const int max_Y=15;
        const int min_X=2;
        const int max_X=14;
    public:
  
        Car()
        {
            x=17;
            y=9;
            score=0;
            enemyPass = 1;
            enemy2Pass = 1;
            enemy_X=1;
            enemy_Y = (Random1[EnemyPos()]);
            enemy2_X=1;
            enemy2_Y = (Random2[EnemyPos()]);
        }
  
        void enemyForward()
        {
        	enemy_X+=1;
        	enemy2_X+=2;
            enemyPass++;
            enemy2Pass++;
		}
  
        void forward()
        {
        	enemyForward();    
        }
  
        void right()
        {
            if(y-3>min_Y)
            {
			    y-=4;	
            	enemyForward();
			}
			else
				cout << "\a" ;    
        }
  
          void left()
        {
            if(y+3<max_Y)
            {
			    y+=4;
                enemyForward();
			} 
 			else
				cout << "\a" ;
        }
  
        int EnemyPos()
        {
			srand(time(NULL));
        	enemyPosition = rand() % 3;
        	return enemyPosition;
    	}
  
    void road()
    {

		if(enemyPass % 18 == 0)
		{
			score++;
			enemy_Y = (Random1[EnemyPos()]); 
	    	enemy_X = 1;
	    	enemyPass = 1;
		}

		if(enemy2Pass % 10 == 0 )
		{
			score++;
			enemy2_Y = (Random2[EnemyPos()]); 
	    	enemy2_X = 1;
            enemy2Pass = 1;
		}

		for (int i = 1; i<=18 ; i++)
    	{
		    for(int j=1;j<=17;j++)
    		{
	    		if(i==1||i==18||j==1||j==17)
    				cout<<"|";
	    		else
	    		{
                    if(i==x&&j==y)
                    {
                        cout<<"#";
                    }         
                    else if(i==enemy_X&&j==enemy_Y)
                    {
                        cout<<"Y";
                    }
                    else if(i==enemy2_X&&j==enemy2_Y)
                    {
                        cout<<"V";
                    }
                    else if(j==3||j==7||j==11||j==15) 
                    {
                        cout<<"|";
                    } 
                    else if(j==5||j==9||j==13)
                    {
                        if(blink%2==0 && i%2==0)
                            cout<<"."; 
                        else if(blink%2==1 && i%2==1)
                            cout << ".";
                    	else
                    		cout << " ";
					}
                    else if(j==2 || j==16)
                    {
                        if(blink%2==0)
                            cout <<"\\"; 
                        else       
                            cout << "/";
                    }                
					else
    				{
						cout<<" ";	
                	}
				}
			}
			cout<<endl;
    		if(x == enemy_X && y == enemy_Y || x == enemy2_X && y == enemy2_Y )
			{
    			cout<<"\"G A M E O V E R\"\a\n";
				cout << "-----------------" << endl;
				cout << "  S C O R E: \"" << score << "\"" << endl;
    	   		cout << "-----------------" << endl;
				exit(1);	
				break;
			}
		}

    	static int scount=0;
        if(scount==0)
        {
            cout<<" S  T  A  R  T !\n";
        	cout<<"[ C A R G A M E ]\n";
			scount++;
        }
        else
        {
        	cout << "-----------------" << endl;
			cout << "  S C O R E: \"" << score << "\"" << endl;
    	    cout << "-----------------" << endl;
		}
	}
};

int main()			
{
	char ch,s;
    Car c;
    
    start();   
	 
	do
	{
		blink++;		
		system("cls"); //Use clrscr() if its not working
		//        clrscr(); //Some compiler not supporting it
	
		c.road();
		ch=getch();
		
		if(ch=='w' || ch == 'W')
			c.forward();
		else if(ch=='a' || ch=='A')
			c.right();
		else if(ch=='d' || ch=='D')
            c.left();
            
	}
	while(ch!='e');
	
    if(ch=='e')
    {
//        clrscr(); //Some compiler not supporting it
		system("cls"); //Use clrscr() if its not working
	    c.road();
        cout<<"\"G A M E O V E R\"\a\n";
        cout << "\nYou Press E Exit Button\n";
    }
    
return 0;
}