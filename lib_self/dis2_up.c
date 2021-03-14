#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<time.h>


#define N 1000
#define M 12

int main() {

	double randd(int,int);
	double rand_gaosi(int,double);
	double rand_num;
	int x[N];
	int i,j,t;
	
	FILE *file, *file2;

	srand((unsigned)time(NULL));
	
	file = fopen("/home/wangjie/test/C/xes1/dis/result.txt", "w");
	file2 = fopen("/home/wangjie/test/C/xes1/dis/result2.txt", "w");

	for (i = 0; i < N; i++) {
		x[i] = 0;
	}

	/*统计0-1000间的数的个数*/
	for ( t = 0; t < 1000000; t++) {
		rand_num = rand_gaosi(7,0.3); // 精度为4的时候会有奇怪的事情，在分布右侧会有固定的形状, 4变大，如变成7，会正常
		i =  (rand_num +1)*10000 / (20000 / N);
		x[i]++;
		fprintf(file2, "%d\t%f\n", i, rand_num);
	}

	for (i = 0; i < N; i++) {
		fprintf(file, "%d\t%d\n", i, x[i]);
	}

	fclose(file);

}
double rand_gaosi(int preci, double W){
/* 产生-1 ~ 1, 精度为preci, 半高宽为W的高斯分布的随机数*/
/* 精度最好远大于统计的间隔数 */
	double randd();
	double randx =  randd(0, preci);
	double randy =  randd(0, preci);
	double f = exp(-randx * randx / W / W * 4 * log(2));
	if (randy < f)
		return rand() % 1000 > 500 ? randx : -randx;
	else
		rand_gaosi(preci, W);
}

double randd(int n, int m) {
	return rand()%(int)(pow(10, n+m))/pow(10, m);
}

