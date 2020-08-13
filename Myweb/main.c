#include <stdio.h>
#include "socket.h"
#include "config.h"
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "trans.h"


char* dir;
int main()
{
	int result = 0;
	SA4 client;
	int Clientfd;
	char web_dir[128];
	char IP[128];
	int port;
	log_fd = init_logfile("error.log");
	if (log_fd == -1)
	{
		printf("init log ERR!");
		result = -1;
	}
	else
	{
		//-------------------------------------通过读写环境变量 读取 port 和 web_dir
		int r = get_conf("web.conf");
		if (r == -1)
		{
			sys_err("config");
			result = -1;
		}
		else
		{
			dir = getenv("web_dir");
			char* p = getenv("web_port");
			if (p == NULL || dir == NULL)
			{
				result = -1;
				sys_err("env val");
			}
			else
				port = atoi(p);
		}
		//------------------------
		int Serverfd = socket_b(port);
		if (Serverfd == -1)
		{
			result = -1;
			sys_err("socket");
		}
		else
		{
			r = listen(Serverfd, 5);
			if (r == -1)
			{
				result = -1;
				sys_err("listen");
			}
			else
			{
				int i = 0;
				socklen_t _Size = sizeof(client);
				while (1)
				{
					Clientfd = accept(Serverfd, (SA*)&client, &_Size);
					printf("C fd:%d\n", Clientfd);
					if (Clientfd == -1)
					{
						result = -1;
						sys_err("accept");
					}
					else
					{
						printf("new link ---------%s\n", inet_ntop(AF_INET, &client.sin_addr, IP, 128));
						pid_t pid = fork();
						if (pid == -1)
						{
							result = -1;
							sys_err("fork");
							break;
						}
						else if (pid == 0)	////子进程的任务
						{
							close(Serverfd);
							// 到这里的时候，三次握手已经成功了
								//对客户端的请求数据进行处理
							trans(Clientfd);
							//关闭本次连接
							close(Clientfd);
							exit(0);
						}
						else
						{
							close(Clientfd);
							waitpid(-1, NULL, WNOHANG);
						}

					}
				}
			}

		}
	}
	return result;
}