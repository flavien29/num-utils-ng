/**
*
*
* ***** BEGIN GPL LICENSE BLOCK *****
*
* This file is part of num-utils-nv project
*
* This program is free software; you can redistribute it and/or
* modify it under the terms of the GNU General Public License
* as published by the Free Software Foundation; either version 3
* of the License, or (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program If not, see <http://www.gnu.org/licenses/>.
*
* The Original Code is Copyright (C) 2011 by num-utils-nv project.
* All rights reserved.
*
* The Original Code is: all of this file.
*
* Contributor(s): none yet.
*
* ***** END GPL LICENSE BLOCK *****
*/



#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

int numgrep(FILE* stream, char* expression){
  int numberRead,number1,number2;
  int mode,count=0;
  int i,j;
  char *token;
  char *savestr;
  char *str;
  char **tab=NULL;

  for (i=0;i<strlen(expression);i++){
    switch(expression[i])
    {
      case '/':
        expression[i]=',';
	break;
      case '.':
	mode=3;
	break;
      case '0':
      case '1':
      case '2':
      case '3':
      case '4':
      case '5':
      case '6':
      case '7':
      case '8':
      case '9':
        break;
      case 'f':                
        mode=1;
	break;
      case 'm':
        mode=2;  
        break;
      case ',':
        count++;
        break;
      default:
        return 0;
    }
  }
  tab =(char **)calloc(count+1,sizeof(char*));
  for (i=0,str=expression;;i++,str=NULL) {
    token=strtok_r(str,",", &savestr);
    if (token == NULL)
      break;
    *(tab+i)=token;
  }

  while(fscanf(stream,"%d",&numberRead)!=EOF ){
    for(i=0;i<=count;i++){

      if(strstr(*(tab+i),"f")!=NULL){
        sscanf(*(tab+i),"f%d",&number1);
        if((number1>=numberRead)&&(number1%numberRead==0))
          printf( "%d\n",numberRead);
      }

      else if(strstr(*(tab+i),"m")!=NULL){
        sscanf(*(tab+i),"m%d",&number1);
        if((numberRead>=number1)&&(numberRead%number1==0))
          printf( "%d\n",numberRead);
      }

      else if(strstr(*(tab+i),"..")!=NULL){
        sscanf(*(tab+i),"%d..%d",&number1,&number2);
        if(number1<number2){
          for(j=number1;j<=number2;j++){
            if(numberRead==j)
              printf( "%d\n",numberRead);
          }
        }
      }

      else{
        sscanf(*(tab+i),"%d",&number1);
        if(numberRead==number1)
         printf( "%d\n",numberRead);
      }
    }
  }
  free(tab);
  return 0;
}


int main(int argc,char *argv[]){
  FILE* stream=NULL;
  if(argv[1][0]!='/'){
    perror("The expression is wrong\n");
    return 2;
  }
  if(argc==2)
    numgrep(stdin,argv[1]);
  else{
    stream=fopen(argv[2],"r");
    if(!stream){
      perror("the file can't be opened, see \"errno\" for more informations");
      return 1;
    }
  numgrep(stream,argv[1]);
  fclose(stream);
  }
  return 0;
}
