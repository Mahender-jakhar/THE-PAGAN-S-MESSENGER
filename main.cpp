
#include "./header/pro.dec"

int main ()
{	
   system("clear");
	start:
	kill = NULL;
	int cnt = 1;
	
	while(cnt)
	{
		if(kill == NULL)
			cnt = main_menu();
		else
			{   usermenu:
				cnt = user_menu();
	//goto usermenu; }

            }
    }
	
	goto start;	footer();
	cout<<"\nHave a nice day Ahead";
	return 0;

}
