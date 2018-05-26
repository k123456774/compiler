
%{
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define Trace(t)  {if(Opt_P) printf(t);}
int Opt_P = 1;


int symtab_counter;
int current_symtab;
int symtab_pre[100];
int id_num[100];
struct node* ids[100][46];

void create(int,int);
int insert(char*,int,int,float);
int lookup(char*,int);
void update_value(char*,int,float);
float get_value(char*,int);
int   get_type(char*,int);
int   check_in_scope(char*,int);

int yylex();
int yyerror(const char*);

%}
%union{
        int type;          // 0=void 1=int 2=float 3=string, for non-terminal(type)

        struct{            //for const value or non-terminal
            float fval;
            int ival;
            char sval[256];
            int type;
            } value;
        
        struct {           //for id
             char name[30];
             int  type;
             float fval;
             int   ival;
                } id_value;
        }

%start program



/* tokens */
%token SEMICOLON
%token <value>integer
%token <value>float_
%token <value>string
%token <id_value>id_name

%token FUNC MUT STRUCT LET
%token INTEGER BOOL STRING CHAR FLOAT
%token ENUM EXTERN MATCH
%token RETURN 
%token ',' ':' ';' '(' ')' '{' '}' '[' ']'
%token '+' '-' '*' '/' '=' 
%token '%'  //'++' '--'
%token Plus_on Minus_on Multi_on Divide_on 

%token IF ELSE BREAK CONTINUE IN TRUE FALSE
%token FOR WHILE  DO LOOP
%token PRINT PRINTLN
%token PUB SELF STATIC USE WHERE


%type <type>type
%type <value>constant_exp
%type <value>expression

%left '||'
%left '&&'
%left '!'
%left E NE GE SE '>' '<' 
%left '+' '-'
%left '*' '/' '%' 
%left '^'
%nonassoc UMINUS

%%

program:    
                declarations func_declarations {Trace("Reduce program OK!\n");}
            ;



func_declarations: 
                func_declaration func_declarations 
            |   
            ;
func_declaration:
                FUNC id_name '(' formal_arguments ')'  example
                { insert($<id_value.name>2,current_symtab,0,0);create(symtab_counter,current_symtab); current_symtab=symtab_counter;symtab_counter+=1;}     
            ;

example     :
                '-' '>' type '{' declarations statements '}'
                { if(current_symtab!=0) current_symtab=symtab_pre[current_symtab];}
                
            |   '{' declarations statements '}' 
                { if(current_symtab!=0) current_symtab=symtab_pre[current_symtab];}
            ;    
formal_arguments:
                id_name ':' type next_argument {insert($<id_value.name>1,current_symtab,$<type>3,0);}
            |
            ;
next_argument:
                ',' id_name ':' type next_argument {insert($<id_value.name>2,current_symtab,$<type>4,0);}
            |
            ;
statements:
                statement statements 
            |   
            ;
statement:
                expression
            |   simple_statement
            |   condition
            |   loop
            ;
