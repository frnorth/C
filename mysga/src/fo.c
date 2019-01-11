
#include"global_conf.h"

double fitness_cal(double * c_variable) {

	double x = c_variable[0];
	double y = c_variable[1];
	double fitness =0;
	fitness= 0.5 - (pow(sin(pow(x * x + y*y, 0.5)), 2.0)-0.5)/ pow(1.0 + 0.001*(x*x+y*y), 2.0);
	return fitness;


//	FILE *fsga; 
//	fsga = fopen(, "r"); 
//
//	/* fscanf will scan one raw twice? */
//	fscanf(fsga, "%8s%d", hahac, &hahad); 
//	pop_size = hahad; 
//	printf("%s\t%d\n", hahac, pop_size); 
//
//	fscanf(fsga, "%14s%d", hahac, &hahad); 
//	generation_num = hahad; 

}
