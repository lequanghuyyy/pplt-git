#include <stdio.h>
#include <math.h>
#include <string.h>
#define PI 3.1415926535
float tinhbanhchung(int dc)
{
	float chung = pow(dc,2)*sqrt(dc);
	return chung;
} 
float tinhbanhgiay(int dg)
{
	float giay = pow(dg,2)*PI/3;
	return giay;
}
int is_fibonacci(int n) {
  if (n < 0) {
    return 0;
  }
  if (n == 0 || n == 1) {
    return 1;
  }
  int f_n_1 = 0;
  int f_n_2 = 1;
  for (int i = 2; i <= n; i++) {
    int f_n = f_n_1 + f_n_2;
    if (f_n == n) {
      return 1;
    }
    f_n_1 = f_n_2;
    f_n_2 = f_n;
  }
  return 0;
}
int sobanbe(int n,int ld)
{int sum1=0;
int sum2=0;
	for(int i = 1;i<n;i++)
	{
		if(n%i==0) sum1=sum1+i;
	}
	for(int i = 1;i<ld;i++)
	{
		if(ld%i==0) sum2=sum2+i;
	}
	if(sum1==ld&&sum2==n)
	{
		return 1;
	}
	return 0;
}
float tinhchungtruoc(float n,int dc,int dg,int ld)
{
	int bc = n/tinhbanhchung(dc);
	int bg = (n-bc*tinhbanhchung(dc))/tinhbanhgiay(dg);
	 float ndchungtruoc = n - bc*tinhbanhchung(dc) - bg*tinhbanhgiay(dg);
	return ndchungtruoc;
}
float tinhgiaytruoc(float n,int dc,int dg,int ld)
{
	int bg = n/tinhbanhgiay(dg);
	 int bc = (n-bg*tinhbanhgiay(dg))/tinhbanhchung(dc);
	 float ndgiaytruoc = (float)(n - (float)(bc*tinhbanhchung(dc)) - (float)(bg*tinhbanhgiay(dg)));
	return ndgiaytruoc;
}
int main()
{
	int n, dc, dg, ld;
    char w[100];
    int bc=0 , bg=0 ;
    float nd;
    FILE *input = fopen("input.text", "r");
    if (input == NULL) {
        printf("Loi khi mo file input.text\n");
        return 1;
    }
    fscanf(input, "%d %d %d %d %s", &n, &dc, &dg, &ld, w);
    fclose(input);
    if(n>2000||n<0||ld<0||ld>600||(dc==0&&dg==0))
	{
		bc=-1;
		bg=-1;
		nd=n;
	 FILE *output = fopen("output.out", "w");
    if (output == NULL) {
        printf("Loi khi mo file output.out\n");
        return 1;
    }

    fprintf(output, "%d %d %.3f\n", bc, bg, nd);
    fclose(output);
    return 0;
	 } 
    if(strcmp(w, "Fog") == 0)
	{
	 if(is_fibonacci(dc)&&is_fibonacci(dg))
	 {
	 	dc=dc/2;
	 	dg=dg/2;
	 }
	 else {
	 	dc=dc*2;
	 	dg=dg*2;
	 }
}
   int lddc = (dc>=8) ? 2 : 1;
   int lddg = (dg>=5) ? 2 : 1;
   	float nep1banhchung = tinhbanhchung(dc);
	float nep1banhgiay = tinhbanhgiay(dg);
if (strcmp(w, "Wind") == 0)
	{ x : 
	 int bc1=n/nep1banhchung;
     int bc2=ld/lddc;
     int bc4=ld/lddg;
     int bc3=n/nep1banhgiay;
     if(dc==0)
     {
     	bg = (bc3>bc4) ? bc4 : bc3;
     	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	 }
	 if(dg==0)
	 {
	 	bc = (bc1>bc2) ? bc2 : bc1;
	 	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	 }
	if(bc1>bc2&&bc3>bc2&&bc2==bc4)
	{
		int a = (nep1banhchung>nep1banhgiay) ? ld/lddc : ld/lddg;
		int b = (ld-a*lddc) / lddc;
		if(nep1banhchung>nep1banhgiay)
		{
			bc = a;
			bg = b;
		}
		else
		{
			bg = a;
			bc = b;
		}
		nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	 }
    else if(nep1banhchung<nep1banhgiay&&bc2>=bc4)
    {
    	if(bc3>bc2)
    	{
    		bc = bc2;
    		bg = ((n-bc*nep1banhchung)/nep1banhgiay>(ld-bc*lddc)/lddg) ? (ld-bc*lddc)/lddg : (n-bc*nep1banhchung)/nep1banhgiay;
    		nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
		}
		if(bc3<bc2)
    	{
		bg = bc3;
        bc = ((n-bg*nep1banhgiay)/nep1banhchung>(ld-bg*lddg)/lddc) ? (ld-bg*lddg)/lddc : (n-bg*nep1banhgiay)/nep1banhchung;
    	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
    	}
	}
else if(nep1banhchung<nep1banhgiay&&bc2<bc4)
    {
    	if(bc3==bc4) 
	   { bc=bc3;
		int ldconlai=ld-bc*lddc;
		bg=ldconlai/lddg;
		nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
		}
    	 bg = (bc3>bc4) ? bc4 : bc3;
    	 bc = ((n-bg*nep1banhgiay)/nep1banhchung>(ld-bg*lddg)/lddc) ? (ld-bg*lddg)/lddc : (n-bg*nep1banhgiay)/nep1banhchung;
    	 nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));	
	}
