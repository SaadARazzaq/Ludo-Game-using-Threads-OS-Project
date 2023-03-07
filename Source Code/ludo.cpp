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

#include "player.h"
#include "masterThread.h"
#include "board.h"
#include "tokenkiller.h"
#include "playerThread.h"
//HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
int main(void)
{ 
	cout<<"    \033[1;93m*****************************************************************\n";
	cout<<"    *****************************************************************\n";
	cout<<"    *****************************************************************\n";
	cout<<"    *                                                               *\n";
	cout<<"    *                  LUDO GAME USING THREADS                      *\n";
	cout<<"    *                                                               *\n";
	cout<<"    *****************************************************************\n";
	cout<<"    *****************************************************************\n";
	cout<<"    *****************************************************************\033[0m\n";
	//asking about the number of tokens
    do
	{
		cout<<"\033[1;95m =>To PLay the Game, Enter token numbers (1 - 4): \033[0m";
    	cin>>tokens;
	} while (tokens<1 || tokens>4);
	
	//creating four players
	player temp('&',tokens);
	player temp1('%',tokens);
	player temp2('#',tokens);
	player temp3('@',tokens);
	
	p1=temp;
	p2=temp1;
	p3=temp2;
	p4=temp3;

	//creating an array for random turns
	int arr[4]={1,2,3,4};	
	while(1){
		sem_init(&sem,0,1);	
		random_shuffle(arr,arr+4);//random values for different player selection 
		pthread_t tid[4];
		system("clear");
       

		//creating 4 threads each for one player
		for(int i=0;i<4;i++){
			pthread_create(&tid[i],NULL,&playerthread,&arr[i]);
			
		}
		//joing 4 threads
		for(int i=0;i<4;i++){
			pthread_join(tid[i],NULL);

		}
		
	}    
    return 0;
}
