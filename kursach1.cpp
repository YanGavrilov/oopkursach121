#include<iostream>
#include<string>
using namespace std;
struct bio{
	string har1;
	string dr1;
	string hh1;
	string har2;
	string dr2;
	string hh2;
};
struct table{
	string al;
};
struct pov{
	string n;
	double k;
};
int main()
{ 
	bio p1,p2;
	cout<<"Enter the first characteristic of the first ancestor:";
	getline(cin,p1.har1);
	cout<<"Enter it's priority(Dominant/Reccessive):";
	getline(cin,p1.dr1);
	cout<<"Enter it's priority type(Heterozigot/Homozigot):";
	getline(cin,p1.hh1);
	cout<<"Enter the second characteristic of the first ancestor:";
	getline(cin,p1.har2);
	cout<<"Enter it's priority(Dominant/Reccessive):";
	getline(cin,p1.dr2);
	cout<<"Enter it's priority type(Heterozigot/Homozigot):";
	getline(cin,p1.hh2);
	cout<<"Enter the first characteristic of the second ancestor:";
	getline(cin,p2.har1);
	cout<<"Enter it's priority(Dominant/Reccessive):";
	getline(cin,p2.dr1);
	cout<<"Enter it's priority type(Heterozigot/Homozigot):";
	getline(cin,p2.hh1);
	cout<<"Enter the second characteristic of the second ancestor:";
	getline(cin,p2.har2);
	cout<<"Enter it's priority(Dominant/Reccessive):";
	getline(cin,p2.dr2);
	cout<<"Enter it's priority type(Heterozigot/Homozigot):";
	getline(cin,p2.hh2);
	table all[5][5];
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	all[i][j].al="";
	string pa1="";
	string pa2="";
	string dom="Dominant";
	string rec="Reccessive";
	string hom="Homozigot";
	string het="Heterozigot";
	if(rec.find(p1.dr1)!=-1)
	p1.hh1=hom;
	if(rec.find(p1.dr2)!=-1)
	p1.hh2=hom;
	if(rec.find(p2.dr1)!=-1)
	p2.hh1=hom;
	if(rec.find(p2.dr2)!=-1)
	p2.hh2=hom;
	if(dom.find(p1.dr1)!=-1 && rec.find(p1.dr2)!=-1)
	{
		if(hom.find(p1.hh1)!=-1)
		pa1+="AA";
		if(het.find(p1.hh1)!=-1)
		pa1+="Aa";
		pa1+="bb";
	}
	if(dom.find(p1.dr1)!=-1 && dom.find(p1.dr2)!=-1)
	{
		if(hom.find(p1.hh1)!=-1)
		pa1+="AA";
		if(het.find(p1.hh1)!=-1)
		pa1+="Aa";
		if(het.find(p1.hh2)!=-1)
		pa1+="Bb";
		if(hom.find(p1.hh2)!=-1)
		pa1+="BB";
	}
	if(rec.find(p1.dr1)!=-1 && rec.find(p1.dr2)!=-1)
	{
		pa1+="aa";
		pa1+="bb";
	}
	if(rec.find(p1.dr1)!=-1 && dom.find(p1.dr2)!=-1)
	{
		pa1+="aa";
		if(hom.find(p1.hh2)!=-1)
		pa1+="BB";
		if(het.find(p1.hh2)!=-1)
		pa1+="Bb";
	}
	if(dom.find(p2.dr1)!=-1 && rec.find(p2.dr2)!=-1)
	{
		if(hom.find(p2.hh1)!=-1)
		pa2+="AA";
		if(het.find(p2.hh1)!=-1)
		pa2+="Aa";
		pa2+="bb";
	}
	if(dom.find(p2.dr1)!=-1 && dom.find(p2.dr2)!=-1)
	{
		if(hom.find(p2.hh1)!=-1)
		pa2+="AA";
		if(het.find(p2.hh1)!=-1)
		pa2+="Aa";
		if(het.find(p2.hh2)!=-1)
		pa2+="Bb";
		if(hom.find(p2.hh2)!=-1)
		pa2+="BB";
	}
	if(rec.find(p2.dr1)!=-1 && rec.find(p2.dr2)!=-1)
	{
		pa2+="aa";
		pa2+="bb";
	}
	if(rec.find(p2.dr1)!=-1 && dom.find(p2.dr2)!=-1)
	{
		pa2+="aa";
		if(hom.find(p2.hh1)!=-1)
		pa2+="BB";
		if(het.find(p2.hh1)!=-1)
		pa2+="Bb";
	}
	pov nma[9];
	nma[0].n="AABB";
	nma[1].n="AABb";
	nma[2].n="AAbb";
	nma[3].n="AaBB";
	nma[4].n="AaBb";
	nma[5].n="Aabb";
	nma[6].n="aaBB";
	nma[7].n="aaBb";
	nma[8].n="aabb";
	nma[0].k=1;
	nma[1].k=0;
	nma[2].k=0;
	nma[3].k=0;
	nma[4].k=0;
	nma[5].k=0;
	nma[6].k=0;
	nma[7].k=0;
	nma[8].k=1;
	cout<<"Ancestors allels are: "<<pa1<<" + "<<pa2<<endl;
	all[0][0].al+="/";
	all[0][1].al+=pa2[0];
	all[0][1].al+=pa2[2];
	all[0][2].al+=pa2[0];
	all[0][2].al+=pa2[3];
	all[0][3].al+=pa2[1];
	all[0][3].al+=pa2[2];
	all[0][4].al+=pa2[1];
	all[0][4].al+=pa2[3];
	all[1][0].al+=pa1[0];
	all[1][0].al+=pa1[2];
	all[2][0].al+=pa1[0];
	all[2][0].al+=pa1[3];
	all[3][0].al+=pa1[1];
	all[3][0].al+=pa1[2];
	all[4][0].al+=pa1[1];
	all[4][0].al+=pa1[3];
	for(int i=1;i<5;i++)
	for(int j=1;j<5;j++)
	{
	all[i][j].al+=all[i][0].al[0];
	all[i][j].al+=all[0][j].al[0];
	all[i][j].al+=all[i][0].al[1];
	all[i][j].al+=all[0][j].al[1];
	if(all[i][j].al[0]=='a' && all[i][j].al[1]=='A')
	swap(all[i][j].al[0],all[i][j].al[1]);
	if(all[i][j].al[2]=='b' && all[i][j].al[3]=='B')
	swap(all[i][j].al[2],all[i][j].al[3]);
    }
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		if(i==0 && all[i][j].al[0]=='a' && all[i][j].al[1]=='B')
		cout<<all[i][j].al[1]<<all[i][j].al[0]<<"\t";
		else if(j==0 && all[i][j].al[0]=='a' && all[i][j].al[1]=='B')
		cout<<all[i][j].al[1]<<all[i][j].al[0]<<"\t";
		else
		cout<<all[i][j].al<<"\t";
	    }
		cout<<"\n";
	}
	pov kid[16];
	for(int i=0;i<16;i++)
	{
		kid[i].n='0';
		kid[i].k=0;
	}
	int s=0;
	int l=0;
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			string p=all[i][j].al;
			for(int k=0;k<16;k++)
			if(kid[k].n==p)
			s++;
			if(s==0)
			{
				kid[l].n=p;
				l++;
			}
			s=0;
		}
	}
	kid[l];
	for(int i=0;i<l;i++)
	for(int j=0;j<9;j++)
	if(kid[i].n==nma[j].n)
	nma[j].k=1;
	for(int i=0;i<l;i++)
	for(int k=1;k<5;k++)
	for(int q=1;q<5;q++)
	if(kid[i].n==all[k][q].al)
	kid[i].k++;
	cout<<"Possible cub's allels and their ratio of numbers:\n";
	for(int i=0;i<l;i++)
	{
	if(kid[i].n[0]=='a' && kid[i].n[2]=='B')
	cout<<kid[i].n[2]<<kid[i].n[3]<<kid[i].n[0]<<kid[i].n[1]<<"\t";
	else
	cout<<kid[i].n<<"\t";
	}
	cout<<endl;
	for(int i=0;i<l;i++)
	cout<<kid[i].k<<"\t";
	cout<<endl;
	for(int i=0;i<l;i++)
	{
		cout<<i+1<<" Cub's characteristics: ";
		if(kid[i].n[0]=='A' && kid[i].n[1]=='A' && kid[i].n[2]=='B')
		cout<<p1.har1<<" + "<<p1.har2;
		if(kid[i].n[0]=='A' && kid[i].n[1]=='a' && kid[i].n[2]=='B')
		cout<<p1.har1<<" + "<<p1.har2;
		if(kid[i].n[0]=='A' && kid[i].n[1]=='A' && kid[i].n[2]=='b')
		cout<<p1.har1<<" + "<<p2.har2;
		if(kid[i].n[0]=='A' && kid[i].n[1]=='a' && kid[i].n[2]=='b')
		cout<<p1.har1<<" + "<<p2.har2;
		if(kid[i].n[0]=='a' && kid[i].n[1]=='a' && kid[i].n[2]=='b' && kid[i].n[3]=='b')
		cout<<p2.har1<<" + "<<p2.har2;
		if(kid[i].n[0]=='a' && kid[i].n[1]=='a' && kid[i].n[2]=='B')
		cout<<p1.har2<<" + "<<p2.har1;
		cout<<endl;
		cout<<"Chance to get cub with this characteristics: ";
		double ch=kid[i].k/16;
		ch*=100;
		int ch1=(kid[i].k/16)*100;
		cout<<ch<<"%(~"<<ch1<<" cub's from 100)"<<endl;
	}
	cout<<endl;
	while(true)
	{
		cout<<"Wanna breed some of this individuals between themselves?\n1)Yes\n2)No\n";
		int choice;
		cin>>choice;
		if(choice==2)
		break;
		cout<<"Possible individuals are:\n";
		for(int i=0;i<9;i++)
		if(nma[i].k==1)
		cout<<nma[i].n<<" ";
		cout<<endl;
		cout<<"Which of this individuals you wish to breed between themselves?\nNumber of first,space,number of second:";
		int c1,c2;
		cin>>c1>>c2;
		for(int i=0,j=0;i<9;i++)
		{
		if(nma[i].k==1)
		j++;
		if(j==c1)
		{
		pa1=nma[i].n;
		break;
	    }
	    }
	    for(int i=0,j=0;i<9;i++)
		{
		if(nma[i].k==1)
		j++;
		if(j==c2)
		{
		pa2=nma[i].n;
		break;
	    }
	    }
	for(int i=0;i<5;i++)
	for(int j=0;j<5;j++)
	all[i][j].al="";
	cout<<"Your breeded individuals allels are: "<<pa1<<" + "<<pa2<<endl;
	all[0][0].al+="/";
	all[0][1].al+=pa2[0];
	all[0][1].al+=pa2[2];
	all[0][2].al+=pa2[0];
	all[0][2].al+=pa2[3];
	all[0][3].al+=pa2[1];
	all[0][3].al+=pa2[2];
	all[0][4].al+=pa2[1];
	all[0][4].al+=pa2[3];
	all[1][0].al+=pa1[0];
	all[1][0].al+=pa1[2];
	all[2][0].al+=pa1[0];
	all[2][0].al+=pa1[3];
	all[3][0].al+=pa1[1];
	all[3][0].al+=pa1[2];
	all[4][0].al+=pa1[1];
	all[4][0].al+=pa1[3];
	for(int i=1;i<5;i++)
	for(int j=1;j<5;j++)
	{
	all[i][j].al+=all[i][0].al[0];
	all[i][j].al+=all[0][j].al[0];
	all[i][j].al+=all[i][0].al[1];
	all[i][j].al+=all[0][j].al[1];
	if(all[i][j].al[0]=='a' && all[i][j].al[1]=='A')
	swap(all[i][j].al[0],all[i][j].al[1]);
	if(all[i][j].al[2]=='b' && all[i][j].al[3]=='B')
	swap(all[i][j].al[2],all[i][j].al[3]);
    }
	for(int i=0;i<5;i++)
	{
		for(int j=0;j<5;j++)
		{
		if(i==0 && all[i][j].al[0]=='a' && all[i][j].al[1]=='B')
		cout<<all[i][j].al[1]<<all[i][j].al[0]<<"\t";
		else if(j==0 && all[i][j].al[0]=='a' && all[i][j].al[1]=='B')
		cout<<all[i][j].al[1]<<all[i][j].al[0]<<"\t";
		else
		cout<<all[i][j].al<<"\t";
	    }
		cout<<"\n";
	}
	kid[16];
	for(int i=0;i<16;i++)
	{
		kid[i].n='0';
		kid[i].k=0;
	}
	s=0;
	l=0;
	for(int i=1;i<5;i++)
	{
		for(int j=1;j<5;j++)
		{
			string p=all[i][j].al;
			for(int k=0;k<16;k++)
			if(kid[k].n==p)
			s++;
			if(s==0)
			{
				kid[l].n=p;
				l++;
			}
			s=0;
		}
	}
	kid[l];
	for(int i=0;i<l;i++)
	for(int j=0;j<9;j++)
	if(kid[i].n==nma[j].n)
	nma[j].k=1;
	for(int i=0;i<l;i++)
	for(int k=1;k<5;k++)
	for(int q=1;q<5;q++)
	if(kid[i].n==all[k][q].al)
	kid[i].k++;
	cout<<"Possible cub's allels and their ratio of numbers:\n";
	for(int i=0;i<l;i++)
	{
	if(kid[i].n[0]=='a' && kid[i].n[2]=='B')
	cout<<kid[i].n[2]<<kid[i].n[3]<<kid[i].n[0]<<kid[i].n[1]<<"\t";
	else
	cout<<kid[i].n<<"\t";
	}
	cout<<endl;
	for(int i=0;i<l;i++)
	cout<<kid[i].k<<"\t";
	cout<<endl;
	for(int i=0;i<l;i++)
	{
		cout<<i+1<<" Cub's characteristics: ";
		if(kid[i].n[0]=='A' && kid[i].n[1]=='A' && kid[i].n[2]=='B')
		cout<<p1.har1<<" + "<<p1.har2;
		if(kid[i].n[0]=='A' && kid[i].n[1]=='a' && kid[i].n[2]=='B')
		cout<<p1.har1<<" + "<<p1.har2;
		if(kid[i].n[0]=='A' && kid[i].n[1]=='A' && kid[i].n[2]=='b')
		cout<<p1.har1<<" + "<<p2.har2;
		if(kid[i].n[0]=='A' && kid[i].n[1]=='a' && kid[i].n[2]=='b')
		cout<<p1.har1<<" + "<<p2.har2;
		if(kid[i].n[0]=='a' && kid[i].n[1]=='a' && kid[i].n[2]=='b' && kid[i].n[3]=='b')
		cout<<p2.har1<<" + "<<p2.har2;
		if(kid[i].n[0]=='a' && kid[i].n[1]=='a' && kid[i].n[2]=='B')
		cout<<p1.har2<<" + "<<p2.har1;
		cout<<endl;
		cout<<"Chance to get cub with this characteristics: ";
		double ch=kid[i].k/16;
		ch*=100;
		int ch1=(kid[i].k/16)*100;
		cout<<ch<<"%(~"<<ch1<<" cub's from 100)"<<endl;
	}
	cout<<endl;
	}
	return 0;
}
