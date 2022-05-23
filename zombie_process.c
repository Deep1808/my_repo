#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>

int main()
{

pid_t child_pid = fork();
// Parent process
if (child_pid > 0)
sleep(5);

// Child process
else
exit(0);

return 0;
}
