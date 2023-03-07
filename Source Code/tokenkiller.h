/*
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
;;;LUDO PROJECT USING TREADS;;;
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
____________________________________
ROLL NUMBER: 20f-0292              |
NAME: Saad Abdur Razzaq            |
SECTION: BCS - 5E                  |
SUBMITTED TO: SIR HASEEB ASRSHAD   |
------------------------------------

*/

int rolling_dice()
{
	srand (time(NULL));
	return rand()%6+1;
}

int x[4][3];
void* hitVictimThread(void * attr)
{
	int temp=(*(int*)attr);
	player * tempPlayer;
	if(temp==1){
		tempPlayer=&p1;
	}
	else if(temp==2){
		tempPlayer=&p2;
	}
	else if(temp==3){
		tempPlayer=&p3;
	}
	else if(temp==4){
		tempPlayer=&p4;
	} 
    if(tempPlayer->inGame && !tempPlayer->is_win)
	{
		sem_wait(&sem1);
		for(int i=0;i<tokens;i++){
			if(tempPlayer->tok[i].sym=='&')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p3.tok[j].x&&tempPlayer->tok[i].y==p3.tok[j].y && p3.tok[j].open ==1 && p3.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 1 KILLED PLAYER 3***\033[0m"<<endl;
						p3.tok[j].value=-1;
						p3.tok[j].open=0;
						p3.tok[j].home=0;
						p3.tok[j].x=8;
						p3.tok[j].y=1;
						tempPlayer->hitRate++;
					}
					if(tempPlayer->tok[i].x==p4.tok[j].x &&tempPlayer->tok[i].y==p4.tok[j].y && p4.tok[j].open==1 &&p4.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 1 KILLED PLAYER 4***\033[0m"<<endl;
						p4.tok[j].value=-1;
						p4.tok[j].open=0;
						p4.tok[j].home=0;
						p4.tok[j].x=13;
						tempPlayer->hitRate++;
						p4.tok[j].y=8;
					}
					if(tempPlayer->tok[i].x==p2.tok[j].x && tempPlayer->tok[i].y==p2.tok[j].y && p2.tok[j].open==1 &&p2.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 1 KILLED PLAYER 2***\033[0m"<<endl;
						p2.tok[j].home=0;

						p2.tok[j].value=-1;
						p2.tok[j].open=0;
						p2.tok[j].x=6;
						tempPlayer->hitRate++;
						p2.tok[j].y=13;
					}
				}
			}
			else if(tempPlayer->tok[i].sym=='%')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p1.tok[j].x && tempPlayer->tok[i].y==p1.tok[j].y&& p1.tok[j].open==1 && p1.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 2 KILLED PLAYER 1***\033[0m"<<endl;
						p1.tok[j].value=-1;
						tempPlayer->hitRate++;
						p1.tok[j].home=0;
						p1.tok[j].open=0;
						p1.tok[j].x=1;
						p1.tok[j].y=6;
					}
					if(tempPlayer->tok[i].x==p3.tok[j].x && tempPlayer->tok[i].y==p3.tok[j].y && p3.tok[j].open==1  &&p3.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 2 KILLED PLAYER 3***\033[0m"<<endl;
						p3.tok[j].value=-1;
						p3.tok[j].home=0;
						p3.tok[j].open=0;
						tempPlayer->hitRate++;
						p3.tok[j].x=8;
						p3.tok[j].y=1;
					}
					if(tempPlayer->tok[i].x==p4.tok[j].x && tempPlayer->tok[i].y==p4.tok[j].y && p4.tok[j].open==1  &&p4.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 2 KILLED PLAYER 4***\033[0m"<<endl;
						p4.tok[j].value=-1;
						p4.tok[j].open=0;
						tempPlayer->hitRate++;
						p4.tok[j].home=0;
						p4.tok[j].x=13;
						p4.tok[j].y=8;
					}
				}
			}
			else if(tempPlayer->tok[i].sym=='#')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p4.tok[j].x && tempPlayer->tok[i].y==p4.tok[j].y && p4.tok[j].open==1  &&p4.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 3 KILLED PLAYER 4***\033[0m"<<endl;
						p4.tok[j].value=-1;
						p4.tok[j].open=0;
						p4.tok[j].home=0;
						p4.tok[j].x=13;
						tempPlayer->hitRate++;
						p4.tok[j].y=8;
					}
					if(tempPlayer->tok[i].x==p2.tok[j].x && tempPlayer->tok[i].y==p2.tok[j].y && p2.tok[j].open==1  &&p2.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 3 KILLED PLAYER 2***\033[0m"<<endl;
						p2.tok[j].value=-1;
						p2.tok[j].open=0;
						tempPlayer->hitRate++;
						p2.tok[j].home=0;
						p2.tok[j].x=6;
						p2.tok[j].y=13;
					}
					if(tempPlayer->tok[i].x==p1.tok[j].x && tempPlayer->tok[i].y==p1.tok[j].y && p1.tok[j].open==1  &&p1.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 3 KILLED PLAYER 1***\033[0m"<<endl;
						p1.tok[j].value=-1;
						tempPlayer->hitRate++;
						p1.tok[j].home=0;
						p1.tok[j].open=0;
						p1.tok[j].x=1;
						p1.tok[j].y=6;
					}
				}
			}
			else if(tempPlayer->tok[i].sym=='@')
			{
				for(int j=0;j<tokens;j++)
				{
					if(tempPlayer->tok[i].x==p2.tok[j].x &&tempPlayer->tok[i].y==p2.tok[j].y && p2.tok[j].open==1 && p2.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 4 KILLED PLAYER 2***\033[0m"<<endl;
						p2.tok[j].value=-1;
						p2.tok[j].open=0;
						p2.tok[j].x=6;
						tempPlayer->hitRate++;
						p2.tok[j].home=0;
						p2.tok[j].y=13;
					}
					if(tempPlayer->tok[i].x==p1.tok[j].x && tempPlayer->tok[i].y==p1.tok[j].y  && p1.tok[j].open==1 &&p1.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 4 KILLED PLAYER 1***\033[0m"<<endl;
						p1.tok[j].value=-1;
						tempPlayer->hitRate++;
						p1.tok[j].home=0;
						p1.tok[j].open=0;
						p1.tok[j].x=1;
						p1.tok[j].y=6;
					}
					if(tempPlayer->tok[i].x==p3.tok[j].x && tempPlayer->tok[i].y==p3.tok[j].y && p3.tok[j].open==1 && p3.tok[j].stop!=1)
					{
						cout<<"\t\034[1;34m ***PLAYER 4 KILLED PLAYER 3***\033[0m"<<endl;
						p3.tok[j].value=-1;
						tempPlayer->hitRate++;
						p3.tok[j].open=0;
						p3.tok[j].home=0;
						p3.tok[j].x=8;
						p3.tok[j].y=1;
					}
				}
			}
		}
		sem_post(&sem1);
	}
pthread_exit(NULL);
}
