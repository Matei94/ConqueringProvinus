/*   Matei Razvan Madalin     */
/*   313 CA                   */

#include<stdio.h>
#include<math.h>

double min(double a, double b, double c) {
	double minim;
	if(a<b) minim=a;
	else minim=b;
	if(c<minim) minim=c;
	return minim; 
}

int main() {
	double v1x, v2x, v3x, v1y, v2y, v3y;
	double px, py;
	double det1, det2, det3;
	double d12, d13, d23;
	int N;
	int i, ok;
	double eps=0.0001;
	int bingo;
	
	do {
	
		bingo=scanf("(%lf,%lf) (%lf,%lf) (%lf,%lf)", &v1x, &v1y, &v2x, &v2y, &v3x, &v3y);
	
		if(bingo<6) {
			printf("\n");
			return 0;
		}
		
		if(( (px==v1x)&&(py==v1y) )||
	      ( (px==v2x)&&(py==v2y) )||
	      ( (px==v3x)&&(py==v3y) )) {
	   	ok=1;
		}
		else {
	
			if( fabs( (v3x-v1x)*(v2y-v1y)-(v3y-v1y)*(v2x-v1x)  ) <= eps ) {
				printf("SATELLITE COMPUTATION ERROR!\n");
				scanf("%d ", &N);
				for(i=0; i<N; i++) {
					scanf("(%lf,%lf) ", &px, &py);
				}
			}
		
			else {
				scanf("%d ", &N);
				printf("%d ", N);
				for(i=0; i<N; i++) {
					scanf("(%lf,%lf) ", &px, &py);
					
					if(( (px==v1x)&&(py==v1y) )||
				   	( (px==v2x)&&(py==v2y) )||
				  	   ( (px==v3x)&&(py==v3y) )) {
				   	ok=1;
					}
					else {
				
						det1 = v1x*v2y - v2x*v1y + v2x*py - px*v2y + px*v1y - v1x*py;
						det2 = v2x*v3y - v3x*v2y + v3x*py - px*v3y + px*v2y - v2x*py;
						det3 = v3x*v1y - v1x*v3y + v1x*py - px*v1y + px*v3y - v3x*py;
				
						if( (det1>0 && det2>0 && det3>0) || 
							 (det1<0 && det2<0 && det3<0) || 
							 (det1==0 && det2==0 && det3==0) ) {
							ok=1;
						}
				
						else {
							ok=0;
						}
					}
					
					if(ok==0) {
						printf("(NO) ");
					}
				
					if(ok==1) {
				
						d12=(fabs ( (v2y-v1y)*px + (v1x - v2x)*py +v2x*v1y - v1x*v2y ) ) / 
							sqrt( (v2y-v1y)*(v2y-v1y) +(v1x - v2x)*(v1x - v2x) );
						d13=(fabs ( (v3y-v1y)*px + (v1x - v3x)*py +v3x*v1y - v1x*v3y ) ) / 
							sqrt( (v3y-v1y)*(v3y-v1y) +(v1x - v3x)*(v1x - v3x) );
						d23=(fabs ( (v3y-v2y)*px + (v2x - v3x)*py +v3x*v2y - v2x*v3y ) ) / 
							sqrt( (v3y-v2y)*(v3y-v2y) +(v2x - v3x)*(v2x - v3x) );
						
						printf("(YES,%.2lf) ", min(d12, d13, d23));
					}
				} }
				printf("\n");
			} 
	
		} while(1);
	
		
	return 0;
}
