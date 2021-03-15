#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>


#define N 1000 //用于统计的坐标点数

int main() {

	double rand_Gaussian(int, double);
	double rand_Fermi_Dirac(int);

	double rand_num;
	double test[N];
	int x[N];
	int i,j,t;
	
	FILE *file_numbers, *file_static;

	srand((unsigned)time(NULL));
	
	file_numbers = fopen("./numbers.txt", "w");
	file_static = fopen("./static.txt", "w");

	for (i = 0; i < N; i++) {
		x[i] = 0;
	}

	/*统计0-1间, 精度为10^-7的1000000个数, 的分布, 统计的间隔数(坐标点)为1000*/
	for ( t = 0; t < 1000000; t++) {
		//rand_num = rand_Gaussian(7,0.3);
		//i = (rand_num +1) * 10000 / (20000 / N);
		rand_num = rand_Fermi_Dirac(7);
		i = rand_num * 10000 / (20000 / N);
		x[i]++;
		fprintf(file_numbers, "%d\t%f\n", i, rand_num);
		if (t % 100000 < 1)
			printf("%d\n",t);
	}

	for (i = 0; i < N; i++) {
		fprintf(file_static, "%d\t%d\n", i, x[i]);
	}

	fclose(file_numbers);
	fclose(file_static);

}

/* 返回-1 ~ 1, 精度为preci, 半高宽为W的高斯分布的随机数*/
/* 精度最好远大于统计的间隔数 */
double rand_Gaussian(int preci, double W){
	double randd();

	double randx =  randd(0, preci);
	double randy =  randd(0, preci);

	double f = exp(-randx * randx / W / W * 4 * log(2));

	if (randy < f)
		return rand() % 10000 > 5000 ? randx : -randx;
	else
		rand_Gaussian(preci, W);
}

/* 返回-1 ~ 1, 精度为preci, 半高宽为W的高斯分布的随机数*/
double rand_Fermi_Dirac(int preci){
	double randd();

	double randx =  randd(0, preci);
	double randy =  randd(0, preci);

	double f = 1.0 / (exp((randx - 0.5)/0.05) + 1.0);

	return randy < f ? randx : rand_Fermi_Dirac(preci);
}

/* 返回0 ~ 10^n以内，小数点后m位的随机数 */
double randd(int n, int m) {
	return rand()%(int)(pow(10, n+m))/pow(10, m);
}