else if(nep1banhchung>nep1banhgiay&&bc2<bc4)
	{
	  if(bc4<bc1)
	  {
	  	bc=bc1;
	  	bg = ((n-bc*nep1banhchung)/nep1banhgiay>(ld-bc*lddc)/lddg) ? (ld-bc*lddc)/lddg : (n-bc*nep1banhchung)/nep1banhgiay;
    	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	  }
	  if(bc4>bc1)
		{
			bg = bc4;
			bc = ((n-bg*nep1banhgiay)/nep1banhchung>(ld-bg*lddg)/lddc) ? (ld-bg*lddg)/lddc : (n-bg*nep1banhgiay)/nep1banhchung;
    	   nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
		}
	}
else if(nep1banhchung>nep1banhgiay&&bc2>=bc4)
	{ if(bc1==bc2) 
	 { bc=bc1;
		int ldconlai=ld-bc*lddc;
		bg=ldconlai/lddg;
		nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	 }
		bc = (bc1>bc2) ? bc2 : bc1;
		bg = ((n-bc*nep1banhchung)/nep1banhgiay>(ld-bc*lddc)/lddg) ? (ld-bc*lddc)/lddg : (n-bc*nep1banhchung)/nep1banhgiay;
    	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	}
goto e;
	}
if (strcmp(w, "Rain") == 0)
    { y : 
	float nd1 = n;
    int ldconlai=ld;
    if(nep1banhchung>nep1banhgiay)
    {
      do {
      if(nd1<nep1banhchung&&nd1<nep1banhgiay) break;
	  if(nd1>nep1banhchung)
		{
			if(ldconlai<lddc) break;
		  bc=bc+1;
     	 ldconlai = ldconlai - lddc;
     	 printf("ldconlai0 = \n",ldconlai);
     	if(ldconlai<0) break;
     	nd1 = nd1 - nep1banhchung;}
     	if(nd1>nep1banhgiay)
    	{
    		if(ldconlai<lddg) break;
		 bg=bg+1;
	    ldconlai = ldconlai - lddg;
	     printf("ldconlai1 = \n",ldconlai);
	    if(ldconlai<0) break;
	    nd1 = nd1 - nep1banhgiay;}
        }
    while(nd1>nep1banhchung||nd1>nep1banhgiay);
}
if(nep1banhchung<nep1banhgiay)
{
	do {
      if(nd1<nep1banhchung&&nd1<nep1banhgiay) break;
     	if(nd1>nep1banhgiay)
    	{
    		if(ldconlai<lddg) break;
		 bg=bg+1;
	    ldconlai = ldconlai - lddg;
	    if(ldconlai<0) break;
	    nd1 = nd1 - nep1banhgiay;}
	    if(nd1>nep1banhchung)
		{
			if(ldconlai<lddc) break;
		  bc=bc+1;
     	 ldconlai = ldconlai - lddc;
     	if(ldconlai<0) break;
     	nd1 = nd1 - nep1banhchung;}
        }
    while(nd1>nep1banhchung||nd1>nep1banhgiay);
}
     nd = nd1;
    printf("%d %d %.3f\n", bc, bg, nd);
     goto e;
	}
	if(strcmp(w, "Fog") == 0)
	{
	float ndchungtruoc = tinhchungtruoc(n,dc,dg,ld);
	float ndgiaytruoc = tinhgiaytruoc(n,dc,dg,ld);
	 nep1banhchung = tinhbanhchung(dc);
	 nep1banhgiay = tinhbanhgiay(dg);
	 int bc1=n/nep1banhchung;
     int bc2=ld/lddc;
     int bc4=ld/lddg;
     int bc3 = n/nep1banhgiay;
     int ldconlai1 = ld - lddc*bc1;
	 int ldconlai2 = ld - lddg*bc3;
     int nepconlai1 = n-bc1*nep1banhchung;
     int nepconlai2 = n-bc3*nep1banhgiay;
     if(dc==0)
     {
     	bc = 0;
     	bg = n/nep1banhgiay;
     	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	 }
	 if(dg==0)
	 {
	 	bg=0;
	 	bc=n/nep1banhchung;
	 	nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	 }
     if(bc1<=bc2&&bc3<=bc4&&nepconlai1/nep1banhgiay<=ldconlai1/lddg&&nepconlai2/nep1banhchung<=ldconlai2/lddc)
    {  if(ndchungtruoc<ndgiaytruoc)
      {
    	bc = n/tinhbanhchung(dc);
	  bg = (n-bc*tinhbanhchung(dc))/tinhbanhgiay(dg);
	  }
	  else 
	  {
	  	bg = n/tinhbanhgiay(dg);
	  bc = (n-bg*tinhbanhgiay(dg))/tinhbanhchung(dc);
	  }
      nd = (ndchungtruoc<ndgiaytruoc) ? ndchungtruoc : ndgiaytruoc ;
    	goto q;
	}
    if(bc3>bc2&&bc1<bc2)
    {
        bc = bc1;
        bg = (n-bc*nep1banhchung)/nep1banhgiay;
        nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
         goto q;
	}
	if(bc1>bc2&&bc3<bc2)
	{
		bg=bc3;
		bc=(n-bg*nep1banhgiay)/nep1banhchung;
		 nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
    	goto q;
	}
 q:
 	;
}
if(strcmp(w, "Sun")==0)
	{
		int G = dc % 6;
		int H = ld % 5;
		int X;
		if(G==H)
		{
			X=5;
		}
		else if(G-H==1) X=7;
		else if(G-H==2||H-G==4) X=10;
		else if(G-H==3||H-G==3) X=12;
		else if(G-H==4||H-G==2) X=15;
		else if(G-H==5||H-G==1) X=20;
	   else printf("Bang sai gia tri");
	   int giatri = (dc+dg)%3;
	   printf("%d\n",X);
	   n = n + n*X/100;
	   ld = ld - X;
	   printf("%d\n",ld);
	   if(giatri==0)
	   {
	   	goto y;
	   }
	   else if(giatri==1)
	   {
	   	goto x;
	   }
	   else if(giatri==2)
	   {
	   	goto z;
	   }
	   else printf("-----");
	}
