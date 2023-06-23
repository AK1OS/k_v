#include <map>  
#include <string>  
#include <iostream>  
#include <fstream>
#include <string.h>
#include <stdio.h>
#include <readline/readline.h>
#include <readline/history.h>

using namespace std;  

const char *pro="input>>";
map<string,string> my_map;
char *lineread=NULL;

char *Readline(){
	if(lineread){
		free(lineread);
		lineread=NULL;
	}
	lineread=readline(pro);
	if(lineread){
		add_history(lineread);
	}
	return lineread;
}

void save_kv(char *a,char *b){
	my_map.insert(pair<string,string>(a,b));
	FILE *p=fopen("./test_file","a+");
	fprintf(p,"%s %s\n",a,b);
	fclose(p);
}

void init(){
	char *str1,*str2;
        FILE *p=fopen("./test_file","r");
        char c[50];
        while((fgets(c,50,p))!=NULL){
	    str1=strtok(c," ");
	    str2=strtok(NULL," ");
	    my_map.insert(pair<string,string>(str1,str2));
    }

}
int main()  
{  
	init();
	while(1){
		int n;
		cout<<"请输入操作对应序号："<<endl;
		cout<<"1.查询键值对\n2.增加键值对\n3.退出\n"<<endl;
		cin>>n;
		switch(n){
			case 1:
			    {
				    while(1)
				    {
					    char key[100];
					    char *temp;
					    cout<<"请输入key(输入exit退出查询)："<<endl;
					    temp=Readline();
					    strcpy(key,temp);
					    if(strcmp(key,"exit")==0){break;}
						    else
						    {
							    map<string,string>::iterator it;
							    it = my_map.find(key);  
							    if(it != my_map.end())  
								cout<<"Find, the value is "<<it->second<<endl;      
							    else  
								cout<<"Do not Find"<<endl;  
						    }
				    }
			    	    continue;
			    }
			case 2:
				{
					while(1)
					{
					    char c[100];
					    char *str1,*str2;
					    cout<<"输入key(输入exit退出新增键值对):"<<endl;
					    str1=Readline();
					    strcpy(c,str1);
					    if(strcmp(c,"exit")==0){break;}
						else
						{
						    cout<<"输入value:"<<endl;
						    str2=Readline();
						    save_kv(c,str2);
						}
					}
				continue;
				}
			case 3:
				break;
			default:
				continue;

		}
    return 0;  
}
}
