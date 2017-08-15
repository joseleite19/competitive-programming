#include <stdio.h>
#include <bits/stdc++.h>
 
long long t1[100100];
long long pre[100100];
long long f1 = 0;
 
long long fim[100100];
 
long long t2[100100];
long long p2[100100];
double r2[100100];
double cum_a[100100];
double cum_x[100100];
long long f2 = 0;
 
int main () {
 
    long long n;
    scanf("%lld", &n);
 
    long long temp = 0;
    for (long long i = 0; i < 2 * n; i++) {
        char c;
        long long a;
        scanf(" %c %lld", &c, &a);
        if (c == '+') {
            temp++;
            pre[f1] = f2 - 1;
            t1[f1++] = a;
        } else {
            p2[f2] = temp;
            t2[f2++] = a;
            temp--;
        }
    }
 
    r2[0] = 1.0;
 
    for (long long i = 0; i < n; i++) {
        cum_a[i] = t2[i] * r2[i] / p2[i];
        cum_x[i] = - r2[i] / p2[i];
 
	if (p2[i] > 1)
		r2[i + 1] = r2[i] * (1 - ((double)1.0)/p2[i]);
	else
		r2[i + 1] = 1.0;
    }
    long long j = 0;
    long long i = 1;
    
    t2[n] = 2e9;
    r2[n] = 1.0;
    
    while (j < n) {
	    //printf("%d %d\n", i, j);
	    //printf("%lf %d %d\n", r2[i], t2[i - 1], t1[j]);
	while (i < n && fabs(r2[i] - 1.0) >= 1e-6) i++;
	while (j < n && t1[j] < t2[i-1]) {
		fim[j++] = i - 1;
	}
	i++;
    }
    for (long long i = 1; i < n; i++) {
        cum_a[i] += cum_a[i - 1];
        cum_x[i] += cum_x[i - 1];
    }
    //for (long long i = 0; i < n; i++) {
    //    printf("%lf %lf, %d, %lf\n", cum_a[i] -(i ? cum_a[i-1] : 0), cum_x[i] -(i ? cum_x[i-1] : 0), p2[i], r2[i]);
    //}
 
    for (long long i = 0; i < n; i++) {
        double c = cum_a[fim[i]];
        double x = cum_x[fim[i]];
        if (pre[i] > -1) {
            c -= cum_a[pre[i]];
            x -= cum_x[pre[i]];
            c /= r2[pre[i] + 1];
            x /= r2[pre[i] + 1];
        }
        printf("%.20lf\n", c + t1[i] * x);
    } 
 
 
    return 0;
 
}