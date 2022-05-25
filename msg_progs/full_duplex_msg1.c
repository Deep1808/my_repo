#include <stdio.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <string.h>
#define SEND_KEY 2
#define RCV_KEY 3

typedef struct msgbuf 
{
    long mtype;     /* message type, must be > 0 */
    char mtext[100];  /* message data */
} MSG_BUF;
int main()
{
    int msg_id;
    MSG_BUF mbuf_snd,mbuf_rcv;

    if((msg_id=msgget(5,IPC_CREAT |0644))<0)
        perror("msgget");

    if(fork()==0)
    {
        // child is receiving
        while(1) {
            if((msgrcv(msg_id,&mbuf_rcv,sizeof(mbuf_rcv.mtext),RCV_KEY,0))<0)
                perror("msgrcv");
            printf("Message : %s\n",mbuf_rcv.mtext);
        }
    }
    else
    {
        // Parent is writing
        while(1){
            mbuf_snd.mtype=SEND_KEY;
            printf("Enter the message\n");
            scanf(" %[^\n]",mbuf_snd.mtext);
            if((msgsnd(msg_id,&mbuf_snd,strlen(mbuf_snd.mtext)+1,0))<0)
                perror("msgsnd");
        }
    }
    return 0;
}
