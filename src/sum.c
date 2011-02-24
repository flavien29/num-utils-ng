# include <stdlib.h>
# include <stdio.h>

double sum (FILE*);
int fileIsEmpty(FILE*);
int typeIsWrong(FILE*);
	

double sum ( FILE* fichier){		//this function calculates the sum of numbers from a file or stdin.
	double sum=0;
	double number=0;
	while (!feof(fichier)){
		sum = sum + number ;					
		fscanf (fichier,"%d",&number);
	}
return sum;
}

int fileTest(FILE* fichier){		//this function triggers every tests on the file.
    if (fileIsEmpty(fichier)){
      fprintf(stderr,"The file is empty \n");
      return 1;	
    }
    if (typeIsWrong(stream)){
      fprintf(stderr,"the type of the file is wrong \n");
      return 1;
    }
    return 0;
}


int fileIsEmpty(FILE*){			//this function tests if the file is empty.
  long position;
  fseek(fichier, 0L, SEEK_END);
  position=ftell(fichier);
  rewind(fichier);
  if (position==0)
    return 1;
  else 
    return 0;
}

int typeIsWrong(FILE*){			//this function tests if there is letters in the file.
	char c ;
	while (!feof(fichier)){
		fscanf ( fichier, "%c", c );
		if ( (d>57) || ((d<48) && (d>32) && (d!=46)))
			return 1 ;
	}
	rewind (fichier);
	return 0;
}

int main(){
FILE* file = NULL
int opt;
	
if((opt=getopt(argc,argv,"iI"))!=-1){
	switch(opt) {

	case 'i':			// option "-i" (integer portion of the final sum)
	if (argv[optind]!=NULL){
        	file = fopen(argv[optind], "r");
        	if (fileTest(file))
          	return 0;
        	fprintf(stderr,"The integer portion of the sum is %d \n",(int)sum(fichier));
        	fclose(tab);
        	}
	else 
        printf("The integer portion of the sum is %d \n",sum(stdin));
	return 0;
	break;

	case 'I':			//option "-I" (decimal portion of the final sum)
	if (argv[optind]!=NULL){
        	file = fopen(argv[optind], "r");
        	if (fileTest(file))
          		return 0;
        	fprintf(stderr,"The decimal portion of the sym is %lf \n",sum(file) - (int)sum(file));
        fclose(tab);
        }
	else {
        	printf("The decimal portion of the average number is %lf \n",sum(stdin) - (int)sum(stdin));
	}
	return 0;
	break;

	case '?':				//option fail.
	printf("optionfail\n");
	return 0;
	break;
	}
}

	



				
	