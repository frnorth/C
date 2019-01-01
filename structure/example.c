
#include"example.h"

int main(){
	LB l1={1.1,NULL};
	LB l0={1.0,&l1};
	printf("%lf\n",(*(l0.ptr)).data);
	return 0;
}
