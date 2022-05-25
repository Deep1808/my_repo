// C Program for Message Queue (Reader Process)
#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#define MAX 10

struct mesg_buffer {
long mesg_type;
char mesg_text[100];
} message;int main()
{
while(1)
{
	key_t key;
	int msgid; key = ftok("progfile", 32);
       	msgid = msgget(key, 0666 | IPC_CREAT);
       	msgrcv(msgid, &message, sizeof(message), 1, 0);
       	printf("Data Received is : %s \n",message.mesg_text);
       	msgctl(msgid, IPC_RMID, NULL);
// msg sending
	message.mesg_type = 1;
	printf("Write Data : ");
	fgets(message.mesg_text,MAX,stdin);
	msgsnd(msgid, &message, sizeof(message), 0);
	printf("Data send is : %s \n", message.mesg_text);
	} return 0;
}


