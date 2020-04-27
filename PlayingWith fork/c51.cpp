#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;
int main(int argc, char const *argv[])
{
	int x =100;
	cout<<"Starting a process with pid : "<<int(getpid());
	int rc = fork();
	if(rc < 0 )
	{
		cout<<"Fork failed!"<<endl;
	}
	else if(rc==0)
	{
		cout<<"This is a child process with pid : "<<int(getpid());
		cout<<"value of x here : "<<x<<endl;

	}
	else 
	{
		wait(NULL);
		cout<<"Back to the parent!"<<endl;
		cout<<"VAlue of x here : "<<x<<endl;

	}
	return 0;
}