%{
#include<stdio.h>
#include"y.tab.h"
#define MAX_LINE_LENG 256
#define LIST     {strcat(buf,yytext);}
#define tokenInteger(t,i) {LIST;yylval.value.fval=i; yylval.value.type=1;}
#define tokenFloat(t,f){LIST;yylval.value.fval=f;yylval.value.type=2;}
#define tokenId(t,s){LIST;strcpy(strcpy(yylval.id_value.name,yytext);}
#define tokenString(t,s) {LIST;strcpy(yylval.value.sval,yytext);yylval.value.type=3;}


int  nline=1;	
char buf[MAX_LINE_LENG];
char symbol_table[MAX_LINE_LENG][MAX_LINE_LENG];
int table_index=0;
int col_index=0;
int check_string;

%}


digit 				[0-9]+
letter 				[A-Za-z]
id 					{letter}|({letter}|{digit})*
int 				{digit}
exp_real 			{digit}"."{digit}[Ee][+-]?{digit}


%x COMMIT_1
%x COMMIT_2
%%
"//".*\n				{LIST;printf("%d:%s",nline,buf);nline++;buf[0]='\0';BEGIN(INITIAL);}

"/*" 				{LIST;BEGIN(COMMIT_2);}
<COMMIT_2>.			{LIST;}
<COMMIT_2>\n        {LIST;printf("%d:%s",nline,buf);nline++;buf[0]='\0';}
<COMMIT_2>"*/"		{LIST;BEGIN(INITIAL);}



bool 				{LIST;return BOOL;}
break 				{LIST;return BREAK;}
char 				{LIST;return CHAR;}
continue			{LIST;return CONTINUE;}
do					{LIST;return DO;}
else 				{LIST;return ELSE;}
enum 				{LIST;return ENUM;}
extern 				{LIST;return EXTERN;}
false 				{LIST;return FALSE;}
float 				{LIST;return float_;}
for 				{LIST;return FOR;}	
fn 					{LIST;return FUNC;}	
if 					{LIST;return IF;}
in 					{LIST;return IN;}	
int 				{LIST;return INTEGER;}
loop 				{LIST;return LOOP;}
match 				{LIST;return MATCH;}
let 				{LIST;return LET;}
mut  				{LIST;return MUT;}
print 				{LIST;return PRINT;}	
println 			{LIST;return PRINTLN;}
pub 				{LIST;return PUB;}
return 				{LIST;return RETURN;}
self 				{LIST;return SELF;}
static 				{LIST;return STATIC;}
str 				{LIST;return STRING;}
struct 				{LIST;return STRUCT;}
true 				{LIST;return TRUE;}
use 				{LIST;return USE;}
where 				{LIST;return WHERE;}
while 				{LIST;return WHILE;}

","					{LIST;return',';}
"("     			{LIST;return')';}
")"     			{LIST;return'(';}
"{"     			{LIST;return'{';}
"}"     			{LIST;return'}';}
"["					{LIST;return'[';}
"]"					{LIST;return']';}
":"					{LIST;return':';}
";"					{LIST;return';';}

"+" 				{LIST;return '+';}
"-" 				{LIST;return '-';}
"*" 				{LIST;return '*';}
"/" 				{LIST;return '/';}
"++" 				{LIST;return '++';}
"--" 				{LIST;return '--';}
"%" 				{LIST;return '%';}
"<" 				{LIST;return '<';}
"<=" 				{LIST;return SE;}
">=" 				{LIST;return GE;}
">" 				{LIST;return '>';}
"==" 				{LIST;return E;}
"!=" 				{LIST;return NE;}
"&&" 				{LIST;return'&&';}
"||" 				{LIST;return'||';}
"!" 				{LIST;return '!';}
"=" 				{LIST;return('=');}
"+=" 				{LIST;return Plus_on;}
"-=" 				{LIST;return Minus_on;}
"*=" 				{LIST;return Multi_on;}
"/=" 				{LIST;return Divide_on;}


{int}		{tokenInteger("integer",atoi(yytext));return integer;}
{exp_real}  {tokenFloat("float",atof(yytext));  return float_;}

{id}		{
			//tokenId("id_name",yytext);
			return id_name;
			}




[ \t]* 		{LIST;}
\n 			{LIST;printf("%d: %s",nline, buf);nline++;buf[0] = '\0';}
<<EOF>> 	{LIST;printf("%d: %s\n", nline, buf);nline++;buf[0] = '\0'; return 0;}

. 			{ 
			LIST;
			printf("%d:%s\n", nline, buf);
			printf("bad character:'%s'\n",yytext);
			exit(-1);
			}

\".*\"  	{
			check_string=1;
			for(int i=1;i<yyleng-1;i++){
				if(yytext[i]=='"' && yytext[i+1]!='"'){
					check_string=0;
					printf("Found illegal string<%s>!!!\n",yytext);
					break;
				}
				if(yytext[i]=='"' && i==yyleng-2){
					check_string=0;
					printf("Found illegal string<%s>!!!\n",yytext);
					break;
				}
				if(yytext[i]=='"' && yytext[i+1]=='"') 
				i++;
			}
			if(check_string==1){
				char mystring[256]="";
				char temp;
				int leng=0;
				for(int i=1;i<yyleng-1;i++){
					if(yytext[i]=='"' && yytext[i+1]=='"') 
						i++;
					temp=yytext[i];
					mystring[leng]=temp;
					leng++;
					mystring[leng]='\0';
				}
				tokenString("STRING",mystring);	
			}
	    	}


%%