simple_statement:
                id_name '=' expression {  if(check_in_scope($<id_value.name>1,current_symtab)==-1){yyerror("ERROR : id is not in scope");}
                                          else{
                                                int i;
                                                i=current_symtab;
                                                while(lookup($<id_value.name>1,i)==-1){i=symtab_pre[i];}
                                                $<id_value.type>1=get_type($<id_value.name>1,i);
                                                if( ($<id_value.type>1==$<value.type>3) || ($<type>1==2 && $<value.type>3==1))
                                                    {
                                                        update_value($<id_value.name>1,i,$<value.fval>3);
                                                        printf("Update %s = %g\n",$<id_value.name>1,$<value.fval>3);
                                                    }
                                                else{ yyerror("ERROR : id assignment type error"); printf("%d=%d\n",$<id_value.type>1,$<value.type>3);}
                                            }
                                        }
            |   id_name '[' integer ']' '=' expression {if(check_in_scope($<id_value.name>1,current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
            |   RETURN expression
            |   RETURN
            |   func_invocation
            |   id_name '=' func_invocation {if(check_in_scope($<id_value.name>1,current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
            ;
expression:
                expression '+' expression {$$=$1; $<value.fval>$ = $<value.fval>1+$<value.fval>3;}
            |   expression '-' expression {$$=$1; $<value.fval>$ = $<value.fval>1-$<value.fval>3;}
            |   expression '*' expression {$$=$1; $<value.fval>$ = $<value.fval>1*$<value.fval>3;}
            |   expression '/' expression {$$=$1; $<value.fval>$ = $<value.fval>1/$<value.fval>3;}
            |   expression '%' expression {$$=$1; $<value.fval>$ = (int)$<value.fval>1%(int)$<value.fval>3;}
            |   expression '^' expression {}
            |   '-' expression    %prec UMINUS {$$=$2; $<value.fval>$=-$<value.fval>2;}
            |   '(' expression ')' {}
            |   id_name {   if(check_in_scope($<id_value.name>1,current_symtab)==-1){yyerror("ERROR : id is not in scope");}
                            else{
                                int i;
                                i=current_symtab;
                                while(lookup($<id_value.name>1,i)==-1){i=symtab_pre[i];}
                                $<value.fval>$=get_value($<id_value.name>1,i); $<value.type>$=get_type($<id_value.name>1,i);
                                }
                         }
            |   constant_exp
            ;
func_invocation:
                id_name '(' expression more_expression ')' {if(check_in_scope($<id_value.name>1,current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
            |   id_name '(' ')' {if(check_in_scope($<id_value.name>1,current_symtab)==-1){yyerror("ERROR : id is not in scope");}}
            ;
more_expression:
                ',' expression more_expression
            |
            ;
bool_exps:      
                '(' bool_exps ')'
            |   bool_exps '&&' bool_exps
            |   bool_exps '||' bool_exps
            |   '!' bool_exps
            |   bool_exp
            ;
bool_exp:
                expression '||' expression {}
            |   expression '&&' expression {}
            |   '!' expression            {}
            |   expression E expression   {}
            |   expression GE expression  {}
            |   expression SE expression  {}
            |   expression NE expression  {}
            |   expression'>' expression {}
            |   expression'<' expression {}
            ;


//variable's declaration

declarations:   
                declaration declarations 
            | 
            ;
declaration:
                var_declaration
            |   const_declaration
            |   array_declaration
            ;
var_declaration:
                LET MUT id_name '=' constant_exp 
                {insert($<id_value.name>3,current_symtab,$<type>5,$<value.fval>5);}
            
            |   LET MUT id_name ';' 
                {insert($<id_value.name>3,current_symtab,0,0);}
            
            |   LET MUT id_name ':' type  
                { insert($<id_value.name>3,current_symtab,$<type>5,0); }
            
            |   LET MUT id_name ':' type '=' constant_exp { 
                if( ($<type>5==$<value.type>7) || ($<type>5==2 && $<value.type>7==1))
                {
                insert($<id_value.name>3,current_symtab,$<type>5,$<value.fval>7);} 
                else{yyerror("ERROR : Var declaration type checking fail");}
                }
            ;
const_declaration:
                LET id_name '=' constant_exp 
                {insert($<id_value.name>2,current_symtab,$<type>4,$<value.fval>4);}
            
            |   LET id_name 
                {insert($<id_value.name>2,current_symtab,0,0);}
            
            |   LET id_name ':' type  
                { insert($<id_value.name>2,current_symtab,$<type>4,0); }
            
            |   LET id_name ':' type '=' constant_exp { 
                if( ($<type>4==$<value.type>6) || ($<type>4==2 && $<value.type>6==1))
                {
                insert($<id_value.name>2,current_symtab,$<type>4,$<value.fval>6);} 
                else{yyerror("ERROR : Var declaration type checking fail");}
                }
array_declaration:
                 LET MUT id_name '[' type ',' integer ']'

            ;
constant_exp:
                string  
            |   integer 
            |   float_  
            |   TRUE  {}
            |   FALSE {}
            ;
type:
                STRING    {$<type>$=3;}
            |   INTEGER   {$<type>$=1;}
            |   FLOAT      {$<type>$=2;}
            |   BOOL      {}
            ;

//condition   and   loop and compound and procedure

compound:   
                '{' 
                { create(symtab_counter,current_symtab); current_symtab=symtab_counter; symtab_counter+=1;} 
                declarations statements '}'
                { if(current_symtab!=0) current_symtab=symtab_pre[current_symtab];}
            ;
simple_or_compound:
                compound
            |   simple_statement
            ;
condition:
                IF '(' bool_exps ')' simple_or_compound ELSE simple_or_compound
            |   IF '(' bool_exps ')' simple_or_compound 
            ;
loop:
                WHILE '(' bool_exps ')' simple_or_compound 
            ;



%%


//symbol tables                  ------------

struct node{
    int index;
    char id[256];
    int type;
    float fval;
    struct node* next;
};

void create(int tab_num, int pretab_num){
    id_num[tab_num]=0;
    symtab_pre[tab_num]=pretab_num;
    for (int i=0;i<46;i++){
        ids[tab_num][i]=NULL;
    }
}

int lookup(char *input, int tab_num){
    int alphabet;
    if(input[0]<='Z')
    alphabet=input[0]-'A';
    else
    alphabet=input[0]-'a'+23;

    if(ids[tab_num][alphabet]!=NULL){
        struct node *temp=ids[tab_num][alphabet];
        while(temp!=NULL){
            if(strcmp(temp->id,input)==0){
                return temp->index;
            }
            temp=temp->next;
        }
    }
    return -1;
}

int insert(char *input,int tab_num,int type,float value){
    if(lookup(input,tab_num)!=-1){
        return -1;
    }

    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *new_node;
    new_node = (struct node*) malloc(sizeof(struct node));
    strcpy(new_node->id,input);
    id_num[tab_num]+=1;
    new_node->index=id_num[tab_num];
    new_node->type=type;
    new_node->fval=value;
    new_node->next=NULL;

    if(ids[tab_num][alphabet]==NULL){
        ids[tab_num][alphabet]=new_node;
    }
    else{
        struct node *temp=ids[tab_num][alphabet];
        while(temp->next!=NULL){
            temp=temp->next;
        }
        temp->next=new_node;
    }
    
    return id_num[tab_num];
}

void dump(int tab_num){
    for(int i=0;i<46;i++){
        if(ids[tab_num][i]!=NULL){
            struct node *temp=ids[tab_num][i];
            do{
                if(temp->type==1){
                printf("index:%d , id:%s , type:int  , value:%g\n",temp->index,temp->id,temp->fval);
                }
                else if(temp->type==2){
                printf("index:%d , id:%s , type:float, value:%g\n",temp->index,temp->id,temp->fval);
                }
                else if(temp->type==3){
                printf("index:%d , id:%s , type:string, value:%g\n",temp->index,temp->id,temp->fval);
                }
                temp=temp->next;
                }while(temp!=NULL);
        }
    }
}

void update_value(char *input,int tab_num,float the_val){
    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *temp=ids[tab_num][alphabet];
    while(temp!=NULL){
        if(strcmp(temp->id,input)==0){
            temp->fval=the_val;
            return;
        }
        temp=temp->next;
    }
}

float get_value(char *input,int tab_num){
    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *temp=ids[tab_num][alphabet];
    while(temp!=NULL){
        if(strcmp(temp->id,input)==0){
            return temp->fval;
        }
        temp=temp->next;
    }
    return -1;
}


int get_type(char *input,int tab_num){
    int alphabet;
    if(input[0]<='Z')
        alphabet=input[0]-'A';
    else
        alphabet=input[0]-'a'+23;

    struct node *temp=ids[tab_num][alphabet];
    while(temp!=NULL){
        if(strcmp(temp->id,input)==0){
            return temp->type;
        }
        temp=temp->next;
    }
    return -1;
}

int check_in_scope(char *input,int tab_num){
    int tab;
    tab=tab_num;
    while(lookup(input,tab)==-1 && tab!=0){
        tab=symtab_pre[tab];
    }
    if(lookup(input,tab)==-1)
    return -1;
    else
    return 1;
}


//          symtab  end          ------------

int yyerror(const char *s)
{
 fprintf(stderr, "%s in Line\n", s);
 return 0;
}

int main()
{   
    //initial all symbol_table
    for(int w=0;w<100;w++){
    id_num[w]=-1;
    symtab_pre[w]=-1;
    }

    //create global symbol_table0
    current_symtab=0;
    symtab_counter=1;
    create(0,-1);

    /* perform parsing */
    yyparse();                 /* parsing */
        
    //dump all symbol table and layers of scope
    for(int q=0;q<symtab_counter;q++){
        printf("Symbol_table %d : (",q);
        for(int p=q;p!=0;p=symtab_pre[p]){
            printf("%d<-",p);
        }
        printf("0)\n");
        dump(q);
    }

    return 0;
}