if(strcmp(w,"Cloud")==0)
{z:
	int banbe=sobanbe(n,ld);
	if(banbe==1)
	{
		bc=0;
		bg=0;
		nd=n;
		goto e;
	}
	int bc1=n/nep1banhchung;
     int bc2=ld/lddc;
     int bc4=ld/lddg;
     int bc3 = n/nep1banhgiay;
    if(nep1banhchung>nep1banhgiay)
    {
    	 bc = (n/nep1banhchung>ld/lddc) ? ld/lddc : n/nep1banhchung;
    	 bg = ((n-bc*nep1banhchung)/nep1banhgiay>(ld-bc*lddc)/lddg) ? (ld-bc*lddc)/lddg : (n-bc*nep1banhchung)/nep1banhgiay;
    	  nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	}
	if(nep1banhchung<nep1banhgiay)
    {
	if(bc3<bc4)
    {
    	bg=bc3;
    	bc = ((n-bg*nep1banhgiay)/nep1banhchung>(ld-bg*lddg)/lddc) ? (ld-bg*lddg)/lddc : (n-bg*nep1banhgiay)/nep1banhchung;
		nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	}
    if(bc3>bc4)
    {
        bg=bc4;
        bc = ((n-bg*nep1banhgiay)/nep1banhchung>(ld-bg*lddg)/lddc) ? (ld-bg*lddg)/lddc : (n-bg*nep1banhgiay)/nep1banhchung;
        nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	}
	if(bc3==bc4)
	{
		bc=bc3-1;
		int ldconlai=ld-bc*lddc;
		bg=ldconlai/lddg;
		nd = (float)(n - (float)(bc*nep1banhchung) - (float)(bg*nep1banhgiay));
	}
}
}
e: 
printf("%d %d %.3f\n", bc, bg, nd);
	 FILE *output = fopen("output.out", "w");
    if (output == NULL) {
        printf("Loi khi mo file output.out\n");
        return 1;
    }
    fprintf(output, "%d %d %.3f\n", bc, bg, nd);
    fclose(output);
    return 0;
}