#include"myheaders.h"
int isPasswordValid(char *p)
{
    int u=0,l=0,d=0,s=0;
    if (strlen(p) < 8) return 0;
    for (int i=0;p[i];i++) {
        if (isupper(p[i])) u=1;
        else if (islower(p[i])) l=1;
        else if (isdigit(p[i])) d=1;
        else s=1;
    }
    return u && l && d && s;
}
int signUp()
{
        USER var;
        int cnt=0,ucnt=0;
        FILE *fp;
        char sname[20],spwd[20];
        fp=fopen("login_info","a+");
        if(fp==NULL)
        {
                printf("login file failed to open\n");
                return 0;
        }
un:     printf("enter username\n");
        scanf("%s",var.name);
pw:     printf("enter password\n");
        scanf("%s",var.password);
        if(!isPasswordValid(var.password))
        {
                cnt++;
		if(cnt>=5)                                                                  {                                                                                   printf("TIME OUT....try after sometime");                                   return 0;                                                           }
                printf("enter valid password\n");
                goto pw;
        }
	rewind(fp);
        while(fscanf(fp,"%s %s",sname,spwd)==2)
        {
                if(!strcmp(sname,var.name))
                {
                        ucnt++;
                        printf("username already exists...try something new\n");
                        if(ucnt>=5)
			{
				printf("you have reached max limit to enter usernames.....try after sometime\n");
				return 0;
			}
			goto un;
                }
        }
        fprintf(fp,"%s %s\n",var.name,var.password);
        fclose(fp);
        return 1;
}
int signIn()
{
        char name[20],password[20],sname[20],spassword[20];
        FILE *fp;
        int cnt=0;
si:     printf("enter username\n");
        scanf("%s",name);
        printf("enter password\n");
        scanf("%s",password);
	if(!strcmp(name,"V25HE1C1")&&!strcmp(password,"Vector#123"))
        {
                        return -1;
        }
        fp=fopen("login_info","r");
        if(fp==NULL)
        {
                printf("failed to open log in details\n");
                return 0;
        }
        while(fscanf(fp,"%s %s",sname,spassword)==2)
        {
                if(!strcmp(name,sname)&&!strcmp(password,spassword))
                {
			fclose(fp);
                        return 1;
                }
        }
	cnt++;
        if(cnt<3)
        {
                printf("provided username and password are not found.....try again\n");
                fclose(fp);
		goto si;
        }
	printf("you have reached the max limit, pls try after 5 min to log in\n");
        fclose(fp);
        return 0;
}
