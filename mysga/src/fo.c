
#include"global_conf.h"

double fitness_cal(double * c_variable) {

	double x = c_variable[0];
	double y = c_variable[1];
	double fitness =0;
	fitness= 0.5 - (pow(sin(pow(x * x + y*y, 0.5)), 2.0)-0.5)/ pow(1.0 + 0.001*(x*x+y*y), 2.0);
	return fitness;


//	char *fo_path = NULL;//argv[1];
//	if (argc < 2)
//		fo_path = get_current_dir_name();
//	int path_length=strlen(fo_path);
//	int i=0;
//
//	char hahac[100];
//	char list_path[100];
//	for (i=0;i<path_length-3;i++){
//		list_path[i]=fo_path[i];
//	}
//	list_path[length-3]='/';
//	list_path[length-2]='l';
//	list_path[length-1]='i';
//	list_path[length]='s';
//	list_path[length+1]='t';
//
//	FILE *fo; 
//	fo = fopen(list_path, "r"); 
//
//	int list_length=0;
//	/* fscanf will scan one raw twice? */
//	fscanf(fo, "%5s%d", hahac, &list_length); 
//	printf("%s\t%d\n", hahac, list_length); 
//
//	double list_x=(double *)malloc(sizeof(double)*list_length); 
//	double list_y=(double *)malloc(sizeof(double)*list_length); 


//	double a=c_variable[0];
//
//	double list_y[100]={1,1,2,3,1,
//						3,2,8,1,2,
//						3,2,8,2,1,
//						7,9,2,1,2};
//
//	double fitness=0,avg=0;
//
//	int i=0;
//	for (i=0;i<20;i++){
//		avg+=list_y[i]/20;
//		fitness+=pow((list_y[i]-a),2.0);
//	}
//
//	printf("%10lf",avg);
//
//	return 1/fitness;















}
