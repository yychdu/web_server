#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int main(void){
	//char *f_line="HTTP1.1 200 \r\n";
	char *content="Content-Type: text/html \r\n\r\n";
	char *html="<html>\n<body><h>this is a test ...<image src=mingxing.jpg></body>\n</html>";
	//printf("%s",f_line);
	printf("%s",content);
	printf("%s",html);
	char *p=getenv("QUERY_STRING");
	if(p!=NULL)
		printf("%s\n",p);
	//fflush();
	//write(1,f_line,strlen(f_line));
	//write(1,content,strlen(content));
	//write(1,html,strlen(html));

	return 0;
}
