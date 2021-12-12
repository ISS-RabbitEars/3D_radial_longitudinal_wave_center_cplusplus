#include <iostream>
#include <fstream>
#include "ran3.h"
#include "vec.hpp"
using namespace std;

#define MBIG 1000000000
#define MSEED 161803398
#define MZ 0
#define FAC (1.0/MBIG)
#define PI 3.141592653589793238462643383





double s(vec&, double&, double&, double&, double&, double&);
double gamma(double, vec&);
vec rdt(double, vec&);
vec psi(vec&, double, vec*, double, double, double, double, double);




int main()
{
    int N=100000;
    int Ne=1;
    vec rp[N],rpdt[N],rc[Ne],r;
    int seed=-931215423;
    double xa,ya,za,edge;
    double t,sigma,k,omega,phi;
    double lambda,nlambda,ncycles;
    double delt,nframes;
    ofstream file;

    /* initialize parameters */
    /*xa=3./2.;
    ya=9./8.;*/
    xa=1.0;
    ya=1.0;
    za=1.0;
    /*edge=1.2;*/
    edge=1.;
    nlambda=2.5;
    ncycles=5;
    lambda=xa/nlambda;
    nframes=210;
    delt=ncycles*2.*PI/nframes;
    t=0;
    sigma=0.1;
    k=2*PI/lambda;
    omega=1;
    phi=0;
    
    /* initialize emitter coordinates */
    /*r(xa,ya);*/
    rc[0](-xa,0,0);
    /*rc[1](-xa,-2*lambda,0);*/
    /*for(int i=1;i<Ne;i+=2)
    {
        rc[i]((i+1)*lambda,0,0);
        rc[i+1](-(i+1)*lambda,0,0);
    }*/

    /* initialize array of points */
    for(int i=0;i<N;i++)
	{
        rp[i](edge*xa*(2.*ran3(&seed)-1.),edge*ya*(2.*ran3(&seed)-1),edge*za*(2.*ran3(&seed)-1));
        rpdt[i]();
	}
    
    /* integrate */
    file.open("points.dat");
    for(int i=0;i<nframes;i++)
    {
        for(int j=0;j<N;j++)
        {
            t=i*delt;
            rpdt[j]=psi(rp[j],Ne,rc,t,sigma,k,omega,phi);
            file<<"<"<<rpdt[j].x<<", "<<rpdt[j].y<<", "<<rpdt[j].z<<">";
            if(j<N-1) file<<",";
            file<<endl;
        }
    }
	file.close();
	
    return 0;
}




double s(vec& r, double& t, double& sigma, double& k, double& omega, double& phi)
{
    return(2.0*PI*sigma/k)*cos((k*r.norm())-(omega*t)+phi);
}

double gamma(double s, vec& r)
{
    return((s/r.norm())+1.);
}

vec rdt(double gamma, vec& r)
{
    return(gamma*r);
}

vec psi(vec& rp, double N, vec* rc, double t, double sigma, double k, double omega, double phi)
{
    vec r,rsum;
    rsum();
    for(int i=0;i<N;i++)
    {
        r();
        r=rp-rc[i];
        rsum+=(rdt(gamma(s(r,t,sigma,k,omega,phi),r),r)+rc[i]);
    }
    rsum-=((N-1)*rp);
    return(rsum);
}






/*--------------------------------------------------------------------------*/
float ran3(int *idum)
//int *idum;
{
	static int inext,inextp;
	static long ma[56];
	static int iff=0;
	long mj,mk;
	int i,ii,k;

	if (*idum < 0 || iff == 0) {
		iff=1;
		mj=MSEED-(*idum < 0 ? -*idum : *idum);
		mj %= MBIG;
		ma[55]=mj;
		mk=1;
		for (i=1;i<=54;i++) {
			ii=(21*i) % 55;
			ma[ii]=mk;
			mk=mj-mk;
			if (mk < MZ) mk += MBIG;
			mj=ma[ii];
		}
		for (k=1;k<=4;k++)
			for (i=1;i<=55;i++) {
				ma[i] -= ma[1+(i+30) % 55];
				if (ma[i] < MZ) ma[i] += MBIG;
			}
		inext=0;
		inextp=31;
		*idum=1;
	}
	if (++inext == 56) inext=1;
	if (++inextp == 56) inextp=1;
	mj=ma[inext]-ma[inextp];
	if (mj < MZ) mj += MBIG;
	ma[inext]=mj;
	return mj*FAC;
}

#undef PI
#undef MBIG
#undef MSEED
#undef MZ
#undef FAC

